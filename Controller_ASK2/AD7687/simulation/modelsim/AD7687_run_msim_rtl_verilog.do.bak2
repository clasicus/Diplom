transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/AD7687 {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/AD7687/AD7687.v}

vlog -vlog01compat -work work +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/AD7687/simulation/modelsim {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/AD7687/simulation/modelsim/AD7687.vt}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneiii_ver -L rtl_work -L work -voptargs="+acc"  AD7687_vlg_tst

add wave *
view structure
view signals
run -all
