// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:21)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSE3_H
#define MATHEMATICS_OBJECTS3D_ELLIPSE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Ellipse3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Ellipse3<Real>;
		using Math = Math<Real>;
		using Vector3D = Vector3D<Real>;	

	public:
		// 含椭圆的面是Dot(N,X-C) = 0 ，
		// 其中X是在平面上的任意点。
		// 向量U，V和N形成正交右手坐标系（矩阵 [U V N]是正交的，且行列式为1）。
		// 在平面内的椭圆为X = C + a*cos(t)*U + b*sin(t)*V，
		// 其中t为[0,2*pi)的角度和其中 a >= b > 0。
		// 在此讨论的符号均与类成员如下。
		// 成员'Center'为C，“Normal”是N，'Major'是U，'Minor'是V，
		// 'MajorLength“是a和”MinorLength'为b。
		Ellipse3(const Vector3D& center, const Vector3D& normal, const Vector3D& major, const Vector3D& minor,
				 Real majorLength, Real minorLength, const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetCenter() const;
		const Vector3D GetNormal() const;
		const Vector3D GetMajor() const;
		const Vector3D GetMinor() const;
		Real GetMajorLength() const;
		Real GetMinorLength() const;

	private:
		Vector3D m_Center;
		Vector3D m_Normal;
		Vector3D m_Major;
		Vector3D m_Minor;
		Real m_MajorLength;
		Real m_MinorLength;

		Real m_Epsilon;
	};

	using Ellipse3f = Ellipse3<float>;
	using Ellipse3d = Ellipse3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_ELLIPSE3_H
