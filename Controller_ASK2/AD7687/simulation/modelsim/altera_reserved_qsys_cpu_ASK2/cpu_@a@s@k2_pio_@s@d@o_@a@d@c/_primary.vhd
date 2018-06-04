library verilog;
use verilog.vl_types.all;
entity cpu_ASK2_pio_SDO_ADC is
    port(
        address         : in     vl_logic_vector(1 downto 0);
        clk             : in     vl_logic;
        in_port         : in     vl_logic_vector(15 downto 0);
        reset_n         : in     vl_logic;
        readdata        : out    vl_logic_vector(31 downto 0)
    );
end cpu_ASK2_pio_SDO_ADC;
