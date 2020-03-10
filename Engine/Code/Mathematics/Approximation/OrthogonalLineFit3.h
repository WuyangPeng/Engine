// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 11:13)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"

#include <vector>

namespace Mathematics
{
	// ��С���η�����ߵ�(x,y,z)�����ݣ�ͨ��ʹ�þ����������������ߡ�
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
