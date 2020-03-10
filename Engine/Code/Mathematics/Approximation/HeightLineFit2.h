// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 11:12)

#ifndef MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_H
#define MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_H

#include "Mathematics/MathematicsDll.h"
 
#include "Mathematics/Objects2D/Line2.h"

#include <vector>

namespace Mathematics
{
	// ��С����ƽ����ϵ��ߵ�(x,f(x)) ͨ��ʹ����y�����ϵľ���������ݡ�
	// �ɴ˲��������� y = A * x + B.	
	template <typename Real>
	class HeightLineFit2
	{
	public:
		using ClassType = HeightLineFit2<Real>;
		using Vector2D = Vector2D<Real>;
		using Line2 = Line2<Real>;

	public:
		explicit HeightLineFit2(const std::vector<Vector2D>& points);
 
		CLASS_INVARIANT_DECLARE;

		// ����ڶ���A��B�ǣ��������������Է�����2x2��ϵ������
		// ����ֵ��false��
		// ����������£�����A��B���׳��쳣��
		bool IsFit2Success() const;

		Real GetCoeffA() const;
		Real GetCoeffB() const;

	private:
		void Calculate(const std::vector<Vector2D>& points);

	private:
		Real m_CoeffA;
		Real m_CoeffB;
		bool m_IsFit2Success;
	};

	using HeightLineFit2d = HeightLineFit2<double>;
	using HeightLineFit2f = HeightLineFit2<float>;
}

#endif // MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_H
