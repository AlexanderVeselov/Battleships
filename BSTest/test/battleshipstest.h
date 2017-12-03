/* TAT TEST SUITE HEADER FILE */
#ifndef TAT_battleshipstest_H
#define TAT_battleshipstest_H
#ifndef TAT_INSTANCE_SUPPORT
#error TAT_INSTANCE_SUPPORT define not set for compilation
#endif
#ifndef TAT_TIME_SUPPORT
#error TAT_TIME_SUPPORT define not set for compilation
#endif
#include <testkern.h>
#include "types.h"

#define TAT_I_SIMULATOR_ID 1
#define TAT_I_STRATEGY_ID 2


#define TAT_S_DESTROYSHIP_ID 1
typedef struct {
	int Param1;
	int Param2;
	int Param3;
} TAT_SIG_DESTROYSHIP;

extern TAT_TEST_RESULT TAT_Send_DESTROYSHIP ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, int Param2, int Param3);

#define TAT_S_FINISHSIMULATION_ID 2
typedef struct {
	int Param1;
	int Param2;
} TAT_SIG_FINISHSIMULATION;


#define TAT_S_INITDATACOMPLETE_ID 3
extern TAT_TEST_RESULT TAT_Send_INITDATACOMPLETE ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc);

#define TAT_S_MESSAGEERROR_ID 4
typedef struct {
	char* Param1;
} TAT_SIG_MESSAGEERROR;


#define TAT_S_MESSAGELOG_ID 5
typedef struct {
	char* Param1;
} TAT_SIG_MESSAGELOG;


#define TAT_S_ORDERFIREREJECT_ID 6
typedef struct {
	int Param1;
	int Param2;
} TAT_SIG_ORDERFIREREJECT;

extern TAT_TEST_RESULT TAT_Send_ORDERFIREREJECT ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, int Param2);

#define TAT_S_ORDERFIREREQUEST_ID 7
typedef struct {
	int Param1;
	int Param2;
	int Param3;
	char* Param4;
} TAT_SIG_ORDERFIREREQUEST;


#define TAT_S_ORDERFIRERESPONSE_ID 8
typedef struct {
	int Param1;
	int Param2;
} TAT_SIG_ORDERFIRERESPONSE;

extern TAT_TEST_RESULT TAT_Send_ORDERFIRERESPONSE ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, int Param2);

#define TAT_S_ORDERSPEEDREJECT_ID 9
typedef struct {
	int Param1;
	int Param2;
} TAT_SIG_ORDERSPEEDREJECT;

extern TAT_TEST_RESULT TAT_Send_ORDERSPEEDREJECT ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, int Param2);

#define TAT_S_ORDERSPEEDREQUEST_ID 10
typedef struct {
	int Param1;
	int Param2;
	float Param3;
} TAT_SIG_ORDERSPEEDREQUEST;


#define TAT_S_ORDERSPEEDRESPONSE_ID 11
typedef struct {
	int Param1;
	int Param2;
} TAT_SIG_ORDERSPEEDRESPONSE;

extern TAT_TEST_RESULT TAT_Send_ORDERSPEEDRESPONSE ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, int Param2);

#define TAT_S_ORDERTURNREJECT_ID 12
typedef struct {
	int Param1;
	int Param2;
} TAT_SIG_ORDERTURNREJECT;

extern TAT_TEST_RESULT TAT_Send_ORDERTURNREJECT ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, int Param2);

#define TAT_S_ORDERTURNREQUEST_ID 13
typedef struct {
	int Param1;
	int Param2;
	float Param3;
} TAT_SIG_ORDERTURNREQUEST;


#define TAT_S_ORDERTURNRESPONSE_ID 14
typedef struct {
	int Param1;
	int Param2;
} TAT_SIG_ORDERTURNRESPONSE;

extern TAT_TEST_RESULT TAT_Send_ORDERTURNRESPONSE ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, int Param2);

#define TAT_S_SHIPSCURRENTSTATE_ID 15
typedef struct {
	int Param1;
	char* Param2;
} TAT_SIG_SHIPSCURRENTSTATE;

extern TAT_TEST_RESULT TAT_Send_SHIPSCURRENTSTATE ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, char* Param2);

#define TAT_S_STARTSIMULATION_ID 16
typedef struct {
	int Param1;
} TAT_SIG_STARTSIMULATION;

extern TAT_TEST_RESULT TAT_Send_STARTSIMULATION ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1);

#define TAT_S_STRATEGYLOSE_ID 17
typedef struct {
	int Param1;
} TAT_SIG_STRATEGYLOSE;

extern TAT_TEST_RESULT TAT_Send_STRATEGYLOSE ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1);

#define TAT_S_STRATEGYVICTORY_ID 18
typedef struct {
	int Param1;
} TAT_SIG_STRATEGYVICTORY;

extern TAT_TEST_RESULT TAT_Send_STRATEGYVICTORY ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1);

#define TAT_S_VISIBLESHIP_ID 19
typedef struct {
	int Param1;
	char* Param2;
} TAT_SIG_VISIBLESHIP;

extern TAT_TEST_RESULT TAT_Send_VISIBLESHIP ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, char* Param2);

extern TAT_TEST_RESULT TAT_Init_battleshipstest (TAT_TEST_INSTANCE * id);
extern TAT_TEST_TABLE TAT_battleshipstest_TestTable[];
extern TAT_TEST_RESULT TAT_TI_battleshipstest_test15N0( TAT_TEST_INSTANCE* id );
extern TAT_TEST_RESULT TAT_T_battleshipstest_test15N0( TAT_TEST_INSTANCE* id );
#endif
