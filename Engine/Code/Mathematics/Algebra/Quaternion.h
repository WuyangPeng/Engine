///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/10 15:14)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Quaternion final : private boost::additive<Quaternion<Real>, boost::multiplicative<Quaternion<Real>, Real, boost::totally_ordered<Quaternion<Real>>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Quaternion<Real>;

        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Matrix3 = Matrix3<Real>;
        using Matrix3Extract = Matrix3Extract<Real>;
        using QuaternionFactor = QuaternionFactor<Real>;
        using QuaternionConstraints = QuaternionConstraints<Real>;
        using QuaternionSwingTwist = QuaternionSwingTwist<Real>;

        enum class PointIndex
        {
            W = 0,
            X,
            Y,
            Z,
            Size
        };

        static constexpr auto sm_W = System::EnumCastUnderlying(PointIndex::W);
        static constexpr auto sm_X = System::EnumCastUnderlying(PointIndex::X);
        static constexpr auto sm_Y = System::EnumCastUnderlying(PointIndex::Y);
        static constexpr auto sm_Z = System::EnumCastUnderlying(PointIndex::Z);        
        static constexpr auto sm_EntrySize = System::EnumCastUnderlying(PointIndex::Size);
        using ArrayType = std::array<Real, sm_EntrySize>;
        using ContainerType = std::vector<Vector3D>;

    public:
        // ��Ԫ��q = w + x * i + y * j + z * k
        // ����(w,x,y,z)��һ���ǵ�λ���ȵ���ά������

        constexpr Quaternion() noexcept
            : m_W{}, m_X{}, m_Y{}, m_Z{}
        {
        }

        constexpr Quaternion(Real w, Real x, Real y, Real z) noexcept
            : m_W{ w }, m_X{ x }, m_Y{ y }, m_Z{ z }
        {
        }

        // ����Ϊ��ת��������Ԫ��
        explicit Quaternion(const Matrix3& matrix);

        // ͨ����-�ǵ���ת������Ԫ��
        Quaternion(const Vector3D& axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // ͨ��ָ��������ת��������Ԫ����
        explicit Quaternion(const ContainerType& rotationColumn);

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
        Quaternion& operator*=(const Quaternion& rhs) noexcept;

        [[nodiscard]] const Quaternion operator-() const noexcept;

        Quaternion& operator+=(const Quaternion& rhs) noexcept;
        Quaternion& operator-=(const Quaternion& rhs) noexcept;
        Quaternion& operator*=(Real scalar) noexcept;
        Quaternion& operator/=(Real scalar) noexcept;

        // ��Ԫ����������ᡪ����֮���ת����
        void FromRotationMatrix(const Matrix3& matrix);
        [[nodiscard]] const Matrix3 ToRotationMatrix() const noexcept;
        void FromRotationColumnVector3D(const ContainerType& rotationColumn);
        [[nodiscard]] const ContainerType ToRotationColumnVector3D() const;
        void FromAxisAngle(const Vector3D& axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] const Vector3D ToAxis() const;
        [[nodiscard]] Real ToAngle() const noexcept;
        [[nodiscard]] const Matrix3Extract ToAngleAxis() const;

        [[nodiscard]] Real Length() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);  // 4-tuple�ĳ���
        [[nodiscard]] Real SquaredLength() const noexcept;  // 4-tuple�ĳ��ȵ�ƽ��
        void Normalize(Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] const Quaternion Inverse() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);  // �����ڷ�����Ԫ��
        [[nodiscard]] const Quaternion Conjugate() const noexcept;  // ȡ������ x, y, �� z ��
        [[nodiscard]] const Quaternion Exp() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);  // ��������Ԫ�� w = 0
        [[nodiscard]] const Quaternion Log() const noexcept;  // �����ڵ�λ������Ԫ��
        [[nodiscard]] bool IsNormalize(Real epsilon = Math::GetZeroTolerance()) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // ����Ԫ����ת������
        [[nodiscard]] const Vector3D Rotate(const Vector3D& vector) const noexcept;

        // �������Բ�ֵ
        void Slerp(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1) noexcept;
        void SlerpExtraSpins(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, int extraSpins) noexcept;

        // �м�����������β�ֵ
        void Intermediate(const Quaternion& quaternion0, const Quaternion& quaternion1, const Quaternion& quaternion2);

        // ������β�ֵ��
        void Squad(Real t, const Quaternion& q0, const Quaternion& a0, const Quaternion& a1, const Quaternion& q1) noexcept;

        // ������ת��λ����ʸ��vector0����λ����ʸ��vector1����Ԫ����
        // ��ת��Χ�ƴ�ֱ��vector0��vector1���ᣬ
        // �Ƕ���vector0��vector1֮��ĽǶȡ�
        // ���vector0��vector1��ƽ�еģ���ת�����ᶼ�У�
        // �������(z2,x2,y2)�����У�vector1 = (x2,y2,z2)��
        void Align(const Vector3D& vector0, const Vector3D& vector1, Real epsilon = Math::GetZeroTolerance());

        // �ֽ���Ԫ��Ϊq = q_twist * q_swing������q��'this'��Ԫ����
        // ���V1���������V2ΪV1ͨ��q����ת��
        // q_swing��ʾ��Լ��ֱ��V1��V2��������ת����Quaternion::Align����
        // ��q_twist�Ǵ�Լ��V1��ת��
        // ����ֵ�ĵ�һ����Ϊtwist���ڶ�����Ϊswing��
        [[nodiscard]] const QuaternionSwingTwist DecomposeTwistTimesSwing(const Vector3D& vector, Real epsilon = Math::GetZeroTolerance()) const;

        // �ֽ���Ԫ��Ϊq = q_swing * q_twist������q��'this'��Ԫ����
        // ���V1���������V2ΪV1ͨ��q����ת��
        // q_swing��ʾ��Լ��ֱ��V1��V2��������ת����Quaternion::Align����
        // ��q_twist�Ǵ�Լ��V1��ת��
        // ����ֵ�ĵ�һ����Ϊswing���ڶ�����Ϊtwist��

        [[nodiscard]] const QuaternionSwingTwist DecomposeSwingTimesTwist(const Vector3D& vector, Real epsilon = Math::GetZeroTolerance()) const;

        // *** ���������Լ���ĽǶȵ���Ԫ����

        // �����������Ԫ����ʽ(cx + sx * i)��
        [[nodiscard]] const Quaternion GetClosestX() const;

        // �����������Ԫ����ʽ (cy + sy * j).
        [[nodiscard]] const Quaternion GetClosestY() const;

        // �����������Ԫ����ʽ (cz + sz * k).
        [[nodiscard]] const Quaternion GetClosestZ() const;

        // �����������Ԫ����ʽ (cx + sx * i) * (cy + sy * j).
        [[nodiscard]] const Quaternion GetClosestXY() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // �����������Ԫ����ʽ (cy + sy * j) * (cx + sx * i).
        [[nodiscard]] const Quaternion GetClosestYX() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // �����������Ԫ����ʽ (cz + sz * k) * (cx + sx * i).
        [[nodiscard]] const Quaternion GetClosestZX() const;

        // �����������Ԫ����ʽ (cx + sx * i) * (cz + sz * k).
        [[nodiscard]] const Quaternion GetClosestXZ() const;

        // �����������Ԫ����ʽ (cy + sy * j) * (cz + sz * k).
        [[nodiscard]] const Quaternion GetClosestYZ() const;

        // �����������Ԫ����ʽ (cz + sz * k) * (cy + sy * j).
        [[nodiscard]] const Quaternion GetClosestZY() const;

        // ϵ��Ϊ (cx + sx * i) * (cy + sy * j) * (cz + sz * k).
        [[nodiscard]] const QuaternionFactor FactorXYZ() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // ϵ��Ϊ  (cx + sx * i) * (cz + sz * k) * (cy + sy * j).
        [[nodiscard]] const QuaternionFactor FactorXZY() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // ϵ��Ϊ  (cy + sy * j) * (cz + sz * k) * (cx + sx * i).
        [[nodiscard]] const QuaternionFactor FactorYZX() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // ϵ��Ϊ  (cy + sy * j) * (cx + sx * i) * (cz + sz * k).
        [[nodiscard]] const QuaternionFactor FactorYXZ() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // ϵ��Ϊ (cz + sz * k) * (cx + sx * i) * (cy + sy * j).
        [[nodiscard]] const QuaternionFactor FactorZXY() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // ϵ��Ϊ  (cz + sz * k) * (cy + sy * j) * (cx + sx * i).
        [[nodiscard]] const QuaternionFactor FactorZYX() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // ���������Լ����Ԫ����ʽΪ (cx + sx * i).
        [[nodiscard]] const Quaternion GetClosestX(const QuaternionConstraints& xCon) const;

        // ���������Լ����Ԫ����ʽΪ (cy + sy * j).
        [[nodiscard]] const Quaternion GetClosestY(const QuaternionConstraints& yCon) const;

        // ���������Լ����Ԫ����ʽΪ (cz + sz * k).
        [[nodiscard]] const Quaternion GetClosestZ(const QuaternionConstraints& zCon) const;

        // ���������Լ����Ԫ����ʽΪ (cx + sx * i)*(cy + sy * j).
        [[nodiscard]] const Quaternion GetClosestXY(const QuaternionConstraints& xCon, const QuaternionConstraints& yCon) const;

        // ���������Լ����Ԫ����ʽΪ  (cy + sy * j)*(cx + sx * i).
        [[nodiscard]] const Quaternion GetClosestYX(const QuaternionConstraints& yCon, const QuaternionConstraints& xCon) const;

        // ���������Լ����Ԫ����ʽΪ  (cz + sz * k)*(cx + sx * i).
        [[nodiscard]] const Quaternion GetClosestZX(const QuaternionConstraints& zCon, const QuaternionConstraints& xCon) const;

        // ���������Լ����Ԫ����ʽΪ  (cx + sx * i)*(cz + sz * k).
        [[nodiscard]] const Quaternion GetClosestXZ(const QuaternionConstraints& xCon, const QuaternionConstraints& zCon) const;

        // ���������Լ����Ԫ����ʽΪ  (cz + sz * k)*(cy + sy * j).
        [[nodiscard]] const Quaternion GetClosestZY(const QuaternionConstraints& zCon, const QuaternionConstraints& yCon) const;

        // ���������Լ����Ԫ����ʽΪ  (cy + sy * j)*(cz + sz * k).
        [[nodiscard]] const Quaternion GetClosestYZ(const QuaternionConstraints& yCon, const QuaternionConstraints& zCon) const;

        [[nodiscard]] const ArrayType GetCoordinate() const noexcept;
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
        [[nodiscard]] const Quaternion GetClosest(QuaternionClosestAxis axis) const;

        // ���������Ԫ��Լ������ʽ��
        //   (cx + sx * i) �� QuaternionClosestAxis = QuaternionClosestAxis::X,
        //   (cy + sy * j) �� QuaternionClosestAxis = QuaternionClosestAxis::Y,
        //   (cz + sz * k) �� QuaternionClosestAxis = QuaternionClosestAxis::Z,
        [[nodiscard]] const Quaternion GetClosest(QuaternionClosestAxis axis, const QuaternionConstraints& con) const;

    private:
        // �洢��˳����(w,x,y,z)��
        Real m_W;
        Real m_X;
        Real m_Y;
        Real m_Z;
    };

    // �Ƚ� (��ʹ���� STL ����).
    template <typename Real>
    [[nodiscard]] bool operator==(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool operator<(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    template <typename Real>
    [[nodiscard]] const Quaternion<Real> operator*(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    template <typename Real>
    [[nodiscard]] Real Dot(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;  // 4Ԫ��ĵ��

    template <typename Real>
    [[nodiscard]] bool Approximate(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs, const Real epsilon = Math<T>::GetZeroTolerance());

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Quaternion<Real>& quaternion);

    using FloatQuaternion = Quaternion<float>;
    using DoubleQuaternion = Quaternion<double>;
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_H
