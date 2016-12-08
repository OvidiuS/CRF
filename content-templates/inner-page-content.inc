					
					<?php
						// the content for this page is simple, we only need the title/headline and the body
						// the rest is handled by the layout template
					 ?>
					<h1><?= $page->get("headline|title");?></h1>
					<?= $page->body; ?>
					<?= $page->special_content; ?>
					<?php 
						foreach($page->faqs as $faq) {
    						echo "<h3 class='faq_question'><a href='#'>{$faq->faq_question}</a></h2>";    
    						echo "<div class='faq_answer'>{$faq->faq_answer}</div>";
    					} 
					?>
					<?= $page->faq_answer ?>