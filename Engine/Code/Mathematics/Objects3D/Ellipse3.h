///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 15:44)

#ifndef MATHEMATICS_OBJECTS_3D_ELLIPSE3_H
#define MATHEMATICS_OBJECTS_3D_ELLIPSE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Ellipse3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Ellipse3<Real>;
        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;

    public:
        // 含椭圆的面是Dot(N,X-C) = 0 ，
        // 其中X是在平面上的任意点。
        // 向量U，V和N形成正交右手坐标系（矩阵 [U V N]是正交的，且行列式为1）。
        // 在平面内的椭圆为X = C + a*cos(t)*U + b*sin(t)*V，
        // 其中t为[0,2*pi)的角度和其中 a >= b > 0。
        // 在此讨论的符号均与类成员如下。
        // 成员'Center'为C，“Normal”是N，'Major'是U，'Minor'是V，
        // 'MajorLength“是a和”MinorLength'为b。
        Ellipse3(const Vector3& center,
                 const Vector3& normal,
                 const Vector3& major,
                 const Vector3& minor,
                 Real majorLength,
                 Real minorLength,
                 const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetCenter() const noexcept;
        NODISCARD Vector3 GetNormal() const noexcept;
        NODISCARD Vector3 GetMajor() const noexcept;
        NODISCARD Vector3 GetMinor() const noexcept;
        NODISCARD Real GetMajorLength() const noexcept;
        NODISCARD Real GetMinorLength() const noexcept;

    private:
        Vector3 center;
        Vector3 normal;
        Vector3 major;
        Vector3 m_Minor;
        Real majorLength;
        Real minorLength;

        Real epsilon;
    };

    using Ellipse3F = Ellipse3<float>;
    using Ellipse3D = Ellipse3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_ELLIPSE3_H
