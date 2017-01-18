var gulp 		= require('gulp');
var bs 			= require('browser-sync').create(); // create a browser sync instance.
var reload      = bs.reload;
var sourcemaps 	= require('gulp-sourcemaps');
var sass 		= require('gulp-sass');

var src = {
    //scss: 'app/scss/*.scss',
    css:  'css/*.css',
    php: '**/*.php',
    inc: '**/*.inc',
    scss: 'scss/*.scss'
};


gulp.task('browser-sync', ['sass'], function() {
	bs.init({
	   	ui: {
	    	port: 3001
		},
        proxy: 'rf.dev',
        port: 3000,
        files: ['*.php', '**/*.inc', '**/*.css', '**/*.js']
    });
});

// Compile sass into CSS & auto-inject into browsers
gulp.task('sass', function() {
    return gulp.src('scss/**/*.scss')
    	.pipe(sourcemaps.init())
        .pipe(sass().on('error', sass.logError))
        .pipe(sourcemaps.write('./'))
        .pipe(gulp.dest('css'))
        .pipe(bs.stream());
});

gulp.task('watch', ['browser-sync'], function () {
    gulp.watch(src.scss, ['sass']);
    //gulp.watch("*.html").on('change', bs.reload);
});