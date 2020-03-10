// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:56)

#include "Imagics/ImagicsExport.h"

#include "GaussianBlur2.h"

Imagics::GaussianBlur2
	::GaussianBlur2 (int xBound, int yBound, float xSpacing,float ySpacing, const float* data, const bool* mask, float borderValue,ScaleType scaleType)
    :PdeFilter2(xBound, yBound, xSpacing, ySpacing, data, mask, borderValue,scaleType)
{
    mMaximumTimeStep = 0.5f/(mInvDxDx + mInvDyDy);
}

Imagics::GaussianBlur2
	::~GaussianBlur2 ()
{
}

float Imagics::GaussianBlur2
	::GetMaximumTimeStep () const
{
    return mMaximumTimeStep;
}

void Imagics::GaussianBlur2
	::OnUpdate (int x, int y)
{
    LookUp5(x, y);

    float uxx = mInvDxDx*(mUpz - 2.0f*mUzz + mUmz);
    float uyy = mInvDyDy*(mUzp - 2.0f*mUzz + mUzm);

    mDst[y][x] = mUzz + mTimeStep*(uxx + uyy);
}

