/* Copyright (c) 2016 - 2019 Qualcomm Technologies International, Ltd. */
/*   %%version */
/**
 * \file
 * Implementations of non-autogenerated streams-related trap calls
 */

#include "trap_api/trap_api_private.h"
#include <sink.h>
#include "assert.h"

#if TRAPSET_STREAM

bool SinkGetBdAddr(Sink sink, tp_bdaddr * tpaddr)
{
    /* Send the Sink and copy the bd_addr back out of the return prim */

    IPC_SINK_GET_BD_ADDR get_bd_addr;
    IPC_SINK_GET_BD_ADDR_RSP bd_addr_rsp;

    get_bd_addr.sink = SINK_TO_ID(sink);
    ipc_transaction(IPC_SIGNAL_ID_SINK_GET_BD_ADDR, &get_bd_addr, sizeof(get_bd_addr),
                    IPC_SIGNAL_ID_SINK_GET_BD_ADDR_RSP, &bd_addr_rsp);

    if (bd_addr_rsp.ret && tpaddr != NULL)
    {
        tpaddr->transport = (TRANSPORT_T)bd_addr_rsp.tpaddr.tp_type;
        tpaddr->taddr.type = bd_addr_rsp.tpaddr.addrt.type;
        tpaddr->taddr.addr.lap = bd_addr_rsp.tpaddr.addrt.addr.lap;
        tpaddr->taddr.addr.uap = bd_addr_rsp.tpaddr.addrt.addr.uap;
        tpaddr->taddr.addr.nap = bd_addr_rsp.tpaddr.addrt.addr.nap;
    }

    return bd_addr_rsp.ret;
}

bool StreamSinksFromBdAddr(uint16 * max, Sink * sinks, const tp_bdaddr * tpaddr)
{
    IPC_STREAM_SINKS_FROM_BD_ADDR send_prim;
    IPC_STREAM_SINKS_FROM_BD_ADDR_RSP rsp_prim;
    TP_BD_ADDR_T tpaddr_fw;
    uint16f i;

    send_prim.max = *max;

    /* Copy the supplied App-space structure into a temporary fw-space
     * structure that's the right shape to go to the streams module */
    tpaddr_fw.tp_type = (PHYSICAL_TRANSPORT_T)tpaddr->transport;
    tpaddr_fw.addrt.type = tpaddr->taddr.type;
    tpaddr_fw.addrt.addr.lap = tpaddr->taddr.addr.lap;
    tpaddr_fw.addrt.addr.uap = tpaddr->taddr.addr.uap;
    tpaddr_fw.addrt.addr.nap = tpaddr->taddr.addr.nap;
    send_prim.tpaddr = &tpaddr_fw;

    ipc_transaction(IPC_SIGNAL_ID_STREAM_SINKS_FROM_BD_ADDR, &send_prim, sizeof(send_prim),
                    IPC_SIGNAL_ID_STREAM_SINKS_FROM_BD_ADDR_RSP, &rsp_prim);

    /* Update the max pointer with the number of Sinks found */
    *max = rsp_prim.max;
    /* The sinks arrive in a block of memory pmalloc'd on P0, so we copy them
     * into the local area and free the P0 memory */
    for (i = 0; i < rsp_prim.max; ++i)
    {
        sinks[i] = SINK_FROM_ID(rsp_prim.sinks[i]);
    }
    pfree(rsp_prim.sinks);
    return rsp_prim.ret;
}

bool SinkGetWallclock(Sink sink, bt_wallclock_info * wallclock)
{
    /* Send the Sink and copy the wallclock back out of the response prim */

    IPC_SINK_GET_WALLCLOCK send_prim;
    IPC_SINK_GET_WALLCLOCK_RSP resp_prim;

    send_prim.sink = SINK_TO_ID(sink);
    ipc_transaction(IPC_SIGNAL_ID_SINK_GET_WALLCLOCK, &send_prim, sizeof(send_prim),
                    IPC_SIGNAL_ID_SINK_GET_WALLCLOCK_RSP, &resp_prim);

    if (resp_prim.ret && wallclock != NULL)
    {
        wallclock->change_count = resp_prim.wallclock.change_count;
        wallclock->btclock = resp_prim.wallclock.btclock;
        wallclock->timestamp = resp_prim.wallclock.timestamp;
    }

    return resp_prim.ret;
}

bool StreamPipePair(Sink * sink_a, Sink * sink_b, uint16 size_a_to_b, uint16 size_b_to_a)
{
    /* Send the sinks and sizes and copy the sinks back out of the response prim */

    IPC_STREAM_PIPE_PAIR send_prim;
    IPC_STREAM_PIPE_PAIR_RSP resp_prim;

    if (sink_a == NULL || sink_b == NULL)
    {
        L0_DBG_MSG("Invalid pointer passed to StreamPipePair");
        return FALSE;
    }

    send_prim.size_a_to_b = size_a_to_b;
    send_prim.size_b_to_a = size_b_to_a;
    send_prim.sink_a = SINK_TO_ID(*sink_a);
    send_prim.sink_b = SINK_TO_ID(*sink_b);

    ipc_transaction(IPC_SIGNAL_ID_STREAM_PIPE_PAIR, &send_prim, sizeof(send_prim),
                    IPC_SIGNAL_ID_STREAM_PIPE_PAIR_RSP, &resp_prim);

    *sink_a = SINK_FROM_ID(resp_prim.sink_a);
    *sink_b = SINK_FROM_ID(resp_prim.sink_b);

    return resp_prim.ret;
}

#endif /* TRAPSET_STREAM */

#if TRAPSET_MIRRORING
Source StreamAclMarshalSource(const tp_bdaddr * tpaddr)
{
    IPC_STREAM_ACL_MARSHAL_SOURCE ipc_send_prim;
    IPC_SOURCE_RSP ipc_recv_prim;
    TP_BD_ADDR_T tpaddr_fw;

    /* Copy the supplied App-space structure into a temporary fw-space
     * structure that's the right shape to go to the streams module */
    tpaddr_fw.tp_type = (PHYSICAL_TRANSPORT_T)tpaddr->transport;
    tpaddr_fw.addrt.type = tpaddr->taddr.type;
    tpaddr_fw.addrt.addr.lap = tpaddr->taddr.addr.lap;
    tpaddr_fw.addrt.addr.uap = tpaddr->taddr.addr.uap;
    tpaddr_fw.addrt.addr.nap = tpaddr->taddr.addr.nap;
    ipc_send_prim.tpaddr = &tpaddr_fw;

    ipc_transaction(IPC_SIGNAL_ID_STREAM_ACL_MARSHAL_SOURCE, &ipc_send_prim, sizeof(ipc_send_prim),
                    IPC_SIGNAL_ID_STREAM_ACL_MARSHAL_SOURCE_RSP, &ipc_recv_prim);
    return SOURCE_FROM_ID(ipc_recv_prim.ret);
}

Sink StreamAclMarshalSink(const tp_bdaddr * tpaddr)
{
    IPC_STREAM_ACL_MARSHAL_SINK ipc_send_prim;
    IPC_SINK_RSP ipc_recv_prim;
    TP_BD_ADDR_T tpaddr_fw;

    /* Copy the supplied App-space structure into a temporary fw-space
     * structure that's the right shape to go to the streams module */
    tpaddr_fw.tp_type = (PHYSICAL_TRANSPORT_T)tpaddr->transport;
    tpaddr_fw.addrt.type = tpaddr->taddr.type;
    tpaddr_fw.addrt.addr.lap = tpaddr->taddr.addr.lap;
    tpaddr_fw.addrt.addr.uap = tpaddr->taddr.addr.uap;
    tpaddr_fw.addrt.addr.nap = tpaddr->taddr.addr.nap;
    ipc_send_prim.tpaddr = &tpaddr_fw;

    ipc_transaction(IPC_SIGNAL_ID_STREAM_ACL_MARSHAL_SINK, &ipc_send_prim, sizeof(ipc_send_prim),
                    IPC_SIGNAL_ID_STREAM_ACL_MARSHAL_SINK_RSP, &ipc_recv_prim);
    return SINK_FROM_ID(ipc_recv_prim.ret);
}

#endif

#ifdef TRAPSET_RFCOMM
Sink StreamRfcommSinkFromServerChannel(const tp_bdaddr * tpaddr, uint8 server_channel)
{
    IPC_STREAM_RFCOMM_SINK_FROM_SERVER_CHANNEL ipc_send_prim;
    IPC_SINK_RSP ipc_recv_prim;
    TP_BD_ADDR_T tpaddr_fw;

    /* Copy the supplied App-space structure into a temporary fw-space
     * structure that's the right shape to go to the streams module */
    tpaddr_fw.tp_type = (PHYSICAL_TRANSPORT_T)tpaddr->transport;
    tpaddr_fw.addrt.type = tpaddr->taddr.type;
    tpaddr_fw.addrt.addr.lap = tpaddr->taddr.addr.lap;
    tpaddr_fw.addrt.addr.uap = tpaddr->taddr.addr.uap;
    tpaddr_fw.addrt.addr.nap = tpaddr->taddr.addr.nap;
    ipc_send_prim.tpaddr = &tpaddr_fw;

    ipc_send_prim.server_channel = server_channel;
    ipc_transaction(IPC_SIGNAL_ID_STREAM_RFCOMM_SINK_FROM_SERVER_CHANNEL, &ipc_send_prim, sizeof(ipc_send_prim),
                    IPC_SIGNAL_ID_STREAM_RFCOMM_SINK_FROM_SERVER_CHANNEL_RSP, &ipc_recv_prim);
    return SINK_FROM_ID(ipc_recv_prim.ret);
}

#endif
