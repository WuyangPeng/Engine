// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 11:12)

#ifndef MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H
#define MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
	// 最小二乘平面的拟合到(x,y,f(x,y))通过使用在z方向距离测量数据。
	// 由此产生的平面由z = A*x + B*y + C表示。
	template <typename Real>
	class HeightPlaneFit3
	{
	public:
		using ClassType = HeightPlaneFit3<Real>;
		using Vector3D = Vector3D<Real>;

	public:
		explicit HeightPlaneFit3(const std::vector<Vector3D>& points);

		CLASS_INVARIANT_DECLARE;
 
		// 如果在线性系统中的3×3系数矩阵的定义A，B，C是（几乎）单数的这个情况下，
		// 返回值是“假”。
		bool IsFit3Success() const;

		Real GetCoeffA() const;
		Real GetCoeffB() const;
		Real GetCoeffC() const;

	private:
		void Calculate(const std::vector<Vector3D>& points);

	private:
		Real m_CoeffA;
		Real m_CoeffB;
		Real m_CoeffC;
		bool m_IsFit3Success;
	};

	using HeightPlaneFit3d = HeightPlaneFit3<double>;
	using HeightPlaneFit3f = HeightPlaneFit3<float>;
}

#endif // MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H
	 