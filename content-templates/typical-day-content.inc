<?php

function listTdImages($imageSet) {
	echo '<ul class="slides">';
	if(count($imageSet)) {
		    foreach($imageSet as $image) {
				$imageUrl = $image->getThumb(gallery_size) ? $image->getThumb(gallery_size) : $image->size(932,402)->url;
				echo "<li><img class='photo' src='{$imageUrl}' data-description='{$image->description}' alt='{$image->description}' /></li>";					
			}// end foreach
	}
	if(!count($imageSet) || count($imageSet)<6){
		$missingImages = count($imageSet) ? 6-count($imageSet) : 6;
		echo str_repeat("<li><img class='photo' src='http://cac.dvsdev.com/site/templates/images/typicalDay/858x370.gif' data-description='Missing image! Please add one in the manager.' alt='placeholder' /></li>", $missingImages);
	}
	echo '</ul>';
}// end listTdImages
?>
	<h1>
		<?= $page->get("headline|title");?>
	</h1>
	<div class="tdSlideShowOuterWrap">
		<div class="tdTopWrapper">
			<ul class="genderSelector">
				<li><a href="#" id="b">Boy</a></li>
				<li><a href="#" id="g">Girl</a></li>
			</ul>
			<ul class="ageSelector">
				<li><a href="#" id="a78">5-8 <span>years</span></a></li>
				<li><a href="#" id="a911">9-11 <span>years</span></a></li>
				<li><a href="#" id="a1213">12-14 <span>years</span></a></li>
				<li><a href="#" id="a1415">15-17 <span>years</span></a></li>
			</ul>
		</div>
		<!-- end tdTopWrapper -->
		<div class="tdSlideShowWrap">
			<div class="welcomeMessage"><img src="<?php echo $config->urls->templates?>/images/typicalDay/typicalDayStart.jpg" /></div>
			<div class="ageError"><img src="<?php echo $config->urls->templates?>/images/typicalDay/typicalDayAgeError.jpg" /></div>
			<div class="genderError"><img src="<?php echo $config->urls->templates?>/images/typicalDay/typicalDayGenderError.jpg" /></div>
			<div class="tdSlideShow flexslider" id="slideShow-b-a78">
				<?php
					listTdImages($page->td_b_age1);
				
				?>
			</div>
			<div class="tdSlideShow flexslider" id="slideShow-b-a911">
				<?php
					listTdImages($page->td_b_age2);
				?>
			</div>
			<div class="tdSlideShow flexslider" id="slideShow-b-a1213">
				<?php
					listTdImages($page->td_b_age3);
				?>
			</div>
			<div class="tdSlideShow flexslider" id="slideShow-b-a1415">
				<?php
					listTdImages($page->td_b_age4);
				?>
			</div>
			<div class="tdSlideShow flexslider" id="slideShow-g-a78">
				<?php
					listTdImages($page->td_g_age1);
				?>
			</div>
			<div class="tdSlideShow flexslider" id="slideShow-g-a911">
				<?php
					listTdImages($page->td_g_age2);
				?>
			</div>
			<div class="tdSlideShow flexslider" id="slideShow-g-a1213">
				<?php
					listTdImages($page->td_g_age3);
				?>
			</div>
			<div class="tdSlideShow flexslider" id="slideShow-g-a1415">
				<?php
					listTdImages($page->td_g_age4);
				?>
			</div>
			<a href="#" id="prev2">prev</a> <a href="#" id="next2">next</a>
		</div>
		<div class="slideshowNavWrap">
		<div class="slideshownavWrapper2">
			<div class="tdSlideshowNavCover"> </div>
			<ul id="tdSlideShowNav" class="tdInactiveButtons">
				<li><a href="#"><span>Water Sports</span></a></li>
				<li><a href="#"><span>Land Sports</span></a></li>
				<li id="thirdButton"><a href="#"><span>Adventure Sports</span></a></li>
				<li><a href="#"><span>Specialty Program</span></a></li>
				<li><a href="#"><span>General Program</span></a></li>
				<li class="last"><a href="#"><span>Evening Program</span></a></li>
				<!-- class="oneLine" -->
			</ul>
			</div>
			<div class="slideDescription"> </div>
		<!-- end .slideDescription--> 
		</div>
		<!-- end slideshowNavWrap -->
		
		
		 </div>
	<!-- end .tdSlideShowOuterWrap -->
	<?= $page->body; ?>