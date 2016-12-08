<?php  
if($page->custom_url) {
	$session->redirect($page->custom_url);
}else{
	echo "This page is an external link to a custom URL, but no URL is specified. Please specify a URL in the backend.";
}
?>