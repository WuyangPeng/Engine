// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:57)

#include "Imagics/ImagicsExport.h"

#include "GradientAnisotropic2.h"
#include "Mathematics/Base/MathDetail.h"

Imagics::GradientAnisotropic2
	::GradientAnisotropic2 (int xBound, int yBound,  float xSpacing, float ySpacing, const float* data, const bool* mask, float borderValue, ScaleType scaleType, float K)
    : PdeFilter2(xBound, yBound, xSpacing, ySpacing, data, mask, borderValue, scaleType)
{
    mK = K;
    ComputeParam();
}

Imagics::GradientAnisotropic2
	::~GradientAnisotropic2 ()
{
}

void Imagics::GradientAnisotropic2
	::ComputeParam ()
{
    float gradMagSqr = 0.0f;
    for (int y = 1; y <= mYBound; ++y)
    {
        for (int x = 1; x <= mXBound; ++x)
        {
            float ux = GetUx(x, y);
            float uy = GetUy(x, y);
            gradMagSqr += ux*ux + uy*uy;
        }
    }
    gradMagSqr /= (float)mQuantity;

    mParam = 1.0f/(mK*mK*gradMagSqr);
    mMHalfParam = -0.5f*mParam;
}

void Imagics::GradientAnisotropic2
	::OnPreUpdate ()
{
    ComputeParam();
}

void Imagics::GradientAnisotropic2
	::OnUpdate (int x, int y)
{
    LookUp9(x, y);

    // one-sided U-derivative estimates
    float uxFwd = mInvDx*(mUpz - mUzz);
    float uxBwd = mInvDx*(mUzz - mUmz);
    float uyFwd = mInvDy*(mUzp - mUzz);
    float uyBwd = mInvDy*(mUzz - mUzm);

    // centered U-derivative estimates
    float uxCenM = mHalfInvDx*(mUpm - mUmm);
    float uxCenZ = mHalfInvDx*(mUpz - mUmz);
    float uxCenP = mHalfInvDx*(mUpp - mUmp);
    float uyCenM = mHalfInvDy*(mUmp - mUmm);
    float uyCenZ = mHalfInvDy*(mUzp - mUzm);
    float uyCenP = mHalfInvDy*(mUpp - mUpm);

    float uxCenZSqr = uxCenZ*uxCenZ;
    float uyCenZSqr = uyCenZ*uyCenZ;
    float gradMagSqr;

    // estimate for C(x+1,y)
    float uyEstP = 0.5f*(uyCenZ + uyCenP);
    gradMagSqr = uxCenZSqr + uyEstP*uyEstP;
    float cxp = Mathematics::Mathf::Exp(mMHalfParam*gradMagSqr);

    // estimate for C(x-1,y)
    float uyEstM = 0.5f*(uyCenZ + uyCenM);
    gradMagSqr = uxCenZSqr + uyEstM*uyEstM;
    float cxm = Mathematics::Mathf::Exp(mMHalfParam*gradMagSqr);

    // estimate for C(x,y+1)
    float uxEstP = 0.5f*(uxCenZ + uxCenP);
    gradMagSqr = uyCenZSqr + uxEstP*uxEstP;
    float cyp = Mathematics::Mathf::Exp(mMHalfParam*gradMagSqr);

    // estimate for C(x,y-1)
    float uxEstM = 0.5f*(uxCenZ + uxCenM);
    gradMagSqr = uyCenZSqr + uxEstM*uxEstM;
    float cym = Mathematics::Mathf::Exp(mMHalfParam*gradMagSqr);

    mDst[y][x] = mUzz + mTimeStep*(cxp*uxFwd - cxm*uxBwd + cyp*uyFwd - cym*uyBwd);
}

