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
					
						<div class="topContentWrapper">
							<div class="topContentLeft"><h1><?=$page->get("headline|title");?></h1>
								<!-- START TEXT MODULE -->
								<?php echo $page->homepage_rich_text ?>
								
								<!-- END TEXT MODULE -->
							</div>
							<!--end topContentLeft-->
						</div>
						<!--end topContentWrapper-->
															
						<div class="hpBottomSection">
							
							<h2 class="facebook-feed-heading">Fresh from Facebook</h2>

							<div class="facebook-posts-wrapper">

								<div class="facebook-post-wrapper">
									<h4 class="fb-post-title">Camps Roosevelt &amp; Firebird&nbsp;shared&nbsp;Joe Tree Mendes's&nbsp;post.</h4>
									<h5 class="fb-post-date">October 31 at 6:46pm</h5>
									<img class="facebook-post-image" src="http://uploads.webflow.com/5829dbd5bb1a1e38054cf463/582a48b159700a67442bc175_fb2.jpg">
									<p class="fb-post-text">Send me a picture of YOU in a Halloween Costume! I'll share it on the camp page. Just get your parent's permission. We want to see something creative! <br><a href="#" class="fb-post-link">Read more...</a></p>
								</div>

								<div class="facebook-post-wrapper last">
									<h4 class="fb-post-title">Camps Roosevelt &amp; Firebird&nbsp;shared&nbsp;Joe Tree Mendes's&nbsp;post.</h4>
									<h5 class="fb-post-date">October 30 at 5:27pm</h5>
									<img class="facebook-post-image" src="http://uploads.webflow.com/5829dbd5bb1a1e38054cf463/582a48bc58366e31663826b7_fb1.jpg">
									<p class="fb-post-text">LAST DAY FOR THE EARLY-BIRD DISCOUNT! SIGN UP TODAY!&nbsp;:)<br><a href="#" class="fb-post-link">Read More...</a></p>
								</div>

							</div>
						</div>
						<!--end hpBottomSection-->

					</div>
					<!--end mainContentWrapper--> 
				</div>
				<!--end bodyWrapper -->

<?php include("./includes/foot.inc"); ?>
</body>
</html>