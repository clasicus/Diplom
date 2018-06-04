library verilog;
use verilog.vl_types.all;
entity AD7687 is
    generic(
        S0              : vl_logic_vector(0 to 2) := (Hi0, Hi0, Hi0);
        S1              : vl_logic_vector(0 to 2) := (Hi0, Hi0, Hi1);
        S2              : vl_logic_vector(0 to 2) := (Hi0, Hi1, Hi0);
        S3              : vl_logic_vector(0 to 2) := (Hi0, Hi1, Hi1);
        S4              : vl_logic_vector(0 to 2) := (Hi1, Hi0, Hi0);
        S5              : vl_logic_vector(0 to 2) := (Hi1, Hi0, Hi1);
        S6              : vl_logic_vector(0 to 2) := (Hi1, Hi1, Hi0)
    );
    port(
        RESET           : in     vl_logic;
        CLK             : in     vl_logic;
        DATA_IN         : in     vl_logic;
        CNV             : out    vl_logic;
        SCK             : out    vl_logic;
        ST              : out    vl_logic_vector(4 downto 0);
        SHIFT_REG_REC   : out    vl_logic_vector(15 downto 0);
        DATA_OUT_ADC    : out    vl_logic_vector(15 downto 0)
    );
    attribute mti_svvh_generic_type : integer;
    attribute mti_svvh_generic_type of S0 : constant is 1;
    attribute mti_svvh_generic_type of S1 : constant is 1;
    attribute mti_svvh_generic_type of S2 : constant is 1;
    attribute mti_svvh_generic_type of S3 : constant is 1;
    attribute mti_svvh_generic_type of S4 : constant is 1;
    attribute mti_svvh_generic_type of S5 : constant is 1;
    attribute mti_svvh_generic_type of S6 : constant is 1;
end AD7687;
