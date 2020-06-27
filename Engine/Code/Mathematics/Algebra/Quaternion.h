// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 10:14)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_H
#define MATHEMATICS_ALGEBRA_QUATERNION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "QuaternionFactor.h"
#include "QuaternionConstraints.h"
#include "QuaternionSwingTwist.h"
#include "Matrix3Extract.h"
#include "Flags/QuaternionFlags.h"
#include "CoreTools/DataTypes/TupleDetail.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Quaternion : private boost::additive<Quaternion<Real>,
																    boost::multiplicative<Quaternion<Real>, Real,
																	boost::totally_ordered<Quaternion<Real> > > >
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Quaternion<Real>;
		using AlgebraTraits = AlgebraTraits<Real>;
		using Math = Math<Real>;
		using Vector3D = Vector3D<Real>;
		using Matrix3 = Matrix3<Real>;
		using QuaternionSwingTwist = QuaternionSwingTwist<Real>;
		using QuaternionFactor = QuaternionFactor<Real>;
		using QuaternionConstraints = QuaternionConstraints<Real>;
		using Matrix3Extract = Matrix3Extract<Real>;
		using Vector3DTools = Vector3DTools<Real>;

	public:
		// ��Ԫ��q = w + x * i + y * j + z * k
		// ����(w,x,y,z)��һ���ǵ�λ���ȵ���ά������

		Quaternion();
		Quaternion(Real w, Real x, Real y, Real z);
		Quaternion(const Quaternion& rhs);

		// ����Ϊ��ת��������Ԫ��
		Quaternion(const Matrix3& matrix);

		// ͨ����-�ǵ���ת������Ԫ��
		Quaternion(const Vector3D& axis, Real angle);

		// ͨ��ָ��������ת��������Ԫ����
		Quaternion(const std::vector<Vector3D>& rotationColumn);

		Quaternion& operator= (const Quaternion& rhs);

		CLASS_INVARIANT_DECLARE;

		// �����������������:  0 = w, 1 = x, 2 = y, 3 = z.
		const Real& operator[] (int index) const;
		Real& operator[] (int index);
		Real GetW() const;
		void SetW(Real w);
		Real GetX() const;
		void SetX(Real x);
		Real GetY() const;
		void SetY(Real y);
		Real GetZ() const;
		void SetZ(Real z);

		// ��������
		Quaternion& operator*= (const Quaternion& rhs);

		const Quaternion operator- () const;

		Quaternion& operator+= (const Quaternion& rhs);
		Quaternion& operator-= (const Quaternion& rhs);
		Quaternion& operator*= (Real scalar);
		Quaternion& operator/= (Real scalar);

		// ��Ԫ����������ᡪ����֮���ת����
		void FromRotationMatrix(const Matrix3& matrix);
		const Matrix3 ToRotationMatrix() const;
		void FromRotationColumnVector3D(const std::vector<Vector3D>& rotationColumn);
		const std::vector<Vector3D>	ToRotationColumnVector3D() const;
		void FromAxisAngle(const Vector3D& axis, Real angle);
		const Vector3D ToAxis() const;
		Real ToAngle() const;
		const Matrix3Extract ToAngleAxis() const;

		Real Length() const;  // 4-tuple�ĳ���
		Real SquaredLength() const;  // 4-tuple�ĳ��ȵ�ƽ��
		void Normalize(Real epsilon = Math::sm_ZeroTolerance);
		const Quaternion Inverse() const;  // �����ڷ�����Ԫ��
		const Quaternion Conjugate() const;  // ȡ������ x, y, �� z ��
		const Quaternion Exp() const;  // ��������Ԫ�� w = 0
		const Quaternion Log() const;  // �����ڵ�λ������Ԫ��
		bool IsNormalize(Real epsilon = Math::sm_ZeroTolerance) const;

		// ����Ԫ����ת������
		const Vector3D Rotate(const Vector3D& vector) const;

		// �������Բ�ֵ
		void Slerp(Real t, const Quaternion& firstQuaternion, const Quaternion& secondQuaternion);
		void SlerpExtraSpins(Real t, const Quaternion& firstQuaternion, const Quaternion& secondQuaternion, int extraSpins);

		// �м�����������β�ֵ 
		void Intermediate(const Quaternion& firstQuaternion, const Quaternion& secondQuaternion, const Quaternion& thirdQuaternion);

		// ������β�ֵ��
		void Squad(Real t, const Quaternion& q0, const Quaternion& a0, const Quaternion& a1, const Quaternion& q1);

		// ������ת��λ����ʸ��firstVector����λ����ʸ��secondVector����Ԫ����
		// ��ת��Χ�ƴ�ֱ��firstVector��secondVector���ᣬ
		// �Ƕ���firstVector��secondVector֮��ĽǶȡ�
		// ���firstVector��secondVector��ƽ�еģ���ת�����ᶼ�У�
		// �������(z2,x2,y2)�����У�secondVector = (x2,y2,z2)��
		void Align(const Vector3D& firstVector, const Vector3D& secondVector, Real epsilon = Math::sm_ZeroTolerance);

		// �ֽ���Ԫ��Ϊq = q_twist * q_swing������q��'this'��Ԫ����
		// ���V1���������V2ΪV1ͨ��q����ת��
		// q_swing��ʾ��Լ��ֱ��V1��V2��������ת����Quaternion::Align����
		// ��q_twist�Ǵ�Լ��V1��ת��
		// ����ֵ�ĵ�һ����Ϊtwist���ڶ�����Ϊswing��
		const QuaternionSwingTwist DecomposeTwistTimesSwing(const Vector3D& vector, Real epsilon = Math::sm_ZeroTolerance) const;

		// �ֽ���Ԫ��Ϊq = q_swing * q_twist������q��'this'��Ԫ����
		// ���V1���������V2ΪV1ͨ��q����ת��
		// q_swing��ʾ��Լ��ֱ��V1��V2��������ת����Quaternion::Align����
		// ��q_twist�Ǵ�Լ��V1��ת��
		// ����ֵ�ĵ�һ����Ϊswing���ڶ�����Ϊtwist��

		const QuaternionSwingTwist DecomposeSwingTimesTwist(const Vector3D& vector, Real epsilon = Math::sm_ZeroTolerance) const;

		// *** ���������Լ���ĽǶȵ���Ԫ����

		// �����������Ԫ����ʽ(cx + sx*i)��
		const Quaternion GetClosestX() const;

		// �����������Ԫ����ʽ (cy + sy*j).
		const Quaternion GetClosestY() const;

		// �����������Ԫ����ʽ (cz + sz*k).
		const Quaternion GetClosestZ() const;

		// �����������Ԫ����ʽ (cx + sx*i) * (cy + sy*j).
		const Quaternion GetClosestXY() const;

		// �����������Ԫ����ʽ (cy + sy*j) * (cx + sx*i).
		const Quaternion GetClosestYX() const;

		// �����������Ԫ����ʽ (cz + sz*k) * (cx + sx*i).
		const Quaternion GetClosestZX() const;

		// �����������Ԫ����ʽ (cx + sx*i) * (cz + sz*k).
		const Quaternion GetClosestXZ() const;

		// �����������Ԫ����ʽ (cy + sy*j) * (cz + sz*k).
		const Quaternion GetClosestYZ() const;

		// �����������Ԫ����ʽ (cz + sz*k) * (cy + sy*j).
		const Quaternion GetClosestZY() const;

		// ϵ��Ϊ (cx + sx*i) * (cy + sy*j) * (cz + sz*k).
		const QuaternionFactor FactorXYZ() const;

		// ϵ��Ϊ  (cx + sx*i) * (cz + sz*k) * (cy + sy*j).
		const QuaternionFactor FactorXZY() const;

		// ϵ��Ϊ  (cy + sy*j) * (cz + sz*k) * (cx + sx*i).
		const QuaternionFactor FactorYZX() const;

		// ϵ��Ϊ  (cy + sy*j) * (cx + sx*i) * (cz + sz*k).
		const QuaternionFactor FactorYXZ() const;

		// ϵ��Ϊ (cz + sz*k) * (cx + sx*i) * (cy + sy*j).
		const QuaternionFactor FactorZXY() const;

		// ϵ��Ϊ  (cz + sz*k) * (cy + sy*j) * (cx + sx*i).
		const QuaternionFactor FactorZYX() const;

		// ���������Լ����Ԫ����ʽΪ (cx + sx*i).
		const Quaternion GetClosestX(const QuaternionConstraints& xCon) const;

		// ���������Լ����Ԫ����ʽΪ (cy + sy*j).
		const Quaternion GetClosestY(const QuaternionConstraints& yCon) const;

		// ���������Լ����Ԫ����ʽΪ (cz + sz*k).
		const Quaternion GetClosestZ(const QuaternionConstraints& zCon) const;

		// ���������Լ����Ԫ����ʽΪ (cx + sx*i)*(cy + sy*j).
		const Quaternion GetClosestXY(const QuaternionConstraints& xCon, const QuaternionConstraints& yCon) const;

		// ���������Լ����Ԫ����ʽΪ  (cy + sy*j)*(cx + sx*i).
		const Quaternion GetClosestYX(const QuaternionConstraints& yCon, const QuaternionConstraints& xCon) const;

		// ���������Լ����Ԫ����ʽΪ  (cz + sz*k)*(cx + sx*i).
		const Quaternion GetClosestZX(const QuaternionConstraints& zCon, const QuaternionConstraints& xCon) const;

		// ���������Լ����Ԫ����ʽΪ  (cx + sx*i)*(cz + sz*k).
		const Quaternion GetClosestXZ(const QuaternionConstraints& xCon, const QuaternionConstraints& zCon) const;

		// ���������Լ����Ԫ����ʽΪ  (cz + sz*k)*(cy + sy*j).
		const Quaternion GetClosestZY(const QuaternionConstraints& zCon, const QuaternionConstraints& yCon) const;

		// ���������Լ����Ԫ����ʽΪ  (cy + sy*j)*(cz + sz*k).
		const Quaternion GetClosestYZ(const QuaternionConstraints& yCon, const QuaternionConstraints& zCon) const;

		// ������Ԫ��
		static const Quaternion sm_Zero;
		static const Quaternion sm_Identity;

	private:
		// ���������Ԫ��Լ������ʽ��
		//   (cx + sx*i) �� QuaternionClosestAxis = QuaternionClosestAxis::X,
		//   (cy + sy*j) �� QuaternionClosestAxis = QuaternionClosestAxis::Y,
		//   (cz + sz*k) �� QuaternionClosestAxis = QuaternionClosestAxis::Z,
		const Quaternion GetClosest(QuaternionClosestAxis axis) const;

		// ���������Ԫ��Լ������ʽ��
		//   (cx + sx*i) �� QuaternionClosestAxis = QuaternionClosestAxis::X,
		//   (cy + sy*j) �� QuaternionClosestAxis = QuaternionClosestAxis::Y,
		//   (cz + sz*k) �� QuaternionClosestAxis = QuaternionClosestAxis::Z,
		const Quaternion GetClosest(QuaternionClosestAxis axis, const QuaternionConstraints& con) const;

	private:
		// �洢��˳����(w,x,y,z)��
		Real m_Tuple[4];
	};

	// �Ƚ� (��ʹ���� STL ����).
	template <typename Real>
	bool operator== (const Quaternion<Real>& lhs, const Quaternion<Real>& rhs);

	template <typename Real>
	bool operator<  (const Quaternion<Real>& lhs, const Quaternion<Real>& rhs);

	template <typename Real>
	const Quaternion<Real> operator* (const Quaternion<Real>& lhs, const Quaternion<Real>& rhs);

	template <typename Real>
	Real Dot(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs);  // 4Ԫ��ĵ��

	template <typename Real>
	bool Approximate(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs, const Real epsilon);

	template <typename Real>
	bool Approximate(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs);

	// ���������
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Quaternion<Real>& quaternion);

	using Quaternionf = Quaternion<float>;
	using Quaterniond = Quaternion<double>;
}

#endif // MATHEMATICS_ALGEBRA_QUATERNION_H
