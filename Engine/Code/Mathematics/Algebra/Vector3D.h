///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/04 14:26)

// 3D向量类的声明
#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3D final : private boost::additive<Vector3D<Real>, boost::multiplicative<Vector3D<Real>, Real, boost::totally_ordered<Vector3D<Real>>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector3D<Real>;
        using Math = Math<Real>;

        enum class PointIndex
        {
            X = 0,
            Y,
            Z,
            Size
        };

        static constexpr auto sm_X = System::EnumCastUnderlying(PointIndex::X);
        static constexpr auto sm_Y = System::EnumCastUnderlying(PointIndex::Y);
        static constexpr auto sm_Z = System::EnumCastUnderlying(PointIndex::Z);
        static constexpr auto sm_PointSize = System::EnumCastUnderlying(PointIndex::Size);

        using BarycentricCoordinates = BarycentricCoordinates<Real, sm_PointSize + 1>;
        using ArrayType = std::array<Real, sm_PointSize>;

        using GetCoordinateFunction = Real (ClassType::*)() const noexcept;
        using SetCoordinateFunction = void (ClassType::*)(Real) noexcept;

    public:
        constexpr Vector3D() noexcept
            : m_X{}, m_Y{}, m_Z{}
        {
        }

        constexpr Vector3D(Real x, Real y, Real z) noexcept
            : m_X{ x }, m_Y{ y }, m_Z{ z }
        {
        }

        template <typename RhsType>
        Vector3D(const Vector2D<RhsType>& vector);
        template <typename RhsType>
        Vector3D(const Vector3D<RhsType>& vector);
        template <typename RhsType>
        Vector3D(const Vector4D<RhsType>& vector);

        CLASS_INVARIANT_DECLARE;

        // 坐标访问
        [[nodiscard]] Real GetX() const noexcept;
        [[nodiscard]] Real GetY() const noexcept;
        [[nodiscard]] Real GetZ() const noexcept;
        [[nodiscard]] bool IsZero(const Real epsilon = Math::GetZeroTolerance()) const noexcept;

        void SetCoordinate(const ArrayType& coordinate) noexcept;
        [[nodiscard]] ArrayType GetCoordinate() const noexcept;

        void ZeroOut() noexcept;
        void SetCoordinate(Real x, Real y, Real z) noexcept;
        void SetX(Real x) noexcept;
        void SetY(Real y) noexcept;
        void SetZ(Real z) noexcept;
        void Normalize(const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        [[nodiscard]] bool IsNormalize(const Real epsilon = Math::GetZeroTolerance()) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        [[nodiscard]] const Vector3D operator-() const noexcept;
        [[nodiscard]] const Real& operator[](int index) const;
        [[nodiscard]] Real& operator[](int index);

        Vector3D& operator+=(const Vector3D& rhs) noexcept;
        Vector3D& operator-=(const Vector3D& rhs) noexcept;
        Vector3D& operator*=(Real rhs) noexcept;
        Vector3D& operator/=(Real rhs) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 特殊Vector3D
        // (0,0,0)
        static constexpr Vector3D GetZero()
        {
            return Vector3D{};
        }

        // (1,0,0)
        static constexpr Vector3D GetUnitX()
        {
            return Vector3D{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0) };
        }

        // (0,1,0)
        static constexpr Vector3D GetUnitY()
        {
            return Vector3D{ Math::GetValue(0), Math::GetValue(1), Math::GetValue(0) };
        }

        // (0,0,1)
        static constexpr Vector3D GetUnitZ()
        {
            return Vector3D{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(1) };
        }

        // (1,1,1)
        static constexpr Vector3D GetOne()
        {
            return Vector3D{ Math::GetValue(1), Math::GetValue(1), Math::GetValue(1) };
        }

        // 相对于计算出点V的重心坐标到四面体<V0,V1,V2,V3>
        // V = b0 * V0 + b1 * V1 + b2 * V2 + b3 * V3，
        // 这里b0 + b1 + b2 + b3 = 1。
        // 当且仅当{V0，V1，V2, V3}是线性无关组时返回值是有效的。
        // 数值上，测试 |det[V0 V1 V2 V3]| <= epsilon。
        [[nodiscard]] const BarycentricCoordinates GetBarycentrics(const Vector3D& vector0, const Vector3D& vector1, const Vector3D& vector2,
                                                                   const Vector3D& vector3, const Real epsilon = Math::GetZeroTolerance()) const;

        [[nodiscard]] const Vector3D GetMove(Real t, const Vector3D& velocity) const;

    private:
        using ToolsType = Vector3DTools<Real>;

    private:
        Real m_X;
        Real m_Y;
        Real m_Z;
    };

    using FloatVector3D = Vector3D<float>;
    using DoubleVector3D = Vector3D<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_H
