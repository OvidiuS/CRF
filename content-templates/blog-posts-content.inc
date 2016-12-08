<?php 

/**
 * Blog posts template
 *
 */

include_once("./includes/blog.inc"); 

// display paginated blog list
echo $page->get('headline|title');
echo renderPosts("limit=10", true); 


