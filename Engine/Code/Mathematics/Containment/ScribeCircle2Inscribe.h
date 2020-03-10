// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/17 16:20)

#ifndef MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_INSCRIBE_H
#define MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_INSCRIBE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Circle2.h"

#include <vector>

namespace Mathematics
{
	// 圆内切三个2D点组成的三角形。
	template <typename Real>
	class ScribeCircle2Inscribe
	{
	public:
		typedef ScribeCircle2Inscribe<Real> ClassType;
		using Vector2D = Vector2D<Real>;
		typedef Circle2<Real> Circle2;

	public:
		ScribeCircle2Inscribe(const Vector2D& v0, const Vector2D& v1, const Vector2D& v2);
  
		CLASS_INVARIANT_DECLARE; 

		// 如果圆被构造，返回真，否则返回假，（输入点是线性相关的）
		bool IsCircleConstructed() const;	
		const Circle2 GetCircle2() const;

	private:
		void Calculate();

	private:
		std::vector<Vector2D> m_Points;
		Circle2 m_Circle2;
		bool m_IsCircleConstructed;     
	};

	using ScribeCircle2Inscribed = ScribeCircle2Inscribe<double>;
	using ScribeCircle2Inscribef = ScribeCircle2Inscribe<float>;
}

#endif // MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_INSCRIBE_H
