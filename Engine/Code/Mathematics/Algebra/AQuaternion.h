///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 14:39)

#ifndef MATHEMATICS_ALGEBRA_A_QUATERNION_H
#define MATHEMATICS_ALGEBRA_A_QUATERNION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <array>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AQuaternion final : private boost::additive<AQuaternion<Real>, boost::multiplicative<AQuaternion<Real>, Real, boost::totally_ordered<AQuaternion<Real>>>>
    {
    public:
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

        static constexpr auto entrySize = System::EnumCastUnderlying(PointIndex::Size);

        using ArrayType = std::array<Real, entrySize>;

    public:
        // ��Ԫ��q = w + x * i + y * j + z * k
        // ����(w,x,y,z)��һ���ǵ�λ���ȵ���ά������

        constexpr AQuaternion() noexcept
            : w{}, x{}, y{}, z{}
        {
        }

        constexpr AQuaternion(Real w, Real x, Real y, Real z) noexcept
            : w{ w }, x{ x }, y{ y }, z{ z }
        {
        }

        explicit AQuaternion(const ArrayType& coordinate) noexcept;

        // ����Ϊ��ת��������Ԫ��
        explicit AQuaternion(const Matrix& matrix);

        // ͨ����-�ǵ���ת������Ԫ��
        AQuaternion(const AVector& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        CLASS_INVARIANT_DECLARE;

        // �����������������:  0 = w, 1 = x, 2 = y, 3 = z.
        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);
        NODISCARD Real GetW() const noexcept;
        void SetW(Real aW) noexcept;
        NODISCARD Real GetX() const noexcept;
        void SetX(Real aX) noexcept;
        NODISCARD Real GetY() const noexcept;
        void SetY(Real aY) noexcept;
        NODISCARD Real GetZ() const noexcept;
        void SetZ(Real aZ) noexcept;

        // ��������
        AQuaternion& operator*=(const AQuaternion& rhs) noexcept;

        NODISCARD AQuaternion operator-() const noexcept;

        AQuaternion& operator+=(const AQuaternion& rhs) noexcept;
        AQuaternion& operator-=(const AQuaternion& rhs) noexcept;
        AQuaternion& operator*=(Real scalar) noexcept;
        AQuaternion& operator/=(Real scalar) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // ��Ԫ����������ᡪ����֮���ת����
        void FromRotationMatrix(const Matrix& matrix);
        NODISCARD Matrix ToRotationMatrix() const noexcept;
        void FromAxisAngle(const AVector& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD AVector ToAxis() const noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD Real ToAngle() const noexcept;

        // 4-tuple�ĳ���
        NODISCARD Real Length() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 4-tuple�ĳ��ȵ�ƽ��
        NODISCARD Real SquaredLength() const noexcept;

        void Normalize(Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // �����ڷ�����Ԫ��
        NODISCARD AQuaternion Inverse() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // ȡ������ x, y, �� z ��
        NODISCARD AQuaternion Conjugate() const noexcept;

        // ��������Ԫ�� w = 0
        NODISCARD AQuaternion Exp() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // �����ڵ�λ������Ԫ��
        NODISCARD AQuaternion Log() const noexcept;

        NODISCARD bool IsNormalize(Real epsilon = Math::GetZeroTolerance()) const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // ����Ԫ����ת������
        NODISCARD AVector Rotate(const AVector& vector) const noexcept;

        // �������Բ�ֵ
        void Slerp(Real t, const AQuaternion& quaternion0, const AQuaternion& quaternion1) noexcept;

        // �м�����������β�ֵ
        void Intermediate(const AQuaternion& quaternion0, const AQuaternion& quaternion1, const AQuaternion& quaternion2);

        // ������β�ֵ��
        void Squad(Real t, const AQuaternion& q0, const AQuaternion& a0, const AQuaternion& a1, const AQuaternion& q1) noexcept;

        NODISCARD ArrayType GetCoordinate() const noexcept;
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
        Real w;
        Real x;
        Real y;
        Real z;
    };

    // �Ƚ� (��ʹ���� STL ����).
    template <typename Real>
    NODISCARD bool operator==(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs);

    template <typename Real>
    NODISCARD bool operator<(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD AQuaternion<Real> operator*(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs) noexcept;

    // 4Ԫ��ĵ��
    template <typename Real>
    NODISCARD Real Dot(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD bool Approximate(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance()) noexcept;

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const AQuaternion<Real>& quaternion);

    using AQuaternionF = AQuaternion<float>;
    using AQuaternionD = AQuaternion<double>;
}

#endif  // MATHEMATICS_ALGEBRA_A_QUATERNION_H
