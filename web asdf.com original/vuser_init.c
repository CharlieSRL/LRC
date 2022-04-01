vuser_init()
{
	web_set_sockets_option("SSL_VERSION", "TLS1.1");
		
	return 0;
}
