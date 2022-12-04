'use strict';
const gulp = require('gulp');
const sass = require('gulp-sass')(require('sass'));

gulp.task('styles', function() {
    return gulp
        .src('../webSrc/scss/style.scss')
        .pipe(sass().on('error', sass.logError))
        .pipe(gulp.dest('../data/'));
});

gulp.task('watch', function(){
    gulp.watch('../webSrc/scss/**/*.scss', gulp.series('styles'));
});

gulp.task(
    'default',
    gulp.series(
       'styles',
       'watch'
    )
 );