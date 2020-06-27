// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 17:23)

#ifndef MATHEMATICS_OBJECTS3D_LOZENGE3_H
#define MATHEMATICS_OBJECTS3D_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Rectangle3.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Lozenge3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Lozenge3<Real>;
		using Rectangle3 = Rectangle3<Real>;

	public:
		// ������һ���ǵȾ�ľ��εĵ㣬��ͬ�ľ����Ϊ�뾶�� 
		Lozenge3(const Rectangle3& rectangle, Real radius);

		CLASS_INVARIANT_DECLARE;

		const Rectangle3 GetRectangle() const;
		Real GetRadius() const;

	private:
		Rectangle3 m_Rectangle;
		Real m_Radius;
	};

	using Lozenge3f = Lozenge3<float>;
	using Lozenge3d = Lozenge3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_LOZENGE3_H
