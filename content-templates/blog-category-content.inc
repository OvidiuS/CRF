<?php 

/**
 * Category template
 *
 */

include_once("./includes/blog.inc"); 

$posts = $pages->find("template=blog-post, categories=$page, limit=10"); // get the last 10 post from this category
$n = $posts->getTotal(); 

if($input->urlSegment1) {
	// rss feed
	if($input->urlSegment1 != 'rss') throw new Wire404Exception();
	renderRSS($posts); 
	return;
}

echo "<h1> Category: ".$page->title."</h1>";
echo $page->body . renderPosts($posts, true); 

?>




