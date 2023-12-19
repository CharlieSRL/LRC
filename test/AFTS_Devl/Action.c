Action()
{

	double trans_time;
    double think_time;
    int res;
    int File_Size;
    
    lr_start_transaction("Get_Token");
	
	web_set_max_html_param_len("99999");	
	
	web_reg_save_param_ex("Paramname=JWRT","LB=\"refresh_token\":\"","RB=\"","NotFound=warning",LAST);	
	
	web_reg_save_param_ex("Paramname=JWT","LB=\"access_token\":\"","RB=\"","NotFound=warning",LAST);
	
	web_rest("Get Token For AFTS",
			"URL={Token_URL}",
			"Method=POST",
			"EncType=application/x-www-form-urlencoded",
			"Snapshot=t860140.inf",
			ITEMDATA,
	        "Name=client_id", "Value={client_ID}", ENDITEM,
	        "Name=client_secret", "Value={ClientSecret}", ENDITEM,
	        "Name=grant_type", "Value=password", ENDITEM,
	        "Name=username", "Value={userName}", ENDITEM,
	        "Name=password", "Value={Password}", ENDITEM,
			LAST);
	//sleep(1000);
	lr_end_transaction("Get_Token", LR_AUTO);	
	
    lr_think_time(1);

	web_set_sockets_option("SSL_VERSION","TLS1.2");

	web_set_timeout("CONNECT", "180"); 


    web_set_timeout("RECEIVE", "180"); 


	web_set_timeout("STEP", "180"); 

	
	lr_save_datetime("%Y-%m-%d", DATE_NOW + ONE_DAY, "pTimeStamp");	

	//PT-AFTS-4HR-4MB-Cycle3
	
//	Get_Token();
	
	
	web_add_header("x-fnma-api-key","{API_Key}");
	web_add_header("x-fnma-jws-token","{JWT}");	
//	web_add_header("routeTo", "aws2.0");	
	
	lr_start_transaction("AFTS_Peak");
	
//	lr_eval_string("{AFTS_File_Size}");
	
	File_Size = atoi(lr_eval_string("{AFTS_File_Type}"));

	switch (File_Size)
	{
//	if (strcmp(lr_eval_string("{AFTS_File_Size}"),"AFTS_5_5MB") == 0)
		case 5: //AFTS_5_MB
			
			lr_start_transaction("AFTS_5MB");
			
			 soap_request("StepName=SOAP Request",
					  "URL={pURL}", //Intg env
				//	  "URL=https://webservices.acptefanniemae.com/AFTSWebServiceIntg", //Intg env
						"SOAPEnvelope="
				        "<soapenv:Envelope xmlns:soapenv=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:urn=\"urn:www-uniformdataportal-com:ucdp-afts-2013-09\" xmlns:xm=\"http://www.w3.org/2005/05/xmlmime\">"
				"<soapenv:Header>"
				"<urn:AFTSHeader>"
				"<urn:DocumentFileID>{TransID}{VuserID}</urn:DocumentFileID>"
				"<urn:PortalDocumentID>12345</urn:PortalDocumentID>"
				"<urn:SequenceNumber>1</urn:SequenceNumber>"				
				"<urn:TransmissionRequestID>{AFTS_TraxID}{TransRequestID}{VuserID}</urn:TransmissionRequestID>"
				"<urn:Checksum>{AFTS_5_5MB_Checksum}</urn:Checksum>"
				"<urn:PortalSubmissionDateTime>{Sub_DateTime}Z</urn:PortalSubmissionDateTime>"
				"<urn:PortalUpdateDateTime>{Updt_DateTime}Z</urn:PortalUpdateDateTime>"
				"<urn:PortalSentDateTime>{Sent_DateTime}Z</urn:PortalSentDateTime>"
				//"<!--Optional:-->"
				"<urn:DocXPathInfo>/VALUATION_RESPONSE/REPORT/EMBEDDED_FILE/DOCUMENT/text()</urn:DocXPathInfo>"
//				"<urn:DocXPathInfo>/VALUATION_RESPONSE/REPORT/FORM/IMAGE/EMBEDDED_FILE/DOCUMENT/text()</urn:DocXPathInfo>"					
				"</urn:AFTSHeader>"
				"<wsse:Security xmlns:wsse=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\">"
				"<wsu:Timestamp xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">"
				"<wsu:Created>{pTimeStamp}T23:59:01.709Z</wsu:Created>"
				"<wsu:Expires>{pTimeStamp}T23:59:01.709Z</wsu:Expires>"
				"</wsu:Timestamp>"
				"<wsse:UsernameToken wsu:Id=\"UsernameToken-164075274\" xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">"
				"<wsse:Username>{ID}</wsse:Username>"
				"<wsse:Password Type=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-username-token-profile-1.0#PasswordText\">{Password}</wsse:Password>"
				"</wsse:UsernameToken>"
				"</wsse:Security>"
				"</soapenv:Header>"
				"<soapenv:Body>"
				"<urn:DocumentTransferRequest>"
				"<urn:fileContent xm:contentType=\"text/xml\">"
				"{AFTS_5_5MB_Data}"
				"</urn:fileContent>"
				"</urn:DocumentTransferRequest>"
				"</soapenv:Body>"
				"</soapenv:Envelope>",
				"SOAPAction=", 
				"ResponseParam=response", 
				"Snapshot=t1381252214.inf", 
				LAST);
			
			lr_end_transaction("AFTS_5MB", LR_AUTO);
			                   
			break;
		case 6: //AFTS_6_0_MB
//		if (strcmp(lr_eval_string("{AFTS_File_Size}"),"AFTS_6_0MB") == 0)
//	{
			lr_start_transaction("AFTS_6MB");
			
			 soap_request("StepName=SOAP Request",
					  "URL={pURL}", //Intg env
				//	  "URL=https://webservices.acptefanniemae.com/AFTSWebServiceIntg", //Intg env
						"SOAPEnvelope="
				        "<soapenv:Envelope xmlns:soapenv=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:urn=\"urn:www-uniformdataportal-com:ucdp-afts-2013-09\" xmlns:xm=\"http://www.w3.org/2005/05/xmlmime\">"
				"<soapenv:Header>"
				"<urn:AFTSHeader>"
				"<urn:DocumentFileID>{TransID}{VuserID}</urn:DocumentFileID>"
				"<urn:PortalDocumentID>12345</urn:PortalDocumentID>"
				"<urn:SequenceNumber>1</urn:SequenceNumber>"
				"<urn:TransmissionRequestID>{AFTS_TraxID}{TransRequestID}{VuserID}</urn:TransmissionRequestID>"
				"<urn:Checksum>{AFTS_6_0MB_Checksum}</urn:Checksum>"
				"<urn:PortalSubmissionDateTime>{Sub_DateTime}Z</urn:PortalSubmissionDateTime>"
				"<urn:PortalUpdateDateTime>{Updt_DateTime}Z</urn:PortalUpdateDateTime>"
				"<urn:PortalSentDateTime>{Sent_DateTime}Z</urn:PortalSentDateTime>"
				//"<!--Optional:-->"
				"<urn:DocXPathInfo>/VALUATION_RESPONSE/REPORT/EMBEDDED_FILE/DOCUMENT/text()</urn:DocXPathInfo>"				
//				"<urn:DocXPathInfo>/VALUATION_RESPONSE/REPORT/FORM/IMAGE/EMBEDDED_FILE/DOCUMENT/text()</urn:DocXPathInfo>"					
				"</urn:AFTSHeader>"
				"<wsse:Security xmlns:wsse=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\">"
				"<wsu:Timestamp xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">"
				"<wsu:Created>{pTimeStamp}T23:59:01.709Z</wsu:Created>"
				"<wsu:Expires>{pTimeStamp}T23:59:01.709Z</wsu:Expires>"
				"</wsu:Timestamp>"
				"<wsse:UsernameToken wsu:Id=\"UsernameToken-164075274\" xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">"
				"<wsse:Username>{ID}</wsse:Username>"
				"<wsse:Password Type=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-username-token-profile-1.0#PasswordText\">{Password}</wsse:Password>"
				"</wsse:UsernameToken>"
				"</wsse:Security>"
				"</soapenv:Header>"
				"<soapenv:Body>"
				"<urn:DocumentTransferRequest>"
				"<urn:fileContent xm:contentType=\"text/xml\">"
				"{AFTS_6_0MB_Data}"
				"</urn:fileContent>"
				"</urn:DocumentTransferRequest>"
				"</soapenv:Body>"
				"</soapenv:Envelope>",
				"SOAPAction=", 
				       "ResponseParam=response", 
				       "Snapshot=t1381252214.inf", 
				       LAST);
			
			lr_end_transaction("AFTS_6MB", LR_AUTO);
			
			break;

		case 8: //AFTS_8MB
//		if (strcmp(lr_eval_string("{AFTS_File_Size}"),"AFTS_14MB") == 0)
//	{
			
			lr_start_transaction("AFTS_8MB");

			 soap_request("StepName=SOAP Request",
					  "URL={pURL}", //Intg env
//					  "URL=https://api-perf.acptfanniemae.com/soap/singlefamily/originating/cdds-afts-service", //Intg env
						"SOAPEnvelope="
				        "<soapenv:Envelope xmlns:soapenv=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:urn=\"urn:www-uniformdataportal-com:ucdp-afts-2013-09\" xmlns:xm=\"http://www.w3.org/2005/05/xmlmime\">"
				"<soapenv:Header>"
				"<urn:AFTSHeader>"
				"<urn:DocumentFileID>{TransID}{VuserID}</urn:DocumentFileID>"
				"<urn:PortalDocumentID>12345</urn:PortalDocumentID>"
				"<urn:SequenceNumber>1</urn:SequenceNumber>"				
				"<urn:TransmissionRequestID>{AFTS_TraxID}{TransRequestID}{VuserID}</urn:TransmissionRequestID>"
				"<urn:Checksum>{AFTS_8_0MB_Checksum}</urn:Checksum>"
				"<urn:PortalSubmissionDateTime>{Sub_DateTime}Z</urn:PortalSubmissionDateTime>"
				"<urn:PortalUpdateDateTime>{Updt_DateTime}Z</urn:PortalUpdateDateTime>"
				"<urn:PortalSentDateTime>{Sent_DateTime}Z</urn:PortalSentDateTime>"
				//"<!--Optional:-->"
				"<urn:DocXPathInfo>/VALUATION_RESPONSE/REPORT/EMBEDDED_FILE/DOCUMENT/text()</urn:DocXPathInfo>"
//				"<urn:DocXPathInfo>/VALUATION_RESPONSE/REPORT/FORM/IMAGE/EMBEDDED_FILE/DOCUMENT/text()</urn:DocXPathInfo>"					
				"</urn:AFTSHeader>"
				"<wsse:Security xmlns:wsse=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\">"
				"<wsu:Timestamp xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">"
				"<wsu:Created>{pTimeStamp}T23:59:01.709Z</wsu:Created>"
				"<wsu:Expires>{pTimeStamp}T23:59:01.709Z</wsu:Expires>"
				"</wsu:Timestamp>"
				"<wsse:UsernameToken wsu:Id=\"UsernameToken-164075274\" xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">"
				"<wsse:Username>{ID}</wsse:Username>"
				"<wsse:Password Type=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-username-token-profile-1.0#PasswordText\">{Password}</wsse:Password>"
				"</wsse:UsernameToken>"
				"</wsse:Security>"
				"</soapenv:Header>"
				"<soapenv:Body>"
				"<urn:DocumentTransferRequest>"
				"<urn:fileContent xm:contentType=\"text/xml\">"
				"{AFTS_8_0MB_Data}"
				"</urn:fileContent>"
				"</urn:DocumentTransferRequest>"
				"</soapenv:Body>"
				"</soapenv:Envelope>",
				"SOAPAction=", 
				"ResponseParam=response", 
				"Snapshot=t1381252214.inf", 
				LAST);
			
			lr_end_transaction("AFTS_8MB", LR_AUTO);
			
			break;
		case 12: //AFTS_12MB	

			lr_start_transaction("AFTS_12MB");
			
					 soap_request("StepName=SOAP Request",
					  "URL={pURL}", //Intg env
				//	  "URL=https://webservices.acptefanniemae.com/AFTSWebServiceIntg", //Intg env
						"SOAPEnvelope="
				        "<soapenv:Envelope xmlns:soapenv=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:urn=\"urn:www-uniformdataportal-com:ucdp-afts-2013-09\" xmlns:xm=\"http://www.w3.org/2005/05/xmlmime\">"
				"<soapenv:Header>"
				"<urn:AFTSHeader>"
//				"<urn:DocumentFileID>{pDocFile}</urn:DocumentFileID>"				
				"<urn:DocumentFileID>{TransID}{VuserID}</urn:DocumentFileID>"
//  				"<urn:PortalDocumentID>{pPortal}</urn:PortalDocumentID>"				
				"<urn:PortalDocumentID>12345</urn:PortalDocumentID>"
				"<urn:SequenceNumber>1</urn:SequenceNumber>"
				"<urn:TransmissionRequestID>{AFTS_TraxID}{TransRequestID}{VuserID}</urn:TransmissionRequestID>"
				"<urn:Checksum>{AFTS_12_MB_Checksum}</urn:Checksum>"
				"<urn:PortalSubmissionDateTime>{Sub_DateTime}Z</urn:PortalSubmissionDateTime>"
				"<urn:PortalUpdateDateTime>{Updt_DateTime}Z</urn:PortalUpdateDateTime>"
				"<urn:PortalSentDateTime>{Sent_DateTime}Z</urn:PortalSentDateTime>"
				//"<!--Optional:-->"
				"<urn:DocXPathInfo>/VALUATION_RESPONSE/REPORT/EMBEDDED_FILE/DOCUMENT/text()</urn:DocXPathInfo>"
//				"<urn:DocXPathInfo>/VALUATION_RESPONSE/REPORT/FORM/IMAGE/EMBEDDED_FILE/DOCUMENT/text()</urn:DocXPathInfo>"					
				"</urn:AFTSHeader>"
				"<wsse:Security xmlns:wsse=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\">"
				"<wsu:Timestamp xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">"
				"<wsu:Created>{pTimeStamp}T23:59:01.709Z</wsu:Created>"
				"<wsu:Expires>{pTimeStamp}T23:59:01.709Z</wsu:Expires>"
				"</wsu:Timestamp>"
				"<wsse:UsernameToken wsu:Id=\"UsernameToken-164075274\" xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">"
				"<wsse:Username>{ID}</wsse:Username>"
				"<wsse:Password Type=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-username-token-profile-1.0#PasswordText\">{Password}</wsse:Password>"
				"</wsse:UsernameToken>"
				"</wsse:Security>"
				"</soapenv:Header>"
				"<soapenv:Body>"
				"<urn:DocumentTransferRequest>"
				"<urn:fileContent xm:contentType=\"text/xml\">"
				"{AFTS_12_MB_Data}"
				"</urn:fileContent>"
				"</urn:DocumentTransferRequest>"
				"</soapenv:Body>"
				"</soapenv:Envelope>",
				"SOAPAction=", 
				       "ResponseParam=response", 
				       "Snapshot=t1381252214.inf", 
				       LAST);
			
			lr_end_transaction("AFTS_12MB", LR_AUTO);
			
			break;
		case 14: //AFTS_14MB
			
			lr_start_transaction("AFTS_14MB");

			soap_request("StepName=SOAP Request",
					  "URL={pURL}", //Intg env
				//	  "URL=https://webservices.acptefanniemae.com/AFTSWebServiceIntg", //Intg env
						"SOAPEnvelope="
				        "<soapenv:Envelope xmlns:soapenv=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:urn=\"urn:www-uniformdataportal-com:ucdp-afts-2013-09\" xmlns:xm=\"http://www.w3.org/2005/05/xmlmime\">"
				"<soapenv:Header>"
				"<urn:AFTSHeader>"
//				"<urn:DocumentFileID>{pDocFile}</urn:DocumentFileID>"				
				"<urn:DocumentFileID>{TransID}{VuserID}</urn:DocumentFileID>"
//				"<urn:PortalDocumentID>{pPortal}</urn:PortalDocumentID>"				
				"<urn:PortalDocumentID>12345</urn:PortalDocumentID>"
				"<urn:SequenceNumber>1</urn:SequenceNumber>"
				"<urn:TransmissionRequestID>{AFTS_TraxID}{TransRequestID}{VuserID}</urn:TransmissionRequestID>"
				"<urn:Checksum>{AFTS_14MB_Checksum}</urn:Checksum>"
				"<urn:PortalSubmissionDateTime>{Sub_DateTime}Z</urn:PortalSubmissionDateTime>"
				"<urn:PortalUpdateDateTime>{Updt_DateTime}Z</urn:PortalUpdateDateTime>"
				"<urn:PortalSentDateTime>{Sent_DateTime}Z</urn:PortalSentDateTime>"
				//"<!--Optional:-->"
				"<urn:DocXPathInfo>/VALUATION_RESPONSE/REPORT/EMBEDDED_FILE/DOCUMENT/text()</urn:DocXPathInfo>"
//				"<urn:DocXPathInfo>/VALUATION_RESPONSE/REPORT/FORM/IMAGE/EMBEDDED_FILE/DOCUMENT/text()</urn:DocXPathInfo>"					
				"</urn:AFTSHeader>"
				"<wsse:Security xmlns:wsse=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\">"
				"<wsu:Timestamp xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">"
				"<wsu:Created>{pTimeStamp}T23:59:01.709Z</wsu:Created>"
				"<wsu:Expires>{pTimeStamp}T23:59:01.709Z</wsu:Expires>"
				"</wsu:Timestamp>"
				"<wsse:UsernameToken wsu:Id=\"UsernameToken-164075274\" xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">"
				"<wsse:Username>{ID}</wsse:Username>"
				"<wsse:Password Type=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-username-token-profile-1.0#PasswordText\">{Password}</wsse:Password>"
				"</wsse:UsernameToken>"
				"</wsse:Security>"
				"</soapenv:Header>"
				"<soapenv:Body>"
				"<urn:DocumentTransferRequest>"
				"<urn:fileContent xm:contentType=\"text/xml\">"
				"{AFTS_14MB_Data}"
				"</urn:fileContent>"
				"</urn:DocumentTransferRequest>"
				"</soapenv:Body>"
				"</soapenv:Envelope>",
				"SOAPAction=", 
				       "ResponseParam=response", 
				       "Snapshot=t1381252214.inf", 
				       LAST);
			
			lr_end_transaction("AFTS_14MB", LR_AUTO);
			                   
			break;			
		case 20: //AFTS_20MB
			
			lr_start_transaction("AFTS_20MB");
			
					 soap_request("StepName=SOAP Request",
					  "URL={pURL}", //Intg env
				//	  "URL=https://webservices.acptefanniemae.com/AFTSWebServiceIntg", //Intg env
						"SOAPEnvelope="
				        "<soapenv:Envelope xmlns:soapenv=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:urn=\"urn:www-uniformdataportal-com:ucdp-afts-2013-09\" xmlns:xm=\"http://www.w3.org/2005/05/xmlmime\">"
				"<soapenv:Header>"
				"<urn:AFTSHeader>"
//				"<urn:DocumentFileID>{pDocFile}</urn:DocumentFileID>"
				"<urn:DocumentFileID>{TransID}{VuserID}</urn:DocumentFileID>"
//				"<urn:PortalDocumentID>{pPortal}</urn:PortalDocumentID>"
				"<urn:PortalDocumentID>12345</urn:PortalDocumentID>"				
				"<urn:SequenceNumber>1</urn:SequenceNumber>"
				"<urn:TransmissionRequestID>{AFTS_TraxID}{TransRequestID}{VuserID}</urn:TransmissionRequestID>"
				"<urn:Checksum>{AFTS_20_MB_Checksum}</urn:Checksum>"	
				"<urn:PortalSubmissionDateTime>{Sub_DateTime}Z</urn:PortalSubmissionDateTime>"
				"<urn:PortalUpdateDateTime>{Updt_DateTime}Z</urn:PortalUpdateDateTime>"
				"<urn:PortalSentDateTime>{Sent_DateTime}Z</urn:PortalSentDateTime>"
				//"<!--Optional:-->"
				"<urn:DocXPathInfo>/VALUATION_RESPONSE/REPORT/EMBEDDED_FILE/DOCUMENT/text()</urn:DocXPathInfo>"
//				"<urn:DocXPathInfo>/VALUATION_RESPONSE/REPORT/FORM/IMAGE/EMBEDDED_FILE/DOCUMENT/text()</urn:DocXPathInfo>"					
				"</urn:AFTSHeader>"
				"<wsse:Security xmlns:wsse=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\">"
				"<wsu:Timestamp xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">"
				"<wsu:Created>{pTimeStamp}T23:59:01.709Z</wsu:Created>"
				"<wsu:Expires>{pTimeStamp}T23:59:01.709Z</wsu:Expires>"
				"</wsu:Timestamp>"
				"<wsse:UsernameToken wsu:Id=\"UsernameToken-164075274\" xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\">"
				"<wsse:Username>{ID}</wsse:Username>"
				"<wsse:Password Type=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-username-token-profile-1.0#PasswordText\">{Password}</wsse:Password>"
				"</wsse:UsernameToken>"
				"</wsse:Security>"
				"</soapenv:Header>"
				"<soapenv:Body>"
				"<urn:DocumentTransferRequest>"
				"<urn:fileContent xm:contentType=\"text/xml\">"			
				"{AFTS_20MB_Data}"
				"</urn:fileContent>"
				"</urn:DocumentTransferRequest>"
				"</soapenv:Body>"
				"</soapenv:Envelope>",
				"SOAPAction=", 
				       "ResponseParam=response", 
				       "Snapshot=t1381252214.inf", 
				       LAST);
			
			lr_end_transaction("AFTS_20MB", LR_AUTO);
			
			break;			
	}	

	lr_xml_get_values("XML={response}",
	                  "Query=//ns2:TransferStatus/ns2:Status",
	                  "ValueParam=ParamValue_Status",
	                  LAST);
	
	 //If the strings match successful, then the transaction passed and res value = 0 otherwise res will be <> 0.
     
     res = strcmp( "Successful", lr_eval_string("{ParamValue_Status}"));

     if (res==0) {
     trans_time=lr_get_transaction_duration("AFTS_Peak");
     lr_end_transaction("AFTS_Peak", LR_PASS);
     }
    else{
     trans_time=lr_get_transaction_duration("AFTS_Peak");
    lr_end_transaction("AFTS_Peak", LR_FAIL);
     }

	return 0;

}




