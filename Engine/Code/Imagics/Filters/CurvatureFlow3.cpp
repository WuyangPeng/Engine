// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:56)

#include "Imagics/ImagicsExport.h"

#include "CurvatureFlow3.h"

Imagics::CurvatureFlow3
	::CurvatureFlow3 (int xBound, int yBound, int zBound,float xSpacing, float ySpacing, float zSpacing, const float* data,const bool* mask, float borderValue, ScaleType scaleType)
    :PdeFilter3(xBound,yBound,zBound,xSpacing,ySpacing,zSpacing,data,mask,borderValue,scaleType)
{
}

Imagics::CurvatureFlow3
	::~CurvatureFlow3 ()
{
}

void Imagics::CurvatureFlow3
	::OnUpdate (int x, int y, int z)
{
    LookUp27(x, y, z);

    float ux = mHalfInvDx*(mUpzz - mUmzz);
    float uy = mHalfInvDy*(mUzpz - mUzmz);
    float uz = mHalfInvDz*(mUzzp - mUzzm);
    float uxx = mInvDxDx*(mUpzz - 2.0f*mUzzz + mUmzz);
    float uxy = mFourthInvDxDy*(mUmmz + mUppz - mUpmz - mUmpz);
    float uxz = mFourthInvDxDz*(mUmzm + mUpzp - mUpzm - mUmzp);
    float uyy = mInvDyDy*(mUzpz - 2.0f*mUzzz + mUzmz);
    float uyz = mFourthInvDyDz*(mUzmm+ mUzpp - mUzpm  - mUzmp);
    float uzz = mInvDzDz*(mUzzp - 2.0f*mUzzz + mUzzm);

    float gradMagSqr = ux*ux + uy*uy + uz*uz;
    float numer0 = uy*(uxx*uy - uxy*ux) + ux*(uyy*ux - uxy*uy);
    float numer1 = uz*(uxx*uz - uxz*ux) + ux*(uzz*ux - uxz*uz);
    float numer2 = uz*(uyy*uz - uyz*uy) + uy*(uzz*uy - uyz*uz);
    float denom = gradMagSqr + 1e-08f;  // prevent zero division
    float curvatureLength = (numer0 + numer1 + numer2)/denom;

    mDst[z][y][x] = mUzzz + mTimeStep*curvatureLength;
}

