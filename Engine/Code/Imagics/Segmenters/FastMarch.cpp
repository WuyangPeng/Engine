// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:23)

#include "Imagics/ImagicsExport.h"
 
#include "FastMarch.h"

#include "CoreTools/Helper/Assertion/ImagicsCustomAssertMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
Imagics::FastMarch
	::FastMarch(int quantity, const float* speeds,const std::vector<int>& seeds)
    : mHeap(quantity, 1, Mathematics::MathF::maxReal)
{
    Initialize(quantity,seeds);
    InitializeSpeed(speeds);
}

Imagics::FastMarch
	::FastMarch(int quantity, const float speed,const std::vector<int>& seeds)
    :mHeap(quantity, 1, Mathematics::MathF::maxReal)
{
    Initialize(quantity, seeds);
    InitializeSpeed(speed);
}

Imagics::FastMarch
	::~FastMarch()
{
	EXCEPTION_TRY
{
// DELETE1(mTrials);
// 	DELETE1(mInvSpeeds);
// 	DELETE1(mTimes);
}
EXCEPTION_ALL_CATCH(Imagics)  
    
}

void Imagics::FastMarch
	::Initialize(int quantity, const std::vector<int>& seeds)
{
    mQuantity = quantity;

    // The seed points have a crossing time of 0.  As the iterations occur,
    // some of the non-seed points are visited by the moving front.  The
    // valid crossing times are 0 <= t < MAX_REAL.  A value of MAX_REAL
    // indicates the pixel has not yet been reached by the moving front.  If
    // the speed value at a pixel is 0, the pixel is marked with a time of
    // -MAX_REAL.  Such pixels can never be visited; the minus sign
    // distinguishes these from pixels not yet reached during iteration.
    mTimes = nullptr;  //NEW1<float>(mQuantity);
   
    for (int i = 0; i < mQuantity; ++i)
    {
		mTimes[i] = Mathematics::MathF::maxReal;
    }

    for (auto i = 0u; i <  seeds.size(); ++i)
    {
        mTimes[seeds[i]] = 0.0f;
    }

    // Trial pixels are identified by having min-heap record associated with
    // them.  Known or Far pixels have no associated record.
    mTrials = nullptr;  //NEW1<int>(mQuantity);
	const size_t numBytes = mQuantity*sizeof(const CoreTools::MinHeapRecord<int, float>*);
    memset(mTrials, 0, numBytes);
}

void Imagics::FastMarch
	::InitializeSpeed(const float* speeds)
{
    // Invert the speeds since the reciprocals are all that are needed in the
    // numerical method.  Mark all zero-speed interior pixels.
    mInvSpeeds = nullptr;  //NEW1<float>(mQuantity);
    for (int i = 0; i < mQuantity; ++i)
    {
        IMAGICS_ASSERTION_0(speeds[i] >= 0.0f, "Invalid speed\n");
        if (speeds[i] > 0.0f)
        {
            mInvSpeeds[i] = 1.0f/speeds[i];
        }
        else
        {
			mInvSpeeds[i] = Mathematics::MathF::maxReal;
			mTimes[i] = -Mathematics::MathF::maxReal;
        }
    }
}

void Imagics::FastMarch
	::InitializeSpeed(const float speed)
{
    const float invSpeed = 1.0f/speed;
    mInvSpeeds = nullptr;  // NEW1<float>(mQuantity);
    for (int i = 0; i < mQuantity; ++i)
    {
        mInvSpeeds[i] = invSpeed;
    }
}

void Imagics::FastMarch
	::GetTimeExtremes(float& minValue, float& maxValue) const
{
	minValue = Mathematics::MathF::maxReal;
	maxValue = -Mathematics::MathF::maxReal;
    int i;
    for (i = 0; i < mQuantity; ++i)
    {
        if (IsValid(i))
        {
            minValue = mTimes[i];
            maxValue = minValue;
            break;
        }
    }
	IMAGICS_ASSERTION_0(i < mQuantity, "At least one time must be valid\n");

    for (/**/; i < mQuantity; ++i)
    {
        if (IsValid(i))
        {
            if (mTimes[i] < minValue)
            {
                minValue = mTimes[i];
            }
            else if (mTimes[i] > maxValue)
            {
                maxValue = mTimes[i];
            }
        }
    }
}

void Imagics::FastMarch
	::GetInterior(std::vector<int>& interior) const
{
    for (int i = 0; i < mQuantity; ++i)
    {
        if (IsValid(i) && !IsTrial(i))
        {
            interior.push_back(i);
        }
    }
}

void Imagics::FastMarch
	::SetTime(int i, float time) noexcept
{
	mTimes[i] = time;
}

float Imagics::FastMarch
	::GetTime(int i) const noexcept
{
	return mTimes[i];
}

int Imagics::FastMarch
	::GetQuantity() const noexcept
{
	return mQuantity;
}

bool Imagics::FastMarch
	::IsValid(int i) const noexcept
{
	return 0.0f <= mTimes[i] && mTimes[i] < Mathematics::MathF::maxReal;
}

bool Imagics::FastMarch
	::IsTrial(int i) const noexcept
{
	return mTrials[i] != 0;
}

bool Imagics::FastMarch
	::IsFar(int i) const noexcept
{
	return mTimes[i] == Mathematics::MathF::maxReal;
}

bool Imagics::FastMarch
	::IsZeroSpeed(int i) const noexcept
{
	return mTimes[i] == -Mathematics::MathF::maxReal;
}

bool Imagics::FastMarch ::IsInterior(int i) const noexcept
{
	return IsValid(i) && !IsTrial(i);
}
#include STSTEM_WARNING_POP