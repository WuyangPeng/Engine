// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:56)

#include "Imagics/ImagicsExport.h"

#include "GaussianBlur3.h"

Imagics::GaussianBlur3
	::GaussianBlur3 (int xBound, int yBound, int zBound,float xSpacing, float ySpacing, float zSpacing, const float* data,const bool* mask, float borderValue, ScaleType scaleType)
    :PdeFilter3(xBound, yBound, zBound, xSpacing, ySpacing, zSpacing, data,mask, borderValue, scaleType)
{
    mMaximumTimeStep = 0.5f/(mInvDxDx + mInvDyDy + mInvDzDz);
}

Imagics::GaussianBlur3
	::~GaussianBlur3 ()
{
}

float Imagics::GaussianBlur3
	::GetMaximumTimeStep () const
{
    return mMaximumTimeStep;
}

void Imagics::GaussianBlur3
	::OnUpdate (int x, int y, int z)
{
    LookUp7(x, y, z);

    float uxx = mInvDxDx*(mUpzz - 2.0f*mUzzz + mUmzz);
    float uyy = mInvDyDy*(mUzpz - 2.0f*mUzzz + mUzmz);
    float uzz = mInvDzDz*(mUzzp - 2.0f*mUzzz + mUzzm);

    mDst[z][y][x] = mUzzz + mTimeStep*(uxx + uyy + uzz);
}

