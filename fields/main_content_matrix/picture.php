<?php $options = array(
  'quality' => 90,
  'upscaling' => false
); ?>

<?php switch ($page->image_alignment_matrix) {
	case '1':
		$imageWidth = 291;
		break;
	case '2':
		$imageWidth = 291;
		break;
	case '3':
		$imageWidth = 367;
		break;
	case '4':
		$imageWidth = 582;
		break;
	default:
		

		break;
} ?>

<figure class="<?= $page->image_alignment_matrix->value ?>">
    <img src='<?= $page->image_matrix->first()->width($imageWidth, $options)->url ?>' alt='<?= $page->image_matrix->first()->description ?>' />
    <figcaption><?= $page->title ?></figcaption>
</figure>