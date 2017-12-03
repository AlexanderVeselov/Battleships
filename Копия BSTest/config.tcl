set flagCLEAR 1
set flagMPP 1
set flagATS 1
set flagACT 1
set flagCOMPILERUN 1


set telelogicdir "C:/Telelogic/SDL_TTCN_Suite4.3/"
set prname "battleships"
set projectRoot "c:/Battleships"
set sdltarget "${projectRoot}/Strategy/target/"
set sourceDir "${projectRoot}/Source/"
set sdlsystemname "Model"


set compilerOptions "/D _Windows /D IC86 /D SCTAPPLCLENV\
		 /D XUSE_GENERIC_FUNC /D XIDNAMES /D XNRINST\
		 /D XUSER_CLOCK_FUNC /D TAT_TIME_SUPPORT\
		 /D TAT_INSTANCE_SUPPORT"

set libpath "C:/Program Files/Microsoft Visual Studio 8/VC/lib"
set mprtail N0_0.mpr
