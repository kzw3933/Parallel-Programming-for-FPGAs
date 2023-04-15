// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __cordic_cordic_phabkb_H__
#define __cordic_cordic_phabkb_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct cordic_cordic_phabkb_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 11;
  static const unsigned AddressRange = 16;
  static const unsigned AddressWidth = 4;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(cordic_cordic_phabkb_ram) {
        ram[0] = "0b01000000000";
        ram[1] = "0b10100100001";
        ram[2] = "0b10000010010";
        ram[3] = "0b11001000000";
        ram[4] = "0b11100100110";
        ram[5] = "0b01110010011";
        ram[6] = "0b00111001010";
        ram[7] = "0b00011100101";
        ram[8] = "0b00001110010";
        ram[9] = "0b00000111001";
        ram[10] = "0b00000011100";
        ram[11] = "0b00000001110";
        ram[12] = "0b00000000111";
        ram[13] = "0b00000000011";
        ram[14] = "0b00000000010";
        ram[15] = "0b00000000001";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(cordic_cordic_phabkb) {


static const unsigned DataWidth = 11;
static const unsigned AddressRange = 16;
static const unsigned AddressWidth = 4;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


cordic_cordic_phabkb_ram* meminst;


SC_CTOR(cordic_cordic_phabkb) {
meminst = new cordic_cordic_phabkb_ram("cordic_cordic_phabkb_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~cordic_cordic_phabkb() {
    delete meminst;
}


};//endmodule
#endif
