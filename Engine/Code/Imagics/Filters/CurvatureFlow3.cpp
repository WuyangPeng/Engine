// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:56)

#include "Imagics/ImagicsExport.h"

#include "CurvatureFlow3.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26489)
Imagics::CurvatureFlow3
	::CurvatureFlow3 (int xBound, int yBound, int zBound,float xSpacing, float ySpacing, float zSpacing, const float* data,const bool* mask, float borderValue, ScaleType scaleType)
    :PdeFilter3(xBound,yBound,zBound,xSpacing,ySpacing,zSpacing,data,mask,borderValue,scaleType)
{
}

 
void Imagics::CurvatureFlow3 ::OnUpdate(int x, int y, int z) noexcept
{
    LookUp27(x, y, z);

   const  float ux = mHalfInvDx*(mUpzz - mUmzz);
   const float uy = mHalfInvDy*(mUzpz - mUzmz);
   const float uz = mHalfInvDz*(mUzzp - mUzzm);
   const float uxx = mInvDxDx*(mUpzz - 2.0f*mUzzz + mUmzz);
   const float uxy = mFourthInvDxDy*(mUmmz + mUppz - mUpmz - mUmpz);
   const float uxz = mFourthInvDxDz*(mUmzm + mUpzp - mUpzm - mUmzp);
   const float uyy = mInvDyDy*(mUzpz - 2.0f*mUzzz + mUzmz);
   const float uyz = mFourthInvDyDz*(mUzmm+ mUzpp - mUzpm  - mUzmp);
   const float uzz = mInvDzDz*(mUzzp - 2.0f*mUzzz + mUzzm);

   const float gradMagSqr = ux*ux + uy*uy + uz*uz;
   const float numer0 = uy*(uxx*uy - uxy*ux) + ux*(uyy*ux - uxy*uy);
   const float numer1 = uz*(uxx*uz - uxz*ux) + ux*(uzz*ux - uxz*uz);
   const float numer2 = uz*(uyy*uz - uyz*uy) + uy*(uzz*uy - uyz*uz);
   const float denom = gradMagSqr + 1e-08f;  // prevent zero division
   const float curvatureLength = (numer0 + numer1 + numer2)/denom;

    mDst[z][y][x] = mUzzz + mTimeStep*curvatureLength;
}

#include STSTEM_WARNING_POP