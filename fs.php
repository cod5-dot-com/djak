<?php
$dn = dirname(dirname(__FILE__)) . "/daily-digest/";

function gen_folder()
{
	$folder = date("Ym");
	return $folder;
}

function get_folder() {
	global $folder;
	if (strlen($folder) < 6) {
		//header('HTTP/1.1 403 Forbidden');
		//exit();
		return "/" . $folder;
	}
	$dst = "/" . substr($folder,0, 4)
		. "/" . substr($folder, 4);
	return $dst;
}

/*
function gen_folder()
{
	global $user;
	$l = strlen($user);
	$folder = date("YmdHis") . "_________________";
	for ($i = 0; $i < $l && $i < 31; $i++) {
		$folder[$i + 14] = $user[$i];
	}
	return $folder;
}

function get_folder() {
	global $dn;
	global $folder;
	if (strlen($folder) < 16) {
		header('HTTP/1.1 403 Forbidden');
		exit();
	}
	$dst = "/" . substr($folder,0, 4)
		. "/" . substr($folder, 4, 2)
		. "/" . substr($folder, 6, 2)
		. "/" . substr($folder, 8, 2)
		. "/" . substr($folder, 10, 2)
		. "/" . substr($folder, 12, 2)
		. "/" . substr($folder, 14);
	return $dst;
}
*/

///////////////////////////////////////////////////////////////////////////////

session_start();

if (isset($_SESSION['UserData']['user']) && 
	isset($_SESSION['UserData']['pass']))
{
	if (!(isset($_POST["user"]) &&
		isset($_POST["pass"]) &&
		$_POST["user"] == $_SESSION['UserData']['user'] &&
		$_POST["pass"] == $_SESSION['UserData']['pass'])) 
	{
		session_destroy();
		header('HTTP/1.1 403 Forbidden');
		header("Content-type: text/plain");
		echo "logout";
		exit();
	}
} else {
	include ".htpasswd";
	if (isset($_POST["user"]) &&
		isset($_POST["pass"]) &&
		isset($logins[$_POST["user"]]))
	{
		if (password_verify($_POST["pass"], $logins[$_POST["user"]])) {
			$_SESSION['UserData']['user'] = $_POST["user"];
			$_SESSION['UserData']['pass'] = $_POST["pass"];
		} else {
			session_destroy();
			header('HTTP/1.1 403 Forbidden');
			$p = password_hash($_POST["pass"], PASSWORD_BCRYPT);
			echo "invalid password : " . $p;
			exit();
		}
	} else {
		session_destroy();
		header('HTTP/1.1 403 Forbidden');
		echo "invalid user / password";
		exit();
	}
}

$user = base64_encode($_POST["user"]);
$folder = str_replace("..", "__", $_POST["folder"]);
$target = str_replace("..", "__", $_POST["target"]);
$seek = intval($_POST["seek"]);
$size = intval($_POST["size"]);

if (strlen($dn) < 5) {
	header('HTTP/1.1 403 Forbidden');
	echo "current directory name is too short";
	exit();
}

///////////////////////////////////////////////////////////////////////////////

switch ($_POST["func"]) {
case "mkfolder":
	$folder = gen_folder();
	$d = $dn . "/" . get_folder();
	if (file_exists($d)) {
		header('HTTP/1.1 403 Forbidden');
		exit();
	}
	mkdir($d, 0777, true);
	header('HTTP/1.1 200 OK');
	header("Content-type: text/plain");
	echo $folder;
	exit();

case "write":
	$v = $_FILES["files"];
	$dst = $dn . "/" . get_folder() . "/" . $target;
	$dr = dirname($dst);
	if ($dr == $dn && $target == "fs.php") {
		header('HTTP/1.1 403 Forbidden');
		exit();
	}
	if (!is_dir($dr)) {
		mkdir($dr, 0777, true);
	}
	$fp = fopen($dst, "cb");
	if (!$fp) {
		header('HTTP/1.1 403 Forbidden');
		exit();
	}
	fseek($fp, 0);
	if ($size >= 0) {
		ftruncate($fp, $size);
	}
	if ($seek >= 0) {
		fseek($fp, $seek);
	}
	$fis = filesize($v['tmp_name'][0]);
	if ($fis > 0) {
		$da = file_get_contents($v['tmp_name'][0]);
		fwrite($fp, $da, $fis);
	}
	fclose($fp);	
	header('HTTP/1.1 200 OK');
	header("Content-type: text/plain");
	echo $folder . "/" . $target;
        exit();	

case "filesize":	
	$dst = $dn . "/" . get_folder() . "/" . $target;
	$se = filesize($dst);
	if ($se == false) {
		header('HTTP/1.1 404 Not Found');
		exit();
	}
	header('HTTP/1.1 200 OK');
	header("Content-type: text/plain");
	echo $se;
	exit(); 

case "read":
	$dst = $dn . "/" . get_folder() . "/" . $target;
	$fp = fopen($dst, "rb");
	if (!$fp) {
		header('HTTP/1.1 404 Not Found');
		//header('HTTP/1.1 403 Forbidden');
		exit();
	}
	if ($seek > 0) {
		fseek($fp, $seek);
	}
	if ($size < 1) {
		$size = filesize($dst);
	}	
	header('HTTP/1.1 200 OK');
	header("Content-type: text/plain");
	if ($size > 0) {
		print(fread($fp, $size));
	}
	fclose($fp);
	exit();

case "unlink":
	$dst = $dn . "/" . get_folder() . "/" . $target;
	if (unlink($dst)) {
		header('HTTP/1.1 200 OK');
		header("Content-type: text/plain");
		echo $folder . "/" . $target;
	} else {
		header('HTTP/1.1 403 Forbidden');
	}
        exit();

case "mkdir":
	$dst = $dn . "/" . get_folder() . "/" . $target;
	if (file_exists($dst)) {
		header('HTTP/1.1 404 Not Found');
		exit();
	}
	if (mkdir($dst, 0777, true)) {
		header('HTTP/1.1 200 OK');
		header("Content-type: text/plain");
		echo $folder . "/" . $target;
	} else {
		header('HTTP/1.1 403 Forbidden');
	}
        exit();	

case "rmdir":
	$dst = $dn . "/" . get_folder() . "/" . $target;
	if (rmdir($dst)) {
		header('HTTP/1.1 200 OK');
		header("Content-type: text/plain");
		echo $folder . "/" . $target;
	} else {
		header('HTTP/1.1 403 Forbidden');
	}
        exit();	

case "scandir":
        $dst = $dn . "/" . get_folder() . "/" . $target;
        $lst = scandir($dst);
	if (!$lst) {
		header('HTTP/1.1 404 Not Found');
		exit();
	}
        header('HTTP/1.1 200 OK');
        header("Content-type: text/plain");
	foreach ($lst as $f) {
		if (is_dir($dst . "/" . $f)) {
			if (!($f == "." || $f == "..")) {
				echo $f . "/\n";
			}
		} else {
                	echo $f . "\n";
		}
        }
        exit();

default:
	header('HTTP/1.1 404 Not Found');
	exit(-1);
}

/*
header('Content-Type: application/octet-stream');
header('Content-Disposition: attachment; filename="example.zip"'); 
header('Content-Transfer-Encoding: binary');

echo ":: data received via GET ::\n\n";
print_r($_GET);

echo "\n\n:: Data received via POST ::\n\n";
print_r($_POST);

echo "\n\n:: Data received as \"raw\" (text/plain encoding) ::\n\n";
if (isset($HTTP_RAW_POST_DATA)) { echo $HTTP_RAW_POST_DATA; }

echo "\n\n:: Files received ::\n\n";
print_r($_FILES);
*/
?>
