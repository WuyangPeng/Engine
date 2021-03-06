// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 18:32)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_BASIS_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_BASIS_DETAIL_H

#include "BSplineBasis.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BSPLINE_BASIS_DETAIL)

#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h" 
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include <memory>
#include "System/Helper/PragmaWarning.h" 
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Contract/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26429)


template <typename Real>
Mathematics::BSplineBasis<Real>
	::BSplineBasis () noexcept
	:mBD1{}, mBD2{}, mBD3{}, mNumCtrlPoints{}, mDegree{}, mKnot{}, mOpen{}, mUniform{}, mBD0{}
{
}

template <typename Real>
Mathematics::BSplineBasis<Real>
	::BSplineBasis (int numCtrlPoints, int degree, bool open)
	:mBD1{}, mBD2{}, mBD3{}, mNumCtrlPoints{}, mDegree{}, mKnot{}, mOpen{}, mUniform{}, mBD0{}
{
    Create(numCtrlPoints, degree, open);
}

template <typename Real>
void Mathematics::BSplineBasis<Real>
	::Create (int numCtrlPoints, int degree, bool open)
{
    mUniform = true;

    int i = 0;
	const auto numKnots = Initialize(numCtrlPoints, degree, open);
	const auto temp = mNumCtrlPoints - mDegree;
    auto factor = (Math::GetValue(1))/(temp);
    if (mOpen)
    {
        for (i = 0; i <= mDegree; ++i)
        {
            mKnot[i] = Math::GetValue(0);
        }

        for (/**/; i < mNumCtrlPoints; ++i)
        {
			const auto temp1 = i - mDegree;
            mKnot[i] = temp1 *factor;
        }

        for (/**/; i < numKnots; ++i)
        {
            mKnot[i] = Math::GetValue(1);
        }
    }
    else
    {
        for (i = 0; i < numKnots; ++i)
        {
			const auto temp2 = i - mDegree;
            mKnot[i] = temp2 *factor;
        }
    }
}

template <typename Real>
Mathematics::BSplineBasis<Real>
	::BSplineBasis (int numCtrlPoints, int degree,const Real* interiorKnot)
	:mBD1{}, mBD2{}, mBD3{}, mNumCtrlPoints{},mDegree{},mKnot{},mOpen{}, mUniform{}, mBD0{}
{
    Create(numCtrlPoints, degree, interiorKnot);
}

template <typename Real>
void Mathematics::BSplineBasis<Real>
	::Create (int numCtrlPoints, int degree, const Real* interiorKnot)
{
    mUniform = false;

    int i = 0;
	const auto numKnots = Initialize(numCtrlPoints, degree, true);
    for (i = 0; i <= mDegree; ++i)
    {
        mKnot[i] = Math ::GetValue(0);
    }

    for (auto j = 0; i < mNumCtrlPoints; ++i, ++j)
    {
        mKnot[i] = interiorKnot[j];
    }

    for (/**/; i < numKnots; ++i)
    {
        mKnot[i] = Math::GetValue(1);
    }
}

template <typename Real>
Mathematics::BSplineBasis<Real>
	::~BSplineBasis ()
{
	
	EXCEPTION_TRY
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
 DELETE1(mKnot);
    Deallocate(mBD0);
    Deallocate(mBD1);
    Deallocate(mBD2);
    Deallocate(mBD3);
#include STSTEM_WARNING_POP
}
EXCEPTION_ALL_CATCH(Mathematics)  
    
}

template <typename Real>
int Mathematics::BSplineBasis<Real>
	::GetNumCtrlPoints () const noexcept
{
    return mNumCtrlPoints;
}

template <typename Real>
int Mathematics::BSplineBasis<Real>
	::GetDegree () const noexcept
{
    return mDegree;
}

template <typename Real>
bool Mathematics::BSplineBasis<Real>
	::IsOpen () const noexcept
{
    return mOpen;
}

template <typename Real>
bool Mathematics::BSplineBasis<Real>
	::IsUniform () const noexcept
{
    return mUniform;
}

template <typename Real>
Real Mathematics::BSplineBasis<Real>
	::GetD0 (int i) const noexcept
{
    return mBD0[mDegree][i];
}

template <typename Real>
Real Mathematics::BSplineBasis<Real>
	::GetD1 (int i) const noexcept
{
    return mBD1[mDegree][i];
}

template <typename Real>
Real Mathematics::BSplineBasis<Real>
	::GetD2 (int i) const noexcept
{
    return mBD2[mDegree][i];
}

template <typename Real>
Real Mathematics::BSplineBasis<Real>
	::GetD3 (int i) const noexcept
{
    return mBD3[mDegree][i];
}

template <typename Real>
Real** Mathematics::BSplineBasis<Real>
	::Allocate () const
{
	const auto numRows = mDegree + 1;
	const auto numCols = mNumCtrlPoints + mDegree;
    Real** data = NEW2<Real>(numCols, numRows);
	const auto num = numRows * numCols;
    memset(data[0], 0, num *sizeof(Real));
    return data;
}

template <typename Real>
void Mathematics::BSplineBasis<Real>
	::Deallocate (Real** data)   
{
    CoreTools::DisableNoexcept();

    DELETE2(data);
}

template <typename Real>
int Mathematics::BSplineBasis<Real>
	::Initialize (int numCtrlPoints, int degree, bool open)
{
    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree <= numCtrlPoints-1, "Invalid input\n");

    mNumCtrlPoints = numCtrlPoints;
    mDegree = degree;
    mOpen = open;

    const int numKnots = mNumCtrlPoints + mDegree + 1;
    mKnot = NEW1<Real>(numKnots);

    mBD0 = Allocate();
    mBD1 = 0;
    mBD2 = 0;
    mBD3 = 0;

    return numKnots;
}

template <typename Real>
void Mathematics::BSplineBasis<Real>
	::SetKnot (int j, Real value)
{
    if (!mUniform)
    {
        // Access only allowed to elements d+1 <= i <= n.
		const auto i = j + mDegree + 1;
        if (mDegree + 1 <= i && i <= mNumCtrlPoints)
        {
            mKnot[i] = value;
        }
        else
        {
            MATHEMATICS_ASSERTION_0(false, "Knot index out of range.\n");
        }
    }
    else
    {
        MATHEMATICS_ASSERTION_0(false, "Knots cannot be set for uniform splines.\n");
    }
}

template <typename Real>
Real Mathematics::BSplineBasis<Real>
	::GetKnot (int j) const 
{
    // Access only allowed to elements d+1 <= i <= n.
	const auto i = j + mDegree + 1;
    if (mDegree + 1 <= i && i <= mNumCtrlPoints)
    {
        return mKnot[i];
    }

    MATHEMATICS_ASSERTION_0(false, "Knot index out of range.\n");
	
	CoreTools::DisableNoexcept();
	
    return Math::sm_MaxReal;
}

template <typename Real>
int Mathematics::BSplineBasis<Real>
	::GetKey (Real& t) const noexcept
{
    if (mOpen)
    {
        // Open splines clamp to [0,1].
        if (t <= Math::GetValue(0))
        {
            t = Math::GetValue(0);
            return mDegree;
        }
        else if (t >= Math::GetValue(1))
        {
            t = Math::GetValue(1);
            return mNumCtrlPoints - 1;
        }
    }
    else
    {
        // Periodic splines wrap to [0,1).
        if (t < Math::GetValue(0) || t >= Math::GetValue(1))
        {
            t -= Math::Floor(t);
        }
    }


    int i = 0;

    if (mUniform)
    {
        i = mDegree + static_cast<int>((mNumCtrlPoints - mDegree)*t);
    }
    else
    {
        for (i = mDegree + 1; i <= mNumCtrlPoints; ++i)
        {
            if (t < mKnot[i])
            {
                break;
            }
        }
        --i;
    }

    return i;
}

template <typename Real>
void Mathematics::BSplineBasis<Real>
	::Compute (Real t, unsigned int order, int& minIndex, int& maxIndex) const
{
    MATHEMATICS_ASSERTION_0(order <= 3, "Only derivatives to third order supported\n");

    if (order >= 1)
    {
        if (!mBD1)
        {
            mBD1 = Allocate();
        }

        if (order >= 2)
        {
            if (!mBD2)
            {
                mBD2 = Allocate();
            }

            if (order >= 3)
            {
                if (!mBD3)
                {
                    mBD3 = Allocate();
                }
            }
        }
    }

	auto i = GetKey(t);
    mBD0[0][i] = Math::GetValue(1);

    if (order >= 1)
    {
        mBD1[0][i] = Math::GetValue(0);
        if (order >= 2)
        {
            mBD2[0][i] = Math::GetValue(0);
            if (order >= 3)
            {
                mBD3[0][i] = Math::GetValue(0);
            }
        }
    }

    Real n0 = t - mKnot[i], n1 = mKnot[i+1] - t;
    Real invD0 = 0, invD1 = 0;
    int j = 0;
    for (j = 1; j <= mDegree; j++)
    {
        invD0 = (Math::GetValue(1))/(mKnot[i+j] - mKnot[i]);
        invD1 = (Math::GetValue(1))/(mKnot[i+1] - mKnot[i-j+1]);

        mBD0[j][i] = n0*mBD0[j-1][i]*invD0;
        mBD0[j][i-j] = n1*mBD0[j-1][i-j+1]*invD1;

        if (order >= 1)
        {
            mBD1[j][i] = (n0*mBD1[j-1][i] + mBD0[j-1][i])*invD0;
            mBD1[j][i-j] = (n1*mBD1[j-1][i-j+1] - mBD0[j-1][i-j+1])*invD1;

            if (order >= 2)
            {
                mBD2[j][i] = (n0*mBD2[j-1][i] + (Math::GetValue(2))*mBD1[j-1][i])*invD0;
                mBD2[j][i-j] = (n1*mBD2[j-1][i-j+1] -   (Math::GetValue(2))*mBD1[j-1][i-j+1])*invD1;

                if (order >= 3)
                {
                    mBD3[j][i] = (n0*mBD3[j-1][i] +  (static_cast<Real>(3))*mBD2[j-1][i])*invD0;
                    mBD3[j][i-j] = (n1*mBD3[j-1][i-j+1] -  (static_cast<Real>(3))*mBD2[j-1][i-j+1])*invD1;
                }
            }
        }
    }

    for (j = 2; j <= mDegree; ++j)
    {
        for (int k = i-j+1; k < i; ++k)
        {
            n0 = t - mKnot[k];
            n1 = mKnot[k+j+1] - t;
            invD0 = (Math::GetValue(1))/(mKnot[k+j] - mKnot[k]);
            invD1 = (Math::GetValue(1))/(mKnot[k+j+1] - mKnot[k+1]);

            mBD0[j][k] = n0*mBD0[j-1][k]*invD0 + n1*mBD0[j-1][k+1]*invD1;

            if (order >= 1)
            {
                mBD1[j][k] = (n0*mBD1[j-1][k]+mBD0[j-1][k])*invD0 +  (n1*mBD1[j-1][k+1]-mBD0[j-1][k+1])*invD1;

                if (order >= 2)
                {
                    mBD2[j][k] = (n0*mBD2[j-1][k] +   (Math::GetValue(2))*mBD1[j-1][k])*invD0 +   (n1*mBD2[j-1][k+1] - (Math::GetValue(2))*mBD1[j-1][k+1])*invD1;

                    if (order >= 3)
                    {
                        mBD3[j][k] = (n0*mBD3[j-1][k] +   (static_cast<Real>(3))*mBD2[j-1][k])*invD0 + (n1*mBD3[j-1][k+1] - (static_cast<Real>(3))*  mBD2[j-1][k+1])*invD1;
                    }
                }
            }
        }
    }

    minIndex = i - mDegree;
    maxIndex = i;
}
#include STSTEM_WARNING_POP

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BSPLINE_BASIS_DETAIL)

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_BASIS_DETAIL_H