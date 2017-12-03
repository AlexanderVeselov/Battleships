source run.tcl

proc rglob {src pattern} {
	set res {}
	set dir $src
	while 1 {
		set cur [glob -type f -nocomplain $dir/$pattern]
		set res [concat $res $cur]
		if [expr {{} == [glob -type d -nocomplain $dir]}] {
			break
		}
		set dir $dir/*
	}
	return $res
}

set mprtail N0_0.mpr

proc copylog {base} {
	global mprtail
	catch {
		puts "COPYLOG $base"
		file copy -force result/${base}${mprtail} ./${base}${mprtail}
	}
}

proc basename {file} {
	return [file rootname [file tail $file]]
}

foreach mpr [rglob msc *.mpr] {
	set base [basename $mpr]
	runTest $mpr
	copylog $base
}
