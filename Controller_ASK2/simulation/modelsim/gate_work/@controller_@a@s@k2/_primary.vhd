library verilog;
use verilog.vl_types.all;
entity Controller_ASK2 is
    port(
        altera_reserved_tms: in     vl_logic;
        altera_reserved_tck: in     vl_logic;
        altera_reserved_tdi: in     vl_logic;
        altera_reserved_tdo: out    vl_logic;
        n_Reset         : out    vl_logic;
        in_clk_10MHz    : in     vl_logic;
        out_pio_res_nWR : out    vl_logic;
        out_pio_res_nSOE: out    vl_logic;
        bidir_angle     : inout  vl_logic_vector(15 downto 0);
        in_pio_keyboard : in     vl_logic_vector(5 downto 0);
        bidir_port_lcd_data: inout  vl_logic_vector(7 downto 0);
        ADC_SDO         : in     vl_logic;
        out_pio_res_nRD : out    vl_logic;
        out_pio_res_nSample: out    vl_logic;
        out_pio_res_nCS : out    vl_logic;
        ADC_CNV         : out    vl_logic;
        ADC_CLK         : out    vl_logic;
        Drv_PWM         : out    vl_logic;
        Drv_DIR         : out    vl_logic;
        Drv_DIS         : out    vl_logic;
        out_clk_resolver: out    vl_logic;
        out_lcd_E_RNOTW_RS: out    vl_logic_vector(2 downto 0);
        out_LED2_LED1   : out    vl_logic_vector(1 downto 0);
        out_pio_res_A1_A0: out    vl_logic_vector(1 downto 0)
    );
end Controller_ASK2;
