// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 17:09)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"

namespace Mathematics
{
	template <typename Real>
	class DistancePoint2Ellipse2Tool
	{
	public:
		using ClassType = DistancePoint2Ellipse2Tool<Real>;
		using Vector2D = Vector2D<Real>;

	public:
		DistancePoint2Ellipse2Tool(Real firstExtent, Real secondExtent, const Vector2D& vector, Real zeroThreshold);

		CLASS_INVARIANT_DECLARE;

		Real GetSquaredDistance() const;
		const Vector2D GetOutputVector() const;

	private:
		// ��Բ��(x0 / e0)^2 + (x1 / e1)^2 = 1��e0 >= e1��
		// ��ѯ����(y0,y1)�� y0 >= 0 ��y1 >= 0
		// �������شӲ�ѯ�㵽��Բ��ƽ�����롣
		// ��Ҳ�����ڵ�һ������ӽ�(y0,y1)����Բ�� (x0,x1) ��
		void ComputeSquaredDistance();

		// ��Բ�� (x0 / e0)^2 + (x1 / e1)^2 = 1��
		// ��ѯ���� (y0,y1)��
		// �������شӲ�ѯ�㵽��Բ��ƽ�����롣
		// ��Ҳ������ӽ�(y0,y1)����Բ�� (x0,x1) ��
		void ComputeSquaredDistanceSpecial(const Vector2D& extent, const Vector2D& queryPoint);

	private:
		Vector2D m_Extent;
		Vector2D m_InputVector;
		Vector2D m_OutputVector;
		Real m_SquaredDistance;
		Real m_ZeroThreshold;
	};
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_H
