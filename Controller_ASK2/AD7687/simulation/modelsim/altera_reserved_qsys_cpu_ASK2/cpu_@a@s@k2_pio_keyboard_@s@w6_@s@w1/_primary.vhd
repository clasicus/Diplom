library verilog;
use verilog.vl_types.all;
entity cpu_ASK2_pio_keyboard_SW6_SW1 is
    port(
        address         : in     vl_logic_vector(1 downto 0);
        clk             : in     vl_logic;
        in_port         : in     vl_logic_vector(5 downto 0);
        reset_n         : in     vl_logic;
        readdata        : out    vl_logic_vector(31 downto 0)
    );
end cpu_ASK2_pio_keyboard_SW6_SW1;
