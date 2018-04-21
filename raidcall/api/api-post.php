<?php 

	// Declaration of variables to Request POST	
	$ac = $_POST['ac'];
	$name = $_POST['name'];
	$email = $_POST['email'];
	$pwd = $_POST['pwd'];
	$login = $_POST['login'];
	$vender = $_POST['vender'];
	$mid = $_POST['mid'];
	$nick = $_POST['nick'];
	$fbid = $_POST['fbid'];
	$fbusername = $_POST['fbusername'];
	$token = $_POST['token'];

	if(($name!="") || ($email!="") || ($pwd!="") || ($nick!="")){
		// Creation of CURL
		$ch = curl_init();

		// Distribution of informations to be sending!
		$queryString = array(
		    'ac' => $ac,
		    'name' => $name,
		    'email' => $email,
		    'pwd' => $pwd,
		    'login' => $login,
		    'vender' => $vender,
		    'mid' => $mid,
		    'nick' => $nick,
		    'fbid' => $fbid,
		    'fbusername' => $fbusername,
		    'token' => $token
		);

		// Url containing address of API Raidcall
		$url = 'http://www.raidcall.com.ru/client/fbreg/api.php?'.http_build_query($queryString);

		// Api to Proxy Request
		$dir = "../public/proxy.txt";
		$f = file($dir);

		//envia a URL como parâmetro para o cURL;
		curl_setopt($ch, CURLOPT_URL, $url);
		curl_setopt($ch, CURLOPT_RETURNTRANSFER,true);
		curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
		//curl_setopt($ch, CURLOPT_PROXY, $f[0]);
		$cont = curl_exec($ch);
		curl_close($ch);

		if($cont == '{"error":403}'){
			echo("Conta já existe!"."<br>");
		}elseif($cont == '{"error":405}'){
			echo("Proxy Expirado!"."<br>");
		}elseif($cont == '{"error":401}'){
			echo("Email Incorreto!"."<br>");
		}elseif($cont == '{"error":400}'){
			echo("Login inválido!"."<br>");
		}elseif($cont == '{"error":500}'){
			echo("Conta não criado. Proxy Inutilizável! Tente novamente."."<br>");
		}else{
			echo("Conta criada com sucesso!"."<br>");
		}

		$contents = str_replace($f[0],'', $f);
		file_put_contents($dir, $contents);	
	}else{
		echo("Preencha todos os campos.<br>");
	}
	
?>
