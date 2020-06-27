// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 12:29)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_H
#define MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
	// 最小二乘使用距离测量正交拟合了一个大圆到单位长度向量 (x,y,z) （并沿大圆测量）所建议的大圆。
	// 输入points[]是单位长度。返回的值是单位长度，把它叫做N。
	// 拟合的大圆定义为Dot(N,X) = 0，其中X是大圆一个单位长度矢量。
	template <typename Real>
	class GreatCircleFit3
	{
	public:
		using ClassType = GreatCircleFit3<Real>;
		using Vector3D = Vector3D<Real>;
		using Points = std::vector<Vector3D>;
		using Math = Math<Real>;

	public:
		explicit GreatCircleFit3(const Points& points);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetNormal();

	private:
		void Calculate(const Points& points);

	private:
		Vector3D m_Normal;
	};

	using GreatCircleFit3d = GreatCircleFit3<double>;
	using GreatCircleFit3f = GreatCircleFit3<float>;
}

#endif // MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_H
