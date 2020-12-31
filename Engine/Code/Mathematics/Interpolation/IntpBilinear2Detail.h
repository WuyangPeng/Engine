// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:16)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BILINEAR2_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_BILINEAR2_DETAIL_H

#include "IntpBilinear2.h"

namespace Mathematics
{

template <typename Real>
IntpBilinear2<Real>::IntpBilinear2 (int xBound, int yBound, Real xMin,  Real xSpacing, Real yMin, Real ySpacing, Real** F)
{
    // At least a 2x2 block of data points are needed.
    MATHEMATICS_ASSERTION_0(xBound >= 2 && yBound >= 2 && F, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(xSpacing > Math<Real>::GetValue(0) && ySpacing > Math<Real>::GetValue(0), "Invalid input\n");

    mXBound = xBound;
    mYBound = yBound;
    m_Quantity = xBound*yBound;

    mXMin = xMin;
    mXSpacing = xSpacing;
    mInvXSpacing = (Math::GetValue(1))/xSpacing;
    mYMin = yMin;
    mYSpacing = ySpacing;
    mInvYSpacing = (Math::GetValue(1))/ySpacing;
    mXMax = xMin + xSpacing*(xBound - 1);
    mYMax = yMin + ySpacing*(yBound - 1);

    mF = F;
}

template <typename Real>
int IntpBilinear2<Real>::GetXBound () const
{
    return mXBound;
}

template <typename Real>
int IntpBilinear2<Real>::GetYBound () const
{
    return mYBound;
}

template <typename Real>
int IntpBilinear2<Real>::GetQuantity () const
{
    return m_Quantity;
}

template <typename Real>
Real** IntpBilinear2<Real>::GetF () const
{
    return mF;
}

template <typename Real>
Real IntpBilinear2<Real>::GetXMin () const
{
    return mXMin;
}

template <typename Real>
Real IntpBilinear2<Real>::GetXMax () const
{
    return mXMax;
}

template <typename Real>
Real IntpBilinear2<Real>::GetXSpacing () const
{
    return mXSpacing;
}

template <typename Real>
Real IntpBilinear2<Real>::GetYMin () const
{
    return mYMin;
}

template <typename Real>
Real IntpBilinear2<Real>::GetYMax () const
{
    return mYMax;
}

template <typename Real>
Real IntpBilinear2<Real>::GetYSpacing () const
{
    return mYSpacing;
}

template <typename Real>
Real IntpBilinear2<Real>::operator() (Real x, Real y) const
{
    // Check for inputs not in the domain of the function.
    if (x < mXMin || x > mXMax || y < mYMin || y > mYMax)
    {
        return Math<Real>::sm_MaxReal;
    }

    // Compute x-index and clamp to image.
    Real xIndex = (x - mXMin)*mInvXSpacing;
    int ix = (int)xIndex;
    if (ix < 0)
    {
        ix = 0;
    }
    else if (ix >= mXBound)
    {
        ix = mXBound - 1;
    }

    // Compute y-index and clamp to image.
    Real yIndex = (y - mYMin)*mInvYSpacing;
    int iy = (int)yIndex;
    if (iy < 0)
    {
        iy = 0;
    }
    else if (iy >= mYBound)
    {
        iy = mYBound - 1;
    }

    Real U[2];
    U[0] = static_cast<Real>(1.0);
    U[1] = xIndex - ix;

    Real V[2];
    V[0] = static_cast<Real>(1.0);
    V[1] = yIndex - iy;

    // Compute P = M*U and Q = M*V.
    Real P[2], Q[2];
    int row, col;
    for (row = 0; row < 2; ++row)
    {
        P[row] = Math<Real>::GetValue(0);
        Q[row] = Math<Real>::GetValue(0);
        for (col = 0; col < 2; ++col)
        {
            P[row] += msBlend[row][col]*U[col];
            Q[row] += msBlend[row][col]*V[col];
        }
    }

    // Compute (M*U)^t D (M*V) where D is the 2x2 subimage containing (x,y).
    Real result = Math<Real>::GetValue(0);
    for (row = 0; row < 2; ++row)
    {
        int yClamp = iy + row;
        if (yClamp >= mYBound)
        {
            yClamp = mYBound - 1;
        }

        for (col = 0; col < 2; ++col)
        {
            int xClamp = ix + col;
            if (xClamp >= mXBound)
            {
                xClamp = mXBound - 1;
            }

            result += Q[row]*mF[yClamp][xClamp]*P[col];
        }
    }

    return result;
}

template <typename Real>
Real IntpBilinear2<Real>::operator() (int xOrder, int yOrder, Real x, Real y)
    const
{
    // Check for inputs not in the domain of the function.
    if (x < mXMin || x > mXMax || y < mYMin || y > mYMax)
    {
        return Math<Real>::sm_MaxReal;
    }

    // Compute x-index and clamp to image.
    Real xIndex = (x - mXMin)*mInvXSpacing;
    int ix = (int)xIndex;
    if (ix < 0)
    {
        ix = 0;
    }
    else if (ix >= mXBound)
    {
        ix = mXBound - 1;
    }

    // Compute y-index and clamp to image.
    Real yIndex = (y - mYMin)*mInvYSpacing;
    int iy = (int)yIndex;
    if (iy < 0)
    {
        iy = 0;
    }
    else if (iy >= mYBound)
    {
        iy = mYBound - 1;
    }

    Real U[2], dx, xMult;
    switch (xOrder)
    {
    case 0:
        dx = xIndex - ix;
        U[0] = Math::GetValue(1);
        U[1] = dx;
        xMult = Math::GetValue(1);
        break;
    case 1:
        dx = xIndex - ix;
        U[0] = Math<Real>::GetValue(0);
        U[1] = Math::GetValue(1);
        xMult = mInvXSpacing;
        break;
    default:
        return Math<Real>::GetValue(0);
    }

    Real V[2], dy, yMult;
    switch (yOrder)
    {
    case 0:
        dy = yIndex - iy;
        V[0] = Math::GetValue(1);
        V[1] = dy;
        yMult = Math::GetValue(1);
        break;
    case 1:
        dy = yIndex - iy;
        V[0] = Math<Real>::GetValue(0);
        V[1] = Math::GetValue(1);
        yMult = mInvYSpacing;
        break;
    default:
        return Math<Real>::GetValue(0);
    }

    // Compute P = M*U and Q = M*V.
    Real P[2], Q[2];
    int row, col;
    for (row = 0; row < 2; ++row)
    {
        P[row] = Math<Real>::GetValue(0);
        Q[row] = Math<Real>::GetValue(0);
        for (col = 0; col < 2; ++col)
        {
            P[row] += msBlend[row][col]*U[col];
            Q[row] += msBlend[row][col]*V[col];
        }
    }

    // Compute (M*U)^t D (M*V) where D is the 2x2 subimage containing (x,y).
    Real result = Math<Real>::GetValue(0);
    for (row = 0; row < 2; ++row)
    {
        int yClamp = iy + row;
        if (yClamp >= mYBound)
        {
            yClamp = mYBound - 1;
        }

        for (col = 0; col < 2; ++col)
        {
            int xClamp = ix + col;
            if (xClamp >= mXBound)
            {
                xClamp = mXBound - 1;
            }

            result += Q[row]*mF[yClamp][xClamp]*P[col];
        }
    }
    result *= xMult*yMult;

    return result;
}



 

template <typename Real>
const Real IntpBilinear2<Real>::msBlend[2][2] =
{
    { 1.0f, -1.0f },
    { 0.0f,  1.0f }
};


}

#endif // MATHEMATICS_INTERPOLATION_INTP_BILINEAR2_DETAIL_H