///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/02 18:35)

// 2D�����������
#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "BarycentricCoordinates.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2D final : private boost::additive<Vector2D<Real>, boost::multiplicative<Vector2D<Real>, Real, boost::totally_ordered<Vector2D<Real>>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector2D<Real>;
        using Math = Math<Real>;

        enum class PointIndex
        {
            X = 0,
            Y,
            Size
        };

        static constexpr auto sm_X = System::EnumCastUnderlying(PointIndex::X);
        static constexpr auto sm_Y = System::EnumCastUnderlying(PointIndex::Y);
        static constexpr auto sm_PointSize = System::EnumCastUnderlying(PointIndex::Size);

        using BarycentricCoordinates = BarycentricCoordinates<Real, sm_PointSize + 1>;
        using ArrayType = std::array<Real, sm_PointSize>;

        using GetCoordinateFunction = Real (ClassType::*)() const noexcept;
        using SetCoordinateFunction = void (ClassType::*)(Real) noexcept;

    public:
        constexpr Vector2D() noexcept
            : m_X{}, m_Y{}
        {
        }

        Vector2D(Real x, Real y) noexcept
            : m_X{ x }, m_Y{ y }
        {
        }

        template <typename RhsType>
        Vector2D(const Vector2D<RhsType>& vector);
        template <typename RhsType>
        Vector2D(const Vector3D<RhsType>& vector);
        template <typename RhsType>
        Vector2D(const Vector4D<RhsType>& vector);

        CLASS_INVARIANT_DECLARE;

        // �������
        [[nodiscard]] Real GetX() const noexcept;
        [[nodiscard]] Real GetY() const noexcept;
        [[nodiscard]] bool IsZero(const Real epsilon = Math::GetZeroTolerance()) const noexcept;

        void SetCoordinate(const ArrayType& coordinate) noexcept;
        [[nodiscard]] ArrayType GetCoordinate() const noexcept;

        void ZeroOut() noexcept;
        void SetCoordinate(Real x, Real y) noexcept;
        void SetX(Real x) noexcept;
        void SetY(Real y) noexcept;
        void Normalize(const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        [[nodiscard]] bool IsNormalize(const Real epsilon = Math::GetZeroTolerance()) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        [[nodiscard]] const Real& operator[](int index) const;
        [[nodiscard]] Real& operator[](int index);
        [[nodiscard]] const Real& operator[](PointIndex index) const;
        [[nodiscard]] Real& operator[](PointIndex index);

        [[nodiscard]] const Vector2D operator-() const noexcept;
        Vector2D& operator+=(const Vector2D& rhs) noexcept;
        Vector2D& operator-=(const Vector2D& rhs) noexcept;

        Vector2D& operator*=(Real rhs) noexcept;
        Vector2D& operator/=(Real rhs) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // ����Vector2D
        // (0,0)
        [[nodiscard]] static constexpr Vector2D GetZero()
        {
            return Vector2D{};
        }

        // (1,0)
        [[nodiscard]] static constexpr Vector2D GetUnitX()
        {
            return Vector2D{ Math::GetValue(1), Math::GetValue(0) };
        }

        // (0,1)
        [[nodiscard]] static constexpr Vector2D GetUnitY()
        {
            return Vector2D{ Math::GetValue(0), Math::GetValue(1) };
        }

        // (1,1)
        [[nodiscard]] static constexpr Vector2D GetOne()
        {
            return Vector2D{ Math::GetValue(1), Math::GetValue(1) };
        }

        // ����ڼ������V���������굽������<V0,V1,V2>
        // V = b0 * V0 + b1 * V1 + b2 * V2��
        // ����b0 + b1 + b2 = 1��
        // ���ҽ���{V0��V1��V2}�������޹���ʱ����ֵ����Ч�ġ�
        // ��ֵ�ϣ����� |det[V0 V1 V2]| <= epsilon��
        [[nodiscard]] const BarycentricCoordinates GetBarycentrics(const Vector2D& vector0, const Vector2D& vector1, const Vector2D& vector2, const Real epsilon = Math::GetZeroTolerance()) const;

        [[nodiscard]] const Vector2D GetMove(Real t, const Vector2D& velocity) const;

    private:
        using ToolsType = Vector2DTools<Real>;

    private:
        Real m_X;
        Real m_Y;
    };

    using FloatVector2D = Vector2D<float>;
    using DoubleVector2D = Vector2D<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_H
