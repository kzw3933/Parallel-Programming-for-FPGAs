-- ==============================================================
-- RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
-- Version: 2022.2
-- Copyright (C) Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity fir_fir_Pipeline_Shift_Accum_Loop is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    mul : IN STD_LOGIC_VECTOR (31 downto 0);
    x : IN STD_LOGIC_VECTOR (31 downto 0);
    acc_out : OUT STD_LOGIC_VECTOR (31 downto 0);
    acc_out_ap_vld : OUT STD_LOGIC );
end;


architecture behav of fir_fir_Pipeline_Shift_Accum_Loop is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_pp0_stage0 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_boolean_0 : BOOLEAN := false;
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv5_A : STD_LOGIC_VECTOR (4 downto 0) := "01010";
    constant ap_const_lv4_0 : STD_LOGIC_VECTOR (3 downto 0) := "0000";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv5_0 : STD_LOGIC_VECTOR (4 downto 0) := "00000";
    constant ap_const_lv4_F : STD_LOGIC_VECTOR (3 downto 0) := "1111";
    constant ap_const_lv5_1F : STD_LOGIC_VECTOR (4 downto 0) := "11111";

attribute shreg_extract : string;
    signal ap_CS_fsm : STD_LOGIC_VECTOR (0 downto 0) := "1";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_pp0_stage0 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_pp0_stage0 : signal is "none";
    signal ap_enable_reg_pp0_iter0 : STD_LOGIC;
    signal ap_enable_reg_pp0_iter1 : STD_LOGIC := '0';
    signal ap_idle_pp0 : STD_LOGIC;
    signal ap_block_state1_pp0_stage0_iter0 : BOOLEAN;
    signal ap_block_state2_pp0_stage0_iter1 : BOOLEAN;
    signal ap_block_pp0_stage0_subdone : BOOLEAN;
    signal tmp_fu_138_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_condition_exit_pp0_iter0_stage0 : STD_LOGIC;
    signal ap_loop_exit_ready : STD_LOGIC;
    signal ap_ready_int : STD_LOGIC;
    signal shift_reg_address0 : STD_LOGIC_VECTOR (3 downto 0);
    signal shift_reg_ce0 : STD_LOGIC;
    signal shift_reg_we0 : STD_LOGIC;
    signal shift_reg_address1 : STD_LOGIC_VECTOR (3 downto 0);
    signal shift_reg_ce1 : STD_LOGIC;
    signal shift_reg_we1 : STD_LOGIC;
    signal shift_reg_q1 : STD_LOGIC_VECTOR (31 downto 0);
    signal fir_int_int_c_address0 : STD_LOGIC_VECTOR (3 downto 0);
    signal fir_int_int_c_ce0 : STD_LOGIC;
    signal fir_int_int_c_q0 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_block_pp0_stage0_11001 : BOOLEAN;
    signal tmp_reg_228 : STD_LOGIC_VECTOR (0 downto 0);
    signal i_cast1_fu_146_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal i_cast1_reg_232 : STD_LOGIC_VECTOR (63 downto 0);
    signal icmp_ln13_fu_155_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln13_reg_237 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_phi_mux_mul_pn_phi_fu_119_p4 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_phi_reg_pp0_iter0_mul_pn_reg_116 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_phi_reg_pp0_iter1_mul_pn_reg_116 : STD_LOGIC_VECTOR (31 downto 0);
    signal mul_ln18_fu_183_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal zext_ln17_fu_167_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_block_pp0_stage0 : BOOLEAN;
    signal acc_fu_48 : STD_LOGIC_VECTOR (31 downto 0);
    signal acc_1_fu_193_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_loop_init : STD_LOGIC;
    signal i_fu_52 : STD_LOGIC_VECTOR (4 downto 0);
    signal add_ln12_fu_172_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal ap_sig_allocacmp_i_1 : STD_LOGIC_VECTOR (4 downto 0);
    signal ap_block_pp0_stage0_01001 : BOOLEAN;
    signal empty_6_fu_151_p1 : STD_LOGIC_VECTOR (3 downto 0);
    signal add_ln17_fu_161_p2 : STD_LOGIC_VECTOR (3 downto 0);
    signal mul_ln18_fu_183_p0 : STD_LOGIC_VECTOR (10 downto 0);
    signal ap_done_reg : STD_LOGIC := '0';
    signal ap_continue_int : STD_LOGIC;
    signal ap_done_int : STD_LOGIC;
    signal ap_NS_fsm : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_enable_pp0 : STD_LOGIC;
    signal ap_start_int : STD_LOGIC;
    signal ap_condition_98 : BOOLEAN;
    signal ap_condition_221 : BOOLEAN;
    signal ap_ce_reg : STD_LOGIC;

    component fir_mul_11s_32s_32_1_1 IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        din0 : IN STD_LOGIC_VECTOR (10 downto 0);
        din1 : IN STD_LOGIC_VECTOR (31 downto 0);
        dout : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;


    component fir_fir_Pipeline_Shift_Accum_Loop_shift_reg_RAM_AUTO_1R1W IS
    generic (
        DataWidth : INTEGER;
        AddressRange : INTEGER;
        AddressWidth : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR (3 downto 0);
        ce0 : IN STD_LOGIC;
        we0 : IN STD_LOGIC;
        d0 : IN STD_LOGIC_VECTOR (31 downto 0);
        address1 : IN STD_LOGIC_VECTOR (3 downto 0);
        ce1 : IN STD_LOGIC;
        we1 : IN STD_LOGIC;
        d1 : IN STD_LOGIC_VECTOR (31 downto 0);
        q1 : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;


    component fir_fir_Pipeline_Shift_Accum_Loop_fir_int_int_c_ROM_AUTO_1R IS
    generic (
        DataWidth : INTEGER;
        AddressRange : INTEGER;
        AddressWidth : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR (3 downto 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;


    component fir_flow_control_loop_pipe_sequential_init IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_start_int : OUT STD_LOGIC;
        ap_loop_init : OUT STD_LOGIC;
        ap_ready_int : IN STD_LOGIC;
        ap_loop_exit_ready : IN STD_LOGIC;
        ap_loop_exit_done : IN STD_LOGIC;
        ap_continue_int : OUT STD_LOGIC;
        ap_done_int : IN STD_LOGIC );
    end component;



begin
    shift_reg_U : component fir_fir_Pipeline_Shift_Accum_Loop_shift_reg_RAM_AUTO_1R1W
    generic map (
        DataWidth => 32,
        AddressRange => 11,
        AddressWidth => 4)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        address0 => shift_reg_address0,
        ce0 => shift_reg_ce0,
        we0 => shift_reg_we0,
        d0 => shift_reg_q1,
        address1 => shift_reg_address1,
        ce1 => shift_reg_ce1,
        we1 => shift_reg_we1,
        d1 => x,
        q1 => shift_reg_q1);

    fir_int_int_c_U : component fir_fir_Pipeline_Shift_Accum_Loop_fir_int_int_c_ROM_AUTO_1R
    generic map (
        DataWidth => 32,
        AddressRange => 11,
        AddressWidth => 4)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        address0 => fir_int_int_c_address0,
        ce0 => fir_int_int_c_ce0,
        q0 => fir_int_int_c_q0);

    mul_11s_32s_32_1_1_U1 : component fir_mul_11s_32s_32_1_1
    generic map (
        ID => 1,
        NUM_STAGE => 1,
        din0_WIDTH => 11,
        din1_WIDTH => 32,
        dout_WIDTH => 32)
    port map (
        din0 => mul_ln18_fu_183_p0,
        din1 => shift_reg_q1,
        dout => mul_ln18_fu_183_p2);

    flow_control_loop_pipe_sequential_init_U : component fir_flow_control_loop_pipe_sequential_init
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => ap_start,
        ap_ready => ap_ready,
        ap_done => ap_done,
        ap_start_int => ap_start_int,
        ap_loop_init => ap_loop_init,
        ap_ready_int => ap_ready_int,
        ap_loop_exit_ready => ap_condition_exit_pp0_iter0_stage0,
        ap_loop_exit_done => ap_done_int,
        ap_continue_int => ap_continue_int,
        ap_done_int => ap_done_int);





    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_pp0_stage0;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    ap_done_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_done_reg <= ap_const_logic_0;
            else
                if ((ap_continue_int = ap_const_logic_1)) then 
                    ap_done_reg <= ap_const_logic_0;
                elsif (((ap_loop_exit_ready = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
                    ap_done_reg <= ap_const_logic_1;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter1_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter1 <= ap_const_logic_0;
            else
                if ((ap_const_logic_1 = ap_condition_exit_pp0_iter0_stage0)) then 
                    ap_enable_reg_pp0_iter1 <= ap_const_logic_0;
                elsif (((ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
                    ap_enable_reg_pp0_iter1 <= ap_start_int;
                end if; 
            end if;
        end if;
    end process;


    acc_fu_48_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
                if ((ap_loop_init = ap_const_logic_1)) then 
                    acc_fu_48 <= ap_const_lv32_0;
                elsif ((ap_enable_reg_pp0_iter1 = ap_const_logic_1)) then 
                    acc_fu_48 <= acc_1_fu_193_p2;
                end if;
            end if; 
        end if;
    end process;

    ap_phi_reg_pp0_iter1_mul_pn_reg_116_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_boolean_1 = ap_condition_98)) then
                if (((icmp_ln13_fu_155_p2 = ap_const_lv1_1) and (tmp_fu_138_p3 = ap_const_lv1_0))) then 
                    ap_phi_reg_pp0_iter1_mul_pn_reg_116 <= mul;
                elsif ((ap_const_boolean_1 = ap_const_boolean_1)) then 
                    ap_phi_reg_pp0_iter1_mul_pn_reg_116 <= ap_phi_reg_pp0_iter0_mul_pn_reg_116;
                end if;
            end if; 
        end if;
    end process;

    i_fu_52_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
                if (((tmp_fu_138_p3 = ap_const_lv1_0) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1))) then 
                    i_fu_52 <= add_ln12_fu_172_p2;
                elsif ((ap_loop_init = ap_const_logic_1)) then 
                    i_fu_52 <= ap_const_lv5_A;
                end if;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((tmp_fu_138_p3 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
                    i_cast1_reg_232(4 downto 0) <= i_cast1_fu_146_p1(4 downto 0);
                icmp_ln13_reg_237 <= icmp_ln13_fu_155_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
                tmp_reg_228 <= ap_sig_allocacmp_i_1(4 downto 4);
            end if;
        end if;
    end process;
    i_cast1_reg_232(63 downto 5) <= "00000000000000000000000000000000000000000000000000000000000";

    ap_NS_fsm_assign_proc : process (ap_CS_fsm)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_pp0_stage0 => 
                ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
            when others =>  
                ap_NS_fsm <= "X";
        end case;
    end process;
    acc_1_fu_193_p2 <= std_logic_vector(unsigned(ap_phi_mux_mul_pn_phi_fu_119_p4) + unsigned(acc_fu_48));
    acc_out <= acc_fu_48;

    acc_out_ap_vld_assign_proc : process(ap_CS_fsm_pp0_stage0, tmp_fu_138_p3, ap_block_pp0_stage0_11001)
    begin
        if (((tmp_fu_138_p3 = ap_const_lv1_1) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            acc_out_ap_vld <= ap_const_logic_1;
        else 
            acc_out_ap_vld <= ap_const_logic_0;
        end if; 
    end process;

    add_ln12_fu_172_p2 <= std_logic_vector(unsigned(ap_sig_allocacmp_i_1) + unsigned(ap_const_lv5_1F));
    add_ln17_fu_161_p2 <= std_logic_vector(unsigned(empty_6_fu_151_p1) + unsigned(ap_const_lv4_F));
    ap_CS_fsm_pp0_stage0 <= ap_CS_fsm(0);
        ap_block_pp0_stage0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_01001 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_11001 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_subdone <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state1_pp0_stage0_iter0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state2_pp0_stage0_iter1 <= not((ap_const_boolean_1 = ap_const_boolean_1));

    ap_condition_221_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter0, tmp_fu_138_p3, ap_block_pp0_stage0)
    begin
                ap_condition_221 <= ((tmp_fu_138_p3 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage0) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0));
    end process;


    ap_condition_98_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter0, ap_block_pp0_stage0_11001)
    begin
                ap_condition_98 <= ((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0));
    end process;


    ap_condition_exit_pp0_iter0_stage0_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter0, ap_block_pp0_stage0_subdone, tmp_fu_138_p3)
    begin
        if (((tmp_fu_138_p3 = ap_const_lv1_1) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            ap_condition_exit_pp0_iter0_stage0 <= ap_const_logic_1;
        else 
            ap_condition_exit_pp0_iter0_stage0 <= ap_const_logic_0;
        end if; 
    end process;


    ap_done_int_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_block_pp0_stage0_subdone, ap_loop_exit_ready, ap_done_reg)
    begin
        if (((ap_loop_exit_ready = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            ap_done_int <= ap_const_logic_1;
        else 
            ap_done_int <= ap_done_reg;
        end if; 
    end process;

    ap_enable_pp0 <= (ap_idle_pp0 xor ap_const_logic_1);
    ap_enable_reg_pp0_iter0 <= ap_start_int;

    ap_idle_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_idle_pp0, ap_start_int)
    begin
        if (((ap_idle_pp0 = ap_const_logic_1) and (ap_start_int = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_pp0_assign_proc : process(ap_enable_reg_pp0_iter0, ap_enable_reg_pp0_iter1)
    begin
        if (((ap_enable_reg_pp0_iter1 = ap_const_logic_0) and (ap_enable_reg_pp0_iter0 = ap_const_logic_0))) then 
            ap_idle_pp0 <= ap_const_logic_1;
        else 
            ap_idle_pp0 <= ap_const_logic_0;
        end if; 
    end process;

    ap_loop_exit_ready <= ap_condition_exit_pp0_iter0_stage0;

    ap_phi_mux_mul_pn_phi_fu_119_p4_assign_proc : process(tmp_reg_228, icmp_ln13_reg_237, ap_phi_reg_pp0_iter1_mul_pn_reg_116, mul_ln18_fu_183_p2)
    begin
        if (((icmp_ln13_reg_237 = ap_const_lv1_0) and (tmp_reg_228 = ap_const_lv1_0))) then 
            ap_phi_mux_mul_pn_phi_fu_119_p4 <= mul_ln18_fu_183_p2;
        else 
            ap_phi_mux_mul_pn_phi_fu_119_p4 <= ap_phi_reg_pp0_iter1_mul_pn_reg_116;
        end if; 
    end process;

    ap_phi_reg_pp0_iter0_mul_pn_reg_116 <= "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

    ap_ready_int_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter0, ap_block_pp0_stage0_subdone)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            ap_ready_int <= ap_const_logic_1;
        else 
            ap_ready_int <= ap_const_logic_0;
        end if; 
    end process;


    ap_sig_allocacmp_i_1_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_block_pp0_stage0, ap_loop_init, i_fu_52)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_init = ap_const_logic_1))) then 
            ap_sig_allocacmp_i_1 <= ap_const_lv5_A;
        else 
            ap_sig_allocacmp_i_1 <= i_fu_52;
        end if; 
    end process;

    empty_6_fu_151_p1 <= ap_sig_allocacmp_i_1(4 - 1 downto 0);
    fir_int_int_c_address0 <= i_cast1_fu_146_p1(4 - 1 downto 0);

    fir_int_int_c_ce0_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter0, ap_block_pp0_stage0_11001)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            fir_int_int_c_ce0 <= ap_const_logic_1;
        else 
            fir_int_int_c_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    i_cast1_fu_146_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(ap_sig_allocacmp_i_1),64));
    icmp_ln13_fu_155_p2 <= "1" when (ap_sig_allocacmp_i_1 = ap_const_lv5_0) else "0";
    mul_ln18_fu_183_p0 <= fir_int_int_c_q0(11 - 1 downto 0);
    shift_reg_address0 <= i_cast1_reg_232(4 - 1 downto 0);

    shift_reg_address1_assign_proc : process(icmp_ln13_fu_155_p2, zext_ln17_fu_167_p1, ap_condition_221)
    begin
        if ((ap_const_boolean_1 = ap_condition_221)) then
            if ((icmp_ln13_fu_155_p2 = ap_const_lv1_1)) then 
                shift_reg_address1 <= ap_const_lv4_0;
            elsif ((icmp_ln13_fu_155_p2 = ap_const_lv1_0)) then 
                shift_reg_address1 <= zext_ln17_fu_167_p1(4 - 1 downto 0);
            else 
                shift_reg_address1 <= "XXXX";
            end if;
        else 
            shift_reg_address1 <= "XXXX";
        end if; 
    end process;


    shift_reg_ce0_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter1, ap_block_pp0_stage0_11001)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            shift_reg_ce0 <= ap_const_logic_1;
        else 
            shift_reg_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    shift_reg_ce1_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter0, tmp_fu_138_p3, ap_block_pp0_stage0_11001, icmp_ln13_fu_155_p2)
    begin
        if ((((icmp_ln13_fu_155_p2 = ap_const_lv1_1) and (tmp_fu_138_p3 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0)) or ((icmp_ln13_fu_155_p2 = ap_const_lv1_0) and (tmp_fu_138_p3 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0)))) then 
            shift_reg_ce1 <= ap_const_logic_1;
        else 
            shift_reg_ce1 <= ap_const_logic_0;
        end if; 
    end process;


    shift_reg_we0_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter1, ap_block_pp0_stage0_11001, tmp_reg_228, icmp_ln13_reg_237)
    begin
        if (((icmp_ln13_reg_237 = ap_const_lv1_0) and (tmp_reg_228 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            shift_reg_we0 <= ap_const_logic_1;
        else 
            shift_reg_we0 <= ap_const_logic_0;
        end if; 
    end process;


    shift_reg_we1_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter0, tmp_fu_138_p3, ap_block_pp0_stage0_11001, icmp_ln13_fu_155_p2)
    begin
        if (((icmp_ln13_fu_155_p2 = ap_const_lv1_1) and (tmp_fu_138_p3 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            shift_reg_we1 <= ap_const_logic_1;
        else 
            shift_reg_we1 <= ap_const_logic_0;
        end if; 
    end process;

    tmp_fu_138_p3 <= ap_sig_allocacmp_i_1(4 downto 4);
    zext_ln17_fu_167_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(add_ln17_fu_161_p2),64));
end behav;