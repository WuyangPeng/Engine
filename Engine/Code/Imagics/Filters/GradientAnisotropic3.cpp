// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:58)

#include "Imagics/ImagicsExport.h"

#include "GradientAnisotropic3.h"

#include <cmath>
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26489)
Imagics::GradientAnisotropic3
	::GradientAnisotropic3 (int xBound, int yBound,int zBound, float xSpacing, float ySpacing, float zSpacing,
							const float* data, const bool* mask, float borderValue,ScaleType scaleType, float K)
    :PdeFilter3(xBound, yBound, zBound, xSpacing, ySpacing, zSpacing, data,mask, borderValue, scaleType)
{
    mK = K;
    ComputeParam();
}

 

void Imagics::GradientAnisotropic3
	::ComputeParam () noexcept
{
    float gradMagSqr = 0.0f;
    for (int z = 1; z <= mZBound; ++z)
    {
        for (int y = 1; y <= mYBound; ++y)
        {
            for (int x = 1; x <= mXBound; ++x)
            {
                const float ux = GetUx(x, y, z);
                const float uy = GetUy(x, y, z);
                const float uz = GetUz(x, y, z);
                gradMagSqr += ux*ux + uy*uy + uz*uz;
            }
        }
    }
    gradMagSqr /= static_cast<float>(mQuantity);

    mParam = 1.0f/(mK*mK*gradMagSqr);
    mMHalfParam = -0.5f*mParam;
}

void Imagics::GradientAnisotropic3
	::OnPreUpdate () noexcept
{
    ComputeParam();
}

void Imagics::GradientAnisotropic3 ::OnUpdate(int x, int y, int z) noexcept
{
    LookUp27(x, y, z);

    // one-sided U-derivative estimates
    float uxFwd = mInvDx*(mUpzz - mUzzz);
    float uxBwd = mInvDx*(mUzzz - mUmzz);
    float uyFwd = mInvDy*(mUzpz - mUzzz);
    float uyBwd = mInvDy*(mUzzz - mUzmz);
    float uzFwd = mInvDz*(mUzzp - mUzzz);
    float uzBwd = mInvDz*(mUzzz - mUzzm);

    // centered U-derivative estimates
    const float duvzz = mHalfInvDx*(mUpzz - mUmzz);
    const float duvpz = mHalfInvDx*(mUppz - mUmpz);
   const float duvmz = mHalfInvDx*(mUpmz - mUmmz);
   const float duvzp = mHalfInvDx*(mUpzp - mUmzp);
   const float duvzm = mHalfInvDx*(mUpzm - mUmzm);

  const  float duzvz = mHalfInvDy*(mUzpz - mUzmz);
   const float dupvz = mHalfInvDy*(mUppz - mUpmz);
   const float dumvz = mHalfInvDy*(mUmpz - mUmmz);
   const float duzvp = mHalfInvDy*(mUzpp - mUzmp);
   const float duzvm = mHalfInvDy*(mUzpm - mUzmm);

   const float duzzv = mHalfInvDz*(mUzzp - mUzzm);
   const float dupzv = mHalfInvDz*(mUpzp - mUpzm);
   const float dumzv = mHalfInvDz*(mUmzp - mUmzm);
   const float duzpv = mHalfInvDz*(mUzpp - mUzpm);
   const float duzmv = mHalfInvDz*(mUzmp - mUzmm);

  const  float uxCenSqr = duvzz*duvzz;
   const float uyCenSqr = duzvz*duzvz;
   const float uzCenSqr = duzzv*duzzv;

    float uxEst = 0.0f, uyEst = 0.0f, uzEst = 0.0f, gradMagSqr = 0.0f;

    // estimate for C(x+1,y,z)
    uyEst = 0.5f*(duzvz + dupvz);
    uzEst = 0.5f*(duzzv + dupzv);
    gradMagSqr = uxCenSqr + uyEst*uyEst + uzEst*uzEst;
    float cxp = expf(mMHalfParam*gradMagSqr);

    // estimate for C(x-1,y,z)
    uyEst = 0.5f*(duzvz + dumvz);
    uzEst = 0.5f*(duzzv + dumzv);
    gradMagSqr = uxCenSqr + uyEst*uyEst + uzEst*uzEst;
    float cxm = expf(mMHalfParam*gradMagSqr);

    // estimate for C(x,y+1,z)
    uxEst = 0.5f*(duvzz + duvpz);
    uzEst = 0.5f*(duzzv + duzpv);
    gradMagSqr = uxEst*uxEst + uyCenSqr + uzEst*uzEst;
    float cyp = expf(mMHalfParam*gradMagSqr);

    // estimate for C(x,y-1,z)
    uxEst = 0.5f*(duvzz + duvmz);
    uzEst = 0.5f*(duzzv + duzmv);
    gradMagSqr = uxEst*uxEst + uyCenSqr + uzEst*uzEst;
    float cym = expf(mMHalfParam*gradMagSqr);

    // estimate for C(x,y,z+1)
    uxEst = 0.5f*(duvzz + duvzp);
    uyEst = 0.5f*(duzvz + duzvp);
    gradMagSqr = uxEst*uxEst + uyEst*uyEst + uzCenSqr;
    float czp = expf(mMHalfParam*gradMagSqr);

    // estimate for C(x,y,z-1)
    uxEst = 0.5f*(duvzz + duvzm);
    uyEst = 0.5f*(duzvz + duzvm);
    gradMagSqr = uxEst*uxEst + uyEst*uyEst + uzCenSqr;
    float czm = expf(mMHalfParam*gradMagSqr);

    mDst[z][y][x] = mUzzz + mTimeStep*(cxp*uxFwd - cxm*uxBwd + cyp*uyFwd - cym*uyBwd + czp*uzFwd - czm*uzBwd);
}

#include STSTEM_WARNING_POP