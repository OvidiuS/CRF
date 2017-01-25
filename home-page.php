<?php include("./includes/head.inc"); ?>

<body>
<?php include("./includes/header.inc"); ?>
					
					<div class="hpVideoBg" style="padding:0 10px;position:relative;">
						<video autoplay="autoplay" loop="loop" style="background-image: url(&quot;https://daks2k3a4ib2z.cloudfront.net/5829dbd5bb1a1e38054cf463/5829e46de899c58c39beee22_ucw1-homepage-video-poster-00001.jpg&quot;); width:100%">
							<source src="https://daks2k3a4ib2z.cloudfront.net/5829dbd5bb1a1e38054cf463/584fb020c49a13fd49b690a5_Camp-Roosevelt-Firebird-Loop-transcode.webm" data-wf-ignore="">
							<source src="https://daks2k3a4ib2z.cloudfront.net/5829dbd5bb1a1e38054cf463/584fb020c49a13fd49b690a5_Camp-Roosevelt-Firebird-Loop-transcode.mp4" data-wf-ignore="">
						</video>
						<a href="<?= $pages->get(1)->main_video ?>&autoplay=1&rel=0" class="fullVideoButton mainVideo">See Full Video</a>
					</div>
					<!-- /.hpVideoBg -->
					
						<div class="homepage-content-wrapper">
							<h1 class="home-main-heading"><?=$page->get("headline|title");?></h1>
							<div class="homepage-intro-para">
								<?php echo $page->homepage_rich_text ?>
							</div>
							<!-- /.homepage-intro-para -->
							
							<div class="home-content-block clearfix">
								<img class="left" src="http://uploads.webflow.com/5829dbd5bb1a1e38054cf463/5841595ec5de377732c29994_fun.jpg" width="241">
								<h2 class="">Fun Activities</h2>
								<p>Lake, field, forest, court and barn … we’ve got it all--great activities and experiences! Our energetic staff creates imaginative, silly and offbeat games. We put our own spin on the normal to make it extraordinary. <br><br> It might start as a carnival, a relay race, a camp fire, a dance or soccer game but then… we suddenly dress up, act goofy and let it all hang out. <br><br> The bottom line is: <strong>We know how to play</strong>.
								</p>
							</div>

							<div class="home-content-block clearfix"><img class="" src="http://uploads.webflow.com/5829dbd5bb1a1e38054cf463/58415972b2a9ecab03f57d68_freedom.jpg" width="241"><h2 class="right">Freedom</h2><p class="right">Camp is a time to <strong>break away from rigid schedules</strong>. Campers choose two supervised activities every morning that last a few days. <br><br>They have <strong>structured free time every afternoon</strong> where they choose from a menu of possibilities. Once a week, <strong>cabin groups plan their own day of activity</strong>.</p></div>

							<div class="home-content-block clearfix"><img class="left" src="http://uploads.webflow.com/5829dbd5bb1a1e38054cf463/58415972b2a9ecab03f57d68_freedom.jpg" width="241"><h2 class="right">Individual Attention</h2><p class="right"><strong>Before your child even attends camp, we do our best to visit your home to get to know you.</strong> We try to match up your child with a “buddy camper” from your town. We constantly consult with a camper’s parents, counselors and his/her friends at camp.<br><br> We keep tabs on how each camper is adjusting and experiencing camp. We observe campers, talk with them and do our best to develop relationships. In this way, over days and even years, each individual camper’s strengths come to light.</strong>.</p></div>

							<div class="home-content-block clearfix"><img class="" src="http://uploads.webflow.com/5829dbd5bb1a1e38054cf463/5841597c34f6093632ab503b_personal-development.jpg" width="241"><h2 class="">Personal Development</h2><p>Staff guide campers activity choices and <strong>encourage them to try new things</strong>: a mountain bike ride in the woods, fishing, zip lining A camper might read a poem in front of 100 people, speak out in a cabin discussion, lead a dance group or come up with an activity of his/her own. <br><br><strong>Campers are recognized and encouraged at our “formation” meeting twice a day</strong>. Counselors create a safe and respectful environment that allows campers to make friendships and resolve cabin conflicts.</p></div>

							<div class="home-content-block clearfix"><img class="left" src="http://uploads.webflow.com/5829dbd5bb1a1e38054cf463/584159862f6a649d0351b386_community.jpg" width="241"><h2 class="right">Meaningful Community Living</h2><p class="right">We have <strong>weekly values based campfires</strong> that inspire our campers to make a difference at camp and in the larger world. We have opportunities for community service. <br><br><strong>We grow food on our small farm and carefully raise animals.</strong> Campers might decide to build a new cook out site or paint a cabin. We compost waste, recycle what we can and minimize our use of natural resources. We do our best to care for each other and our natural environment.</p></div>
								
						</div>
						<!--end topContentWrapper-->
															
						<div class="hpBottomSection">
							
							<h2 class="facebook-feed-heading">Fresh from Facebook</h2>

							<div class="facebook-posts-wrapper">

								<!-- <div class="facebook-post-wrapper">
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
								</div> -->

								<?php 
								// fetch the json displayed on the service page
								$fb_events_json = file_get_contents('https://graph.facebook.com/v2.8/270670676412/posts?access_token=1590125341012914|oljz2LZ1NBiXuqy0yacc5yBhwHk&limit=10');

								// transform it into a php array
								$fb_events_obj = json_decode($fb_events_json, true);

								//print_r($fb_events_obj);

								 //usort($fb_events_obj['data'], function($a, $b) {
								 //  return (strtotime($a['start_time']) < strtotime($b['start_time']) ? -1 : 1);
								// });

								$postCount = 0;

								foreach ($fb_events_obj['data'] as $event) : 
								
								$postCount++;
								if ($postCount == 3) {
									break;
								}
								if (!$event['message']) {continue;}?>

								<div class="facebook-post-wrapper">
									<h4 class="fb-post-title"><?= date("M d Y", strtotime($event['created_time'])); ?></h4>
									<?php 
									$post_id = substr($event['id'], 13);
									$fb_post_image_json = file_get_contents('https://graph.facebook.com/'.$post_id.'?access_token=1590125341012914|oljz2LZ1NBiXuqy0yacc5yBhwHk&fields=source'); 
									$fb_post_image = json_decode($fb_post_image_json, true);
									?>
									<?php if ($fb_post_image['source']): ?>
										<img class="facebook-post-image" src="<?= 	$fb_post_image['source'] ?>">
									<?php endif ?>
									
									<p class="fb-post-text"><?= $string = preg_replace('/(http|https|ftp|ftps)\:\/\/[a-zA-Z0-9\-\.]+\.[a-zA-Z]{2,3}(\/\S*)?/', '<a href="$0" target="_blank" title="$0">Click Here for the Link</a>', $event['message']) ?>
									<br><a href="http://www.facebook.com/270670676412/posts/<?= $post_id ?>" class="fb-post-link" target="_blank">See on Facebook</a></p>
								</div>

								<?php endforeach ?>

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