// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 10:14)

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
		// 四元数q = w + x * i + y * j + z * k
		// 这里(w,x,y,z)不一定是单位长度的四维向量。

		Quaternion();
		Quaternion(Real w, Real x, Real y, Real z);
		Quaternion(const Quaternion& rhs);

		// 输入为旋转矩阵构造四元数
		Quaternion(const Matrix3& matrix);

		// 通过轴-角的旋转构造四元数
		Quaternion(const Vector3D& axis, Real angle);

		// 通过指定的列旋转矩阵构造四元数。
		Quaternion(const std::vector<Vector3D>& rotationColumn);

		Quaternion& operator= (const Quaternion& rhs);

		CLASS_INVARIANT_DECLARE;

		// 坐标访问类似于数组:  0 = w, 1 = x, 2 = y, 3 = z.
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

		// 算术运算
		Quaternion& operator*= (const Quaternion& rhs);

		const Quaternion operator- () const;

		Quaternion& operator+= (const Quaternion& rhs);
		Quaternion& operator-= (const Quaternion& rhs);
		Quaternion& operator*= (Real scalar);
		Quaternion& operator/= (Real scalar);

		// 四元数，矩阵和轴——角之间的转换。
		void FromRotationMatrix(const Matrix3& matrix);
		const Matrix3 ToRotationMatrix() const;
		void FromRotationColumnVector3D(const std::vector<Vector3D>& rotationColumn);
		const std::vector<Vector3D>	ToRotationColumnVector3D() const;
		void FromAxisAngle(const Vector3D& axis, Real angle);
		const Vector3D ToAxis() const;
		Real ToAngle() const;
		const Matrix3Extract ToAngleAxis() const;

		Real Length() const;  // 4-tuple的长度
		Real SquaredLength() const;  // 4-tuple的长度的平方
		void Normalize(Real epsilon = Math::sm_ZeroTolerance);
		const Quaternion Inverse() const;  // 适用于非零四元数
		const Quaternion Conjugate() const;  // 取负数在 x, y, 和 z 上
		const Quaternion Exp() const;  // 适用于四元数 w = 0
		const Quaternion Log() const;  // 适用于单位长度四元数
		bool IsNormalize(Real epsilon = Math::sm_ZeroTolerance) const;

		// 由四元数旋转向量。
		const Vector3D Rotate(const Vector3D& vector) const;

		// 球面线性插值
		void Slerp(Real t, const Quaternion& firstQuaternion, const Quaternion& secondQuaternion);
		void SlerpExtraSpins(Real t, const Quaternion& firstQuaternion, const Quaternion& secondQuaternion, int extraSpins);

		// 中间条款球面二次插值 
		void Intermediate(const Quaternion& firstQuaternion, const Quaternion& secondQuaternion, const Quaternion& thirdQuaternion);

		// 球面二次插值。
		void Squad(Real t, const Quaternion& q0, const Quaternion& a0, const Quaternion& a1, const Quaternion& q1);

		// 计算旋转单位长度矢量firstVector到单位长度矢量secondVector的四元数。
		// 旋转是围绕垂直于firstVector和secondVector的轴，
		// 角度是firstVector和secondVector之间的角度。
		// 如果firstVector和secondVector是平行的，旋转任意轴都行，
		// 例如组合(z2,x2,y2)，其中，secondVector = (x2,y2,z2)。
		void Align(const Vector3D& firstVector, const Vector3D& secondVector, Real epsilon = Math::sm_ZeroTolerance);

		// 分解四元数为q = q_twist * q_swing，其中q是'this'四元数。
		// 如果V1是输入轴和V2为V1通过q的旋转，
		// q_swing表示大约垂直于V1和V2的轴线旋转（见Quaternion::Align），
		// 并q_twist是大约是V1旋转。
		// 返回值的第一部分为twist，第二部分为swing。
		const QuaternionSwingTwist DecomposeTwistTimesSwing(const Vector3D& vector, Real epsilon = Math::sm_ZeroTolerance) const;

		// 分解四元数为q = q_swing * q_twist，其中q是'this'四元数。
		// 如果V1是输入轴和V2为V1通过q的旋转，
		// q_swing表示大约垂直于V1和V2的轴线旋转（见Quaternion::Align），
		// 并q_twist是大约是V1旋转。
		// 返回值的第一部分为swing，第二部分为twist。

		const QuaternionSwingTwist DecomposeSwingTimesTwist(const Vector3D& vector, Real epsilon = Math::sm_ZeroTolerance) const;

		// *** 查找最近无约束的角度的四元数。

		// 距离最近的四元数形式(cx + sx*i)。
		const Quaternion GetClosestX() const;

		// 距离最近的四元数形式 (cy + sy*j).
		const Quaternion GetClosestY() const;

		// 距离最近的四元数形式 (cz + sz*k).
		const Quaternion GetClosestZ() const;

		// 距离最近的四元数形式 (cx + sx*i) * (cy + sy*j).
		const Quaternion GetClosestXY() const;

		// 距离最近的四元数形式 (cy + sy*j) * (cx + sx*i).
		const Quaternion GetClosestYX() const;

		// 距离最近的四元数形式 (cz + sz*k) * (cx + sx*i).
		const Quaternion GetClosestZX() const;

		// 距离最近的四元数形式 (cx + sx*i) * (cz + sz*k).
		const Quaternion GetClosestXZ() const;

		// 距离最近的四元数形式 (cy + sy*j) * (cz + sz*k).
		const Quaternion GetClosestYZ() const;

		// 距离最近的四元数形式 (cz + sz*k) * (cy + sy*j).
		const Quaternion GetClosestZY() const;

		// 系数为 (cx + sx*i) * (cy + sy*j) * (cz + sz*k).
		const QuaternionFactor FactorXYZ() const;

		// 系数为  (cx + sx*i) * (cz + sz*k) * (cy + sy*j).
		const QuaternionFactor FactorXZY() const;

		// 系数为  (cy + sy*j) * (cz + sz*k) * (cx + sx*i).
		const QuaternionFactor FactorYZX() const;

		// 系数为  (cy + sy*j) * (cx + sx*i) * (cz + sz*k).
		const QuaternionFactor FactorYXZ() const;

		// 系数为 (cz + sz*k) * (cx + sx*i) * (cy + sy*j).
		const QuaternionFactor FactorZXY() const;

		// 系数为  (cz + sz*k) * (cy + sy*j) * (cx + sx*i).
		const QuaternionFactor FactorZYX() const;

		// 距离最近的约束四元数形式为 (cx + sx*i).
		const Quaternion GetClosestX(const QuaternionConstraints& xCon) const;

		// 距离最近的约束四元数形式为 (cy + sy*j).
		const Quaternion GetClosestY(const QuaternionConstraints& yCon) const;

		// 距离最近的约束四元数形式为 (cz + sz*k).
		const Quaternion GetClosestZ(const QuaternionConstraints& zCon) const;

		// 距离最近的约束四元数形式为 (cx + sx*i)*(cy + sy*j).
		const Quaternion GetClosestXY(const QuaternionConstraints& xCon, const QuaternionConstraints& yCon) const;

		// 距离最近的约束四元数形式为  (cy + sy*j)*(cx + sx*i).
		const Quaternion GetClosestYX(const QuaternionConstraints& yCon, const QuaternionConstraints& xCon) const;

		// 距离最近的约束四元数形式为  (cz + sz*k)*(cx + sx*i).
		const Quaternion GetClosestZX(const QuaternionConstraints& zCon, const QuaternionConstraints& xCon) const;

		// 距离最近的约束四元数形式为  (cx + sx*i)*(cz + sz*k).
		const Quaternion GetClosestXZ(const QuaternionConstraints& xCon, const QuaternionConstraints& zCon) const;

		// 距离最近的约束四元数形式为  (cz + sz*k)*(cy + sy*j).
		const Quaternion GetClosestZY(const QuaternionConstraints& zCon, const QuaternionConstraints& yCon) const;

		// 距离最近的约束四元数形式为  (cy + sy*j)*(cz + sz*k).
		const Quaternion GetClosestYZ(const QuaternionConstraints& yCon, const QuaternionConstraints& zCon) const;

		// 特殊四元数
		static const Quaternion sm_Zero;
		static const Quaternion sm_Identity;

	private:
		// 距离最近四元数约束的形式：
		//   (cx + sx*i) 当 QuaternionClosestAxis = QuaternionClosestAxis::X,
		//   (cy + sy*j) 当 QuaternionClosestAxis = QuaternionClosestAxis::Y,
		//   (cz + sz*k) 当 QuaternionClosestAxis = QuaternionClosestAxis::Z,
		const Quaternion GetClosest(QuaternionClosestAxis axis) const;

		// 距离最近四元数约束的形式：
		//   (cx + sx*i) 当 QuaternionClosestAxis = QuaternionClosestAxis::X,
		//   (cy + sy*j) 当 QuaternionClosestAxis = QuaternionClosestAxis::Y,
		//   (cz + sz*k) 当 QuaternionClosestAxis = QuaternionClosestAxis::Z,
		const Quaternion GetClosest(QuaternionClosestAxis axis, const QuaternionConstraints& con) const;

	private:
		// 存储的顺序是(w,x,y,z)。
		Real m_Tuple[4];
	};

	// 比较 (仅使用在 STL 容器).
	template <typename Real>
	bool operator== (const Quaternion<Real>& lhs, const Quaternion<Real>& rhs);

	template <typename Real>
	bool operator<  (const Quaternion<Real>& lhs, const Quaternion<Real>& rhs);

	template <typename Real>
	const Quaternion<Real> operator* (const Quaternion<Real>& lhs, const Quaternion<Real>& rhs);

	template <typename Real>
	Real Dot(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs);  // 4元组的点积

	template <typename Real>
	bool Approximate(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs, const Real epsilon);

	template <typename Real>
	bool Approximate(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs);

	// 调试输出。
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Quaternion<Real>& quaternion);

	using Quaternionf = Quaternion<float>;
	using Quaterniond = Quaternion<double>;
}

#endif // MATHEMATICS_ALGEBRA_QUATERNION_H
