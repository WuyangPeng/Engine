// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 11:10)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_VECTOR_H
#define MATHEMATICS_RATIONAL_RATIONAL_VECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "SignRational.h"

#include <boost/operators.hpp>
#include <iosfwd>

namespace Mathematics
{
	template <int VectorSize,int IntSize>
	class RationalVector : private boost::additive<RationalVector<VectorSize,IntSize>,		
		                    	   boost::totally_ordered<RationalVector<VectorSize,IntSize>,
								   boost::multiplicative<RationalVector<VectorSize,IntSize>,SignRational<IntSize>>>> 
	{
	public:		
		using ClassType = RationalVector<VectorSize,IntSize>;
		using Rational = SignRational<IntSize>;

	public:	
		RationalVector ();
		RationalVector (const RationalVector& rhs);

		RationalVector& operator= (const RationalVector& rhs);

		CLASS_INVARIANT_DECLARE;
	
		const Rational& operator[] (int index) const;
		Rational& operator[] (int index);	
		
		const RationalVector operator- () const;
		RationalVector& operator+= (const RationalVector& rhs);
		RationalVector& operator-= (const RationalVector& rhs);
		RationalVector& operator*= (const Rational& scalar);
		RationalVector& operator/= (const Rational& scalar);
	
		Rational SquaredLength () const;		

	private:	
		Rational m_Tuple[VectorSize];
	};

	template <int VectorSize,int IntSize>
	SignRational<IntSize> Dot (const RationalVector<VectorSize,IntSize>& lhs,const RationalVector<VectorSize,IntSize>& rhs);

	template <int VectorSize,int IntSize>
	bool operator== (const RationalVector<VectorSize,IntSize>& lhs,const RationalVector<VectorSize,IntSize>& rhs);

	template <int VectorSize,int IntSize>
	bool operator< (const RationalVector<VectorSize,IntSize>& lhs,const RationalVector<VectorSize,IntSize>& rhs);

	template <int VectorSize, int IntSize>
	std::ostream& operator<< (std::ostream& os, const RationalVector<VectorSize, IntSize>& rhs);
}

#endif // MATHEMATICS_RATIONAL_RATIONAL_VECTOR_H
