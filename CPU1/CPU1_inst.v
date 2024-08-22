	module CPU1_inst (input clk, reset, key_1, key_2, key_3, rst,
	output [9:0] leds, output [6:0] sev_seg_0, output [6:0] sev_seg_1, output[6:0] sev_seg_2,
	output[6:0] sev_seg_3, output[6:0] sev_seg_4, output[6:0] sev_seg_5, output buzz);

	CPU1 u0 (
		.clk_clk            (clk),            //         clk.clk
		.key_1_export       (key_1),       //       key_1.export
		.key_2_export       (key_2),       //       key_2.export
		.key_3_export       (key_3),       //       key_3.export
		.leds_export        (leds),        //        leds.export
		.reset_reset_n      (reset),      //       reset.reset_n
		.seven_seg_0_export (sev_seg_0), // seven_seg_0.export
		.seven_seg_1_export (sev_seg_1), // seven_seg_1.export
		.seven_seg_2_export (sev_seg_2), // seven_seg_2.export
		.seven_seg_3_export (sev_seg_3), // seven_seg_3.export
		.seven_seg_4_export (sev_seg_4), // seven_seg_4.export
		.seven_seg_5_export (sev_seg_5), // seven_seg_5.export
		.buzzer_export      (buzz),       //      buzzer.export
		.sw_rst_export		  (rst)
	);
	endmodule
