<?php include("./includes/head.inc"); ?>

<body>
<?php include("./includes/header.inc"); ?>
					
					<div class="hpVideoBg" style="padding:0 10px;position:relative;">
						<video autoplay="autoplay" loop="loop" style="background-image: url(&quot;https://daks2k3a4ib2z.cloudfront.net/5829dbd5bb1a1e38054cf463/5829e46de899c58c39beee22_ucw1-homepage-video-poster-00001.jpg&quot;); width:100%">
							<source src="https://daks2k3a4ib2z.cloudfront.net/5829dbd5bb1a1e38054cf463/5829e46de899c58c39beee22_ucw1-homepage-video-transcode.webm" data-wf-ignore="">
							<source src="https://daks2k3a4ib2z.cloudfront.net/5829dbd5bb1a1e38054cf463/5829e46de899c58c39beee22_ucw1-homepage-video-transcode.mp4" data-wf-ignore="">
						</video>
						<a href="<?= $pages->get(1)->main_video ?>&autoplay=1&rel=0" class="fullVideoButton mainVideo">See Full Video</a>
					</div>
					<!-- /.hpVideoBg -->
					
					
					<div class="mainContentWrapper">

						<div class="topContentWrapper">
							<div class="topContentLeft"><h1><?=$page->get("headline|title");?></h1>
								<!-- START TEXT MODULE -->
								<?php echo $page->homepage_rich_text ?>
								
								<!-- END TEXT MODULE -->
							</div>
							<!--end topContentLeft-->
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
							
							</div>
							<!--end bottomContentRight--> 
						</div>
						<!--end bottomContentWrapper-->
					</div>
					<!--end mainContentWrapper--> 
				</div>	<!--end bodyWrapper -->
<?php include("./includes/foot.inc"); ?>
</body>
</html>