// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:23)

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
		// 菱形是一组是等距的矩形的点，共同的距离称为半径。 
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
