// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 11:13)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"

#include <vector>

namespace Mathematics
{
	// 最小二次方拟合线到(x,y,z)的数据，通过使用距离测量正交建议的线。
	template <typename Real>
	class OrthogonalLineFit3
	{
	public:
		using ClassType = OrthogonalLineFit3<Real>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;

	public:
		explicit OrthogonalLineFit3(const std::vector<Vector3D>& points);

		CLASS_INVARIANT_DECLARE;

		Line3 GetLine3() const;

	private:
		static Line3 Calculate(const std::vector<Vector3D>& points);

	private:
		Line3 m_Line;
	};

	using OrthogonalLineFit3d = OrthogonalLineFit3<double>;
	using OrthogonalLineFit3f = OrthogonalLineFit3<float>;
}

#endif // MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_H
