// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 10:04)

#ifndef MATHEMATICS_ALGEBRA_A_POINT_H
#define MATHEMATICS_ALGEBRA_A_POINT_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "HomogeneousPoint.h"
#include "Mathematics/Base/BaseFwd.h"

#include <type_traits>

namespace Mathematics
{
	template <typename T>
	class APoint
	{
	public:
		static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

		using ClassType = APoint<T>;
		using HomogeneousPoint = HomogeneousPoint<T>;
		using Math = Math<T>;
		using AlgebraTraits = AlgebraTraits<T>;
		using Vector3D = Vector3D<T>;
		using AVector = AVector<T>;

	public:
		// APoint表示仿射坐标 (x,y,z,1)。 默认 (0,0,0,1)
		APoint();
		APoint(T x, T y, T z);
		APoint(const Float3& tuple);
		APoint(const Vector3D& rhs);

		CLASS_INVARIANT_DECLARE;

		const Float3 GetFloat3() const;
		const Vector3D GetVector3D() const;
		const HomogeneousPoint GetHomogeneousPoint() const;

		const T& operator[] (int index) const;
		T& operator[] (int index);

		// 算术运算支持仿射代数。		

		// 一个点加或减一个向量的结果是一个点
		ClassType& operator+= (const AVector& rhs);
		ClassType& operator-= (const AVector& rhs);

		ClassType& operator+= (const ClassType& rhs);
		ClassType& operator-= (const ClassType& rhs);
		ClassType& operator*= (T scalar);
		ClassType& operator/= (T scalar);
		const APoint operator- () const;

		// 特殊向量
		static const APoint sm_Origin;  // (0,0,0,1)	

	private:
		HomogeneousPoint m_HomogeneousPoint;
	};

	// 两个点相减为一个向量
	template <typename T>
	const AVector<T> operator- (const APoint<T>& lhs, const APoint<T>& rhs);

	// 一个点增加或减小一个向量的结果是一个点
	template <typename T>
	const APoint<T> operator+ (const APoint<T>& lhs, const AVector<T>& rhs);
	template <typename T>
	const APoint<T> operator- (const APoint<T>& lhs, const AVector<T>& rhs);

	// 在仿射代数，点不能随意加减。然而，仿射和和仿射差是允许的。您有责任确保您在计算哪一个。

	// 一个仿射和是来自
	// r = s1 * p1 + s2 * p2 + ... + sn * pn
	// 这里p1到pn是齐次坐标的点（w值是1）和 s1到sn是标量，且s1 + s2 + ... + sn = 1，其结果r是齐次坐标点。

	// 一个仿射差是来自
	// r = d1 * p1 + d2 * p2 + ... + dn * pn
	// 这里p1到pn是齐次坐标的点（w值是1）和 d1到dn是标量，且d1 + d2 + ... + dn = 0，其结果r是齐次坐标点。

	// 注意：这个类的算法操作返回APoint对象，但仿射差需要返回一个HomogeneousPoint对象。
	// 下面的代码显示了如何实现这一点：  
	// APoint p1, p2, p3;  // 初始化为任何值
	// APoint difference = 1.5f * p1 + (-0.2f) * p2 + (-0.3f) * p3;
	// HomogeneousPoint r = difference.GetHomogeneousPoint();
	template <typename T>
	const APoint<T> operator+ (const APoint<T>& lhs, const APoint<T>& rhs);

	template <typename T>
	const APoint<T> operator* (const APoint<T>& lhs, T scalar);

	template <typename T>
	const APoint<T> operator/ (const APoint<T>& lhs, T scalar);

	template <typename T>
	const APoint<T> operator* (T scalar, const APoint<T>& rhs);

	// 在仿射代数是不允许计算一个点和一个向量的内积。 然而，当处理平面时，这是一个方便的定义。
	// 具体而言，平面是Dot(N,X-P) = 0，其中N是一个向量，P是平面上一个特定的点，且X是在平面上的任意点。 
	// 差X - P是一个向量，那么Dot(N,X - P)被很好地定义。如果平面被重写为Dot(N,X) = Dot(N,P)，这在仿射代数中是不支持的，
	// 无论无如，我们有时需要计算Dot(N,P)。在下文中，APoint的w分量被忽略，这意味着APoint被视为向量。
	template <typename T>
	T Dot(const APoint<T>& lhs, const AVector<T>& rhs);

	template <typename T>
	bool Approximate(const APoint<T>& lhs, const APoint<T>& rhs, const T epsilon);

	template <typename T>
	bool Approximate(const APoint<T>& lhs, const APoint<T>& rhs);

	// 调试输出
	template <typename T>
	std::ostream& operator<< (std::ostream& outFile, const APoint<T>& point);

	using APointf = APoint<float>;
	using APointd = APoint<double>;
}

#endif // MATHEMATICS_ALGEBRA_A_POINT_H

