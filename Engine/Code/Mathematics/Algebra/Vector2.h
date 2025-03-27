///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 15:11)

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
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2 final : private boost::additive<Vector2<Real>, boost::multiplicative<Vector2<Real>, Real, boost::totally_ordered<Vector2<Real>>>>
    {
    public:
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

        using MathType = Math<Real>;
        using BarycentricCoordinatesType = BarycentricCoordinates<Real, pointSize + 1>;
        using ArrayType = std::array<Real, pointSize>;
        using ToolsType = Vector2Tools<Real>;
        using AlgebraVector2 = Algebra::Vector<2, Real>;

        using GetCoordinateFunction = Real (ClassType::*)() const noexcept;
        using SetCoordinateFunction = void (ClassType::*)(Real) noexcept;

    public:
        constexpr Vector2() noexcept
            : x{}, y{}
        {
        }

        constexpr Vector2(Real x, Real y) noexcept
            : x{ x }, y{ y }
        {
        }

        template <typename RhsType>
        explicit Vector2(const Vector2<RhsType>& vector);
        template <typename RhsType>
        explicit Vector2(const Vector3<RhsType>& vector);
        template <typename RhsType>
        explicit Vector2(const Vector4<RhsType>& vector);

        explicit Vector2(const ArrayType& coordinate);

        CLASS_INVARIANT_DECLARE;

        NODISCARD AlgebraVector2 GetVector() const noexcept;

        // 坐标访问
        NODISCARD Real GetX() const noexcept;
        NODISCARD Real GetY() const noexcept;
        NODISCARD bool IsZero(Real epsilon = MathType::GetZeroTolerance()) const noexcept;

        void SetCoordinate(const ArrayType& coordinate);
        NODISCARD ArrayType GetCoordinate() const noexcept;

        void ZeroOut() noexcept;
        void SetCoordinate(Real aX, Real aY) noexcept;
        void SetX(Real aX) noexcept;
        void SetY(Real aY) noexcept;
        void Normalize(Real epsilon = MathType::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void RobustNormalize(Real epsilon = MathType::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD bool IsNormalize(Real epsilon = MathType::GetZeroTolerance()) const noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD Vector2 GetNormalize(Real epsilon = MathType::GetZeroTolerance()) const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);
        NODISCARD const Real& operator[](PointIndex index) const;
        NODISCARD Real& operator[](PointIndex index);

        NODISCARD Vector2 operator-() const noexcept;
        Vector2& operator+=(const Vector2& rhs) noexcept;
        Vector2& operator-=(const Vector2& rhs) noexcept;

        Vector2& operator*=(Real rhs) noexcept;
        Vector2& operator/=(Real rhs) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 特殊Vector2
        // (0,0)
        NODISCARD static constexpr Vector2 GetZero()
        {
            return Vector2{};
        }

        // (1,0)
        NODISCARD static constexpr Vector2 GetUnitX()
        {
            return Vector2{ MathType::GetValue(1), MathType::GetValue(0) };
        }

        // (0,1)
        NODISCARD static constexpr Vector2 GetUnitY()
        {
            return Vector2{ MathType::GetValue(0), MathType::GetValue(1) };
        }

        // (1,1)
        NODISCARD static constexpr Vector2 GetOne()
        {
            return Vector2{ MathType::GetValue(1), MathType::GetValue(1) };
        }

        // 相对于计算出点V的重心坐标到三角形<V0,V1,V2>
        // V = b0 * V0 + b1 * V1 + b2 * V2，
        // 这里b0 + b1 + b2 = 1。
        // 当且仅当{V0，V1，V2}是线性无关组时返回值是有效的。
        // 数值上，测试 |det[V0 V1 V2]| <= epsilon。
        NODISCARD BarycentricCoordinatesType GetBarycentrics(const Vector2& vector0, const Vector2& vector1, const Vector2& vector2, const Real epsilon = MathType::GetZeroTolerance()) const;

        NODISCARD Vector2 GetMove(Real t, const Vector2& velocity) const;

        NODISCARD Real GetMaxAbsComp() const noexcept;

    private:
        Real x;
        Real y;
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
