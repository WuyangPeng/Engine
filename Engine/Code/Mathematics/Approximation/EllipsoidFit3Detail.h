///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:09)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_DETAIL_H
#define MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_DETAIL_H

#include "EllipsoidFit3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Containment/ContBox3Detail.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Ellipsoid3Detail.h"
#include "Mathematics/Distance/DistanceResultDetail.h"
#include "Mathematics/NumericalAnalysis/MinimizeNDetail.h"

template <typename Real>
Mathematics::EllipsoidFit3<Real>::EllipsoidFit3(const Points& points)
    : points{ points }, center{}, rotate{}, extent0{}, extent1{}, extent2{}, exactly{}
{
    Fit3();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::EllipsoidFit3<Real>::Fit3()
{
    // 能量函数为 E : Real^9 -> Real  其中
    // V = (V0,V1,V2,V3,V4,V5,V6,V7,V8)
    //   = (D[0],D[1],D[2],U.X(),U,y,U.Z(),A0,A1,A2)。
    // 对于真正分散的数据，你可能需要一个搜索函数

    InitialGuess();

    auto angle = MatrixToAngles(rotate);

    Angle extent{ extent0 * MathType::FAbs(rotate.template GetValue<0, 0>()) + extent1 * MathType::FAbs(rotate.template GetValue<0, 1>()) + extent2 * MathType::FAbs(rotate.template GetValue<0, 2>()),
                  extent0 * MathType::FAbs(rotate.template GetValue<1, 0>()) + extent1 * MathType::FAbs(rotate.template GetValue<1, 1>()) + extent2 * MathType::FAbs(rotate.template GetValue<1, 2>()),
                  extent0 * MathType::FAbs(rotate.template GetValue<2, 0>()) + extent1 * MathType::FAbs(rotate.template GetValue<2, 1>()) + extent2 * MathType::FAbs(rotate.template GetValue<2, 2>()) };

    Angle begin{ MathType::GetRational(1, 2) * extent0,
                 MathType::GetRational(1, 2) * extent1,
                 MathType::GetRational(1, 2) * extent2,
                 center.GetX() - extent.at(0),
                 center.GetY() - extent.at(1),
                 center.GetZ() - extent.at(2),
                 -MathType::GetPI(),
                 MathType::GetValue(0),
                 MathType::GetValue(0) };

    Angle end{ MathType::GetValue(2) * extent0,
               MathType::GetValue(2) * extent1,
               MathType::GetValue(2) * extent2,
               center.GetX() + extent.at(0),
               center.GetY() + extent.at(1),
               center.GetZ() + extent.at(2),
               MathType::GetPI(),
               MathType::GetPI(),
               MathType::GetPI() };

    Angle initial{ extent0,
                   extent1,
                   extent2,
                   center.GetX(),
                   center.GetY(),
                   center.GetZ(),
                   angle.at(0),
                   angle.at(1),
                   angle.at(2) };

    const MinimizeN<Real, ClassType> minimizer{ 9, Energy, 8, 8, 32, this };
    const auto data = minimizer.GetMinimum(begin, end, initial);
    exactly = data.GetMinValue();

    extent0 = data.GetMinLocation(0);
    extent1 = data.GetMinLocation(1);
    extent2 = data.GetMinLocation(2);
    center.SetCoordinate(data.GetMinLocation(3), data.GetMinLocation(4), data.GetMinLocation(5));

    angle.at(0) = data.GetMinLocation(6);
    angle.at(1) = data.GetMinLocation(7);
    angle.at(2) = data.GetMinLocation(8);

    rotate = AnglesToMatrix(angle);
}

template <typename Real>
void Mathematics::EllipsoidFit3<Real>::InitialGuess()
{
    const auto box = ContBox3<Real>::ContOrientedBox(points);

    center = box.GetCenter();
    rotate = Matrix3Type{ box.GetAxis0().GetX(),
                      box.GetAxis0().GetY(),
                      box.GetAxis0().GetZ(),
                      box.GetAxis1().GetX(),
                      box.GetAxis1().GetY(),
                      box.GetAxis1().GetZ(),
                      box.GetAxis2().GetX(),
                      box.GetAxis2().GetY(),
                      box.GetAxis2().GetZ() };
    extent0 = box.GetExtent0();
    extent1 = box.GetExtent1();
    extent2 = box.GetExtent2();
}

template <typename Real>
Real Mathematics::EllipsoidFit3<Real>::Energy(const Angle& input, const EllipsoidFit3* userData)
{
    if (userData == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("致命错误，传递空指针。"s));
    }

    const auto& self = *userData;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 构建旋转矩阵
    Angle angle{ input[6], input[7], input[8] };
    const auto rotate = AnglesToMatrix(angle);

    // 均匀缩放程度，以保持合理的浮点值距离计算。
    auto maxValue = input[0];
    if (maxValue < input[1])
    {
        maxValue = input[1];
    }
    if (maxValue < input[2])
    {
        maxValue = input[2];
    }

    const Ellipsoid3<Real> ellipsoid{ Vector3Type::GetZero(), Vector3Type::GetUnitX(), Vector3Type::GetUnitY(), Vector3Type::GetUnitZ(), input[0] / maxValue, input[1] / maxValue, input[2] / maxValue };

    // 变换点到中心C和旋转Real的列的坐标系统
    auto energy = MathType::GetValue(0);

    const auto numPoints = userData->GetNumPoint();

    for (auto i = 0; i < numPoints; ++i)
    {
        const Vector3Type diff{ self.GetPoint(i).GetX() - input[3],
                            self.GetPoint(i).GetY() - input[4],
                            self.GetPoint(i).GetZ() - input[5] };

        auto point = rotate * diff / maxValue;

        DistancePoint3Ellipsoid3<Real> distancePoint3Ellipsoid3{ point, ellipsoid };
        auto distance = distancePoint3Ellipsoid3.Get();

        energy += distance.GetDistance() * maxValue;
    }

#include SYSTEM_WARNING_POP

    return energy;
}

template <typename Real>
typename Mathematics::EllipsoidFit3<Real>::Angle Mathematics::EllipsoidFit3<Real>::MatrixToAngles(const Matrix3Type& rotate)
{
    // 旋转轴 = (cos(a0)sin(a1),sin(a0)sin(a1),cos(a1))
    // a0 在 [-pi,pi], a1 在 [0,pi], a2 在 [0,pi]

    const auto extract = rotate.ExtractAngleAxis();
    const auto axis = extract.GetAxis();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    Angle angle(3);
    angle[2] = extract.GetAngle();

    if (MathType::GetValue(-1) < axis.GetZ())
    {
        if (axis.GetZ() < MathType::GetValue(1))
        {
            angle[0] = MathType::ATan2(axis.GetY(), axis.GetX());
            angle[1] = MathType::ACos(axis.GetZ());
        }
        else
        {
            angle[0] = MathType::GetValue(0);
            angle[1] = MathType::GetValue(0);
        }
    }
    else
    {
        angle[0] = MathType::GetValue(0);
        angle[1] = MathType::GetPI();
    }

#include SYSTEM_WARNING_POP

    return angle;
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::EllipsoidFit3<Real>::AnglesToMatrix(const Angle& angle) noexcept
{
    // 旋转轴 = (cos(a0)sin(a1),sin(a0)sin(a1),cos(a1))
    // a0 在  [-pi,pi], a1 在 [0,pi], a2 在 [0,pi]

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    const auto cs0 = MathType::Cos(angle[0]);
    const auto sn0 = MathType::Sin(angle[0]);
    const auto cs1 = MathType::Cos(angle[1]);
    const auto sn1 = MathType::Sin(angle[1]);

    const Vector3Type axis{ cs0 * sn1, sn0 * sn1, cs1 };

    return Matrix3Type{ axis, angle[2] };

#include SYSTEM_WARNING_POP
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::EllipsoidFit3<Real>::IsValid() const noexcept
{
    if (MathType::GetValue(0) <= exactly)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::EllipsoidFit3<Real>::GetExactly() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return exactly;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::EllipsoidFit3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::EllipsoidFit3<Real>::GetRotate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rotate;
}

template <typename Real>
Real Mathematics::EllipsoidFit3<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return extent0;
}

template <typename Real>
Real Mathematics::EllipsoidFit3<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return extent1;
}

template <typename Real>
Real Mathematics::EllipsoidFit3<Real>::GetExtent2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return extent2;
}

template <typename Real>
int Mathematics::EllipsoidFit3<Real>::GetNumPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(points.size());
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::EllipsoidFit3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return points.at(index);
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_DETAIL_H
