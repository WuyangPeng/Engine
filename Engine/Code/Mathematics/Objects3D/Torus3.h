// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 09:17)

#ifndef MATHEMATICS_OBJECTS3D_TORUS3_H
#define MATHEMATICS_OBJECTS3D_TORUS3_H

#include "Mathematics/MathematicsDll.h"

#include "Torus3Parameters.h"
#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "CoreTools/DataTypes/TupleDetail.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Torus3
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Torus3<Real>;
		using Vector3D = Vector3D<Real>;
		using Tuple2 = CoreTools::Tuple<2,Real>;
		using Math = Math<Real>;
		using Torus3Parameters = Torus3Parameters<Real>;

	public:	
		// 以z轴为对称轴，中心在（0,0,0）圆环的实现
		// （轴为圈形转动以产生环面）。
		//
		// 代数形式：
		//      Ro > 0 为半径的圆环（外径）的中心
		//      Ri > 0 为半径的圆环（内径）的中心
		//      p^2 = x^2 + y^2 + z^2
		//      p^4 - 2*(Ro^2 + Ri^2)*p^2 + 4*Ro^2*z^2 + (Ro^2 - Ri^2)^2 = 0
		//
		// 参数表：
		//      0 <= s <= 1, 0 <= t <= 1
		//      Rc = Ro + Ri*cos(2*PI*t)
		//      x = Rc*cos(2*PI*s)
		//      y = Rc*sin(2*PI*s)
		//      z = Ri*sin(2*PI*t)
		Torus3 (Real outerRadius, Real innerRadius);

		CLASS_INVARIANT_DECLARE;

		Real GetOuterRadius() const;
		Real GetInnerRadius() const;

		const Vector3D GetPosition (Real s, Real t) const;
		const Vector3D GetNormal (Real s, Real t) const;

		// 返回值第一部分为s，第二部分为t
		const Torus3Parameters GetParameters (const Vector3D& position) const;

	private:
		Real m_OuterRadius;
		Real m_InnerRadius;
	};

	using Torus3f = Torus3<float>;
	using Torus3d = Torus3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_TORUS3_H
