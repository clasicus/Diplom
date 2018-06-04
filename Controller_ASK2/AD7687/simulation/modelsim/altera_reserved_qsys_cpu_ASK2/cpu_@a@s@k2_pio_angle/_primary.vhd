library verilog;
use verilog.vl_types.all;
entity cpu_ASK2_pio_angle is
    port(
        address         : in     vl_logic_vector(1 downto 0);
        chipselect      : in     vl_logic;
        clk             : in     vl_logic;
        reset_n         : in     vl_logic;
        write_n         : in     vl_logic;
        writedata       : in     vl_logic_vector(31 downto 0);
        bidir_port      : inout  vl_logic_vector(15 downto 0);
        readdata        : out    vl_logic_vector(31 downto 0)
    );
end cpu_ASK2_pio_angle;
