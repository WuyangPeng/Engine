///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 14:55)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_H
#define MATHEMATICS_ALGEBRA_QUATERNION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Matrix3Extract.h"
#include "QuaternionConstraints.h"
#include "QuaternionFactor.h"
#include "QuaternionSwingTwist.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Quaternion final : private boost::additive<Quaternion<Real>, boost::multiplicative<Quaternion<Real>, Real, boost::totally_ordered<Quaternion<Real>>>>
    {
    public:
        using ClassType = Quaternion<Real>;

        enum class PointIndex
        {
            W = 0,
            X,
            Y,
            Z,
            Size
        };

        static constexpr auto wIndex = System::EnumCastUnderlying(PointIndex::W);
        static constexpr auto xIndex = System::EnumCastUnderlying(PointIndex::X);
        static constexpr auto yIndex = System::EnumCastUnderlying(PointIndex::Y);
        static constexpr auto zIndex = System::EnumCastUnderlying(PointIndex::Z);
        static constexpr auto entrySize = System::EnumCastUnderlying(PointIndex::Size);

        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;
        using Vector4 = Vector4<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Matrix3 = Matrix3<Real>;
        using Matrix3Extract = Matrix3Extract<Real>;
        using QuaternionFactor = QuaternionFactor<Real>;
        using QuaternionConstraints = QuaternionConstraints<Real>;
        using QuaternionSwingTwist = QuaternionSwingTwist<Real>;
        using ArrayType = std::array<Real, entrySize>;
        using ContainerType = std::vector<Vector3>;

    public:
        // ��Ԫ��q = w + x * i + y * j + z * k
        // ����(w,x,y,z)��һ���ǵ�λ���ȵ���ά������

        constexpr Quaternion() noexcept
            : w{}, x{}, y{}, z{}
        {
        }

        constexpr Quaternion(Real w, Real x, Real y, Real z) noexcept
            : w{ w }, x{ x }, y{ y }, z{ z }
        {
        }

        // ����Ϊ��ת��������Ԫ��
        explicit Quaternion(const Matrix3& matrix);

        // ͨ����-�ǵ���ת������Ԫ��
        Quaternion(const Vector3& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // ͨ��ָ��������ת��������Ԫ����
        explicit Quaternion(const ContainerType& rotationColumn);

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
        Quaternion& operator*=(const Quaternion& rhs) noexcept;

        NODISCARD Quaternion operator-() const noexcept;

        Quaternion& operator+=(const Quaternion& rhs) noexcept;
        Quaternion& operator-=(const Quaternion& rhs) noexcept;
        Quaternion& operator*=(Real scalar) noexcept;
        Quaternion& operator/=(Real scalar) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // ��Ԫ����������ᡪ����֮���ת����
        void FromRotationMatrix(const Matrix3& matrix);
        NODISCARD Matrix3 ToRotationMatrix() const noexcept;
        void FromRotationColumnVector3(const ContainerType& rotationColumn);
        NODISCARD ContainerType ToRotationColumnVector3() const;
        void FromAxisAngle(const Vector3& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD Vector3 ToAxis() const;
        NODISCARD Real ToAngle() const noexcept;
        NODISCARD Matrix3Extract ToAngleAxis() const;

        NODISCARD Real Length() const noexcept(gAssert < 3 || gMathematicsAssert < 3);  // 4-tuple�ĳ���
        NODISCARD Real SquaredLength() const noexcept;  // 4-tuple�ĳ��ȵ�ƽ��
        void Normalize(Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD Quaternion Inverse() const noexcept(gAssert < 1 || gMathematicsAssert < 1);  // �����ڷ�����Ԫ��
        NODISCARD Quaternion Conjugate() const noexcept;  // ȡ������ x, y, �� z ��
        NODISCARD Quaternion Exp() const noexcept(gAssert < 1 || gMathematicsAssert < 1);  // ��������Ԫ�� w = 0
        NODISCARD Quaternion Log() const noexcept;  // �����ڵ�λ������Ԫ��
        NODISCARD bool IsNormalize(Real epsilon = Math::GetZeroTolerance()) const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // ����Ԫ����ת������
        NODISCARD Vector3 Rotate(const Vector3& vector) const noexcept;
        NODISCARD Vector4 Rotate(const Vector4& vector) const noexcept;

        // �������Բ�ֵ
        void Slerp(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1) noexcept;
        void SlerpExtraSpins(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, int extraSpins) noexcept;
        void SlerpChebyshevRatio(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1);
        void SlerpChebyshevRatioRestricted(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1);
        void SlerpChebyshevRatioRestrictedPreprocessed(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, Real cosA);
        void SlerpChebyshevRatioRestrictedPreprocessedHalf(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, const Quaternion& quaternionHalf, Real cosAHalf);

        // �м�����������β�ֵ
        void Intermediate(const Quaternion& quaternion0, const Quaternion& quaternion1, const Quaternion& quaternion2);

        // ������β�ֵ��
        void Squad(Real t, const Quaternion& q0, const Quaternion& a0, const Quaternion& a1, const Quaternion& q1) noexcept;

        // ������ת��λ����ʸ��vector0����λ����ʸ��vector1����Ԫ����
        // ��ת��Χ�ƴ�ֱ��vector0��vector1���ᣬ
        // �Ƕ���vector0��vector1֮��ĽǶȡ�
        // ���vector0��vector1��ƽ�еģ���ת�����ᶼ�У�
        // �������(z2,x2,y2)�����У�vector1 = (x2,y2,z2)��
        void Align(const Vector3& vector0, const Vector3& vector1, Real epsilon = Math::GetZeroTolerance());

        // �ֽ���Ԫ��Ϊq = q_twist * q_swing������q��'this'��Ԫ����
        // ���V1���������V2ΪV1ͨ��q����ת��
        // q_swing��ʾ��Լ��ֱ��V1��V2��������ת����Quaternion::Align����
        // ��q_twist�Ǵ�Լ��V1��ת��
        // ����ֵ�ĵ�һ����Ϊtwist���ڶ�����Ϊswing��
        NODISCARD QuaternionSwingTwist DecomposeTwistTimesSwing(const Vector3& vector, Real epsilon = Math::GetZeroTolerance()) const;

        // �ֽ���Ԫ��Ϊq = q_swing * q_twist������q��'this'��Ԫ����
        // ���V1���������V2ΪV1ͨ��q����ת��
        // q_swing��ʾ��Լ��ֱ��V1��V2��������ת����Quaternion::Align����
        // ��q_twist�Ǵ�Լ��V1��ת��
        // ����ֵ�ĵ�һ����Ϊswing���ڶ�����Ϊtwist��

        NODISCARD QuaternionSwingTwist DecomposeSwingTimesTwist(const Vector3& vector, Real epsilon = Math::GetZeroTolerance()) const;

        // *** ���������Լ���ĽǶȵ���Ԫ����

        // �����������Ԫ����ʽ(cx + sx * i)��
        NODISCARD Quaternion GetClosestX() const;

        // �����������Ԫ����ʽ (cy + sy * j).
        NODISCARD Quaternion GetClosestY() const;

        // �����������Ԫ����ʽ (cz + sz * k).
        NODISCARD Quaternion GetClosestZ() const;

        // �����������Ԫ����ʽ (cx + sx * i) * (cy + sy * j).
        NODISCARD Quaternion GetClosestXY() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // �����������Ԫ����ʽ (cy + sy * j) * (cx + sx * i).
        NODISCARD Quaternion GetClosestYX() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // �����������Ԫ����ʽ (cz + sz * k) * (cx + sx * i).
        NODISCARD Quaternion GetClosestZX() const;

        // �����������Ԫ����ʽ (cx + sx * i) * (cz + sz * k).
        NODISCARD Quaternion GetClosestXZ() const;

        // �����������Ԫ����ʽ (cy + sy * j) * (cz + sz * k).
        NODISCARD Quaternion GetClosestYZ() const;

        // �����������Ԫ����ʽ (cz + sz * k) * (cy + sy * j).
        NODISCARD Quaternion GetClosestZY() const;

        // ϵ��Ϊ (cx + sx * i) * (cy + sy * j) * (cz + sz * k).
        NODISCARD QuaternionFactor FactorXYZ() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // ϵ��Ϊ  (cx + sx * i) * (cz + sz * k) * (cy + sy * j).
        NODISCARD QuaternionFactor FactorXZY() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // ϵ��Ϊ  (cy + sy * j) * (cz + sz * k) * (cx + sx * i).
        NODISCARD QuaternionFactor FactorYZX() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // ϵ��Ϊ  (cy + sy * j) * (cx + sx * i) * (cz + sz * k).
        NODISCARD QuaternionFactor FactorYXZ() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // ϵ��Ϊ (cz + sz * k) * (cx + sx * i) * (cy + sy * j).
        NODISCARD QuaternionFactor FactorZXY() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // ϵ��Ϊ  (cz + sz * k) * (cy + sy * j) * (cx + sx * i).
        NODISCARD QuaternionFactor FactorZYX() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // ���������Լ����Ԫ����ʽΪ (cx + sx * i).
        NODISCARD Quaternion GetClosestX(const QuaternionConstraints& xCon) const;

        // ���������Լ����Ԫ����ʽΪ (cy + sy * j).
        NODISCARD Quaternion GetClosestY(const QuaternionConstraints& yCon) const;

        // ���������Լ����Ԫ����ʽΪ (cz + sz * k).
        NODISCARD Quaternion GetClosestZ(const QuaternionConstraints& zCon) const;

        // ���������Լ����Ԫ����ʽΪ (cx + sx * i)*(cy + sy * j).
        NODISCARD Quaternion GetClosestXY(const QuaternionConstraints& xCon, const QuaternionConstraints& yCon) const;

        // ���������Լ����Ԫ����ʽΪ  (cy + sy * j)*(cx + sx * i).
        NODISCARD Quaternion GetClosestYX(const QuaternionConstraints& yCon, const QuaternionConstraints& xCon) const;

        // ���������Լ����Ԫ����ʽΪ  (cz + sz * k)*(cx + sx * i).
        NODISCARD Quaternion GetClosestZX(const QuaternionConstraints& zCon, const QuaternionConstraints& xCon) const;

        // ���������Լ����Ԫ����ʽΪ  (cx + sx * i)*(cz + sz * k).
        NODISCARD Quaternion GetClosestXZ(const QuaternionConstraints& xCon, const QuaternionConstraints& zCon) const;

        // ���������Լ����Ԫ����ʽΪ  (cz + sz * k)*(cy + sy * j).
        NODISCARD Quaternion GetClosestZY(const QuaternionConstraints& zCon, const QuaternionConstraints& yCon) const;

        // ���������Լ����Ԫ����ʽΪ  (cy + sy * j)*(cz + sz * k).
        NODISCARD Quaternion GetClosestYZ(const QuaternionConstraints& yCon, const QuaternionConstraints& zCon) const;

        NODISCARD ArrayType GetCoordinate() const noexcept;
        void SetCoordinate(const ArrayType& coordinate) noexcept;

        // ������Ԫ��
        static constexpr Quaternion GetZero() noexcept
        {
            return Quaternion{};
        }

        static constexpr Quaternion GetIdentity() noexcept
        {
            return Quaternion{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }

    private:
        // ���������Ԫ��Լ������ʽ��
        //   (cx + sx * i) �� QuaternionClosestAxis = QuaternionClosestAxis::X,
        //   (cy + sy * j) �� QuaternionClosestAxis = QuaternionClosestAxis::Y,
        //   (cz + sz * k) �� QuaternionClosestAxis = QuaternionClosestAxis::Z,
        NODISCARD Quaternion GetClosest(QuaternionClosestAxis axis) const;

        // ���������Ԫ��Լ������ʽ��
        //   (cx + sx * i) �� QuaternionClosestAxis = QuaternionClosestAxis::X,
        //   (cy + sy * j) �� QuaternionClosestAxis = QuaternionClosestAxis::Y,
        //   (cz + sz * k) �� QuaternionClosestAxis = QuaternionClosestAxis::Z,
        NODISCARD Quaternion GetClosest(QuaternionClosestAxis axis, const QuaternionConstraints& con) const;

    private:
        // �洢��˳����(w,x,y,z)��
        Real w;
        Real x;
        Real y;
        Real z;
    };

    // �Ƚ� (��ʹ���� STL ����).
    template <typename Real>
    NODISCARD bool operator==(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs);

    template <typename Real>
    NODISCARD bool operator<(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD Quaternion<Real> operator*(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD Real Dot(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;  // 4Ԫ��ĵ��

    template <typename Real>
    NODISCARD bool Approximate(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance()) noexcept;

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Quaternion<Real>& quaternion);

    using QuaternionF = Quaternion<float>;
    using QuaternionD = Quaternion<double>;
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_H
