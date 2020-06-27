// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 12:29)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_H
#define MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
	// ������С���˵�һ����Բ����������ͶӰ��Բ��
	// ��С�ǵ�����(���ܵ�)��������㡣
	// ���Ķ˵�����α����ء����صĶ˵�A0��A1�Ǵ�ֱ�ڷ��صķ���N��
	// ����,����鿴��ͨ���۲�ƽ��Ĵ�Բ�� N����,Բ���Ǳ�����ʱ���A0��A1��
	template <typename Real>
	class GreatArcFit3
	{
	public:
		using ClassType = GreatArcFit3<Real>;
		using Vector3D = Vector3D<Real>;
		using Points = std::vector<Vector3D>;

	public:
		explicit GreatArcFit3(const Points& points);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetNormal() const;
		const Vector3D GetArcEnd0() const;
		const Vector3D GetArcEnd1() const;

	private:
		void Calculate(const Points& points);

	private:
		Vector3D m_Normal;
		Vector3D m_ArcEnd0;
		Vector3D m_ArcEnd1;
	};

	using GreatArcFit3d = GreatArcFit3<double>;
	using GreatArcFit3f = GreatArcFit3<float>;
}

#endif // MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_H
