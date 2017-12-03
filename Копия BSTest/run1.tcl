source config.tcl

proc runTest {mprfile} {
	global flagCLEAR flagMPP flagATS flagACT flagCOMPILERUN
	global telelogicdir prname projectRoot sdltarget sourceDir
	global compilerOptions libpath 
	set SIC_PATH "c:/Motorola/sic"
		
	proc runCond {name flag cmd} {
		if $flag {
			puts "ENTER $name"
			catch {eval $cmd} msg
			puts "EXIT $name:\n${msg}\n"
		}
	}


	set tclsh [info nameofexecutable]
	if { $tclsh == "" } {
		puts "Fatal ERROR: Can`t setup Tcl shell!"
		return (1)
	}
	
	
if {$flagCLEAR} then {
	set files [glob -nocomplain -- *.obj *.mpr *.txt *.exe *.lst test/*.* work/*.* ]
	foreach f $files {
		file delete $f
	}

}

if { $flagMPP } then {
	catch {eval exec "$SIC_PATH/bin/macroprc -config config.xml -m  $mprfile -glob -iar -plaindir -il -ul -o work -list work/macroprc_mpr.lst"} res1
	puts "MACROPREPROCESSOR:\n${res1}\n"
}

if { $flagATS } then {
	puts [pwd]
	catch {eval exec "$SIC_PATH/bin/atsgen -m @work/macroprc_mpr.lst -config config.xml -o work/${prname}test.tcl -mf -tt -state -nia -incl types.h"} res3
    	puts "ATS GENERATOR:\n${res3}\n"
}

if { $flagACT } then {
    catch {eval exec "\$tclsh\ $SIC_PATH/bin/cgtc.tcl -ats work/${prname}test.tcl -inst -break -log -time -o test"} res4
    puts "TEMPLATE:\n${res4}\n"
}


	if { $flagCOMPILERUN } then {

	set srcfiles "$SIC_PATH/cgtc/testkern.c "
	append srcfiles "$SIC_PATH/cgtc/txtlog.c "
	append srcfiles "$SIC_PATH/cgtc/mprlog.c "
	append srcfiles "test/${prname}test.c "
	append srcfiles "test/${prname}testdata.c "
	append srcfiles "const_code/wrapper.c "
	append srcfiles "const_code/env.c "
	append srcfiles "${sdltarget}/Model.c "
	append srcfiles "${sdltarget}/BasicTypes.c "
	append srcfiles "${sdltarget}/ctypes.c "
	append srcfiles "C:/Battleships/Battleships/Source/MapFunctions.c "
	append srcfiles "C:/Battleships/Battleships/Source/ExternalFunction.c "
	append srcfiles "${telelogicdir}/sdt/sdtdir/wini386/include/sctsdl.c "
	append srcfiles "${telelogicdir}/sdt/sdtdir/wini386/include/sctpred.c "
	append srcfiles "${telelogicdir}/sdt/sdtdir/wini386/include/sctos.c"
	#puts $srcfiles

	set inclDir "/I $SIC_PATH/cgtc /I ${telelogicdir}/sdt/sdtdir/wini386/include /I ${sdltarget} /I test /I const_code"

	set optComp "/D _Windows /D IC86 /D SCTAPPLCLENV\
			 /D XUSE_GENERIC_FUNC /D XIDNAMES /D XNRINST\
			 /D XUSER_CLOCK_FUNC /D TAT_TIME_SUPPORT\
			 /D TAT_INSTANCE_SUPPORT"
	#puts $optComp



	catch {eval exec "cl.exe $srcfiles $inclDir $optComp /Fetest.exe"} res5
      catch {eval exec "link.exe *.obj /out:test.exe \"/libpath:C:/Program Files/Microsoft Visual Studio 8/VC/lib/\""} res6
	puts "COMPILE:\n${res5}\n"
	puts "LINK:\n${res6}\n"

	set files [glob -nocomplain -- *.obj]
	foreach f $files {
		file delete $f
	}
	

		runCond RUN 1 {exec "test.exe"}
	}

	puts "End"
	unset tclsh
}

proc copylog {base} {
	global mprtail
	catch {
		puts "COPYLOG $base"
		file copy -force result/${base}${mprtail} ./${base}${mprtail}
	}
}
