# Raster Images
## Introduction

Welcome to Computer Graphics! The main purpose of this assignment will be to get
you up and running with C++ and the cmake build setup used for our assignments.


### Layout

All assignments will have a similar directory and file layout:

    README.md
    CMakeLists.txt
    main.cpp
    include/
      function1.h
      function2.h
      ...
    src/
      function1.cpp
      function2.cpp
      ...
    data/
      ...
    ...

The `README.md` file will describe the background, contents and tasks of the
assignment.

The `CMakeLists.txt` file setups up the cmake build routine for this
assignment.

The `main.cpp` file will include the headers in the `include/` directory and
link to the functions compiled in the `src/` directory. This file contains the
`main` function that is executed when the program is run from the command line.

The `include/` directory contains one file for each function that you will
implement as part of the assignment. **_Do not change_** these files.

The `src/` directory contains _empty implementations_ of the functions
specified in the `include/` directory. This is where you will implement the
parts of the assignment.

The `data/` directory contains _sample_ input data for your program. Keep in
mind you should create your own test data to verify your program as you write
it. It is not necessarily sufficient that your program _only_ works on the given
sample data.

## Compilation

This and all following assignments will follow a typical cmake/make build
routine. Starting in this directory, issue:

    mkdir build
    cd build
    cmake ..

If you are using Mac or Linux, then issue:

    make

If you are using Windows, then running `cmake ..` should have created a Visual Studio solution file
called `raster.sln` that you can open and build from there. Building the raster project will generate an .exe file.

Why don't you try this right now?

## Execution

Once built, you can execute the assignment from inside the `build/` using 

    ./raster

## Tasks

> Every assignment, including this one, will contain a **Tasks** section. This
> will enumerate all of the tasks a student will need to complete for this
> assignment. These tasks will match the header/implementation pairs in the
> `include/`/`src/` directories.

### Groundrules

Implementations of nearly any task you're asked to implemented in this course
can be found online. Do not copy these and avoid _googling for code_; instead,
search the internet for explanations. Many topics have relevant wikipedia
articles. Use these as references. Always remember to cite any references in
your comments.

#### White List

Feel free and encouraged to use standard template library functions in `#include
<algorithm>` and `#include <cmath>` such as `std::fmod` and `std::fabs`.


### `src/rgba_to_rgb.cpp`

Extract the 3-channel rgb data from a 4-channel rgba image.

### `src/write_ppm.cpp`

Write an rgb or grayscale image to a .ppm file.

At this point, you should start seeing output files:

 - `bayer.ppm`
 - `composite.ppm`
 - `demosaicked.ppm`
 - `desaturated.ppm`
 - `gray.ppm`
 - `reflected.ppm`
 - `rgb.ppm`
 - `rotated.ppm`
 - `shifted.ppm`

![If you've implemented `src/rgba_to_rgb.cpp` correctly then `./raster
../data/dog.png` should produce this image in
`rgb.ppm`.](images/rgb.png) 

### `src/reflect.cpp`

Horizontally reflect an image (like a mirror)

![If you've implemented `src/write_ppm.cpp` correctly then `./raster
../data/dog.png` should produce this image in
`reflected.ppm`.](images/reflected.png) 

### `src/rotate.cpp`

Rotate an image 90^\circ   counter-clockwise

![`./raster
../data/dog.png` should produce this image in
`rotated.ppm`.](images/rotated.png) 

### `src/rgb_to_gray.cpp`

Convert a 3-channel RGB image to a 1-channel grayscale image.

![`./raster
../data/dog.png` should produce this image in
`gray.ppm`.](images/gray.png) 

### `src/simulate_bayer_mosaic.cpp`

Simulate an image acquired from the Bayer mosaic by taking a 3-channel rgb image
and creating a single channel grayscale image composed of interleaved
red/green/blue channels. The output image should be the same size as the input but only one
channel.

![`./raster
../data/dog.png` should produce this image in
`bayer.ppm`. **Zoom in** to see interleaving.](images/bayer.png) 

### `src/demosaic.cpp`

Given a mosaiced image (interleaved GBRG colors in a single channel), created a
3-channel rgb image.

![`./raster ../data/dog.png` should produce this image in
`demosaicked.ppm`.](images/demosaicked.png) 

### `src/rgb_to_hsv.cpp`

Convert a color represented by red, green and blue intensities to its
representation using hue, saturation and value.

### `src/hsv_to_rgb.cpp`

Convert a color represented by hue, saturation and value to its representation
using red, green and blue intensities.

### `src/hue_shift.cpp`

Shift the hue of a color rgb image. 

Hint: Use your `rgb_to_hsv` and `hsv_to_rgb` functions.

![`./raster
../data/dog.png` should produce this image in
`shifted.ppm`.](images/shifted.png) 

### `src/desaturate.cpp`

Desaturate a given rgb color image by a given factor.

Hint: Use your `rgb_to_hsv` and `hsv_to_rgb` functions.

![`./raster
../data/dog.png` should produce this image in
`desaturated.ppm`.](images/desaturated.png) 

### `src/over.cpp`

Compute C = A Over B, where A and B are semi-transparent rgba images and
"Over" is the Porter-Duff Over operator.

![`./raster
../data/{dog,glasses,laser-beams,sparkles}.png` should produce this image in
`composite.ppm`.](images/composite.png) 


