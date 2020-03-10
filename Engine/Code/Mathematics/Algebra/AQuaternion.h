// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/04 10:12)

#ifndef MATHEMATICS_ALGEBRA_AQUATERNION_H
#define MATHEMATICS_ALGEBRA_AQUATERNION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/Math.h"

#include <boost/operators.hpp>
#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AQuaternion: private boost::additive<AQuaternion<Real>,		                          	
		                                                            boost::multiplicative<AQuaternion<Real>,Real,
							                                        boost::totally_ordered<AQuaternion<Real>>>> 
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = AQuaternion<Real>;
		using Math = Math<Real>;
		using Matrix = Matrix<Real>;
		using AVector = AVector<Real>;
		using AlgebraTraits = AlgebraTraits<Real>;

	public:
		// 四元数q = w + x * i + y * j + z * k
		// 这里(w,x,y,z)不一定是单位长度的四维向量。

		AQuaternion ();  
		AQuaternion (Real w, Real x, Real y, Real z);
		AQuaternion (const AQuaternion& q);

		// 输入为旋转矩阵构造四元数
		AQuaternion (const Matrix& matrix);

		// 通过轴-角的旋转构造四元数
		AQuaternion (const AVector& axis, Real angle);

		AQuaternion& operator= (const AQuaternion& rhs);

		CLASS_INVARIANT_DECLARE;

		// 坐标访问类似于数组:  0 = w, 1 = x, 2 = y, 3 = z.
		const Real& operator[] (int index) const;
		Real& operator[] (int index);
		Real GetW () const;
		void SetW (Real w);
		Real GetX () const;
		void SetX (Real x);
		Real GetY () const;
		void SetY (Real y);
		Real GetZ () const;
		void SetZ (Real z);	

		// 算术运算
		AQuaternion& operator*= (const AQuaternion& rhs);

		const AQuaternion operator- () const;	

		AQuaternion& operator+= (const AQuaternion& rhs);
		AQuaternion& operator-= (const AQuaternion& rhs);
		AQuaternion& operator*= (Real scalar);
		AQuaternion& operator/= (Real scalar);		

		// 四元数，矩阵和轴——角之间的转换。
		void FromRotationMatrix (const Matrix& matrix);
		const Matrix ToRotationMatrix () const;
		void FromAxisAngle (const AVector& axis, Real angle);
		const AVector ToAxis() const;
		Real ToAngle() const;

		// 4-tuple的长度
		Real Length () const; 

		// 4-tuple的长度的平方
		Real SquaredLength () const;  

		void Normalize (Real epsilon = Math::sm_ZeroTolerance);

		// 适用于非零四元数
		const AQuaternion Inverse () const;  

		// 取负数在 x, y, 和 z 上
		const AQuaternion Conjugate () const;  

		// 适用于四元数 w = 0
		const AQuaternion Exp () const; 

		// 适用于单位长度四元数
		const AQuaternion Log () const; 

		bool IsNormalize (Real epsilon = Math::sm_ZeroTolerance) const;   	

		// 由四元数旋转向量。
		const AVector Rotate (const AVector& vector) const;

		// 球面线性插值
		void Slerp (Real t, const AQuaternion& firstQuaternion,const AQuaternion& secondQuaternion);

		// 中间条款球面二次插值 
		void Intermediate (const AQuaternion& firstQuaternion,const AQuaternion& secondQuaternion,const AQuaternion& thirdQuaternion);

		// 球面二次插值。
		void Squad (Real t, const AQuaternion& q0, const AQuaternion& a0,
			        const AQuaternion& a1, const AQuaternion& q1);
	
		// 特殊四元数
		static const AQuaternion sm_Zero;
		static const AQuaternion sm_Identity;

	private:
		// 存储的顺序是(w,x,y,z)。
		Real m_Tuple[4];	
	};

	// 比较 (仅使用在 STL 容器).
	template <typename Real>
	bool operator== (const AQuaternion<Real>& lhs,const AQuaternion<Real>& rhs);

	template <typename Real>
	bool operator<  (const AQuaternion<Real>& lhs,const AQuaternion<Real>& rhs);

	template <typename Real>
	const AQuaternion<Real> operator* (const AQuaternion<Real>& lhs,const AQuaternion<Real>& rhs);

	// 4元组的点积
	template <typename Real> 
	Real Dot (const AQuaternion<Real>& lhs,const AQuaternion<Real>& rhs); 

	template <typename Real>
	bool Approximate(const AQuaternion<Real>& lhs,const AQuaternion<Real>& rhs,const Real epsilon);

	template <typename Real>
	bool Approximate(const AQuaternion<Real>& lhs,const AQuaternion<Real>& rhs);

	// 调试输出
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const AQuaternion<Real>& quaternion);

    using AQuaternionf = AQuaternion<float>;
	using AQuaterniond = AQuaternion<double>;
}

#endif // MATHEMATICS_ALGEBRA_AQUATERNION_H
