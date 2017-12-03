#ifndef WRAPPER_H
#define WRAPPER_H
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
* Description:  Test suite "battleshipstest" wrapper header
*
* Notes:        None
*
******************************************************************************/

#include <stdio.h>
#include "testkern.h"
#include "../test/battleshipstest.h"
#include "txtlog.h"
#include "mprlog.h"


extern TAT_SIG_FINISHSIMULATION model_sigFINISHSIMULATION;
extern TAT_EVENT_INSTANCE model_evFINISHSIMULATION;


extern TAT_SIG_MESSAGEERROR model_sigMESSAGEERROR;
extern TAT_EVENT_INSTANCE model_evMESSAGEERROR;


extern TAT_SIG_MESSAGELOG model_sigMESSAGELOG;
extern TAT_EVENT_INSTANCE model_evMESSAGELOG;


extern TAT_SIG_ORDERFIREREQUEST model_sigORDERFIREREQUEST;
extern TAT_EVENT_INSTANCE model_evORDERFIREREQUEST;


extern TAT_SIG_ORDERSPEEDREQUEST model_sigORDERSPEEDREQUEST;
extern TAT_EVENT_INSTANCE model_evORDERSPEEDREQUEST;


extern TAT_SIG_ORDERTURNREQUEST model_sigORDERTURNREQUEST;
extern TAT_EVENT_INSTANCE model_evORDERTURNREQUEST;

int battleshipstest_Recv_FINISHSIMULATION(int, int, int, int);
int battleshipstest_Recv_MESSAGEERROR(char*, int, int);
int battleshipstest_Recv_MESSAGELOG(char*, int, int);
int battleshipstest_Recv_ORDERFIREREQUEST(int, int, int, char*, int, int);
int battleshipstest_Recv_ORDERSPEEDREQUEST(int, int, float, int, int);
int battleshipstest_Recv_ORDERTURNREQUEST(int, int, float, int, int);

#endif /* WRAPPER_H */
