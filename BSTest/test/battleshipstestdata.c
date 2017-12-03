#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <testkern.h>
#include "battleshipstest.h"

static TAT_INSTANCE_DEF tat_InstanceDefinition[]={
{TAT_I_SIMULATOR_ID, "SIMULATOR", 100},
{TAT_I_STRATEGY_ID, "STRATEGY", 100}
};


static TAT_SIG_PARAM_DEF tat_SIG_PARAM_DESTROYSHIP[]={
	{0,"Param1",sizeof(int), offsetof(TAT_SIG_DESTROYSHIP, Param1), TAT_Dump_int},
	{1,"Param2",sizeof(int), offsetof(TAT_SIG_DESTROYSHIP, Param2), TAT_Dump_int},
	{2,"Param3",sizeof(int), offsetof(TAT_SIG_DESTROYSHIP, Param3), TAT_Dump_int}
};
TAT_TEST_RESULT TAT_Send_DESTROYSHIP ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, int Param2, int Param3)
{
	((TAT_SIG_DESTROYSHIP *)ev->eventData)->Param1=Param1;
	((TAT_SIG_DESTROYSHIP *)ev->eventData)->Param2=Param2;
	((TAT_SIG_DESTROYSHIP *)ev->eventData)->Param3=Param3;
	ev->eventID=TAT_S_DESTROYSHIP_ID;
	if(id->dumpEvent(id,ev,evSrc)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
	return (id->testResult=id->sendMessage(id, ev));
}
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_FINISHSIMULATION[]={
	{3,"Param1",sizeof(int), offsetof(TAT_SIG_FINISHSIMULATION, Param1), TAT_Dump_int},
	{4,"Param2",sizeof(int), offsetof(TAT_SIG_FINISHSIMULATION, Param2), TAT_Dump_int}
};
TAT_TEST_RESULT TAT_Send_INITDATACOMPLETE ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc)
{
	ev->eventID=TAT_S_INITDATACOMPLETE_ID;
	if(id->dumpEvent(id,ev,evSrc)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
	return (id->testResult=id->sendMessage(id, ev));
}
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_MESSAGEERROR[]={
	{5,"Param1",sizeof(char*), offsetof(TAT_SIG_MESSAGEERROR, Param1), TAT_Dump_String}
};
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_MESSAGELOG[]={
	{6,"Param1",sizeof(char*), offsetof(TAT_SIG_MESSAGELOG, Param1), TAT_Dump_String}
};
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_ORDERFIREREJECT[]={
	{7,"Param1",sizeof(int), offsetof(TAT_SIG_ORDERFIREREJECT, Param1), TAT_Dump_int},
	{8,"Param2",sizeof(int), offsetof(TAT_SIG_ORDERFIREREJECT, Param2), TAT_Dump_int}
};
TAT_TEST_RESULT TAT_Send_ORDERFIREREJECT ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, int Param2)
{
	((TAT_SIG_ORDERFIREREJECT *)ev->eventData)->Param1=Param1;
	((TAT_SIG_ORDERFIREREJECT *)ev->eventData)->Param2=Param2;
	ev->eventID=TAT_S_ORDERFIREREJECT_ID;
	if(id->dumpEvent(id,ev,evSrc)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
	return (id->testResult=id->sendMessage(id, ev));
}
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_ORDERFIREREQUEST[]={
	{9,"Param1",sizeof(int), offsetof(TAT_SIG_ORDERFIREREQUEST, Param1), TAT_Dump_int},
	{10,"Param2",sizeof(int), offsetof(TAT_SIG_ORDERFIREREQUEST, Param2), TAT_Dump_int},
	{11,"Param3",sizeof(int), offsetof(TAT_SIG_ORDERFIREREQUEST, Param3), TAT_Dump_int},
	{12,"Param4",sizeof(char*), offsetof(TAT_SIG_ORDERFIREREQUEST, Param4), TAT_Dump_String}
};
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_ORDERFIRERESPONSE[]={
	{13,"Param1",sizeof(int), offsetof(TAT_SIG_ORDERFIRERESPONSE, Param1), TAT_Dump_int},
	{14,"Param2",sizeof(int), offsetof(TAT_SIG_ORDERFIRERESPONSE, Param2), TAT_Dump_int}
};
TAT_TEST_RESULT TAT_Send_ORDERFIRERESPONSE ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, int Param2)
{
	((TAT_SIG_ORDERFIRERESPONSE *)ev->eventData)->Param1=Param1;
	((TAT_SIG_ORDERFIRERESPONSE *)ev->eventData)->Param2=Param2;
	ev->eventID=TAT_S_ORDERFIRERESPONSE_ID;
	if(id->dumpEvent(id,ev,evSrc)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
	return (id->testResult=id->sendMessage(id, ev));
}
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_ORDERSPEEDREJECT[]={
	{15,"Param1",sizeof(int), offsetof(TAT_SIG_ORDERSPEEDREJECT, Param1), TAT_Dump_int},
	{16,"Param2",sizeof(int), offsetof(TAT_SIG_ORDERSPEEDREJECT, Param2), TAT_Dump_int}
};
TAT_TEST_RESULT TAT_Send_ORDERSPEEDREJECT ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, int Param2)
{
	((TAT_SIG_ORDERSPEEDREJECT *)ev->eventData)->Param1=Param1;
	((TAT_SIG_ORDERSPEEDREJECT *)ev->eventData)->Param2=Param2;
	ev->eventID=TAT_S_ORDERSPEEDREJECT_ID;
	if(id->dumpEvent(id,ev,evSrc)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
	return (id->testResult=id->sendMessage(id, ev));
}
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_ORDERSPEEDREQUEST[]={
	{17,"Param1",sizeof(int), offsetof(TAT_SIG_ORDERSPEEDREQUEST, Param1), TAT_Dump_int},
	{18,"Param2",sizeof(int), offsetof(TAT_SIG_ORDERSPEEDREQUEST, Param2), TAT_Dump_int},
	{19,"Param3",sizeof(float), offsetof(TAT_SIG_ORDERSPEEDREQUEST, Param3), TAT_Dump_float}
};
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_ORDERSPEEDRESPONSE[]={
	{20,"Param1",sizeof(int), offsetof(TAT_SIG_ORDERSPEEDRESPONSE, Param1), TAT_Dump_int},
	{21,"Param2",sizeof(int), offsetof(TAT_SIG_ORDERSPEEDRESPONSE, Param2), TAT_Dump_int}
};
TAT_TEST_RESULT TAT_Send_ORDERSPEEDRESPONSE ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, int Param2)
{
	((TAT_SIG_ORDERSPEEDRESPONSE *)ev->eventData)->Param1=Param1;
	((TAT_SIG_ORDERSPEEDRESPONSE *)ev->eventData)->Param2=Param2;
	ev->eventID=TAT_S_ORDERSPEEDRESPONSE_ID;
	if(id->dumpEvent(id,ev,evSrc)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
	return (id->testResult=id->sendMessage(id, ev));
}
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_ORDERTURNREJECT[]={
	{22,"Param1",sizeof(int), offsetof(TAT_SIG_ORDERTURNREJECT, Param1), TAT_Dump_int},
	{23,"Param2",sizeof(int), offsetof(TAT_SIG_ORDERTURNREJECT, Param2), TAT_Dump_int}
};
TAT_TEST_RESULT TAT_Send_ORDERTURNREJECT ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, int Param2)
{
	((TAT_SIG_ORDERTURNREJECT *)ev->eventData)->Param1=Param1;
	((TAT_SIG_ORDERTURNREJECT *)ev->eventData)->Param2=Param2;
	ev->eventID=TAT_S_ORDERTURNREJECT_ID;
	if(id->dumpEvent(id,ev,evSrc)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
	return (id->testResult=id->sendMessage(id, ev));
}
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_ORDERTURNREQUEST[]={
	{24,"Param1",sizeof(int), offsetof(TAT_SIG_ORDERTURNREQUEST, Param1), TAT_Dump_int},
	{25,"Param2",sizeof(int), offsetof(TAT_SIG_ORDERTURNREQUEST, Param2), TAT_Dump_int},
	{26,"Param3",sizeof(float), offsetof(TAT_SIG_ORDERTURNREQUEST, Param3), TAT_Dump_float}
};
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_ORDERTURNRESPONSE[]={
	{27,"Param1",sizeof(int), offsetof(TAT_SIG_ORDERTURNRESPONSE, Param1), TAT_Dump_int},
	{28,"Param2",sizeof(int), offsetof(TAT_SIG_ORDERTURNRESPONSE, Param2), TAT_Dump_int}
};
TAT_TEST_RESULT TAT_Send_ORDERTURNRESPONSE ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, int Param2)
{
	((TAT_SIG_ORDERTURNRESPONSE *)ev->eventData)->Param1=Param1;
	((TAT_SIG_ORDERTURNRESPONSE *)ev->eventData)->Param2=Param2;
	ev->eventID=TAT_S_ORDERTURNRESPONSE_ID;
	if(id->dumpEvent(id,ev,evSrc)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
	return (id->testResult=id->sendMessage(id, ev));
}
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_SHIPSCURRENTSTATE[]={
	{29,"Param1",sizeof(int), offsetof(TAT_SIG_SHIPSCURRENTSTATE, Param1), TAT_Dump_int},
	{30,"Param2",sizeof(char*), offsetof(TAT_SIG_SHIPSCURRENTSTATE, Param2), TAT_Dump_String}
};
TAT_TEST_RESULT TAT_Send_SHIPSCURRENTSTATE ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, char* Param2)
{
	((TAT_SIG_SHIPSCURRENTSTATE *)ev->eventData)->Param1=Param1;
	((TAT_SIG_SHIPSCURRENTSTATE *)ev->eventData)->Param2=Param2;
	ev->eventID=TAT_S_SHIPSCURRENTSTATE_ID;
	if(id->dumpEvent(id,ev,evSrc)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
	return (id->testResult=id->sendMessage(id, ev));
}
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_STARTSIMULATION[]={
	{31,"Param1",sizeof(int), offsetof(TAT_SIG_STARTSIMULATION, Param1), TAT_Dump_int}
};
TAT_TEST_RESULT TAT_Send_STARTSIMULATION ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1)
{
	((TAT_SIG_STARTSIMULATION *)ev->eventData)->Param1=Param1;
	ev->eventID=TAT_S_STARTSIMULATION_ID;
	if(id->dumpEvent(id,ev,evSrc)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
	return (id->testResult=id->sendMessage(id, ev));
}
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_STRATEGYLOSE[]={
	{32,"Param1",sizeof(int), offsetof(TAT_SIG_STRATEGYLOSE, Param1), TAT_Dump_int}
};
TAT_TEST_RESULT TAT_Send_STRATEGYLOSE ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1)
{
	((TAT_SIG_STRATEGYLOSE *)ev->eventData)->Param1=Param1;
	ev->eventID=TAT_S_STRATEGYLOSE_ID;
	if(id->dumpEvent(id,ev,evSrc)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
	return (id->testResult=id->sendMessage(id, ev));
}
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_STRATEGYVICTORY[]={
	{33,"Param1",sizeof(int), offsetof(TAT_SIG_STRATEGYVICTORY, Param1), TAT_Dump_int}
};
TAT_TEST_RESULT TAT_Send_STRATEGYVICTORY ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1)
{
	((TAT_SIG_STRATEGYVICTORY *)ev->eventData)->Param1=Param1;
	ev->eventID=TAT_S_STRATEGYVICTORY_ID;
	if(id->dumpEvent(id,ev,evSrc)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
	return (id->testResult=id->sendMessage(id, ev));
}
static TAT_SIG_PARAM_DEF tat_SIG_PARAM_VISIBLESHIP[]={
	{34,"Param1",sizeof(int), offsetof(TAT_SIG_VISIBLESHIP, Param1), TAT_Dump_int},
	{35,"Param2",sizeof(char*), offsetof(TAT_SIG_VISIBLESHIP, Param2), TAT_Dump_String}
};
TAT_TEST_RESULT TAT_Send_VISIBLESHIP ( TAT_TEST_INSTANCE * id, TAT_EVENT_INSTANCE *ev, TAT_EVENT_INSTANCE *evSrc, int Param1, char* Param2)
{
	((TAT_SIG_VISIBLESHIP *)ev->eventData)->Param1=Param1;
	((TAT_SIG_VISIBLESHIP *)ev->eventData)->Param2=Param2;
	ev->eventID=TAT_S_VISIBLESHIP_ID;
	if(id->dumpEvent(id,ev,evSrc)!=TAT_TEST_CONTINUE) return TAT_TEST_CRITICAL;
	return (id->testResult=id->sendMessage(id, ev));
}
static TAT_SIGNAL_DEF tat_SignalDefinition[]={
	{    TAT_S_DESTROYSHIP_ID,	"DESTROYSHIP", sizeof(TAT_SIG_DESTROYSHIP), 3, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_DESTROYSHIP, 100},
	{TAT_S_FINISHSIMULATION_ID,	"FINISHSIMULATION", sizeof(TAT_SIG_FINISHSIMULATION), 2, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_FINISHSIMULATION, 100},
	{TAT_S_INITDATACOMPLETE_ID,	"INITDATACOMPLETE", 0, 0, NULL, 100},
	{   TAT_S_MESSAGEERROR_ID,	"MESSAGEERROR", sizeof(TAT_SIG_MESSAGEERROR), 1, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_MESSAGEERROR, 100},
	{     TAT_S_MESSAGELOG_ID,	"MESSAGELOG", sizeof(TAT_SIG_MESSAGELOG), 1, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_MESSAGELOG, 100},
	{TAT_S_ORDERFIREREJECT_ID,	"ORDERFIREREJECT", sizeof(TAT_SIG_ORDERFIREREJECT), 2, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_ORDERFIREREJECT, 100},
	{TAT_S_ORDERFIREREQUEST_ID,	"ORDERFIREREQUEST", sizeof(TAT_SIG_ORDERFIREREQUEST), 4, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_ORDERFIREREQUEST, 100},
	{TAT_S_ORDERFIRERESPONSE_ID,	"ORDERFIRERESPONSE", sizeof(TAT_SIG_ORDERFIRERESPONSE), 2, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_ORDERFIRERESPONSE, 100},
	{TAT_S_ORDERSPEEDREJECT_ID,	"ORDERSPEEDREJECT", sizeof(TAT_SIG_ORDERSPEEDREJECT), 2, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_ORDERSPEEDREJECT, 100},
	{TAT_S_ORDERSPEEDREQUEST_ID,	"ORDERSPEEDREQUEST", sizeof(TAT_SIG_ORDERSPEEDREQUEST), 3, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_ORDERSPEEDREQUEST, 100},
	{TAT_S_ORDERSPEEDRESPONSE_ID,	"ORDERSPEEDRESPONSE", sizeof(TAT_SIG_ORDERSPEEDRESPONSE), 2, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_ORDERSPEEDRESPONSE, 100},
	{TAT_S_ORDERTURNREJECT_ID,	"ORDERTURNREJECT", sizeof(TAT_SIG_ORDERTURNREJECT), 2, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_ORDERTURNREJECT, 100},
	{TAT_S_ORDERTURNREQUEST_ID,	"ORDERTURNREQUEST", sizeof(TAT_SIG_ORDERTURNREQUEST), 3, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_ORDERTURNREQUEST, 100},
	{TAT_S_ORDERTURNRESPONSE_ID,	"ORDERTURNRESPONSE", sizeof(TAT_SIG_ORDERTURNRESPONSE), 2, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_ORDERTURNRESPONSE, 100},
	{TAT_S_SHIPSCURRENTSTATE_ID,	"SHIPSCURRENTSTATE", sizeof(TAT_SIG_SHIPSCURRENTSTATE), 2, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_SHIPSCURRENTSTATE, 100},
	{TAT_S_STARTSIMULATION_ID,	"STARTSIMULATION", sizeof(TAT_SIG_STARTSIMULATION), 1, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_STARTSIMULATION, 100},
	{   TAT_S_STRATEGYLOSE_ID,	"STRATEGYLOSE", sizeof(TAT_SIG_STRATEGYLOSE), 1, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_STRATEGYLOSE, 100},
	{TAT_S_STRATEGYVICTORY_ID,	"STRATEGYVICTORY", sizeof(TAT_SIG_STRATEGYVICTORY), 1, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_STRATEGYVICTORY, 100},
	{    TAT_S_VISIBLESHIP_ID,	"VISIBLESHIP", sizeof(TAT_SIG_VISIBLESHIP), 2, (TAT_SIG_PARAM_DEF *)&tat_SIG_PARAM_VISIBLESHIP, 100}
};


static int _ssort(const void *x1, const void *x2)
{
	return (( TAT_SIGNAL_DEF * ) x1 )->signalID - (( TAT_SIGNAL_DEF * ) x2 )->signalID;
}
static int _isort(const void *x1, const void *x2)
{
	return (( TAT_INSTANCE_DEF * ) x1 )->instanceID - (( TAT_INSTANCE_DEF * ) x2 )->instanceID;
}
TAT_TEST_RESULT TAT_Init_battleshipstest (TAT_TEST_INSTANCE * id)
{
	if (!id) return TAT_TEST_CRITICAL;
	id->signalCount = 19;
	id->signalDef = (TAT_SIGNAL_DEF *)&tat_SignalDefinition;
	id->instanceCount = 2;
	id->instanceDef = (TAT_INSTANCE_DEF *)&tat_InstanceDefinition;
	qsort(id->signalDef, id->signalCount, sizeof(TAT_SIGNAL_DEF), _ssort);
	qsort(id->instanceDef, id->instanceCount, sizeof(TAT_INSTANCE_DEF), _isort);
	id->currSuiteName = "battleshipstest";
	id->testCount = 1;
	id->testTable = (TAT_TEST_TABLE *)&TAT_battleshipstest_TestTable;
	return TAT_TEST_CONTINUE;
}
TAT_TEST_TABLE TAT_battleshipstest_TestTable[]={
{"test15N0", TAT_T_battleshipstest_test15N0, TAT_TI_battleshipstest_test15N0}};
