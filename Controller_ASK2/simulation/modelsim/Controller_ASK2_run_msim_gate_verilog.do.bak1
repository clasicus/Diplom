transcript on
if {[file exists gate_work]} {
	vdel -lib gate_work -all
}
vlib gate_work
vmap work gate_work

vlog -vlog01compat -work work +incdir+. {Controller_ASK2_7_1200mv_100c_slow.vo}

vlog -vlog01compat -work work +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/AD7687/simulation/modelsim {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/AD7687/simulation/modelsim/AD7687.vt}

vsim -t 1ps +transport_int_delays +transport_path_delays -L altera_ver -L cycloneiii_ver -L gate_work -L work -voptargs="+acc"  AD7687_vlg_test

add wave *
view structure
view signals
run -all
