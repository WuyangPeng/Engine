/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/02/05 09:14)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_H
#define MATHEMATICS_ALGEBRA_QUATERNION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "AxisAngle.h"
#include "QuaternionConstraints.h"
#include "QuaternionFactor.h"
#include "QuaternionSwingTwist.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    /// ��Ԫ������ʽΪ
    /// q = x*i + y*j + z*k + w*1 = x*i + y*j + z*k + w
    /// ����w��x��y��z��ʵ�����������ֺ�ʸ�����ֱַ�Ϊ
    ///   Vector(q) = x * i + y * j + z * k
    ///   Scalar(q) = w
    ///   q = Vector(q) + Scalar(q)
    ///
    /// ��ʹ��rotatedU = q * (0,u) * Conjugate(q)������MATHEMATICS_USE_MATRIX_VECTOR����
    /// rotatedU = Conjugate(q) * (0, u) * q������MATHEMATICS_USE_VECTOR_MATRIX��
    /// ��ԭʼʵ����ȣ�Rotate(...)������Ҫ���ٵ��������㡣
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
        using Vector4Tools = Vector4Tools<Real>;
        using Matrix3 = Matrix3<Real>;
        using AxisAngle = AxisAngle<Real>;
        using QuaternionFactor = QuaternionFactor<Real>;
        using QuaternionConstraints = QuaternionConstraints<Real>;
        using QuaternionSwingTwist = QuaternionSwingTwist<Real>;
        using ArrayType = std::array<Real, entrySize>;
        using ContainerType = std::vector<Vector3>;
        using AlgebraVector3 = Algebra::Vector<3, Real>;
        using AlgebraVector4 = Algebra::Vector<4, Real>;

    public:
        /// ��Ԫ������ʽΪq = w + x * i + y * j + z * k
        /// ����(w,x,y,z)��һ���ǵ�λ���ȵ���ά������

        constexpr Quaternion() noexcept
            : w{}, x{}, y{}, z{}
        {
        }

        constexpr Quaternion(Real w, Real x, Real y, Real z) noexcept
            : w{ w }, x{ x }, y{ y }, z{ z }
        {
        }

        /// ����Ϊ��ת��������Ԫ��
        explicit Quaternion(const Matrix3& matrix);

        /// ͨ����-�ǵ���ת������Ԫ��
        Quaternion(const Vector3& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// ͨ��ָ��������ת��������Ԫ����
        explicit Quaternion(const ContainerType& rotationColumn);

        CLASS_INVARIANT_DECLARE;

        /// �����������������:  0 = w, 1 = x, 2 = y, 3 = z.
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

        /// һԪ���㡣
        NODISCARD Quaternion operator+() const noexcept;
        NODISCARD Quaternion operator-() const noexcept;

        /// ���Դ������㡣
        Quaternion& operator+=(const Quaternion& rhs) noexcept;
        Quaternion& operator-=(const Quaternion& rhs) noexcept;
        Quaternion& operator*=(Real scalar) noexcept;
        Quaternion& operator/=(Real scalar) noexcept;

        /// ��������
        Quaternion& operator*=(const Quaternion& rhs) noexcept;

        /// ��Ԫ����������ᡪ����֮���ת����
        void FromRotationMatrix(const Matrix3& matrix);
        NODISCARD Matrix3 ToRotationMatrix() const noexcept;
        void FromRotationColumnVector3(const ContainerType& rotationColumn);
        NODISCARD ContainerType ToRotationColumnVector3() const;
        void FromAxisAngle(const Vector3& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD Vector3 ToAxis() const;
        NODISCARD Real ToAngle() const noexcept;
        NODISCARD AxisAngle ToAngleAxis() const;

        /// 4-tuple�ĳ���
        NODISCARD Real Length() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        /// 4-tuple�ĳ��ȵ�ƽ��
        NODISCARD Real SquaredLength() const noexcept;

        void Normalize(Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD bool IsNormalize(Real epsilon = Math::GetZeroTolerance()) const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        /// ���ڷ�����Ԫ�� q = (w,x,y,z)��inv(q) = (w,-x,-y,-z)/|q|^2��
        /// ����|q|����Ԫ���ĳ��ȡ�
        /// ��qΪ��ʱ�����������㣬����Ϊ�ǲ����ܵ������
        NODISCARD Quaternion Inverse() const;

        /// q = (w,x,y,z) �Ĺ�����conj(q) = (w,-x,-y,-z)��
        /// ȡ������ x, y, �� z ��
        NODISCARD Quaternion Conjugate() const noexcept;

        /// ��������Ԫ�� w = 0
        NODISCARD Quaternion Exp() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// �����ڵ�λ������Ԫ��
        NODISCARD Quaternion Log() const noexcept;

        /// ����Ԫ����ת������

        /// ʹ����Ԫ���˷���ת��άʸ��u = (u0,u1,u2)��
        /// ������Ԫ�������ǵ�λ���ȡ�
        /// ���R�Ƕ�Ӧ����Ԫ��q����ת����
        /// �򵱶�����MATHEMATICS_USE_MATRIX_VECTOR����Ŀ��Ĭ��ֵ��ʱ����Ӧ��u����תʸ��vΪv = R * u ��
        /// ���ߵ�δ����MATHEMATICS_USE_MATRIX_VECTORʱ��Ϊv = u * R��
        NODISCARD Vector3 Rotate(const Vector3& uVector) const;
        NODISCARD AlgebraVector3 Rotate(const AlgebraVector3& uVector) const;

        /// ʹ����Ԫ���˷���ת��άʸ������ʾΪ���4Dʸ��u = (u0,u1,u2,0)��
        /// ������Ԫ�������ǵ�λ���ȡ�
        /// ���R�Ƕ�Ӧ����Ԫ��q����ת����
        /// �򵱶�����MATHEMATICS_USE_MATRIX_VECTOR����Ŀ��Ĭ��ֵ��ʱ����Ӧ��u����תʸ��vΪv = R * u ��
        /// ���ߵ�δ����MATHEMATICS_USE_MATRIX_VECTORʱ��Ϊv = u * R��
        NODISCARD Vector4 Rotate(const Vector4& uVector) const;
        NODISCARD AlgebraVector4 Rotate(const AlgebraVector4& uVector) const;

        /// �������Բ�ֵ
        /// [0,1]��t�ĵ�λ������Ԫ��q0��q1���������Բ�ֵ(slerp)Ϊ
        /// slerp(t,q0,q1) = [sin(t*theta)*q0 + sin((1-t)*theta)*q1]/sin(theta)
        /// ����theta��q0��q1֮��ĽǶ�[cos(theta) = Dot(q0,q1)]��
        /// ��������ǵ�λ��������q0��q1֮��Ĵ����满�Ĳ�������
        /// ���⣬�������ǹ�һ��������һ�֡����������Ż���ʱ��t���Ժ㶨�ٶ��˶���
        ///
        /// �����漰��Ԫ�����еĶ�����ʹ��slerpʱ��ͨ������Ԫ������Ԥ����
        /// �Ա���������Ԫ����[0,pi/2]���γ����A��
        /// ����Ԥ������԰���������ܡ����������Ĺ���ע�͡�
        ///
        /// ��μ�SlerpEstimate.{h,inl}���ڸ��ֽ��ƣ�
        /// ����SLERP<Real>::EstimateRPH��
        /// ��ΪԤ�������Ԫ���ṩ�����õ����ܺ�׼ȷ�Ľ����

        /// q0��q1֮��ĽǶ���[0,pi)�С�
        /// û�нǶ����ƣ�Ҳû��Ԥ�ȼ����κ����ݡ�
        void Slerp(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1);

        /// q0��q1֮��ĽǶȱ�����[0,pi/2]�С�
        /// ��׺Restricted��ʾ�����ޡ���
        /// Ԥ�������Ϊ
        ///   Quaternion<Real> q[n];  // �����ѳ�ʼ��
        ///   for (i0 = 0, i1 = 1; i1 < n; i0 = i1++)
        ///   {
        ///       cosA = Dot(q[i0], q[i1]);
        ///       if (cosA < 0)
        ///       {
        ///           q[i1] = -q[i1];  // ���� Dot(q[i0], q[i]1) >= 0
        ///       }
        ///   }
        void SlerpChebyshevRatioRestricted(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1);

        /// q0��q1֮��ĽǶȱ�����[0,pi/2]�С�
        /// ��׺Restricted��ʾ�����ޡ�����׺Preprocessed��ʾ��Ԥ������
        /// Ԥ���������
        ///   Quaternion<Real> q[n];  // �����ѳ�ʼ��
        ///   Real cosA[n-1]; // ��Ԥ����
        ///   Real omCosA[n-1];  // ��Ԥ����
        ///   for (i0 = 0, i1 = 1; i1 < n; i0 = i1++)
        ///   {
        ///       cs = Dot(q[i0], q[i1]);
        ///       if (cosA[i0] < 0)
        ///       {
        ///           q[i1] = -q[i1];
        ///           cs = -cs;
        ///       }
        ///
        ///       // �� Quaternion<Real>::SlerpRP
        ///       cosA[i0] = cs;
        ///
        ///       // �� SLERP<Real>::EstimateRP
        ///       omCosA[i0] = 1 - cs;
        ///   }
        void SlerpChebyshevRatioRestrictedPreprocessed(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, Real cosA);

        /// q0��q1֮��ĽǶ���A�����ұ�����[0,pi/2]�С�
        /// ��׺Restricted��ʾ�����ޡ���
        /// ��׺Preprocessed��ʾ��Ԥ������
        /// ��׺Half��ʾ���롱��Ԥ�ȼ���q0��q1�м����Ԫ��quaternionHalf����
        /// ��Ԫ��quaternionHalf�� slerp(1/2,q0,q1) = (q0+q1)/|q0+q1|��
        /// ����q0��quaternionHalf֮��ĽǶ���A/2��
        /// qh��q1֮��ĽǶ�ΪA/2��
        /// Ԥ���������
        ///  Quaternion<Real> q[n];  // �����ѳ�ʼ��
        //   Quaternion<Real> qh[n-1];  // ��Ԥ����
        //   Real omCosAH[n-1];  // ��Ԥ����
        //   for (i0 = 0, i1 = 1; i1 < n; i0 = i1++)
        //   {
        //       cosA = Dot(q[i0], q[i1]);
        //       if (cosA < 0)
        //       {
        //           q[i1] = -q[i1];
        //           cosA = -cosA;
        //       }
        //
        //       // �� Quaternion<Real>::SlerpRPH �� SLERP<Real>::EstimateRPH
        //       cosAH[i0] = sqrt((1+cosA)/2);
        //       qh[i0] = (q0 + q1) / (2 * cosAH[i0]);
        //
        //       // �� SLERP<Real>::EstimateRPH
        //       omCosAH[i0] = 1 - cosAH[i0];
        //   }
        void SlerpChebyshevRatioRestrictedPreprocessedHalf(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, const Quaternion& quaternionHalf, Real cosAHalf);

        void SlerpExtraSpins(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, int extraSpins) noexcept;
        void SlerpChebyshevRatio(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1);

        /// �м�����������β�ֵ
        void Intermediate(const Quaternion& quaternion0, const Quaternion& quaternion1, const Quaternion& quaternion2);

        /// ������β�ֵ��
        void Squad(Real t, const Quaternion& q0, const Quaternion& a0, const Quaternion& a1, const Quaternion& q1);

        /// ������ת��λ����ʸ��vector0����λ����ʸ��vector1����Ԫ����
        /// ��ת��Χ�ƴ�ֱ��vector0��vector1���ᣬ
        /// �Ƕ���vector0��vector1֮��ĽǶȡ�
        /// ���vector0��vector1��ƽ�еģ���ת�����ᶼ�У�
        /// �������(z2,x2,y2)�����У�vector1 = (x2,y2,z2)��
        void Align(const Vector3& vector0, const Vector3& vector1, Real epsilon = Math::GetZeroTolerance());

        /// �ֽ���Ԫ��Ϊq = q_twist * q_swing������q��'this'��Ԫ����
        /// ���V1���������V2ΪV1ͨ��q����ת��
        /// q_swing��ʾ��Լ��ֱ��V1��V2��������ת����Quaternion::Align����
        /// ��q_twist�Ǵ�Լ��V1��ת��
        /// ����ֵ�ĵ�һ����Ϊtwist���ڶ�����Ϊswing��
        NODISCARD QuaternionSwingTwist DecomposeTwistTimesSwing(const Vector3& vector, Real epsilon = Math::GetZeroTolerance()) const;

        /// �ֽ���Ԫ��Ϊq = swing * twist������q��'this'��Ԫ����
        /// ���V1���������V2ΪV1ͨ��q����ת��
        /// swing��ʾ��Լ��ֱ��V1��V2��������ת����Quaternion::Align����
        /// ��twist�Ǵ�Լ��V1��ת��
        /// ����ֵ�ĵ�һ����Ϊswing���ڶ�����Ϊtwist��

        NODISCARD QuaternionSwingTwist DecomposeSwingTimesTwist(const Vector3& vector, Real epsilon = Math::GetZeroTolerance()) const;

        /// *** ���������Լ���ĽǶȵ���Ԫ����

        /// �����������Ԫ����ʽ(cx + sx * i)��
        NODISCARD Quaternion GetClosestX() const;

        /// �����������Ԫ����ʽ (cy + sy * j).
        NODISCARD Quaternion GetClosestY() const;

        /// �����������Ԫ����ʽ (cz + sz * k).
        NODISCARD Quaternion GetClosestZ() const;

        /// �����������Ԫ����ʽ (cx + sx * i) * (cy + sy * j).
        NODISCARD Quaternion GetClosestXY() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        /// �����������Ԫ����ʽ (cy + sy * j) * (cx + sx * i).
        NODISCARD Quaternion GetClosestYX() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        /// �����������Ԫ����ʽ (cz + sz * k) * (cx + sx * i).
        NODISCARD Quaternion GetClosestZX() const;

        /// �����������Ԫ����ʽ (cx + sx * i) * (cz + sz * k).
        NODISCARD Quaternion GetClosestXZ() const;

        /// �����������Ԫ����ʽ (cy + sy * j) * (cz + sz * k).
        NODISCARD Quaternion GetClosestYZ() const;

        /// �����������Ԫ����ʽ (cz + sz * k) * (cy + sy * j).
        NODISCARD Quaternion GetClosestZY() const;

        /// ϵ��Ϊ (cx + sx * i) * (cy + sy * j) * (cz + sz * k).
        NODISCARD QuaternionFactor FactorXYZ() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// ϵ��Ϊ  (cx + sx * i) * (cz + sz * k) * (cy + sy * j).
        NODISCARD QuaternionFactor FactorXZY() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// ϵ��Ϊ  (cy + sy * j) * (cz + sz * k) * (cx + sx * i).
        NODISCARD QuaternionFactor FactorYZX() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// ϵ��Ϊ  (cy + sy * j) * (cx + sx * i) * (cz + sz * k).
        NODISCARD QuaternionFactor FactorYXZ() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// ϵ��Ϊ (cz + sz * k) * (cx + sx * i) * (cy + sy * j).
        NODISCARD QuaternionFactor FactorZXY() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// ϵ��Ϊ  (cz + sz * k) * (cy + sy * j) * (cx + sx * i).
        NODISCARD QuaternionFactor FactorZYX() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// ���������Լ����Ԫ����ʽΪ (cx + sx * i).
        NODISCARD Quaternion GetClosestX(const QuaternionConstraints& xCon) const;

        /// ���������Լ����Ԫ����ʽΪ (cy + sy * j).
        NODISCARD Quaternion GetClosestY(const QuaternionConstraints& yCon) const;

        /// ���������Լ����Ԫ����ʽΪ (cz + sz * k).
        NODISCARD Quaternion GetClosestZ(const QuaternionConstraints& zCon) const;

        /// ���������Լ����Ԫ����ʽΪ (cx + sx * i)*(cy + sy * j).
        NODISCARD Quaternion GetClosestXY(const QuaternionConstraints& xCon, const QuaternionConstraints& yCon) const;

        /// ���������Լ����Ԫ����ʽΪ  (cy + sy * j)*(cx + sx * i).
        NODISCARD Quaternion GetClosestYX(const QuaternionConstraints& yCon, const QuaternionConstraints& xCon) const;

        /// ���������Լ����Ԫ����ʽΪ  (cz + sz * k)*(cx + sx * i).
        NODISCARD Quaternion GetClosestZX(const QuaternionConstraints& zCon, const QuaternionConstraints& xCon) const;

        /// ���������Լ����Ԫ����ʽΪ  (cx + sx * i)*(cz + sz * k).
        NODISCARD Quaternion GetClosestXZ(const QuaternionConstraints& xCon, const QuaternionConstraints& zCon) const;

        /// ���������Լ����Ԫ����ʽΪ  (cz + sz * k)*(cy + sy * j).
        NODISCARD Quaternion GetClosestZY(const QuaternionConstraints& zCon, const QuaternionConstraints& yCon) const;

        /// ���������Լ����Ԫ����ʽΪ  (cy + sy * j)*(cz + sz * k).
        NODISCARD Quaternion GetClosestYZ(const QuaternionConstraints& yCon, const QuaternionConstraints& zCon) const;

        NODISCARD ArrayType GetCoordinate() const noexcept;
        void SetCoordinate(const ArrayType& coordinate) noexcept;

        /// ������Ԫ��
        static constexpr Quaternion GetZero() noexcept
        {
            return Quaternion{};
        }

        static constexpr Quaternion GetI() noexcept
        {
            return Quaternion{ Math::GetValue(0), Math::GetValue(1), Math::GetValue(0), Math::GetValue(0) };
        }

        static constexpr Quaternion GetJ() noexcept
        {
            return Quaternion{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(1), Math::GetValue(0) };
        }

        static constexpr Quaternion GetK() noexcept
        {
            return Quaternion{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(0), Math::GetValue(1) };
        }

        static constexpr Quaternion GetIdentity() noexcept
        {
            return Quaternion{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }

    private:
        /// ���������Ԫ��Լ������ʽ��
        ///   (cx + sx * i) �� QuaternionClosestAxis = QuaternionClosestAxis::X,
        ///   (cy + sy * j) �� QuaternionClosestAxis = QuaternionClosestAxis::Y,
        ///   (cz + sz * k) �� QuaternionClosestAxis = QuaternionClosestAxis::Z,
        NODISCARD Quaternion GetClosest(QuaternionClosestAxis axis) const;

        /// ���������Ԫ��Լ������ʽ��
        ///   (cx + sx * i) �� QuaternionClosestAxis = QuaternionClosestAxis::X,
        ///   (cy + sy * j) �� QuaternionClosestAxis = QuaternionClosestAxis::Y,
        ///   (cz + sz * k) �� QuaternionClosestAxis = QuaternionClosestAxis::Z,
        NODISCARD Quaternion GetClosest(QuaternionClosestAxis axis, const QuaternionConstraints& con) const;

    private:
        /// �洢��˳����(w,x,y,z)��
        Real w;
        Real x;
        Real y;
        Real z;
    };

    /// �Ƚ� (��ʹ���� STL ����).
    template <typename Real>
    NODISCARD bool operator==(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD bool operator<(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    /// ��Ԫ���ĳ˻����˷�һ�㲻�ǿɽ����ģ������ڴ��������£�
    /// p * q != q * p
    /// (x0*i + y0*j + z0*k + w0)*(x1*i + y1*j + z1*k + w1)
    /// =
    /// i*(+x0*w1 + y0*z1 - z0*y1 + w0*x1) +
    /// j*(-x0*z1 + y0*w1 + z0*x1 + w0*y1) +
    /// k*(+x0*y1 - y0*x1 + z0*w1 + w0*z1) +
    /// 1*(-x0*x1 - y0*y1 - z0*z1 + w0*w1)
    template <typename Real>
    NODISCARD Quaternion<Real> operator*(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    /// ��������
    /// 4Ԫ��ĵ��
    template <typename Real>
    NODISCARD Real Dot(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD bool Approximate(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance()) noexcept;

    /// ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& stream, const Quaternion<Real>& quaternion);

    using QuaternionF = Quaternion<float>;
    using QuaternionD = Quaternion<double>;
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_H
