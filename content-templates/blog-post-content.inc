<?php 

/**
 * Blog Post template
 *
 */

include_once("./includes/blog.inc"); 

function renderNextPrevPosts($page) {
	$date = $page->getUnformatted('date');
	$nextPost = $page->parent->child("date>$date, sort=date");
	$prevPost = $page->parent->child("date<$date, sort=-date");

	$out = "<div class='next-prev-posts'>"; 
	if($prevPost->id > 0) $out .= "<p class='prev-post'><span>&lt;</span> <a href='{$prevPost->url}'>{$prevPost->title}</a></p>";
	if($nextPost->id > 0) $out .= "<p class='next-post'><a href='{$nextPost->url}'>{$nextPost->title}</a> <span>&gt;</span></p>";
	$out .= "</div>";
	return $out; 
}


// render our blog post and comments

$numComments = $page->blog_comments->count();
if($numComments > 0) $numCommentsStr = sprintf(_n('%d Comment', '%d Comments', $numComments), $numComments);
	else $numCommentsStr = __('No comments yet'); 

		// set a couple new fields that our output will use
		$page->set('authorName', $page->createdUser->get('title|name')); 
		$page->set('authorURL', wire('config')->urls->root . 'authors/' . $page->createdUser->name . '/'); 

?>
<div class='post' id='post-<?php echo $page->id; ?>'>

	<div class='post-head'>

		<?php 
		echo "<a class='num-comments-icon' href='{$page->url}#comments' title='$numCommentsStr'>$numComments</a> ";
		// headline
		$h = $small ? 'h4' : 'h2';
		echo "<$h class='post-headline'><a href='{$page->url}'>{$page->title}</a></$h>";
		?>

		<p class='post-byline'><?php 
			// meta/byline
			echo "<span class='author'>" . sprintf(__('Posted by %s'), "<a href='{$page->authorURL}'>{$page->authorName}</a></span>, ");
			echo "<span class='date'>{$page->date}</span> ";
			if($page->editable()) echo "<span class='edit'>(<a href='" . wire('config')->urls->admin . "page/edit/?id={$page->id}'>" . __('edit') . "</a>)</span>";
		?></p>
	</div>

	<div class='post-body'>

		<?php 
		if($small) {
			echo "<p>" . $page->summary . "&hellip; <a class='more' href='{$page->url}'>" . __('View More') . "</a></p>";
		} else {
			echo $page->body; 
			// if the post has images and no <img> tags in the body, then make it a gallery
			if(count($page->images) && strpos($page->body, '<img ') === false) include("./gallery.php"); 
		}
		?>

	</div>

	<div class='post-foot'>

		<?php

		if(!$small) {
			// display categories & tags when doing large posts
			$out = '';
			if(count($page->categories)) {
				$out = "<p class='categories'><span>" . __('Categories:') . '</span> ';
				foreach($page->categories as $category) {
					$out .= "<a href='{$category->url}'>{$category->title}</a>, ";	
				}
				echo rtrim($out, ", ") . "</p> ";
			}

			if(count($page->tags)) {
				$out = "<p class='tags'><span>" . __('Tags:') . '</span> '; 
				foreach($page->tags as $tag) {
					$out .= "<a href='{$tag->url}'>{$tag->title}</a>, ";
				}
				echo rtrim($out, ", ") . "</p> ";
			}

			echo "<p class='num-comments'><span>" . __('Comments:') . "</span> <a href='{$page->url}#comments'>$numCommentsStr</a></p> ";
		}

		?>
		
	</div>

</div>
<a name="comments" />

<?php echo renderComments($page->blog_comments) . renderNextPrevPosts($page); 
