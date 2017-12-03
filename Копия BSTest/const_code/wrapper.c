/******************************************************************************
*
*       COPYRIGHT 2001-2003 MOTOROLA, ALL RIGHTS RESERVED
*
*       The code is the property of Motorola St.Petersburg Software Development
*       and is Motorola Confidential Proprietary Information.
*
*       The copyright notice above does not evidence any
*       actual or intended publication of such source code.
*
* Functions:    
*
* History:      Use the ClearCase command "History"
*               to display revision history information.
*               
* Description:  Test suite "battleshipstest" wrapper functions
*
* Notes:        None
*
******************************************************************************/
/* Standart include files */
#include "wrapper.h"

#include "stdlib.h"
TAT_TEST_INSTANCE * TI_ID;
static TAT_TIME_TYPE battleshipstest_Clock=0;

TAT_TEST_RESULT res;

struct {
	TAT_EVENT_INSTANCE** data;
	int head;
	int tail;
	int max;
} QueueToSDL;

int InitSDLQueue(int maxsize)
{
	QueueToSDL.head = 0;
	QueueToSDL.tail = 0;
	QueueToSDL.max = maxsize;
	QueueToSDL.data = malloc(maxsize*sizeof(TAT_EVENT_INSTANCE*));
	return 1;
}

int PushSDLQueue(TAT_EVENT_INSTANCE* element)
{
	QueueToSDL.data[QueueToSDL.tail] = malloc(sizeof(TAT_EVENT_INSTANCE));
	memcpy(QueueToSDL.data[QueueToSDL.tail],element,sizeof(TAT_EVENT_INSTANCE));
	QueueToSDL.tail++;
	if(QueueToSDL.tail==QueueToSDL.max)
		QueueToSDL.tail=0;
	return 1;
}

int PopSDLQueue(TAT_EVENT_INSTANCE* element)
{
	memcpy(element,QueueToSDL.data[QueueToSDL.head],sizeof(TAT_EVENT_INSTANCE));
	free(QueueToSDL.data[QueueToSDL.head]);
	QueueToSDL.head++;
	if(QueueToSDL.head==QueueToSDL.max)
		QueueToSDL.head=0;
	return 1;
}

int CloseSDLQueue()
{
	free(QueueToSDL.data);
	return 1;
}

int IsSDLQueueEmpty()
{
	if(QueueToSDL.tail==QueueToSDL.head)
		return 1;
	return 0;
}

/************************************************************************************
*
* Function    : battleshipstest_resetSys
*
* Description : This funtion invoked from test to initialize testing system
*
* Return      : TAT_TEST_CONTINUE - if all OK
*               TAT_TEST_CRITICAL - if something wrong
*
* Notes       : 
*
*************************************************************************************/
TAT_TEST_RESULT battleshipstest_resetSys(TAT_TEST_INSTANCE *id)
{
	int res = 0;

	battleshipstest_Clock=0;

	/* TODO: Add necessary functionality to initialaize testing system */

	if ( res != 0 )
	{
		id->testStatus = TAT_ERR_RESET_IUT;
		return TAT_TEST_CRITICAL;
	}
	else
		return TAT_TEST_CONTINUE;
}

/************************************************************************************
*
* Function    : battleshipstest_clockF
*
* Description : This funtion invoked from test to get current time value
*
* Return      : Current time value
*
* Notes       : 
*
*************************************************************************************/
TAT_TIME_TYPE battleshipstest_clockF (TAT_TEST_INSTANCE *id)
{
	/* TODO: Add necessary functionality to determine current time */

	return battleshipstest_Clock;
}

/************************************************************************************
*
* Function    : battleshipstest_startCase
*
* Description : This funtion invoked at the begining of test case
*
* Return      : TAT_TEST_CONTINUE - if all OK
*               TAT_TEST_CRITICAL - if something wrong
*
* Notes       : 
*
*************************************************************************************/
TAT_TEST_RESULT battleshipstest_startCase (TAT_TEST_INSTANCE *id)
{
	/* TODO: Add necessary functionality to execute */
	/* on the begining of each test case running    */

	return TAT_TEST_CONTINUE;
}

/************************************************************************************
*
* Function    : battleshipstest_finishCase
*
* Description : This funtion invoked at the ending of test case
*
* Return      : TAT_TEST_CONTINUE - if all OK
*               TAT_TEST_CRITICAL - if something wrong
*
* Notes       : 
*
*************************************************************************************/
TAT_TEST_RESULT battleshipstest_finishCase (TAT_TEST_INSTANCE *id)
{
	/* TODO: Add necessary functionality to execute */
	/* on the ending of each test case running    */

	return TAT_TEST_CONTINUE;
}

/************************************************************************************
*
* Function    : battleshipstest_sendMess
*
* Description : This funtion invoked from test to send signal to testing system
*
* Return      : TAT_TEST_CONTINUE - if all OK
*               TAT_TEST_CRITICAL - if something wrong
*
* Notes       : 
*
*************************************************************************************/
TAT_TEST_RESULT battleshipstest_sendMess(TAT_TEST_INSTANCE *id, TAT_EVENT_INSTANCE *event)
{
	int res = 0;

	if (!id || !event)
	{
		return TAT_TEST_CRITICAL;
	}

	if (event->eventType == TAT_SEND_EV)
		PushSDLQueue(event);

	if ( res != 0 )
	{
		id->testStatus = TAT_ERR_SEND_EVENT;
		return TAT_TEST_CRITICAL;
	}
	else
		return TAT_TEST_CONTINUE;
}

TAT_SIG_FINISHSIMULATION model_sigFINISHSIMULATION = { 0, 0 };
TAT_INSTANCE_ID instances_evFINISHSIMULATION[] = {0, 0};
TAT_EVENT_INSTANCE model_evFINISHSIMULATION = { TAT_RECV_EV, TAT_S_FINISHSIMULATION_ID, &model_sigFINISHSIMULATION, {{0,0}, {0,0}, ""},2,
 instances_evFINISHSIMULATION, NULL, 0, NULL, TAT_VERDICT_PASS, -1, NULL, NULL};

TAT_SIG_MESSAGEERROR model_sigMESSAGEERROR = { 0 };
TAT_INSTANCE_ID instances_evMESSAGEERROR[] = {0, 0};
TAT_EVENT_INSTANCE model_evMESSAGEERROR = { TAT_RECV_EV, TAT_S_MESSAGEERROR_ID, &model_sigMESSAGEERROR, {{0,0}, {0,0}, ""},2,
 instances_evMESSAGEERROR, NULL, 0, NULL, TAT_VERDICT_PASS, -1, NULL, NULL};

TAT_SIG_MESSAGELOG model_sigMESSAGELOG = { 0 };
TAT_INSTANCE_ID instances_evMESSAGELOG[] = {0, 0};
TAT_EVENT_INSTANCE model_evMESSAGELOG = { TAT_RECV_EV, TAT_S_MESSAGELOG_ID, &model_sigMESSAGELOG, {{0,0}, {0,0}, ""},2,
 instances_evMESSAGELOG, NULL, 0, NULL, TAT_VERDICT_PASS, -1, NULL, NULL};

TAT_SIG_ORDERFIREREQUEST model_sigORDERFIREREQUEST = { 0, 0, 0, 0 };
TAT_INSTANCE_ID instances_evORDERFIREREQUEST[] = {0, 0};
TAT_EVENT_INSTANCE model_evORDERFIREREQUEST = { TAT_RECV_EV, TAT_S_ORDERFIREREQUEST_ID, &model_sigORDERFIREREQUEST, {{0,0}, {0,0}, ""},2,
 instances_evORDERFIREREQUEST, NULL, 0, NULL, TAT_VERDICT_PASS, -1, NULL, NULL};

TAT_SIG_ORDERSPEEDREQUEST model_sigORDERSPEEDREQUEST = { 0, 0, 0 };
TAT_INSTANCE_ID instances_evORDERSPEEDREQUEST[] = {0, 0};
TAT_EVENT_INSTANCE model_evORDERSPEEDREQUEST = { TAT_RECV_EV, TAT_S_ORDERSPEEDREQUEST_ID, &model_sigORDERSPEEDREQUEST, {{0,0}, {0,0}, ""},2,
 instances_evORDERSPEEDREQUEST, NULL, 0, NULL, TAT_VERDICT_PASS, -1, NULL, NULL};

TAT_SIG_ORDERTURNREQUEST model_sigORDERTURNREQUEST = { 0, 0, 0 };
TAT_INSTANCE_ID instances_evORDERTURNREQUEST[] = {0, 0};
TAT_EVENT_INSTANCE model_evORDERTURNREQUEST = { TAT_RECV_EV, TAT_S_ORDERTURNREQUEST_ID, &model_sigORDERTURNREQUEST, {{0,0}, {0,0}, ""},2,
 instances_evORDERTURNREQUEST, NULL, 0, NULL, TAT_VERDICT_PASS, -1, NULL, NULL};

/************************************************************************************
*
* Function    : battleshipstest_Recv_FINISHSIMULATION
*
* Description : This funtion transfer signals from testing system to test
*
* Return      : 1
*
* Notes       : 
*
*************************************************************************************/
int battleshipstest_Recv_FINISHSIMULATION(int Param1, int Param2, int from, int to)
{
	model_sigFINISHSIMULATION.Param1 = Param1;
	model_sigFINISHSIMULATION.Param2 = Param2;
	instances_evFINISHSIMULATION[0] = from;
	instances_evFINISHSIMULATION[1] = to;
	TAT_ReceiveMessage(TI_ID, &model_evFINISHSIMULATION);
	return 1;
}

/************************************************************************************
*
* Function    : battleshipstest_Recv_MESSAGEERROR
*
* Description : This funtion transfer signals from testing system to test
*
* Return      : 1
*
* Notes       : 
*
*************************************************************************************/
int battleshipstest_Recv_MESSAGEERROR(char* Param1, int from, int to)
{
	model_sigMESSAGEERROR.Param1 = Param1;
	instances_evMESSAGEERROR[0] = from;
	instances_evMESSAGEERROR[1] = to;
	TAT_ReceiveMessage(TI_ID, &model_evMESSAGEERROR);
	return 1;
}

/************************************************************************************
*
* Function    : battleshipstest_Recv_MESSAGELOG
*
* Description : This funtion transfer signals from testing system to test
*
* Return      : 1
*
* Notes       : 
*
*************************************************************************************/
int battleshipstest_Recv_MESSAGELOG(char* Param1, int from, int to)
{
	model_sigMESSAGELOG.Param1 = Param1;
	instances_evMESSAGELOG[0] = from;
	instances_evMESSAGELOG[1] = to;
	TAT_ReceiveMessage(TI_ID, &model_evMESSAGELOG);
	return 1;
}

/************************************************************************************
*
* Function    : battleshipstest_Recv_ORDERFIREREQUEST
*
* Description : This funtion transfer signals from testing system to test
*
* Return      : 1
*
* Notes       : 
*
*************************************************************************************/
int battleshipstest_Recv_ORDERFIREREQUEST(int Param1, int Param2, int Param3, char* Param4, int from, int to)
{
	model_sigORDERFIREREQUEST.Param1 = Param1;
	model_sigORDERFIREREQUEST.Param2 = Param2;
	model_sigORDERFIREREQUEST.Param3 = Param3;
	model_sigORDERFIREREQUEST.Param4 = Param4;
	instances_evORDERFIREREQUEST[0] = from;
	instances_evORDERFIREREQUEST[1] = to;
	TAT_ReceiveMessage(TI_ID, &model_evORDERFIREREQUEST);
	return 1;
}

/************************************************************************************
*
* Function    : battleshipstest_Recv_ORDERSPEEDREQUEST
*
* Description : This funtion transfer signals from testing system to test
*
* Return      : 1
*
* Notes       : 
*
*************************************************************************************/
int battleshipstest_Recv_ORDERSPEEDREQUEST(int Param1, int Param2, float Param3, int from, int to)
{
	model_sigORDERSPEEDREQUEST.Param1 = Param1;
	model_sigORDERSPEEDREQUEST.Param2 = Param2;
	model_sigORDERSPEEDREQUEST.Param3 = Param3;
	instances_evORDERSPEEDREQUEST[0] = from;
	instances_evORDERSPEEDREQUEST[1] = to;
	TAT_ReceiveMessage(TI_ID, &model_evORDERSPEEDREQUEST);
	return 1;
}

/************************************************************************************
*
* Function    : battleshipstest_Recv_ORDERTURNREQUEST
*
* Description : This funtion transfer signals from testing system to test
*
* Return      : 1
*
* Notes       : 
*
*************************************************************************************/
int battleshipstest_Recv_ORDERTURNREQUEST(int Param1, int Param2, float Param3, int from, int to)
{
	model_sigORDERTURNREQUEST.Param1 = Param1;
	model_sigORDERTURNREQUEST.Param2 = Param2;
	model_sigORDERTURNREQUEST.Param3 = Param3;
	instances_evORDERTURNREQUEST[0] = from;
	instances_evORDERTURNREQUEST[1] = to;
	TAT_ReceiveMessage(TI_ID, &model_evORDERTURNREQUEST);
	return 1;
}

int WrapInit()
{
	InitSDLQueue(128);

	/* Create and initialize test instance structure */
	TI_ID = TAT_CreateTestInstance(128, 3, 4096, battleshipstest_resetSys,
 												 battleshipstest_sendMess,
 												 battleshipstest_clockF,
 												 battleshipstest_startCase,
 												 battleshipstest_finishCase);
	if (!TI_ID)
	{
		printf("ERROR: can't initialize test instance\n");
		return 1;
	}

	/* Register dumping modules */
	TAT_RegisterLogFunc(TI_ID, TAT_OpenLogMPR, TAT_LogFuncMPR, TAT_CloseLogMPR);
	TAT_RegisterLogFunc(TI_ID, TAT_OpenLogTXT, TAT_LogFuncTXT, TAT_CloseLogTXT);

	/* Call generated function to additional initializing test instance structure */
	res = TAT_StartSuite(TI_ID, TAT_Init_battleshipstest);

	return (res==TAT_TEST_CRITICAL);
}

int WrapRun()
{
	/* Run test suite */
	while (res == TAT_TEST_CONTINUE)
	{
		res = TAT_ContinueSuite(TI_ID);

		/* TODO: Realize functionality to transfer of control to testing system */
		/*       to get response to test`s action.                              */
		return 0;
	}

	if (res == TAT_TEST_CRITICAL)
	{
		printf("ERROR: critical error during execution\n");
		return 1;
	}
	return 1;
}

int WrapClose()
{
	CloseSDLQueue();
	/* Free test instance structure */
	TAT_FreeTestInstance(TI_ID);
	return (res==TAT_TEST_CRITICAL);
}
