<!DOCTYPE html>
<html class="no-js"> 
<head> 

    <title><?= $page->get("headline|title") ?></title>

    

</head>

<body>
									
<?php echo $page->blog_comments->render(); 
echo $page->blog_comments->renderForm(); ?>
				
</body>
</html>