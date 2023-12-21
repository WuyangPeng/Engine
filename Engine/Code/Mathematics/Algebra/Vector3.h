///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 15:16)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_H
#define MATHEMATICS_ALGEBRA_VECTOR3_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

// �������洢��ֵΪ������ʱ���Ƚ���������ȣ�
// ��ʹ�ú���Vector2Tools::Approximate��������==��
// == ������STL
namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3 final : private boost::additive<Vector3<Real>, boost::multiplicative<Vector3<Real>, Real, boost::totally_ordered<Vector3<Real>>>>
    {
    public:
        enum class PointIndex
        {
            X = 0,
            Y,
            Z,
            Size
        };

        static constexpr auto xIndex = System::EnumCastUnderlying(PointIndex::X);
        static constexpr auto yIndex = System::EnumCastUnderlying(PointIndex::Y);
        static constexpr auto zIndex = System::EnumCastUnderlying(PointIndex::Z);
        static constexpr auto pointSize = System::EnumCastUnderlying(PointIndex::Size);

        using ClassType = Vector3<Real>;

        using Math = Math<Real>;
        using ToolsType = Vector3Tools<Real>;
        using BarycentricCoordinates = BarycentricCoordinates<Real, pointSize + 1>;
        using ArrayType = std::array<Real, pointSize>;

        using GetCoordinateFunction = Real (ClassType::*)() const noexcept;
        using SetCoordinateFunction = void (ClassType::*)(Real) noexcept;

    public:
        constexpr Vector3() noexcept
            : x{}, y{}, z{}
        {
        }

        constexpr Vector3(Real x, Real y, Real z) noexcept
            : x{ x }, y{ y }, z{ z }
        {
        }

        template <typename RhsType>
        explicit Vector3(const Vector2<RhsType>& vector);
        template <typename RhsType>
        explicit Vector3(const Vector3<RhsType>& vector);
        template <typename RhsType>
        explicit Vector3(const Vector4<RhsType>& vector);

        explicit Vector3(const ArrayType& coordinate);

        CLASS_INVARIANT_DECLARE;

        // �������
        NODISCARD Real GetX() const noexcept;
        NODISCARD Real GetY() const noexcept;
        NODISCARD Real GetZ() const noexcept;
        NODISCARD bool IsZero(Real epsilon = Math::GetZeroTolerance()) const noexcept;

        void SetCoordinate(const ArrayType& coordinate) noexcept;
        NODISCARD ArrayType GetCoordinate() const noexcept;

        void ZeroOut() noexcept;
        void SetCoordinate(Real aX, Real aY, Real aZ) noexcept;
        void SetX(Real aX) noexcept;
        void SetY(Real aY) noexcept;
        void SetZ(Real aZ) noexcept;
        void Normalize(Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void RobustNormalize(Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD bool IsNormalize(Real epsilon = Math::GetZeroTolerance()) const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD Vector3 operator-() const noexcept;
        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);
        NODISCARD const Real& operator[](PointIndex index) const;
        NODISCARD Real& operator[](PointIndex index);

        Vector3& operator+=(const Vector3& rhs) noexcept;
        Vector3& operator-=(const Vector3& rhs) noexcept;
        Vector3& operator*=(Real rhs) noexcept;
        Vector3& operator/=(Real rhs) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // ����Vector3
        // (0,0,0)
        static constexpr Vector3 GetZero()
        {
            return Vector3{};
        }

        // (1,0,0)
        static constexpr Vector3 GetUnitX()
        {
            return Vector3{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0) };
        }

        // (0,1,0)
        static constexpr Vector3 GetUnitY()
        {
            return Vector3{ Math::GetValue(0), Math::GetValue(1), Math::GetValue(0) };
        }

        // (0,0,1)
        static constexpr Vector3 GetUnitZ()
        {
            return Vector3{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(1) };
        }

        // (1,1,1)
        static constexpr Vector3 GetOne()
        {
            return Vector3{ Math::GetValue(1), Math::GetValue(1), Math::GetValue(1) };
        }

        // ����ڼ������V���������굽������<V0,V1,V2,V3>
        // V = b0 * V0 + b1 * V1 + b2 * V2 + b3 * V3��
        // ����b0 + b1 + b2 + b3 = 1��
        // ���ҽ���{V0��V1��V2, V3}�������޹���ʱ����ֵ����Ч�ġ�
        // ��ֵ�ϣ����� |det[V0 V1 V2 V3]| <= epsilon��
        NODISCARD BarycentricCoordinates GetBarycentrics(const Vector3& vector0,
                                                         const Vector3& vector1,
                                                         const Vector3& vector2,
                                                         const Vector3& vector3,
                                                         const Real epsilon = Math::GetZeroTolerance()) const;

        NODISCARD Vector3 GetMove(Real t, const Vector3& velocity) const;

        NODISCARD Real GetMaxAbsComp() const noexcept;

    private:
        Real x;
        Real y;
        Real z;
    };

    // STL
    template <typename Real>
    NODISCARD bool operator==(const Vector3<Real>& lhs, const Vector3<Real>& rhs);

    template <typename Real>
    NODISCARD bool operator<(const Vector3<Real>& lhs, const Vector3<Real>& rhs) noexcept;

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Vector3<Real>& vector);

    using Vector3F = Vector3<float>;
    using Vector3D = Vector3<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_H
