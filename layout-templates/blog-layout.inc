<? include($config->paths->templates."includes/head.inc"); ?>

<body>
<? include($config->paths->templates."includes/header.inc"); ?>
					
		<div class="contentTwoCollumns blogContent">
			<div class="menuBgLeft contentLeft">
				<div class="menuBgRight">
				<div id="menuDropdown" class=""> 
						<span>Select a page...</span>
					</div>
					<div id='leftMenu'>
						<div class='widget'>
							<?php include_once('./includes/blog.inc');  ?>
							<?php $limit = 5; 
								$posts = $pages->find("template=blog-post, sort=-date, start=0, limit=$limit");	
								$parent = null;
								$out = '';
								
								foreach($posts as $item) {
									$date = date('F j Y',strtotime($item->date));
									$out .= "<li><span class='date'>$date</span> <a href='{$item->url}'>{$item->title}</a></li>";
									$parent = $item->parent; 
								}
								
								if($out) {
									$out = 	"<h4>Recent Posts</h4>" . 
										"<ul class='recent-posts links'>$out</ul>" . 
										"<p>" . 
										"<a class='more' href='{$parent->url}'>" . __('More') . "</a> " . 
										"<a class='rss' href='{$parent->url}rss/'>" . __('RSS') . "</a>" . 
										"</p>";
									echo $out; 
								} else {
									echo "<p>No recent posts</p>";
								} 
							?>
						</div>
						<!-- end widget recent posts-->
						<div class='widget'>
						<?php
							echo renderArchivesForSidebar(getArchives());
						?>
						</div>
						<!-- end widget archives-->
						<div class='widget'>
						<?php
							$blogposts = $pages->get( "/blog/posts/" )->children;

							$comments = array();
							
							foreach( $blogposts as $blogpost ) {
							
							    foreach($blogpost->blog_comments as $comment) {
							        if($comment->isApproved()) {
							
							            array_push($comments, array("comment"=>$comment, "post"=>$blogpost));
							
							        }
							    }
							}
							
							if($comments) {
							    $out = "<h4>Latest comments</h4>";
							    $out .= "<ul>";
							
							    arsort($comments);
							
							    $num_comments = 0;
							
							    foreach($comments as $comment) {
							        $cite = htmlentities($comment["comment"]->cite);
							        $text = $summary = strip_tags(substr(htmlentities($comment["comment"]->text), 0, 100)).'...';
							        $date = date("j M 'y ", $comment["comment"]->created);
							        $comment_parent_url = $comment["post"]->url . "#Comment" . $comment["comment"];
									$comment_parent_title = $pages->get($comment["post"]->url)->title;

							        $out .= "<li><span class='sidebarCommentDate'>{$date}</span><a href='{$comment_parent_url}'><span class='sidebarComentTitle'>{$comment_parent_title}</a>";
							        $out .= "<span class='sidebarCommentAuthor'><strong>{$cite}</strong> said: ";
							        $out .= "{$text}</span></li>";
							
							        $num_comments++;
							        if($num_comments == 3) break;
							    }
							
							    $out .= "</ul>";
							    echo $out;
							
							} else {
							    echo "<p>No comments.</p>";
							}
						?>
						</div>
						<!-- end widget archives-->
					</div>
					<!-- end #leftMenu -->
				</div>
				<!-- end .menuBgRight -->
			</div>
			<!-- end .menuBgLeft-->
			
			<div class="contentRight">
				<div class="mainContentInnerBlog">
					<?php require($contentTemplateName); ?>
				</div>
				<!-- end mainContentInner-->
			</div>
			<!--end contentRight-->
			<div class="contentLeft">
				<div class="boxWrapperInner">
					<div class="videoBoxInner"><a href="<?= $pages->get(1)->main_video ?>" class="mainVideo"> <img  id="videoBackgroundInner" src="<?= $config->urls->templates?>images/videoBackground.png" alt="videobg"/> <img  id="movieFilmInner" src="<?= $config->urls->templates?>images/movieFilm.png" alt=" "/> <span>Watch Our Video</span></a>
					</div>
					<!--end videoBoxInner-->
					
					<ul class="imageBoxWrapperInner">
						<li class="imageBoxleftInner"><a href="<?= $pages->get(1307)->url ?>">
								<img  id="campDayInner" src="<?= $config->urls->templates?>images/campDayInner.png" alt="Typical Day Button"/>
								<span>Camper Growth &amp; Development</span>
							</a>
						</li>
						<!--end imageBoxleftInner-->
						
						<li class="imageBoxcenterInner"><a href="<?= $pages->get(1320)->url ?>">
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
				</div>	
<? include($config->paths->templates."includes/foot.inc"); ?>
</body>
</html>