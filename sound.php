<?php
$log_file = 'testcurl.txt';
$value = $_POST['db'];
$str = date("M d Y H:i:s",time()).' '.$value."\n";

echo "This is from the server: ";
// now we open the file 
if (file_exists($log_file)){
		$fp = fopen($log_file,a);// the file is opened as apeend mode
		fwrite($fp, $str);
		fclose($fp);
}else{
		$fp = fopen($log_file,w);
		fwrite($fp, $str);
		fclose($fp);
}
?>