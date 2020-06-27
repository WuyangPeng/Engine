// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 12:30)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Objects3D/Plane3.h"

#include <vector>

namespace Mathematics
{
	// ��С���˷���ϵ�ƽ��(x,y,z) �����ݣ�ͨ��ʹ�þ�������������ƽ�档
	template <typename Real>
	class OrthogonalPlaneFit3
	{
	public:
		using ClassType = OrthogonalPlaneFit3<Real>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Math = Math<Real>;

	public:
		explicit OrthogonalPlaneFit3(const std::vector<Vector3D>& points);

		CLASS_INVARIANT_DECLARE;


		Plane3 GetPlane3() const;

	private:
		static Plane3 Calculate(const std::vector<Vector3D>& points);

	private:
		Plane3 m_Plane3;
	};

	using OrthogonalPlaneFit3d = OrthogonalPlaneFit3<double>;
	using OrthogonalPlaneFit3f = OrthogonalPlaneFit3<float>;
}

#endif // MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_H
