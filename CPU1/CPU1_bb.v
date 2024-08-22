
module CPU1 (
	buzzer_export,
	clk_clk,
	key_1_export,
	key_2_export,
	key_3_export,
	leds_export,
	reset_reset_n,
	seven_seg_0_export,
	seven_seg_1_export,
	seven_seg_2_export,
	seven_seg_3_export,
	seven_seg_4_export,
	seven_seg_5_export,
	sw_rst_export);	

	output		buzzer_export;
	input		clk_clk;
	input		key_1_export;
	input		key_2_export;
	input		key_3_export;
	output	[9:0]	leds_export;
	input		reset_reset_n;
	output	[6:0]	seven_seg_0_export;
	output	[6:0]	seven_seg_1_export;
	output	[6:0]	seven_seg_2_export;
	output	[6:0]	seven_seg_3_export;
	output	[6:0]	seven_seg_4_export;
	output	[6:0]	seven_seg_5_export;
	input		sw_rst_export;
endmodule
