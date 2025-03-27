/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:25)

#ifndef MATHEMATICS_OBJECTS_3D_PLANE3_H
#define MATHEMATICS_OBJECTS_3D_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Plane3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Plane3<Real>;

        using Vector3 = Vector3<Real>;
        using MathType = Math<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Triangle3 = Triangle3<Real>;

    public:
        // 平面表示为Dot(N,X) = c，
        // 其中N是一个单位长度的法线向量，
        // c是平面常数，且X是在平面上的任意点。
        // 用户必须保证法线的向量是单位长度

        Plane3() noexcept;

        // 直接指定N和C。
        Plane3(const Vector3& normal, Real constant, Real epsilon = MathType::GetZeroTolerance()) noexcept;

        // 指定N，c = Dot(N,P)，这里P是平面是的一点。
        Plane3(const Vector3& normal, const Vector3& point, Real epsilon = MathType::GetZeroTolerance()) noexcept;

        // N = Cross(P1 - P0,P2 - P0)/Length(Cross(P1 - P0,P2 - P0))，
        // c = Dot(N,P0)，其中P0，P1，P2是在平面上的点。
        Plane3(const Vector3& point0, const Vector3& point1, const Vector3& point2, Real epsilon = MathType::GetZeroTolerance());

        explicit Plane3(const Triangle3& triangle, Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetNormal() const noexcept;
        NODISCARD Real GetConstant() const noexcept;

        // 计算d = Dot(N,P)-c 其中N是平面法线和c是平面常量。
        // 这是一个符号距离。
        // 如果返回值的符号是正的，则该点是在平面上的正方向，
        // 如果是负的，则在平面负方向，
        // 如果为零，则点在平面上。
        NODISCARD Real DistanceTo(const Vector3& point) const noexcept;

        // 平面的正面是法线点所在的半空间，背面是另一半空间。
        // 函数返回点在平面的哪一侧。
        NODISCARD NumericalValueSymbol WhichSide(const Vector3& point) const noexcept;

        void SetPlane(const Vector3& newNormal, const Vector3& point) noexcept;

        NODISCARD Plane3 GetMove(Real t, const Vector3& velocity) const noexcept;

    private:
        Vector3 normal;
        Real constant;

        Real epsilon;
    };

    using Plane3F = Plane3<float>;
    using Plane3D = Plane3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_PLANE3_H
