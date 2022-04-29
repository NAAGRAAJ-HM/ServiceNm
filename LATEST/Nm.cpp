/******************************************************************************/
/* File   : Nm.cpp                                                            */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "CfgNm.hpp"
#include "Nm_core.hpp"
#include "infNm.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define NM_AR_RELEASE_VERSION_MAJOR                                            4
#define NM_AR_RELEASE_VERSION_MINOR                                            3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(NM_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible NM_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(NM_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible NM_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_Nm:
      public abstract_module
   ,  public class_Nm_Functionality
{
   public:
      module_Nm(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, NM_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, NM_CONFIG_DATA, NM_APPL_CONST) lptrCfgModule
      );
      FUNC(void, NM_CODE) DeInitFunction (void);
      FUNC(void, NM_CODE) MainFunction   (void);
      NM_CORE_FUNCTIONALITIES
};

extern VAR(module_Nm, NM_VAR) Nm;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, NM_VAR, NM_CONST) gptrinfEcuMClient_Nm = &Nm;
CONSTP2VAR(infDcmClient,  NM_VAR, NM_CONST) gptrinfDcmClient_Nm  = &Nm;
CONSTP2VAR(infSchMClient, NM_VAR, NM_CONST) gptrinfSchMClient_Nm = &Nm;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Nm, NM_VAR) Nm(
   {
         NM_AR_RELEASE_VERSION_MAJOR
      ,  NM_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, NM_CODE) module_Nm::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, NM_CONFIG_DATA, NM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == Nm_InitCheck)
   if(E_OK == IsInitDone){
#if(STD_ON == Nm_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      if(NULL_PTR == lptrCfgModule){
#if(STD_ON == Nm_DevErrorDetect)
         Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
         );
#endif
      }
      else{
         if(STD_LOW){
// check lptrCfgModule for memory faults
            lptrCfg = lptrCfgModule;
         }
         else{
// use PBcfgCanIf as back-up configuration
            lptrCfg = &PBcfgNm;
         }
      }
      IsInitDone = E_OK;
#if(STD_ON == Nm_InitCheck)
   }
#endif
}

FUNC(void, NM_CODE) module_Nm::DeInitFunction(void){
#if(STD_ON == Nm_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == Nm_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      IsInitDone = E_NOT_OK;
#if(STD_ON == Nm_InitCheck)
   }
#endif
}

FUNC(void, NM_CODE) module_Nm::MainFunction(void){
#if(STD_ON == Nm_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == Nm_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
#if(STD_ON == Nm_InitCheck)
   }
#endif
}

FUNC(void, NM_CODE) class_Nm_Functionality::PassiveStartUp(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::NetworkRequest(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::NetworkRelease(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::DisableCommunication(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::EnableCommunication(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::GetPduData(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::GetUserData(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::SetUserData(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::RepeateMessageRequest(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::GetNodeIdentifier(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::GetLocalNodeIdentifier(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CheckRemoteSleepIndication(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::GetState(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CbNetworkStartIndication(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CbNetworkMode(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CbBusSleepMode(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CbPrepareBusSleepMode(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CbRemoteSleepIndication(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CbRemoteSleepCancellation(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CbSynchronizationPoint(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CbCoordReadyToSleepIndication(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CbCoordReadyToSleepCancellation(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CbPduRxIndication(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CbStateChangeNotification(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CbRepeateMessageIndication(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CbTxTimeoutException(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CbCarWakeUpIndication(void){
}

FUNC(void, NM_CODE) class_Nm_Functionality::CalloutCarWakeUp(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

