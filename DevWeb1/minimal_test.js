//FSM
// Afegit LifeRay Auth-token 
// 9/9/2020 - Update password despres del bloqueig - PRE PROVA
// 19/10/2020 - Proves amb MultiUser
// 04/11/2020 - Multiuser per VU


load.initialize(async function () {
});

load.action("Action", async function () {
    var loginParam = load.params.userdni;
    var passwdParam = load.params.userpasswd;
    load.log(`User Params: \n-DNI:${loginParam}`); 
    load.log(`User Params2: \n-PASS:${passwdParam}`); 
    
    load.WebRequest.defaults.returnBody = false;
    load.WebRequest.defaults.headers = {
        "Accept-Language": "en-US,en;q=0.5",
        "Cache-Control": "no-cache",
        "Connection": "keep-alive",
        "Pragma": "no-cache",
        "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:68.0) Gecko/20100101 Firefox/68.0"
    };

    // -- Access a la pagina inicial -- 
    const iniciTransaction = new load.Transaction("1-PaginaInicio"); //new transacion
    iniciTransaction.start()
    const webResponse1 = new load.WebRequest({
        id: 1,
        url: "https://moneytopay.com/",
        method: "GET",
        headers: {
            "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
            "Accept-Encoding": "gzip, deflate, br",
            "Upgrade-Insecure-Requests": "1"
        },
    }).sendSync();
    //important per treure el Liferay.authToken = 'cpS1v5hI';
    const regexpRule1 = new load.RegexpExtractor("liferayauthtoken","authToken = '(.*)'" ,"i");
    const webResponse106 = new load.WebRequest({
        id: 106,
        url: "https://moneytopay.com/web/guest/area-usuario",
        method: "GET",
        returnBody: false,
        extractors: [
            regexpRule1
        ],
        headers: {
            "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
            "Accept-Encoding": "gzip, deflate, br",
            "Referer": "https://moneytopay.com/",
            "Upgrade-Insecure-Requests": "1"
        },
    }).sendSync();

    load.log(`The authtoken is ${webResponse106.extractors.liferayauthtoken}`)
    const lauthtoken = webResponse106.extractors.liferayauthtoken

    // Final carrega inicial
    iniciTransaction.stop(load.TransactionStatus.Passed); 

    // Fem LOGIN
    const loginTransaction = new load.Transaction("2-Login"); //new transacion
    loginTransaction.start()
    const webResponse194 = new load.WebRequest({
        id: 194,
        url: "https://moneytopay.com/web/guest/area-usuario",
        method: "POST",
        returnBody: true,
        headers: {
            "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
            "Accept-Encoding": "gzip, deflate, br",
            "Content-Type": "application/x-www-form-urlencoded",
            "Referer": "https://moneytopay.com/web/guest/area-usuario",
            "Upgrade-Insecure-Requests": "1"
        },
        body: {
            "login": loginParam,
            "password": passwdParam
        },
        queryString: {
            "p_p_id": "m2pdxpuserflows_WAR_m2pdxpuserflows",
            "p_p_lifecycle": "1",
            "p_p_state": "normal",
            "p_p_mode": "view",
            "_m2pdxpuserflows_WAR_m2pdxpuserflows_execution": "e1s1",
            "_m2pdxpuserflows_WAR_m2pdxpuserflows__eventId": "loginUser",
            "p_auth": lauthtoken
        },
    }).sendSync();
    // Fi Login 
    if (webResponse194.textCheck("dataLayer = [{'registered': checkCookie('M2PESL_USER'), 'loggedIn' : true}];")){
        load.log("Success! LoggedIn: true");
        loginTransaction.stop(load.TransactionStatus.Passed);
    } else {
        load.log("Failure! KO. Problema de Login");
        loginTransaction.stop(load.TransactionStatus.Failed)
    }
    //loginTransaction.stop(load.TransactionStatus.Passed);


});

load.finalize(async function () {
});
