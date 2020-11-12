///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/02 13:42)

#ifndef MATHEMATICS_ALGEBRA_AQUATERNION_H
#define MATHEMATICS_ALGEBRA_AQUATERNION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <array>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AQuaternion final : private boost::additive<AQuaternion<Real>, boost::multiplicative<AQuaternion<Real>, Real, boost::totally_ordered<AQuaternion<Real>>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = AQuaternion<Real>;
        using Math = Math<Real>;
        using Matrix = Matrix<Real>;
        using AVector = AVector<Real>;

        enum class PointIndex
        {
            W = 0,
            X,
            Y,
            Z,
            Size
        };

        static constexpr auto sm_EntrySize = System::EnumCastUnderlying(PointIndex::Size);

        using ArrayType = std::array<Real, sm_EntrySize>;

    public:
        // ��Ԫ��q = w + x * i + y * j + z * k
        // ����(w,x,y,z)��һ���ǵ�λ���ȵ���ά������

        constexpr AQuaternion() noexcept
            : m_W{}, m_X{}, m_Y{}, m_Z{}
        {
        }

        constexpr AQuaternion(Real w, Real x, Real y, Real z) noexcept
            : m_W{ w }, m_X{ x }, m_Y{ y }, m_Z{ z }
        {
        }

        AQuaternion(const ArrayType& coordinate) noexcept;

        // ����Ϊ��ת��������Ԫ��
        AQuaternion(const Matrix& matrix);

        // ͨ����-�ǵ���ת������Ԫ��
        AQuaternion(const AVector& axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        CLASS_INVARIANT_DECLARE;

        // �����������������:  0 = w, 1 = x, 2 = y, 3 = z.
        [[nodiscard]] const Real& operator[](int index) const;
        [[nodiscard]] Real& operator[](int index);
        [[nodiscard]] Real GetW() const noexcept;
        void SetW(Real w) noexcept;
        [[nodiscard]] Real GetX() const noexcept;
        void SetX(Real x) noexcept;
        [[nodiscard]] Real GetY() const noexcept;
        void SetY(Real y) noexcept;
        [[nodiscard]] Real GetZ() const noexcept;
        void SetZ(Real z) noexcept;

        // ��������
        AQuaternion& operator*=(const AQuaternion& rhs) noexcept;

        [[nodiscard]] const AQuaternion operator-() const noexcept;

        AQuaternion& operator+=(const AQuaternion& rhs) noexcept;
        AQuaternion& operator-=(const AQuaternion& rhs) noexcept;
        AQuaternion& operator*=(Real scalar) noexcept;
        AQuaternion& operator/=(Real scalar) noexcept;

        // ��Ԫ����������ᡪ����֮���ת����
        void FromRotationMatrix(const Matrix& matrix);
        [[nodiscard]] const Matrix ToRotationMatrix() const noexcept;
        void FromAxisAngle(const AVector& axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] const AVector ToAxis() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] Real ToAngle() const noexcept;

        // 4-tuple�ĳ���
        [[nodiscard]] Real Length() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 4-tuple�ĳ��ȵ�ƽ��
        [[nodiscard]] Real SquaredLength() const noexcept;

        void Normalize(Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // �����ڷ�����Ԫ��
        [[nodiscard]] const AQuaternion Inverse() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // ȡ������ x, y, �� z ��
        [[nodiscard]] const AQuaternion Conjugate() const noexcept;

        // ��������Ԫ�� w = 0
        [[nodiscard]] const AQuaternion Exp() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // �����ڵ�λ������Ԫ��
        [[nodiscard]] const AQuaternion Log() const noexcept;

        [[nodiscard]] bool IsNormalize(Real epsilon = Math::GetZeroTolerance()) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // ����Ԫ����ת������
        [[nodiscard]] const AVector Rotate(const AVector& vector) const noexcept;

        // �������Բ�ֵ
        void Slerp(Real t, const AQuaternion& quaternion0, const AQuaternion& quaternion1) noexcept;

        // �м�����������β�ֵ
        void Intermediate(const AQuaternion& quaternion0, const AQuaternion& quaternion1, const AQuaternion& quaternion2);

        // ������β�ֵ��
        void Squad(Real t, const AQuaternion& q0, const AQuaternion& a0, const AQuaternion& a1, const AQuaternion& q1) noexcept;

        [[nodiscard]] const ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate) noexcept;

        // ������Ԫ��
        static constexpr AQuaternion GetZero()
        {
            return AQuaternion{};
        }

        static constexpr AQuaternion GetIdentity()
        {
            return AQuaternion{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }

    private:
        // �洢��˳����(w,x,y,z)��
        Real m_W;
        Real m_X;
        Real m_Y;
        Real m_Z;
    };

    // �Ƚ� (��ʹ���� STL ����).
    template <typename Real>
    [[nodiscard]] bool operator==(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool operator<(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs) noexcept;

    template <typename Real>
    [[nodiscard]] const AQuaternion<Real> operator*(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs) noexcept;

    // 4Ԫ��ĵ��
    template <typename Real>
    [[nodiscard]] Real Dot(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs) noexcept;

    template <typename Real>
    [[nodiscard]] bool Approximate(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs, const Real epsilon = Math<Real>::GetZeroTolerance()) noexcept;

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const AQuaternion<Real>& quaternion);

    using FloatAQuaternion = AQuaternion<float>;
    using DoubleAQuaternion = AQuaternion<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AQUATERNION_H
