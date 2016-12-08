<?php 
include($site->config->templates."includes/head.inc"); ?>

<body>
<?php include($site->config->templates."includes/header.inc"); ?>
		<div class="contentTwoCollumns">
			<?php if($page->rootParent->numChildren): ?>
			<div class="menuBgLeft contentLeft">
				<div class="menuBgRight">
					<div id="menuDropdown" class=""> 
						<span>Select a page...</span>
					</div>
					<?php
						$sideMenuOptions = array(
							'outer_tpl' => '<ul id="leftMenu">||</ul>',
							'list_tpl' => '<li%s>||<span class="arrow"></span></li>',
							'current_class' => 'active',
							'inner_tpl' => '<ul class="secondMenu">||</ul>',
							'item_tpl' => '<a href="{custom_url|url}">{title}</a>'
							);
						$treeMenu = $modules->get("MarkupSimpleNavigation"); // load the module
						echo $treeMenu->render($sideMenuOptions, null, $page->rootParent); // render default menu
					?>
				</div>
				<!-- end .menuBgRight -->
			</div>
			<!-- end .menuBgLeft-->
			<?php endif; ?>
			
			<div class="contentRight">
				
				<div class="headerImageWrapper">

    				<img class='photo' src="<?= $page->innerPageBanner ? $page->innerPageBanner->getCrop('banner_size')->url : 'http://dummyimage.com/601x248&text=header%20image%20here' ?>" alt='<?= $page->innerPageBanner->description ?>' />
    						
				</div>
				<!--end headerImageWrapper-->
				<div class="mainContentInner">
					<?php require($contentTemplateName); ?>
				</div>
				<!-- end mainContentInner-->			
						</div>
			<!--end contentRight-->
			<div class="contentLeft">
				<div class="boxWrapperInner">
					<div class="videoBoxInner"><a href="<?= $pages->get(1)->main_video ?>&autoplay=1&rel=0" class="mainVideo"> <img  id="videoBackgroundInner" src="<?= $config->urls->templates?>images/videoBackground.png" alt=" "/> <img  id="movieFilmInner" src="<?= $config->urls->templates?>images/movieFilm.png" alt=" "/> <span>Watch Our Video</span></a>
					</div>
					<!--end videoBoxInner-->
					
					<ul class="imageBoxWrapperInner">
						<li class="imageBoxleftInner">
							<a href="<?= $pages->get(1307)->url ?>">
								<img  id="campDayInner" src="<?= $config->urls->templates?>images/campDayInner.png" alt="Typical Day Button"/>
								<span>Camper Growth &amp; Development</span>
							</a>
						</li>
						<!--end imageBoxleftInner-->
						
						<li class="imageBoxcenterInner">
							<a href="<?= $pages->get(1320)->url ?>">
								<img  id="interactiveMapInner" src="<?= $config->urls->templates?>images/neverDoneBeforeInner.png" alt="Interactive Map Button"/>
								<span>I've Never Done That Before</span>
							</a>
						</li>
						<!--end imageBoxcenterInner-->
					
						<li class="imageBoxrightInner">
							<a href="/fullscreen-gallery/" target="_blank">
								<img  id="photoGalleryInner" src="<?= $config->urls->templates?>images/photoGaleryInner.png" alt="Gallery Button"/>
								<span>View our Photo Gallery</span>
							</a>
						</li>					
						<!--end imageBoxrightInner-->
					</ul>
					<!--end imageBoxWrapperInner--> 
				</div>
				<!--end boxWrapperInner--> 
			</div>
			<!--end contentLeft--> 
		
		</div>
		<!--end contentTwoCollumns-->
<?php include($site->config->templates."includes/foot.inc"); ?>
</body>
</html>