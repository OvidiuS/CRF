					
					<?php
						// the content for this page is simple, we only need the title/headline and the body
						// the rest is handled by the layout template
					 ?>
					<h1><?= $page->get("headline|title");?></h1>
					<?= $page->body; ?>
					<?php 

						foreach($page->camper_forms_list as $camper_form) {
    						echo "<div class='camper_form'>";    
    						echo "<a href='{$camper_form->camper_form_pdf->url}'><span>{$camper_form->camper_form_name}</span>";
    						echo "<img src='{$camper_form->camper_form_image->url}' alt='{$camper_form->camper_form_name}' /></a>";
    						echo "</div>";
						}

					?>