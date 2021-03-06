// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/30 15:56)

#include "Imagics/ImagicsExport.h"

#include "GaussianBlur3.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26489)
Imagics::GaussianBlur3
	::GaussianBlur3 (int xBound, int yBound, int zBound,float xSpacing, float ySpacing, float zSpacing, const float* data,const bool* mask, float borderValue, ScaleType scaleType)
    :PdeFilter3(xBound, yBound, zBound, xSpacing, ySpacing, zSpacing, data,mask, borderValue, scaleType)
{
    mMaximumTimeStep = 0.5f/(mInvDxDx + mInvDyDy + mInvDzDz);
}

 

float Imagics::GaussianBlur3
	::GetMaximumTimeStep () const noexcept
{
    return mMaximumTimeStep;
}

void Imagics::GaussianBlur3 ::OnUpdate(int x, int y, int z) noexcept
{
    LookUp7(x, y, z);

    float uxx = mInvDxDx*(mUpzz - 2.0f*mUzzz + mUmzz);
    float uyy = mInvDyDy*(mUzpz - 2.0f*mUzzz + mUzmz);
    float uzz = mInvDzDz*(mUzzp - 2.0f*mUzzz + mUzzm);

    mDst[z][y][x] = mUzzz + mTimeStep*(uxx + uyy + uzz);
}
#include STSTEM_WARNING_POP