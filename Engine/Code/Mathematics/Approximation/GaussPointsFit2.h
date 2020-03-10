// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 11:10)

#ifndef MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_H
#define MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Box2.h"

#include <vector> 

namespace Mathematics
{
	// 高斯分布拟合点。该中心是点的平均值，轴是所述协方差矩阵的特征向量，
	// 而扩展是协方差矩阵的特征值和并以递增的顺序返回。
	// 数量存储在Box2<Real>仅仅有一个单一的容器中。
	template <typename Real>
	class GaussPointsFit2
	{
	public:
		using ClassType = GaussPointsFit2<Real>;
		using Vector2D = Vector2D<Real>;
		using Box2 = Box2<Real>;

	public:
		explicit GaussPointsFit2(const std::vector<Vector2D>& points);

		CLASS_INVARIANT_DECLARE;

		Box2 GetBox2() const;

	private:
		static Box2 Calculate(const std::vector<Vector2D>& points);

	private:
		Box2 m_Box;
	};

	using GaussPointsFit2d = GaussPointsFit2<double>;
	using GaussPointsFit2f = GaussPointsFit2<float>;
}

#endif // MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_H
