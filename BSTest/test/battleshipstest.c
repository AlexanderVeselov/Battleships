#include <stdlib.h>
#include <testkern.h>
#include "battleshipstest.h"

static char * tat_battleshipstest_test15N0_MessageTable[] = {
	"INITDATACOMPLETE()",
	"SHIPSCURRENTSTATE(1,\"(. (. 1, 1, DESTROYER, 0, EAST, 50, (. 5, 1 .), (: 0, 0, 0, 0 :) .) .)\")",
	"STARTSIMULATION(0)",
	"ORDERTURNREQUEST(1,1,RIGHT)",
	"FINISHSIMULATION(0,1)",
	"STRATEGYVICTORY(1)"
};
static TAT_SRC_FILE_DEF tat_battleshipstest_test15N0_SrcFiles[] = {
	{"C:\\Battleships\\BSTest\\msc\\test15\\test15.mpr", 1, 5, 16 },
	{"C:\\Battleships\\BSTest\\work\\test15N0.mpr", 2, 5, 16 }};
TAT_TEST_RESULT TAT_TI_battleshipstest_test15N0( TAT_TEST_INSTANCE* id )
{
	id->varDefs = NULL;
	id->timeLabels = NULL;
	id->srcFiles = (TAT_SRC_FILE_DEF*)&tat_battleshipstest_test15N0_SrcFiles;
	id->timeLabelCount = 0;
	id->srcFilesCount = 2;
	id->varCount = 0;
	id->branchCount = 0;
	id->repeatCount = 1;
	id->timerCount  = 0;
	id->loopCount   = 0;
	return TAT_TEST_CONTINUE;
}
static TAT_INSTANCE_ID tat_I_battleshipstest_test15N0_N0[]={TAT_I_SIMULATOR_ID,TAT_I_STRATEGY_ID};
static TAT_INSTANCE_ID tat_I_battleshipstest_test15N0_N1[]={TAT_I_SIMULATOR_ID,TAT_I_STRATEGY_ID};
static TAT_INSTANCE_ID tat_I_battleshipstest_test15N0_N2[]={TAT_I_SIMULATOR_ID,TAT_I_STRATEGY_ID};
static TAT_INSTANCE_ID tat_I_battleshipstest_test15N0_N3[]={TAT_I_STRATEGY_ID,TAT_I_SIMULATOR_ID};
static TAT_INSTANCE_ID tat_I_battleshipstest_test15N0_N4[]={TAT_I_STRATEGY_ID,TAT_I_SIMULATOR_ID};
static TAT_INSTANCE_ID tat_I_battleshipstest_test15N0_N5[]={TAT_I_SIMULATOR_ID,TAT_I_STRATEGY_ID};
static TAT_SRC_REF_STRUCT tat_battleshipstest_test15N0_0_SrcRef[] = {{0, 5}, {1, 5}};
static TAT_EVENT_INSTANCE tat_battleshipstest_test15N0_0_event = {TAT_SEND_EV, TAT_S_INITDATACOMPLETE_ID, NULL, {{0,0}, {0,0}, ""},2, 
(TAT_INSTANCE_ID *) &tat_I_battleshipstest_test15N0_N0, "", 2, (TAT_SRC_REF_STRUCT *) tat_battleshipstest_test15N0_0_SrcRef, 
TAT_VERDICT_PASS, -1, &tat_battleshipstest_test15N0_MessageTable[0],
NULL};

static TAT_SRC_REF_STRUCT tat_battleshipstest_test15N0_1_SrcRef[] = {{0, 7}, {1, 7}};
static TAT_SIG_SHIPSCURRENTSTATE tat_battleshipstest_test15N0_1_sigdata;
static TAT_EVENT_INSTANCE tat_battleshipstest_test15N0_1_event = {TAT_SEND_EV, TAT_S_SHIPSCURRENTSTATE_ID, &tat_battleshipstest_test15N0_1_sigdata, {{0,0}, {0,0}, ""},2, 
(TAT_INSTANCE_ID *) &tat_I_battleshipstest_test15N0_N1, "", 2, (TAT_SRC_REF_STRUCT *) tat_battleshipstest_test15N0_1_SrcRef, 
TAT_VERDICT_PASS, -1, &tat_battleshipstest_test15N0_MessageTable[1],
NULL};

static TAT_SRC_REF_STRUCT tat_battleshipstest_test15N0_2_SrcRef[] = {{0, 9}, {1, 9}};
static TAT_SIG_STARTSIMULATION tat_battleshipstest_test15N0_2_sigdata;
static TAT_EVENT_INSTANCE tat_battleshipstest_test15N0_2_event = {TAT_SEND_EV, TAT_S_STARTSIMULATION_ID, &tat_battleshipstest_test15N0_2_sigdata, {{0,0}, {0,0}, ""},2, 
(TAT_INSTANCE_ID *) &tat_I_battleshipstest_test15N0_N2, "", 2, (TAT_SRC_REF_STRUCT *) tat_battleshipstest_test15N0_2_SrcRef, 
TAT_VERDICT_PASS, -1, &tat_battleshipstest_test15N0_MessageTable[2],
NULL};

static TAT_SRC_REF_STRUCT tat_battleshipstest_test15N0_3_SrcRef[] = {{0, 11}, {1, 11}};
static TAT_SIG_ORDERTURNREQUEST tat_battleshipstest_test15N0_3_sigdata;
static TAT_EVENT_INSTANCE tat_battleshipstest_test15N0_3_event = {TAT_RECV_EV, TAT_S_ORDERTURNREQUEST_ID, &tat_battleshipstest_test15N0_3_sigdata, {{0,0}, {0,0}, ""},2, 
(TAT_INSTANCE_ID *) &tat_I_battleshipstest_test15N0_N3, "", 2, (TAT_SRC_REF_STRUCT *) tat_battleshipstest_test15N0_3_SrcRef, 
TAT_VERDICT_PASS, -1, &tat_battleshipstest_test15N0_MessageTable[3],
NULL};

static TAT_SRC_REF_STRUCT tat_battleshipstest_test15N0_4_SrcRef[] = {{0, 13}, {1, 13}};
static TAT_SIG_FINISHSIMULATION tat_battleshipstest_test15N0_4_sigdata;
static TAT_EVENT_INSTANCE tat_battleshipstest_test15N0_4_event = {TAT_RECV_EV, TAT_S_FINISHSIMULATION_ID, &tat_battleshipstest_test15N0_4_sigdata, {{0,0}, {0,0}, ""},2, 
(TAT_INSTANCE_ID *) &tat_I_battleshipstest_test15N0_N4, "", 2, (TAT_SRC_REF_STRUCT *) tat_battleshipstest_test15N0_4_SrcRef, 
TAT_VERDICT_PASS, -1, &tat_battleshipstest_test15N0_MessageTable[4],
NULL};

static TAT_SRC_REF_STRUCT tat_battleshipstest_test15N0_5_SrcRef[] = {{0, 15}, {1, 15}};
static TAT_SIG_STRATEGYVICTORY tat_battleshipstest_test15N0_5_sigdata;
static TAT_EVENT_INSTANCE tat_battleshipstest_test15N0_5_event = {TAT_SEND_EV, TAT_S_STRATEGYVICTORY_ID, &tat_battleshipstest_test15N0_5_sigdata, {{0,0}, {0,0}, ""},2, 
(TAT_INSTANCE_ID *) &tat_I_battleshipstest_test15N0_N5, "", 2, (TAT_SRC_REF_STRUCT *) tat_battleshipstest_test15N0_5_SrcRef, 
TAT_VERDICT_PASS, -1, &tat_battleshipstest_test15N0_MessageTable[5],
NULL};

static TAT_TEST_RESULT tat_test15N0_state0(TAT_TEST_INSTANCE *id)
{
	TAT_EVENT_INSTANCE __ev;
			memcpy(&__ev, &tat_battleshipstest_test15N0_0_event, sizeof(__ev));
			if (TAT_Send_INITDATACOMPLETE(id, &__ev, &tat_battleshipstest_test15N0_0_event)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
			id->nextState=1;
	return TAT_TEST_FINISHED;
}
static TAT_TEST_RESULT tat_test15N0_state1(TAT_TEST_INSTANCE *id)
{
	TAT_EVENT_INSTANCE __ev;
			memcpy(&__ev, &tat_battleshipstest_test15N0_1_event, sizeof(__ev));
			if (TAT_Send_SHIPSCURRENTSTATE(id, &__ev, &tat_battleshipstest_test15N0_1_event, 1, "(. (. 1, 1, DESTROYER, 0, EAST, 50, (. 5, 1 .), (: 0, 0, 0, 0 :) .) .)")!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
			id->nextState=2;
	return TAT_TEST_FINISHED;
}
static TAT_TEST_RESULT tat_test15N0_state2(TAT_TEST_INSTANCE *id)
{
	TAT_EVENT_INSTANCE __ev;
			memcpy(&__ev, &tat_battleshipstest_test15N0_2_event, sizeof(__ev));
			if (TAT_Send_STARTSIMULATION(id, &__ev, &tat_battleshipstest_test15N0_2_event, 0)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
			id->nextState=3;
	return TAT_TEST_FINISHED;
}
static TAT_TEST_RESULT tat_test15N0_state3(TAT_TEST_INSTANCE *id)
{
	TAT_EVENT_INSTANCE *_ev;
	if (id->queue.length>0) {
		_ev = id->getQueue(id);
			if ((_ev->eventID == TAT_S_ORDERTURNREQUEST_ID)&&
				((((TAT_SIG_ORDERTURNREQUEST *)_ev->eventData)->Param1==(1)))&&
				((((TAT_SIG_ORDERTURNREQUEST *)_ev->eventData)->Param2==(1)))&&
				((((TAT_SIG_ORDERTURNREQUEST *)_ev->eventData)->Param3==(RIGHT)))){
				if (id->dumpEvent(id, _ev, &tat_battleshipstest_test15N0_3_event)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
				id->popQueue(id);
				id->nextState=4;
				return TAT_TEST_CONTINUE;
			}
	};
	return TAT_TEST_FINISHED;
}
static TAT_TEST_RESULT tat_test15N0_state4(TAT_TEST_INSTANCE *id)
{
	TAT_EVENT_INSTANCE *_ev;
	if (id->queue.length>0) {
		_ev = id->getQueue(id);
			if ((_ev->eventID == TAT_S_FINISHSIMULATION_ID)&&
				((((TAT_SIG_FINISHSIMULATION *)_ev->eventData)->Param1==(0)))&&
				((((TAT_SIG_FINISHSIMULATION *)_ev->eventData)->Param2==(1)))){
				if (id->dumpEvent(id, _ev, &tat_battleshipstest_test15N0_4_event)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
				id->popQueue(id);
				id->nextState=5;
				return TAT_TEST_CONTINUE;
			}
	};
	return TAT_TEST_FINISHED;
}
static TAT_TEST_RESULT tat_test15N0_state5(TAT_TEST_INSTANCE *id)
{
	TAT_EVENT_INSTANCE __ev;
			memcpy(&__ev, &tat_battleshipstest_test15N0_5_event, sizeof(__ev));
			if (TAT_Send_STRATEGYVICTORY(id, &__ev, &tat_battleshipstest_test15N0_5_event, 1)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
			id->nextState=-1;
	return TAT_TEST_FINISHED;
}
TAT_TEST_RESULT TAT_T_battleshipstest_test15N0( TAT_TEST_INSTANCE* id )
{
	static const TAT_STATE_FUNC states[6]={
	tat_test15N0_state0,tat_test15N0_state1,tat_test15N0_state2,tat_test15N0_state3,tat_test15N0_state4,
	tat_test15N0_state5};
	TAT_TEST_RESULT res;
	int prevState;
	if( id == NULL )
	{
		id->testStatus = TAT_ERR_INTERNAL;
		id->testResult = TAT_TEST_CRITICAL;
		id->dumpEvent(id, NULL, NULL);
		return TAT_TEST_CRITICAL;
	}
	while( id->nextState != TAT_FINAL_STATE )
	{
		prevState=id->nextState;
		res = states[id->nextState](id);
		if (res == TAT_TEST_CRITICAL) return TAT_TEST_CRITICAL;
		if (res == TAT_TEST_FINISHED && id->testStatus != TAT_OK)
			return TAT_TEST_FINISHED;
		if (res == TAT_TEST_FINISHED && id->nextState != TAT_FINAL_STATE && id->nextState==prevState)
			return TAT_TEST_CONTINUE;
	}
	return TAT_TEST_FINISHED;
}


/****************************************************************************/
