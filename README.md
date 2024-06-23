# Raster Graphics Console Editor

## Overview
This project is a console-based raster graphics editor for my OOP course. It allows users to work with different image files, start sessions, apply various transformations to images, and save the results.

## Supported File Formats
- PPM (Portable Pixmap)
- PGM (Portable Graymap)
- PBM (Portable Bitmap)

## Features
- `load <filename1> <filename2>...`  
  Creates a new session.
  
- `add <filename>`  
  Adds an image to the current session.
  
- `session info`  
  Provides information on the current session.
  
- `switch <id>`  
  Switches to another session.
  
- `save`  
  Saves changes to the file.
  
- `save as <filename>`  
  Saves changes to a new file.
  
- `save all`  
  Saves changes from all sessions.
  
- `monochrome`  
  Applies monochrome effect to all images in the current session.
  
- `grayscale`  
  Applies grayscale effect to all images in the current session.
  
- `negative`  
  Applies negative effect to all images in the current session.
  
- `rotate left`  
  Rotates all images in the current session to the left.
  
- `rotate right`  
  Rotates all images in the current session to the right.
  
- `undo`  
  Undoes the last change in the current session.
  
- `collage <direction(horizontal/vertical)> <filename1> <filename2> <outfileName>`  
  Creates a collage of two images.
  
- `exit`  
  Ends the program.
