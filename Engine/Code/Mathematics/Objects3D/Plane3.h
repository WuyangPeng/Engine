// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:23)

#ifndef MATHEMATICS_OBJECTS3D_PLANE3_H
#define MATHEMATICS_OBJECTS3D_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Objects3D/Triangle3.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Plane3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Plane3<Real>;
		using Vector3D = Vector3D<Real>;
		using Math = Math<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Triangle3 = Triangle3<Real>;

	public:
		// 平面表示为Dot(N,X) = c，
		// 其中N是一个单位长度的法线向量，
		// c是平面常数，且X是在平面上的任意点。
		// 用户必须保证法线的向量是单位长度

		Plane3();

		// 直接指定N和C。
		Plane3(const Vector3D& normal, Real constant, const Real epsilon = Math::GetZeroTolerance());

		// 指定N，c = Dot(N,P)，这里P是平面是的一点。
		Plane3(const Vector3D& normal, const Vector3D& point, const Real epsilon = Math::GetZeroTolerance());

		// N = Cross(P1-P0,P2-P0)/Length(Cross(P1-P0,P2-P0))，
		// c = Dot(N,P0)，其中P0，P1，P2是在平面上的点。
		Plane3(const Vector3D& firstPoint, const Vector3D& secondPoint, const Vector3D& thirdPoint, const Real epsilon = Math::GetZeroTolerance());

		explicit Plane3(const Triangle3& triangle, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetNormal() const;
		Real GetConstant() const;

		// 计算d = Dot(N,P)-c 其中N是平面法线和c是平面常量。
		// 这是一个符号距离。
		// 如果返回值的符号是正的，则该点是在平面上的正方向，
		// 如果是负的，则在平面负方向，
		// 如果为零，则点在平面上。
		Real DistanceTo(const Vector3D& point) const;

		// 平面的正面是法线点所在的半空间，背面是另一半空间。
		// 函数返回点在平面的哪一侧。
		NumericalValueSymbol WhichSide(const Vector3D& point) const;

	private:
		Vector3D m_Normal;
		Real m_Constant;

		Real m_Epsilon;
	};

	using Plane3f = Plane3<float>;
	using Plane3d = Plane3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_PLANE3_H
