module \$_DFF_P_ (input D, C, output Q); MISTRAL_FF _TECHMAP_REPLACE_(.D(D), .CLK(C), .AC(1'b0), .Q(Q)); endmodule
module \$_DFF_N_ (input D, C, output Q); MISTRAL_FF _TECHMAP_REPLACE_(.D(D), .CLK(~C), .AC(1'b0), .Q(Q)); endmodule
module \$_DFF_PP0_ (input D, C, R, output Q); MISTRAL_FF _TECHMAP_REPLACE_(.D(D), .CLK(C), .AC(R), .Q(Q)); endmodule
module \$_DFF_PP1_ (input D, C, R, output Q); MISTRAL_FF _TECHMAP_REPLACE_(.D(~D), .CLK(C), .AC(R), .Q(~Q)); endmodule

