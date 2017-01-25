							<div class="home-content-block clearfix">
								<img class="<?= $page->left_right?>" src="<?= $page->image_matrix->first()->width(371)->url ?>">
								<h2 class=""><?= $page->title ?></h2>
								<div class="<?= $page->left_right == 'left' ? 'right' : 'left' ?>"> <?= $page->rich_text; ?></div>
							</div>