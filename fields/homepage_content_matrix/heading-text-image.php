							<div class="home-content-block clearfix">
								<img class="<?= $page->left_right->title?>" src="<?= $page->innerPageBanner->getCrop("homepage_image")->url ?>">
								<h2 class=""><?= $page->title ?></h2>
								<div class="<?= $page->left_right->title == 'left' ? 'right' : 'left' ?>"> <?= $page->rich_text; ?></div>
							</div>