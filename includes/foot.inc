
			</div>
			<!--end containerRightWrapper--> 
		</div>
	<!--end containerLeftWrapper-->
	</div>
	<!--end bodyWrapper-->

<footer>
		<div class="footerWrapper">
			<div class="footer">
				<div class="footerLeft">
					<nav>
						<ul  id="footerMenu">
							<?php
                        		$homepage = $pages->get("/"); 
								$footerMenuPages = $homepage->footer_menu_pages;
								$footerMenuPages->prepend($homepage); 
								
								foreach($footerMenuPages as $child) {
									$class = $child === $page->rootParent ? " class='active'" : '';
									echo "<li$class><a href='{$child->url}'>{$child->title}</a></li>";
								}
                        	?>
						</ul>
					</nav>
					
					<div class="vcard">
						<div class="tel">Call Now <?= $pages->get(1)->phone_no ?><!-- <br />Vendors: <?= $pages->get(1)->flickr_url ?> --></div>
						<div class="org"><?= $pages->get(1)->org_name ?></div>
							Joe Mendes, Owner/Director: <a class="email" href="mailto:<?= $pages->get(1)->contact_email ?>"><?= $pages->get(1)->contact_email ?></a> <br/>
							Debbie Collins, Associate Director: <a href="mailto:debbie@camprooseveltfirebird.com">debbie@camprooseveltfirebird.com</a>
							<div class="adr">
							<div class="street-address"><?= $pages->get(1)->street_address ?></div>
							<span class="locality"><?= $pages->get(1)->locality ?></span>, 
							<span class="region"><?= $pages->get(1)->region_name ?></span>&nbsp;
							<span class="postal-code"><?= $pages->get(1)->postal_code ?></span>&nbsp;&nbsp;
							<span class="country-name"><?= $pages->get(1)->country ?></span>
						</div>
						
					</div>
					<!-- <div class="campAccredited">
						<img  id="accredited" src="<?php echo $config->urls->templates?>images/accreditedOld.png" alt="accredited"/>
						<p class="accredited">Accredited member of the American Camp Association</p>
					</div>  -->
					
				</div>
				
				<!--end footerLeft-->
				
				<div class="footerRight"> 
					<? include("./includes/newsletter_form.inc"); ?>
					<div class="socialMedia">
						<a class="twitter" href="https://twitter.com/camp_firebird">
							<img src="<?php echo $config->urls->templates?>images/twitter_57.png" alt="twitter"/>
						</a>
						<a href="http://www.youtube.com/user/FirebirdRoosevelt">
							<img src="<?php echo $config->urls->templates?>images/youtube_57.png" alt="youtube"/>
						</a>
						<a href="https://www.facebook.com/pages/Camps-Firebird-Roosevelt/270670676412"><img src="<?php echo $config->urls->templates?>images/facebook_57.png" alt="facebook"/></a> 
						
					</div><p style="clear: both;">Copyright ©<?= $copyYears = (date("Y")>2013)? "2013-".date("Y") : date("Y")?> <?= $pages->get(1)->org_name; ?>.<br/><a href="http://www.dvscampwebsites.com">Camp website by DVS Camp Websites</a></p>
				</div>
				
				<!--end footerRight--> 
				
			</div>
			<!--end footer-->
			<div class="footerBanner"></div>
			<div class="grass"></div>
		</div>
		<!--end footerWrapper--> 
	</footer>
	<?php 

	// If the page is editable, then output a link that takes us straight to the page edit screen:
	if($page->editable() && $page->id!="1") {
		echo "<a class='nav' id='editpage' href='{$config->urls->admin}page/edit/?id={$page->id}'>Edit</a>"; 
	}

	?>
	
	<!-- CLOSE all html-elements (+wrapper) before this line -->
       <script src="<?php echo AIOM::JS(array('js/jquery.min.js', 'js/plugins.js', 'js/jquery.flexslider-min.js', 'js/jquery.fancybox.pack.js', 'js/jquery.fancybox-media.js', 'js/scripts.js')); ?>"></script>
        
        <!-- Google Code for alidm20.com -->
		<!-- Remarketing tags may not be associated with personally identifiable information or placed on pages related to sensitive categories. For instructions on adding this tag and more information on the above requirements, read the setup guide: google.com/ads/remarketingsetup -->
		<script type="text/javascript">
		/* <![CDATA[ */
		var google_conversion_id = 952069528;
		var google_conversion_label = "NGPWCOXi-VoQmNv9xQM";
		var google_custom_params = window.google_tag_params;
		var google_remarketing_only = true;
		/* ]]> */
		</script>
		<script type="text/javascript" src="//www.googleadservices.com/pagead/conversion.js">
		</script>
		<noscript>
		<div style="display:inline;">
		<img height="1" width="1" style="border-style:none;" alt="" src="//googleads.g.doubleclick.net/pagead/viewthroughconversion/952069528/?value=1.00&amp;currency_code=USD&amp;label=NGPWCOXi-VoQmNv9xQM&amp;guid=ON&amp;script=0"/>
		</div>
		</noscript>

        <!--GA tracking code goes here -->
<script>
  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');


  ga('create', 'UA-70897004-1', 'auto');
  ga('send', 'pageview');


</script>