<? include($site->config->templates."includes/head.inc"); ?>

<body>
<? include($site->config->templates."includes/header.inc"); ?>
					
					<div class="singleColumnWrapper">
						
						<?php require($contentTemplateName); ?>
						
					</div>
					<!--end singleColumnWrapper--> 
					
<? include($site->config->templates."includes/foot.inc"); ?>
</body>
</html>