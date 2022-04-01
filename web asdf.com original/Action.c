Action()
{

lr_start_transaction("1_transaction");

	web_reg_find("Text=asdf", 
		LAST);

	web_add_auto_header("Accept", 
		"text/html, application/xhtml+xml, */*");

	web_add_header("User-Agent", 
		"Mozilla/5.0 (Windows NT 6.1; Win64; x64; Trident/7.0; rv:11.0) like Gecko");

	web_url("www.asdf.com", 
		"URL=http://www.asdf.com/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("1_transaction",LR_AUTO);

	return 0;
}