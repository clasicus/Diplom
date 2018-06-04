library verilog;
use verilog.vl_types.all;
entity pwm_ver is
    port(
        i_clk           : in     vl_logic;
        RESET           : in     vl_logic;
        Pwm_in          : in     vl_logic_vector(11 downto 0);
        I_max           : in     vl_logic_vector(15 downto 0);
        I_in            : in     vl_logic_vector(15 downto 0);
        PWM_out         : out    vl_logic;
        Count           : out    vl_logic_vector(10 downto 0);
        DIR             : out    vl_logic;
        OFF             : out    vl_logic
    );
end pwm_ver;
