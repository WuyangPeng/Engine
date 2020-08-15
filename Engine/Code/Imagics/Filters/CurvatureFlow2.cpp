// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:55)

#include "Imagics/ImagicsExport.h"

#include "CurvatureFlow2.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
Imagics::CurvatureFlow2
	::CurvatureFlow2 (int xBound, int yBound, float xSpacing, float ySpacing, const float* data, const bool* mask, float borderValue, ScaleType scaleType)
    : PdeFilter2(xBound, yBound, xSpacing, ySpacing, data, mask, borderValue, scaleType)
{
}

 

void Imagics::CurvatureFlow2
	::OnUpdate (int x, int y) noexcept
{
    LookUp9(x, y);

    float ux = mHalfInvDx*(mUpz - mUmz);
    float uy = mHalfInvDy*(mUzp - mUzm);
    float uxx = mInvDxDx*(mUpz - 2.0f*mUzz + mUmz);
    float uxy = mFourthInvDxDy*(mUmm + mUpp - mUmp - mUpm);
    float uyy = mInvDyDy*(mUzp - 2.0f*mUzz + mUzm);

    float sqrUx = ux*ux;
    float sqrUy = uy*uy;
    float sqrLength = sqrUx + sqrUy + 1e-08f;  // prevent zero division
    mDst[y][x] = mUzz + mTimeStep*(uxx*sqrUy + uyy*sqrUx - 0.5f*uxy*ux*uy)/sqrLength;
}

#include STSTEM_WARNING_POP