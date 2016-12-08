<?php
/**
 * Render blog archives for a given year
 *
 * Used by the /site/templates/archives.php template.
 *
 * Variables provided:
 * 
 * $year - The year being rendered (integer)
 * $total - The total number of posts in this year (integer)
 * $url - URL to this page (string)
 * $months - An array of months in this format: 
 *	array(
 *		1 => array(
 * 			'name' => 'January', 
 *			'url' => '/archives/2012/01/',
 *			'posts' => PageArray, // containing first few posts
 *			'total' => 5 // total # of posts in month
 *		),
 *		2 => array(
 *			'name' => 'February',
 *			...and so on
 *		)
 *	);
 *
 */
?>



	<li>
		<a href='<?php echo $url; ?>'><?php echo $year." (".sprintf(_n('%d post', '%d posts', $total), $total).")"; ?></a> 
		
		<!--<ul>

		<?php foreach($months as $monthNum => $month): ?>

		<li>
			<a href='<?php echo $month['url']; ?>'><?php echo $month['name'].' ('.sprintf(_n('%d post', '%d posts', $month['total']), $month['total']).')'; ?></a>
			

			<?php if(count($month['posts'])): // posts will be empty if $blog->archives() call specified 0 for limit; ?>

			<ul>
				<?php foreach($month['posts'] as $item): ?>
				<li><a href='<?php echo $item->url; ?>'><?php echo $item->title; ?></a></li>
				<?php endforeach; ?>
				
				<?php if($month['total'] > count($month['posts'])): ?>
				<li><a class='more' href='<?php echo $month['url']; ?>'><?php echo __('View All'); ?></a></li>
				<?php endif; ?>
			</ul>

			<?php endif; ?>

		</li>

		<?php endforeach; ?>

		</ul>-->

	</li>

	



