// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:44)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_RECTANGLE_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_RECTANGLE_DETAIL_H

#include "BSplineRectangle.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26489)
namespace Mathematics
{
    template <typename Real>
    BSplineRectangle<Real>::BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, Vector3D<Real>** ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, bool vOpen)
        : ParametricSurface<Real>{ Math::GetValue(0), Math::GetValue(1), Math::GetValue(0), Math::GetValue(1), true }
    {
        MATHEMATICS_ASSERTION_0(numUCtrlPoints >= 2, "Invalid input\n");
        MATHEMATICS_ASSERTION_0(1 <= uDegree && uDegree <= numUCtrlPoints - 1, "Invalid input\n");
        MATHEMATICS_ASSERTION_0(numVCtrlPoints >= 2, "Invalid input\n");
        MATHEMATICS_ASSERTION_0(1 <= vDegree && vDegree <= numVCtrlPoints - 1, "Invalid input\n");

        mLoop[0] = uLoop;
        mLoop[1] = vLoop;

        mNumUCtrlPoints = numUCtrlPoints;
        mNumVCtrlPoints = numVCtrlPoints;
        mUReplicate = (uLoop ? (uOpen ? 1 : uDegree) : 0);
        mVReplicate = (vLoop ? (vOpen ? 1 : vDegree) : 0);
        CreateControl(ctrlPoint);

        mBasis[0].Create(mNumUCtrlPoints + mUReplicate, uDegree, uOpen);
        mBasis[1].Create(mNumVCtrlPoints + mVReplicate, vDegree, vOpen);
    }

    template <typename Real>
    BSplineRectangle<Real>::BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, Vector3D<Real>** ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, Real* vKnot)
        : ParametricSurface<Real>{ Math ::GetValue(0), Math::GetValue(1), Math ::GetValue(0), Math::GetValue(1), true }
    {
        MATHEMATICS_ASSERTION_0(numUCtrlPoints >= 2, "Invalid input\n");
        MATHEMATICS_ASSERTION_0(1 <= uDegree && uDegree <= numUCtrlPoints - 1, "Invalid input\n");
        MATHEMATICS_ASSERTION_0(numVCtrlPoints >= 2, "Invalid input\n");
        MATHEMATICS_ASSERTION_0(1 <= vDegree && vDegree <= numVCtrlPoints - 1, "Invalid input\n");

        mLoop[0] = uLoop;
        mLoop[1] = vLoop;

        mNumUCtrlPoints = numUCtrlPoints;
        mNumVCtrlPoints = numVCtrlPoints;
        mUReplicate = (uLoop ? (uOpen ? 1 : uDegree) : 0);
        mVReplicate = (vLoop ? 1 : 0);
        CreateControl(ctrlPoint);

        mBasis[0].Create(mNumUCtrlPoints + mUReplicate, uDegree, uOpen);
        mBasis[1].Create(mNumVCtrlPoints + mVReplicate, vDegree, vKnot);
    }

    template <typename Real>
    BSplineRectangle<Real>::BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, Vector3D<Real>** ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, Real* uKnot, bool vOpen)
        : ParametricSurface<Real>{ Math ::GetValue(0), Math::GetValue(1), Math ::GetValue(0), Math::GetValue(1), true }
    {
        MATHEMATICS_ASSERTION_0(numUCtrlPoints >= 2, "Invalid input\n");
        MATHEMATICS_ASSERTION_0(1 <= uDegree && uDegree <= numUCtrlPoints - 1, "Invalid input\n");
        MATHEMATICS_ASSERTION_0(numVCtrlPoints >= 2, "Invalid input\n");
        MATHEMATICS_ASSERTION_0(1 <= vDegree && vDegree <= numVCtrlPoints - 1, "Invalid input\n");

        mLoop[0] = uLoop;
        mLoop[1] = vLoop;

        mNumUCtrlPoints = numUCtrlPoints;
        mNumVCtrlPoints = numVCtrlPoints;
        mUReplicate = (uLoop ? 1 : 0);
        mVReplicate = (vLoop ? (vOpen ? 1 : vDegree) : 0);
        CreateControl(ctrlPoint);

        mBasis[0].Create(mNumUCtrlPoints + mUReplicate, uDegree, uKnot);
        mBasis[1].Create(mNumVCtrlPoints + mVReplicate, vDegree, vOpen);
    }

    template <typename Real>
    BSplineRectangle<Real>::BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, Vector3D<Real>** ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, Real* uKnot, Real* vKnot)
        : ParametricSurface<Real>{ Math ::GetValue(0), Math::GetValue(1), Math ::GetValue(0), Math::GetValue(1), true }
    {
        MATHEMATICS_ASSERTION_0(numUCtrlPoints >= 2, "Invalid input\n");
        MATHEMATICS_ASSERTION_0(1 <= uDegree && uDegree <= numUCtrlPoints - 1, "Invalid input\n");
        MATHEMATICS_ASSERTION_0(numVCtrlPoints >= 2, "Invalid input\n");
        MATHEMATICS_ASSERTION_0(1 <= vDegree && vDegree <= numVCtrlPoints - 1, "Invalid input\n");

        mLoop[0] = uLoop;
        mLoop[1] = vLoop;

        mNumUCtrlPoints = numUCtrlPoints;
        mNumVCtrlPoints = numVCtrlPoints;
        mUReplicate = (uLoop ? 1 : 0);
        mVReplicate = (vLoop ? 1 : 0);
        CreateControl(ctrlPoint);

        mBasis[0].Create(mNumUCtrlPoints + mUReplicate, uDegree, uKnot);
        mBasis[1].Create(mNumVCtrlPoints + mVReplicate, vDegree, vKnot);
    }

    template <typename Real>
    BSplineRectangle<Real>::~BSplineRectangle()
    {
        EXCEPTION_TRY
        {
            DELETE2(mCtrlPoint);
        }
        EXCEPTION_ALL_CATCH(Mathematics)
    }

    template <typename Real>
    void BSplineRectangle<Real>::CreateControl(Vector3D<Real>** ctrlPoint)
    {
        const auto newNumUCtrlPoints = mNumUCtrlPoints + mUReplicate;
        const auto newNumVCtrlPoints = mNumVCtrlPoints + mVReplicate;
        mCtrlPoint = NEW2<Vector3D<Real>>(newNumVCtrlPoints, newNumUCtrlPoints);

        for (auto u = 0; u < newNumUCtrlPoints; ++u)
        {
            auto uOld = u % mNumUCtrlPoints;
            for (auto v = 0; v < newNumVCtrlPoints; ++v)
            {
                auto vOld = v % mNumVCtrlPoints;
                mCtrlPoint[u][v] = ctrlPoint[uOld][vOld];
            }
        }
    }

    template <typename Real>
    int BSplineRectangle<Real>::GetNumCtrlPoints(int dim) const noexcept
    {
        return mBasis[dim].GetNumCtrlPoints();
    }

    template <typename Real>
    int BSplineRectangle<Real>::GetDegree(int dim) const noexcept
    {
        return mBasis[dim].GetDegree();
    }

    template <typename Real>
    bool BSplineRectangle<Real>::IsOpen(int dim) const noexcept
    {
        return mBasis[dim].IsOpen();
    }

    template <typename Real>
    bool BSplineRectangle<Real>::IsUniform(int dim) const
    {
        return mBasis[dim].IsUniform();
    }

    template <typename Real>
    bool BSplineRectangle<Real>::IsLoop(int dim) const noexcept
    {
        return mLoop[dim];
    }

    template <typename Real>
    void BSplineRectangle<Real>::SetControlPoint(int uIndex, int vIndex, const Vector3D<Real>& ctrl)
    {
        if (0 <= uIndex && uIndex < mNumUCtrlPoints && 0 <= vIndex && vIndex < mNumVCtrlPoints)
        {
            // Set the control point.
            mCtrlPoint[uIndex][vIndex] = ctrl;

            // Set the replicated control point.
            auto doUReplicate = (uIndex < mUReplicate);
            auto doVReplicate = (vIndex < mVReplicate);
            int iUExt = 0, iVExt = 0;

            if (doUReplicate)
            {
                iUExt = mNumUCtrlPoints + uIndex;
                mCtrlPoint[iUExt][vIndex] = ctrl;
            }
            if (doVReplicate)
            {
                iVExt = mNumVCtrlPoints + vIndex;
                mCtrlPoint[uIndex][iVExt] = ctrl;
            }
            if (doUReplicate && doVReplicate)
            {
                mCtrlPoint[iUExt][iVExt] = ctrl;
            }
        }
    }

    template <typename Real>
    Vector3D<Real> BSplineRectangle<Real>::GetControlPoint(int uIndex, int vIndex) const noexcept
    {
        if (0 <= uIndex && uIndex < mNumUCtrlPoints && 0 <= vIndex && vIndex < mNumVCtrlPoints)
        {
            return mCtrlPoint[uIndex][vIndex];
        }

        return Vector3D<Real>{ Math ::sm_MaxReal, Math ::sm_MaxReal, Math ::sm_MaxReal };
    }

    template <typename Real>
    void BSplineRectangle<Real>::SetKnot(int dim, int i, Real knot)
    {
        if (0 <= dim && dim <= 1)
        {
            mBasis[dim].SetKnot(i, knot);
        }
    }

    template <typename Real>
    Real BSplineRectangle<Real>::GetKnot(int dim, int i) const
    {
        if (0 <= dim && dim <= 1)
        {
            return mBasis[dim].GetKnot(i);
        }

        return Math ::sm_MaxReal;
    }

    template <typename Real>
    void BSplineRectangle<Real>::Get(Real u, Real v, Vector3D<Real>* pos, Vector3D<Real>* derU, Vector3D<Real>* derV, Vector3D<Real>* derUU, Vector3D<Real>* derUV, Vector3D<Real>* derVV) const
    {
        int iu = 0, iumin = 0, iumax = 0;
        if (derUU)
        {
            mBasis[0].Compute(u, 0, iumin, iumax);
            mBasis[0].Compute(u, 1, iumin, iumax);
            mBasis[0].Compute(u, 2, iumin, iumax);
        }
        else if (derUV || derU)
        {
            mBasis[0].Compute(u, 0, iumin, iumax);
            mBasis[0].Compute(u, 1, iumin, iumax);
        }
        else
        {
            mBasis[0].Compute(u, 0, iumin, iumax);
        }

        int iv = 0, ivmin = 0, ivmax = 0;
        if (derVV)
        {
            mBasis[1].Compute(v, 0, ivmin, ivmax);
            mBasis[1].Compute(v, 1, ivmin, ivmax);
            mBasis[1].Compute(v, 2, ivmin, ivmax);
        }
        else if (derUV || derV)
        {
            mBasis[1].Compute(v, 0, ivmin, ivmax);
            mBasis[1].Compute(v, 1, ivmin, ivmax);
        }
        else
        {
            mBasis[1].Compute(v, 0, ivmin, ivmax);
        }

        Real tmp{};

        if (pos)
        {
            *pos = Vector3D<Real>::GetZero();
            for (iu = iumin; iu <= iumax; ++iu)
            {
                for (iv = ivmin; iv <= ivmax; ++iv)
                {
                    tmp = mBasis[0].GetD0(iu) * mBasis[1].GetD0(iv);
                    *pos += tmp * mCtrlPoint[iu][iv];
                }
            }
        }

        if (derU)
        {
            *derU = Vector3D<Real>::GetZero();
            for (iu = iumin; iu <= iumax; ++iu)
            {
                for (iv = ivmin; iv <= ivmax; ++iv)
                {
                    tmp = mBasis[0].GetD1(iu) * mBasis[1].GetD0(iv);
                    *derU += tmp * mCtrlPoint[iu][iv];
                }
            }
        }

        if (derV)
        {
            *derV = Vector3D<Real>::GetZero();
            for (iu = iumin; iu <= iumax; ++iu)
            {
                for (iv = ivmin; iv <= ivmax; ++iv)
                {
                    tmp = mBasis[0].GetD0(iu) * mBasis[1].GetD1(iv);
                    *derV += tmp * mCtrlPoint[iu][iv];
                }
            }
        }

        if (derUU)
        {
            *derUU = Vector3D<Real>::GetZero();
            for (iu = iumin; iu <= iumax; ++iu)
            {
                for (iv = ivmin; iv <= ivmax; ++iv)
                {
                    tmp = mBasis[0].GetD2(iu) * mBasis[1].GetD0(iv);
                    *derUU += tmp * mCtrlPoint[iu][iv];
                }
            }
        }

        if (derUV)
        {
            *derUV = Vector3D<Real>::GetZero();
            for (iu = iumin; iu <= iumax; ++iu)
            {
                for (iv = ivmin; iv <= ivmax; ++iv)
                {
                    tmp = mBasis[0].GetD1(iu) * mBasis[1].GetD1(iv);
                    *derUV += tmp * mCtrlPoint[iu][iv];
                }
            }
        }

        if (derVV)
        {
            *derVV = Vector3D<Real>::GetZero();
            for (iu = iumin; iu <= iumax; ++iu)
            {
                for (iv = ivmin; iv <= ivmax; ++iv)
                {
                    tmp = mBasis[0].GetD0(iu) * mBasis[1].GetD2(iv);
                    *derVV += tmp * mCtrlPoint[iu][iv];
                }
            }
        }
    }

    template <typename Real>
    Vector3D<Real> BSplineRectangle<Real>::P(Real u, Real v) const
    {
        Vector3D<Real> pos;
        Get(u, v, &pos, 0, 0, 0, 0, 0);
        return pos;
    }

    template <typename Real>
    Vector3D<Real> BSplineRectangle<Real>::PU(Real u, Real v) const
    {
        Vector3D<Real> derU;
        Get(u, v, 0, &derU, 0, 0, 0, 0);
        return derU;
    }

    template <typename Real>
    Vector3D<Real> BSplineRectangle<Real>::PV(Real u, Real v) const
    {
        Vector3D<Real> derV;
        Get(u, v, 0, 0, &derV, 0, 0, 0);
        return derV;
    }

    template <typename Real>
    Vector3D<Real> BSplineRectangle<Real>::PUU(Real u, Real v) const
    {
        Vector3D<Real> derUU;
        Get(u, v, 0, 0, 0, &derUU, 0, 0);
        return derUU;
    }

    template <typename Real>
    Vector3D<Real> BSplineRectangle<Real>::PUV(Real u, Real v) const
    {
        Vector3D<Real> derUV;
        Get(u, v, 0, 0, 0, 0, &derUV, 0);
        return derUV;
    }

    template <typename Real>
    Vector3D<Real> BSplineRectangle<Real>::PVV(Real u, Real v) const
    {
        Vector3D<Real> derVV;
        Get(u, v, 0, 0, 0, 0, 0, &derVV);
        return derVV;
    }

}

#include STSTEM_WARNING_POP
#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_RECTANGLE_DETAIL_H