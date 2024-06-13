# Introduction

A warehouse for the attachments of spatial analytic geometry papers.

Use the least-squares method, two-dimensional and three-dimensional convex hull algorithms to solve the problem of quadric surface enclosure.

# Code

## Fitting conicoid

Compile and run `./fitting.cpp`, note that you need the Eigen library.

### Introduction

For a set of points in a given space, the quadric surface is fitted using the least squares method.

### Input

The first line contains one integer $n$, indicating the number of points.

Each of following $n$ lines contains three floating numbers, indicating the $x,y,z$ coordinates of the $i-th$ point.

### Output

parameters $a\sim f$ of the quadric surface.

## Find the two-dimensional convex hull

Compile and run `./2dconvexhull.cpp`, note that you need the Eigen library.

### Introduction

For a set of points in a given space, find the two-dimensional convex hull of them.

### Input

The first line contains one integer $n$, indicating the number of points.

Each of following $n$ lines contains three floating numbers, indicating the $x,y,z$ coordinates of the $i-th$ point. Note that the $z$ coordinate do not use for Find the convex hull, just for output.

### Output

Outputs all points on the convex hull.

## Find the three-dimensional convex hull

Compile and run `./3dconvexhull.cpp`, note that you need the Eigen library.

### Introduction

For a set of points in a given space, find the three-dimensional convex hull of them.

### Input

The first line contains one integer $n$, indicating the number of points.

Each of following $n$ lines contains three floating numbers, indicating the $x,y,z$ coordinates of the $i-th$ point.

### Output

Outputs all points on the convex hull.

# Data

There are four data sets for this project in path `./Data`.

The first line contains one integer $n$, indicating the number of points. And each of following $n$ lines contains three floating numbers, indicating the $x,y,z$ coordinates of the $i-th$ point.
