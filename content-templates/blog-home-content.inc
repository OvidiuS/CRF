					<?php include_once("./includes/blog.inc");  ?>

					<h1><?= $page->get("headline|title");?></h1>
					<?= $page->body . renderPosts("limit={$page->quantity}"); ?>