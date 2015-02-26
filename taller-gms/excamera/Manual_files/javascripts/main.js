
/* -----------------------------------------
   Offline Documentation
----------------------------------------- */

var layoutWidth;
var layoutHeight;
var sidebarWidth;
var contentsWidth;	

$(document).ready(function($) {

	$('.javascript-warning').hide();
	$('.layout-content').show().height( ($(window).height()-60) );
	
	loadPage('ex_camera_welcome.html');
	$('.topics').children('li:first-child').css({ 'background-color': '#333', 'color': '#fff' });
	
	$('.layout-header .logo').on('click', function(){
		$('.topics').children('li').css({ 'background-color': 'transparent', 'color': '#222' });
		$('.topics').children('li:first-child').css({ 'background-color': '#333', 'color': '#fff' });
		loadPage('ex_camera_welcome.html');
	});

	$('.topics').children('li').on('click', function(){
		$('.topics').children('li').css({ 'background-color': 'transparent', 'color': '#222' });
		$(this).css({ 'background-color': '#333', 'color': '#fff' });
	});
	
	$('.logo').on('mouseover', function(){
		$(this).finish().animate({ 'opacity': 0.7 }, 300);
	});
	
	$('.logo').on('mouseout', function(){
		$(this).finish().animate({ 'opacity': 1 }, 300);
	});
	
	adjustDimensions();
	
});

function adjustDimensions() {
	
	layoutWidth = $(window).width();
	layoutHeight = ($(window).height()-60);
	sidebarWidth = layoutWidth / 5;
	contentsWidth = (layoutWidth - sidebarWidth);

	$('.sidebar').width(sidebarWidth);
	$('.contents').width(contentsWidth-36);
	$('.layout-content, .sidebar, .contents').height( layoutHeight );
	
	$('.sidebar-inner').css( {'height': (layoutHeight-56)+'px' });
	$('.contents-inner').css( {'height': (layoutHeight-10)+'px' });
	
	$('<iframe id="contents" class="contents-inner-iframe" width="100%" height="96.66666%" frameborder="0" scrolling="auto"></iframe>').insertAfter('.contents-inner');
	$('.contents-inner').remove();
	
}

function loadPage(page) {
	
	$('.contents-inner-iframe').attr('src', 'Manual_files/contents/'+page);
	
}

function filter(element) {
	var value = $(element).val().toLowerCase();

	$(".topics > li").each(function() {
		if ($(this).text().toLowerCase().search(value) > -1) {
			$('.hr').hide();
			$(this).show();
		}
		else {
			$(this).hide();
		}
	});
	
	if (value == "") {
		$('.hr').show();
	}
}


		
$(window).resize(function() {

	adjustDimensions();
	
});
