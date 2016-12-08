<?php include("./includes/head.inc"); ?>

<body>
<?php include("./includes/header.inc"); ?>
					
					<div class="slideshowWrapper">
    					<div class="slideshow flexslider">
        					<ul  class="slides">
        						
        						<?php         
    								if (count($page->homepage_main_slideshow)) {         
    								  foreach($page->homepage_main_slideshow as $image) {             
    								            
    								    echo '<li><img class="photo" src="'.$image->getCrop('slideshow-size-crop')->url.'" alt="{$image->description}" /></li>';
    								   }     
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
					
					<div class="boxWrapper">
						<div class="videoBox">
							<a href="<?= $pages->get(1)->main_video ?>&autoplay=1&rel=0" class="mainVideo" title="<?= $pages->get(1)->org_name;?> - Presentation Video"> 
								<img id="videoBackground" src="<?php echo $config->urls->templates?>images/videoBackground.png" alt=" "/>
								<img  id="movieFilm" src="<?php echo $config->urls->templates?>images/movieFilm.png" alt=" "/>
								<span>Watch Our Video</span>
							</a>
						</div>
						
						<!--end videoBox-->
						<ul class="imageBoxWrapper">
							<li class="imageBoxleft">
								<a href="<?= $pages->get(1307)->url ?>">
									<img src="<?php echo $config->urls->templates?>images/imageBoxleft.png" alt=" "/>
									<img  id="campDay" src="<?php echo $config->urls->templates?>images/campDay.png" alt=" "/>
									<img  id="leftImgArrow" src="<?php echo $config->urls->templates?>images/leftImgArrow.png" alt=" "/>
									<span>Camper Growth &amp; Development</span>
								</a>
							</li>
										
							<!--end imageBoxleft-->
							
							<li class="imageBoxcenter">
								<a href="<?= $pages->get(1320)->url ?>">
									<img   src="<?php echo $config->urls->templates?>images/imageBoxcenter.png" alt=" "/>
									<img  id="interactiveMap" src="<?php echo $config->urls->templates?>images/neverDoneBefore.png" alt=" "/>
									<img id="centerImgArrow" src="<?php echo $config->urls->templates?>images/centerImgArrow.png" alt=" "/>
									<span>I've Never Done That Before</span>
								</a>
							</li>
							
							<!--end imageBoxcenter-->
							
							<li class="imageBoxright">
								<a href="/fullscreen-gallery/" target="_blank">
									<img  src="<?php echo $config->urls->templates?>images/imageBoxright.png" alt=" "/>
									<img  id="photoGallery" src="<?php echo $config->urls->templates?>images/photoGalery.png" alt=" "/>
									<img  id="rightImgArrow" src="<?php echo $config->urls->templates?>images/rightImgArrow.png" alt=" "/>
									<span>View our Photo Gallery</span>
								</a>
							</li>
							
							<!--end imageBoxright-->
							
						</ul>
						<!--end imageBoxWrapper--> 
						
					</div>
					<!--end boxWrapper-->
					
					<div class="mainContentWrapper">
						<div class="topContentWrapper">
						
							
							<div class="topContentLeft"><h1><?=$page->get("headline|title");?></h1>
								<!-- START TEXT MODULE -->
								<?php echo $page->homepage_rich_text ?>
								
								<!-- END TEXT MODULE -->
							</div>
							<!--end topContentLeft-->
							
							
							
							<div class="topContentRight"> 
							<div class="homeRightColumn">
								<?=$page->home_right_column ?>
							</div>
							<div class="countedownWrapper" style="position: relative;">
								<!-- START COUNTDOWN MODULE -->
								<img src="<?php echo $config->urls->templates?>images/Countdown.png" alt="countdown"/>
								<div class="countdown">
									<p>
										<?php
											$calculation = (($page->countdown_date - time(void))/3600);
											$hours = (int)$calculation;
											$days  = (int)($hours/24);
											if ($days >= 0) { echo $days ; }else{echo "0";}
										?>
									</p>
									<span>Days<br>
									to Camp Opening</span> </div>
									<!-- END COUNTDOWN MODULE  -->
								</div>
							</div>
							<!--end topContentRight-->
							
						</div>
						<!--end topContentWrapper-->
						
						<h2 style="margin: 0;">News and Events</h2>
						<div class="bottomContentWrapper">
							
							<div class="bottomContentLeft">
							<a href="<?= $pages->get(1053)->url ?>">
								<!-- START RSS MODULE -->
								<img src="<?php echo $config->urls->templates?>images/blog64.png" alt="blog"/></a>
								<!-- START NEWS MODULE -->
								<h3>Latest <br />Blog Posts</h3>
								<ul>
									<?php 
										$latest_blog_posts = $pages->find("template=blog-post, sort=-date, limit=2");
										foreach ($latest_blog_posts as $blog_post) {
											if(empty($blog_post->summary)) {
												// summary is blank so we auto-generate a summary from the body
												$summary = strip_tags(substr($blog_post->body, 0, 150));
												$blog_post->summary = substr($summary, 0, strrpos($summary, ' ')). "...";
											}
	
											echo "<li><span>{$blog_post->date}</span>
												<a class='itemTitle' href='{$blog_post->url}'>{$blog_post->title}:</a>
												
												<span>{$blog_post->summary}</span>
											<div class='link'> <a href='{$blog_post->url}'>read more...</a> </div>
											</li>";
										}
									?>
								</ul>
								
								<!-- END NEWS MODULE -->
							</div>
							<!--end bottomContentLeft-->
							
							<div class="bottomContentCenter"> <a href="https://www.facebook.com/pages/Camps-Firebird-Roosevelt/270670676412">
								<!-- START RSS MODULE -->
								<img src="<?php echo $config->urls->templates?>images/facebook64.png" alt="facebook"/></a>
								<h3>Fresh from Facebook</h3>
								<ul class="freshFromFB">
								<?php 

									$token =  file_get_contents("https://graph.facebook.com/oauth/access_token?client_id=370212483178411&client_secret=71e876eb21f8e72a6497409cdd7b8faa&grant_type=client_credentials");
									//echo file_get_contents("https://graph.facebook.com/v2.2/29598302267/feed?access_token=1451351111833066|CyPzCYU1NBpvPr-FqMpJJ5PjlCg");

									$unparsed_json = file_get_contents("https://graph.facebook.com/v2.2/270670676412/feed?".$token);

									$json_array = json_decode($unparsed_json, true);
									$noOfWordstoShow = 15;
									$i= 0 ; // initialize counter

									foreach ($json_array['data'] as $item_arr) : 
										$postBody = $item_arr["message"] == "" ? $item_arr["story"] : $item_arr["message"];
										?>
										<li>
											<h4>
												<a href="<?= $item_arr['actions'][0]['link']; ?>"><?= date('m/d/Y',strtotime($item_arr["created_time"])); ?></a>
											</h4>
											<?php 
											 if ( str_word_count($postBody) > $noOfWordstoShow) {
											 	echo extractText($postBody, $noOfWordstoShow, "on");
											 }else{
											 	echo $postBody;
											 }
											
											?>
										</li>

									<?php
									$i++; if ($i >= 3 ) {	break; } // set number of posts to list
									endforeach 
									?>

								</ul>
								<!-- END RSS MODULE -->
							</div>
							<!--end bottomCenterContent-->
							<div class="topContentRight">
							<div class="bottomContentRight">
								<h3>Events Showcase</h3>
								<div class="miniSlideshowWrapper">
								<!-- START MINI SLIDESHOW -->
								<div  class="slideshowNeedle"></div>
								<!--<img src="images/javaslideshowImage.jpg" alt="img"/>-->
								<div class="javaSlideshow">
									<div class="miniSlideshow flexslider">
        								<ul  class="slides">
        						
        									<?php         
    											if (count($page->homepage_mini_slideshow)) {         
    											  foreach($page->homepage_mini_slideshow as $image): ?>             										
    										<li>
    											<img class="photo" src="<?= $image->getCrop('mini-slideshow-crop')->url ?>" alt="<?=$image->description?>" />
													<div class="slideCaption"><?=$image->description?></div>
											</li>
												   <?php endforeach; 
    											}else{
    												echo '<li><img class="photo" src="http://placehold.it/261x189.gif" alt="placeholder" /></li>';
    											}     
    										?> 
										</ul>
    								</div>
    								<!-- end slideshow flexslider -->
								</div>
								

								<div class="miniSlideButtonWrapper">
									
								</div>
								<!-- END MINI SLIDESHOW -->
							</div>		</div> </div>
							<!--end bottomContentRight--> 
						</div>
						<!--end bottomContentWrapper-->
					</div>
					<!--end mainContentWrapper--> 
				</div>	<!--end bodyWrapper -->
<?php include("./includes/foot.inc"); ?>
</body>
</html>