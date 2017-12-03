#ifndef X_SCTTYPES_H
#define X_SCTTYPES_H


/*******************************************************************************
Copyright by Telesoft Europe AB 1990, 1991.
Copyright by Telelogic Malmoe AB 1991, 1992, 1993, 1994.
Copyright by Telelogic AB 1994 - 2001.
This Program is owned by Telelogic and is protected by national
copyright laws and international copyright treaties. Telelogic
grants you the right to use this Program on one computer or in
one local computer network at any one time.
Under this License you may only modify the source code for the purpose
of adapting it to your environment. You must reproduce and include
any copyright and trademark notices on all copies of the source code.
You may not use, copy, merge, modify or transfer the Program except as
provided in this License.
Telelogic does not warrant that the Program will meet your
requirements or that the operation of the Program will be
uninterrupted and error free. You are solely responsible that the
selection of the Program and the modification of the source code
will achieve your intended results and that the results are actually
obtained.
*******************************************************************************/

/*
# clearcase scttypes.h@@/main/104 : 2001/08/21 jk
*/

/*
FILE INDEX
00   Utility macros
01   Main User oriented #ifdef
02   Dependent #ifdef
03   C Library
04   SDL Model macro expansions
05   Utility #ifdef
06   Constants
07   Forward Declarations
08   SDL predefined types (except SDL_PId)
09   SDL_PId
10   Signal Set
11   Procedure ( = Prd )
12   Process ( = Prs )
13   Timer
14   Signal
15   Symbol Table
16   Global Data Structure
17   sctos
18   sctenv
19   sctsdl
20   sctpost
21   sctutil
*/


/****+***************************************************************
00   Utility macros
********************************************************************/

#ifndef XNO_VERSION_CHECK
#if defined(XSCT_CBASIC) || defined(XSCT_CADVANCED)
#ifndef SCT_VERSION_4_3
Version_of_code_generator_and_library_does_not_match force_error;
#endif
#endif
#endif

#define COMMENT(P)
/* to be used for inserting comments in in-line C-code in SDL.
   the syntax is: COMMENT(( your free format comment text )) */

#ifdef OSE_CC
#include <sys/time.h>
#include "ose.h"
#endif

#ifdef VXWORKS_CC
#include "vxWorks.h"
#endif

#ifdef THREADOSE
#include "ose.h"
#endif /* THREADOSE */
#ifdef THREADVXWORKS
#if defined(THREADLIGHT_TRACE) || defined(THREADLIGHT_ERROR)
#include "errno.h"
#endif
#include "vxWorks.h"
#include "semLib.h"
#include "msgQLib.h"        /* msgQCreate msgQDelete msgQSend msgQReceive */
                            /* msgQNumMsgs */
#include "taskLib.h"        /* taskSpawn */
#include "semaphore.h"      /* POSIX semaphores */
#endif

#ifdef CHORUS_CC
#include <include/chorus.h>
#endif

#ifdef CHORUSCLASSIX_CC
#include <chorus.h>
#endif

#ifdef PSOS_C
#include <psos.h>
#include <drv_intf.h>
#include <prepc.h>
#include <stdio.h>
 
#define abs(j) ((j)<0?-(j):(j))
 
#endif

#ifdef VRTX_C
#include <vrtxil.h>
#endif


/****+***************************************************************
01   Main User oriented #ifdef
********************************************************************/

/*---+---------------------------------------------------------------
     #ifdef SCTDEBCOM
-------------------------------------------------------------------*/
/* Simulator for host. Can be executed from SDL Suite or from OS.
   Requires post.o */

/* This is kernel Simulation in Generate-Options. */

#ifdef SCTDEBCOM

#define XPRSPRIO
#define XEALL
#define XMONITOR
#define XTRACE
#define XCTRACE
#define XMSCE
#define XCOVERAGE

#define XGRTRACE
#define XPMCOMM
#define XSDLENVUI
#define XITEXCOMM
#define XSIMULATORUI

#define XPERFSIM

#endif

/*---+---------------------------------------------------------------
     #ifdef SCTDEB
-------------------------------------------------------------------*/
/* Stand alone simulator for any environment. Should be executed from OS. */

#ifdef SCTDEB

#define XPRSPRIO
#define XEALL
#define XMONITOR
#define XTRACE
#define XCTRACE
#define XMSCE
#define XCOVERAGE

#endif

/*---+---------------------------------------------------------------
     #ifdef SCTDEBCLCOM
-------------------------------------------------------------------*/
/* Simulator with real time for host. Can be executed from SDL Suite
   or from OS.
   Requires post.o */

/* This is kernel RealTimeSimulation in Generate-Options. */

#ifdef SCTDEBCLCOM

#define XCLOCK
#define XPRSPRIO
#define XEALL
#define XMONITOR
#define XTRACE
#define XCTRACE
#define XMSCE
#define XCOVERAGE

#define XGRTRACE
#define XPMCOMM
#define XSDLENVUI
/* #define XITEXCOMM */
#define XSIMULATORUI

#endif

/*---+---------------------------------------------------------------
     #ifdef SCTDEBCLENVCOM
-------------------------------------------------------------------*/
/* Simulator, with real time and env functions,
   for any environment. May be executed from OS or form Sim-UI. */

/* This is kernel ApplicationDebug in Generate-Options. */

#ifdef SCTDEBCLENVCOM

#define XCALENDERCLOCK
#define XPRSPRIO
#define XENV
#define XPRSOPT
#define XEALL
#define XMONITOR
#define XTRACE
#define XCTRACE
#define XMSCE
#define XCOVERAGE

#define XGRTRACE
#define XPMCOMM
#define XSDLENVUI
/* #define XITEXCOMM */
#define XSIMULATORUI

#endif

/*---+---------------------------------------------------------------
     #ifdef SCTDEBCL
-------------------------------------------------------------------*/
/* Stand alone simulator with real time for any environment.
   Should be executed from OS. */

#ifdef SCTDEBCL

#define XCLOCK
#define XPRSPRIO
#define XEALL
#define XMONITOR
#define XTRACE
#define XCTRACE
#define XMSCE
#define XCOVERAGE

#endif

/*---+---------------------------------------------------------------
     #ifdef SCTDEBCLENV
-------------------------------------------------------------------*/
/* Stand alone simulator, with real time and env functions,
   for any environment. Should be executed from OS. */

#ifdef SCTDEBCLENV

#define XCALENDERCLOCK
#define XENV
#define XPRSPRIO
#define XPRSOPT
#define XEALL
#define XMONITOR
#define XTRACE
#define XCTRACE
#define XMSCE
#define XCOVERAGE

#endif

/*---+---------------------------------------------------------------
     #ifdef SCTAPPLENV
-------------------------------------------------------------------*/
/* Application without clock. */

#ifdef SCTAPPLENV

#define XENV
#define XPRSPRIO
#define XOPTSIGPARA
#define XOPTDCL
#define XOPTFPAR
#define XOPTSTRUCT
#define XOPTLIT
#define XPRSOPT

#ifdef XSCT_CBASIC
C-Basic generator cannot be used for applications
#endif

#endif

/*---+---------------------------------------------------------------
     #ifdef SCTAPPLCLENV
-------------------------------------------------------------------*/
/* Application!. */

/* This is kernel Application in Generate-Options. */

#ifdef SCTAPPLCLENV

#define XCALENDERCLOCK
#define XENV
#define XPRSPRIO
#define XOPT
#define XPRSOPT

#ifdef XSCT_CBASIC
C-Basic generator cannot be used for applications
#endif

#endif

/*---+---------------------------------------------------------------
     #ifdef SCTOPT1APPLCLENV
-------------------------------------------------------------------*/
/* Application with minimal memory requirements.
   Real cannot be used. 
   no Channel information */

#ifdef SCTOPT1APPLCLENV

#define XCALENDERCLOCK
#define XENV
#define XPRSPRIO
#define XOPT
#define XOPTCHAN
#define XPRSOPT
#define XNOUSEOFREAL

#ifdef XSCT_CBASIC
C-Basic generator cannot be used for applications
#endif

#endif

/*---+---------------------------------------------------------------
     #ifdef SCTOPT2APPLCLENV
-------------------------------------------------------------------*/
/* Application with minimal memory requirements.
   Real cannot be used. 
   const for all Channel information */

#ifdef SCTOPT2APPLCLENV

#define XCALENDERCLOCK
#define XENV
#define XPRSPRIO
#define XOPT
#define XCONST const
#define XCONST_COMP const
#define XPRSOPT
#define XNOUSEOFREAL

#ifdef XSCT_CBASIC
C-Basic generator cannot be used for applications
#endif

#endif

/*---+---------------------------------------------------------------
     #ifdef SCTPERFSIM
-------------------------------------------------------------------*/
/* Suitable for execution of performance simulations. */

#ifdef SCTPERFSIM

#define XPRSPRIO
#define XEALL

#endif



/****+***************************************************************
02   Dependent #ifdef
********************************************************************/

#ifdef USER_CONFIG
#include "sct_mcf.h"
#elif defined(AUTOMATIC_CONFIG)
#include "sdl_cfg.h"
#endif

/*---+---------------------------------------------------------------
     #ifdef THREADLIGHT_POSIX_THREADS
-------------------------------------------------------------------*/
/* Threaded Light OS-integration. Application using POSIX threads.
   Currently tested only on Linux. */

#ifdef THREADLIGHT_POSIX_THREADS
#include "sctthltypes.h"
#endif

/*---+---------------------------------------------------------------
     Dependent user oriented #ifdef
-------------------------------------------------------------------*/

#define XFREEVARS
#define XFREESIGNALFUNCS

#ifdef XEALL
/* Turn on all XE... .*/
#define XEOUTPUT
#define XEINTDIV
#define XEREALDIV
#define XECSOP
#define XEFIXOF
#define XERANGE
#define XEINDEX
#define XECREATE
#define XEDECISION
#define XEEXPORT
#define XEVIEW
#define XEERROR
#define XASSERT
#define XEUNION
#define XEOPTIONAL
#define XECHOICE
#define XEREF
#define XEOWN
#define XECODER
#endif

#ifdef XOPT
#define XOPTSIGPARA
#define XOPTDCL
#define XOPTFPAR
#define XOPTSTRUCT
#define XOPTLIT
#define XOPTSORT
#endif

#ifdef XTENV
#define XENV
#endif

#ifdef XSDLENVUI
#ifndef XPMCOMM
#define XPMCOMM
#endif
#endif

/*---+---------------------------------------------------------------
     Dependent function oriented #ifdef
-------------------------------------------------------------------*/
#ifndef XCONST
#define XCONST
#endif
#ifndef XCONST_COMP
#define XCONST_COMP
#endif

#ifdef XEDECISION
#define XERRORSTATE
#endif

#if defined(XERANGE) || defined(XEINDEX) || defined(XMONITOR)
#define XTESTF
#endif

#if defined(XECSOP) || defined(XEFIXOF) || defined(XEINTDIV) || defined(XEREALDIV)
#define XOPERRORF
#endif

#if defined(XPMCOMM) || defined(XGRTRACE) || defined(XITEXCOMM)
#define XCONNECTPM
#endif

#if defined(XTESTF) || defined(XOPERRORF) || defined(XEOUTPUT) || defined(XECREATE) || defined(XEDECISION) || defined(XEEXPORT) || defined(XEVIEW) || defined(XEUNION) || defined(XEOPTIONAL) || defined(XCHOICE) || defined(XMONITOR) || defined(XTRACE) || defined(XCONNECTPM)
#define XREADANDWRITEF
#endif

#if defined(XMONITOR) || defined(XSIGLOG)
#define XNRINST
#define XSIGPATH
#endif

#if defined(XMONITOR) || defined(XSIGLOG) || defined(XPMCOMM) || defined(XREADANDWRITEF)
#define XIDNAMES
#endif

#ifdef XMONITOR
#define XPRSSENDER
#define XCOUNTRESETS
#define XREMOVETIMERSIG
#ifndef XENVSIGNALLIMIT
#define XENVSIGNALLIMIT 20
#endif
#define XCASELABELS
#endif
#define XCASEAFTERPRDLABELS

#if defined(XMONITOR) || defined(XGRTRACE)
#define XBREAKBEFORE
#endif

#if defined(XMONITOR) || defined(XGRTRACE) || defined(XTRACE) || defined(XMSCE) || defined(XREADANDWRITEF)
#define XSYMBTLINK
#endif

#if defined(XSIGPRSPRIO) || defined(XPRSSIGPRIO)
#ifdef XSIGPRIO
#undef XSIGPRIO
#endif
#ifdef XPRSPRIO
#undef XPRSPRIO
#endif
#endif

#ifdef XCALENDERCLOCK
#ifndef XCLOCK
#define XCLOCK
#endif
#endif

#if ! ( defined(XOPTSIGPARA) && defined(XOPTDCL) && defined(XOPTFPAR) && defined(XOPTSTRUCT) && defined(XOPTLIT) )
#ifdef XOPTSORT
  ERROR ILLEGAL_COMBINATION_OF_DEFINES
#endif
#endif

#if defined(XSIGPRSPRIO) && defined(XPRSSIGPRIO)
  ERROR ILLEGAL_COMBINATION_OF_DEFINES__XSIGPRSPRIO_XPRSSIGPRIO
#endif

#if defined(XSIGPRIO) && defined(XPRSPRIO)
  ERROR ILLEGAL_COMBINATION_OF_DEFINES__XSIGPRIO_XPRSPRIO
#endif

#if defined(XCOVERAGE) && !defined(XMONITOR)
  ERROR ILLEGAL_COMBINATION_OF_DEFINES__XCOVERAGE_!XMONITOR
#endif

#ifndef XTRACHANNELSTOENV
#define XTRACHANNELSTOENV  0
#define XTRACHANNELLIST
#endif

#ifndef XINPUTREFTYPE
#define XINPUTREFTYPE  int
#endif

#ifdef XEALLOC
#define XALLOC(SIZE,TYPEINFONODE) xAllocSort(SIZE,TYPEINFONODE)
#define XFREE(P,SIZE)             xFreeSort(P)
#else
#define XALLOC(SIZE,TYPEINFONODE) xAlloc(SIZE)
#define XFREE(P,SIZE)             xFree(P)
#endif


/****+***************************************************************
03   C Library
********************************************************************/

#define XPP_PROTO(P)    P
#define XPP_NOPROTO(P)
#define XPP(x)          x


/*---+---------------------------------------------------------------
     Compiler
-------------------------------------------------------------------*/
#if defined(__linux)
#define SCT_POSIX

#elif defined(__sun)
#define SCT_POSIX

#elif defined(__hpux)
#define SCT_POSIX

#elif defined(__CYGWIN__)
#define SCT_POSIX

#elif defined(QNX4_CC)
#define SCT_POSIX

#elif defined(__BORLANDC__)
#define SCT_WINDOWS

#elif defined(_MSC_VER)
#define SCT_WINDOWS

#else
#include "user_cc.h"

#endif


/*---+---------------------------------------------------------------
     General ANSI section
-------------------------------------------------------------------*/
#if defined(SCT_POSIX) || defined(SCT_WINDOWS)
#define XMULTIBYTE_SUPPORT
#endif

#define XCAT(P1,P2)     P1##P2

#ifdef XUSING_SCCD  /* Can only be used with the Microsoft compiler */
#define STRING_h XCAT(#,include <string.h>)
STRING_h
#define STDLIB_h XCAT(#,include <stdlib.h>)
STDLIB_h
#define LIMITS_h XCAT(#,include <limits.h>)
LIMITS_h
#define STDARG_h XCAT(#,include <stdarg.h>)
STDARG_h
#ifdef XREADANDWRITEF
#define STDIO_h XCAT(#,include <stdio.h>)
STDIO_h
#ifdef XMULTIBYTE_SUPPORT
#define LOCALE_h XCAT(#,include <locale.h>)
LOCALE_h
#endif
#endif

#else      /* not XUSING_SCCD */

#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#ifdef XREADANDWRITEF
#include <stdio.h>
#ifdef XMULTIBYTE_SUPPORT
#include <locale.h>
#endif
#endif
#endif      /* XUSING_SCCD */

#ifndef GETINTRAND
#define GETINTRAND      rand()
#endif
#ifndef GETINTRAND_MAX
#define GETINTRAND_MAX  RAND_MAX
#endif

/* Define xptrint to be an unsigned type of same size as a pointer.
   Assume pointers are 4 bytes */
#ifndef xptrint
#if (UINT_MAX < 4294967295)
#define xptrint         unsigned long
#define X_XPTRINT_LONG
#else
#define xptrint         unsigned
#endif
#endif

/* Define xint32 to be an int type of 4 bytes (or more) */
#ifndef xint32
#if (INT_MAX >= 2147483647)
#define xint32          int
#define X_XINT32_INT
#else
#define xint32          long int
#endif
#endif


/*---+---------------------------------------------------------------
     Nucleus MNT (Microsoft compiler)
-------------------------------------------------------------------*/
#ifdef NUCLEUS_MNT

#include <windows.h>
#include <winbase.h>
#include "hardware.h"
#include "nucleus.h"

#define XMAIN_NAME SDL_main

#define RTC 50  /* PC Real Time Clock */
#define MANAGER_STACK_SIZE (MINSTACK+4000)
#define MANAGER_TIME_SLICE 10
#define MANAGER_TASK_PRIORITY 5
#define MIN_ALLOCATION 50  /* Specifies the minimum no. of bytes in
                              each allocation from the memory pool.
                              Required for Application_initialize() */

extern NU_MEMORY_POOL System_Memory;
void XMAIN_NAME(UNSIGNED argc, VOID *argv);

#endif  /* NUCLEUS_MNT */



/****+***************************************************************
04   SDL Model macro expansions
********************************************************************/

/* ------------------ Variables at system level ------------------ */

#ifndef THREADLIGHT
#define XSYSTEMVARS \
   xSystemData  xSysD;
#define XSYSTEMVARS_H
#define XSYSDPRS_RQ(P)   xSysD.xReadyQueue
#define XSYSDPRS_TQ(P)   xSysD.xTimerQueue
#define XSYSDPRS_CL(P)   xSysD.xCheckList
#define THREADLIGHT_GLOBAL_VARS
#define THREADLIGHT_GLOBAL_INIT
#define THREADLIGHT_THREAD_VARS
#define THREADLIGHT_THREAD_INIT(SYSD)
#define THREADLIGHT_THREAD_BEGINNING(SYSD)
#define THREADLIGHT_LOCK_INPUTPORT(SYSD)
#define THREADLIGHT_UNLOCK_INPUTPORT(SYSD)
#define THREADLIGHT_WAIT_AND_UNLOCK_INPUTPORT(SYSD)
#define THREADLIGHT_SIGNAL_AND_UNLOCK_INPUTPORT(SYSD)
#define THREADLIGHT_LISTREAD_START
#define THREADLIGHT_LISTWRITE_START
#define THREADLIGHT_LISTACCESS_END
#define THREADLIGHT_EXPORT_START
#define THREADLIGHT_EXPORT_END
#define THREADLIGHT_START_THREAD(F, SYSD)
#define THREADLIGHT_STOP_THREAD(SYSD)
#define THREADLIGHT_AFTER_THREAD_START
#else
#define XSYSTEMVARS
#define XSYSTEMVARS_H
#define XSYSDPRS_RQ(P)   P->SysD->xReadyQueue
#define XSYSDPRS_TQ(P)   P->SysD->xTimerQueue
#define XSYSDPRS_CL(P)   P->SysD->xCheckList
#endif


/* ----------------- Extra components in IdNodes ----------------- */

  /* System, system type */
#define XCOMMON_EXTRAS

  /* System, system type */
#define XSYS_EXTRAS

  /* Package */
#define XPAC_EXTRAS

  /* Block, Block type */
#define XBLO_EXTRAS

  /* Block substructure */
#define XBLS_EXTRAS

  /* Process, Process type */
#define XPRS_EXTRAS(PRS_NAME)

  /* Service, Service type */
#define XSRV_EXTRAS

  /* Procedure */
#define XPRD_EXTRAS

  /* Signal */
#define XSIG_EXTRAS

  /* Signal parameter */
#define XSPA_EXTRAS

  /* Variable, formal parameter, struct component */
#define XVAR_EXTRAS

  /* Channel, signal route, gate */
#define XCHA_EXTRAS

  /* State */
#define XSTA_EXTRAS

  /* Sort, syntype */
#define XSRT_EXTRAS

  /* Literal */
#define XLIT_EXTRAS


/* ---------------- Variables in the PAD function ---------------- */

#ifdef XPRSSENDER
#define XPRSSENDERCOMP   SDL_PId  Sender;
#else
#define XPRSSENDERCOMP
#endif

#ifdef XTRACE
#define XTRACEDEFAULTCOMP   int Trace_Default;
#else
#define XTRACEDEFAULTCOMP
#endif

#ifdef XGRTRACE
#define XGRTRACECOMP   int GRTrace;
#else
#define XGRTRACECOMP
#endif

#ifdef XMSCE
#define XMSCETRACECOMP   int  MSCETrace;
#else
#define XMSCETRACECOMP
#endif

#if defined(XMONITOR) || defined(XTRACE)
#define XINTRANSCOMP   xbool InTransition;
#else
#define XINTRANSCOMP
#endif

#ifdef XMONITOR
#define XCALL_ADDR   int  CallAddress;
#else
#define XCALL_ADDR
#endif

#ifndef XNOUSEOFSERVICE
#define XSERVICE_COMP   xSrvNode ActiveSrv; xSrvNode SrvList;
#else
#define XSERVICE_COMP
#endif

#ifdef THREADLIGHT
#define XSYSDINPRS  struct xSystemData * SysD;
#else
#define XSYSDINPRS
#endif

#define PROCESS_VARS \
   xPrsNode       Pre; \
   xPrsNode       Suc; \
   int            RestartAddress; \
   xPrdNode       ActivePrd; \
   void (*RestartPAD) (xPrsNode  VarP); \
   XCALL_ADDR \
   XSERVICE_COMP \
   xPrsNode       NextPrs; \
   SDL_PId        Self; \
   xPrsIdNode     NameNode; \
   int            State; \
   xSignalNode    Signal; \
   xInputPortRec  InputPort; \
   SDL_PId        Parent; \
   SDL_PId        Offspring; \
   int            BlockInstNumber; \
   XSIGTYPE       pREPLY_Waited_For; \
   xSignalNode    pREPLY_Signal; \
   XSYSDINPRS \
   XPRSSENDERCOMP \
   XTRACEDEFAULTCOMP \
   XGRTRACECOMP \
   XMSCETRACECOMP \
   XINTRANSCOMP

#ifndef XNOUSEOFSERVICE
#define SERVICE_VARS \
   xSrvNode       NextSrv; \
   xPrsNode       ContainerPrs; \
   int            RestartAddress; \
   xPrdNode       ActivePrd; \
   void (*RestartPAD) (xPrsNode  VarP); \
   XCALL_ADDR \
   xSrvIdNode     NameNode; \
   int            State; \
   XSIGTYPE       pREPLY_Waited_For; \
   xSignalNode    pREPLY_Signal; \
   XINTRANSCOMP
#else
#define SERVICE_VARS
#endif

#define PROCEDURE_VARS \
   xPrdIdNode   NameNode; \
   xPrdNode     StaticFather; \
   xPrdNode     DynamicFather; \
   int          RestartAddress; \
   XCALL_ADDR \
   int (*RestartPRD) (xPrsNode  VarP); \
   xSignalNode  pREPLY_Signal; \
   int          State;

#define YPAD_TEMP_VARS \
   xPrdNode     yTempPrd; \
   xSignalNode  yOutputSignal;
#define YPRD_TEMP_VARS \
   xPrdNode     yTempPrd; \
   xSignalNode  yOutputSignal;
#define YPAD_YSVARP             void  *ySVarP = VarP->Signal;
#define YPAD_YVARP(VDEF_TYPE) \
   register VDEF_TYPE * yVarP = (VDEF_TYPE *)VarP;
#define YGLOBALSRV_YVARP \
   xPrsNode yVarP = (xPrsNode)VarP;
#define YPRD_YVARP(VDEF_TYPE) \
   register VDEF_TYPE * yVarP = (VDEF_TYPE *)VarP;
#define YGLOBALPRD_YVARP \
   xPrsNode yVarP = VarP;

#define SDL_SELF                yVarP->Self
#define SDL_PARENT              yVarP->Parent
#define SDL_OFFSPRING           yVarP->Offspring
#define SDL_SENDER              yVarP->Signal->Sender
#define XPRSNODE                xPrsNode
#define XNAMENODE               yVarP->NameNode
#define XNAMENODE_SRV           ySrvVarP->NameNode
#define XNAMENODE_PRD           yPrdVarP->NameNode


/* ------------------ Structure of PAD function ------------------ */

#define YPAD_PROTOTYPE(PAD)     extern void PAD (xPrsNode);
#define YPAD_FUNCTION(PAD)      extern void PAD (xPrsNode  VarP)
#define YPRD_PROTOTYPE(PAD)     extern int PAD (xPrsNode);
#define YPRD_FUNCTION(PAD)      extern int PAD (xPrsNode  VarP)

#define BEGIN_PAD(VDEF_TYPE)
#define LOOP_LABEL
#define LOOP_LABEL_SERVICEDECOMP
#define LOOP_LABEL_PRD
#define LOOP_LABEL_PRD_NOSTATE
#define BEGIN_START_TRANSITION(STARTUP_PAR_TYPE)
#define XEND_PRD  return 0;

#define SIGNAL_NAME(SIG_NAME, SIG_IDNODE) \
   SIG_IDNODE
#define XNONE_SIGNAL \
   xNoneSigId
#define XRPC_WAIT_STATE \
   -3
#define ERROR_STATE \
   -2
#define ASTERISK_STATE \
   -1
#define START_STATE \
   0
#define START_STATE_PRD \
   0

#define INSIGNAL_NAME           yVarP->Signal->NameNode
#define CALL_SUPER_PAD_START(PAD) \
   yVarP->RestartPAD = PAD; \
   PAD(VarP); \
   return;
#define CALL_SUPER_SRV_START(PAD) \
   yVarP->ActiveSrv->RestartPAD = PAD; \
   PAD(VarP); \
   return;
#define CALL_SUPER_PRD_START(PRD, THISPRD) \
   yPrdVarP->RestartPRD = PRD; \
   return PRD(VarP);

#define CALL_SERVICE \
   if (yVarP->ActiveSrv != (xSrvNode)0) { \
     (*yVarP->ActiveSrv->RestartPAD)(VarP); \
     return; \
   }

#define START_SERVICES \
   xStart_Services((xPrsNode)yVarP);



/* --------------------- Transition functions -------------------- */
#define XPTFUNC(PROC_NAME)      static void PROC_NAME (xPrsNode VarP)
#define XPTCALL(PROC_NAME)      PROC_NAME (VarP); return;



/* ------------------------ yInit function ----------------------- */
/* Variables and function used to describe the static structure of
   the SDL system */

#define YINIT_TEMP_VARS
#define BEGIN_YINIT

#define XPROCESSDEF_C(PROC_NAME, PROC_NAME_STRING, PREFIX_PROC_NAME, PAD_FUNCTION, VDEF_TYPE)
#define XPROCESSDEF_H(PROC_NAME, PROC_NAME_STRING, PREFIX_PROC_NAME, PAD_FUNCTION, VDEF_TYPE)

#define XSIGTYPE xSignalIdNode
#define xSigCode(P)
#define SIGCODE(P)


/* ------------------ Actions within transitions ----------------- */


/* ---------------------------- Output --------------------------- */

#ifdef XMSCE
#define GLOBALINSTID  int GlobalInstanceId;
#else
#define GLOBALINSTID
#endif

#if defined(XSIGPATH) && defined(XMSCE)
#define ENVCHANNEL  xChannelIdNode EnvChannel;
                    /* Used if env split into channels in MSC trace */
#else
#define ENVCHANNEL
#endif

#ifdef XENV_CONFORM_2_3
#define XSIGNAL_VARP  void * VarP;
#else
#define XSIGNAL_VARP
#endif

#define SIGNAL_VARS \
   xSignalNode   Pre; \
   xSignalNode   Suc; \
   int           Prio; \
   SDL_PId       Receiver; \
   SDL_PId       Sender; \
   xSignalIdNode NameNode; \
   GLOBALINSTID \
   ENVCHANNEL \
   XSIGNAL_VARP

#define XSIGNALHEADERTYPE xSignalRec

#define ALLOC_SIGNAL(SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_TYPE) \
   OUTSIGNAL_DATA_PTR = xGetSignal(SIG_IDNODE, RECEIVER, SDL_SELF);

#define ALLOC_SIGNAL_PAR(SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_TYPE) \
   OUTSIGNAL_DATA_PTR = xGetSignal(SIG_IDNODE, RECEIVER, SDL_SELF);

#ifdef XEOUTPUT
#define TRANSFER_SIGNAL(SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_TYPE) \
   if (SIG_IDNODE == INSIGNAL_NAME) { \
     OUTSIGNAL_DATA_PTR = xGetSignal(SIG_IDNODE, RECEIVER, yVarP->Signal->Sender); \
   } else { \
     xSDLOutputError(5, yVarP->Signal, 0); \
     OUTSIGNAL_DATA_PTR = xGetSignal(SIG_IDNODE, RECEIVER, SDL_SELF); \
   }
#define TRANSFER_SIGNAL_PAR(SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_TYPE) \
   if (SIG_IDNODE == INSIGNAL_NAME) { \
     OUTSIGNAL_DATA_PTR = xGetSignal(SIG_IDNODE, RECEIVER, yVarP->Signal->Sender); \
     memcpy(OUTSIGNAL_DATA_PTR, ySVarP, SIG_IDNODE->VarSize); \
     OUTSIGNAL_DATA_PTR->Receiver = RECEIVER; \
   } else { \
     xSDLOutputError(5, yVarP->Signal, 0); \
     OUTSIGNAL_DATA_PTR = xGetSignal(SIG_IDNODE, RECEIVER, SDL_SELF); \
   }
#else
#define TRANSFER_SIGNAL(SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_TYPE) \
   if (SIG_IDNODE == INSIGNAL_NAME) { \
     OUTSIGNAL_DATA_PTR = xGetSignal(SIG_IDNODE, RECEIVER, yVarP->Signal->Sender); \
   } else { \
     OUTSIGNAL_DATA_PTR = xGetSignal(SIG_IDNODE, RECEIVER, SDL_SELF); \
   }
#define TRANSFER_SIGNAL_PAR(SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_TYPE) \
   if (SIG_IDNODE == INSIGNAL_NAME) { \
     OUTSIGNAL_DATA_PTR = xGetSignal(SIG_IDNODE, RECEIVER, yVarP->Signal->Sender); \
     memcpy(OUTSIGNAL_DATA_PTR, ySVarP, SIG_IDNODE->VarSize); \
     OUTSIGNAL_DATA_PTR->Receiver = RECEIVER; \
   } else { \
     OUTSIGNAL_DATA_PTR = xGetSignal(SIG_IDNODE, RECEIVER, SDL_SELF); \
   }
#endif

#define SIGNAL_ALLOC_ERROR
#define SIGNAL_ALLOC_ERROR_END
#define OUTSIGNAL_DATA_PTR \
   yOutputSignal

#if defined(XSIGPRIO) || defined(XSIGPRSPRIO) || defined(XPRSSIGPRIO)

#define SDL_2OUTPUT(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(OUTSIGNAL_DATA_PTR, PRIO, VIA);

#define SDL_2OUTPUT_NO_TO(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(OUTSIGNAL_DATA_PTR, PRIO, VIA);

#define SDL_2OUTPUT_COMPUTED_TO(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(OUTSIGNAL_DATA_PTR, PRIO, VIA);

#define SDL_ALT2OUTPUT(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(OUTSIGNAL_DATA_PTR, PRIO, VIA);

#define SDL_ALT2OUTPUT_NO_TO(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(OUTSIGNAL_DATA_PTR, PRIO, VIA);

#define SDL_ALT2OUTPUT_COMPUTED_TO(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(OUTSIGNAL_DATA_PTR, PRIO, VIA);

#else

#define SDL_2OUTPUT(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(OUTSIGNAL_DATA_PTR, VIA);

#define SDL_2OUTPUT_NO_TO(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(OUTSIGNAL_DATA_PTR, VIA);

#define SDL_2OUTPUT_COMPUTED_TO(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(OUTSIGNAL_DATA_PTR, VIA);

#define SDL_ALT2OUTPUT(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(OUTSIGNAL_DATA_PTR, VIA);

#define SDL_ALT2OUTPUT_NO_TO(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(OUTSIGNAL_DATA_PTR, VIA);

#define SDL_ALT2OUTPUT_COMPUTED_TO(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(OUTSIGNAL_DATA_PTR, VIA);
#endif


#define SDL_THIS                yVarP->Self

#ifdef THREADLIGHT
#define TO_PROCESS(PROC_NAME, PROC_IDNODE) \
   SDL_TO_Process(PROC_IDNODE)
#else
#ifndef XMULTIPLESYSTEMS
#define TO_PROCESS(PROC_NAME, PROC_IDNODE) \
   ( *(PROC_IDNODE)->ActivePrsList != (xPrsNode)0 \
     ? (*(PROC_IDNODE)->ActivePrsList)->Self : SDL_NULL \
   )
#else
#define TO_PROCESS(PROC_NAME, PROC_IDNODE) \
   ( PROC_IDNODE == xEnvId \
    ? xNotDefPId \
    : ( *(PROC_IDNODE)->ActivePrsList != (xPrsNode)0 \
        ? (*(PROC_IDNODE)->ActivePrsList)->Self : SDL_NULL \
      ) \
   )
#endif
#endif

#define XRELEASE_SIGNAL_PARS \
   if (VarP->Signal->NameNode->Free_Signal != 0) \
     VarP->Signal->NameNode->Free_Signal((void *)(VarP->Signal));


/* ----------------------------- RPC ----------------------------- */

/* Output of pCALL signal */
#if defined(XSIGPRIO) || defined(XSIGPRSPRIO) || defined(XPRSSIGPRIO)
#define SDL_2OUTPUT_RPC_CALL(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(OUTSIGNAL_DATA_PTR, PRIO, VIA);
#else
#define SDL_2OUTPUT_RPC_CALL(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(OUTSIGNAL_DATA_PTR, VIA);
#endif

/* Output of pREPLY signal */
#define XRPC_SAVE_SENDER
#define XRPC_SENDER_IN_ALLOC       yVarP->Signal->Sender
#define XRPC_SENDER_IN_OUTPUT      Not_Used
#define XRPC_SAVE_SENDER_PRD
#define XRPC_SENDER_IN_ALLOC_PRD   yVarP->Signal->Sender
#define XRPC_SENDER_IN_OUTPUT_PRD  Not_Used

#define ALLOC_REPLY_SIGNAL(SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_TYPE) \
   REPLYSIGNAL_DATA_PTR = xGetSignal(SIG_IDNODE, RECEIVER, SDL_SELF);
#define ALLOC_REPLY_SIGNAL_PAR(SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_TYPE) \
   REPLYSIGNAL_DATA_PTR = xGetSignal(SIG_IDNODE, RECEIVER, SDL_SELF);
#define ALLOC_REPLY_SIGNAL_PRD(SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_TYPE) \
   REPLYSIGNAL_DATA_PTR_PRD = xGetSignal(SIG_IDNODE, RECEIVER, SDL_SELF);
#define ALLOC_REPLY_SIGNAL_PRD_PAR(SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_TYPE) \
   REPLYSIGNAL_DATA_PTR_PRD = xGetSignal(SIG_IDNODE, RECEIVER, SDL_SELF);

#define REPLYSIGNAL_DATA_PTR \
   yVarP->pREPLY_Signal
#define REPLYSIGNAL_DATA_PTR_PRD \
   yPrdVarP->pREPLY_Signal

#if defined(XSIGPRIO) || defined(XSIGPRSPRIO) || defined(XPRSSIGPRIO)
#define SDL_2OUTPUT_RPC_REPLY(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(REPLYSIGNAL_DATA_PTR, PRIO, VIA);
#define SDL_2OUTPUT_RPC_REPLY_PRD(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(REPLYSIGNAL_DATA_PTR_PRD, PRIO, VIA);
#else
#define SDL_2OUTPUT_RPC_REPLY(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(REPLYSIGNAL_DATA_PTR, VIA);
#define SDL_2OUTPUT_RPC_REPLY_PRD(PRIO, VIA, SIG_NAME, SIG_IDNODE, RECEIVER, SIG_PAR_SIZE, SIG_NAME_STRING) \
   SDL_Output(REPLYSIGNAL_DATA_PTR_PRD, VIA);
#endif

#define XGETEXPORTINGPRS(REMOTENODE) \
   xGetExportingPrs(REMOTENODE, VarP)

#define SDL_RPCWAIT_NEXTSTATE(PREPLY_IDNODE, PREPLY_NAME, RESTARTADDR) \
   SDL_RPC_WaitState(VarP, RESTARTADDR, PREPLY_IDNODE); \
   return;

#define SDL_RPCWAIT_NEXTSTATE_PRD(PREPLY_IDNODE, PREPLY_NAME, RESTARTADDR) \
   SDL_RPC_WaitState(VarP, RESTARTADDR, PREPLY_IDNODE); \
   return 1;

#define SDL_RPCWAIT_NEXTSTATE_XPT(PREPLY_IDNODE, PREPLY_NAME, RESTARTADDR) \
   SDL_RPC_WaitState(VarP, RESTARTADDR, PREPLY_IDNODE); \
   return;

#define XRPC_REPLY_INPUT
#define XRPC_REPLY_INPUT_PRD

/* ---------------------------- IMPORT --------------------------- */

#define XGETEXPORTADDR(REMOTENODE, EXPORTER, IS_DEF_EXPORTER) \
  xGetExportAddr(REMOTENODE, EXPORTER, IS_DEF_EXPORTER, VarP)


/* ---------------------------- Create --------------------------- */

#define STARTUP_VARS

#define ALLOC_STARTUP(PROC_NAME, STARTUP_IDNODE, STARTUP_PAR_TYPE) \
   STARTUP_DATA_PTR = xGetSignal(STARTUP_IDNODE, SDL_NULL, SDL_SELF);
#define ALLOC_STARTUP_PAR(PROC_NAME, STARTUP_IDNODE, STARTUP_PAR_TYPE) \
   STARTUP_DATA_PTR = xGetSignal(STARTUP_IDNODE, SDL_NULL, SDL_SELF);
#define ALLOC_STARTUP_THIS \
   STARTUP_DATA_PTR = xGetSignal((XSIGTYPE)((xPrsIdNode)yVarP->NameNode)->Super->Suc,\
                   SDL_NULL, SDL_SELF);

#define STARTUP_ALLOC_ERROR
#define STARTUP_ALLOC_ERROR_END
#define STARTUP_DATA_PTR \
   yOutputSignal

#define SDL_CREATE(PROC_NAME, PROC_IDNODE, PROC_NAME_STRING) \
   SDL_Create(STARTUP_DATA_PTR, PROC_IDNODE, yVarP->BlockInstNumber);
#define SDL_CREATE_THIS \
   SDL_Create(STARTUP_DATA_PTR, yVarP->NameNode, yVarP->BlockInstNumber);


/* ------------------------- Static Create ------------------------ */

#define INIT_PROCESS_TYPE(PROC_NAME, PREFIX_PROC_NAME, PROC_IDNODE, PROC_NAME_STRING, MAX_NO_OF_INST, STATIC_INST, PRIV_DATA_TYPE, PRIO, PAD_FUNCTION)

#define SDL_STATIC_CREATE(PROC_NAME, PREFIX_PROC_NAME, PROC_IDNODE, PROC_NAME_STRING, STARTUP_IDNODE, STARTUP_PAR_TYPE, PRIV_DATA_TYPE, PRIO, PAD_FUNCTION, BLOCK_INST_NUMBER) \
   SDL_Create(xGetSignal(STARTUP_IDNODE, SDL_NULL, SDL_NULL), PROC_IDNODE, BLOCK_INST_NUMBER);


/* ----------------------------- Stop ---------------------------- */

#define SDL_STOP \
   SDL_Stop(VarP); \
   return;

#define SDL_STOP_XPT \
   SDL_Stop(VarP); \
   return;

#ifdef XFREEVARS
#define FREE_PROCESS_VARS
#endif



/* ---------------------------- Timers --------------------------- */

#define TIMER_VARS \
   xSignalNode   Pre; \
   xSignalNode   Suc; \
   int           Prio; \
   SDL_PId       Receiver; \
   SDL_PId       Sender; \
   xSignalIdNode NameNode; \
   GLOBALINSTID \
   ENVCHANNEL \
   SDL_Time      TimerTime;
/* NOTE!!! TIMER_VARS HAS TO BE IDENTICAL TO SIGNAL_VARS, EXCEPT FOR TimerTime */

#define XTIMERHEADERTYPE xTimerRec

/* Set without parameters */
#define SDL_SET(TIME_EXPR, TIMER_NAME, TIMER_IDNODE, TIMER_VAR, TIMER_NAME_STRING) \
   SDL_Set(TIME_EXPR, xGetSignal(TIMER_IDNODE, SDL_SELF, SDL_SELF));

#define SDL_SET_DUR(TIME_EXPR, DUR_EXPR, TIMER_NAME, TIMER_IDNODE, TIMER_VAR, TIMER_NAME_STRING) \
   SDL_Set(TIME_EXPR, xGetSignal(TIMER_IDNODE, SDL_SELF, SDL_SELF));

#define SDL_SET_TICKS(TIME_EXPR, DUR_EXPR, TIMER_NAME, TIMER_IDNODE, TIMER_VAR, TIMER_NAME_STRING) \
   SDL_Set(TIME_EXPR, xGetSignal(TIMER_IDNODE, SDL_SELF, SDL_SELF));

/* Set with parameters */
#define ALLOC_TIMER_SIGNAL_PAR(TIMER_NAME, TIMER_IDNODE, TIMER_PAR_TYPE) \
   TIMER_DATA_PTR = xGetSignal(TIMER_IDNODE, SDL_SELF, SDL_SELF);
#define TIMER_SIGNAL_ALLOC_ERROR
#define TIMER_SIGNAL_ALLOC_ERROR_END
#define TIMER_DATA_PTR \
   yOutputSignal

#define SDL_SET_WITH_PARA(TIME_EXPR, TIMER_NAME, TIMER_IDNODE, TIMER_PAR_TYPE, EQ_FUNC, TIMER_VAR, TIMER_NAME_STRING) \
   SDL_Set(TIME_EXPR, TIMER_DATA_PTR);

#define SDL_SET_DUR_WITH_PARA(TIME_EXPR, DUR_EXPR, TIMER_NAME, TIMER_IDNODE, TIMER_PAR_TYPE, EQ_FUNC, TIMER_VAR, TIMER_NAME_STRING) \
   SDL_Set(TIME_EXPR, TIMER_DATA_PTR);

#define SDL_SET_TICKS_WITH_PARA(TIME_EXPR, DUR_EXPR, TIMER_NAME, TIMER_IDNODE, TIMER_PAR_TYPE, EQ_FUNC, TIMER_VAR, TIMER_NAME_STRING) \
   SDL_Set(TIME_EXPR, TIMER_DATA_PTR);


/* Reset without parameters */
#define SDL_RESET(TIMER_NAME, TIMER_IDNODE, TIMER_VAR, TIMER_NAME_STRING) \
   SDL_SimpleReset(VarP, TIMER_IDNODE);

/* Reset with parameters */
#define SDL_RESET_WITH_PARA(EQ_FUNC, TIMER_VAR, TIMER_NAME_STRING) \
   SDL_Reset(&TIMER_DATA_PTR);

/* Active (timer active) */
#define SDL_ACTIVE(TIMER_NAME, TIMER_IDNODE, TIMER_VAR) \
   SDL_Active(TIMER_IDNODE, VarP)

#define DEF_TIMER_VAR(NAME)
#define INIT_TIMER_VAR(NAME)
#define RELEASE_TIMER_VAR(NAME)
#define INPUT_TIMER_VAR(NAME)

#define DEF_TIMER_VAR_PARA(TIMER_VAR)
#define INIT_TIMER_VAR_PARA(TIMER_VAR)
#define INPUT_TIMER_VAR_PARA(TIMER_VAR)
#define RELEASE_TIMER_VAR_PARA(TIMER_VAR)

/* Now */
#define SDL_NOW                  SDL_Now()


/* ------------------------ Procedure call ----------------------- */

#define ALLOC_PROCEDURE(PROC_NAME, PROC_IDNODE, VAR_SIZE) \
   yTempPrd = xGetPrd(PROC_IDNODE);
#define ALLOC_VIRT_PROCEDURE(PROC_IDNODE) \
   yTempPrd = xGetPrd(PROC_IDNODE);
#define ALLOC_THIS_PROCEDURE \
   yTempPrd = xGetPrd(yPrdVarP->NameNode);
#define PROCEDURE_ALLOC_ERROR
#define PROCEDURE_ALLOC_ERROR_END
#define PROC_DATA_PTR \
   yTempPrd

#define CALL_PROCEDURE(PROC_NAME, PROC_IDNODE, LEVELS, RESTARTADDR) \
   xAddPrdCall(yTempPrd, VarP, LEVELS, RESTARTADDR); \
   if ( PROC_NAME (VarP) ) return;

#define CALL_PROCEDURE_IN_PRD(PROC_NAME, PROC_IDNODE, LEVELS, RESTARTADDR) \
   xAddPrdCall(yTempPrd, VarP, LEVELS, RESTARTADDR); \
   if ( PROC_NAME (VarP) ) return 1;

#define CALL_COMPSTMT_IN_COMPSTMT(PROC_NAME, PROC_IDNODE, LEVELS, RESTARTADDR) \
   { int i; \
     xAddPrdCall(yTempPrd, VarP, LEVELS, RESTARTADDR); \
     i = PROC_NAME(VarP); \
     if (i == 1) return 1; \
     if (i < 0) { SDL_BREAK(i+1) } \
   }

#define CALL_PROCEDURE_XPT(PROC_NAME, PROC_IDNODE, LEVELS, RESTARTADDR) \
   xAddPrdCall(yTempPrd, VarP, LEVELS, RESTARTADDR); \
   if ( PROC_NAME (VarP) ) return;

#define CALL_VIRT_PROCEDURE(PROC_IDNODE, LEVELS, RESTARTADDR) \
   xAddPrdCall(yTempPrd, VarP, LEVELS, RESTARTADDR); \
   if ( (*PROC_IDNODE->Assoc_Function)(VarP) ) return;

#define CALL_VIRT_PROCEDURE_IN_PRD(PROC_IDNODE, LEVELS, RESTARTADDR) \
   xAddPrdCall(yTempPrd, VarP, LEVELS, RESTARTADDR); \
   if ( (*PROC_IDNODE->Assoc_Function)(VarP) ) return 1;

#define CALL_VIRT_PROCEDURE_XPT(PROC_IDNODE, LEVELS, RESTARTADDR) \
   xAddPrdCall(yTempPrd, VarP, LEVELS, RESTARTADDR); \
   if ( (*PROC_IDNODE->Assoc_Function)(VarP) ) return;

#define CALL_THIS_PROCEDURE(RESTARTADDR) \
   xAddPrdCall(yTempPrd, VarP, 1, RESTARTADDR); \
   if ( (*yPrdVarP->NameNode->Assoc_Function)(VarP) ) return 1;

#define CALL_PROCEDURE_STARTUP \
  { int i; \
    i = (*yVarP->ActivePrd->RestartPRD)(VarP); \
    if (i == 1) return; \
    while (i<0) {xReleasePrd(VarP); i++;} \
  }
#define CALL_PROCEDURE_STARTUP_SRV \
  { int i; \
    i = (*ySrvVarP->ActivePrd->RestartPRD)(VarP); \
    if (i == 1) return; \
    while (i<0) {xReleasePrd(VarP); i++;} \
  }


/* ----------------------- Procedure return ---------------------- */

#define SDL_RETURN \
   xReleasePrd(VarP); \
   return 0;
#define SDL_BREAK(LEVELS) \
   xReleasePrd(VarP); \
   return LEVELS;


/* --------------------------- Nextstate ------------------------- */

#define SDL_NEXTSTATE(STATE_NAME, STATE_IDNODE, STATE_NAME_STRING) \
   SDL_NextState(VarP, STATE_IDNODE); \
   return;
#define SDL_DASH_NEXTSTATE \
   SDL_NextState(VarP, yVarP->State); \
   return;
#define SDL_DASH_NEXTSTATE_SRV \
   SDL_NextState(VarP, yVarP->ActiveSrv->State); \
   return;
#define SDL_NEXTSTATE_PRD(STATE_NAME, STATE_IDNODE, STATE_NAME_STRING) \
   SDL_NextState(VarP, STATE_IDNODE); \
   return 1;
#define SDL_NEXTSTATE_XPT(STATE_NAME, STATE_IDNODE, STATE_NAME_STRING) \
   SDL_NextState(VarP, STATE_IDNODE); \
   return;
#define SDL_DASH_NEXTSTATE_XPT \
   SDL_NextState(VarP, yVarP->State); \
   return;

#ifndef XNOUSEOFSERVICE
#define SDL_DASH_NEXTSTATE_PRD \
   SDL_NextState(VarP, (yVarP->ActiveSrv == (xSrvNode)0 \
                        ? yVarP->ActivePrd->State \
                        : yVarP->ActiveSrv->ActivePrd->State) ); \
   return 1;
#else
#define SDL_DASH_NEXTSTATE_PRD \
   SDL_NextState(VarP, yVarP->ActivePrd->State); \
   return 1;
#endif

/* ----------------------------- Join ---------------------------- */
#define XJOIN_XPT(RESTARTADDR) \
   yVarP->RestartAddress = RESTARTADDR; \
   return;

#define XJOIN_SUPER_PRS(RESTARTADDR,RESTARTPAD) \
   yVarP->RestartAddress = RESTARTADDR; \
   yVarP->RestartPAD = RESTARTPAD; \
   RESTARTPAD(VarP); \
   return;

#define XJOIN_SUPER_PRD(RESTARTADDR,RESTARTPRD) \
   yPrdVarP->RestartAddress = RESTARTADDR; \
   yPrdVarP->RestartPRD = RESTARTPRD; \
   return RESTARTPRD(VarP);

#define XJOIN_SUPER_SRV(RESTARTADDR,RESTARTSRV) \
   yVarP->ActiveSrv->RestartAddress = RESTARTADDR; \
   yVarP->ActiveSrv->RestartPAD = RESTARTSRV; \
   RESTARTSRV(VarP); \
   return;

/* --------------------------- Decision -------------------------- */

/* Informal decisions */
#define BEGIN_INFORMAL_DECISION(NO_OF_PATHS, QUESTION) \
   { \
    int xPathSymbolNo[NO_OF_PATHS]; \
    char *xPathAnswer[NO_OF_PATHS]; \
    xInformalDecision(QUESTION);
#define DEF_INFORMAL_PATH(PATH_NO, ANSWER, SYMBOLNUMBER) \
   xInformalPath(PATH_NO, ANSWER, SYMBOLNUMBER, xPathSymbolNo, xPathAnswer);
#define DEF_INFORMAL_ELSE_PATH(PATH_NO, SYMBOLNUMBER) \
   xInformalPath(PATH_NO, "LELSE", SYMBOLNUMBER, xPathSymbolNo, xPathAnswer);
#define END_DEFS_INFORMAL_PATH(NO_OF_PATHS) \
   xReadPath(&yDcn_SDL_Integer, NO_OF_PATHS, xPathSymbolNo, xPathAnswer, (xbool)1); \
   }
#define BEGIN_FIRST_INFORMAL_PATH(PATH_NO) \
   if ((yEqF_SDL_Integer(yDcn_SDL_Integer, PATH_NO))) {
#define BEGIN_INFORMAL_PATH(PATH_NO) \
   else if ((yEqF_SDL_Integer(yDcn_SDL_Integer, PATH_NO))) {
#define END_INFORMAL_PATH \
   }
#define BEGIN_INFORMAL_ELSE_PATH(PATH_NO) \
   if ((yEqF_SDL_Integer(yDcn_SDL_Integer, PATH_NO))) {
#define END_INFORMAL_ELSE_PATH \
   }
#define END_INFORMAL_DECISION

/* Non-deterministic decisions */
#define BEGIN_ANY_DECISION(NO_OF_PATHS) \
   { \
    int xPathSymbolNo[NO_OF_PATHS]; \
    xAnyDecision();
#define DEF_ANY_PATH(PATH_NO, SYMBOLNUMBER) \
   xAnyPath(PATH_NO, SYMBOLNUMBER, xPathSymbolNo);
#define END_DEFS_ANY_PATH(NO_OF_PATHS) \
   xReadPath(&yDcn_SDL_Integer, NO_OF_PATHS, xPathSymbolNo, (char **)0, (xbool)0); \
   }
#define BEGIN_FIRST_ANY_PATH(PATH_NO) \
   if ((yEqF_SDL_Integer(yDcn_SDL_Integer, PATH_NO))) {
#define BEGIN_ANY_PATH(PATH_NO) \
   else if ((yEqF_SDL_Integer(yDcn_SDL_Integer, PATH_NO))) {
#define END_ANY_PATH \
   }
#define END_ANY_DECISION


/* ----------------------------- View ---------------------------- */

#define SDL_VIEW(PID_EXPR, HAS_EXPR, VAR_NAME_STRING, REVEALED_LIST, SORT_SIZE) \
   SDL_View(REVEALED_LIST, PID_EXPR, HAS_EXPR, VarP, xeView(VAR_NAME_STRING) SORT_SIZE)


/* ------------------- Execution trace and Debug ----------------- */

#define YPRSNAME_VAR(PRS_NAME_STRING)
#define YPRDNAME_VAR(PRD_NAME_STRING)
#define XOS_TRACE_INPUT(SIG_NAME_STRING)
#define XDEBUG_LABEL(LABEL_NAME)

#ifdef XEUNION
#define XCHECK_UNION_TAG(TAG,VALUE,ASSTAG,NEQTAG,COMPNAME,CURR_VALUE,TYPEINFO) \
   if (NEQTAG(TAG,VALUE)) { \
     xUnionTagError(COMPNAME,CURR_VALUE,TYPEINFO,(xbool)1); \
     ASSTAG(TAG,VALUE,XASS_MR_ASS_NF); \
   }
#define XCHECK_UNION_TAG_FREE(TAG,VALUE,ASSTAG,NEQTAG,FREEFUNC,COMPNAME,CURR_VALUE,TYPEINFO) \
   if (NEQTAG(TAG,VALUE)) { \
     xUnionTagError(COMPNAME,CURR_VALUE,TYPEINFO,(xbool)1); \
     FREEFUNC((void **)&(TAG)); \
     ASSTAG(TAG,VALUE,XASS_MR_ASS_NF); \
   }
#define XCHECK_UNION_TAG_USAGE(TAG,VALUE,NEQTAG,COMPNAME,CURR_VALUE,TYPEINFO) \
   if (NEQTAG(TAG,VALUE)) { \
     xUnionTagError(COMPNAME,CURR_VALUE,TYPEINFO,(xbool)0); \
   }
#else
#define XCHECK_UNION_TAG(TAG,VALUE,ASSTAG,NEQTAG,COMPNAME,CURR_VALUE,TYPEINFO) \
   if (NEQTAG(TAG,VALUE)) { \
     ASSTAG(TAG,VALUE,XASS_MR_ASS_NF); \
   }
#define XCHECK_UNION_TAG_FREE(TAG,VALUE,ASSTAG,NEQTAG,FREEFUNC,COMPNAME,CURR_VALUE,TYPEINFO) \
   if (NEQTAG(TAG,VALUE)) { \
     FREEFUNC((void **)&(TAG)); \
     ASSTAG(TAG,VALUE,XASS_MR_ASS_NF); \
   }
#define XCHECK_UNION_TAG_USAGE(TAG,VALUE,NEQTAG,COMPNAME,CURR_VALUE,TYPEINFO)
#endif

#ifdef XEOPTIONAL
#define XCHECK_OPTIONAL_USAGE(PRESENT_VAR,COMPNAME) \
   if (! PRESENT_VAR) xOptionalError(COMPNAME);
#else
#define XCHECK_OPTIONAL_USAGE(PRESENT_VAR,COMPNAME)
#endif

#define XSET_CHOICE_TAG(TAG,VALUE,ASSTAG,NEQTAG,COMPNAME,CURR_VALUE,TYPEINFO) \
   if (NEQTAG(TAG,VALUE)) { \
     ASSTAG(TAG,VALUE,XASS_MR_ASS_NF); \
   }
#define XSET_CHOICE_TAG_FREE(TAG,VALUE,ASSTAG,NEQTAG,FREEFUNC,COMPNAME,CURR_VALUE,TYPEINFO) \
   if (NEQTAG(TAG,VALUE)) { \
     FREEFUNC((void **)&(TAG)); \
     ASSTAG(TAG,VALUE,XASS_MR_ASS_NF); \
   }
#ifdef XECHOICE
#define XCHECK_CHOICE_USAGE(TAG,VALUE,NEQTAG,COMPNAME,CURR_VALUE,TYPEINFO) \
   if (NEQTAG(TAG,VALUE)) { \
     xChoiceError(COMPNAME,CURR_VALUE,TYPEINFO); \
   }
#else
#define XCHECK_CHOICE_USAGE(TAG,VALUE,NEQTAG,COMPNAME,CURR_VALUE,TYPEINFO)
#endif

#ifdef XEOWN
#define XCHECK_OREF(VALUE,REF_TYPEINFO,REF_SORT) \
   if (VALUE == 0) { \
     VALUE = (REF_SORT)xAlloc((REF_TYPEINFO)->CompOrFatherSort->SortSize); \
     xRefError((void *)&(VALUE), REF_TYPEINFO); \
   } else { \
     xCheckRefOwn((void *)(VALUE)); \
   }
#define XCHECK_OREF2(VALUE) \
   if (VALUE != 0) xCheckRefOwn((void *)(VALUE));
#define XCHECK_OWN(VALUE,REF_TYPEINFO,REF_SORT) \
   if (VALUE == 0) { \
     VALUE = (REF_SORT)xAlloc((REF_TYPEINFO)->CompOrFatherSort->SortSize); \
     xRefError((void *)&(VALUE), REF_TYPEINFO); \
   }
#else
#define XCHECK_OREF(VALUE,REF_TYPEINFO,REF_SORT)
#define XCHECK_OREF2(VALUE)
#define XCHECK_OWN(VALUE,REF_TYPEINFO,REF_SORT)
#endif

#ifdef XEREF
#define XCHECK_REF(VALUE,REF_TYPEINFO,REF_SORT) \
   if (VALUE == 0) { \
     VALUE = (REF_SORT)xAlloc((REF_TYPEINFO)->CompOrFatherSort->SortSize); \
     xRefError((void *)&(VALUE), REF_TYPEINFO); \
   }
#else
#define XCHECK_REF(VALUE,REF_TYPEINFO,REF_SORT)
#endif

/* -------------------------- Simulation ------------------------- */

#ifdef XBREAKBEFORE
#define XAT_FIRST_SYMBOL(SYMB_NO) \
   xGRSetSymbol(SYMB_NO);
#define XBETWEEN_SYMBOLS(SYMB_NO, C_LINE_NO) \
   if ( xBreakBefore(VarP, xCTrace(xFileName) \
        xCTrace(C_LINE_NO)  SYMB_NO, (xbool)1) ) return;
#define XBETWEEN_SYMBOLS_PRD(SYMB_NO, C_LINE_NO) \
   if ( xBreakBefore(VarP, xCTrace(xFileName) \
        xCTrace(C_LINE_NO)  SYMB_NO, (xbool)1) ) return 1;
#define XBETWEEN_STMTS(SYMB_NO, C_LINE_NO) \
   if ( xBreakBefore(VarP, xCTrace(xFileName) \
        xCTrace(C_LINE_NO)  SYMB_NO, (xbool)0) ) return;
#define XBETWEEN_STMTS_PRD(SYMB_NO, C_LINE_NO) \
   if ( xBreakBefore(VarP, xCTrace(xFileName) \
        xCTrace(C_LINE_NO)  SYMB_NO, (xbool)0) ) return 1;
#define XAFTER_VALUE_RET_PRDCALL(SYMB_NO) \
   xSetupGRCov(VarP, SYMB_NO);
#define XAT_LAST_SYMBOL \
   xGRSetSymbol(-1);
#else
#define XAT_FIRST_SYMBOL(SYMB_NO)
#define XBETWEEN_SYMBOLS(SYMB_NO, C_LINE_NO)
#define XBETWEEN_SYMBOLS_PRD(SYMB_NO, C_LINE_NO)
#define XBETWEEN_STMTS(SYMB_NO, C_LINE_NO)
#define XBETWEEN_STMTS_PRD(SYMB_NO, C_LINE_NO)
#define XAFTER_VALUE_RET_PRDCALL(SYMB_NO)
#define XAT_LAST_SYMBOL
#endif

#define XASN1_SYNTAX  xSysD.xUse_ASN1_Syntax

#define XNEWREF_SYNTAX  xSysD.xUse_NewRef_Syntax
#define XDEREF_SYNTAX   xSysD.xUse_DeRef_Syntax

#define XVALUE_SYNTAX   xSysD.xValue_Syntax  /* E.g. struct should start with (. */

#define XINTEGER_OUTPUT_MODE  xSysD.xIntegerOutputMode
#define XPRINT_INT_FORMAT  xSysD.xPrintIntFormat
#define XSCAN_INT_FORMAT   xSysD.xScanIntFormat

/****+***************************************************************
05   Utility #ifdef
********************************************************************/
#ifndef THREADOSE
#define NIL 0
#endif /* THREADOSE */
#define XSYSD xSysD.

#if defined(XPRSPRIO) || defined(XSIGPRSPRIO) || defined(XPRSSIGPRIO)
#define xPrsPrioPar(p)  , p
#else
#define xPrsPrioPar(p)
#endif

#if defined(XSIGPRIO) || defined(XSIGPRSPRIO) || defined(XPRSSIGPRIO)
#define xSigPrioPar(p)  , p
#define xSigPrioParS(p)  p;
#else
#define xSigPrioPar(p)
#define xSigPrioParS(p)
#endif

#ifdef XTESTF
#define xTestF(p)  , p
#else
#define xTestF(p)
#endif

#ifdef XREADANDWRITEF
#define xRaWF(p)  , p
#else
#define xRaWF(p)
#endif

#define xFreF(p)  , p

#ifdef XFREESIGNALFUNCS
#define xFreS(p)  , p
#else
#define xFreS(p)
#endif

#define xAssF(p)
#define xEqF(p)

#ifdef XIDNAMES 
#define xIdNames(p)  , p
#else
#define xIdNames(p)
#endif

#ifndef XOPTCHAN
#define xOptChan(p)  , p
#define xOptChanZ(p)   p
#else
#define xOptChan(p)
#define xOptChanZ(p)   0
#endif

#ifdef XBREAKBEFORE
#define xBreakB(p)  , p
#else
#define xBreakB(p)
#endif

#ifdef XGRTRACE
#define xGRTrace(p)  , p
#else
#define xGRTrace(p)
#endif

#ifdef XMSCE
#define xMSCETrace(p)  , p
#else
#define xMSCETrace(p)
#endif

#ifdef XTRACE
#define xTrace(p)  , p
#else
#define xTrace(p)
#endif

#ifdef XCOVERAGE
#define xCoverage(p)  , p
#else
#define xCoverage(p)
#endif

#ifdef XNRINST
#define xNrInst(p)  , p
#else
#define xNrInst(p)
#endif

#ifdef XSYMBTLINK
#define xSymbTLink(p1, p2) , p1, p2
#else
#define xSymbTLink(p1, p2)
#endif

#ifdef XEVIEW
#define xeView(p)  p,
#define xeViewS(p)  p;
#else
#define xeView(p)
#define xeViewS(p)
#endif

#ifdef XCTRACE
#define xCTrace(p)  p,
#define xCTraceS(p)  p;
#else
#define xCTrace(p)
#define xCTraceS(p)
#endif

#ifndef XNOUSEOFSERVICE
#define xService(p)  , p
#else
#define xService(p)
#endif

#ifdef THREADLIGHT
#define xThreadName(p) , p
#else
#define xThreadName(p)
#endif


/****+***************************************************************
06   Constants
********************************************************************/

#if !defined(XPMCOMM) && !defined(XENV)
#define xGlobalNodeNumber() 1
#endif

#define xSizeOfPathStack 50

#ifndef xOffsetOf
#define xOffsetOf(type, field)  ((xptrint) &((type *) 0)->field)
#endif
#define xToLower(C) \
        ((C >= 'A' && C <= 'Z') ? (char)((int)C - (int)'A' + (int)'a') : C)

#ifndef xDefaultPrioProcess
#define xDefaultPrioProcess      100
#endif

#ifndef xDefaultPrioSignal
#define xDefaultPrioSignal       100
#endif

#ifndef xDefaultPrioTimerSignal
#define xDefaultPrioTimerSignal  100
#endif

#ifndef xDefaultPrioContSignal
#define xDefaultPrioContSignal   100
#endif

#ifndef xDefaultPrioCreate
#define xDefaultPrioCreate       100
#endif

#define xbool int

#ifndef MAX_READ_LENGTH
#define MAX_READ_LENGTH 10000
                        /* max length of input line */
#endif



/****+***************************************************************
07   Forward Declarations
********************************************************************/
struct xSystemData;

typedef XCONST struct xIdStruct           *xIdNode;
typedef XCONST struct xBlockSubstIdStruct *xBlockSubstIdNode;
typedef XCONST struct xLiteralIdStruct    *xLiteralIdNode;
typedef XCONST struct xPackageIdStruct    *xPackageIdNode;
typedef XCONST struct xSystemIdStruct     *xSystemIdNode;
#ifndef XOPTCHAN
typedef XCONST struct xChannelIdStruct    *xChannelIdNode;
#endif
typedef XCONST struct xBlockIdStruct      *xBlockIdNode;
typedef XCONST struct xPrsIdStruct        *xPrsIdNode;
#ifndef XNOUSEOFSERVICE
typedef XCONST struct xSrvIdStruct        *xSrvIdNode;
#endif
typedef XCONST struct xPrdIdStruct        *xPrdIdNode;
typedef        struct xRemotePrdIdStruct  *xRemotePrdIdNode;
typedef XCONST struct xSignalIdStruct     *xSignalIdNode;
typedef XCONST struct xStateIdStruct      *xStateIdNode;
typedef XCONST struct xSortIdStruct       *xSortIdNode;
typedef XCONST struct xVarIdStruct        *xVarIdNode;
typedef        struct xRemoteVarIdStruct  *xRemoteVarIdNode;

typedef struct xPrsStruct          *xPrsNode;

#ifndef XNOUSEOFSERVICE
typedef struct xSrvStruct          *xSrvNode;
#endif

typedef struct xTimerStruct        *xTimerNode;

#ifndef THREADOSE
typedef struct xSignalStruct       *xSignalNode;
#endif /* THREADOSE */


/****+***************************************************************
08   SDL predefined types (except SDL_PId)
********************************************************************/

#include "sctpred.h"


/****+***************************************************************
09   SDL_PId
********************************************************************/

typedef struct {
   xPrsNode   PrsP;
#ifdef XNRINST
   int        InstNr;
#endif
#if defined(XPRSOPT) && !defined(XNRINST)
   xbool      InAvailList;
#endif  
#ifdef XMSCE
   int        GlobalInstanceId;
#endif
}  xLocalPIdRec;

typedef xLocalPIdRec  *xLocalPIdNode;

typedef struct {
   int            GlobalNodeNr;
   xLocalPIdNode  LocalPId;
}  SDL_PId;
#define SDL_pid SDL_PId
#define SDL_Pid SDL_PId

#define xDef_SDL_PId(V)       (*(V) = SDL_NULL)
#define yDef_SDL_PId(V)       xDef_SDL_PId(V)
#define yAssF_SDL_PId(V,E,A)  (V = E)
#define yEqF_SDL_PId(E1,E2)   xEq_SDL_PId(E1,E2)
#define yNEqF_SDL_PId(E1,E2)  (! xEq_SDL_PId(E1,E2))
extern void * yMkAddr_SDL_PId (SDL_PId, SDL_PId *);

#ifdef XREADANDWRITEF
extern xPrsNode xReadProcess (char *, xPrsIdNode *, xIdNode);
#endif


/****+***************************************************************
10   Signal Set
********************************************************************/
typedef unsigned char xInputAction;

#define xDiscard         (xInputAction)0
#define xInput           (xInputAction)1
#define xSave            (xInputAction)2
#define xEnablCond       (xInputAction)3
#define xPrioInput       (xInputAction)4


/****+***************************************************************
14   Signal
********************************************************************/
/*typedef xSignalRec  *xSignalNode; See Forward Declarations.*/

typedef struct xSignalStruct {
   SIGNAL_VARS
       /*  Pre = 0 if in avail list. */
       /*  Suc is also used as pointer in avail list. */
}  xSignalRec;

typedef struct xInputPortStruct {
   xSignalNode   Pre;
   xSignalNode   Suc;
   int           Prio;
}  xInputPortRec;      /* HAS TO BE FIRST THREE COMPONENTS IN SIGNAL_VARS !!! */


/****+***************************************************************
13   Timer
********************************************************************/
/*typedef xTimerRec  *xTimerNode; See Forward Declarations.*/

typedef struct xTimerStruct {
   TIMER_VARS
}  xTimerRec;


/****+***************************************************************
11   Procedure ( = Prd )
********************************************************************/
typedef struct xPrdStruct  *xPrdNode;

typedef struct xPrdStruct {
   PROCEDURE_VARS
     /* StaticFather = 0 if in avail list.*/
     /* DynamicFather also used as pointer in avail list.*/
}  xPrdRec;


/****+***************************************************************
12   Process ( = Prs )
********************************************************************/
/*typedef struct xPrsStruct  *xPrsNode; See Forward Declarations.*/
/*typedef struct xSrvStruct  *xSrvNode; See Forward Declarations.*/

typedef struct xPrsStruct {
   PROCESS_VARS
}  xPrsRec;

#ifndef XNOUSEOFSERVICE
typedef struct xSrvStruct {
   SERVICE_VARS
}  xSrvRec;
#endif


/****+***************************************************************
15   Symbol Table
********************************************************************/
typedef enum {
  xRemoteVarEC,
  xRemotePrdEC,
  xSignalrouteEC,
  xStateEC,
  xTimerEC,
  xFormalParEC,
  xLiteralEC,
  xVariableEC,
  xBlocksubstEC,
  xPackageEC,
  xProcedureEC,
  xOperatorEC,
  xProcessEC,
  xProcessTypeEC,
  xGateEC,
  xSignalEC,
  xSignalParEC,
  xStartUpSignalEC,
  xRPCSignalEC,
  xSortEC,
  xSyntypeEC,
  xSystemEC,
  xSystemTypeEC,
  xBlockEC,
  xBlockTypeEC,
  xChannelEC,
  xServiceEC,
  xServiceTypeEC,
  xCompoundStmtEC,
  xSyntVariableEC,
  xMonitorCommandEC
  /* xExportEC */
  /* xViewEC */
  /* xChannelsubstEC */
  /* xEnvironmentEC */
  /* xConnectEC */
  /* xGeneratorEC */
  /* xImportedEC */
  /* xLabelEC */
  /* xSignallistEC */
  /* xSynonymEC */
}   xEntityClassType;

typedef enum {
  xPredef, xUserdef, xEnum,
  xStruct, xArray, xGArray, xCArray, xRef, xOwn, xORef, xString, xLString,
  xPowerSet, xGPowerSet, xBag, xInherits, xSyntype,
  xUnion, xUnionC, xChoice
}   xTypeOfSort;

#ifdef XBREAKBEFORE
/* KEEP xSymbolType UPDATED WITH xSymbolTypeStr AS DEFINED
   IN sctutil.c */
typedef enum {
   xsStart, xsInput, xsPriorityInput, xsContinuousSignal,
   xsTask, xsAssignmentStatement, xsAssignment2Statement, xsOutput,
   xsCreateRequest, xsDecision, xsDecisionAny, xsDecisionInformal,
   xsTransitionOption, xsSet, xsReset, xsExport,
   xsProcedureCall, xsValueReturningProcedureCall, xsRPC, xsValueReturningRPC,
   xsIf, xsLoop, xsLoopTest, xsLoopUpdate, xsBreak, xsContinue,
   xsNextstate, xsJoin, xsStop, xsReturn,
   xspCALLInput, xspCALLProcedureCall, xspREPLYOutput, xspCALLNextstate,
   xspREPLYInput, xsLabel, xsNoSuchSymbolType
} xSymbolType;
#endif

typedef char  *xNameType;

                                  /*VIEW*/
typedef struct xViewListStruct {
   xPrsIdNode  ViewingPrs;
#ifndef XNOUSEOFSERVICE
   xSrvIdNode  SrvId;
#endif
   xptrint     Offset;
}  xViewListRec;

typedef struct xViewIndexStruct {
   char       *ViewName;   /* var name, prefix for type */
   int         Index;      /* index in xViewListRec */
}  xViewIndexRec;


typedef struct xIdStruct {
   xEntityClassType  EC;
#ifdef XSYMBTLINK
   xIdNode           First;
   xIdNode           Suc;
#endif
   xIdNode           Parent;
#ifdef XIDNAMES
   xNameType         Name;
#endif
}  xIdRec;


                                  /*BLOCKSUBSTRUCTURE*/
typedef struct xBlockSubstIdStruct {
   xEntityClassType  EC;
#ifdef XSYMBTLINK
   xIdNode           First;
   xIdNode           Suc;
#endif
   xIdNode           Parent;
#ifdef XIDNAMES
   xNameType         Name;
#endif
}  xBlockSubstIdRec;


                                  /*LITERAL*/
typedef struct xLiteralIdStruct {
   xEntityClassType  EC;
#ifdef XSYMBTLINK
   xIdNode           First;
   xIdNode           Suc;
#endif
   xIdNode           Parent;
#ifdef XIDNAMES
   xNameType         Name;
#endif
   int               LiteralValue;
}  xLiteralIdRec;


                                  /*PACKAGE*/
typedef struct xPackageIdStruct {
   xEntityClassType  EC;
#ifdef XSYMBTLINK
   xIdNode           First;
   xIdNode           Suc;
#endif
   xIdNode           Parent;
#ifdef XIDNAMES
   xNameType         Name;
#endif
#ifdef XIDNAMES
   xNameType         ModuleName;
#endif
}  xPackageIdRec;


                                  /*SYSTEM*/
typedef struct xSystemIdStruct {
   xEntityClassType  EC;
#ifdef XSYMBTLINK
   xIdNode           First;
   xIdNode           Suc;
#endif
   xIdNode           Parent;
#ifdef XIDNAMES
   xNameType         Name;
#endif
   XCONST_COMP xIdNode         * Contents;
   XCONST_COMP xPrdIdNode      * VirtPrdList;
   xSystemIdNode     Super;
#ifdef XTRACE
   int               Trace_Default;
#endif
#ifdef XGRTRACE
   int               GRTrace;
#endif
#ifdef XMSCE
   int               MSCETrace;
#endif
}  xSystemIdRec;


                                  /*CHANNEL,SIGNALROUTE*/
#ifndef XOPTCHAN
typedef struct xChannelIdStruct {
   xEntityClassType  EC;
#ifdef XSYMBTLINK
   xIdNode           First;
   xIdNode           Suc;
#endif
   xIdNode           Parent;
#ifdef XIDNAMES
   xNameType         Name;
#endif
   XCONST_COMP xSignalIdNode    *SignalSet; /*Array*/
   XCONST_COMP xIdNode          *ToId;      /*Array*/
   xChannelIdNode    Reverse;
}  xChannelIdRec;   /* And xSignalRouteEC.*/
#endif


                                  /*BLOCK*/
typedef struct xBlockIdStruct {
   xEntityClassType  EC;
#ifdef XSYMBTLINK
   xIdNode           First;
   xIdNode           Suc;
#endif
   xIdNode           Parent;
#ifdef XIDNAMES
   xNameType         Name;
#endif
   xBlockIdNode      Super;
   XCONST_COMP xIdNode         * Contents;
   XCONST_COMP xPrdIdNode      * VirtPrdList;
   xViewListRec    * ViewList;
   xViewIndexRec   * ViewIndex;
   int               NumberOfInst;
#ifdef XTRACE
   int               Trace_Default;
#endif
#ifdef XGRTRACE
   int               GRTrace;
#endif
#ifdef XMSCE
   int               MSCETrace;
   int               GlobalInstanceId;
#endif
}  xBlockIdRec;


                                  /*PROCESS*/
typedef struct xPrsIdStruct {
   xEntityClassType  EC;
#ifdef XSYMBTLINK
   xIdNode           First;
   xIdNode           Suc;
#endif
   xIdNode           Parent;
#ifdef XIDNAMES
   xNameType         Name;
#endif
   XCONST_COMP xStateIdNode     *StateList;
   XCONST_COMP xSignalIdNode    *SignalSet; /*Used as an array of xIdNode.*/
#ifndef XNOUSEOFSERVICE
   XCONST_COMP xIdNode          *Contents;
#endif
#ifndef XOPTCHAN
   XCONST_COMP xIdNode          *ToId; /*Array*/
#endif
   int               MaxNoOfInst;
#ifdef XNRINST
   int               NextNr;
   int               NoOfStaticInst;
#endif
   xPrsNode         *ActivePrsList;
   xptrint           VarSize;
#if defined(XPRSPRIO) || defined(XSIGPRSPRIO) || defined(XPRSSIGPRIO)
   int               Prio;
#endif
   xPrsNode         *AvailPrsList;
#ifdef XTRACE
   int               Trace_Default;
#endif
#ifdef XGRTRACE
   int               GRTrace;
#endif
#ifdef XBREAKBEFORE
   char             *(*GRrefFunc) (int, xSymbolType *);
   int               MaxSymbolNumber;
   int               SignalSetLength;
#endif
#ifdef XMSCE
   int               MSCETrace;
#endif
#ifdef XCOVERAGE
   long int         *CoverageArray;
   long int          NoOfStartTransitions;
   long int          MaxQueueLength;
#endif
   void              (*PAD_Function) (xPrsNode);
   void              (*Free_Vars) (void *);
   xPrsIdNode        Super;
   XCONST_COMP xPrdIdNode      * VirtPrdList;
   xBlockIdNode      InBlockInst;
#ifdef XBREAKBEFORE
   char            * RefToDefinition;
#endif
#ifdef THREADLIGHT
   struct xSystemData * SysD;
  xThreadParam       * ThreadParam;
#endif
}  xPrsIdRec;


#ifndef XNOUSEOFSERVICE
                                  /*SERVICE*/
typedef struct xSrvIdStruct {
   xEntityClassType  EC;
#ifdef XSYMBTLINK
   xIdNode           First;
   xIdNode           Suc;
#endif
   xIdNode           Parent;
#ifdef XIDNAMES
   xNameType         Name;
#endif
   XCONST_COMP xStateIdNode     *StateList;
   XCONST_COMP xSignalIdNode    *SignalSet; /*Used as an array of xIdNode.*/
#ifndef XOPTCHAN
   XCONST_COMP xIdNode          *ToId; /*Array*/
#endif
   xptrint           VarSize;
#ifdef XBREAKBEFORE
   char             *(*GRrefFunc) (int, xSymbolType *);
   int               MaxSymbolNumber;
   int               SignalSetLength;
#endif
#ifdef XCOVERAGE
   long int         *CoverageArray;
   long int          NoOfStartTransitions;
#endif
   xSrvNode         *AvailSrvList;
   void              (*PAD_Function) (xPrsNode);
   void              (*Free_Vars) (void *);
   xSrvIdNode        Super;
   XCONST_COMP xPrdIdNode      * VirtPrdList;
}  xSrvIdRec;
#endif


                                  /*PROCEDURE*/
typedef struct xPrdIdStruct {
   xEntityClassType  EC;
#ifdef XSYMBTLINK
   xIdNode           First;
   xIdNode           Suc;
#endif
   xIdNode           Parent;
#ifdef XIDNAMES
   xNameType         Name;
#endif
   XCONST_COMP xStateIdNode     *StateList;
   XCONST_COMP xSignalIdNode    *SignalSet; /*Used as an array of xIdNode.*/
   int              (*Assoc_Function) (xPrsNode);
   void             (*Free_Vars) (void *);
   xptrint           VarSize;
   xPrdNode         *AvailPrdList;
#ifdef XBREAKBEFORE
   char             *(*GRrefFunc) (int, xSymbolType *);
   int               MaxSymbolNumber;
   int               SignalSetLength;
#endif
#ifdef XCOVERAGE
   long int         *CoverageArray;
#endif
   xPrdIdNode        Super;
   XCONST_COMP xPrdIdNode      * VirtPrdList;
}  xPrdIdRec;


                                  /*REMOTE PROCEDURE*/
typedef struct xRemotePrdListStruct *xRemotePrdListNode;
typedef struct xRemotePrdListStruct {
   xRemotePrdListNode  Next;
   xPrsIdNode          ExportedPrs;
}  xRemotePrdListRec;

typedef struct xRemotePrdIdStruct {
   xEntityClassType    EC;
#ifdef XSYMBTLINK
   xIdNode             First;
   xIdNode             Suc;
#endif
   xIdNode             Parent;
#ifdef XIDNAMES
   xNameType           Name;
#endif
   xRemotePrdListNode  RemoteList;   
}  xRemotePrdIdRec;


                                /* SIGNAL, TIMER */
typedef struct xSignalIdStruct {
   xEntityClassType  EC;
#ifdef XSYMBTLINK
   xIdNode           First;
   xIdNode           Suc;
#endif
   xIdNode           Parent;
#ifdef XIDNAMES
   xNameType         Name;
#endif
   xptrint           VarSize;
   xSignalNode      *AvailSignalList;
   xbool             (*Equal_Timer) (void *, void *);
#ifdef XFREESIGNALFUNCS
   void              (*Free_Signal) (void *);
#endif
#ifdef XBREAKBEFORE
   char               *RefToDefinition;
#endif
#if defined(XSIGPRIO) || defined(XSIGPRSPRIO) || defined(XPRSSIGPRIO)
   int               Prio;
#endif
}  xSignalIdRec;   /* And xTimerEC, xStartUpSignalEC, and xRPCSignalEC.*/


                                  /*STATE*/
typedef struct xStateIdStruct {
   xEntityClassType  EC;
#ifdef XSYMBTLINK
   xIdNode           First;
   xIdNode           Suc;
#endif
   xIdNode           Parent;
#ifdef XIDNAMES
   xNameType         Name;
#endif
   int               StateNumber;
   XCONST_COMP xInputAction     *SignalHandlArray;
                         /*Used as an array of xInputAction.*/
   XCONST_COMP XINPUTREFTYPE    *InputRef;
   xInputAction      (*EnablCond_Function) (XSIGTYPE, void *);
   void              (*ContSig_Function) (void *, int *, xIdNode *, int *);
   int               StateProperties;
#ifdef XCOVERAGE
   long int         *CoverageArray;
#endif
   xStateIdNode      Super;
#ifdef XBREAKBEFORE
   char              *RefToDefinition;
#endif
}  xStateIdRec;


                                  /*SORT*/
typedef struct xSortIdStruct {
   xEntityClassType  EC;
#ifdef XSYMBTLINK
   xIdNode           First;
   xIdNode           Suc;
#endif
   xIdNode           Parent;
#ifdef XIDNAMES
   xNameType         Name;
#endif
   void              (*Free_Function) (void **);
#ifdef XTESTF
   xbool             (*Test_Function) (void *);
#endif
   xptrint           SortSize;
   xTypeOfSort       SortType;
   xSortIdNode       CompOrFatherSort;
   xSortIdNode       IndexSort;
   long int          LowestValue;
      /* xSyntype with one closed range  : lowest value */
      /* xGArray,xString,xGPowerset,xBag : offset of Data in type_yrec */
      /* xLString                        : offset of Data in type */
      /* otherwise                       : 0 */
   long int          HighestValue;
      /* xSyntype with one closed range  : highest value */
      /* xGArray,xString,xGPowerset,xBag : sizeof type_yrec */
      /* xCArray,xLString                : number of elements */
      /* SDL_Character                   : 255 */
      /* SDL_Boolean                     : 1 */
      /* otherwise                       : 0 */
   long int          yrecIndexOffset;
      /* xGArray                         : offset of Index in type_yrec */
      /* otherwise                       : 0 */
   long int          typeDataOffset;
      /* xGArray                         : offset of Data in type (default value) */
      /* otherwise                       : 0 */
#ifdef XREADANDWRITEF
   tSDLTypeInfo     *TypeInfo;
#endif
}  xSortIdRec;


                                  /*VARIABLE,...*/
typedef struct xVarIdStruct {
   xEntityClassType  EC;
#ifdef XSYMBTLINK
   xIdNode           First;
   xIdNode           Suc;
#endif
   xIdNode           Parent;
#ifdef XIDNAMES
   xNameType         Name;
#endif
   xSortIdNode       SortNode;
   tSDLTypeInfo     *TypeNode;
   xptrint           Offset;
   xptrint           Offset2;
                      /* Offset in startupsignal. Used for process fpar */
                      /* or: Offset for exported value. For process dcl */
   int               IsAddress;
                      /* Used if procedure/operator fpar: */
                      /* first bit = is address */
                      /* second-third bit IN(=0) - IN/OUT(=2) - OUT(=4) */
}  xVarIdRec;    /* And xFormalParEC and xSignalParEC.*/

#define XIS_ADDRESS(P)     ((P)->IsAddress & (int)1)
#define XIS_INOUT_PARA(P)  ((P)->IsAddress & (int)2)
#define XIS_RESULT_PARA(P) ((P)->IsAddress & (int)4)


                                  /*REMOTE VAR*/
typedef struct xRemoteVarListStruct *xRemoteVarListNode;
typedef struct xRemoteVarListStruct {
   xRemoteVarListNode  Next;
   xPrsIdNode          ExportingPrs;
#ifndef XNOUSEOFSERVICE
   xSrvIdNode          SrvId;
#endif
   xptrint             Offset;
}  xRemoteVarListRec;

typedef struct xRemoteVarIdStruct {
   xEntityClassType     EC;
#ifdef XSYMBTLINK
   xIdNode              First;
   xIdNode              Suc;
#endif
   xIdNode              Parent;
#ifdef XIDNAMES
   xNameType            Name;
#endif
   xptrint              SortSize;
   xRemoteVarListNode   RemoteList;
}  xRemoteVarIdRec;


                                  /*MONITORCOMMAND*/
#ifdef XMONITOR
typedef struct xMonitorCommandIdStruct  *xMonitorCommandIdNode;

typedef struct xMonitorCommandIdStruct {
   xEntityClassType  EC;
#ifdef XSYMBTLINK
   xIdNode           First;
   xIdNode           Suc;
#endif
   xIdNode           Parent;
#ifdef XIDNAMES
   xNameType         Name;
#endif
   int               CommandNo;
}  xMonitorCommandIdRec;

#endif

#ifdef XCONNECTPM
typedef  struct {
    xbool       PMConnected;
    int         MyPID;
    int         StartedFromPostmaster;
#ifdef XITEXCOMM
    int         ITEXCommStarted;
    int         TimeManager;
#endif
#ifdef XPMCOMM
    int         CommStarted;
#endif
#ifdef XSDLENVUI
    int         UIStarted;
#endif
#ifdef XSIMULATORUI
    int         SimulatorUIStarted;
#endif
#ifdef XMSCE
    int         MSCEStarted;
    int         MSCDiagram;
#endif
#ifdef TARGETSIM
    int         TargetParam;
#endif
  } xNoticeBoardType;
#endif


#ifdef XREADANDWRITEF
typedef struct xInteractionLogStruct {
  xbool Active;
  char  Filename[256];
  FILE  *File;
} xInteractionLogRec;

typedef struct xCommandFileStruct *xCommandFileNode;

typedef struct xCommandFileStruct {
  FILE  *File;
  char  *A[99];
  xCommandFileNode Next;
} xCommandFileRec;
#endif


#ifdef XMONITOR
typedef struct xAtBreakpointStruct *xAtBreakpointNode;

typedef struct xAtBreakpointStruct {
   char             *GRReference;
   xIdNode           PrsIdNode;
   long int          SymbolNumber;
   char             *Command;
   xAtBreakpointNode Next;
} xAtBreakpointRec;

typedef struct xVariableBreakpointStruct *xVariableBreakpointNode;

typedef struct xVariableBreakpointStruct {
   xPrsNode        Process;
   xPrdNode        Procedure;
#ifndef XNOUSEOFSERVICE
   xSrvNode        Service;
#endif
   xPrdIdNode      PrdId;
   int             PrdInstance;
   SDL_PId         PId;
   xVarIdNode      VarId;
   WriteBuf       *CurrentValue;
   char           *Command;
   xVariableBreakpointNode Next;
} xVariableBreakpointRec;

typedef struct xBreakpointStruct *xBreakpointNode;

typedef struct xBreakpointStruct {
   xPrsIdNode      ProcId;
   int             InstNr;
#ifndef XNOUSEOFSERVICE
   xSrvIdNode      SrvId;
#endif
   xStateIdNode    StateId;
   xSignalIdNode   SignalId;
   xPrsIdNode      SenderId;
   int             SenderInstNr;
   int             Counter;
   int             SetToCounter;
   xbool           Remove;
   char           *Command;
   xBreakpointNode Next;
} xBreakpointRec;

typedef struct xBreakpointOutputStruct *xBreakpointOutputNode;

typedef struct xBreakpointOutputStruct {
   xSignalIdNode   SignalId;
   xPrsIdNode      ReceiverId;
   int             ReceiverInstNr;
   xPrsIdNode      SenderId;
   int             SenderInstNr;
   int             Counter;
   int             SetToCounter;
   xbool           Remove;
   char           *Command;
   xBreakpointOutputNode Next;
} xBreakpointOutputRec;

typedef struct xSignalLogStruct *xSignalLogNode;

typedef struct xSignalLogStruct {
   xIdNode          UnitId;
/*  ***   Either no signal or a list of signals    ***
   xIdNode          SignalId;
    ***                                            ***   */
   xPrsNode         PrsNode;
   char             Filename[256];
   FILE            *File;
   xSignalLogNode   Next;
} xSignalLogRec;
#endif


#ifdef XMSCE
typedef struct {
  char  Filename[256];
  FILE  *File;
} MSCLogRec;
#endif


/****+***************************************************************
16   Global Data Structure
********************************************************************/
#ifndef XOPTSORT
extern XCONST struct xPackageIdStruct yPacR_Predefined;
extern XCONST struct xSortIdStruct    xSrtR_SDL_Boolean;
extern XCONST struct xSortIdStruct    xSrtR_SDL_Bit;
extern XCONST struct xSortIdStruct    xSrtR_SDL_Bit_String;
extern XCONST struct xSortIdStruct    xSrtR_SDL_Octet;
extern XCONST struct xSortIdStruct    xSrtR_SDL_Octet_String;
extern XCONST struct xSortIdStruct    xSrtR_SDL_Character;
extern XCONST struct xSortIdStruct    xSrtR_SDL_Charstring;
extern XCONST struct xSortIdStruct    xSrtR_SDL_IA5String;
extern XCONST struct xSortIdStruct    xSrtR_SDL_NumericString;
extern XCONST struct xSortIdStruct    xSrtR_SDL_PrintableString;
extern XCONST struct xSortIdStruct    xSrtR_SDL_VisibleString;
extern XCONST struct xSortIdStruct    xSrtR_SDL_Duration;
extern XCONST struct xSortIdStruct    xSrtR_SDL_Integer;
extern XCONST struct xSortIdStruct    xSrtR_SDL_Natural;
extern XCONST struct xSortIdStruct    xSrtR_SDL_Null;
extern XCONST struct xSortIdStruct    xSrtR_SDL_Object_Identifier;
extern XCONST struct xSortIdStruct    xSrtR_SDL_PId;
extern XCONST struct xSortIdStruct    xSrtR_SDL_Real;
extern XCONST struct xSortIdStruct    xSrtR_SDL_Time;
#define xSrtN_SDL_Boolean             (&xSrtR_SDL_Boolean)
#define xSrtN_SDL_Bit                 (&xSrtR_SDL_Bit)
#define xSrtN_SDL_Bit_String          (&xSrtR_SDL_Bit_String)
#define xSrtN_SDL_Octet               (&xSrtR_SDL_Octet)
#define xSrtN_SDL_Octet_String        (&xSrtR_SDL_Octet_String)
#define xSrtN_SDL_Character           (&xSrtR_SDL_Character)
#define xSrtN_SDL_Charstring          (&xSrtR_SDL_Charstring)
#define xSrtN_SDL_IA5String           (&xSrtR_SDL_IA5String)
#define xSrtN_SDL_NumericString       (&xSrtR_SDL_NumericString)
#define xSrtN_SDL_PrintableString     (&xSrtR_SDL_PrintableString)
#define xSrtN_SDL_VisibleString       (&xSrtR_SDL_VisibleString)
#define xSrtN_SDL_Duration            (&xSrtR_SDL_Duration)
#define xSrtN_SDL_Integer             (&xSrtR_SDL_Integer)
#define xSrtN_SDL_Natural             (&xSrtR_SDL_Natural)
#define xSrtN_SDL_Null                (&xSrtR_SDL_Null)
#define xSrtN_SDL_Object_Identifier   (&xSrtR_SDL_Object_Identifier)
#define xSrtN_SDL_PId                 (&xSrtR_SDL_PId)
#define xSrtN_SDL_Real                (&xSrtR_SDL_Real)
#define xSrtN_SDL_Time                (&xSrtR_SDL_Time)
#endif

extern XCONST struct xIdStruct        xSymbolTableIdRec;
#define xSymbolTableRoot      (&xSymbolTableIdRec)

extern XCONST struct xPrsIdStruct yEnvR_env;
extern xIdNode yEnvO_env[];

extern XCONST struct xStateIdStruct   xStartStateIdRec;
#define xStartStateId         (&xStartStateIdRec)

extern XCONST struct xSignalIdStruct  xContSigIdRec;
#define xContSigId            (&xContSigIdRec)

extern XCONST struct xStateIdStruct   xRPCWaitStateIdRec;

extern XCONST struct xSignalIdStruct  xNoneSigIdRec;
#define xNoneSigId            (&xNoneSigIdRec)

extern XCONST struct xPrsIdStruct xNullIdRec;
#define xNullId               (&xNullIdRec)

#define xTranslatorVersion  xSysD.xTranslatorVersion_Var
#define xInputPos  xSysD.xInputPos_Var

typedef struct xSystemData {
    xPrsNode       xReadyQueue;
    xSignalNode    xTimerQueue;
    xPrsNode       xCheckList;
#ifdef THREADLIGHT
    xInputPortRec  xNewSignals;
    THREADLIGHT_THREAD_VARS
#endif

#ifdef XCLOCK
#ifndef XCALENDERCLOCK
    SDL_Time       xStartTime;
#endif
#else
    SDL_Time       xSystemTime;
#endif

#ifdef XERRORSTATE
    xStateIdNode   xErrorStateId;
#endif

#ifdef XCTRACE
    char      *xCFileName;
    long int   xCLineNo;
    xbool      xBetweenTrans;
#endif

#if defined(XGRTRACE) || defined(XMONITOR)
    char      *xCurrentSymbolRef;
    char      *xPreviousSymbolRef;
#endif

#ifdef XCONNECTPM
    xNoticeBoardType  xNoticeBoard;
#endif

#ifdef XPMCOMM
    xbool      xRaW_use_Global_PId;
#endif

#ifdef XITEXCOMM
    xbool      xUse_Itex_Syntax;
#endif

#ifdef XMONITOR
    int        xCurrentSymbolNumber;
    char      *xTranslatorVersion_Var;  /* from generated code */
    xbool      xMonitorCreate;
    xbool      xMonitorOutput;
    xbool      xDynamicError;
    xbool      xDoLoopForInput;
    xPrsNode   xPrsScope;
    xPrdNode   xPrdScope;
#ifndef XNOUSEOFSERVICE
    xSrvNode   xSrvScope;
#endif
#endif

#if defined(XMONITOR) && defined(XCLOCK)
    SDL_Duration xTimeInMonitor;
#endif

#ifdef XREADANDWRITEF
    char      *SystemName;
    char       xInputLineVar[MAX_READ_LENGTH];
    char      *xInputLine;
    char      *xInputPos_Var;
    char      *xSaveLine;
    char      *xSavePos_Var;
    xbool      xUse_ASN1_Syntax;
    xbool      xUse_NewRef_Syntax;
    xbool      xUse_DeRef_Syntax;
    xbool      xValue_Syntax;
    int        xIntegerOutputMode;
    char       xPrintIntFormat[10];
    char       xScanIntFormat[10];
#endif

#ifdef XTRACE
    int        Trace_Default;
    int        xSilent;
#endif

#ifdef XGRTRACE
    int        GRTrace;
#endif

#if defined(XTRACE) || defined(XGRTRACE)
    xbool      xNoTraceOn;
#endif

#if defined(XENV) && defined(XMONITOR)
    xbool      xInEnvOn;
#endif

#ifdef XMSCE
    int        MSCETrace;
    int        xSilentMSCE;
                 /* Set when calling SDL_Output in
                    SDL_OutputTimerSignal to prevent extra MSC-trace */
#endif
#ifdef XREADANDWRITEF
    xInteractionLogRec InteractionLog;
    xInteractionLogRec CommandLog;
    xCommandFileNode   CommandFile;

    int        WriteSortLevel;           /* used by xWriteSort */
    FILE      *ExtSynFile;
    xbool      First_Call; /* to xReadSynonym */
    char       ExtSynFileName[256];
#endif

#ifdef XMONITOR
        /* Local data in sctmon.c */   
    int        Interrupted;
    int        xProceedUntil;
    int        xGoForever;
    int        StopInMonitor;
    int        StoppedInMonitor;
    int        StepSymbol;
    int        StepStatement;
    int        NextSymbol;
    int        NextStatement;
    int        Finish;
    int        NextLevel;
    int        xStepToVisible;
    int        WelcomeMessagePrinted;
    SDL_Time   NowInMonitor;
    xIdNode    xCommandTable;
    SDL_Time   xNextMonTimeVar;

#ifndef XNOSELECT
    xbool      xDoCheckForInput;
#endif

    xVariableBreakpointNode VariableBreakpoints;
    xAtBreakpointNode     AtBreakpoints;
    xBreakpointNode       TransitionBreakpoints;
    xBreakpointOutputNode OutputBreakpoints;
    xSignalLogNode        SignalLogList;

#ifdef XCOVERAGE
    FILE     *xCoverageFile;
#endif

#endif
       /* XMONITOR */

#ifdef XMSCE
    MSCLogRec  MSCLog;
    int        MSCLogStarted;
     /* =1 MSC-Log started.
        xSysD.xNoticeBoard.MSCEStarted = 0 means Batch
        otherwise Interactive */

    int        GlobalProcessInstanceId;
    int        GlobalSignalInstanceId;

    int        GlobalSignalInstanceIdWhenStart;
     /* Value of GlobalSignalInstanceId when MSC Trace started,
        used to find signal sent before MSC Trace started.
       (NOTE! The signals may have been sent in a previous MSC Trace)   */
    int        VoidProcessInstanceId;
     /* Void process instance is used to represent all process
        instances not being traced */
    int        DoingReset;   /* used by xMSCEReset */
    int        MSCSymbolLevel;

#endif
       /* XMSCE */

#ifdef XSIMULATORUI
    char       SESIMUICOMStr[MAX_READ_LENGTH];

    int        SESIMUICOMFlag; /* =1 means SESIMUICOMStr contains input */
    int        SESIMUICOMInput;
#endif

#ifdef XCOVERAGE
    long int   SystemTransNo, SystemSymbNo;
#endif
  } xSystemData;


/****+***************************************************************
     In generated code
********************************************************************/
extern void yInit (void);

/****+***************************************************************
     C++ specific declarations
********************************************************************/
#ifdef __cplusplus
#ifdef __BORLANDC__
#include <stddef.h> /* size_t */
#else
#include <cstddef> /* size_t */
#endif
typedef char * xSpecial;
extern void * operator new (size_t pp, xSpecial vv);
#endif

/****+***************************************************************
17   sctos
********************************************************************/

#ifdef XCLOCK
extern SDL_Time SDL_Clock (void);
#endif

#if defined(XCLOCK) && !defined(XENV)
extern void xSleepUntil (SDL_Time WakeUpTime);
#endif

extern void * xAlloc (xptrint);
extern void xFree (void **);
extern void xHalt (void);

#if defined(XPMCOMM) && !defined(XENV)
extern int xGlobalNodeNumber (void);
#endif

#if defined(XMONITOR) && !defined(XNOSELECT)
extern xbool xCheckForKeyboardInput (long);
#endif

#if defined(XMONITOR)
extern char *xGetWorkdir (char **d);
extern char *xSetWorkdir (char *d);
#endif

/****+***************************************************************
18   sctenv
********************************************************************/

#ifdef XENV
extern int xGlobalNodeNumber (void);
extern void xInitEnv (void);
extern void xCloseEnv (void);
extern void xOutEnv (xSignalNode *);
#ifndef XTENV
extern void xInEnv (SDL_Time);
#else
extern SDL_Duration xInEnv (SDL_Time);
#endif
#endif
       /* XENV */

#ifdef XSIGLOG
extern void xSignalLog (xSignalNode, int, xIdNode *, int);
extern void xProcessLog (xPrsNode);
#endif


/****+***************************************************************
19   sctsdl
********************************************************************/

#ifndef THREADLIGHT
extern xSystemData  xSysD;
#endif
extern xSignalNode  xAvailSignal;
extern xSignalNode  xAvailTimer;

#if !defined(XNOUSEOFREAL) && defined(XEFIXOF)
extern SDL_Integer  xMax_SDL_Integer;
#endif
extern SDL_Time     xMaxTime;
extern SDL_PId      xEnv;
extern xPrsIdNode   xEnvId;
extern SDL_PId      SDL_NULL;
#ifndef XOPTCHAN
extern SDL_PId      xNotDefPId;
#endif

#ifdef XEOUTPUT
extern void xSDLOutputError (int, xSignalNode, int);
#endif
#ifdef XOPERRORF
extern void xSDLOpError (char *, char *);
#endif
#ifdef XERANGE
extern void xErrorSubrange (tSDLTypeInfo *, void *);
#endif
#ifdef XEINDEX
extern void xErrorIndex (tSDLTypeInfo *, void *);
#endif
#ifdef XEDECISION
extern void xErrorDecision (tSDLTypeInfo *, void *);
#endif
extern void * SDL_Error (int);
#ifdef XASSERT
extern void xAssertError (char *);
#endif
#ifdef XEUNION
extern void xUnionTagError (char *, void *, tSDLTypeInfo *, xbool);
#endif
#ifdef XEOPTIONAL
extern void xOptionalError (char *);
#endif
#ifdef XECODER
extern void xCoderError (char *, char *);
#endif
#ifdef XECHOICE
extern void xChoiceError (char *, void *, tSDLTypeInfo *);
#endif
#ifdef XEREF
extern void xRefError (void *, tSDLGenInfo *);
#endif
#ifdef XEOWN
extern void xInsertOwnList (void *, tSDLTypeInfo *);
extern void xRemoveOwnList (void *);
extern void xSetUpOwner (void **, xbool);
extern void xCheckRefOwn (void *);
extern void xCheckForOwnLoops (void);
#endif

#if defined(XSYMBTLINK) || defined(XCOVERAGE) || defined(XMONITOR)
extern void xInsertIdNode (xIdNode);
#else
#define xInsertIdNode(Node)
#endif

extern SDL_PId xGetPId (xPrsIdNode, SDL_PId);
extern void xReleasePId (SDL_PId *);

#ifndef XNOUSEOFSERVICE
extern xSrvNode xGetService (xSrvIdNode, xPrsNode);
extern void xReleaseService (xSrvNode *);
#endif

extern xSignalNode xGetSignal (XSIGTYPE, SDL_PId, SDL_PId);
extern void xReleaseSignal (xSignalNode *);
extern void xReleaseSignalNotPara (xSignalNode *);
extern xPrdNode xGetPrd (xPrdIdNode);
extern void xReleasePrd (xPrsNode); 

extern void xInsertExportedVar (xRemoteVarListNode, xRemoteVarIdNode);
extern void xInsertExportedPrd (xRemotePrdListNode, xRemotePrdIdNode);
extern xbool xInList (XSIGTYPE, XSIGTYPE *);
extern void xAddPrdCall (xPrdNode, xPrsNode, int, int);
extern xIdNode xContentsInstNode (xIdNode, xIdNode);
#ifdef THREADLIGHT
extern SDL_PId SDL_TO_Process (xPrsIdNode);
#endif

#if defined(XEOUTPUT) || defined(XMONITOR)
#ifdef XSIGPATH
extern int xIsPath (XSIGTYPE, xIdNode, xPrsIdNode, xIdNode *, xIdNode [], int *);
#else
extern int xIsPath (XSIGTYPE, xIdNode, xPrsIdNode, xIdNode *);
#endif
#endif

#ifndef XOPTCHAN
#ifdef XSIGPATH
extern SDL_PId xFindReceiver (XSIGTYPE, SDL_PId, xIdNode *, int *, xIdNode *, int *);
#else
extern SDL_PId xFindReceiver (XSIGTYPE, SDL_PId, xIdNode *, int *, xIdNode *);
#endif
#endif

extern void xRemoveFromQueue (void *);
extern void SDL_Output (xSignalNode xSigPrioPar(int), xIdNode []);
extern void SDL_Create (xSignalNode, xPrsIdNode, int);
extern void SDL_Stop (xPrsNode);
extern void SDL_Set (SDL_Time, xSignalNode);
extern void SDL_Reset (xSignalNode *);
extern void SDL_SimpleReset (xPrsNode, XSIGTYPE);
extern SDL_Boolean SDL_Active (XSIGTYPE, xPrsNode);
extern void SDL_NextState (xPrsNode, int);
extern void SDL_RPC_WaitState (xPrsNode, int, XSIGTYPE);
extern SDL_Time SDL_Now (void);
extern void * xGetExportAddr (xRemoteVarIdNode, SDL_PId, xbool, xPrsNode);
extern SDL_PId xGetExportingPrs (xRemotePrdIdNode, xPrsNode);
extern void * SDL_View (xViewListRec *, SDL_PId, xbool, xPrsNode, xeView(char *) int);
extern int SDL_View_Index (xPrsNode, char *);
extern void SDL_Halt (void);
extern SDL_Boolean xEq_SDL_PId (SDL_PId, SDL_PId);
extern SDL_Boolean xEq_SDL_PId_NULL (SDL_PId A);

#ifndef XNOUSEOFSERVICE
extern void xStart_Services (xPrsNode);
#endif

#ifdef XCONNECTPM
extern void xSysDInit (int, char * [], xSystemData*);
extern void xMainInit (int, char * []);
#else
extern void xSysDInit (xSystemData*);
extern void xMainInit (void);
#endif
#if !defined(XNOMAIN) && !defined(THREADLIGHT)
extern void xMainLoop (void);
#endif
#ifdef THREADLIGHT
#if defined(THREADSOLARIS) || defined(THREADVXWORKS)
#ifdef __cplusplus
extern "C"  void * xMainLoop (void *);
#else
extern void * xMainLoop (void *);
#endif 

#elif THREADOSE
extern OSENTRYPOINT xMainLoop;
#else
extern void xMainLoop (xSystemData *);
#endif /* THREADSOLARIS */
#endif

#if defined(XNOMAIN) && !defined(THREADLIGHT)
extern void SDL_OutputTimer (void);
extern void SDL_Execute (void);
extern int SDL_Timer_Prio (void);
extern int SDL_Transition_Prio (void);
extern SDL_Time SDL_Timer_Time (void);
#endif

#ifndef XOPTCHAN
extern void xAddToEnv (xChannelIdNode);
#endif


/****+***************************************************************
20   sctpost
********************************************************************/

#if defined(XPMCOMM) || defined(XITEXCOMM)
extern XSIGTYPE xEnvFindSignalId (char *);
#endif
#ifdef XITEXCOMM
extern xIdNode xEnvFindChannelId (char *);
#endif



/****+***************************************************************
21   sctutil
********************************************************************/

#ifdef XREADANDWRITEF
#define xChangeInputLine(strVar) \
  xSysD.xSaveLine = xSysD.xInputLine; \
  xSysD.xSavePos_Var = xSysD.xInputPos_Var; \
  xSysD.xInputLine = strVar; \
  xSysD.xInputPos_Var = strVar
#define xRestoreInputLine() \
  xSysD.xInputLine = xSysD.xSaveLine; \
  xSysD.xInputPos_Var = xSysD.xSavePos_Var; \
  xSysD.xSaveLine = (char *)0
#define xUngetChar()    (void)xInputPos--

typedef enum {
  xxId, xxString, xxASN1String, xxSlash, xxColon, xxMinus, xxPlus, xxStar,
  xxComma, xxSemicolon, xxArrowHead,
  xxLPar, xxRPar, xxLParDot, xxRParDot, xxLParColon, xxRParColon, xxDot,
  xxLBracket, xxRBracket, xxLCurlyBracket, xxRCurlyBracket, xxAt,
  xxQuaStart, xxQuaEnd,
  xxLT, xxLE, xxGT, xxGE, xxEQ, xxNE,
  xxQuestionMark, xx2QuestionMark, xxExclMark, xxRArrow, xxStarArrow,
  xxSystem, xxPackage, xxBlock, xxProcess, xxService, xxProcedure,
  xxOperator, xxSubstructure, xxChannel, xxSignalroute, xxType,
  xxNull, xxEnv, xxSelf, xxParent, xxOffspring, xxSender,
  xxEoln, xxEOF, xxErrorToken
} xxToken;

extern int xNextInputChar (void);
extern xxToken xScanToken (char *);
extern void xUngetToken (xxToken, char *);
extern void xSkipLine (void);
extern int xScanS (char *);
extern void xReadSynonym (void *, xSortIdNode, char *);
extern xxToken xPromptQuestionMark (char *, char *, char *);
extern xIdNode xGetIdNodeInECSet (char *, long, xIdNode, xbool *, xbool, xIdNode);
extern xIdNode xReadIdNodeInECSet (xxToken, char *, long, xIdNode, xIdNode);
extern int xfEqualIdString (char *, char *);
extern int lenNL(void **);
extern void addNL(void ***, void *);
extern int indexNL(void **, void *);
extern void releaseNL(void ***);

extern char * xWriteSort (void *, xSortIdNode);
extern void xWriteOpParameter (char *, void *, tSDLTypeInfo *);
extern xbool xReadOperator (void *, xSortIdNode);
extern void xGetQualifier (WriteBuf *, xIdNode, int);
extern xbool xNeedsQualifier (xIdNode);

#ifdef XMSCE
extern void xMSCEProcedureReturn (xPrsNode, xPrdNode );
extern void xMSCEDecision (void *, tSDLTypeInfo *);
extern void xMSCETask (char *);
extern void xMSCEAssign (char *, void *, tSDLTypeInfo *);
extern void xMSCEConstructor (SDL_PId, char *, char *);
extern void xMSCEDestructor (SDL_PId, char *);
extern void xMSCEMethodCall (SDL_PId, char *, char *);
#endif
       /* XMSCE */

#endif
       /* XREADANDWRITEF */


/****+***************************************************************
22   sctmon
********************************************************************/

#ifdef XREADANDWRITEF
extern void xInitReadAndWrite (void);
extern void xPrintString (char * Str);
extern int xRead_SDL_PId (void *);
extern char * xWri_SDL_PId (void *);
extern void xInformalDecision (char *);
extern void xInformalPath (int, char *, int, int [], char *[]);
extern void xAnyDecision (void);
extern void xAnyPath (int, int, int []);
extern void xReadPath (SDL_Integer *, int, int [], char * [], xbool);
#endif
       /* XREADANDWRITEF */

#ifdef XTRACE
typedef enum {
  xtOutput, xtOutputDiscard, xtOutputPara, xtTask, xtTaskValue,
  xtDecision, xtProcedureStart, xtProcedureReturn, xtProcedurePara,
  xtCreate, xtCreatePara, xtSet,
  xtSetChangeTime, xtSetPara, xtSetImplicitReset, xtReset, xtResetAction,
  xtResetPara, xtTimerOutput, xtTimerOutputDiscard, xtTimerOutputPara,
  xtNextstate, xtNextstateDiscard, xtNextstateDiscardPara, xtStop,
  xtStopDiscard, xtStopDiscardPara, xtStopTimerDiscard,
  xtStopTimerDiscardPara, xtTransition, xtTransitionPara,
  xtExport,
  xtVisibleStep,
  xtOne, xtTwo, xtThree, xtFour, xtFive, xtSix, xtSeven, xtEight,
  xtNine, xtTen
} xTraceType;

extern xbool xShouldBeTraced (xTraceType, xPrsNode);
extern void xTraceTask (char *);
extern void xTraceAlg (char *);
extern void xTraceAlgValue (char *, void *, tSDLTypeInfo *);
extern void xTraceAssign (char *, void *, tSDLTypeInfo *);
extern void xTraceDecision (void *, tSDLTypeInfo *);
extern void xTraceNotImplCreate (char * S);
extern void xTraceNotImplProcedure (char * S);
extern void xTraceProcedureReturn (xPrdNode);
extern void xTraceExport (char *);
#endif
       /* XTRACE */

#ifdef XBREAKBEFORE
extern void xSetupGRCov (xPrsNode, int);
extern xbool xBreakBefore (xPrsNode, xCTrace(char *) xCTrace(long int) int, xbool);
extern void xGRSetSymbol (int);
#endif


#endif
       /* X_SCTTYPES_H */
