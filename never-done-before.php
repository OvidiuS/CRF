<?php 

// first choose what content you want to show, setting the $contentTemplateName variable to the name of the file that contains your content
// this can be as simple as static HTML or as dynamic as a Typical Day module
// content templates must all reside in {pw-root}/site/templates/content-templates/name-of-content-template.inc
// if you don't specify any content, the layput template will appear empty

$contentTemplateName = "./content-templates/never-done-before-content.inc";


// next choose a layput for your content, like single-column, left-column, right-column, etc 
// layout templates are all located in {pw-root}/site/templates/layout-templates/ , so go have a look at what's available, or create a new one.

include("./layout-templates/single-column-layout.inc");


// with the 2 lines of code above, we're saying we want to load the typical-day content into a page with a single column layout.
?>