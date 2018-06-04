transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/PWM_ver {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/PWM_ver/pwm_ver.v}

vlog -vlog01compat -work work +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/PWM_ver/simulation/modelsim {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/PWM_ver/simulation/modelsim/pwm_ver.vt}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneiii_ver -L rtl_work -L work -voptargs="+acc"  pwm_ver_vlg_ts

add wave *
view structure
view signals
run -all
