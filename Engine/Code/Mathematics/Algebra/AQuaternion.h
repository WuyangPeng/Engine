// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.5 (2020/03/19 10:06)

#ifndef MATHEMATICS_ALGEBRA_AQUATERNION_H
#define MATHEMATICS_ALGEBRA_AQUATERNION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/MathDetail.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AQuaternion : private boost::additive<AQuaternion<Real>,
                                                                                     boost::multiplicative<AQuaternion<Real>, Real,
                                                                                                           boost::totally_ordered<AQuaternion<Real>>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = AQuaternion<Real>;
        using Math = Math<Real>;
        using Matrix = Matrix<Real>;
        using AVector = AVector<Real>;
        using AlgebraTraits = AlgebraTraits<Real>;

        constexpr static auto sm_EntrySize = 4;
        using ArrayType = std::array<Real, sm_EntrySize>;

    public:
        // ��Ԫ��q = w + x * i + y * j + z * k
        // ����(w,x,y,z)��һ���ǵ�λ���ȵ���ά������

        AQuaternion() noexcept;
        AQuaternion(Real w, Real x, Real y, Real z) noexcept;

        // ����Ϊ��ת��������Ԫ��
        AQuaternion(const Matrix& matrix);

        // ͨ����-�ǵ���ת������Ԫ��
        AQuaternion(const AVector& axis, Real angle);

        AQuaternion(const AQuaternion&) noexcept = default;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
        AQuaternion& operator=(const AQuaternion& rhs) noexcept = default;
#include STSTEM_WARNING_POP
        ~AQuaternion() noexcept = default;
        AQuaternion(AQuaternion&& rhs) noexcept
            : m_Tuple{}
        {
            for (int i = 0; i < 4; ++i)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
                m_Tuple[i] = rhs.m_Tuple[i];
#include STSTEM_WARNING_POP
            }
        }
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
        AQuaternion& operator=(AQuaternion&& rhs) noexcept
        {
            for (int i = 0; i < 4; ++i)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
                m_Tuple[i] = rhs.m_Tuple[i];
#include STSTEM_WARNING_POP
            }

            return *this;
        }
#include STSTEM_WARNING_POP

        CLASS_INVARIANT_DECLARE;

        // �����������������:  0 = w, 1 = x, 2 = y, 3 = z.
        const Real& operator[](int index) const;
        Real& operator[](int index);
        Real GetW() const noexcept;
        void SetW(Real w) noexcept;
        Real GetX() const noexcept;
        void SetX(Real x) noexcept;
        Real GetY() const noexcept;
        void SetY(Real y) noexcept;
        Real GetZ() const noexcept;
        void SetZ(Real z) noexcept;

        // ��������
        AQuaternion& operator*=(const AQuaternion& rhs);

        const AQuaternion operator-() const noexcept;

        AQuaternion& operator+=(const AQuaternion& rhs) noexcept;
        AQuaternion& operator-=(const AQuaternion& rhs) noexcept;
        AQuaternion& operator*=(Real scalar) noexcept;
        AQuaternion& operator/=(Real scalar) noexcept;

        // ��Ԫ����������ᡪ����֮���ת����
        void FromRotationMatrix(const Matrix& matrix);
        const Matrix ToRotationMatrix() const noexcept;
        void FromAxisAngle(const AVector& axis, Real angle);
        const AVector ToAxis() const;
        Real ToAngle() const noexcept;

        // 4-tuple�ĳ���
        Real Length() const;

        // 4-tuple�ĳ��ȵ�ƽ��
        Real SquaredLength() const noexcept;

        void Normalize(Real epsilon = Math::GetZeroTolerance());

        // �����ڷ�����Ԫ��
        const AQuaternion Inverse() const;

        // ȡ������ x, y, �� z ��
        const AQuaternion Conjugate() const noexcept;

        // ��������Ԫ�� w = 0
        const AQuaternion Exp() const;

        // �����ڵ�λ������Ԫ��
        const AQuaternion Log() const noexcept;

        bool IsNormalize(Real epsilon = Math::GetZeroTolerance()) const;

        // ����Ԫ����ת������
        const AVector Rotate(const AVector& vector) const;

        // �������Բ�ֵ
        void Slerp(Real t, const AQuaternion& firstQuaternion, const AQuaternion& secondQuaternion);

        // �м�����������β�ֵ
        void Intermediate(const AQuaternion& firstQuaternion, const AQuaternion& secondQuaternion, const AQuaternion& thirdQuaternion);

        // ������β�ֵ��
        void Squad(Real t, const AQuaternion& q0, const AQuaternion& a0,
                   const AQuaternion& a1, const AQuaternion& q1);

        [[nodiscard]] const ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate) noexcept;

        // ������Ԫ��
        static const AQuaternion sm_Zero;
        static const AQuaternion sm_Identity;

    private:
        // �洢��˳����(w,x,y,z)��
        Real m_Tuple[4];
    };

    // �Ƚ� (��ʹ���� STL ����).
    template <typename Real>
    bool operator==(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs);

    template <typename Real>
    bool operator<(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs);

    template <typename Real>
    const AQuaternion<Real> operator*(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs);

    // 4Ԫ��ĵ��
    template <typename Real>
    Real Dot(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs);

    template <typename Real>
    bool Approximate(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs, const Real epsilon);

    template <typename Real>
    bool Approximate(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const AQuaternion<Real>& quaternion);

    using AQuaternionf = AQuaternion<float>;
    using AQuaterniond = AQuaternion<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AQUATERNION_H
