library verilog;
use verilog.vl_types.all;
entity cpu_ASK2_sysid_qsys_0 is
    port(
        address         : in     vl_logic;
        clock           : in     vl_logic;
        reset_n         : in     vl_logic;
        readdata        : out    vl_logic_vector(31 downto 0)
    );
end cpu_ASK2_sysid_qsys_0;