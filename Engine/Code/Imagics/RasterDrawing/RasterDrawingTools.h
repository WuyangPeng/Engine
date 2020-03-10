// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:22)

#ifndef IMAGICS_RASTER_DRAWING_RASTER_DRAWING_TOOLS_H
#define IMAGICS_RASTER_DRAWING_RASTER_DRAWING_TOOLS_H

#include "Imagics/ImagicsDll.h"

namespace Imagics
{	
	// Process the pixels visited by Bresenham's algorithm for the line segment
	// with end points (x0,y0) and (x1,y1).  The callback is executed for each
	// visited pixel (x,y).  The arguments to the callback are x and y.
	IMAGICS_DEFAULT_DECLARE	void Line2D(int x0, int y0, int x1, int y1, void (*callback)(int,int));
	
	// Process the voxels visited by Bresenham's algorithm for the line segment
	// with end points (x0,y0,z0) and (x1,y1,z1).  The callback is executed for
	// each visited voxel (x,y,z).  The arguments to the callback are x, y, and z.
	IMAGICS_DEFAULT_DECLARE void Line3D(int x0, int y0, int z0, int x1, int y1, int z1, void (*callback)(int,int,int));
	
	// Process the hypervoxels visited by Bresenham's algorithm for the line
	// segment with end points (x0,y0,z0,w0) and (x1,y1,z1,w1).  The callback is
	// executed for each visited hypervoxel (x,y,z,w).  The arguments to the
	// callback are x, y, z, and w.
	IMAGICS_DEFAULT_DECLARE void Line4D(int x0, int y0, int z0, int w0, int x1, int y1, int z1, int w1, void (*callback)(int,int,int,int));
	
	// Process the pixels visited by Bresenham's algorithm for the circle
	// (x-xc)^2 + (y-yc)^2 = r^2.  The callback is executed for each
	// visited pixel (x,y).  The arguments to the callback are x and y.
	IMAGICS_DEFAULT_DECLARE void Circle2D(int xc, int yc, int radius,  void (*callback)(int,int));
	
	// Process the pixels visited by Bresenham's algorithm for the axis-aligned
	// ellipse (x-xc)^2/a^2 + (y-yc)^2/b^2 = 1.  The callback is
	// executed for each visited pixel (x,y).  The arguments to the callback are
	// x and y.
	IMAGICS_DEFAULT_DECLARE void Ellipse2D(int xc, int yc, int A, int B, void (*callback)(int,int));
	
	// Process the pixels visited by Bresenham's algorithm for an arc of the
	// axis-aligned ellipse (x-xc)^2/a^2 + (y-yc)^2/b^2 = 1.  The arc has end
	// points (x0,fy0) and (x1,fy1) where (xi-xc)^2/a^2 + (yi-yc)/b^2 = 1 for
	// i = 0,1.  The arc is traversed in clockwise order.  The callback is
	// executed for each visited pixel (x,y).  The arguments to the callback are
	// x and y.
	IMAGICS_DEFAULT_DECLARE void EllipseArc2D(int xc, int yc, int A, int B, float fx0, float fy0, float fx1, float fy1, void (*callback)(int,int));
	
	// Process the pixels visited by Bresenham's algorithm for an oriented
	// ellipse.  The ellipse has shape and orientation determined by the bounding
	// box with center (xc,yc) and axes (xa,ya) and (xb,yb), where theoretically
	// Dot((xa,ya),(xb,yb)) = 0.  Rounding to the nearest integer will cause the
	// dot product to be nonzero, yet small compared to the length of the
	// cross product Cross((xa,ya,0),(xb,yb,0)) = (0,0,xa*yb-xb*ya).  This should
	// not be a problem when drawing the ellipse.
	IMAGICS_DEFAULT_DECLARE void GeneralEllipse2D(int xc, int yc, int xa, int ya,int xb, int yb, void (*callback)(int,int));
	
	// The initial call must guarantee that the seed point (x,y) satisfies
	// 0 <= x < xMax and 0 <= y < yMax and that image[y][x] is the
	// background color (backColor).  The fill color is specified by foreColor.
	IMAGICS_DEFAULT_DECLARE void RecursiveFill(int x, int y, int xMax, int yMax,  int** image, int foreColor, int backColor);
	
	IMAGICS_DEFAULT_DECLARE void NonrecursiveFill(int x, int y, int xMax,  int yMax, int** image, int foreColor, int backColor);
}

#endif // IMAGICS_RASTER_DRAWING_RASTER_DRAWING_TOOLS_H
