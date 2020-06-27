// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 12:29)

#ifndef MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_H
#define MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"

#include <vector> 

namespace Mathematics
{
	// 高斯分布拟合点。该中心是点的平均值，轴是所述协方差矩阵的特征向量，
	// 而扩展是协方差矩阵的特征值和并以递增的顺序返回。
	// 数量存储在Box3<Real>仅仅有一个单一的容器中。
	template <typename Real>
	class GaussPointsFit3
	{
	public:
		using ClassType = GaussPointsFit3<Real>;
		using Vector3D = Vector3D<Real>;
		using Box3 = Box3<Real>;

	public:
		explicit GaussPointsFit3(const std::vector<Vector3D>& points);

		CLASS_INVARIANT_DECLARE;

		Box3 GetBox3() const;

	private:
		static Box3 Calculate(const std::vector<Vector3D>& points);

	private:
		Box3 m_Box;
	};

	using GaussPointsFit3d = GaussPointsFit3<double>;
	using GaussPointsFit3f = GaussPointsFit3<float>;
}

#endif // MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_H
