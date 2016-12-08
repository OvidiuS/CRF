
	<h1>
		<?= $page->get("headline|title");?>
	</h1>

	<?= $page->body; ?>
	<div class="slideshowWrapper">
    					<div class="slideshow flexslider">
        					<ul  class="slides">
        						
        						<?php         
    								if (count($page->homepage_main_slideshow)) {         
    								  foreach($page->homepage_main_slideshow as $image): ?>             
    								  	<li>
											<img class="photo" src="<?=$image->getCrop('slideshow-size-crop')->url ?>" alt="<?= $image->description?>" />
											<div class="ndbText">
												<?= $image->description?>
											</div>
										</li>
    								  <?php endforeach;    
    								}else{
    									echo '<li><img class="photo" src="'.$config->urls->templates.'images/homepage/900x400.gif" alt="placeholder" /></li>';
    								}     
    							?> 
            					
							</ul>
    					</div>
    					<!--end slideshow--> 
    					<div id="pin"></div>
					</div>
					<!--end slideshowWrapper-->