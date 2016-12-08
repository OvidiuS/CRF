<?php  
if($page->innerPageLink) {
	$session->redirect($page->innerPageLink->url);
}else{
	echo "This page is supposed to be a link to another page in this site, but no page is selected. Please specify a page to link to in the backend.";
}
?>