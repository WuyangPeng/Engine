// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 11:13)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Line2.h"

#include <vector>

namespace Mathematics
{
	// ��С���η�����ߵ�(x,y,z)�����ݣ�ͨ��ʹ�þ����������������ߡ�
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
