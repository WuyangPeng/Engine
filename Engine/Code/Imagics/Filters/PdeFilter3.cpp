// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:59)

#include "Imagics/ImagicsExport.h"

#include "PdeFilter3.h"
#include "Mathematics/Base/MathDetail.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/ImagicsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include <memory>
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26429)
Imagics::PdeFilter3 ::PdeFilter3(int xBound, int yBound, int zBound, float xSpacing, float ySpacing, float zSpacing, const float* data, const bool* mask, float borderValue, ScaleType scaleType)
    : PdeFilter(xBound * yBound * zBound, data, borderValue, scaleType),
      mXBound(xBound),
      mYBound(yBound),
      mZBound(zBound),
      mXSpacing(xSpacing),
      mYSpacing(ySpacing),
      mZSpacing(zSpacing),
      mInvDx(1.0f / xSpacing),
      mInvDy(1.0f / ySpacing),
      mInvDz(1.0f / zSpacing),
      mHalfInvDx(0.5f * mInvDx),
      mHalfInvDy(0.5f * mInvDy),
      mHalfInvDz(0.5f * mInvDz),
      mInvDxDx(mInvDx * mInvDx),
      mFourthInvDxDy(mHalfInvDx * mHalfInvDy),
      mFourthInvDxDz(mHalfInvDx * mHalfInvDz),
      mInvDyDy(mInvDy * mInvDy),
      mFourthInvDyDz(mHalfInvDy * mHalfInvDz),
      mInvDzDz(mInvDz * mInvDz)
{
    // Create two buffers for filtering, one a source buffer and one a
    // destination buffer.  Their roles are reversed on each iteration of
    // the filter.
    const int xBp2 = mXBound + 2;
    const int yBp2 = mYBound + 2;
    const int zBp2 = mZBound + 2;
    mSrc = nullptr;  //NEW3<float>(xBp2, yBp2, zBp2);
    mDst = nullptr;  //NEW3<float>(xBp2, yBp2, zBp2);
    if (mask)
    {
        mMask = nullptr;  // NEW3<bool>(xBp2, yBp2, zBp2);

        // This sets all mask values to 'false' initially.  The interior mask
        // values will be filled in later using the input mask.  The
        // boundary mask values will remain 'false'.
        memset(mMask[0][0], 0, xBp2 * yBp2 * zBp2 * sizeof(bool));
    }
    else
    {
        mMask = 0;
    }

    // Copy the inputs data and mask to the interior elements of
    // mSrc and mMask.
    int x = 0, y = 0, z = 0, xp = 0, yp = 0, zp = 0, i = 0;
    for (z = 0, zp = 1, i = 0; z < mZBound; ++z, ++zp)
    {
        for (y = 0, yp = 1; y < mYBound; ++y, ++yp)
        {
            for (x = 0, xp = 1; x < mXBound; ++x, ++xp, ++i)
            {
                mSrc[zp][yp][xp] = mOffset + (data[i] - mMin) * mScale;

                if (mMask)
                {
                    mMask[zp][yp][xp] = mask[i];
                }
            }
        }
    }

    // Assign values to the 1-voxel thick border.
    if (mBorderValue != Mathematics::MathF::maxReal)
    {
        AssignDirichletImageBorder();
    }
    else
    {
        AssignNeumannImageBorder();
    }

    // To handle masks that do not cover the entire image, assign values to
    // those voxels that are 26-neighbors of the mask voxels.
    if (mMask)
    {
        if (mBorderValue != Mathematics::MathF::maxReal)
        {
            AssignDirichletMaskBorder();
        }
        else
        {
            AssignNeumannMaskBorder();
        }
    }
}

Imagics::PdeFilter3 ::~PdeFilter3()
{
    EXCEPTION_TRY
    {
//         DELETE3(mSrc);
//         DELETE3(mDst);
//         DELETE3(mMask);
    }
    EXCEPTION_ALL_CATCH(Mathematics)
}

void Imagics::PdeFilter3 ::AssignDirichletImageBorder() noexcept
{
    int xBp1 = mXBound + 1, yBp1 = mYBound + 1, zBp1 = mZBound + 1;
    int x = 0, y = 0, z = 0;

    // vertex (0,0,0)
    mSrc[0][0][0] = mBorderValue;
    mDst[0][0][0] = mBorderValue;
    if (mMask)
    {
        mMask[0][0][0] = false;
    }

    // vertex (xmax,0,0)
    mSrc[0][0][xBp1] = mBorderValue;
    mDst[0][0][xBp1] = mBorderValue;
    if (mMask)
    {
        mMask[0][0][xBp1] = false;
    }

    // vertex (0,ymax,0)
    mSrc[0][yBp1][0] = mBorderValue;
    mDst[0][yBp1][0] = mBorderValue;
    if (mMask)
    {
        mMask[0][yBp1][0] = false;
    }

    // vertex (xmax,ymax,0)
    mSrc[0][yBp1][xBp1] = mBorderValue;
    mDst[0][yBp1][xBp1] = mBorderValue;
    if (mMask)
    {
        mMask[0][yBp1][xBp1] = false;
    }

    // vertex (0,0,zmax)
    mSrc[zBp1][0][0] = mBorderValue;
    mDst[zBp1][0][0] = mBorderValue;
    if (mMask)
    {
        mMask[zBp1][0][0] = false;
    }

    // vertex (xmax,0,zmax)
    mSrc[zBp1][0][xBp1] = mBorderValue;
    mDst[zBp1][0][xBp1] = mBorderValue;
    if (mMask)
    {
        mMask[zBp1][0][xBp1] = false;
    }

    // vertex (0,ymax,zmax)
    mSrc[zBp1][yBp1][0] = mBorderValue;
    mDst[zBp1][yBp1][0] = mBorderValue;
    if (mMask)
    {
        mMask[zBp1][yBp1][0] = false;
    }

    // vertex (xmax,ymax,zmax)
    mSrc[zBp1][yBp1][xBp1] = mBorderValue;
    mDst[zBp1][yBp1][xBp1] = mBorderValue;
    if (mMask)
    {
        mMask[zBp1][yBp1][xBp1] = false;
    }

    // edges (x,0,0) and (x,ymax,0)
    for (x = 1; x <= mXBound; ++x)
    {
        mSrc[0][0][x] = mBorderValue;
        mDst[0][0][x] = mBorderValue;
        if (mMask)
        {
            mMask[0][0][x] = false;
        }

        mSrc[0][yBp1][x] = mBorderValue;
        mDst[0][yBp1][x] = mBorderValue;
        if (mMask)
        {
            mMask[0][yBp1][x] = false;
        }
    }

    // edges (0,y,0) and (xmax,y,0)
    for (y = 1; y <= mYBound; ++y)
    {
        mSrc[0][y][0] = mBorderValue;
        mDst[0][y][0] = mBorderValue;
        if (mMask)
        {
            mMask[0][y][0] = false;
        }

        mSrc[0][y][xBp1] = mBorderValue;
        mDst[0][y][xBp1] = mBorderValue;
        if (mMask)
        {
            mMask[0][y][xBp1] = false;
        }
    }

    // edges (x,0,zmax) and (x,ymax,zmax)
    for (x = 1; x <= mXBound; ++x)
    {
        mSrc[zBp1][0][x] = mBorderValue;
        mDst[zBp1][0][x] = mBorderValue;
        if (mMask)
        {
            mMask[zBp1][0][x] = false;
        }

        mSrc[zBp1][yBp1][x] = mBorderValue;
        mDst[zBp1][yBp1][x] = mBorderValue;
        if (mMask)
        {
            mMask[zBp1][yBp1][x] = false;
        }
    }

    // edges (0,y,zmax) and (xmax,y,zmax)
    for (y = 1; y <= mYBound; ++y)
    {
        mSrc[zBp1][y][0] = mBorderValue;
        mDst[zBp1][y][0] = mBorderValue;
        if (mMask)
        {
            mMask[zBp1][y][0] = false;
        }

        mSrc[zBp1][y][xBp1] = mBorderValue;
        mDst[zBp1][y][xBp1] = mBorderValue;
        if (mMask)
        {
            mMask[zBp1][y][xBp1] = false;
        }
    }

    // edges (0,0,z) and (xmax,0,z)
    for (z = 1; z <= mZBound; ++z)
    {
        mSrc[z][0][0] = mBorderValue;
        mDst[z][0][0] = mBorderValue;
        if (mMask)
        {
            mMask[z][0][0] = false;
        }

        mSrc[z][0][xBp1] = mBorderValue;
        mDst[z][0][xBp1] = mBorderValue;
        if (mMask)
        {
            mMask[z][0][xBp1] = false;
        }
    }

    // edges (0,ymax,z) and (xmax,ymax,z)
    for (z = 1; z <= mZBound; ++z)
    {
        mSrc[z][yBp1][0] = mBorderValue;
        mDst[z][yBp1][0] = mBorderValue;
        if (mMask)
        {
            mMask[z][yBp1][0] = false;
        }

        mSrc[z][yBp1][xBp1] = mBorderValue;
        mDst[z][yBp1][xBp1] = mBorderValue;
        if (mMask)
        {
            mMask[z][yBp1][xBp1] = false;
        }
    }

    // faces (x,y,0) and (x,y,zmax)
    for (y = 1; y <= mYBound; ++y)
    {
        for (x = 1; x <= mXBound; ++x)
        {
            mSrc[0][y][x] = mBorderValue;
            mDst[0][y][x] = mBorderValue;
            if (mMask)
            {
                mMask[0][y][x] = false;
            }

            mSrc[zBp1][y][x] = mBorderValue;
            mDst[zBp1][y][x] = mBorderValue;
            if (mMask)
            {
                mMask[zBp1][y][x] = false;
            }
        }
    }

    // faces (x,0,z) and (x,ymax,z)
    for (z = 1; z <= mZBound; ++z)
    {
        for (x = 1; x <= mXBound; ++x)
        {
            mSrc[z][0][x] = mBorderValue;
            mDst[z][0][x] = mBorderValue;
            if (mMask)
            {
                mMask[z][0][x] = false;
            }

            mSrc[z][yBp1][x] = mBorderValue;
            mDst[z][yBp1][x] = mBorderValue;
            if (mMask)
            {
                mMask[z][yBp1][x] = false;
            }
        }
    }

    // faces (0,y,z) and (xmax,y,z)
    for (z = 1; z <= mZBound; ++z)
    {
        for (y = 1; y <= mYBound; ++y)
        {
            mSrc[z][y][0] = mBorderValue;
            mDst[z][y][0] = mBorderValue;
            if (mMask)
            {
                mMask[z][y][0] = false;
            }

            mSrc[z][y][xBp1] = mBorderValue;
            mDst[z][y][xBp1] = mBorderValue;
            if (mMask)
            {
                mMask[z][y][xBp1] = false;
            }
        }
    }
}

void Imagics::PdeFilter3 ::AssignNeumannImageBorder() noexcept
{
    int xBp1 = mXBound + 1, yBp1 = mYBound + 1, zBp1 = mZBound + 1;
    int x = 0, y = 0, z = 0;
    float duplicate;

    // vertex (0,0,0)
    duplicate = mSrc[1][1][1];
    mSrc[0][0][0] = duplicate;
    mDst[0][0][0] = duplicate;
    if (mMask)
    {
        mMask[0][0][0] = false;
    }

    // vertex (xmax,0,0)
    duplicate = mSrc[1][1][mXBound];
    mSrc[0][0][xBp1] = duplicate;
    mDst[0][0][xBp1] = duplicate;
    if (mMask)
    {
        mMask[0][0][xBp1] = false;
    }

    // vertex (0,ymax,0)
    duplicate = mSrc[1][mYBound][1];
    mSrc[0][yBp1][0] = duplicate;
    mDst[0][yBp1][0] = duplicate;
    if (mMask)
    {
        mMask[0][yBp1][0] = false;
    }

    // vertex (xmax,ymax,0)
    duplicate = mSrc[1][mYBound][mXBound];
    mSrc[0][yBp1][xBp1] = duplicate;
    mDst[0][yBp1][xBp1] = duplicate;
    if (mMask)
    {
        mMask[0][yBp1][xBp1] = false;
    }

    // vertex (0,0,zmax)
    duplicate = mSrc[mZBound][1][1];
    mSrc[zBp1][0][0] = duplicate;
    mDst[zBp1][0][0] = duplicate;
    if (mMask)
    {
        mMask[zBp1][0][0] = false;
    }

    // vertex (xmax,0,zmax)
    duplicate = mSrc[mZBound][1][mXBound];
    mSrc[zBp1][0][xBp1] = duplicate;
    mDst[zBp1][0][xBp1] = duplicate;
    if (mMask)
    {
        mMask[zBp1][0][xBp1] = false;
    }

    // vertex (0,ymax,zmax)
    duplicate = mSrc[mZBound][mYBound][1];
    mSrc[zBp1][yBp1][0] = duplicate;
    mDst[zBp1][yBp1][0] = duplicate;
    if (mMask)
    {
        mMask[zBp1][yBp1][0] = false;
    }

    // vertex (xmax,ymax,zmax)
    duplicate = mSrc[mZBound][mYBound][mXBound];
    mSrc[zBp1][yBp1][xBp1] = duplicate;
    mDst[zBp1][yBp1][xBp1] = duplicate;
    if (mMask)
    {
        mMask[zBp1][yBp1][xBp1] = false;
    }

    // edges (x,0,0) and (x,ymax,0)
    for (x = 1; x <= mXBound; ++x)
    {
        duplicate = mSrc[1][1][x];
        mSrc[0][0][x] = duplicate;
        mDst[0][0][x] = duplicate;
        if (mMask)
        {
            mMask[0][0][x] = false;
        }

        duplicate = mSrc[1][mYBound][x];
        mSrc[0][yBp1][x] = duplicate;
        mDst[0][yBp1][x] = duplicate;
        if (mMask)
        {
            mMask[0][yBp1][x] = false;
        }
    }

    // edges (0,y,0) and (xmax,y,0)
    for (y = 1; y <= mYBound; ++y)
    {
        duplicate = mSrc[1][y][1];
        mSrc[0][y][0] = duplicate;
        mDst[0][y][0] = duplicate;
        if (mMask)
        {
            mMask[0][y][0] = false;
        }

        duplicate = mSrc[1][y][mXBound];
        mSrc[0][y][xBp1] = duplicate;
        mDst[0][y][xBp1] = duplicate;
        if (mMask)
        {
            mMask[0][y][xBp1] = false;
        }
    }

    // edges (x,0,zmax) and (x,ymax,zmax)
    for (x = 1; x <= mXBound; ++x)
    {
        duplicate = mSrc[mZBound][1][x];
        mSrc[zBp1][0][x] = duplicate;
        mDst[zBp1][0][x] = duplicate;
        if (mMask)
        {
            mMask[zBp1][0][x] = false;
        }

        duplicate = mSrc[mZBound][mYBound][x];
        mSrc[zBp1][yBp1][x] = duplicate;
        mDst[zBp1][yBp1][x] = duplicate;
        if (mMask)
        {
            mMask[zBp1][yBp1][x] = false;
        }
    }

    // edges (0,y,zmax) and (xmax,y,zmax)
    for (y = 1; y <= mYBound; ++y)
    {
        duplicate = mSrc[mZBound][y][1];
        mSrc[zBp1][y][0] = duplicate;
        mDst[zBp1][y][0] = duplicate;
        if (mMask)
        {
            mMask[zBp1][y][0] = false;
        }

        duplicate = mSrc[mZBound][y][mXBound];
        mSrc[zBp1][y][xBp1] = duplicate;
        mDst[zBp1][y][xBp1] = duplicate;
        if (mMask)
        {
            mMask[zBp1][y][xBp1] = false;
        }
    }

    // edges (0,0,z) and (xmax,0,z)
    for (z = 1; z <= mZBound; ++z)
    {
        duplicate = mSrc[z][1][1];
        mSrc[z][0][0] = duplicate;
        mDst[z][0][0] = duplicate;
        if (mMask)
        {
            mMask[z][0][0] = false;
        }

        duplicate = mSrc[z][1][mXBound];
        mSrc[z][0][xBp1] = duplicate;
        mDst[z][0][xBp1] = duplicate;
        if (mMask)
        {
            mMask[z][0][xBp1] = false;
        }
    }

    // edges (0,ymax,z) and (xmax,ymax,z)
    for (z = 1; z <= mZBound; ++z)
    {
        duplicate = mSrc[z][mYBound][1];
        mSrc[z][yBp1][0] = duplicate;
        mDst[z][yBp1][0] = duplicate;
        if (mMask)
        {
            mMask[z][yBp1][0] = false;
        }

        duplicate = mSrc[z][mYBound][mXBound];
        mSrc[z][yBp1][xBp1] = duplicate;
        mDst[z][yBp1][xBp1] = duplicate;
        if (mMask)
        {
            mMask[z][yBp1][xBp1] = false;
        }
    }

    // faces (x,y,0) and (x,y,zmax)
    for (y = 1; y <= mYBound; ++y)
    {
        for (x = 1; x <= mXBound; ++x)
        {
            duplicate = mSrc[1][y][x];
            mSrc[0][y][x] = duplicate;
            mDst[0][y][x] = duplicate;
            if (mMask)
            {
                mMask[0][y][x] = false;
            }

            duplicate = mSrc[mZBound][y][x];
            mSrc[zBp1][y][x] = duplicate;
            mDst[zBp1][y][x] = duplicate;
            if (mMask)
            {
                mMask[zBp1][y][x] = false;
            }
        }
    }

    // faces (x,0,z) and (x,ymax,z)
    for (z = 1; z <= mZBound; ++z)
    {
        for (x = 1; x <= mXBound; ++x)
        {
            duplicate = mSrc[z][1][x];
            mSrc[z][0][x] = duplicate;
            mDst[z][0][x] = duplicate;
            if (mMask)
            {
                mMask[z][0][x] = false;
            }

            duplicate = mSrc[z][mYBound][x];
            mSrc[z][yBp1][x] = duplicate;
            mDst[z][yBp1][x] = duplicate;
            if (mMask)
            {
                mMask[z][yBp1][x] = false;
            }
        }
    }

    // faces (0,y,z) and (xmax,y,z)
    for (z = 1; z <= mZBound; ++z)
    {
        for (y = 1; y <= mYBound; ++y)
        {
            duplicate = mSrc[z][y][1];
            mSrc[z][y][0] = duplicate;
            mDst[z][y][0] = duplicate;
            if (mMask)
            {
                mMask[z][y][0] = false;
            }

            duplicate = mSrc[z][y][mXBound];
            mSrc[z][y][xBp1] = duplicate;
            mDst[z][y][xBp1] = duplicate;
            if (mMask)
            {
                mMask[z][y][xBp1] = false;
            }
        }
    }
}

void Imagics::PdeFilter3 ::AssignDirichletMaskBorder()
{
    if (mMask)
    {
        for (int z = 1; z <= mZBound; ++z)
        {
            for (int y = 1; y <= mYBound; ++y)
            {
                for (int x = 1; x <= mXBound; ++x)
                {
                    if (mMask[z][y][x])
                    {
                        continue;
                    }

                    bool found = false;
                    int i0 = 0, i1 = 0, i2 = 0, j0 = 0, j1 = 0, j2 = 0;
                    for (i2 = 0, j2 = z - 1; i2 < 3 && !found; ++i2, ++j2)
                    {
                        for (i1 = 0, j1 = y - 1; i1 < 3 && !found; ++i1, ++j1)
                        {
                            for (i0 = 0, j0 = x - 1; i0 < 3; ++i0, ++j0)
                            {
                                if (mMask[j2][j1][j0])
                                {
                                    mSrc[z][y][x] = mBorderValue;
                                    mDst[z][y][x] = mBorderValue;
                                    found = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        ASSERTION_0(false, "Mask must exist\n");
    }
}

void Imagics::PdeFilter3 ::AssignNeumannMaskBorder() noexcept
{
    // Recompute the values just outside the masked region.  This guarantees
    // that derivative estimations use the current values around the boundary.
    for (int z = 1; z <= mZBound; ++z)
    {
        for (int y = 1; y <= mYBound; ++y)
        {
            for (int x = 1; x <= mXBound; ++x)
            {
                if (mMask[z][y][x])
                {
                    continue;
                }

                int count = 0;
                float average = 0.0f;
                int i0 = 0, i1 = 0, i2 = 0, j0 = 0, j1 = 0, j2 = 0;
                for (i2 = 0, j2 = z - 1; i2 < 3; ++i2, ++j2)
                {
                    for (i1 = 0, j1 = y - 1; i1 < 3; ++i1, ++j1)
                    {
                        for (i0 = 0, j0 = x - 1; i0 < 3; ++i0, ++j0)
                        {
                            if (mMask[j2][j1][j0])
                            {
                                average += mSrc[j2][j1][j0];
                                count++;
                            }
                        }
                    }
                }

                if (count > 0)
                {
                    average /= static_cast<float>(count);
                    mSrc[z][y][x] = average;
                    mDst[z][y][x] = average;
                }
            }
        }
    }
}

void Imagics::PdeFilter3 ::OnPreUpdate() noexcept
{
    if (mMask && mBorderValue == Mathematics::MathF::maxReal)
    {
        // Neumann boundary conditions are in use, so recompute the mask
        // border.
        AssignNeumannMaskBorder();
    }
    // else: No mask has been specified or Dirichlet boundary conditions are
    // in use.  Nothing to do.
}

void Imagics::PdeFilter3 ::OnUpdate()
{
    for (int z = 1; z <= mZBound; ++z)
    {
        for (int y = 1; y <= mYBound; ++y)
        {
            for (int x = 1; x <= mXBound; ++x)
            {
                if (!mMask || mMask[z][y][x])
                {
                    OnUpdate(x, y, z);
                }
            }
        }
    }
}

void Imagics::PdeFilter3 ::OnPostUpdate() noexcept
{
    // Swap the buffers for the next pass.
    float*** save = mSrc;
    mSrc = mDst;
    mDst = save;
}

void Imagics::PdeFilter3 ::LookUp7(int x, int y, int z) noexcept
{
    const int xm = x - 1, xp = x + 1;
    const int ym = y - 1, yp = y + 1;
    const int zm = z - 1, zp = z + 1;
    mUzzm = mSrc[zm][y][x];
    mUzmz = mSrc[z][ym][x];
    mUmzz = mSrc[z][y][xm];
    mUzzz = mSrc[z][y][x];
    mUpzz = mSrc[z][y][xp];
    mUzpz = mSrc[z][yp][x];
    mUzzp = mSrc[zp][y][x];
}

void Imagics::PdeFilter3 ::LookUp27(int x, int y, int z) noexcept
{
    const int xm = x - 1, xp = x + 1;
    const int ym = y - 1, yp = y + 1;
    const int zm = z - 1, zp = z + 1;
    mUmmm = mSrc[zm][ym][xm];
    mUzmm = mSrc[zm][ym][x];
    mUpmm = mSrc[zm][ym][xp];
    mUmzm = mSrc[zm][y][xm];
    mUzzm = mSrc[zm][y][x];
    mUpzm = mSrc[zm][y][xp];
    mUmpm = mSrc[zm][yp][xm];
    mUzpm = mSrc[zm][yp][x];
    mUppm = mSrc[zm][yp][xp];
    mUmmz = mSrc[z][ym][xm];
    mUzmz = mSrc[z][ym][x];
    mUpmz = mSrc[z][ym][xp];
    mUmzz = mSrc[z][y][xm];
    mUzzz = mSrc[z][y][x];
    mUpzz = mSrc[z][y][xp];
    mUmpz = mSrc[z][yp][xm];
    mUzpz = mSrc[z][yp][x];
    mUppz = mSrc[z][yp][xp];
    mUmmp = mSrc[zp][ym][xm];
    mUzmp = mSrc[zp][ym][x];
    mUpmp = mSrc[zp][ym][xp];
    mUmzp = mSrc[zp][y][xm];
    mUzzp = mSrc[zp][y][x];
    mUpzp = mSrc[zp][y][xp];
    mUmpp = mSrc[zp][yp][xm];
    mUzpp = mSrc[zp][yp][x];
    mUppp = mSrc[zp][yp][xp];
}

int Imagics::PdeFilter3 ::GetXBound() const noexcept
{
    return mXBound;
}

int Imagics::PdeFilter3 ::GetYBound() const noexcept
{
    return mYBound;
}

int Imagics::PdeFilter3 ::GetZBound() const noexcept
{
    return mZBound;
}

float Imagics::PdeFilter3 ::GetXSpacing() const noexcept
{
    return mXSpacing;
}

float Imagics::PdeFilter3 ::GetYSpacing() const noexcept
{
    return mYSpacing;
}

float Imagics::PdeFilter3 ::GetZSpacing() const noexcept
{
    return mZSpacing;
}

float Imagics::PdeFilter3 ::GetU(int x, int y, int z) const noexcept
{
    return mSrc[z + 1][y + 1][x + 1];
}

float Imagics::PdeFilter3 ::GetUx(int x, int y, int z) const noexcept
{
    const int iYp1 = y + 1;
    const int iZp1 = z + 1;
    return mHalfInvDx * (mSrc[iZp1][iYp1][x + 2] - mSrc[iZp1][iYp1][x]);
}

float Imagics::PdeFilter3 ::GetUy(int x, int y, int z) const noexcept
{
    const int iXp1 = x + 1;
    const int iZp1 = z + 1;
    return mHalfInvDy * (mSrc[iZp1][y + 2][iXp1] - mSrc[iZp1][y][iXp1]);
}

float Imagics::PdeFilter3 ::GetUz(int x, int y, int z) const noexcept
{
    const int iXp1 = x + 1;
    const int iYp1 = y + 1;
    return mHalfInvDz * (mSrc[z + 2][iYp1][iXp1] - mSrc[z][iYp1][iXp1]);
}

float Imagics::PdeFilter3 ::GetUxx(int x, int y, int z) const noexcept
{
    const int iYp1 = y + 1;
    const int iZp1 = z + 1;
    return mInvDxDx * (mSrc[iZp1][iYp1][x + 2] - 2.0f * mSrc[iZp1][iYp1][x + 1] + mSrc[iZp1][iYp1][x]);
}

float Imagics::PdeFilter3 ::GetUxy(int x, int y, int z) const noexcept
{
    const int iXp2 = x + 2;
    const int iYp2 = y + 2;
    const int iZp1 = z + 1;
    return mFourthInvDxDy * (mSrc[iZp1][y][x] - mSrc[iZp1][y][iXp2] + mSrc[iZp1][iYp2][iXp2] - mSrc[iZp1][iYp2][x]);
}

float Imagics::PdeFilter3 ::GetUxz(int x, int y, int z) const noexcept
{
    const int iXp2 = x + 2;
    const int iYp1 = y + 1;
    const int iZp2 = z + 2;
    return mFourthInvDxDz * (mSrc[z][iYp1][x] - mSrc[z][iYp1][iXp2] + mSrc[iZp2][iYp1][iXp2] - mSrc[iZp2][iYp1][x]);
}

float Imagics::PdeFilter3 ::GetUyy(int x, int y, int z) const noexcept
{
    const int iXp1 = x + 1, iZp1 = z + 1;
    return mInvDyDy * (mSrc[iZp1][y + 2][iXp1] - 2.0f * mSrc[iZp1][y + 1][iXp1] + mSrc[iZp1][y][iXp1]);
}

float Imagics::PdeFilter3 ::GetUyz(int x, int y, int z) const noexcept
{
    const int iXp1 = x + 1, iYp2 = y + 2, iZp2 = z + 2;
    return mFourthInvDyDz * (mSrc[z][y][iXp1] - mSrc[z][iYp2][iXp1] + mSrc[iZp2][iYp2][iXp1] - mSrc[iZp2][y][iXp1]);
}

float Imagics::PdeFilter3 ::GetUzz(int x, int y, int z) const noexcept
{
    const int iXp1 = x + 1, iYp1 = y + 1;
    return mInvDzDz * (mSrc[z + 2][iYp1][iXp1] - 2.0f * mSrc[z + 1][iYp1][iXp1] + mSrc[z][iYp1][iXp1]);
}

bool Imagics::PdeFilter3 ::GetMask(int x, int y, int z) const noexcept
{
    return (mMask ? mMask[z + 1][y + 1][x + 1] : true);
}

#include STSTEM_WARNING_POP