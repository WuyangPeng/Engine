// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:57)

#include "Imagics/ImagicsExport.h"

#include "GradientAnisotropic2.h"
#include "Mathematics/Base/MathDetail.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26440)
Imagics::GradientAnisotropic2
	::GradientAnisotropic2 (int xBound, int yBound,  float xSpacing, float ySpacing, const float* data, const bool* mask, float borderValue, ScaleType scaleType, float K)
    : PdeFilter2(xBound, yBound, xSpacing, ySpacing, data, mask, borderValue, scaleType)
{
    mK = K;
    ComputeParam();
}

 

void Imagics::GradientAnisotropic2
	::ComputeParam () noexcept
{
    float gradMagSqr = 0.0f;
    for (int y = 1; y <= mYBound; ++y)
    {
        for (int x = 1; x <= mXBound; ++x)
        {
            const float ux = GetUx(x, y);
            const float uy = GetUy(x, y);
            gradMagSqr += ux*ux + uy*uy;
        }
    }
    gradMagSqr /= static_cast<float>(mQuantity);

    mParam = 1.0f/(mK*mK*gradMagSqr);
    mMHalfParam = -0.5f*mParam;
}

void Imagics::GradientAnisotropic2
	::OnPreUpdate () noexcept
{
    ComputeParam();
}

void Imagics::GradientAnisotropic2 ::OnUpdate(int x, int y)  
{
    LookUp9(x, y);

    // one-sided U-derivative estimates
    float uxFwd = mInvDx*(mUpz - mUzz);
    float uxBwd = mInvDx*(mUzz - mUmz);
    float uyFwd = mInvDy*(mUzp - mUzz);
    float uyBwd = mInvDy*(mUzz - mUzm);

    // centered U-derivative estimates
   const float uxCenM = mHalfInvDx*(mUpm - mUmm);
    const float uxCenZ = mHalfInvDx*(mUpz - mUmz);
   const float uxCenP = mHalfInvDx*(mUpp - mUmp);
   const float uyCenM = mHalfInvDy*(mUmp - mUmm);
   const float uyCenZ = mHalfInvDy*(mUzp - mUzm);
   const float uyCenP = mHalfInvDy*(mUpp - mUpm);

  const  float uxCenZSqr = uxCenZ*uxCenZ;
  const  float uyCenZSqr = uyCenZ*uyCenZ;
    float gradMagSqr = 0.0f;

    // estimate for C(x+1,y)
  const  float uyEstP = 0.5f*(uyCenZ + uyCenP);
    gradMagSqr = uxCenZSqr + uyEstP*uyEstP;
    float cxp = Mathematics::FloatMath::Exp(mMHalfParam*gradMagSqr);

    // estimate for C(x-1,y)
 const   float uyEstM = 0.5f*(uyCenZ + uyCenM);
    gradMagSqr = uxCenZSqr + uyEstM*uyEstM;
    float cxm = Mathematics::FloatMath::Exp(mMHalfParam*gradMagSqr);

    // estimate for C(x,y+1)
 const   float uxEstP = 0.5f*(uxCenZ + uxCenP);
    gradMagSqr = uyCenZSqr + uxEstP*uxEstP;
    float cyp = Mathematics::FloatMath::Exp(mMHalfParam*gradMagSqr);

    // estimate for C(x,y-1)
  const  float uxEstM = 0.5f*(uxCenZ + uxCenM);
    gradMagSqr = uyCenZSqr + uxEstM*uxEstM;
    float cym = Mathematics::FloatMath::Exp(mMHalfParam*gradMagSqr);

    mDst[y][x] = mUzz + mTimeStep*(cxp*uxFwd - cxm*uxBwd + cyp*uyFwd - cym*uyBwd);
}

#include STSTEM_WARNING_POP