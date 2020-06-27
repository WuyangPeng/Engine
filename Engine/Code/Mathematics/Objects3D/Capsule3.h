// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 17:18)

#ifndef MATHEMATICS_OBJECTS3D_CAPSULE3_H
#define MATHEMATICS_OBJECTS3D_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Segment3.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Capsule3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Capsule3<Real>;
		using Segment3 = Segment3<Real>;

	public:
		// ��������һ����߶��еȾ�ĵ㣬 �������뱻��Ϊ�뾶��
		Capsule3(const Segment3& segment, Real radius);

		CLASS_INVARIANT_DECLARE;

		const Segment3 GetSegment() const;
		Real GetRadius() const;

	private:
		Segment3 m_Segment;
		Real m_Radius;
	};

	using Capsule3f = Capsule3<float>;
	using Capsule3d = Capsule3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_CAPSULE3_H
