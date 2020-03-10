// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/07 11:56)

#ifndef MATHEMATICS_OBJECTS3D_CIRCLE3_H
#define MATHEMATICS_OBJECTS3D_CIRCLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/Vector3DTools.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Circle3
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Circle3<Real>;
		using Vector3D = Vector3D<Real>;
		using Math = Math<Real>;
		using Vector3DTools = Vector3DTools<Real>;

	public:
		// 含有该圆的平面是Dot(N,X-C) = 0，其中X是在平面上的任意点。
		// 向量U，V和N形成正交右手坐标系集合。
		// （矩阵[U V N]是正交的，具有行列式1）。
		// 在平面内的圆周参数为X = C + Real*(cos(t)*U + sin(t)*V)，
		// 其中t是在[-pi,pi)的角度。

		// U 是输入向量 'direction0', V 是输入向量 'direction1, 
		// 和 N 是输入向量 'normal'.
		Circle3 (const Vector3D& center, const Vector3D& direction0,const Vector3D& direction1,
				 const Vector3D& normal,const Real radius,const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;
		
		 const Vector3D GetCenter() const;
		 const Vector3D GetDirection0() const;
		 const Vector3D GetDirection1() const;
		 const Vector3D GetNormal() const;
		 Real GetRadius() const;

		 const ClassType GetMove(Real t, const Vector3D& velocity) const;

	private:
		Vector3D m_Center;
		Vector3D m_Direction0;
		Vector3D m_Direction1;
		Vector3D m_Normal;
		Real m_Radius;
		Real m_Epsilon;
	};

	using Circle3f = Circle3<float>;
	using Circle3d = Circle3<double>;

	template <typename Real>
	bool Approximate(const Circle3<Real>& lhs, const Circle3<Real>& rhs, const Real epsilon);

	// 调试输出
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Circle3<Real>& circle);
}

#endif // MATHEMATICS_OBJECTS3D_CIRCLE3_H
