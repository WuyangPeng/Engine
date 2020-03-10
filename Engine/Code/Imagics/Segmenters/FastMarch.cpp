// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:23)

#include "Imagics/ImagicsExport.h"
 
#include "FastMarch.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/Assertion/ImagicsCustomAssertMacro.h"

Imagics::FastMarch
	::FastMarch(int quantity, const float* speeds,const std::vector<int>& seeds)
    : mHeap(quantity, 1, Mathematics::Mathf::sm_MaxReal)
{
    Initialize(quantity,seeds);
    InitializeSpeed(speeds);
}

Imagics::FastMarch
	::FastMarch(int quantity, const float speed,const std::vector<int>& seeds)
    :mHeap(quantity, 1, Mathematics::Mathf::sm_MaxReal)
{
    Initialize(quantity, seeds);
    InitializeSpeed(speed);
}

Imagics::FastMarch
	::~FastMarch()
{
    DELETE1(mTrials);
	DELETE1(mInvSpeeds);
	DELETE1(mTimes);
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
    mTimes = NEW1<float>(mQuantity);
    int i;
    for (i = 0; i < mQuantity; ++i)
    {
		mTimes[i] = Mathematics::Mathf::sm_MaxReal;
    }

    for (i = 0; i < (int)seeds.size(); ++i)
    {
        mTimes[seeds[i]] = 0.0f;
    }

    // Trial pixels are identified by having min-heap record associated with
    // them.  Known or Far pixels have no associated record.
	mTrials = NEW1<int>(mQuantity);
	size_t numBytes = mQuantity*sizeof(const CoreTools::MinHeapRecord<int, float>*);
    memset(mTrials, 0, numBytes);
}

void Imagics::FastMarch
	::InitializeSpeed(const float* speeds)
{
    // Invert the speeds since the reciprocals are all that are needed in the
    // numerical method.  Mark all zero-speed interior pixels.
	mInvSpeeds = NEW1<float>(mQuantity);
    for (int i = 0; i < mQuantity; ++i)
    {
        IMAGICS_ASSERTION_0(speeds[i] >= 0.0f, "Invalid speed\n");
        if (speeds[i] > 0.0f)
        {
            mInvSpeeds[i] = 1.0f/speeds[i];
        }
        else
        {
			mInvSpeeds[i] = Mathematics::Mathf::sm_MaxReal;
			mTimes[i] = -Mathematics::Mathf::sm_MaxReal;
        }
    }
}

void Imagics::FastMarch
	::InitializeSpeed(const float speed)
{
    float invSpeed = 1.0f/speed;
    mInvSpeeds = NEW1<float>(mQuantity);
    for (int i = 0; i < mQuantity; ++i)
    {
        mInvSpeeds[i] = invSpeed;
    }
}

void Imagics::FastMarch
	::GetTimeExtremes(float& minValue, float& maxValue) const
{
	minValue = Mathematics::Mathf::sm_MaxReal;
	maxValue = -Mathematics::Mathf::sm_MaxReal;
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
	::SetTime(int i, float time)
{
	mTimes[i] = time;
}

float Imagics::FastMarch
	::GetTime(int i) const
{
	return mTimes[i];
}

int Imagics::FastMarch
	::GetQuantity() const
{
	return mQuantity;
}

bool Imagics::FastMarch
	::IsValid(int i) const
{
	return 0.0f <= mTimes[i] && mTimes[i] < Mathematics::Mathf::sm_MaxReal;
}

bool Imagics::FastMarch
	::IsTrial(int i) const
{
	return mTrials[i] != 0;
}

bool Imagics::FastMarch
	::IsFar(int i) const
{
	return mTimes[i] == Mathematics::Mathf::sm_MaxReal;
}

bool Imagics::FastMarch
	::IsZeroSpeed(int i) const
{
	return mTimes[i] == -Mathematics::Mathf::sm_MaxReal;
}

bool Imagics::FastMarch
	::IsInterior(int i) const
{
	return IsValid(i) && !IsTrial(i);
}
