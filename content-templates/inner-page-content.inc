					
					<?php
						// the content for this page is simple, we only need the title/headline and the body
						// the rest is handled by the layout template
					 ?>
					<h1><?= $page->get("headline|title");?></h1>
					<?= $page->render('main_content_matrix'); ?>
					<?= $page->special_content; ?>