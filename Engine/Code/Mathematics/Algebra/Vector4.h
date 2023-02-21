///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/01 22:09)

#ifndef MATHEMATICS_ALGEBRA_VECTOR4_H
#define MATHEMATICS_ALGEBRA_VECTOR4_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector4 final : private boost::additive<Vector4<Real>, boost::multiplicative<Vector4<Real>, Real, boost::totally_ordered<Vector4<Real>>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector4<Real>;

        enum class PointIndex
        {
            X = 0,
            Y,
            Z,
            W,
            Size
        };

        static constexpr auto xIndex = System::EnumCastUnderlying(PointIndex::X);
        static constexpr auto yIndex = System::EnumCastUnderlying(PointIndex::Y);
        static constexpr auto zIndex = System::EnumCastUnderlying(PointIndex::Z);
        static constexpr auto wIndex = System::EnumCastUnderlying(PointIndex::W);
        static constexpr auto pointSize = System::EnumCastUnderlying(PointIndex::Size);

        using Math = Math<Real>;
        using ArrayType = std::array<Real, pointSize>;

        using GetCoordinateFunction = Real (ClassType::*)() const noexcept;
        using SetCoordinateFunction = void (ClassType::*)(Real) noexcept;

    public:
        constexpr Vector4() noexcept
            : m_X{}, m_Y{}, m_Z{}, m_W{}
        {
        }

        constexpr Vector4(Real x, Real y, Real z, Real w) noexcept
            : m_X{ x }, m_Y{ y }, m_Z{ z }, m_W{ w }
        {
        }

        template <typename RhsType>
        Vector4(const Vector2<RhsType>& vector);
        template <typename RhsType>
        Vector4(const Vector3<RhsType>& vector);
        template <typename RhsType>
        Vector4(const Vector4<RhsType>& vector);

        CLASS_INVARIANT_DECLARE;

        void SetCoordinate(const ArrayType& coordinate) noexcept;
        NODISCARD ArrayType GetCoordinate() const noexcept;

        // 坐标访问
        NODISCARD Real GetX() const noexcept;
        NODISCARD Real GetY() const noexcept;
        NODISCARD Real GetZ() const noexcept;
        NODISCARD Real GetW() const noexcept;
        NODISCARD bool IsZero(const Real epsilon = Math::GetZeroTolerance()) const noexcept;

        void ZeroOut() noexcept;
        void SetCoordinate(Real x, Real y, Real z, Real w) noexcept;
        void SetX(Real x) noexcept;
        void SetY(Real y) noexcept;
        void SetZ(Real z) noexcept;
        void SetW(Real w) noexcept;
        void Normalize(const Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void RobustNormalize(const Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void ProjectionNormalization(const Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD const Vector4 operator-() const noexcept;
        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);
        NODISCARD const Real& operator[](PointIndex index) const;
        NODISCARD Real& operator[](PointIndex index);

        Vector4& operator+=(const Vector4& rhs) noexcept;
        Vector4& operator-=(const Vector4& rhs) noexcept;
        Vector4& operator*=(Real rhs) noexcept;
        Vector4& operator/=(Real rhs) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 特殊Vector4

        // (0,0,0,0)
        NODISCARD static constexpr Vector4 GetZero()
        {
            return Vector4{};
        }

        // (1,0,0,0)
        NODISCARD static constexpr Vector4 GetUnitX()
        {
            return Vector4{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }

        // (0,1,0,0)
        NODISCARD static constexpr Vector4 GetUnitY()
        {
            return Vector4{ Math::GetValue(0), Math::GetValue(1), Math::GetValue(0), Math::GetValue(0) };
        }

        // (0,0,1,0)
        NODISCARD static constexpr Vector4 GetUnitZ()
        {
            return Vector4{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(1), Math::GetValue(0) };
        }

        // (0,0,0,1)
        NODISCARD static constexpr Vector4 GetUnitW()
        {
            return Vector4{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(0), Math::GetValue(1) };
        }

        // (1,1,1,1)
        NODISCARD static constexpr Vector4 GetOne()
        {
            return Vector4{ Math::GetValue(1), Math::GetValue(1), Math::GetValue(1), Math::GetValue(1) };
        }

        NODISCARD Vector4 GetMove(Real t, const Vector4& velocity) const;

        NODISCARD Real GetMaxAbsComp() const noexcept;

    private:
        using ToolsType = Vector4Tools<Real>;

    private:
        Real m_X;
        Real m_Y;
        Real m_Z;
        Real m_W;
    };

    // STL
    template <typename Real>
    NODISCARD bool operator==(const Vector4<Real>& lhs, const Vector4<Real>& rhs);

    template <typename Real>
    NODISCARD bool operator<(const Vector4<Real>& lhs, const Vector4<Real>& rhs) noexcept;

    // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Vector4<Real>& vector);

    using Vector4F = Vector4<float>;
    using Vector4D = Vector4<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR4_H
