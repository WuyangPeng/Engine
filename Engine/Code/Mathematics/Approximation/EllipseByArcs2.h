// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 12:28)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Circle2.h"

namespace Mathematics
{
	// ��ԲΪ(x/a)^2 + (y/b)^2 = 1��
	// �����ڵ�һ�����еĲ���(x >= 0 and y >= 0)���ơ�
	// ����numArcs >= 2 �Ļ������Ӧ������������
	// ��Բ��(a,0) �� (0,b)�ļ�Ȩƽ��ֵ�С�
	// ���ص������������numArcs+1��Ԫ�غ�
	// ��������Բ�ĺͰ뾶ÿ��������numArcԪ�ء�
	// m_Points[i]��m_Points[i+1]������Ļ�
	// ��������m_Center[i]�Ͱ뾶��m_Radius[i]��

	template <typename Real>
	class EllipseByArcs2
	{
	public:
		using ClassType = EllipseByArcs2<Real>;
		using Vector2D = Vector2D<Real>;
		using Arc2 = Arc2<Real>;
		using Circle2 = Circle2<Real>;

	public:
		EllipseByArcs2(Real begin, Real end, size_t numArcs);

		CLASS_INVARIANT_DECLARE;

		const std::vector<Vector2D> GetPoints() const;
		const std::vector<Circle2> GetCircle2() const;

		const Arc2 GetArc2(int index) const;
		int getNumArcs() const;

	private:
		void Calculate(Real begin, Real end);

	private:
		std::vector<Vector2D> m_Points;
		std::vector<Circle2> m_Circle;
	};

	using EllipseByArcs2d = EllipseByArcs2<double>;
	using EllipseByArcs2f = EllipseByArcs2<float>;
}

#endif // MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_H
