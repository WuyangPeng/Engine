// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:18)

#ifndef MATHEMATICS_OBJECTS3D_CONE3_H
#define MATHEMATICS_OBJECTS3D_CONE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Cone3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Cone3<Real>;
		using Math = Math<Real>;
		using Vector3D = Vector3D<Real>;		

	public:
		// 锐角锥体是Dot(A,X-V) = |X-V| cos(t)
		// 其中V是顶点，A为圆锥的轴的单位长度方向，
		// 并且T是圆锥角在0 < t < pi/2。 
		// 圆锥内部的点定义为Dot(A,X-V) >= |X-V| cos(t)。
		// 由于cos(t) > 0，可避免计算平方根。 
		// 固体锥是由不等式定义为 Dot(A,X-V)^2 >= Dot(X-V,X-V) cos(t)^2。
		// 这是一个无限的，单面锥。
		//
		// 锥体可以由平面截断垂直于它在从顶点的高度h的轴
		// （从顶点至平面的交点与轴的距离）。
		// 无限锥体h = 无穷大。
		// 有限锥体有一个底盘上的平面和无限锥体之间交叉。
		// 底盘的半径r为r = h*tan(t)。

		// axis必须是单位长度和角度必须在(0,pi/2)。
		// 对于无限锥，设置“height”为Math<Real>::sm_MaxReal
		Cone3(const Vector3D& vertex, const Vector3D& axis, const Real angle,
			  const Real height, const Real epsilon = Math::sm_ZeroTolerance);

		// axis必须是单位长度。
		// 一对(cosAngle,sinAngle)必须严格在平面的第一象限，以保证锥角为(0,pi/2)
		// 对于无限锥，设置“height”为Math<Real>::sm_MaxReal
		Cone3(const Real cosAngle, const Real sinAngle, const Real height,
			  const Vector3D& vertex, const Vector3D& axis, const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetVertex() const;
		const Vector3D GetAxis() const;
		Real GetCosAngle() const;
		Real GetSinAngle() const;
		Real GetHeight() const;

	private:
		Vector3D m_Vertex;
		Vector3D m_Axis;
		Real m_CosAngle;
		Real m_SinAngle;
		Real m_Height;

		Real m_Epsilon;
	};

	using Cone3f = Cone3<float>;
	using Cone3d = Cone3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_CONE3_H
