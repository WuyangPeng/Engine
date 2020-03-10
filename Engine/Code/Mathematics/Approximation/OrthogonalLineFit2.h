// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 11:13)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Line2.h"

#include <vector>

namespace Mathematics
{
	// 最小二次方拟合线到(x,y,z)的数据，通过使用距离测量正交建议的线。
	template <typename Real>
	class OrthogonalLineFit2
	{
	public:
		using ClassType = OrthogonalLineFit2<Real>;
		using Vector2D = Vector2D<Real>;
		using Line2 = Line2<Real>;

	public:
		explicit OrthogonalLineFit2(const std::vector<Vector2D>& points);

		CLASS_INVARIANT_DECLARE;

		Line2 GetLine2() const;

	private:
		static Line2 Calculate(const std::vector<Vector2D>& points);

	private:
		Line2 m_Line;
	};

	using OrthogonalLineFit2d = OrthogonalLineFit2<double>;
	using OrthogonalLineFit2f = OrthogonalLineFit2<float>;
}

#endif // MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_H
