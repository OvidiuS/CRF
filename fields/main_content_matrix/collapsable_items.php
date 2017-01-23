<?php 
						foreach($page->faqs as $faq) {
    						echo "<h3 class='faq_question'><a href='#'>{$faq->faq_question}</a></h2>";    
    						echo "<div class='faq_answer'>{$faq->faq_answer}</div>";
    					} 
					?>