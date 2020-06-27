// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 12:29)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_H
#define MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
	// ��С����ʹ�þ���������������һ����Բ����λ�������� (x,y,z) �����ش�Բ������������Ĵ�Բ��
	// ����points[]�ǵ�λ���ȡ����ص�ֵ�ǵ�λ���ȣ���������N��
	// ��ϵĴ�Բ����ΪDot(N,X) = 0������X�Ǵ�Բһ����λ����ʸ����
	template <typename Real>
	class GreatCircleFit3
	{
	public:
		using ClassType = GreatCircleFit3<Real>;
		using Vector3D = Vector3D<Real>;
		using Points = std::vector<Vector3D>;
		using Math = Math<Real>;

	public:
		explicit GreatCircleFit3(const Points& points);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetNormal();

	private:
		void Calculate(const Points& points);

	private:
		Vector3D m_Normal;
	};

	using GreatCircleFit3d = GreatCircleFit3<double>;
	using GreatCircleFit3f = GreatCircleFit3<float>;
}

#endif // MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_H
