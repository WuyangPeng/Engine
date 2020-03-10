// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 10:37)

#ifndef MATHEMATICS_RATIONAL_INT64_VECTOR2_IMPL_H
#define MATHEMATICS_RATIONAL_INT64_VECTOR2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/ConfigMacro.h"
#include "Mathematics/Rational/Int64Vector.h"

namespace Mathematics
{
	class MATHEMATICS_HIDDEN_DECLARE Int64Vector2Impl
	{
	public:
		using ClassType = Int64Vector2Impl;

	public:
		Int64Vector2Impl ();		
		Int64Vector2Impl (const Int64Vector<2>& rhs);
		Int64Vector2Impl (const int64_t& x, const int64_t& y);

		Int64Vector2Impl& operator= (const Int64Vector<2>& rhs);

		CLASS_INVARIANT_DECLARE;

		int64_t GetX () const;
		void SetX (const int64_t& x);
		int64_t GetY () const;
		void SetY (const int64_t& y);		

		// ∑µªÿ (y,-x).
		const Int64Vector2Impl Perp () const;	

		const Int64Vector2Impl operator- () const;

		Int64Vector2Impl& operator+= (const Int64Vector2Impl& rhs);
		Int64Vector2Impl& operator-= (const Int64Vector2Impl& rhs);
		Int64Vector2Impl& operator*= (const int64_t& scalar);
		Int64Vector2Impl& operator/= (const int64_t& scalar);

		int64_t SquaredLength () const;		

	private:		
		Int64Vector<2> m_Tuple;
	};

	// ∑µªÿ Dot(lhs,rhs).
	int64_t Dot (const Int64Vector2Impl& lhs,const Int64Vector2Impl& rhs);

	// ∑µªÿ Cross((lhs.x,lhs.y,0),(rhs.x,rhs.y,0)) = lhs.x*rhs.y - lhs.y*rhs.x.
	int64_t DotPerp (const Int64Vector2Impl& lhs,const Int64Vector2Impl& rhs);

	bool operator== (const Int64Vector2Impl& lhs,const Int64Vector2Impl& rhs);

	bool operator<  (const Int64Vector2Impl& lhs,const Int64Vector2Impl& rhs);	
}

#endif // MATHEMATICS_RATIONAL_INT64_VECTOR2_IMPL_H
