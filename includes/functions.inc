<?php 
// extracts part of a longer block of text; if the tags are to be on/off the stripTags paramenter will do it
function extractText($fieldName, $wordsNo, $stripTags) {
	$bar = explode(" ", $stripTags=="on" ? strip_tags($fieldName) : strip_tags($fieldName, '<p><a><h3><h2><h1><span><div><img><strong><em><br />'));
	$failSafe = count($bar);
	(int)$wordCount = 1;
	if($failSafe>=$wordsNo) $wordCount = $wordsNo; else $wordCount = $failSafe-1;
	$excerpt = '';
	for($x=0; $x<$wordCount; $x++){
		$excerpt .= $bar[$x]." ";
	};
	$excerpt = rtrim($excerpt);
	if(substr("$excerpt", -1)=="."||substr("$excerpt", -1)==","||substr("$excerpt", -1)==";"||substr("$excerpt", -1)==":") $excerpt = substr($excerpt, 0, -1);
	$excerpt .= " ...";
	return $excerpt;
}
