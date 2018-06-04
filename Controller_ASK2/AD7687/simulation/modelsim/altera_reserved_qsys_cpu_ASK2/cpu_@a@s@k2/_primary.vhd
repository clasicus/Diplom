library verilog;
use verilog.vl_types.all;
entity cpu_ASK2 is
    port(
        clk_clk         : in     vl_logic;
        reset_reset_n   : in     vl_logic;
        pio_angle_external_connection_export: inout  vl_logic_vector(15 downto 0);
        pio_lcd_control_external_connection_export: out    vl_logic_vector(2 downto 0);
        pio_lcd_data_external_connection_export: inout  vl_logic_vector(7 downto 0);
        pio_res_nwr_external_connection_export: out    vl_logic;
        pio_res_nrd_external_connection_export: out    vl_logic;
        pio_res_nsoe_external_connection_export: inout  vl_logic;
        pio_res_nsample_external_connection_export: out    vl_logic;
        pio_res_ncs_external_connection_export: out    vl_logic;
        pio_a1_a0_external_connection_export: out    vl_logic_vector(1 downto 0);
        pio_sdo_adc_external_connection_export: in     vl_logic_vector(15 downto 0);
        pio_i_max_external_connection_export: out    vl_logic_vector(15 downto 0);
        pio_keyboard_sw6_sw1_external_connection_export: in     vl_logic_vector(5 downto 0);
        pio_led2_led1_external_connection_export: out    vl_logic_vector(1 downto 0);
        pio_pwm_in_external_connection_export: out    vl_logic_vector(15 downto 0)
    );
end cpu_ASK2;
