<div class="bodyWrapper">
	<div class="topHeaderWrapper"> </div>
	
	<!--end topHeaderWrapper-->
		<div class="containerLeftWrapper">
			<div class="containerRightWrapper">
				<div class="container">
					<header>
						<div class="header">

							<div class="lefttopHeader">
								<a href="#">Join Our Email <br>Newsletter</a>
							</div>
							<!--end lefttopHeader--> 

							<div id="boots"></div>
							<a class="centertopHeader" href="/">
								<img src="<?= $config->urls->templates?>images/Camp-Roosevelt-Firebird-Logo.png" alt="Camp Roosevelt-Firebird Logo"/>
							</a> 
							<!--end centertopHeader-->

							<div class="rightHeader">
								<a class="rightHeaderContent" href="https://www.ultracamp.com/clientlogin.aspx?idCamp=426&amp;campCode=CFR" target="_blank">
									<span>Sign Up Now</span>
								</a>
							</div>
							<!--end rightHeader-->

							<div class="righttopHeader">
								<!-- <a href="#" target="_blank">Parent login /</a> --> 
								<a href="tel:<?= $pages->get(1)->phone_no ?>" target="_blank">Call Now <?= $pages->get(1)->phone_no ?></a><!--  | <a href="<?= $pages->get(1053)->url ?>">Blog</a> -->
							</div>
							<!--end righttopHeader--> 

							<div id="oars"><img id="oarsText" src="<?php echo $config->urls->templates?>images/oarsText.png" alt="text"/></div>

							<div id="binoculars"></div> 
							
							<div class="navBanner">
								
								<nav>
                        			<?php
											
                        					$homepage = $pages->get("/"); 
											$mainMenuPages = $homepage->main_menu_pages;
											$mainMenuPages->prepend($homepage); 

											$mainMenu = $modules->get("MarkupSimpleNavigation");
											
											$mainMenuOptions = array(
												'levels' => true,
												'levels_prefix' => 'level-',
												'max_levels' => 3,
												'outer_tpl' => '<ul id="mainMenu" class="mainMenu sm sm-clean">||</ul>',
												'item_tpl' => '<a href="{url}"><span>{title}</span></a>',
												'item_current_tpl' => '<a href="{url}">{title}</a>'
											);
											foreach ($mainMenuPages as $item) {
												echo $item->tile;
											}
											echo $mainMenu->render($mainMenuOptions,null,$mainMenuPages);

                        			?>
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