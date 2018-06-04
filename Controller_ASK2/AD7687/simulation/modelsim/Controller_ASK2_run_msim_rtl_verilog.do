transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/PWM_ver {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/PWM_ver/pwm_ver.v}
vlog -vlog01compat -work work +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/AD7687 {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/AD7687/AD7687.v}
vlog -vlog01compat -work work +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2 {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/REST_Global.v}
vlog -vlog01compat -work work +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/pll0_altpll.v}
vlib altera_reserved_qsys_cpu_ASK2
vmap altera_reserved_qsys_cpu_ASK2 altera_reserved_qsys_cpu_ASK2
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2 {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/cpu_ASK2.v}
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/altera_avalon_sc_fifo.v}
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/altera_reset_controller.v}
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/altera_reset_synchronizer.v}
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_jtag_uart_0.v}
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_onchip_memory2_0.v}
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_pio_A1_A0.v}
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_pio_I_max.v}
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_pio_SDO_ADC.v}
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_pio_angle.v}
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_pio_keyboard_SW6_SW1.v}
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_pio_lcd_control.v}
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_pio_lcd_data.v}
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_pio_res_nSOE.v}
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_pio_res_nWr.v}
vlog -vlog01compat -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_sysid_qsys_0.v}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/altera_merlin_arbitrator.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/altera_merlin_burst_uncompressor.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/altera_merlin_master_agent.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/altera_merlin_master_translator.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/altera_merlin_slave_agent.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/altera_merlin_slave_translator.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/altera_merlin_traffic_limiter.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_addr_router.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_addr_router_001.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_cmd_xbar_demux.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_cmd_xbar_demux_001.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_cmd_xbar_mux.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_id_router.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_id_router_002.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_irq_mapper.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_rsp_xbar_demux.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_rsp_xbar_demux_002.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_rsp_xbar_mux.sv}
vlog -sv -work altera_reserved_qsys_cpu_ASK2 +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/db/ip/cpu_ASK2/submodules/cpu_ASK2_rsp_xbar_mux_001.sv}
vcom -93 -work work {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/pll0.vhd}

vlog -vlog01compat -work work +incdir+D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/AD7687/simulation/modelsim {D:/work/RADIONIX/KOORDINATOR/ALTERA_13/Controller_ASK2/AD7687/simulation/modelsim/AD7687.vt}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneiii_ver -L rtl_work -L work -L altera_reserved_qsys_cpu_ASK2 -voptargs="+acc"  AD7687_vlg_test

add wave *
view structure
view signals
run -all
