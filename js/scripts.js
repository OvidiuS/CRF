$(document).ready(function() {

// homepage main slider.
$('.slideshowWrapper .slideshow').flexslider({
    animation: "slide",
    directionNav: true,
    controlNav: false,
    start: function(slider){
        $('body').removeClass('loading');
    }
});
$('.javaSlideshow .miniSlideshow').flexslider({
    animation: "slide",
    directionNav: true,
    controlNav: false,
    controlsContainer: ".miniSlideButtonWrapper",
    start: function(slider){
        $('body').removeClass('loading');
    }
});

// anti-spam reverse honeypot
var $input = "<input type='hidden' name='crf_security_field' value='1' />";
	$("#CommentForm form").append($input);
	$("#CommentForm").show();

// menu dropdown for responsive
$("#menuDropdown").click(function(){
              $("#leftMenu").slideToggle("slow"); 
			     $(this).toggleClass("activeDropdown"); 
    });

// newsletter clear default field values

$("form input")
		.focus(function() {
			if (this.value === this.defaultValue) {
				this.value = '';
			}
		 })
		 .blur(function() {
			if (this.value === '') {
				this.value = this.defaultValue;
			}
		});

// blog lightbox for images
$("div.post-body a:has(>img)").fancybox({
          helpers: {
              title : {
                  type : 'float'
              }
          }
      });
// video link
$("a.mainVideo").click(function() {
    $.fancybox({
            'padding'       : 0,
            'autoScale'     : false,
            'transitionIn'  : 'none',
            'transitionOut' : 'none',
            'title'         : this.title,
            'width'     : 680,
            'height'        : 495,
            'href'          : this.href.replace(new RegExp("watch\\?v=", "i"), 'v/'),
            'type'          : 'swf',
            'swf'           : {
                 'wmode'        : 'transparent',
                'allowfullscreen'   : 'true'
            }
        });

    return false;
});

// virtual tour open links in new window
 $('a[href="/virtual_tour/Tourviewer_CAC.html"]').click(function() {
        window.open($(this).attr('href'),'Canadian Adventure Camp Virtual Tour', 'width=920, height=520');
        return false;
    });  

// Function for animating the FAQs
    $questions = $('h3.faq_question a');
	$answers = $('div.faq_answer');
	$answers.hide();

	$questions.click(function() {

		if ($(this).parent().next("div.faq_answer").is(":hidden")) {
	    	$answers.hide();
	    	$(this).parent().next("div.faq_answer").slideDown('fast');
		}else{
			$(this).parent().next("div.faq_answer").slideUp();
		}
		return false;
});
// i've never done that before.
//$('.neverDoneBefore .imagesHolderNDB').cycle({
//        fx:'fade',
//		timeout: 10000,
//        next: '.arrowRight',
//        prev: '.arrowLeft'
//	});

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



//$('.whatsNewSlidesow').cycle({
//		fx: 'scrollHorz',
//		pager:  $(this).find('.whatsNewPager'),
//		timeout: 3000
//		//prev: $("a.arrowLeft"),
//		//next: $("a.arrowRight")
//		//easing: 'easeInOutCirc'
//	});	


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
		$('div#slideShow-' + selectedGender + '-' + selectedAge).show().flexslider(0);

		// load the first slide's description in the HTML
		var slideDescription = $('.tdSlideShow:visible img:visible').attr('data-description');
		if (slideDescription== "") {
			slideDescription = "Missing description! Please add one in the manager.";
		}
		 $('.slideDescription').html( '<p>' + slideDescription + '</p>');

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
$('.tdSlideShow').flexslider({
	directionNav: false, 
	slideshow: false,
	before: function() {// this part assures user won't click any more buttons while animation is playing
		$('div.tdSlideshowNavCover').css("display", "block");
	},
	after: function(slider) {
		$('div.tdSlideshowNavCover').css("display", "none");
		var slideDescription = $('.tdSlideShow:visible img:visible').attr('data-description');
		if (slideDescription== "") {
			slideDescription = "Missing description! Please add one in the manager.";
		}
		$('.slideDescription').html( '<p>' + slideDescription + '</p>');
		$('.slideDescription p').vAlign();// we center the description vertically
	}
});

// below are the click handlers for the previous & next buttons
$('#prev2').click(function(){
	//alert ($('#tdSlideShowNav li').index($('.activeSlide')));
	var currentSlideIndex = $('#tdSlideShowNav li').index($('.activeSlide'));
	if (currentSlideIndex>0) {
		$('#tdSlideShowNav li').removeClass();
		$('.tdSlideShow:visible').flexslider('prev');
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
		$('.tdSlideShow:visible').flexslider('next');
		$('#tdSlideShowNav li:nth-child(' + nextSlideIndex +')').addClass('activeSlide');
		return false;
	};
	return false;
});

// and this part  is for the slideshow navigation
$('#tdSlideShowNav li a').each(function(index){
	$(this).click(function(){
		
		$(this).parent().addClass('activeSlide').siblings().removeClass();
		$('.tdSlideShow:visible').flexslider(index);
		return false;
	});
});
// end typical day page code

});