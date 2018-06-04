transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+I:/SYS_REST {I:/SYS_REST/SYS_REST.v}

vlog -vlog01compat -work work +incdir+I:/SYS_REST/simulation/modelsim {I:/SYS_REST/simulation/modelsim/SYS_REST.vt}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L maxv_ver -L rtl_work -L work -voptargs="+acc"  test_1

add wave *
view structure
view signals
run -all
