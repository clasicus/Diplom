library verilog;
use verilog.vl_types.all;
entity REST_Global is
    port(
        CLK_IN          : in     vl_logic;
        PLL_OK          : in     vl_logic;
        n_RESET         : out    vl_logic
    );
end REST_Global;
