// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:23)

#include "Imagics/ImagicsExport.h"

#include "FastMarch3.h"
#include "CoreTools/Helper/Assertion/ImagicsCustomAssertMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
#include SYSTEM_WARNING_DISABLE(26481)
const float Imagics::FastMarch3
	::msOneThird = 1.0f / 3.0f;

Imagics::FastMarch3
	::FastMarch3(int xBound, int yBound, int zBound,
                 float xSpacing, float ySpacing, float zSpacing, const float* speeds,
				 const std::vector<int>& seeds)
    :FastMarch(xBound*yBound*zBound, speeds, seeds)
{
    Initialize(xBound, yBound, zBound, xSpacing, ySpacing, zSpacing);
}

Imagics::FastMarch3
	::FastMarch3(int xBound, int yBound, int zBound,
                 float xSpacing, float ySpacing, float zSpacing, const float speed,
				 const std::vector<int>& seeds)
    :FastMarch(xBound*yBound*zBound, speed, seeds)
{
    Initialize(xBound, yBound, zBound, xSpacing, ySpacing, zSpacing);
}

 

void Imagics::FastMarch3
	::Initialize(int xBound, int yBound, int zBound,
                 float xSpacing, float ySpacing, float zSpacing)
{
    mXBound = xBound;
    mYBound = yBound;
    mZBound = zBound;
    mXYBound = xBound*yBound;
    mXBm1 = mXBound - 1;
    mYBm1 = mYBound - 1;
    mZBm1 = mZBound - 1;
    mXSpacing = xSpacing;
    mYSpacing = ySpacing;
    mZSpacing = zSpacing;
    mInvXSpacing = 1.0f/xSpacing;
    mInvYSpacing = 1.0f/ySpacing;
    mInvZSpacing = 1.0f/zSpacing;

    // Boundary pixels are marked as zero speed to allow us to avoid having
    // to process the boundary pixels separately during the iteration.
    int x = 0, y = 0, z = 0, i = 0;

    // vertex (0,0,0)
    i = Index(0,0,0);
    mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
    mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;

    // vertex (xmax,0,0)
    i = Index(mXBm1,0,0);
    mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
    mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;

    // vertex (0,ymax,0)
    i = Index(0,mYBm1,0);
    mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
    mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;

    // vertex (xmax,ymax,0)
    i = Index(mXBm1,mYBm1,0);
    mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
    mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;

    // vertex (0,0,zmax)
    i = Index(0,0,mZBm1);
    mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
    mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;

    // vertex (xmax,0,zmax)
    i = Index(mXBm1,0,mZBm1);
    mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
    mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;

    // vertex (0,ymax,zmax)
    i = Index(0,mYBm1,mZBm1);
    mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
    mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;

    // vertex (xmax,ymax,zmax)
    i = Index(mXBm1,mYBm1,mZBm1);
    mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
    mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;

    // edges (x,0,0) and (x,ymax,0)
    for (x = 0; x < mXBound; ++x)
    {
        i = Index(x,0,0);
        mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
        mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;
        i = Index(x,mYBm1,0);
        mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
        mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;
    }

    // edges (0,y,0) and (xmax,y,0)
    for (y = 0; y < mYBound; ++y)
    {
        i = Index(0,y,0);
        mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
        mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;
        i = Index(mXBm1,y,0);
        mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
        mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;
    }

    // edges (x,0,zmax) and (x,ymax,zmax)
    for (x = 0; x < mXBound; ++x)
    {
        i = Index(x,0,mZBm1);
        mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
        mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;
        i = Index(x,mYBm1,mZBm1);
        mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
        mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;
    }

    // edges (0,y,zmax) and (xmax,y,zmax)
    for (y = 0; y < mYBound; ++y)
    {
        i = Index(0,y,mZBm1);
        mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
        mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;
        i = Index(mXBm1,y,mZBm1);
        mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
        mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;
    }

    // edges (0,0,z) and (xmax,0,z)
    for (z = 0; z < mZBound; ++z)
    {
        i = Index(0,0,z);
        mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
        mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;
        i = Index(mXBm1,0,z);
        mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
        mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;
    }

    // edges (0,ymax,z) and (xmax,ymax,z)
    for (z = 0; z < mZBound; ++z)
    {
        i = Index(0,mYBm1,z);
        mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
        mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;
        i = Index(mXBm1,mYBm1,z);
        mInvSpeeds[i] = Mathematics::FloatMath::sm_MaxReal;
        mTimes[i] = -Mathematics::FloatMath::sm_MaxReal;
    }

    // Compute the first batch of trial pixels.  These are pixels a grid
    // distance of one away from the seed pixels.
    for (z = 1; z < mZBm1; ++z)
    {
        for (y = 1; y < mYBm1; ++y)
        {
            for (x = 1; x < mXBm1; ++x)
            {
                i = Index(x,y,z);
                if (IsFar(i))
                {
                    if ((IsValid(i-1) && !IsTrial(i-1))
                    ||  (IsValid(i+1) && !IsTrial(i+1))
                    ||  (IsValid(i-mXBound) && !IsTrial(i-mXBound))
                    ||  (IsValid(i+mXBound) && !IsTrial(i+mXBound))
                    ||  (IsValid(i-mXYBound) && !IsTrial(i-mXYBound))
                    ||  (IsValid(i+mXYBound) && !IsTrial(i+mXYBound)))
                    {
                        ComputeTime(i);
                        mTrials[i] = mHeap.Insert(i, mTimes[i]);
                    }
                }
            }
        }
    }
}

void Imagics::FastMarch3
	::GetBoundary(std::vector<int>& rkBoundary) const
{
    for (int i = 0; i < mQuantity; ++i)
    {
        if (IsValid(i) && !IsTrial(i))
        {
            if (IsTrial(i-1)
            ||  IsTrial(i+1)
            ||  IsTrial(i-mXBound)
            ||  IsTrial(i+mXBound)
            ||  IsTrial(i-mXYBound)
            ||  IsTrial(i+mXYBound))
            {
                rkBoundary.push_back(i);
            }
        }
    }
}

bool Imagics::FastMarch3 ::IsBoundary(int i) const noexcept
{
    if (IsValid(i) && !IsTrial(i))
    {
        if (IsTrial(i-1)
        ||  IsTrial(i+1)
        ||  IsTrial(i-mXBound)
        ||  IsTrial(i+mXBound)
        ||  IsTrial(i-mXYBound)
        ||  IsTrial(i+mXYBound))
        {
            return true;
        }
    }
    return false;
}

void Imagics::FastMarch3
	::Iterate()
{
    // Remove the minimum trial value from the heap.
   
	const CoreTools::MinHeapRecord<int, float> record = mHeap.Remove();
	int i = record.GetUniqueIndex();
	//float value = record.GetValue();

    // Promote the trial value to a known value.  The value was negative but
    // is now nonnegative (the heap stores only nonnegative numbers).
	IMAGICS_ASSERTION_0(IsTrial(i) && mTimes[i] == record.GetValue(), "Unexpected condition\n");
    mTrials[i] = 0;

    // All trial pixels must be updated.  All far neighbors must become trial
    // pixels.
    int iM1 = i - 1;
    if (IsTrial(iM1))
    {
        ComputeTime(iM1);
        mHeap.Update(mTrials[iM1], mTimes[iM1]);
    }
    else if (IsFar(iM1))
    {
        ComputeTime(iM1);
        mTrials[iM1] = mHeap.Insert(iM1, mTimes[iM1]);
    }

    int iP1 = i + 1;
    if (IsTrial(iP1))
    {
        ComputeTime(iP1);
        mHeap.Update(mTrials[iP1], mTimes[iP1]);
    }
    else if (IsFar(iP1))
    {
        ComputeTime(iP1);
        mTrials[iP1] = mHeap.Insert(iP1, mTimes[iP1]);
    }

    int iMXB = i - mXBound;
    if (IsTrial(iMXB))
    {
        ComputeTime(iMXB);
        mHeap.Update(mTrials[iMXB], mTimes[iMXB]);
    }
    else if (IsFar(iMXB))
    {
        ComputeTime(iMXB);
        mTrials[iMXB] = mHeap.Insert(iMXB, mTimes[iMXB]);
    }

    int iPXB = i + mXBound;
    if (IsTrial(iPXB))
    {
        ComputeTime(iPXB);
        mHeap.Update(mTrials[iPXB], mTimes[iPXB]);
    }
    else if (IsFar(iPXB))
    {
        ComputeTime(iPXB);
        mTrials[iPXB] = mHeap.Insert(iPXB, mTimes[iPXB]);
    }

    int iMXYB = i - mXYBound;
    if (IsTrial(iMXYB))
    {
        ComputeTime(iMXYB);
        mHeap.Update(mTrials[iMXYB], mTimes[iMXYB]);
    }
    else if (IsFar(iMXYB))
    {
        ComputeTime(iMXYB);
        mTrials[iMXYB] = mHeap.Insert(iMXYB, mTimes[iMXYB]);
    }

    int iPXYB = i + mXYBound;
    if (IsTrial(iPXYB))
    {
        ComputeTime(iPXYB);
        mHeap.Update(mTrials[iPXYB], mTimes[iPXYB]);
    }
    else if (IsFar(iPXYB))
    {
        ComputeTime(iPXYB);
        mTrials[iPXYB] = mHeap.Insert(iPXYB, mTimes[iPXYB]);
    }
}

void Imagics::FastMarch3
	::ComputeTime(int i)
{
    bool hasXTerm = false;
    float xConst = 0.0f;
    if (IsValid(i-1))
    {
        hasXTerm = true;
        xConst = mTimes[i-1];
        if (IsValid(i+1))
        {
            if (mTimes[i+1] < xConst)
            {
                xConst = mTimes[i+1];
            }
        }
    }
    else if (IsValid(i+1))
    {
        hasXTerm = true;
        xConst = mTimes[i+1];
    }
    else
    {
        hasXTerm = false;
        xConst = 0.0f;
    }

    bool hasYTerm= false;
    float yConst = 0.0f;
    if (IsValid(i-mXBound))
    {
        hasYTerm = true;
        yConst = mTimes[i-mXBound];
        if (IsValid(i+mXBound))
        {
            if (mTimes[i+mXBound] < yConst)
            {
                yConst = mTimes[i+mXBound];
            }
        }
    }
    else if (IsValid(i+mXBound))
    {
        hasYTerm = true;
        yConst = mTimes[i+mXBound];
    }
    else
    {
        hasYTerm = false;
        yConst = 0.0f;
    }

    bool hasZTerm= false;
    float zConst=0.0f;
    if (IsValid(i-mXYBound))
    {
        hasZTerm = true;
        zConst = mTimes[i-mXYBound];
        if (IsValid(i+mXYBound))
        {
            if (mTimes[i+mXYBound] < zConst)
            {
                zConst = mTimes[i+mXYBound];
            }
        }
    }
    else if (IsValid(i+mXYBound))
    {
        hasZTerm = true;
        zConst = mTimes[i+mXYBound];
    }
    else
    {
        hasZTerm = false;
        zConst = 0.0f;
    }

    float sum=0.0f, diff=0.0f, discr=0.0f;

    if (hasXTerm)
    {
        if (hasYTerm)
        {
            if (hasZTerm)
            {
                // xyz
                sum = xConst + yConst + zConst;
                discr = 3.0f*mInvSpeeds[i]*mInvSpeeds[i];
                diff = xConst - yConst;
                discr -= diff*diff;
                diff = xConst - zConst;
                discr -= diff*diff;
                diff = yConst - zConst;
                discr -= diff*diff;
                if (discr >= 0.0f)
                {
                    // The quadratic equation has a real-valued solution.
                    // Choose the largest positive root for the crossing time.
                    mTimes[i] = msOneThird*(sum + Mathematics::FloatMath::Sqrt(discr));
                }
                else
                {
                    // The quadratic equation does not have a real-valued
                    // solution.  This can happen when the speed is so large
                    // that the time gradient has very small length, which
                    // means that the time has not changed significantly from
                    // the neighbors to the current pixel.  Just choose the
                    // maximum time of the neighbors.  Is there a better
                    // choice?.
                    mTimes[i] = xConst;
                    if (yConst > mTimes[i])
                    {
                        mTimes[i] = yConst;
                    }
                    if (zConst > mTimes[i])
                    {
                        mTimes[i] = zConst;
                    }
                }
            }
            else
            {
                // xy
                sum = xConst + yConst;
                diff = xConst - yConst;
                discr = 2.0f*mInvSpeeds[i]*mInvSpeeds[i] - diff*diff;
                if (discr >= 0.0f)
                {
                    // The quadratic equation has a real-valued solution.
                    // Choose the largest positive root for the crossing time.
					mTimes[i] = 0.5f*(sum + Mathematics::FloatMath::Sqrt(discr));
                }
                else
                {
                    // The quadratic equation does not have a real-valued
                    // solution.  This can happen when the speed is so large
                    // that the time gradient has very small length, which
                    // means that the time has not changed significantly from
                    // the neighbors to the current pixel.  Just choose the
                    // maximum time of the neighbors.  Is there a better
                    // choice?.
                    mTimes[i] = (diff >= 0.0f ? xConst : yConst);
                }
            }
        }
        else
        {
            if (hasZTerm)
            {
                // xz
                sum = xConst + zConst;
                diff = xConst - zConst;
                discr = 2.0f*mInvSpeeds[i]*mInvSpeeds[i] - diff*diff;
                if (discr >= 0.0f)
                {
                    // The quadratic equation has a real-valued solution.
                    // Choose the largest positive root for the crossing time.
					mTimes[i] = 0.5f*(sum + Mathematics::FloatMath::Sqrt(discr));
                }
                else
                {
                    // The quadratic equation does not have a real-valued
                    // solution.  This can happen when the speed is so large
                    // that the time gradient has very small length, which
                    // means that the time has not changed significantly from
                    // the neighbors to the current pixel.  Just choose the
                    // maximum time of the neighbors.  Is there a better
                    // choice?.
                    mTimes[i] = (diff >= 0.0f ? xConst : zConst);
                }
            }
            else
            {
                // x
                mTimes[i] = mInvSpeeds[i] + xConst;
            }
        }
    }
    else
    {
        if (hasYTerm)
        {
            if (hasZTerm)
            {
                // yz
                sum = yConst + zConst;
                diff = yConst - zConst;
                discr = 2.0f*mInvSpeeds[i]*mInvSpeeds[i] - diff*diff;
                if (discr >= 0.0f)
                {
                    // The quadratic equation has a real-valued solution.
                    // Choose the largest positive root for the crossing time.
					mTimes[i] = 0.5f*(sum + Mathematics::FloatMath::Sqrt(discr));
                }
                else
                {
                    // The quadratic equation does not have a real-valued
                    // solution.  This can happen when the speed is so large
                    // that the time gradient has very small length, which
                    // means that the time has not changed significantly from
                    // the neighbors to the current pixel.  Just choose the
                    // maximum time of the neighbors.  Is there a better
                    // choice?.
                    mTimes[i] = (diff >= 0.0f ? yConst : zConst);
                }
            }
            else
            {
                // y
                mTimes[i] = mInvSpeeds[i] + yConst;
            }
        }
        else
        {
            if (hasZTerm)
            {
                // z
                mTimes[i] = mInvSpeeds[i] + zConst;
            }
            else
            {
                // No terms, which cannot happen.  The voxel must have at
                // least one valid neighbor.
                IMAGICS_ASSERTION_0(false, "Voxel must have a known neighbor\n");
            }
        }
    }
}


int Imagics::FastMarch3
	::GetXBound() const noexcept
{
	return mXBound;
}

int Imagics::FastMarch3 
	::GetYBound() const noexcept
{
	return mYBound;
}

int Imagics::FastMarch3
	::GetZBound() const noexcept
{
	return mZBound;
}

float Imagics::FastMarch3
	::GetXSpacing() const noexcept
{
	return mXSpacing;
}

float Imagics::FastMarch3
	::GetYSpacing() const noexcept
{
	return mYSpacing;
}

float Imagics::FastMarch3
	::GetZSpacing() const noexcept
{
	return mZSpacing;
}

int Imagics::FastMarch3
	::Index(int x, int y, int z) const noexcept
{
	return x + mXBound*(y + mYBound*z);
}

#include STSTEM_WARNING_POP