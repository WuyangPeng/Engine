///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/16 11:47)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_IMPLICIT_SURFACE_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_IMPLICIT_SURFACE_DETAIL_H

#include "ImplicitSurface.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ImplicitSurface<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ImplicitSurface<Real>::IsOnSurface(const Vector3<Real>& pos, Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Math<Real>::FAbs(F(pos)) <= epsilon;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::ImplicitSurface<Real>::GetGradient(const Vector3<Real>& pos) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto fx = FX(pos);
    auto fy = FY(pos);
    auto fz = FZ(pos);

    return Vector3<Real>{ fx, fy, fz };
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::ImplicitSurface<Real>::GetHessian(const Vector3<Real>& pos) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto fxx = FXX(pos);
    auto fxy = FXY(pos);
    auto fxz = FXZ(pos);
    auto fyy = FYY(pos);
    auto fyz = FYZ(pos);
    auto fzz = FZZ(pos);

    return Matrix3<Real>{ fxx, fxy, fxz, fxy, fyy, fyz, fxz, fyz, fzz };
}

template <typename Real>
void Mathematics::ImplicitSurface<Real>::GetFrame(const Vector3<Real>& pos, Vector3<Real>& tangent0, Vector3<Real>& tangent1, Vector3<Real>& normal) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    normal = GetGradient(pos);
    const auto vector3OrthonormalBasis = Vector3Tools<Real>::GenerateOrthonormalBasis(normal);
    tangent0 = vector3OrthonormalBasis.GetUVector();
    tangent1 = vector3OrthonormalBasis.GetVVector();
}

template <typename Real>
bool Mathematics::ImplicitSurface<Real>::ComputePrincipalCurvatureInfo(const Vector3<Real>& pos, Real& curv0, Real& curv1, Vector3<Real>& dir0, Vector3<Real>& dir1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto fx = FX(pos);
    auto fy = FY(pos);
    auto fz = FZ(pos);
    auto fLength = Math<Real>::Sqrt(fx * fx + fy * fy + fz * fz);
    if (fLength <= Math<Real>::GetZeroTolerance())
    {
        return false;
    }

    auto fxfx = fx * fx;
    auto fxfy = fx * fy;
    auto fxfz = fx * fz;
    auto fyfy = fy * fy;
    auto fyfz = fy * fz;
    auto fzfz = fz * fz;

    auto invLength = (Math<Real>::GetValue(1)) / fLength;
    auto invLength2 = invLength * invLength;
    auto invLength3 = invLength * invLength2;
    auto invLength4 = invLength2 * invLength2;

    auto fxx = FXX(pos);
    auto fxy = FXY(pos);
    auto fxz = FXZ(pos);
    auto fyy = FYY(pos);
    auto fyz = FYZ(pos);
    auto fzz = FZZ(pos);

    auto meanCurv = Math<Real>::GetRational(1, 2) * invLength3 * (fxx * (fyfy + fzfz) + fyy * (fxfx + fzfz) + fzz * (fxfx + fyfy) - (Math<Real>::GetValue(2)) * (fxy * fxfy + fxz * fxfz + fyz * fyfz));

    auto gaussCurv = invLength4 * (fxfx * (fyy * fzz - fyz * fyz) + fyfy * (fxx * fzz - fxz * fxz) + fzfz * (fxx * fyy - fxy * fxy) + (Math<Real>::GetValue(2)) * (fxfy * (fxz * fyz - fxy * fzz) + fxfz * (fxy * fyz - fxz * fyy) + fyfz * (fxy * fxz - fxx * fyz)));

    auto discr = Math<Real>::Sqrt(Math<Real>::FAbs(meanCurv * meanCurv - gaussCurv));
    curv0 = meanCurv - discr;
    curv1 = meanCurv + discr;

    auto m00 = ((-Math<Real>::GetValue(1) + fxfx * invLength2) * fxx) * invLength + (fxfy * fxy) * invLength3 + (fxfz * fxz) * invLength3;
    auto m01 = ((-Math<Real>::GetValue(1) + fxfx * invLength2) * fxy) * invLength + (fxfy * fyy) * invLength3 + (fxfz * fyz) * invLength3;
    auto m02 = ((-Math<Real>::GetValue(1) + fxfx * invLength2) * fxz) * invLength + (fxfy * fyz) * invLength3 + (fxfz * fzz) * invLength3;
    auto m10 = (fxfy * fxx) * invLength3 + ((-Math<Real>::GetValue(1) + fyfy * invLength2) * fxy) * invLength + (fyfz * fxz) * invLength3;
    auto m11 = (fxfy * fxy) * invLength3 + ((-Math<Real>::GetValue(1) + fyfy * invLength2) * fyy) * invLength + (fyfz * fyz) * invLength3;
    auto m12 = (fxfy * fxz) * invLength3 + ((-Math<Real>::GetValue(1) + fyfy * invLength2) * fyz) * invLength + (fyfz * fzz) * invLength3;
    auto m20 = (fxfz * fxx) * invLength3 + (fyfz * fxy) * invLength3 + ((-Math<Real>::GetValue(1) + fzfz * invLength2) * fxz) * invLength;
    auto m21 = (fxfz * fxy) * invLength3 + (fyfz * fyy) * invLength3 + ((-Math<Real>::GetValue(1) + fzfz * invLength2) * fyz) * invLength;
    auto m22 = (fxfz * fxz) * invLength3 + (fyfz * fyz) * invLength3 + ((-Math<Real>::GetValue(1) + fzfz * invLength2) * fzz) * invLength;

    auto tmp1 = m00 + curv0;
    auto tmp2 = m11 + curv0;
    auto tmp3 = m22 + curv0;

    std::array<Vector3<Real>, 3> u{};
    Vector3<Real> lengths{};

    u.at(0)[0] = m01 * m12 - m02 * tmp2;
    u.at(0)[1] = m02 * m10 - m12 * tmp1;
    u.at(0)[2] = tmp1 * tmp2 - m01 * m10;
    lengths[0] = Vector3Tools<Real>::GetLength(u.at(0));

    u.at(1)[0] = m01 * tmp3 - m02 * m21;
    u.at(1)[1] = m02 * m20 - tmp1 * tmp3;
    u.at(1)[2] = tmp1 * m21 - m01 * m20;
    lengths[1] = Vector3Tools<Real>::GetLength(u.at(1));

    u.at(2)[0] = tmp2 * tmp3 - m12 * m21;
    u.at(2)[1] = m12 * m20 - m10 * tmp3;
    u.at(2)[2] = m10 * m21 - m20 * tmp2;
    lengths[2] = Vector3Tools<Real>::GetLength(u.at(2));

    auto maxIndex = 0;
    auto maxValue = lengths[0];
    if (lengths[1] > maxValue)
    {
        maxIndex = 1;
        maxValue = lengths[1];
    }
    if (lengths[2] > maxValue)
    {
        maxIndex = 2;
    }

    invLength = (Math<Real>::GetValue(1)) / lengths[maxIndex];
    u.at(maxIndex) *= invLength;

    dir1 = u.at(maxIndex);
    dir0 = Vector3Tools<Real>::UnitCrossProduct(dir1, (Vector3<Real>(fx, fy, fz)));

    return true;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_IMPLICIT_SURFACE_DETAIL_H