###############################################################################
#
# COPYRIGHT 2001-2002 MOTOROLA, ALL RIGHTS RESERVED
#
# Description: Abstract Test Suite 'battleshipstest'
#
###############################################################################
# command line: 'C:\Motorola\sic\bin\atsgen.exe -m @work/macroprc_mpr.lst -config config.xml -o work/battleshipstest.tcl -mf -tt -state -nia -incl types.h '

set INSTANCE_NAME 0
set INSTANCE_TYPE 1
set INSTANCE_ATTR 2
set INSTANCE_PARAMS 3
set INSTANCE_STYPES 4
set INSTANCE_FIELDS 5
set INSTANCE_PARAMTYPE 6
set INSTANCE_VARARG 7
set INSTANCE_PRIORITY 8
set INSTANCE_RECORD_SIZE 9
set InstanceSet [ list \
 "SIMULATOR" "env" [ list  ] [ list ] [ list ] [ list ] "" 0 100\
 "STRATEGY" "model" [ list  ] [ list ] [ list ] [ list ] "" 0 100\
 ]
set SIGNAL_NAME 0
set SIGNAL_TYPE 1
set SIGNAL_ATTR 2
set SIGNAL_PARAMS 3
set SIGNAL_STYPES 4
set SIGNAL_FIELDS 5
set SIGNAL_PARAMTYPE 6
set SIGNAL_VARARG 7
set SIGNAL_PRIORITY 8
set SIGNAL_RECORD_SIZE 9
set SignalSet [list \
"DESTROYSHIP"  "in"  [list ] [ list "int" "int" "int" ] [ list -1 -1 -1 ] [ list Param1 Param2 Param3 ] "C" 0 100\
"FINISHSIMULATION"  "out"  [list ] [ list "int" "int" ] [ list -1 -1 ] [ list Param1 Param2 ] "C" 0 100\
"INITDATACOMPLETE"  "in"  [list ] [ list ] [ list ] [ list ] "C" 0 100\
"MESSAGEERROR"  "out"  [list ] [ list "char*" ] [ list 0 ] [ list Param1 ] "C" 0 100\
"MESSAGELOG"  "out"  [list ] [ list "char*" ] [ list 0 ] [ list Param1 ] "C" 0 100\
"ORDERFIREREJECT"  "in"  [list ] [ list "int" "int" ] [ list -1 -1 ] [ list Param1 Param2 ] "C" 0 100\
"ORDERFIREREQUEST"  "out"  [list ] [ list "int" "int" "int" "char*" ] [ list -1 -1 -1 0 ] [ list Param1 Param2 Param3 Param4 ] "C" 0 100\
"ORDERFIRERESPONSE"  "in"  [list ] [ list "int" "int" ] [ list -1 -1 ] [ list Param1 Param2 ] "C" 0 100\
"ORDERSPEEDREJECT"  "in"  [list ] [ list "int" "int" ] [ list -1 -1 ] [ list Param1 Param2 ] "C" 0 100\
"ORDERSPEEDREQUEST"  "out"  [list ] [ list "int" "int" "float" ] [ list -1 -1 -1 ] [ list Param1 Param2 Param3 ] "C" 0 100\
"ORDERSPEEDRESPONSE"  "in"  [list ] [ list "int" "int" ] [ list -1 -1 ] [ list Param1 Param2 ] "C" 0 100\
"ORDERTURNREJECT"  "in"  [list ] [ list "int" "int" ] [ list -1 -1 ] [ list Param1 Param2 ] "C" 0 100\
"ORDERTURNREQUEST"  "out"  [list ] [ list "int" "int" "float" ] [ list -1 -1 -1 ] [ list Param1 Param2 Param3 ] "C" 0 100\
"ORDERTURNRESPONSE"  "in"  [list ] [ list "int" "int" ] [ list -1 -1 ] [ list Param1 Param2 ] "C" 0 100\
"SHIPSCURRENTSTATE"  "in"  [list ] [ list "int" "char*" ] [ list -1 0 ] [ list Param1 Param2 ] "C" 0 100\
"STARTSIMULATION"  "in"  [list ] [ list "int" ] [ list -1 ] [ list Param1 ] "C" 0 100\
"STRATEGYLOSE"  "in"  [list ] [ list "int" ] [ list -1 ] [ list Param1 ] "C" 0 100\
"STRATEGYVICTORY"  "in"  [list ] [ list "int" ] [ list -1 ] [ list Param1 ] "C" 0 100\
"VISIBLESHIP"  "in"  [list ] [ list "int" "char*" ] [ list -1 0 ] [ list Param1 Param2 ] "C" 0 100\
]
set TestCaseNames [list "test15N0"]
set DATATYPE_NAME 0
set DATATYPE_ATTR 1
set DATATYPE_ENUM 2
set DATATYPE_PARAMTYPE 3
set DATATYPE_DATACLASS 4
set DATATYPE_RECORD_SIZE 5
set DataTypeSet [list \
		"STRING" [list "" "strcmp" ] [ list ] "" ""\
]
set IncludeFiles [ list "types.h"  ]
set CONFIGURATION ""
set ATS_EVENT_TYPE 0
set ATS_EVENT_TIME 1
set ATS_EVENT_OTIME 2
set ATS_EVENT_PTIME 3
set ATS_EVENT_COND 4
set ATS_EVENT_INST 5
set ATS_EVENT_VERD 6
set ATS_EVENT_SREF 7
set ATS_EVENT_COMMENT 8
set ATS_EVENT_LABEL 9
set ATS_EVENT_DATA 10

StartTestSuite "battleshipstest"


StartTestCase "test15N0" 1 [ list ]\
[ list ]\
[ list ]  0 0 \
[ list \
"INITDATACOMPLETE()"\
"SHIPSCURRENTSTATE(1,\"(. (. 1, 1, DESTROYER, 0, EAST, 50, (. 5, 1 .), (: 0, 0, 0, 0 :) .) .)\")"\
"STARTSIMULATION(0)"\
"ORDERTURNREQUEST(1,1,RIGHT)"\
"FINISHSIMULATION(0,1)"\
"STRATEGYVICTORY(1)"\
] [ list  ]\
[ list  [list "C:\\Battleships\\BSTest\\msc\\test15\\test15.mpr" 1 5 16 ]\
[list "C:\\Battleships\\BSTest\\work\\test15N0.mpr" 2 5 16 ]\
]\
[ list \
 [list  0  1  ]\
 [list  0  1  ]\
 [list  0  1  ]\
 [list  1  0  ]\
 [list  1  0  ]\
 [list  0  1  ]\
]\
[ list \
[ list "send" [list [ list REL "0" "INF" ] [ list REL "0" "INF" ] ] [list ] [list ] "" 0  PASS  [list [list 0 5 ] [list 1 5 ] ] "" "" [list  2 [ list  ]  0 [ list REL "0" "0" ] ] ]\
[ list "send" [list [ list REL "0" "INF" ] [ list REL "0" "INF" ] ] [list ] [list ] "" 1  PASS  [list [list 0 7 ] [list 1 7 ] ] "" "" [list  14 [ list [ list "" "1"  ] [ list "" "\"(. (. 1, 1, DESTROYER, 0, EAST, 50, (. 5, 1 .), (: 0, 0, 0, 0 :) .) .)\""  ]  ]  1 [ list REL "0" "0" ] ] ]\
[ list "send" [list [ list REL "0" "INF" ] [ list REL "0" "INF" ] ] [list ] [list ] "" 2  PASS  [list [list 0 9 ] [list 1 9 ] ] "" "" [list  15 [ list [ list "" "0"  ]  ]  2 [ list REL "0" "0" ] ] ]\
[ list "recv" [list [ list REL "0" "INF" ] [ list REL "0" "INF" ] ] [list ] [list ] "" 3  PASS  [list [list 0 11 ] [list 1 11 ] ] "" "" [list  12 [ list [ list "" "1"  ] [ list "" "1"  ] [ list "" "RIGHT"  ]  ]  3 [ list REL "0" "0" ] ] ]\
[ list "recv" [list [ list REL "0" "INF" ] [ list REL "0" "INF" ] ] [list ] [list ] "" 4  PASS  [list [list 0 13 ] [list 1 13 ] ] "" "" [list  1 [ list [ list "" "0"  ] [ list "" "1"  ]  ]  4 [ list REL "0" "0" ] ] ]\
[ list "send" [list [ list REL "0" "INF" ] [ list REL "0" "INF" ] ] [list ] [list ] "" 5  PASS  [list [list 0 15 ] [list 1 15 ] ] "" "" [list  17 [ list [ list "" "1"  ]  ]  5 [ list REL "0" "0" ] ] ]\
] 1 0

State 0 0 0 0 1 0 [list \
[list 0  1 ]\
]

State 1 0 0 0 1 0 [list \
[list 1  2 ]\
]

State 2 0 0 0 1 0 [list \
[list 2  3 ]\
]

State 3 0 0 1 0 0 [list \
[list 3  4 ]\
]

State 4 0 0 1 0 0 [list \
[list 4  5 ]\
]

State 5 0 0 0 1 0 [list \
[list 5  -1 ]\
]

FinishTestCase "test15N0"

EndTestSuite "battleshipstest"
