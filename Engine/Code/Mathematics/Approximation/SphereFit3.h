// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 11:22)

#ifndef MATHEMATICS_APPROXIMATION_SPHERE_FIT3_H
#define MATHEMATICS_APPROXIMATION_SPHERE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
	// 对一组点的最小二次拟合球。
	// 如果迭代的次数已超过maxIterations，触发一个断言。尝试增加迭代的最大数量。
	// 如果initialCenterIsAverage设置为“真”，
	// 对于球体中心的初始猜测是数据点的平均值。
	// 如果数据点沿一个立体角的群集，SphereFit3是收敛速度很慢。
	// 如果initialCenterIsAverage设置为“假”，
	// 球体中心的初始值猜测使用一个球面二次方程，
	// 表示一个球面的系数的最小二乘法来估算。
	// 这种做法往往会迅速收敛。 
	template <typename Real>
	class SphereFit3
    {
    public:
		using ClassType = SphereFit3<Real>;
        using Vector3D = Vector3D<Real>;
		using Sphere3 = Sphere3<Real>;
        
    public:
		SphereFit3(const std::vector<Vector3D>& points,int maxIterations,bool initialCenterIsAverage);

        CLASS_INVARIANT_DECLARE;
        
		const Sphere3 GetSphere() const;
        
    private:
        void Calculate(const std::vector<Vector3D>& points,int maxIterations,bool initialCenterIsAverage);
		const Vector3D GetAveragePoint(const std::vector<Vector3D>& points);
		void Iteration(const std::vector<Vector3D>& points, const Vector3D& average);

    private:
		Sphere3 m_Sphere;
    };

	using SphereFit3d = SphereFit3<double>;
	using SphereFit3f = SphereFit3<float>;
}

#endif // MATHEMATICS_APPROXIMATION_SPHERE_FIT3_H
