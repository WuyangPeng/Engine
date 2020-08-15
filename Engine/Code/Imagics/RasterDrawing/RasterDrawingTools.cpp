// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/30 16:22)

#include "Imagics/ImagicsExport.h"

#include "RasterDrawingTools.h"

#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26487)
void Imagics
	::Line2D(int x0, int y0, int x1, int y1, void(*callback)(int, int)) noexcept
{
    // Starting point of line.
    int x = x0, y = y0;

    // Direction of line.
    int dx = x1-x0, dy = y1-y0;

    // Increment or decrement depending on direction of line.
    const int sx = (dx > 0 ? 1 : (dx < 0 ? -1 : 0));
    const int sy = (dy > 0 ? 1 : (dy < 0 ? -1 : 0));

    // Decision parameters for pixel selection.
    if (dx < 0)
    {
        dx = -dx;
    }
    if (dy < 0)
    {
        dy = -dy;
    }
    const int ax = 2*dx, ay = 2*dy;
    int decX = 0, decY= 0;

    // Determine largest direction component, single-step related variable.
    const int maxValue = dx;
    int var = 0;
    if (dy > maxValue)
    {
        var = 1;
    }

    // Traverse Bresenham line.
    switch (var)
    {
    case 0:  // Single-step in x-direction.
        decY = ay - dx;
        for (/**/; /**/; x += sx, decY += ay)
        {
            // Process pixel.
            callback(x, y);

            // Take Bresenham step.
            if (x == x1)
            {
                break;
            }
            if (decY >= 0)
            {
                decY -= ax;
                y += sy;
            }
        }
        break;
    case 1:  // Single-step in y-direction.
        decX = ax - dy;
        for (/**/; /**/; y += sy, decX += ax)
        {
            // Process pixel.
            callback(x, y);

            // Take Bresenham step.
            if (y == y1)
            {
                break;
            }
            if (decX >= 0)
            {
                decX -= ay;
                x += sx;
            }
        }
        break;
    }
}

void Imagics
	::Line3D(int x0, int y0, int z0, int x1, int y1, int z1,
             void (*callback)(int,int,int)) noexcept
{
    // Starting point of line.
    int x = x0, y = y0, z = z0;

    // Direction of line.
    int dx = x1-x0, dy = y1-y0, dz = z1-z0;

    // Increment or decrement depending on direction of line.
    const int sx = (dx > 0 ? 1 : (dx < 0 ? -1 : 0));
    const int sy = (dy > 0 ? 1 : (dy < 0 ? -1 : 0));
    const int sz = (dz > 0 ? 1 : (dz < 0 ? -1 : 0));

    // Decision parameters for voxel selection.
    if (dx < 0)
    {
        dx = -dx;
    }
    if (dy < 0)
    {
        dy = -dy;
    }
    if (dz < 0)
    {
        dz = -dz;
    }
    const int ax = 2*dx, ay = 2*dy, az = 2*dz;
    int decX = 0, decY = 0, decZ = 0;

    // Determine largest direction component, single-step related variable.
    int maxValue = dx, var = 0;
    if (dy > maxValue)
    {
        maxValue = dy;
        var = 1;
    }
    if (dz > maxValue)
    {
        var = 2;
    }

    // Traverse Bresenham line.
    switch (var)
    {
    case 0:  // Single-step in x-direction.
        decY = ay - dx;
        decZ = az - dx;
        for (/**/; /**/; x += sx, decY += ay, decZ += az)
        {
            // Process voxel.
            callback(x, y, z);

            // Take Bresenham step.
            if (x == x1)
            {
                break;
            }
            if (decY >= 0)
            {
                decY -= ax;
                y += sy;
            }
            if (decZ >= 0)
            {
                decZ -= ax;
                z += sz;
            }
        }
        break;
    case 1:  // Single-step in y-direction.
        decX = ax - dy;
        decZ = az - dy;
        for (/**/; /**/; y += sy, decX += ax, decZ += az)
        {
            // Process voxel.
            callback(x, y, z);

            // Take Bresenham step.
            if (y == y1)
            {
                break;
            }
            if (decX >= 0)
            {
                decX -= ay;
                x += sx;
            }
            if (decZ >= 0)
            {
                decZ -= ay;
                z += sz;
            }
        }
        break;
    case 2:  // Single-step in z-direction.
        decX = ax - dz;
        decY = ay - dz;
        for (/**/; /**/; z += sz, decX += ax, decY += ay)
        {
            // Process voxel.
            callback(x,y,z);

            // Take Bresenham step.
            if (z == z1)
            {
                break;
            }
            if (decX >= 0)
            {
                decX -= az;
                x += sx;
            }
            if (decY >= 0)
            {
                decY -= az;
                y += sy;
            }
        }
        break;
    }
}

void Imagics
	::Line4D(int x0, int y0, int z0, int w0, int x1, int y1, int z1,
             int w1,  void (*callback)(int,int,int,int)) noexcept
{
    // Starting point of line.
    int x = x0, y = y0, z = z0, w = w0;

    // Direction of line.
    int dx = x1-x0, dy = y1-y0, dz = z1-z0, dw = w1-w0;

    // Increment or decrement depending on direction of line.
    const int sx = (dx > 0 ? 1 : (dx < 0 ? -1 : 0));
    const int sy = (dy > 0 ? 1 : (dy < 0 ? -1 : 0));
    const int sz = (dz > 0 ? 1 : (dz < 0 ? -1 : 0));
    const int sw = (dw > 0 ? 1 : (dw < 0 ? -1 : 0));

    // Decision parameters for hypervoxel selection.
    if (dx < 0)
    {
        dx = -dx;
    }
    if (dy < 0)
    {
        dy = -dy;
    }
    if (dz < 0)
    {
        dz = -dz;
    }
    if (dw < 0)
    {
        dw = -dw;
    }
    const int ax = 2*dx, ay = 2*dy, az = 2*dz, aw = 2*dw;
    int decX = 0, decY = 0, decZ = 0, decW = 0;

    // Determine largest direction component, single-step related variable.
    int maxValue = dx, var = 0;
    if (dy > maxValue)
    {
        maxValue = dy;
        var = 1;
    }
    if (dz > maxValue)
    {
        maxValue = dz;
        var = 2;
    }
    if (dw > maxValue)
    {
        var = 3;
    }

    // Traverse Bresenham line.
    switch (var)
    {
    case 0:  // Single-step in x-direction.
        decY = ay - dx;
        decZ = az - dx;
        decW = aw - dx;
        for (/**/; /**/; x += sx, decY += ay, decZ += az, decW += aw)
        {
            // Process hypervoxel.
            callback(x, y, z, w);

            // Take Bresenham step.
            if (x == x1)
            {
                break;
            }
            if (decY >= 0)
            {
                decY -= ax;
                y += sy;
            }
            if (decZ >= 0)
            {
                decZ -= ax;
                z += sz;
            }
            if (decW >= 0)
            {
                decW -= ax;
                w += sw;
            }
        }
        break;
    case 1:  // Single-step in y-direction.
        decX = ax - dy;
        decZ = az - dy;
        decW = aw - dy;
        for (/**/; /**/; y += sy, decX += ax, decZ += az, decW += aw)
        {
            // Process hypervoxel.
            callback(x, y, z, w);

            // Take Bresenham step.
            if (y == y1)
            {
                break;
            }
            if (decX >= 0)
            {
                decX -= ay;
                x += sx;
            }
            if (decZ >= 0)
            {
                decZ -= ay;
                z += sz;
            }
            if (decW >= 0)
            {
                decW -= ay;
                w += sw;
            }
        }
        break;
    case 2:  // Single-step in z-direction.
        decX = ax - dz;
        decY = ay - dz;
        decW = aw - dz;
        for (/**/; /**/; z += sz, decX += ax, decY += ay, decW += aw)
        {
            // Process hypervoxel.
            callback(x, y, z, w);

            // Take Bresenham step.
            if (z == z1)
            {
                break;
            }
            if (decX >= 0)
            {
                decX -= az;
                x += sx;
            }
            if (decY >= 0)
            {
                decY -= az;
                y += sy;
            }
            if (decW >= 0)
            {
                decW -= az;
                w += sw;
            }
        }
        break;
    case 3:  // Single-step in w-direction.
        decX = ax - dw;
        decY = ay - dw;
        decZ = az - dw;
        for (/**/; /**/; w += sw, decX += ax, decY += ay, decZ += az)
        {
            // Process hypervoxel.
            callback(x, y, z, w);

            // Take Bresenham step.
            if (w == w1)
            {
                break;
            }
            if (decX >= 0)
            {
                decX -= aw;
                x += sx;
            }
            if (decY >= 0)
            {
                decY -= aw;
                y += sy;
            }
            if (decZ >= 0)
            {
                decZ -= aw;
                z += sz;
            }
        }
        break;
    }
}

void Imagics
	::Circle2D(int xc, int yc, int radius, void(*callback)(int, int)) noexcept
{
    for (int x = 0, y = radius, dec = 3-2*radius; x <= y; ++x)
    {
        callback(xc+x, yc+y);
        callback(xc+x, yc-y);
        callback(xc-x, yc+y);
        callback(xc-x, yc-y);
        callback(xc+y, yc+x);
        callback(xc+y, yc-x);
        callback(xc-y, yc+x);
        callback(xc-y, yc-x);

        if (dec >= 0)
        {
            dec += -4*(y--) + 4;
        }
        dec += 4*x + 6;
    }
}

void Imagics
	::Ellipse2D(int xc, int yc, int A, int B, void(*callback)(int, int)) noexcept
{
    const int A2 = A*A, B2 = B*B;
    int x= 0, y= 0, dec = 0;

    for (x = 0, y = B, dec = 2*B2+A2*(1-2*B); B2*x <= A2*y; ++x)
    {
        callback(xc+x, yc+y);
        callback(xc-x, yc+y);
        callback(xc+x, yc-y);
        callback(xc-x, yc-y);

        if (dec >= 0)
        {
            dec += 4*A2*(1-(y--));
        }
        dec += B2*(4*x+6);
    }
    if (y == 0 && x < A)
    {
        // The discretization caused us to reach the y-axis before the
        // x-values reached the ellipse vertices.  Draw a solid line along
        // the x-axis to those vertices.
        for (/**/; x <= A; ++x)
        {
            callback(xc+x, yc);
            callback(xc-x, yc);
        }
        return;
    }

    for (x = A, y = 0, dec = 2*A2+B2*(1-2*A); A2*y <= B2*x; ++y)
    {
        callback(xc+x, yc+y);
        callback(xc-x, yc+y);
        callback(xc+x, yc-y);
        callback(xc-x, yc-y);

        if (dec >= 0)
        {
            dec += 4*B2*(1-(x--));
        }
        dec += A2*(4*y+6);
    }
    if (x == 0 && y < B)
    {
        // The discretization caused us to reach the x-axis before the
        // y-values reached the ellipse vertices.  Draw a solid line along
        // the y-axis to those vertices.
        for (/**/; y <= B; ++y)
        {
            callback(xc, yc+y);
            callback(xc, yc-y);
        }
    }
}

static void SelectEllipsePoint (int A2, int B2, float fx, float fy, int& x,int& y) noexcept
{
    int xFloor = static_cast<int>(Mathematics::Mathf::Floor(fx));
    int yFloor = static_cast<int>(Mathematics::Mathf::Floor(fy));
    const int xIncr = B2*(2*xFloor + 1);
    const int yIncr = A2*(2*yFloor + 1);
    const int base = B2*xFloor*xFloor + A2*yFloor*yFloor - A2*B2;
    const int a00 = abs(base);
    const int a10 = abs(base + xIncr);
    const int a01 = abs(base + yIncr);
    const int a11 = abs(base + xIncr + yIncr);

    int minValue = a00;
    x = xFloor;
    y = yFloor;
    if (a10 < minValue)
    {
        minValue = a10;
        x = xFloor + 1;
        y = yFloor;
    }
    if (a01 < minValue)
    {
        minValue = a01;
        x = xFloor;
        y = yFloor + 1;
    }
    if (a11 < minValue)
    {
        minValue = a11;
        x = xFloor + 1;
        y = yFloor + 1;
    }
}

static int WhichArc (int A2, int B2, int x, int y) noexcept
{
    if (x > 0)
    {
        if (y > 0)
        {
            return (B2*x <  A2*y ? 0 : 1);
        }
        else if (y < 0)
        {
            return (B2*x > -A2*y ? 2 : 3);
        }
        else
        {
            return 2;
        }
    }
    else if (x < 0)
    {
        if (y < 0)
        {
            return (A2*y <  B2*x ? 4 : 5);
        }
        else if (y > 0)
        {
            return (A2*y < -B2*x ? 6 : 7);
        }
        else
        {
            return 6;
        }
    }
    else
    {
        return (y > 0 ? 0 : 4);
    }
}

void Imagics
	::EllipseArc2D(int xc, int yc, int A, int B, float fx0,
                   float fy0, float fx1, float fy1, void (*callback)(int,int)) noexcept
{
    // Assert (within floating point roundoff errors):
    //   (x0-xc)^2/a^2 + (y0-yc)^2/b^2 = 1
    //   (x1-xc)^2/a^2 + (y1-yc)^2/b^2 = 1
    // Assume if (x0,y0) == (x1,y1), then entire ellipse should be drawn.
    //
    // Pixels on arc are guaranteed to be traversed clockwise.

    const int A2 = A*A, B2 = B*B;

    // Get integer endpoints for arc.
    int x0, y0, x1, y1;
    SelectEllipsePoint(A2, B2, fx0 - xc, fy0 - yc, x0, y0);
    SelectEllipsePoint(A2, B2, fx1 - xc, fy1 - yc, x1, y1);

    int dx = x0 - x1, dy = y0 - y1, sqrLen = dx*dx + dy*dy;
    if (sqrLen == 1 || (sqrLen == 2 && abs(dx) == 1))
    {
        callback(xc+x0, yc+y0);
        callback(xc+x1, yc+y1);
        return;
    }

    // Determine initial case for arc drawing.
    int arc = WhichArc(A2,B2,x0,y0);
    bool notDone = true;
    while (notDone)
    {
        // Process the pixel.
        callback(xc+x0, yc+y0);

        // Determine next pixel to process.  Notation <(x,y),dy/dx> indicates
        // point on ellipse and slope at that point.
        int sigma = 0;
        switch (arc)
        {
        case 0:  // <(0,b),0> to <(u0,v0),-1>
            x0++;
            dx++;
            sigma = B2*x0*x0 + A2*(y0-1)*(y0-1) - A2*B2;
            if (sigma >= 0)
            {
                y0--;
                dy--;
            }
            if (B2*x0 >= A2*y0)
            {
                // Slope dy/dx is no longer between 0 and -1.  Switch to next
                // arc drawer.  For large a and b, you expect to go to
                // 'arc = 1'.  But for small a or b, it is possible that the
                // next arc is so small (on the discrete raster) that it is
                // skipped.
                arc = (y0 > 0 ? 1 : 2);
            }
            break;
        case 1:  // <(u0,v0),-1> to <(a,0),infinity>
            y0--;
            dy--;
            sigma = B2*x0*x0 + A2*y0*y0 - A2*B2;
            if (sigma < 0)
            {
                x0++;
                dx++;
            }
            if (y0 == 0)
            {
                arc = 2;
            }
            break;
        case 2:  // <(a,0),infinity> to <(u1,v1),+1>
            y0--;
            dy--;
            sigma = B2*(x0-1)*(x0-1) + A2*y0*y0 - A2*B2;
            if (sigma >= 0)
            {
                x0--;
                dx--;
            }
            if (B2*x0 <= -A2*y0)
            {
                // Slope dy/dx is no longer between 0 and +1.  Switch to next
                // arc drawer.  For large a and b, you expect to go to
                // 'arc = 3'.  But for small a or b, it is possible that the
                // next arc is so small (on the discrete raster) that it is
                // skipped.
                arc = (x0 > 0 ? 3 : 4);
            }
            break;
        case 3:  // <(u1,v1),+1> to <(0,-b),0>
            x0--;
            dx--;
            sigma = B2*x0*x0 + A2*y0*y0 - A2*B2;
            if (sigma < 0)
            {
                y0--;
                dy--;
            }
            if (x0 == 0)
            {
                arc = 4;
            }
            break;
        case 4:  // <(0,-b),0> to <(u2,v2,-1)>
            x0--;
            dx--;
            sigma = B2*x0*x0 + A2*(y0+1)*(y0+1) - A2*B2;
            if (sigma >= 0)
            {
                y0++;
                dy++;
            }
            if (A2*y0 >= B2*x0)
            {
                // Slope dy/dx is no longer between 0 and -1.  Switch to next
                // arc drawer.  For large a and b, you expect to go to
                // 'arc = 5'.  But for small a or b, it is possible that the
                // next arc is so small (on the discrete raster) that it is
                // skipped.
                arc = (y0 < 0 ? 5 : 6);
            }
            break;
        case 5:  // <(u2,v2,-1)> to <(-a,0),infinity>
            y0++;
            dy++;
            sigma = B2*x0*x0 + A2*y0*y0 - A2*B2;
            if (sigma < 0)
            {
                x0--;
                dx--;
            }
            if (y0 == 0)
            {
                arc = 6;
            }
            break;
        case 6:  // <(-a,0),infinity> to <(u3,v3),+1>
            y0++;
            dy++;
            sigma = B2*(x0+1)*(x0+1) + A2*y0*y0 - A2*B2;
            if (sigma >= 0)
            {
                x0++;
                dx++;
            }
            if (A2*y0 >= -B2*x0)
            {
                // Slope dy/dx is no longer between 0 and +1.  Switch to next
                // arc drawer.  For large a and b, you expect to go to
                // 'arc = 7'.  But for small a or b, it is possible that the
                // next arc is so small (on the discrete raster) that it is
                // skipped.
                arc = (x0 < 0 ? 7 : 8);
            }
            break;
        case 7:  // <(u3,v3),+1> to <(0,b),0>
            x0++;
            dx++;
            sigma = B2*x0*x0 + A2*y0*y0 - A2*B2;
            if (sigma < 0)
            {
                y0++;
                dy++;
            }
            if (x0 == 0)
            {
                arc = 0;
            }
            break;
        }

        if (sqrLen <= 1)
        {
            notDone = false;
            continue;
        }

        sqrLen = dx*dx + dy*dy;
    }
}

void Imagics
	::GeneralEllipse2D(int xc, int yc, int xa, int ya, int xb, int yb,
                       void (*callback)(int,int))
{
    // Change sign and/or swap the direction vectors in order to satisfy this
    // algorithm's requirement for visiting pixels in a particular order.
    int save = 0;
    if (xa <= 0 && ya > 0)
    {
        // Use (-xb,-yb,xa,ya).
        save = xa;
        xa = -xb;
        xb = save;
        save = ya;
        ya = -yb;
        yb = save;
    }
    else if (xa < 0 && ya <= 0)
    {
        // Use (-xa,-ya,-xb,-yb).
        xa = -xa;
        ya = -ya;
        xb = -xb;
        yb = -yb;
    }
    else if (xa >= 0 && ya < 0)
    {
        // Use (xb,yb,-xa,-ya).
        save = xa;
        xa = xb;
        xb = -save;
        save = ya;
        ya = yb;
        yb = -save;
    }
    // else (xa > 0 && ya >= 0): use (xa,ya,xb,yb)

    // Ellipse is a*(x-xc)^2+2*b*(x-xc)*(y-yc)+c*(y-yc)^2 = d where
    //
    //   a = xa^2*Lb^4 + xb^2*La^4
    //   b = xa*ya*Lb^4 + xb*yb*La^4
    //   c = ya^2*Lb^4 + yb^2*La^4
    //   d = La^4*Lb^4
    //   La^2 = xa^2+ya^2
    //   Lb^2 = xb^2+yb^2
    //
    // Pixel determination is performed relative to origin (0,0).  The
    // ellipse at origin is a*x^2+b*x*y+c*y^2=d.  Slope of curve is
    // dy/dx = -(a*x+b*y)/(b*x+c*y).  Slope at (xb,yb) is
    // dy/dx = -xb/yb >= 0 and slope at (xa,ya) is dy/dx = -xa/ya < 0.

	const Mathematics::Integer<4> iXA2 = Mathematics::Integer<4>(xa)* Mathematics::Integer<4>(xa);
	const Mathematics::Integer<4> iYA2 = Mathematics::Integer<4>(ya)*Mathematics::Integer<4>(ya);
	const Mathematics::Integer<4> iXB2 = Mathematics::Integer<4>(xb)*Mathematics::Integer<4>(xb);
	const Mathematics::Integer<4> iYB2 = Mathematics::Integer<4>(yb)*Mathematics::Integer<4>(yb);
	const Mathematics::Integer<4> iXAYA = Mathematics::Integer<4>(xa)*Mathematics::Integer<4>(ya);
	const Mathematics::Integer<4> iXBYB = Mathematics::Integer<4>(xb)*Mathematics::Integer<4>(yb);
	const Mathematics::Integer<4> iLa2 = iXA2 + iYA2;
	const Mathematics::Integer<4> iLa4 = iLa2*iLa2;
	const Mathematics::Integer<4> iLb2 = iXB2 + iYB2;
	const Mathematics::Integer<4> iLb4 = iLb2*iLb2;
	const Mathematics::Integer<4> iA = iXA2*iLb4 + iXB2*iLa4;
	const Mathematics::Integer<4> iB = iXAYA*iLb4 + iXBYB*iLa4;
	const Mathematics::Integer<4> iC = iYA2*iLb4 + iYB2*iLa4;
	const Mathematics::Integer<4> iD = iLa4*iLb4;

	Mathematics::Integer<4> dx, dy, sigma;
    int x= 0, y= 0, xp1= 0, ym1= 0, yp1= 0;

    if (ya <= xa)
    {
        // Start at (-xA,-yA).
        x = -xa;
        y = -ya;
		dx = -(iB*Mathematics::Integer<4>(xa) +iC*Mathematics::Integer<4>(ya));
		dy = iA*Mathematics::Integer<4>(xa) +iB*Mathematics::Integer<4>(ya);

        // Arc from (-xA,-yA) to point (x0,y0) where dx/dy = 0.
		while (dx <= Mathematics::Integer<4>(0))
        {
            callback(xc+x, yc+y);
            callback(xc-x, yc-y);
            y++;
			sigma = iA*Mathematics::Integer<4>(x)*Mathematics::Integer<4>(x) +Mathematics::Integer<4>(2) * iB*Mathematics::Integer<4>(x)*Mathematics::Integer<4>(y) +iC*Mathematics::Integer<4>(y)*Mathematics::Integer<4>(y) -iD;
			if (sigma < Mathematics::Integer<4>(0))
            {
                dx -= iB;
                dy += iA;
                x--;
            }
            dx += iC;
            dy -= iB;
        }

        // Arc from (x0,y0) to point (x1,y1) where dy/dx = 1.
        while (dx <= dy)
        {
            callback(xc+x, yc+y);
            callback(xc-x, yc-y);
            y++;
            xp1 = x+1;
			sigma = iA*Mathematics::Integer<4>(xp1)*Mathematics::Integer<4>(xp1) +Mathematics::Integer<4>(2) * iB*Mathematics::Integer<4>(xp1)*Mathematics::Integer<4>(y) +iC*Mathematics::Integer<4>(y)*Mathematics::Integer<4>(y) - iD;
			if (sigma >= Mathematics::Integer<4>(0))
            {
                dx += iB;
                dy -= iA;
                x = xp1;
            }
            dx += iC;
            dy -= iB;
        }

        // Arc from (x1,y1) to point (x2,y2) where dy/dx = 0.
		while (dy >= Mathematics::Integer<4>(0))
        {
            callback(xc+x, yc+y);
            callback(xc-x, yc-y);
            x++;
			sigma = iA*Mathematics::Integer<4>(x*x) + Mathematics::Integer<4>(2) * iB*Mathematics::Integer<4>(x*y) + iC*Mathematics::Integer<4>(y*y) - iD;
			if (sigma < Mathematics::Integer<4>(0))
            {
                dx += iC;
                dy -= iB;
                y++;
            }
            dx += iB;
            dy -= iA;
        }

        // Arc from (x2,y2) to point (x3,y3) where dy/dx = -1.
        while (dy >= -dx)
        {
            callback(xc+x, yc+y);
            callback(xc-x, yc-y);
            x++;
            ym1 = y-1;
			sigma = iA*Mathematics::Integer<4>(x*x) + Mathematics::Integer<4>(2) * iB*Mathematics::Integer<4>(x*ym1) + iC*Mathematics::Integer<4>(ym1*ym1) - iD;
			if (sigma >= Mathematics::Integer<4>(0))
            {
                dx -= iC;
                dy += iB;
                y = ym1;
            }
            dx += iB;
            dy -= iA;
        }

        // Arc from (x3,y3) to (xa,ya).
        while (y >= ya)
        {
            callback(xc+x, yc+y);
            callback(xc-x, yc-y);
            y--;
			sigma = iA*Mathematics::Integer<4>(x*x) + Mathematics::Integer<4>(2) * iB*Mathematics::Integer<4>(x*y) + iC*Mathematics::Integer<4>(y*y) - iD;
			if (sigma < Mathematics::Integer<4>(0))
            {
                dx += iB;
                dy -= iA;
                x++;
            }
            dx -= iC;
            dy += iB;
        }
    }
    else
    {
        // Start at (-xa,-ya).
        x = -xa;
        y = -ya;
		dx = -(iB*Mathematics::Integer<4>(xa) +iC*Mathematics::Integer<4>(ya));
		dy = iA*Mathematics::Integer<4>(xa) +iB*Mathematics::Integer<4>(ya);

        // Arc from (-xa,-ya) to point (x0,y0) where dy/dx = -1.
        while (-dx >= dy)
        {
            callback(xc+x, yc+y);
            callback(xc-x, yc-y);
            x--;
            yp1 = y+1;
			sigma = iA*Mathematics::Integer<4>(x*x) + Mathematics::Integer<4>(2) * iB*Mathematics::Integer<4>(x*yp1) + iC*Mathematics::Integer<4>(yp1*yp1) - iD;
			if (sigma >= Mathematics::Integer<4>(0))
            {
                dx += iC;
                dy -= iB;
                y = yp1;
            }
            dx -= iB;
            dy += iA;
        }

        // Arc from (x0,y0) to point (x1,y1) where dx/dy = 0.
		while (dx <= Mathematics::Integer<4>(0))
        {
            callback(xc+x, yc+y);
            callback(xc-x, yc-y);
            y++;
			sigma = iA*Mathematics::Integer<4>(x*x) + Mathematics::Integer<4>(2) * iB*Mathematics::Integer<4>(x*y) + iC*Mathematics::Integer<4>(y*y) - iD;
			if (sigma < Mathematics::Integer<4>(0))
            {
                dx -= iB;
                dy += iA;
                x--;
            }
            dx += iC;
            dy -= iB;
        }

        // Arc from (x1,y1) to point (x2,y2) where dy/dx = 1.
        while (dx <= dy)
        {
            callback(xc+x, yc+y);
            callback(xc-x, yc-y);
            y++;
            xp1 = x+1;
			sigma = iA*Mathematics::Integer<4>(xp1)*Mathematics::Integer<4>(xp1) +Mathematics::Integer<4>(2) * iB*Mathematics::Integer<4>(xp1)*Mathematics::Integer<4>(y) +iC*Mathematics::Integer<4>(y)*Mathematics::Integer<4>(y) - iD;
			if (sigma >= Mathematics::Integer<4>(0))
            {
                dx += iB;
                dy -= iA;
                x = xp1;
            }
            dx += iC;
            dy -= iB;
        }

        // Arc from (x2,y2) to point (x3,y3) where dy/dx = 0.
		while (dy >= Mathematics::Integer<4>(0))
        {
            callback(xc+x, yc+y);
            callback(xc-x, yc-y);
            x++;
			sigma = iA*Mathematics::Integer<4>(x)*Mathematics::Integer<4>(x) +Mathematics::Integer<4>(2) * iB*Mathematics::Integer<4>(x)*Mathematics::Integer<4>(y) +iC*Mathematics::Integer<4>(y)*Mathematics::Integer<4>(y) - iD;
			if (sigma < Mathematics::Integer<4>(0))
            {
                dx += iC;
                dy -= iB;
                y++;
            }
            dx += iB;
            dy -= iA;
        }

        // Arc from (x3,y3) to (xa,ya).
        while (x <= xa)
        {
            callback(xc+x, yc+y);
            callback(xc-x, yc-y);
            x++;
            ym1 = y-1;
			sigma = iA*Mathematics::Integer<4>(x)*Mathematics::Integer<4>(x) +Mathematics::Integer<4>(2) * iB*Mathematics::Integer<4>(x)*Mathematics::Integer<4>(ym1) +iC*Mathematics::Integer<4>(ym1)*Mathematics::Integer<4>(ym1) - iD;
			if (sigma >= Mathematics::Integer<4>(0))
            {
                dx -= iC;
                dy += iB;
                y = ym1;
            }
            dx += iB;
            dy -= iA;
        }
    }
}

void Imagics
	::RecursiveFill(int x, int y, int xMax, int yMax, int** image,
                    int foreColor, int backColor)
{
    image[y][x] = foreColor;

    const int xp1 = x+1;
    if (xp1 < xMax && image[y][xp1] == backColor)
    {
        RecursiveFill(xp1, y, xMax, yMax, image, foreColor, backColor);
    }

    const int xm1 = x-1;
    if (0 <= xm1 && image[y][xm1] == backColor)
    {
        RecursiveFill(xm1, y, xMax, yMax, image, foreColor, backColor);
    }

    const int yp1 = y+1;
    if (yp1 < yMax && image[yp1][x] == backColor)
    {
        RecursiveFill(x, yp1, xMax, yMax, image, foreColor, backColor);
    }

    const int ym1 = y-1;
    if (0 <= ym1 && image[ym1][x] == backColor)
    {
        RecursiveFill(x, ym1, xMax, yMax, image, foreColor, backColor);
    }
}

void Imagics
	::NonrecursiveFill(int x, int y, int xMax, int yMax,
                       int** image, int foreColor, int backColor)
{
    // Allocate the maximum amount of space needed.  If you prefer less, you
    // need to modify this data structure to allow for dynamic reallocation
    // when it is needed.  An empty stack has top == -1.
    const int quantity = xMax*yMax;
    int* xStack = NEW1<int>(quantity);
	int* yStack = NEW1<int>(quantity);

    // Push seed point onto stack if it has the background color.  All points
    // pushed onto stack have background color backColor.
    int top = 0;
    xStack[top] = x;
    yStack[top] = y;

    while (top >= 0)  // stack is not empty
    {
        // Read top of stack.  Do not pop since we need to return to this
        // top value later to restart the fill in a different direction.
        x = xStack[top];
        y = yStack[top];

        // Fill the pixel.
        image[y][x] = foreColor;

        const int xp1 = x+1;
        if (xp1 < xMax && image[y][xp1] == backColor)
        {
            // Push pixel with background color.
            ++top;
            xStack[top] = xp1;
            yStack[top] = y;
            continue;
        }

        const int xm1 = x-1;
        if (0 <= xm1 && image[y][xm1] == backColor)
        {
            // Push pixel with background color.
            ++top;
            xStack[top] = xm1;
            yStack[top] = y;
            continue;
        }

        const int yp1 = y+1;
        if (yp1 < yMax && image[yp1][x] == backColor)
        {
            // Push pixel with background color.
            ++top;
            xStack[top] = x;
            yStack[top] = yp1;
            continue;
        }

        const int ym1 = y-1;
        if (0 <= ym1 && image[ym1][x] == backColor)
        {
            // Push pixel with background color.
            ++top;
            xStack[top] = x;
            yStack[top] = ym1;
            continue;
        }

        // Done in all directions, pop and return to search other directions.
        --top;
    }

    DELETE1(xStack);
	DELETE1(yStack);
}

#include STSTEM_WARNING_POP