// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/06 10:58)

#ifndef MATHEMATICS_OBJECTS2D_CIRCLE2_H
#define MATHEMATICS_OBJECTS2D_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"

#include <type_traits> 
#include <iosfwd>

namespace Mathematics
{
	template <typename Real>
	class Circle2
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");
		
		using ClassType= Circle2<Real>;
		using Vector2D = Vector2D<Real>;

	public:	
		Circle2 (const Vector2D& center, Real radius);
		Circle2();

		CLASS_INVARIANT_DECLARE;

		const Vector2D GetCenter() const;
		Real GetRadius() const;

		void SetCircle(const Vector2D& center, Real radius);

	private:
		Vector2D m_Center;
		Real m_Radius;
	};

	template <typename Real>
	bool Approximate(const Circle2<Real>& lhs, const Circle2<Real>& rhs,const Real epsilon);

	// µ˜ ‘ ‰≥ˆ
	template <typename Real>
	std::ostream& operator<< (std::ostream& out, const Circle2<Real>& circle2);

	using Circle2f = Circle2<float>;
	using Circle2d = Circle2<double>;
}

#endif // MATHEMATICS_OBJECTS2D_CIRCLE2_H
