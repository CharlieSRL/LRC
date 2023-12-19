#define BUFFER_SIZE 10000 

char buffer[BUFFER_SIZE];
#ifndef _GLOBALS_H
#define _GLOBALS_H

//--------------------------------------------------------------------
// Include Files
#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"

//--------------------------------------------------------------------
// Global Variables
// char *client_ID[64];
// char *userName[64];

	 char *HostName;

	 char *command_password[64];
	 char *command_CS[64];
	 
	 char *client_ID[64];
	 char *userName[64];
	 
	 
     long fp; // file/stream pointer
     long fp1;
     int count; // number of characters that have been read from the stream.
     char buffer[BUFFER_SIZE]; // allocate memory for the output of the command.
     char * token;
     char * Pwd_output;
     char param_buf[10]; // buffer to hold the parameter name.
     char * CS_output;
     long ls;
	 char buf[1024];
	 
	       double trans_time;
      double log_trans_time;
      double wst_time;
      double rs;
      int find_error_cnt;
      int found_cnt = 0;
      int PaceThink;
      char * starttime;
      char * endtime;
   
  
   log_write_error()
	{
   	char * filename;
	char workfilename[150];
    long file;

    // Create a new file

    sprintf(workfilename,"\\\\fanniemae.com\\corp\\DC\\Shared\\SF\\AUBTTeam\\CDDS Performance Test\\Script Logs\\AFSA_Axway\\%s_CDDS_AFSA_OnCloud_Log_%s.txt",lr_eval_string("{CurrentDate}"),lr_eval_string("{VuserID}"));
    filename=workfilename;
    
    if ((file = fopen(filename, "a" )) == NULL) {

        lr_output_message("Unable to create %s", filename);

        return -1;

    }

    // Write the Vuser ID and group to the log file 
 
	fprintf(file, "Date: %s, Vuser ID: %s, Iteration: %s, Start Time: %s, End Time: %s, TransID: %s\n", 
            lr_eval_string("{CurrentDate}"),lr_eval_string("{VuserID}"), lr_eval_string("{Iteration}"),starttime,endtime,lr_eval_string("{TranID}"));
    
    
    //fprintf(file, "TransID = %s\n",lr_eval_string("{TranID}"));
    	
    fprintf(file, "Response: %s, Response Code: %s, Message: %s\n",      
            lr_eval_string("{response}"), lr_eval_string("{pRespCode}"),lr_eval_string("{message_1}"));

    fprintf(file, "DocFileID: %s, PostalCode: %s, AppAmount: %s, LenderLoan: %s, LenderSeller:%s \n",      
            lr_eval_string("{pDocFileID}"), lr_eval_string("{pPostalCD}"),lr_eval_string("{pAppAmount}"),lr_eval_string("{LenderLoan}"),lr_eval_string("{LenderSeller}"));
    	lr_save_string("","message_1");    	

    fclose(file);
    return 0;
    
   }
     TE_UsrCredMgr_Password()
     {
     	
     	ls = popen(command_password, "r");

while (fgets(buf, sizeof(buf), ls) != 0)
{   
  // save output to a variable and do string manipulations
 // lr_output_message("%s",buf);   
 }

token = (char *)strtok(buf, "\n"); 
//lr_output_message ("value of NUID-secret-0:%s", token );
if (!token) {
        lr_output_message ("No tokens found in string!");
        return( -1 );
    }


/// While valid tokens are returned
    while (token != NULL ) { 
    // lr_output_message ("value of NUID-secret:%s", token );
	// Get the next token
	lr_save_string(token, "Password");
    
// lr_output_message("Password is: %s", lr_eval_string("{Password}"));
        token = (char *)strtok(NULL, "\n"); 
      //  lr_output_message ("value of NUID-secret-1:%s", token );
}
    
    pclose(ls);
    
    return 0;
     }

      TE_UsrCredMgr_CS()
     {
      	   	  lr_output_message("CS command is is %s", command_CS);
ls = popen(command_CS, "r");

while (fgets(buf, sizeof(buf), ls) != 0)
{   
  // save output to a variable and do string manipulations
 // lr_output_message("%s",buf);   
 }

token = (char *)strtok(buf, "\n"); 
//lr_output_message ("value of NUID-secret-0:%s", token );
if (!token) {
        lr_output_message ("No tokens found in string!");
        return( -1 );
    }


/// While valid tokens are returned
    while (token != NULL ) { 
       // lr_output_message ("value of NUID-secret:%s", token );
	// Get the next token
	lr_save_string(token, "ClientSecret");
    
// lr_output_message("ClientSecret is: %s", lr_eval_string("{ClientSecret}"));
        token = (char *)strtok(NULL, "\n"); 
      //  lr_output_message ("value of NUID-secret-1:%s", token );
}
    
    pclose(ls);
    
    return 0;
     }
     
#endif // _GLOBALS_H
