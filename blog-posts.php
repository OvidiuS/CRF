<?php 
include_once("./includes/blog.inc"); 
if($input->urlSegment1) {
	// check for rss feed
	if($input->urlSegment1 != 'rss') throw new Wire404Exception();
	$homepage = $pages->get('/'); 
	renderRSS($page->children("limit=10"), $homepage->get('headline|title'), $homepage->get('summary|meta_description')); 
	
} else {
	// specify the content
	$contentTemplateName = "./content-templates/blog-posts-content.inc";
	// specify the layout
	include("./layout-templates/blog-layout.inc");
}

?>