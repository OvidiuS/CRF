<?php 

/**
 * Categories (list) template
 *
 */

/**
 * Render a list of categories, optionally showing a few posts from each
 *
 * @param PageArray $categories
 * @param int Number of posts to show from each category (default=0)
 * @return string
 *
 */
function renderCategories(PageArray $categories, $showNumPosts = 0) {
	foreach($categories as $category) {
		$category->posts = wire('pages')->find("template=blog-post, categories=$category, limit=$showNumPosts, sort=-date"); 
	}
	$t = new TemplateFile(wire('config')->paths->templates . 'markup/categories.php'); 
	$t->set('categories', $categories); 
	return $t->render();
}

/*********************************************/

include_once("./includes/blog.inc"); 

$limit = 3; // number of posts to show per category
echo "<h1>".$page->title."</h1>"; 
echo $page->body . renderCategories($page->children, $limit);
