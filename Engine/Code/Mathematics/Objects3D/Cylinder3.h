// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 09:05)

#ifndef MATHEMATICS_OBJECTS3D_CYLINDER3_H
#define MATHEMATICS_OBJECTS3D_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Line3.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Cylinder3
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Cylinder3<Real>;
		using Line3 = Line3<Real>;

	public:	
		// ����������һ���ߡ������ԭ�㱻ѡ��Ϊ��ԭ�㡣
		// ��������ھ�������Real��Ԫ�����޵ĸ��������޵ĸ߶ȡ�
		// һ�����޸������е�C���ߵ����;������޵ĸ߶�H
		// �߶�Ϊ����Բ����˵�C-(H/2)*D �� C+(H/2)*D������D���ߵĵ�λ���ȷ���
		Cylinder3 (const Line3& axis, Real radius, Real height);

		CLASS_INVARIANT_DECLARE;

		const Line3 GetAxis() const;
		Real GetRadius() const;
		Real GetHeight() const;
		
	private:
		Line3 m_Axis;
		Real m_Radius;
		Real m_Height;
	};

	using Cylinder3f = Cylinder3<float>;
	using Cylinder3d = Cylinder3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_CYLINDER3_H
