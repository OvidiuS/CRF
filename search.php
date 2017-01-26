<?php

/**
 * Search template
 *
 */

$out = '';

if($q = $sanitizer->selectorValue($input->get->q)) {

	// Send our sanitized query 'q' variable to the whitelist where it will be
	// picked up and echoed in the search box by the head.inc file.
	$input->whitelist('q', $q); 

	// Search the title, body and sidebar fields for our query text.
	// Limit the results to 50 pages. 
	// Exclude results that use the 'admin' template. 
	$matches = $pages->find("title|body|main_content_matrix.rich_text~=$q,template!=blog-post,limit=50"); 

	$count = count($matches); 

	if($count) {
		$out .= "<h2>Found $count pages matching your query:</h2>" . 
			"<ul class='nav'>";

		foreach($matches as $m) {
			if ($m->main_content_matrix ) {
				foreach ($m->main_content_matrix as $matrix_block) {
					if ($matrix_block->type == "rich_text") {
						$m_summary = $matrix_block->rich_text;
						break;
					}
				}
				$m_summary = strip_tags($m_summary);
				$limit = 150;
				if(strlen($m_summary) >= $limit){
					$m_summary = substr($m_summary, 0, $limit);
					$pos = strrpos($m_summary, " ");
					if ($pos>0) {
				        $m_summary = substr($m_summary, 0, $pos);
				    }
				}
			}

			$out .= "<li><p><a href='{$m->url}'>{$m->title}</a><br />{$m_summary}...</p></li>";
		}

		$out .= "</ul>";

	} else {
		$out .= "<h2>Sorry, no results were found.</h2>";
	}
} else {
	$out .= "<h2>Please enter a search term in the search box</h2>";
}

// Note that we stored our output in $out before printing it because we wanted to execute
// the search before including the header template. This is because the header template 
// displays the current search query in the search box (via the $input->whitelist) and 
// we wanted to make sure we had that setup before including the header template. 


include($config->paths->templates."includes/head.inc");?>

<body>
<? include($config->paths->templates."includes/header.inc"); ?>
					
					<div class="singleColumnWrapper">
						<h1>Search</h1>
						<form id='search_form' action='<?php echo $config->urls->root?>search/' method='get'>
							<input type='text' name='q' id='search_query' value='<?php echo htmlentities($input->whitelist('q'), ENT_QUOTES, 'UTF-8'); ?>' />
							<button type='submit' id='search_submit'>Search</button>
						</form>
						<?php echo $out; ?>
						<br/><br/><br/><br/><br/><br/>
					</div>
					<!--end singleColumnWrapper--> 
</div>
<? include($config->paths->templates."includes/foot.inc"); ?>
</body>
</html>
