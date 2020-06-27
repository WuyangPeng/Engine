// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 17:16)
#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
	template <typename Real>
	class DistancePoint3Ellipsoid3Tool
	{
	public:
		using ClassType = DistancePoint3Ellipsoid3Tool<Real> ;
		using Vector3D = Vector3D<Real>;

	public:
		DistancePoint3Ellipsoid3Tool(Real firstExtent, Real secondExtent, Real thirdExtent, const Vector3D& vector, Real zeroThreshold);

		CLASS_INVARIANT_DECLARE;

		Real GetSquaredDistance() const;
		const Vector3D GetOutputVector() const;

	private:
		// ��Բ��(x0 / e0)^2 + (x1 / e1)^2 + (x2 / e2)^2 = 1��e0 >= e1 >= e2��
		// ��ѯ����(y0,y1,y2)�� y0 >= 0 ,y1 >= 0��y2 >= 0
		// �������شӲ�ѯ�㵽��Բ��ƽ�����롣
		// ��Ҳ�����ڵ�һ������ӽ�(y0,y1,y2)����Բ��(x0,x1,x2) ��
		void ComputeSquaredDistance();

		// ��Բ�� (x0 / e0)^2 + (x1 / e1)^2 + (x2 / e2)^2 = 1��
		// ��ѯ���� (y0,y1,y2)��
		// �������شӲ�ѯ�㵽��Բ��ƽ�����롣
		// ��Ҳ������ӽ�(y0,y1,y2)����Բ�� (x0,x1,x2)  ��
		void ComputeSquaredDistanceSpecial(const Vector3D& extent, const Vector3D& queryPoint);

		// ��ƽ���㷨��Ѱ��F(t)��Ψһ����
		const std::vector<Real> Bisector(const std::vector<Real>& extent, const std::vector<Real>& queryPoint);

	private:
		Vector3D m_Extent;
		Vector3D m_InputVector;
		Vector3D m_OutputVector;
		Real m_SquaredDistance;
		Real m_ZeroThreshold;
	};
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_H
