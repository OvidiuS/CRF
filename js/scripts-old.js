// homepage main slider.
$('.slideshowWrapper .slideshow').flexslider({
    animation: "slide",
    directionNav: true,
    controlNav: false,
    start: function(slider){
        $('body').removeClass('loading');
    }
});

$("a[rel^='prettyPhoto']").prettyPhoto();

// Function for animating the FAQs
    $questions = $('h3.faq_question a');
	$answers = $('div.faq_answer');
	$answers.hide();

	$questions.click(function() {

		if ($(this).parent().next().is(":hidden")) {
	    	$answers.hide();
	    	$(this).parent().next().slideDown();
		}else{
			$(this).parent().next().slideUp();
		}
		return false;
});
// i've never done that before.
$('.neverDoneBefore .imagesHolderNDB').cycle({
        fx:'fade',
		timeout: 10000,
        next: '.arrowRight',
        prev: '.arrowLeft'
	});

// What's New For Me This Summer
$('#newAgeGroup1,#newAgeGroup2,#newAgeGroup3').hide();

$('div.whatsNewHeader ul li a').click(function(){
    $('div.whatsNewHeader ul li a').removeClass('active');
    $(this).addClass('active');
    
    $('div#' + $(this).parent().attr("class") + ' div.whatsNewSlidesow').cycle(0);
	$('div.whatsNewSlideWrapper').hide();
	$('div#'+$(this).parent().attr("class")).fadeIn(1000);
	return false;
});

$('.whatsNewSlidesow').cycle({
		fx: 'scrollHorz',
		pager:  $(this).find('.whatsNewPager'),
		timeout: 3000
		//prev: $("a.arrowLeft"),
		//next: $("a.arrowRight")
		//easing: 'easeInOutCirc'
	});	


// *****************************
// typical day slideshow
//******************************

$('.tdSlideShow img').jail({event:'click'});

// here we set the data placeholders to their defaults
$('body').data('selGender', 'notSet');
$('body').data('selAge', 'notSet');


// this function handles updating the main display area based on what buttons the users push
// it either displays the proper error message or one of the slideshows
// it takes it's parameters from the 2 data properties selGender and selAge
function updateSlideshow(selectedGender,selectedAge) {
	//alert('gender is: ' + selectedGender + ' and  age is: ' + selectedAge);
	if (selectedGender == 'notSet') {
		$('div.genderError').show().siblings().hide();
	}else if (selectedAge == 'notSet') {
		$('div.ageError').show().siblings().hide();
	}else{
		//alert('gender is: ' + selectedGender + ' and  age is: ' + selectedAge);

		// next we show the correct slideshow and reset it then hide all others
		$('div#slideShow-' + selectedGender + '-' + selectedAge).siblings().hide();
		$('div#slideShow-' + selectedGender + '-' + selectedAge).cycle(0).fadeIn(1000);

		// load the first slide's description in the HTML
		 $('.slideDescription').html( '<p>' + $('.tdSlideShow:visible img:first').attr('data-description') + '</p>');

		$('#tdSlideShowNav').removeClass();// this makes the "Inactive" styling go away
		$('div.tdSlideshowNavCover').css("display", "none"); // and moves the blinder div up so we can now click on the nav buttons
		// we show the slide description and vertically align the text within
		$('div.slideDescription').show().children('p').vAlign();
		// also make the previous and next buttons visible now
		$('a#prev2, a#next2').show();

		// we trigger the preloading of the images inside of the slideshow
		$('#slideShow-' + selectedGender + '-' + selectedAge + ' img').click();
		// and we make the first nav button active.
		$('#tdSlideShowNav li:first').addClass('activeSlide').siblings().removeClass();
	};

}
// below are the two click handlers, one for age one fore gender
$('ul.genderSelector li a').click(function(){
	$('ul.genderSelector li a').removeClass();
	$(this).addClass('tdButtonSelected');
	$('body').data('selGender', $(this).attr('id'));
	updateSlideshow($('body').data('selGender'),$('body').data('selAge'));
	return false;
});
$('ul.ageSelector li a').click(function(){
	$('ul.ageSelector li a').removeClass();
	$(this).addClass('tdButtonSelected').siblings().removeClass();
	$('body').data('selAge', $(this).attr('id'));
	updateSlideshow($('body').data('selGender'),$('body').data('selAge'));
	return false;
});

// this part initializes all the 6 slideshows
$('.tdSlideShow').cycle({
	fx: 'shuffle',
	speed: 700,
	timeout: 0,
	nowrap: 1,
	easing: 'easeInOutCirc',
	after:     function() {

            $('.slideDescription').html( '<p>' + $(this).attr('data-description') + '</p>');
            $('.slideDescription p').vAlign();// we center the description vertically
        }
});

// below are the click handlers for the previous & next buttons
$('#prev2').click(function(){
	//alert ($('#tdSlideShowNav li').index($('.activeSlide')));
	var currentSlideIndex = $('#tdSlideShowNav li').index($('.activeSlide'));
	if (currentSlideIndex>0) {
		$('#tdSlideShowNav li').removeClass();
		$('.tdSlideShow:visible').cycle('prev');
		$('#tdSlideShowNav li:nth-child(' + currentSlideIndex +')').addClass('activeSlide');
		return false;
	};
	return false;
});
$('#next2').click(function(){
	var currentSlideIndex = $('#tdSlideShowNav li').index($('.activeSlide'));
	if (currentSlideIndex<5) {
		var nextSlideIndex = currentSlideIndex + 2;
		$('#tdSlideShowNav li').removeClass();
		$('.tdSlideShow:visible').cycle('next');
		$('#tdSlideShowNav li:nth-child(' + nextSlideIndex +')').addClass('activeSlide');
		return false;
	};
	return false;
});

// and this part  is for the slideshow navigation
$('#tdSlideShowNav li a').each(function(index){
	$(this).click(function(){
		$(this).parent().addClass('activeSlide').siblings().removeClass();
		$('.tdSlideShow:visible').cycle(index);
		return false;
	});
});
// end typical day page code