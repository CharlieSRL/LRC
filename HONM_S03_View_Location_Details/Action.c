//   *****************************************************************************************************************************************
//   ****   PLEASE NOTE: This is a READ-ONLY representation of the actual script. For editing please press the "Develop Script" button.   ****
//   *****************************************************************************************************************************************

Action()
{
	lr_start_transaction("S03_T01_Load_Login_Page");
	truclient_step("1", "Navigate to URL", "snapshot=Action_1.inf");
	lr_end_transaction("S03_T01_Load_Login_Page",0);
	truclient_step("2", "Type USERNAME in Username textbox", "snapshot=Action_2.inf");
	truclient_step("3", "Type ******** in Password passwordbox", "snapshot=Action_3.inf");
	truclient_step("4", "Wait WAIT seconds", "snapshot=Action_4.inf");
	lr_start_transaction("S03_T02_Login");
	truclient_step("6", "Click on Login button", "snapshot=Action_6.inf");
	truclient_step("7", "Wait until User Icon image exists", "snapshot=Action_7.inf");
	lr_end_transaction("S03_T02_Login",0);
	truclient_step("8", "Wait WAIT seconds", "snapshot=Action_8.inf");
	truclient_step("11", "Click on Search textbox", "snapshot=Action_11.inf");
	truclient_step("12", "Type LOCATIONID in Search textbox", "snapshot=Action_12.inf");
	lr_start_transaction("S03_T03_Global_Search_Locations");
	truclient_step("13", "Click on Advance Search Dropdown - Locations", "snapshot=Action_13.inf");
	truclient_step("14", "Wait until Customer Location ID / + exists", "snapshot=Action_14.inf");
	lr_end_transaction("S03_T03_Global_Search_Locations",0);
	truclient_step("15", "Wait WAIT seconds", "snapshot=Action_15.inf");
	lr_start_transaction("S03_T04_Open_Location_Details");
	truclient_step("16", "Click on Customer Location ID...", "snapshot=Action_16.inf");
	truclient_step("17", "Wait 10 seconds", "snapshot=Action_17.inf");
	truclient_step("18", "Wait until Location Operational Status header exists", "snapshot=Action_18.inf");
	lr_end_transaction("S03_T04_Open_Location_Details",0);
	truclient_step("19", "Wait WAIT seconds", "snapshot=Action_19.inf");
	lr_start_transaction("S03_T05_Location_Details_Open_Alerts");
	truclient_step("20", "Click on Alerts button", "snapshot=Action_20.inf");
	truclient_step("21", "Wait until Page 1 of 1 or No records found exists", "snapshot=Action_21.inf");
	lr_end_transaction("S03_T05_Location_Details_Open_Alerts",0);
	truclient_step("22", "Wait WAIT seconds", "snapshot=Action_22.inf");
	lr_start_transaction("S03_T06_Back_To_Location_Details");
	truclient_step("23", "Click on Back button", "snapshot=Action_23.inf");
	truclient_step("24", "Wait until Location Operational Status header exists", "snapshot=Action_24.inf");
	lr_end_transaction("S03_T06_Back_To_Location_Details",0);
	truclient_step("25", "Wait WAIT seconds", "snapshot=Action_25.inf");
	lr_start_transaction("S03_T07_Location_Details_Open_Cases");
	truclient_step("26", "Click on Cases button", "snapshot=Action_26.inf");
	truclient_step("27", "Wait until Total Records exists", "snapshot=Action_27.inf");
	lr_end_transaction("S03_T07_Location_Details_Open_Cases",0);
	truclient_step("28", "Wait WAIT seconds", "snapshot=Action_28.inf");
	lr_start_transaction("S03_T08_Back_To_Location_Details");
	truclient_step("29", "Click on Back button", "snapshot=Action_29.inf");
	truclient_step("30", "Wait until Location Operational Status header exists", "snapshot=Action_30.inf");
	lr_end_transaction("S03_T08_Back_To_Location_Details",0);
	truclient_step("31", "Wait WAIT seconds", "snapshot=Action_31.inf");
	lr_start_transaction("S03_T09_Location_Details_Open_Installs");
	truclient_step("32", "Click on Installs button", "snapshot=Action_32.inf");
	truclient_step("33", "Wait until Master FSO# columnheader exists", "snapshot=Action_33.inf");
	lr_end_transaction("S03_T09_Location_Details_Open_Installs",0);
	truclient_step("34", "Wait WAIT seconds", "snapshot=Action_34.inf");
	lr_start_transaction("S03_T10_Back_To_Location_Details");
	truclient_step("35", "Click on Back button", "snapshot=Action_35.inf");
	truclient_step("36", "Wait until Location Operational Status header exists", "snapshot=Action_36.inf");
	lr_end_transaction("S03_T10_Back_To_Location_Details",0);
	truclient_step("37", "Wait WAIT seconds", "snapshot=Action_37.inf");
	lr_start_transaction("S03_T11_Back_To_Locations_Search_Results");
	truclient_step("38", "Click on Back button", "snapshot=Action_38.inf");
	truclient_step("39", "Wait until Customer Location ID / + exists", "snapshot=Action_39.inf");
	lr_end_transaction("S03_T11_Back_To_Locations_Search_Results",0);
	truclient_step("40", "Wait WAIT seconds", "snapshot=Action_40.inf");
	truclient_step("41", "Click on User Icon image", "snapshot=Action_41.inf");
	lr_start_transaction("S03_T12_Logout");
	truclient_step("42", "Click on Logout", "snapshot=Action_42.inf");
	truclient_step("43", "Wait until Login button exists", "snapshot=Action_43.inf");
	lr_end_transaction("S03_T12_Logout",0);

	return 0;
}
