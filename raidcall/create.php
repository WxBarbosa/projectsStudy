<?php 
	
?>

<!DOCTYPE html>
<html>
<head>
	<title>Create Account</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="public/style/style.css">
	<link href="https://fonts.googleapis.com/css?family=Open+Sans" rel="stylesheet">
</head>
<body>
	<div id="account">
		<div id="form_account">
			<span class="txt_style">Email:</span>
			<input class="form_style" type="email" name="email" id="email">

			<span class="txt_style">Login:</span>
			<input class="form_style" type="text" name="login" id="login">

			<span class="txt_style">Senha:</span>
			<input class="form_style" type="password" name="pass" id="pass">

			<span class="txt_style">Nickname:</span>
			<input class="form_style" type="text" name="nickname" id="nickname">

			<button id="enviar">Enviar</button>
		</div>
	</div>
	<span id="result" style="color: white; background-color: red; border-radius: 5px;"></span>
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
	<script src="public/js/script.js"></script>		
</body>
</html>