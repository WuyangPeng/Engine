// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 10:04)

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
		// APoint��ʾ�������� (x,y,z,1)�� Ĭ�� (0,0,0,1)
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

		// ��������֧�ַ��������		

		// һ����ӻ��һ�������Ľ����һ����
		ClassType& operator+= (const AVector& rhs);
		ClassType& operator-= (const AVector& rhs);

		ClassType& operator+= (const ClassType& rhs);
		ClassType& operator-= (const ClassType& rhs);
		ClassType& operator*= (T scalar);
		ClassType& operator/= (T scalar);
		const APoint operator- () const;

		// ��������
		static const APoint sm_Origin;  // (0,0,0,1)	

	private:
		HomogeneousPoint m_HomogeneousPoint;
	};

	// ���������Ϊһ������
	template <typename T>
	const AVector<T> operator- (const APoint<T>& lhs, const APoint<T>& rhs);

	// һ�������ӻ��Сһ�������Ľ����һ����
	template <typename T>
	const APoint<T> operator+ (const APoint<T>& lhs, const AVector<T>& rhs);
	template <typename T>
	const APoint<T> operator- (const APoint<T>& lhs, const AVector<T>& rhs);

	// �ڷ���������㲻������Ӽ���Ȼ��������ͺͷ����������ġ���������ȷ�����ڼ�����һ����

	// һ�������������
	// r = s1 * p1 + s2 * p2 + ... + sn * pn
	// ����p1��pn���������ĵ㣨wֵ��1���� s1��sn�Ǳ�������s1 + s2 + ... + sn = 1������r���������㡣

	// һ�������������
	// r = d1 * p1 + d2 * p2 + ... + dn * pn
	// ����p1��pn���������ĵ㣨wֵ��1���� d1��dn�Ǳ�������d1 + d2 + ... + dn = 0������r���������㡣

	// ע�⣺�������㷨��������APoint���󣬵��������Ҫ����һ��HomogeneousPoint����
	// ����Ĵ�����ʾ�����ʵ����һ�㣺  
	// APoint p1, p2, p3;  // ��ʼ��Ϊ�κ�ֵ
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

	// �ڷ�������ǲ��������һ�����һ���������ڻ��� Ȼ����������ƽ��ʱ������һ������Ķ��塣
	// ������ԣ�ƽ����Dot(N,X-P) = 0������N��һ��������P��ƽ����һ���ض��ĵ㣬��X����ƽ���ϵ�����㡣 
	// ��X - P��һ����������ôDot(N,X - P)���ܺõض��塣���ƽ�汻��дΪDot(N,X) = Dot(N,P)�����ڷ���������ǲ�֧�ֵģ�
	// �������磬������ʱ��Ҫ����Dot(N,P)���������У�APoint��w���������ԣ�����ζ��APoint����Ϊ������
	template <typename T>
	T Dot(const APoint<T>& lhs, const AVector<T>& rhs);

	template <typename T>
	bool Approximate(const APoint<T>& lhs, const APoint<T>& rhs, const T epsilon);

	template <typename T>
	bool Approximate(const APoint<T>& lhs, const APoint<T>& rhs);

	// �������
	template <typename T>
	std::ostream& operator<< (std::ostream& outFile, const APoint<T>& point);

	using APointf = APoint<float>;
	using APointd = APoint<double>;
}

#endif // MATHEMATICS_ALGEBRA_A_POINT_H

