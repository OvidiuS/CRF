<?php 

/**
 * Blog Post template
 *
 */

include_once("./includes/blog.inc"); 

// render our blog post and comments
echo $page->blog_comments->render() .
$page->blog_comments->renderForm();

