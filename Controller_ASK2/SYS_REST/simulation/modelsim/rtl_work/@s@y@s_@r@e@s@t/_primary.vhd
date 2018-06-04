library verilog;
use verilog.vl_types.all;
entity SYS_REST is
    port(
        CLK_IN          : in     vl_logic;
        MASTER_OK       : in     vl_logic;
        REST_master     : out    vl_logic;
        REST_slave      : out    vl_logic
    );
end SYS_REST;
