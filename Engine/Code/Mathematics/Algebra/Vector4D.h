///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/04 15:10)

// 4D向量类的声明
#ifndef MATHEMATICS_ALGEBRA_VECTOR_4D_H
#define MATHEMATICS_ALGEBRA_VECTOR_4D_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector4D final : private boost::additive<Vector4D<Real>, boost::multiplicative<Vector4D<Real>, Real, boost::totally_ordered<Vector4D<Real>>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector4D<Real>;
        using Math = Math<Real>;

        enum class PointIndex
        {
            X = 0,
            Y,
            Z,
            W,
            Size
        };

        static constexpr auto sm_X = System::EnumCastUnderlying(PointIndex::X);
        static constexpr auto sm_Y = System::EnumCastUnderlying(PointIndex::Y);
        static constexpr auto sm_Z = System::EnumCastUnderlying(PointIndex::Z);
        static constexpr auto sm_W = System::EnumCastUnderlying(PointIndex::W);
        static constexpr auto sm_PointSize = System::EnumCastUnderlying(PointIndex::Size);
        using ArrayType = std::array<Real, sm_PointSize>;

        using GetCoordinateFunction = Real (ClassType::*)() const noexcept;
        using SetCoordinateFunction = void (ClassType::*)(Real) noexcept;

    public:
        constexpr Vector4D() noexcept
            : m_X{}, m_Y{}, m_Z{}, m_W{}
        {
        }

        constexpr Vector4D(Real x, Real y, Real z, Real w) noexcept
            : m_X{ x }, m_Y{ y }, m_Z{ z }, m_W{ w }
        {
        }

        template <typename RhsType>
        Vector4D(const Vector2D<RhsType>& vector);
        template <typename RhsType>
        Vector4D(const Vector3D<RhsType>& vector);
        template <typename RhsType>
        Vector4D(const Vector4D<RhsType>& vector);

        CLASS_INVARIANT_DECLARE;

        void SetCoordinate(const ArrayType& coordinate) noexcept;
        [[nodiscard]] ArrayType GetCoordinate() const noexcept;

        // 坐标访问
        [[nodiscard]] Real GetX() const noexcept;
        [[nodiscard]] Real GetY() const noexcept;
        [[nodiscard]] Real GetZ() const noexcept;
        [[nodiscard]] Real GetW() const noexcept;
        [[nodiscard]] bool IsZero(const Real epsilon = Math::GetZeroTolerance()) const noexcept;

        void ZeroOut() noexcept;
        void SetCoordinate(Real x, Real y, Real z, Real w) noexcept;
        void SetX(Real x) noexcept;
        void SetY(Real y) noexcept;
        void SetZ(Real z) noexcept;
        void SetW(Real w) noexcept;
        void Normalize(const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void ProjectionNormalization(const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        [[nodiscard]] const Vector4D operator-() const noexcept;
        [[nodiscard]] const Real& operator[](int index) const;
        [[nodiscard]] Real& operator[](int index);

        Vector4D& operator+=(const Vector4D& rhs) noexcept;
        Vector4D& operator-=(const Vector4D& rhs) noexcept;
        Vector4D& operator*=(Real rhs) noexcept;
        Vector4D& operator/=(Real rhs) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 特殊Vector4D

        // (0,0,0,0)
        [[nodiscard]] static constexpr Vector4D GetZero()
        {
            return Vector4D{};
        }

        // (1,0,0,0)
        [[nodiscard]] static constexpr Vector4D GetUnitX()
        {
            return Vector4D{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }

        // (0,1,0,0)
        [[nodiscard]] static constexpr Vector4D GetUnitY()
        {
            return Vector4D{ Math::GetValue(0), Math::GetValue(1), Math::GetValue(0), Math::GetValue(0) };
        }

        // (0,0,1,0)
        [[nodiscard]] static constexpr Vector4D GetUnitZ()
        {
            return Vector4D{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(1), Math::GetValue(0) };
        }

        // (0,0,0,1)
        [[nodiscard]] static constexpr Vector4D GetUnitW()
        {
            return Vector4D{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(0), Math::GetValue(1) };
        }

        // (1,1,1,1)
        [[nodiscard]] static constexpr Vector4D GetOne()
        {
            return Vector4D{ Math::GetValue(1), Math::GetValue(1), Math::GetValue(1), Math::GetValue(1) };
        }

        [[nodiscard]] const Vector4D GetMove(Real t, const Vector4D& velocity) const;

    private:
        using ToolsType = Vector4DTools<Real>;

    private:
        Real m_X;
        Real m_Y;
        Real m_Z;
        Real m_W;
    };

    using FloatVector4D = Vector4D<float>;
    using DoubleVector4D = Vector4D<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_4D_H
