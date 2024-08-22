module CPU3 (
		input  logic       clk,
								 rst_n,
		input  logic       key1,       //       key_1.export
		input  logic       key2,       //       key_2.export
		input  logic       key3,       //       key_3.export
		output logic [9:0] leds,        //        leds.export
		output logic [6:0] sev_seg0, // seven_seg_0.export
		output logic [6:0] sev_seg1, // seven_seg_1.export
		output logic [6:0] sev_seg2, // seven_seg_2.export
		output logic [6:0] sev_seg3, // seven_seg_3.export
		output logic [6:0] sev_seg4, // seven_seg_4.export
		output logic [6:0] sev_seg5,  // seven_seg_5.export
		output logic buzzer,
		input logic sw_rst
	);

        cpu1 cpu
        (
            .clk_clk(clk),            //         clk.clk
            .key_1_export(key1),       //       key_1.export
            .key_2_export(key2),       //       key_2.export
            .key_3_export(key3),       //       key_3.export
            .leds_export(leds),        //        leds.export
            .reset_reset_n(rst_n),      //       reset.reset_n
            .seven_seg_0_export(sev_seg0),//seven_seg_0.export
            .seven_seg_1_export(sev_seg1), // seven_seg_1.export
            .seven_seg_2_export(sev_seg2), // seven_seg_2.export
            .seven_seg_3_export(sev_seg3), // seven_seg_3.export
            .seven_seg_4_export(sev_seg4), // seven_seg_4.export
            .seven_seg_5_export(sev_seg5), // seven_seg_5.export
            .buzzer_export(buzzer),
            .sw_rst_export(sw_rst)
        );
	endmodule
