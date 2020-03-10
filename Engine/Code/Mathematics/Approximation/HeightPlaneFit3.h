// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 11:12)

#ifndef MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H
#define MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
	// ��С����ƽ�����ϵ�(x,y,f(x,y))ͨ��ʹ����z�������������ݡ�
	// �ɴ˲�����ƽ����z = A*x + B*y + C��ʾ��
	template <typename Real>
	class HeightPlaneFit3
	{
	public:
		using ClassType = HeightPlaneFit3<Real>;
		using Vector3D = Vector3D<Real>;

	public:
		explicit HeightPlaneFit3(const std::vector<Vector3D>& points);

		CLASS_INVARIANT_DECLARE;
 
		// ���������ϵͳ�е�3��3ϵ������Ķ���A��B��C�ǣ��������������������£�
		// ����ֵ�ǡ��١���
		bool IsFit3Success() const;

		Real GetCoeffA() const;
		Real GetCoeffB() const;
		Real GetCoeffC() const;

	private:
		void Calculate(const std::vector<Vector3D>& points);

	private:
		Real m_CoeffA;
		Real m_CoeffB;
		Real m_CoeffC;
		bool m_IsFit3Success;
	};

	using HeightPlaneFit3d = HeightPlaneFit3<double>;
	using HeightPlaneFit3f = HeightPlaneFit3<float>;
}

#endif // MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_H
	 