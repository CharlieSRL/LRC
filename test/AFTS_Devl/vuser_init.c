//#define BUFFER_SIZE 10000 
//
//char buffer[BUFFER_SIZE];

vuser_init()
{
	    	
	 int web_cache_cleanup( );
	 char *command_py = lr_eval_string("{CmdLineCmd}");
	 char *LRC_NUID = lr_eval_string("{LRC_NUID_SecretName}");
	 char *LRC_Client_Secret = lr_eval_string("{LRC_Client_SecretName}");
	 
	 char *App_NUID = lr_eval_string("{App_NUID_SecretName}");
	 char *App_Client_Secret = lr_eval_string("{App_Client_SecretName}");
 
     HostName = lr_get_host_name(); 
	  

    
    
     lr_save_string(HostName, "hostaname_val");
 
	
//	if ((strstr(lr_eval_string("{HostName}"), "GU6")) || (stricmp(HostName, "WAZP-PGENS31284") == 0))
	
	if ((strstr(lr_eval_string("{hostaname_val}"), "gu6")))


	  {
	 
	  lr_output_message("HostName is %s", HostName);
	  lr_output_message("IF Condition for LRC");
	 	
	  sprintf(command_password, "%s %s", command_py, LRC_NUID);
	  
	  sprintf(command_CS, "%s %s", command_py, LRC_Client_Secret);

	  
	 
	  lr_save_string(lr_eval_string("{LRC_Client_ID}"), "client_ID");
	  lr_save_string(lr_eval_string("{LRC_UserName}"), "userName");
     
      TE_UsrCredMgr_Password();
     
      web_cache_cleanup();
     
      TE_UsrCredMgr_CS();
      
       web_cache_cleanup();
	 
	 }
	 else
	 {
	
   	  lr_output_message("HostName is %s", HostName);
   	  lr_output_message("ELSE Condition for App");
	  	
	  sprintf(command_password, "%s %s", command_py, App_NUID);
	 
	  sprintf(command_CS, "%s %s", command_py, App_Client_Secret);

	  
	  lr_save_string(lr_eval_string("{App_Client_ID}"), "client_ID");
	  lr_save_string(lr_eval_string("{App_UserName}"), "userName");

     
      TE_UsrCredMgr_Password();
     
      web_cache_cleanup();
     
      TE_UsrCredMgr_CS();
      
       web_cache_cleanup();
      
     }
	
	 return 0;
}
