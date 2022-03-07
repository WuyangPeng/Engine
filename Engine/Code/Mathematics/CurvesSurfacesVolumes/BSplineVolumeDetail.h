// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:49)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_VOLUME_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_VOLUME_DETAIL_H

#include "BSplineVolume.h"

#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26451)
namespace Mathematics
{

template <typename Real>
BSplineVolume<Real>::BSplineVolume (int numUCtrlPoints, int numVCtrlPoints, int numWCtrlPoints, int uDegree, int vDegree, int wDegree)
{
    MATHEMATICS_ASSERTION_0(numUCtrlPoints >= 2, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(1 <= uDegree && uDegree <= numUCtrlPoints - 1, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(numVCtrlPoints >= 2, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(1 <= vDegree && vDegree <= numVCtrlPoints - 1, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(numWCtrlPoints >= 2, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(1 <= wDegree && wDegree <= numWCtrlPoints - 1,  "Invalid input\n");

    mCtrlPoint = nullptr;  // NEW3<Vector3<Real> >(numUCtrlPoints, numVCtrlPoints, numWCtrlPoints);
    memset(mCtrlPoint[0][0], 0, numUCtrlPoints*numVCtrlPoints*numWCtrlPoints* sizeof(Vector3<Real>));

    mBasis[0].Create(numUCtrlPoints, uDegree, true);
    mBasis[1].Create(numVCtrlPoints, vDegree, true);
    mBasis[2].Create(numWCtrlPoints, wDegree, true);
}

template <typename Real>
BSplineVolume<Real>::~BSplineVolume ()
{
	EXCEPTION_TRY
{
DELETE3(mCtrlPoint);
}
EXCEPTION_ALL_CATCH(Rendering)  
    
}

template <typename Real>
int BSplineVolume<Real>::GetNumCtrlPoints (int dim) const noexcept
{
    return mBasis[dim].GetNumCtrlPoints();
}

template <typename Real>
int BSplineVolume<Real>::GetDegree (int dim) const noexcept
{
    return mBasis[dim].GetDegree();
}

template <typename Real>
void BSplineVolume<Real>::SetControlPoint (int uIndex, int vIndex,
    int wIndex, const Vector3<Real>& ctrlPoint) noexcept
{
    if (0 <= uIndex && uIndex < mBasis[0].GetNumCtrlPoints()  &&  0 <= vIndex && vIndex < mBasis[1].GetNumCtrlPoints() &&  0 <= wIndex && wIndex < mBasis[2].GetNumCtrlPoints())
    {
        mCtrlPoint[uIndex][vIndex][wIndex] = ctrlPoint;
    }
}

template <typename Real>
Vector3<Real> BSplineVolume<Real>::GetControlPoint (int uIndex, int vIndex,
    int wIndex) const noexcept
{
    if (0 <= uIndex && uIndex < mBasis[0].GetNumCtrlPoints() &&  0 <= vIndex && vIndex < mBasis[1].GetNumCtrlPoints()  &&  0 <= wIndex && wIndex < mBasis[2].GetNumCtrlPoints())
    {
        return mCtrlPoint[uIndex][vIndex][wIndex];
    }

	return Vector3<Real>{ Math<Real>::maxReal, Math<Real>::maxReal, Math<Real>::maxReal };
}

template <typename Real>
Vector3<Real> BSplineVolume<Real>::GetPosition (Real u, Real v, Real w) const
{
    int iumin, iumax, ivmin, ivmax, iwmin, iwmax;
    mBasis[0].Compute(u, 0, iumin, iumax);
    mBasis[1].Compute(v, 0, ivmin, ivmax);
    mBasis[2].Compute(w, 0, iwmin, iwmax);

	auto pos = Vector3<Real>::GetZero();
    for (auto iu = iumin; iu <= iumax; ++iu)
    {
		auto tmp0 = mBasis[0].GetD0(iu);
        for (auto iv = ivmin; iv <= ivmax; ++iv)
        {
			auto tmp1 = mBasis[1].GetD0(iv);
            for (auto iw = iwmin; iw <= iwmax; ++iw)
            {
				auto tmp2 = mBasis[2].GetD0(iw);
				auto prod = tmp0*tmp1*tmp2;
                pos += prod*mCtrlPoint[iu][iv][iw];
            }
        }
    }

    return pos;
}

template <typename Real>
Vector3<Real> BSplineVolume<Real>::GetDerivativeU (Real u, Real v, Real w)  const
{
    int iumin, iumax, ivmin, ivmax, iwmin, iwmax;
    mBasis[0].Compute(u, 1, iumin, iumax);
    mBasis[1].Compute(v, 0, ivmin, ivmax);
    mBasis[2].Compute(w, 0, iwmin, iwmax);

	auto derU = Vector3<Real>::GetZero();
    for (auto iu = iumin; iu <= iumax; ++iu)
    {
		auto tmp0 = mBasis[0].GetD1(iu);
        for (auto iv = ivmin; iv <= ivmax; ++iv)
        {
			auto tmp1 = mBasis[1].GetD0(iv);
            for (auto iw = iwmin; iw <= iwmax; ++iw)
            {
				auto tmp2 = mBasis[2].GetD0(iw);
				auto prod = tmp0*tmp1*tmp2;
                derU += prod*mCtrlPoint[iu][iv][iw];
            }
        }
    }

    return derU;
}

template <typename Real>
Vector3<Real> BSplineVolume<Real>::GetDerivativeV (Real u, Real v, Real w) const
{
    int iumin, iumax, ivmin, ivmax, iwmin, iwmax;
    mBasis[0].Compute(u, 0, iumin, iumax);
    mBasis[1].Compute(v, 1, ivmin, ivmax);
    mBasis[2].Compute(w, 0, iwmin, iwmax);

	auto derV = Vector3<Real>::GetZero();
    for (auto iu = iumin; iu <= iumax; ++iu)
    {
		auto tmp0 = mBasis[0].GetD0(iu);
        for (auto iv = ivmin; iv <= ivmax; ++iv)
        {
			auto tmp1 = mBasis[1].GetD1(iv);
            for (auto iw = iwmin; iw <= iwmax; ++iw)
            {
				auto tmp2 = mBasis[2].GetD0(iw);
				auto prod = tmp0*tmp1*tmp2;
                derV += prod*mCtrlPoint[iu][iv][iw];
            }
        }
    }

    return derV;
}

template <typename Real>
Vector3<Real> BSplineVolume<Real>::GetDerivativeW (Real u, Real v, Real w)  const
{
    int iumin, iumax, ivmin, ivmax, iwmin, iwmax;
    mBasis[0].Compute(u, 0, iumin, iumax);
    mBasis[1].Compute(v, 0, ivmin, ivmax);
    mBasis[2].Compute(w, 1, iwmin, iwmax);

	auto derW = Vector3<Real>::GetZero();
    for (auto iu = iumin; iu <= iumax; ++iu)
    {
		auto tmp0 = mBasis[0].GetD0(iu);
		for (auto iv = ivmin; iv <= ivmax; ++iv)
        {
			auto tmp1 = mBasis[1].GetD0(iv);
            for (auto iw = iwmin; iw <= iwmax; ++iw)
            {
				auto tmp2 = mBasis[2].GetD1(iw);
				auto prod = tmp0*tmp1*tmp2;
                derW += prod*mCtrlPoint[iu][iv][iw];
            }
        }
    }

    return derW;
}

template <typename Real>
Vector3<Real> BSplineVolume<Real>::GetPosition (Real pos[3]) const
{
    return GetPosition(pos[0], pos[1], pos[2]);
}

template <typename Real>
Vector3<Real> BSplineVolume<Real>::GetDerivative (int i, Real pos[3]) const
{
    switch (i)
    {
    case 0:  return GetDerivativeU(pos[0], pos[1], pos[2]);
    case 1:  return GetDerivativeV(pos[0], pos[1], pos[2]);
    case 2:
        return GetDerivativeW(pos[0], pos[1], pos[2]);
    default:
        break;
    }

    MATHEMATICS_ASSERTION_0(false, "Derivatives larger than order 3 not supported\n");
    return Vector3<Real>::GetZero();
}

}
#include STSTEM_WARNING_POP

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_VOLUME_DETAIL_H