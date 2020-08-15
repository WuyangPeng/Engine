// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:59)

#include "Imagics/ImagicsExport.h"

#include "PdeFilter.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
Imagics::PdeFilter
	::PdeFilter (int quantity, const float* data, float borderValue, ScaleType scaleType) noexcept
{
    mQuantity = quantity;
    mBorderValue = borderValue;
    mScaleType = scaleType;
    mTimeStep = 0.0f;

    float maxValue = data[0];
    mMin = maxValue;
    for (int i = 1; i < mQuantity; i++)
    {
        const float value = data[i];
        if (value < mMin)
        {
            mMin = value;
        }
        else if (value > maxValue)
        {
            maxValue = value;
        }
    }

    if (mMin != maxValue)
    {
        switch (mScaleType)
        {
        case ScaleType::ST_NONE:
            mOffset = 0.0f;
            mScale = 1.0f;
            break;
        case ScaleType::ST_UNIT:
            mOffset = 0.0f;
            mScale = 1.0f/(maxValue - mMin);
            break;
        case ScaleType::ST_SYMMETRIC:
            mOffset = -1.0f;
            mScale = 2.0f/(maxValue - mMin);
            break;
        case ScaleType::ST_PRESERVE_ZERO:
            mOffset = 0.0f;
            mScale = (maxValue >= -mMin ? 1.0f/maxValue : -1.0f/mMin);
            mMin = 0.0f;
            break;
        }
    }
    else
    {
        mOffset = 0.0f;
        mScale = 1.0f;
    }
}

Imagics::PdeFilter
	::~PdeFilter ()
{
}

void Imagics::PdeFilter
	::Update ()
{
    OnPreUpdate();
    OnUpdate();
    OnPostUpdate();
}


int Imagics::PdeFilter
	::GetQuantity () const noexcept
{
	return mQuantity;
}

float Imagics::PdeFilter
	::GetBorderValue () const noexcept
{
	return mBorderValue;
}

Imagics::PdeFilter::ScaleType Imagics::PdeFilter
	::GetScaleType () const noexcept
{
	return mScaleType;
}

void Imagics::PdeFilter
	::SetTimeStep (float timeStep) noexcept
{ 
	mTimeStep = timeStep;
}

float Imagics::PdeFilter
	::GetTimeStep () const noexcept
{
	return mTimeStep;
}

#include STSTEM_WARNING_POP