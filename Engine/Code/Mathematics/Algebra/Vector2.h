///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/01/31 3:50)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_H
#define MATHEMATICS_ALGEBRA_VECTOR2_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "BarycentricCoordinates.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

// 当向量存储的值为浮点数时，比较两向量相等，
// 请使用函数Vector2Tools::Approximate，而不是==。
// == 仅用于STL
namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2 final : private boost::additive<Vector2<Real>, boost::multiplicative<Vector2<Real>, Real, boost::totally_ordered<Vector2<Real>>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        enum class PointIndex
        {
            X = 0,
            Y,
            Size
        };

        static constexpr auto xIndex = System::EnumCastUnderlying(PointIndex::X);
        static constexpr auto yIndex = System::EnumCastUnderlying(PointIndex::Y);
        static constexpr auto pointSize = System::EnumCastUnderlying(PointIndex::Size);

        using ClassType = Vector2<Real>;
        using Math = Math<Real>;
        using BarycentricCoordinates = BarycentricCoordinates<Real, pointSize + 1>;
        using ArrayType = std::array<Real, pointSize>;
        using ToolsType = Vector2Tools<Real>;

        using GetCoordinateFunction = Real (ClassType::*)() const noexcept;
        using SetCoordinateFunction = void (ClassType::*)(Real) noexcept;

    public:
        constexpr Vector2() noexcept
            : m_X{}, m_Y{}
        {
        }

        constexpr Vector2(Real x, Real y) noexcept
            : m_X{ x }, m_Y{ y }
        {
        }

        template <typename RhsType>
        Vector2(const Vector2<RhsType>& vector);
        template <typename RhsType>
        Vector2(const Vector3<RhsType>& vector);
        template <typename RhsType>
        Vector2(const Vector4<RhsType>& vector);

        CLASS_INVARIANT_DECLARE;

        // 坐标访问
        NODISCARD Real GetX() const noexcept;
        NODISCARD Real GetY() const noexcept;
        NODISCARD bool IsZero(const Real epsilon = Math::GetZeroTolerance()) const noexcept;

        void SetCoordinate(const ArrayType& coordinate) noexcept;
        NODISCARD ArrayType GetCoordinate() const noexcept;

        void ZeroOut() noexcept;
        void SetCoordinate(Real x, Real y) noexcept;
        void SetX(Real x) noexcept;
        void SetY(Real y) noexcept;
        void Normalize(const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void RobustNormalize(const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        NODISCARD bool IsNormalize(const Real epsilon = Math::GetZeroTolerance()) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);
        NODISCARD const Real& operator[](PointIndex index) const;
        NODISCARD Real& operator[](PointIndex index);

        NODISCARD Vector2 operator-() const noexcept;
        Vector2& operator+=(const Vector2& rhs) noexcept;
        Vector2& operator-=(const Vector2& rhs) noexcept;

        Vector2& operator*=(Real rhs) noexcept;
        Vector2& operator/=(Real rhs) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 特殊Vector2
        // (0,0)
        NODISCARD static constexpr Vector2 GetZero()
        {
            return Vector2{};
        }

        // (1,0)
        NODISCARD static constexpr Vector2 GetUnitX()
        {
            return Vector2{ Math::GetValue(1), Math::GetValue(0) };
        }

        // (0,1)
        NODISCARD static constexpr Vector2 GetUnitY()
        {
            return Vector2{ Math::GetValue(0), Math::GetValue(1) };
        }

        // (1,1)
        NODISCARD static constexpr Vector2 GetOne()
        {
            return Vector2{ Math::GetValue(1), Math::GetValue(1) };
        }

        // 相对于计算出点V的重心坐标到三角形<V0,V1,V2>
        // V = b0 * V0 + b1 * V1 + b2 * V2，
        // 这里b0 + b1 + b2 = 1。
        // 当且仅当{V0，V1，V2}是线性无关组时返回值是有效的。
        // 数值上，测试 |det[V0 V1 V2]| <= epsilon。
        NODISCARD BarycentricCoordinates GetBarycentrics(const Vector2& vector0, const Vector2& vector1, const Vector2& vector2, const Real epsilon = Math::GetZeroTolerance()) const;

        NODISCARD Vector2 GetMove(Real t, const Vector2& velocity) const;

        NODISCARD Real GetMaxAbsComp() const noexcept;

    private:
        Real m_X;
        Real m_Y;
    };

    // STL
    template <typename Real>
    NODISCARD bool operator==(const Vector2<Real>& lhs, const Vector2<Real>& rhs);

    template <typename Real>
    NODISCARD bool operator<(const Vector2<Real>& lhs, const Vector2<Real>& rhs) noexcept;

    // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Vector2<Real>& vector);

    using Vector2F = Vector2<float>;
    using Vector2D = Vector2<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_H
