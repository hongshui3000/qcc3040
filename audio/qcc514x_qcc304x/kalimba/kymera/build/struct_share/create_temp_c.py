############################################################################
# CONFIDENTIAL
#
# Copyright (c) 2013 - 2017 Qualcomm Technologies International, Ltd.
#
############################################################################
"""
Make temporary C file that has no real content but includes the headers
we want to share definitions from.
"""

import sys

HEADERS = ''
for arg in sys.argv[2:]:
    if arg[0:2] == '-H':
        HEADERS = '#include "' + arg.replace('-H', '') + '"\n' + HEADERS

FILENAME = sys.argv[1]

# Put a cautionary "DO NOT EDIT" comment into the generated file
COMMENT = "/* Caution, this file has been auto-generated by " + __file__ +";\n"
COMMENT += " * its purpose is to enable a dummy-built object "
COMMENT += "which is subsequently parsed for symbolic information.\n"
COMMENT += " * MANUAL EDITS TO THIS FILE MAY BE OVERWRITTEN WHEN REBUILDING! */\n"
# Make sure the file contains some code
MAIN = "void main( void )\n{\n\t\n}\n"

# Add the list of headers
MAIN = COMMENT + HEADERS + MAIN

# And write the result
with open(FILENAME, 'w') as file:
    file.write(MAIN)