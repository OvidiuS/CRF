<?php require($config->paths->templates."includes/functions.inc") ?>
<!DOCTYPE html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7"> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8"> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js"> <!--<![endif]-->
<head> 
    <meta charset="utf-8" />
    <!--[if IE]><meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" /><![endif]-->
    <title><?= $page->get("seo_title|headline|title") ?></title>
    <link rel="dns-prefetch" href="//ajax.googleapis.com">
    <meta name="keywords" content="<?= $page->seo_keywords ?>" />
    <meta name="description" content="<?= $page->seo_description ?>" />
    <meta name="viewport" content="width=device-width, maximum-scale=1.0, initial-scale=1,  user-scalable=1"/>
    
    <meta property="og:title" content="<?= $page->get("seo_title|headline|title") ?>"/>


    <!-- <link rel="stylesheet" href="<?php echo AIOM::CSS(array('css/style.css', 'css/flexslider.css', 'css/jquery.fancybox.css')); ?>"> -->
	<link rel="stylesheet" href="/site/templates/css/main.css">
	<link rel="stylesheet" href="/site/templates/css/flexslider.css">
	<link rel="stylesheet" href="/site/templates/css/jquery.fancybox.css">
	<link rel="stylesheet" href="/site/templates/css/sm-core-css.css">
	<link rel="stylesheet" href="/site/templates/css/sm-clean.css">
	
    <script src="<?= $config->urls->templates?>js/modernizr-2.6.2.min.js"></script>
    <!--google fonts go here -->
    <link href='https://fonts.googleapis.com/css?family=Archivo+Narrow:400,400italic,700italic,700|Oswald:400,700,300|Droid+Sans:400,700' rel='stylesheet' type='text/css'>
    
    <link rel="apple-touch-icon" sizes="57x57" href="<?= $config->urls->root?>apple-icon-57x57.png">
	<link rel="apple-touch-icon" sizes="60x60" href="<?= $config->urls->root?>apple-icon-60x60.png">
	<link rel="apple-touch-icon" sizes="72x72" href="<?= $config->urls->root?>apple-icon-72x72.png">
	<link rel="apple-touch-icon" sizes="76x76" href="<?= $config->urls->root?>apple-icon-76x76.png">
	<link rel="apple-touch-icon" sizes="114x114" href="<?= $config->urls->root?>apple-icon-114x114.png">
	<link rel="apple-touch-icon" sizes="120x120" href="<?= $config->urls->root?>apple-icon-120x120.png">
	<link rel="apple-touch-icon" sizes="144x144" href="<?= $config->urls->root?>apple-icon-144x144.png">
	<link rel="apple-touch-icon" sizes="152x152" href="<?= $config->urls->root?>apple-icon-152x152.png">
	<link rel="apple-touch-icon" sizes="180x180" href="<?= $config->urls->root?>apple-icon-180x180.png">
	<link rel="icon" type="image/png" sizes="192x192"  href="<?= $config->urls->root?>android-icon-192x192.png">
	<link rel="icon" type="image/png" sizes="32x32" href="<?= $config->urls->root?>favicon-32x32.png">
	<link rel="icon" type="image/png" sizes="96x96" href="<?= $config->urls->root?>favicon-96x96.png">
	<link rel="icon" type="image/png" sizes="16x16" href="<?= $config->urls->root?>favicon-16x16.png">
	<link rel="manifest" href="<?= $config->urls->root?>manifest.json">
	<meta name="msapplication-TileColor" content="#ffffff">
	<meta name="msapplication-TileImage" content="<?= $config->urls->root?>ms-icon-144x144.png">
	<meta name="theme-color" content="#ffffff">

</head>