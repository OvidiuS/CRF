<div class="bodyWrapper">
	<div class="topHeaderWrapper"> </div>
	
	<!--end topHeaderWrapper-->
		<div class="containerLeftWrapper">
			<div class="containerRightWrapper">
				<div class="container">
					<header>
						<div class="header">
								<div class="lefttopHeader"> <a href="<?= $pages->get(1059)->url ?>"> Joe's Tales from the Off-Ramp </a> </div>
								<!--end lefttopHeader--> 
								<div id="boots"></div> <a class="centertopHeader" href="/"> <img src="<?= $config->urls->templates?>images/FirebirdRoosevelt-Logos.png" alt="Camp Firebird Roosevelt Logo"/></a> 
								<!--end centertopHeader-->

							<div class="rightHeader"> <a  class="rightHeaderContent" href="https://www.ultracamp.com/clientlogin.aspx?idCamp=426&amp;campCode=CFR" target="_blank"><span>Sign Up Now</span></a>
								<p><a href="tel:<?= $pages->get(1)->phone_no ?>">Call Now <?= $pages->get(1)->phone_no ?></a><!-- <br />Vendors: <?= $pages->get(1)->flickr_url ?>  --></p>
							</div>
							
							<!--end rightHeader-->
							<div class="righttopHeader"> <!-- <a href="#" target="_blank">Parent login /</a> --> 
							<a href="http://www.ultracamp.com/info/campcontact.aspx?idCamp=426&amp;campCode=CFR" target="_blank">Request Info</a><!--  | <a href="<?= $pages->get(1053)->url ?>">Blog</a> --> </div>
								<!--end righttopHeader--> 
							<div id="oars"><img id="oarsText" src="<?php echo $config->urls->templates?>images/oarsText.png" alt="text"/> </div>
							<div id="binoculars"></div> 
							<div class="navBanner">
								
								<nav>
                        			<ul class="mainMenu">
										<?php
											
                        					$homepage = $pages->get("/"); 
											$mainMenuPages = $homepage->main_menu_pages;
											$mainMenuPages->prepend($homepage); 
											
											foreach($mainMenuPages as $child) {
												$class="";
												if($page->rootParent->id == $child->id): 													$class = " class='active'"; 
												endif;
												//$class = $child === $page->rootParent ? " class='active'" : '';
												echo "<li".$class." data-id='{$child->id}' data-id01='{$page->id}'><a href='{$child->url}'><span>{$child->title}</span></a></li>";
											}
                        				?>
									</ul>
                    			</nav>
								<div id="leftBanner"></div>
								<div id="rightBanner"></div>
								
							</div>
							<!--end navBanner--> 
							<div class="topBoard"></div>
							
						</div>
						<!--end header--> 
						
					</header>
					<!--end head.inc-->