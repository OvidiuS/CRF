<? include($config->paths->templates."includes/head.inc"); ?>

<body>
<? include($config->paths->templates."includes/header.inc"); ?>
					
					<div class="singleColumnWrapper">
						
						<?php require($contentTemplateName); ?>
						
					</div>
					<!--end singleColumnWrapper--> 
					
<? include($config->paths->templates."includes/foot.inc"); ?>
</body>
</html>