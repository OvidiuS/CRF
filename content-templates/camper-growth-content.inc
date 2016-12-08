<?php
						// the content for this page is simple, we only need the title/headline and the body
						// the rest is handled by the layout template
					 ?>
					<h1><?= $page->get("headline|title");?></h1>
					<?= $page->body; ?>
					
					<?php foreach($page->camperGDimages as $camperImage) :?>
		
				<div class="camperGanDItemWrapper">
					<img src="<?= $camperImage->camperGDImage ? $camperImage->camperGDImage->getThumb('resized_image') : "http://placehold.it/650x375"; ?>" alt="<?= $camperImage->camperGDImage->description; ?>" width="650" height="375" />
					<div class="iwas tableCont">
					  <div class="inner">
						<span>I was...</span><?= $camperImage->camperGD_was; ?>
					  </div>
					</div>
					<div class="iam tableCont">
					  <div class="inner">
						<span>I am now...</span><?= $camperImage->camperGD_am; ?>
					  </div>
					</div>
					<div class="iwillbe tableCont">
					  <div class="inner">
						<span>I will be...</span><?= $camperImage->camperGD_will; ?>
					  </div>
					</div>
					<span class="firstArrow">&gt;</span>
					<span class="secondArrow">&gt;</span>
				</div>
				<!-- /.camperGanDItemWrapper -->
	
				<?php endforeach; ?>
					
					<?= $page->special_content; ?>