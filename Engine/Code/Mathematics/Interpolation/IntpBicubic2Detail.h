// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:16)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BICUBIC2_DATAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_BICUBIC2_DATAIL_H

#include "IntpBicubic2.h"

namespace Mathematics
{

template <typename Real>
IntpBicubic2<Real>::IntpBicubic2 (int xBound, int yBound, Real xMin, Real xSpacing, Real yMin, Real ySpacing, Real** F, bool catmullRom)
{
    // At least a 3x3 block of data points are needed to construct the
    // estimates of the boundary derivatives.
    MATHEMATICS_ASSERTION_0(xBound >= 3 && yBound >= 3 && F, "Invalid input\n");
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

    mBlend = (catmullRom ? msCRBlend : msBSBlend);
}

template <typename Real>
int IntpBicubic2<Real>::GetXBound () const
{
    return mXBound;
}

template <typename Real>
int IntpBicubic2<Real>::GetYBound () const
{
    return mYBound;
}

template <typename Real>
int IntpBicubic2<Real>::GetQuantity () const
{
    return m_Quantity;
}

template <typename Real>
Real** IntpBicubic2<Real>::GetF () const
{
    return mF;
}

template <typename Real>
Real IntpBicubic2<Real>::GetXMin () const
{
    return mXMin;
}

template <typename Real>
Real IntpBicubic2<Real>::GetXMax () const
{
    return mXMax;
}

template <typename Real>
Real IntpBicubic2<Real>::GetXSpacing () const
{
    return mXSpacing;
}

template <typename Real>
Real IntpBicubic2<Real>::GetYMin () const
{
    return mYMin;
}

template <typename Real>
Real IntpBicubic2<Real>::GetYMax () const
{
    return mYMax;
}

template <typename Real>
Real IntpBicubic2<Real>::GetYSpacing () const
{
    return mYSpacing;
}

template <typename Real>
Real IntpBicubic2<Real>::operator() (Real x, Real y) const
{
    // Compute x-index and clamp to image.
    Real xIndex = (x - mXMin)*mInvXSpacing;
    int ix = (int)xIndex;
    if (ix < 0 || ix > mXBound - 1)
    {
        return Math<Real>::sm_MaxReal;
    }

    // Compute y-index and clamp to image.
    Real yIndex = (y - mYMin)*mInvYSpacing;
    int iy = (int)yIndex;
    if (iy < 0 || iy > mYBound - 1)
    {
        return Math<Real>::sm_MaxReal;
    }

    Real U[4];
    U[0] = Math::GetValue(1);
    U[1] = xIndex - ix;
    U[2] = U[1]*U[1];
    U[3] = U[1]*U[2];

    Real V[4];
    V[0] = Math::GetValue(1);
    V[1] = yIndex - iy;
    V[2] = V[1]*V[1];
    V[3] = V[1]*V[2];

    // Compute P = M*U and Q = M*V.
    Real P[4], Q[4];
    int row, col;
    for (row = 0; row < 4; ++row)
    {
        P[row] = Math<Real>::GetValue(0);
        Q[row] = Math<Real>::GetValue(0);
        for (col = 0; col < 4; ++col)
        {
            P[row] += mBlend[row][col]*U[col];
            Q[row] += mBlend[row][col]*V[col];
        }
    }

    // Compute (M*U)^t D (M*V) where D is the 4x4 subimage containing (x,y).
    --ix;
    --iy;
    Real result = Math<Real>::GetValue(0);
    for (row = 0; row < 4; ++row)
    {
        int yClamp = iy + row;
        if (yClamp < 0)
        {
            yClamp = 0;
        }
        else if (yClamp > mYBound - 1)
        {
            yClamp = mYBound - 1;
        }

        for (col = 0; col < 4; ++col)
        {
            int xClamp = ix + col;
            if (xClamp < 0)
            {
                xClamp = 0;
            }
            else if (xClamp > mXBound - 1)
            {
                xClamp = mXBound - 1;
            }

            result += Q[row]*mF[yClamp][xClamp]*P[col];
        }
    }

    return result;
}

template <typename Real>
Real IntpBicubic2<Real>::operator() (int xOrder, int yOrder, Real x, Real y)   const
{
    // Compute x-index and clamp to image.
    Real xIndex = (x - mXMin)*mInvXSpacing;
    int ix = (int)xIndex;
    if (ix < 0 || ix > mXBound - 1)
    {
        return Math<Real>::sm_MaxReal;
    }

    // Compute y-index and clamp to image.
    Real yIndex = (y - mYMin)*mInvYSpacing;
    int iy = (int)yIndex;
    if (iy < 0 || iy > mYBound - 1)
    {
        return Math<Real>::sm_MaxReal;
    }

    Real U[4], dx, xMult;
    switch (xOrder)
    {
    case 0:
        dx = xIndex - ix;
        U[0] = Math::GetValue(1);
        U[1] = dx;
        U[2] = dx*U[1];
        U[3] = dx*U[2];
        xMult = Math::GetValue(1);
        break;
    case 1:
        dx = xIndex - ix;
        U[0] = Math<Real>::GetValue(0);
        U[1] = Math::GetValue(1);
        U[2] = (Math::GetValue(2))*dx;
        U[3] = (static_cast<Real>(3))*dx*dx;
        xMult = mInvXSpacing;
        break;
    case 2:
        dx = xIndex - ix;
        U[0] = Math<Real>::GetValue(0);
        U[1] = Math<Real>::GetValue(0);
        U[2] = Math::GetValue(2);
        U[3] = (Real)6*dx;
        xMult = mInvXSpacing*mInvXSpacing;
        break;
    case 3:
        U[0] = Math<Real>::GetValue(0);
        U[1] = Math<Real>::GetValue(0);
        U[2] = Math<Real>::GetValue(0);
        U[3] = (Real)6;
        xMult = mInvXSpacing*mInvXSpacing*mInvXSpacing;
        break;
    default:
        return Math<Real>::GetValue(0);
    }

    Real V[4], dy, yMult;
    switch (yOrder)
    {
    case 0:
        dy = yIndex - iy;
        V[0] = Math::GetValue(1);
        V[1] = dy;
        V[2] = dy*V[1];
        V[3] = dy*V[2];
        yMult = Math::GetValue(1);
        break;
    case 1:
        dy = yIndex - iy;
        V[0] = Math<Real>::GetValue(0);
        V[1] = Math::GetValue(1);
        V[2] = (Math::GetValue(2))*dy;
        V[3] = (static_cast<Real>(3))*dy*dy;
        yMult = mInvYSpacing;
        break;
    case 2:
        dy = yIndex - iy;
        V[0] = Math<Real>::GetValue(0);
        V[1] = Math<Real>::GetValue(0);
        V[2] = Math::GetValue(2);
        V[3] = ((Real)6)*dy;
        yMult = mInvYSpacing*mInvYSpacing;
        break;
    case 3:
        V[0] = Math<Real>::GetValue(0);
        V[1] = Math<Real>::GetValue(0);
        V[2] = Math<Real>::GetValue(0);
        V[3] = (Real)6;
        yMult = mInvYSpacing*mInvYSpacing*mInvYSpacing;
        break;
    default:
        return Math<Real>::GetValue(0);
    }

    // Compute P = M*U and Q = M*V.
    Real P[4], Q[4];
    int row, col;
    for (row = 0; row < 4; ++row)
    {
        P[row] = Math<Real>::GetValue(0);
        Q[row] = Math<Real>::GetValue(0);
        for (col = 0; col < 4; ++col)
        {
            P[row] += mBlend[row][col]*U[col];
            Q[row] += mBlend[row][col]*V[col];
        }
    }

    // Compute (M*U)^t D (M*V) where D is the 4x4 subimage containing (x,y).
    --ix;
    --iy;
    Real result = Math<Real>::GetValue(0);
    for (row = 0; row < 4; ++row)
    {
        int yClamp = iy + row;
        if (yClamp < 0)
        {
            yClamp = 0;
        }
        else if (yClamp > mYBound - 1)
        {
            yClamp = mYBound - 1;
        }

        for (col = 0; col < 4; ++col)
        {
            int xClamp = ix + col;
            if (xClamp < 0)
            {
                xClamp = 0;
            }
            else if (xClamp > mXBound - 1)
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
const Real IntpBicubic2<Real>::msCRBlend[4][4] =
{
	{ 0.0f, -0.5f,  1.0f, -0.5f },
	{ 1.0f,  0.0f, -2.5f,  1.5f },
	{ 0.0f,  0.5f,  2.0f, -1.5f },
	{ 0.0f,  0.0f, -0.5f,  0.5f }
};

template <typename Real>
const Real IntpBicubic2<Real>::msBSBlend[4][4] =
{
	{ 1.0f/6.0f, -3.0f/6.0f,  3.0f/6.0f, -1.0f/6.0f },
	{ 4.0f/6.0f,  0.0f/6.0f, -6.0f/6.0f,  3.0f/6.0f },
	{ 1.0f/6.0f,  3.0f/6.0f,  3.0f/6.0f, -3.0f/6.0f },
	{ 0.0f/6.0f,  0.0f/6.0f,  0.0f/6.0f,  1.0f/6.0f }
};

// Explicit instantiation

template<>
const float IntpBicubic2<float>::msCRBlend[4][4] =
{
    { 0.0f, -0.5f,  1.0f, -0.5f },
    { 1.0f,  0.0f, -2.5f,  1.5f },
    { 0.0f,  0.5f,  2.0f, -1.5f },
    { 0.0f,  0.0f, -0.5f,  0.5f }
};

template<>
const float IntpBicubic2<float>::msBSBlend[4][4] =
{
    { 1.0f/6.0f, -3.0f/6.0f,  3.0f/6.0f, -1.0f/6.0f },
    { 4.0f/6.0f,  0.0f/6.0f, -6.0f/6.0f,  3.0f/6.0f },
    { 1.0f/6.0f,  3.0f/6.0f,  3.0f/6.0f, -3.0f/6.0f },
    { 0.0f/6.0f,  0.0f/6.0f,  0.0f/6.0f,  1.0f/6.0f }
};


template<>
const double IntpBicubic2<double>::msCRBlend[4][4] =
{
    { 0.0, -0.5,  1.0, -0.5 },
    { 1.0,  0.0, -2.5,  1.5 },
    { 0.0,  0.5,  2.0, -1.5 },
    { 0.0,  0.0, -0.5,  0.5 }
};

template<>
const double IntpBicubic2<double>::msBSBlend[4][4] =
{
    { 1.0/6.0, -3.0/6.0,  3.0/6.0, -1.0/6.0 },
    { 4.0/6.0,  0.0/6.0, -6.0/6.0,  3.0/6.0 },
    { 1.0/6.0,  3.0/6.0,  3.0/6.0, -3.0/6.0 },
    { 0.0/6.0,  0.0/6.0,  0.0/6.0,  1.0/6.0 }
};



}


#endif // MATHEMATICS_INTERPOLATION_INTP_BICUBIC2_DATAIL_H