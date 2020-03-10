// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 11:11)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_VECTOR2_H
#define MATHEMATICS_RATIONAL_RATIONAL_VECTOR2_H

#include "Mathematics/MathematicsDll.h"

#include "RationalVector.h"

#include <boost/operators.hpp>
#include <iosfwd>

namespace Mathematics
{
    template <int IntSize>
    class RationalVector2 : private boost::additive<RationalVector2<IntSize>,
                                    boost::totally_ordered<RationalVector2<IntSize>,
                                    boost::multiplicative<RationalVector2<IntSize>,SignRational<IntSize>>>>
    {
    public:
        using ClassType = RationalVector2<IntSize>;
        using Rational = SignRational<IntSize>;
        
    public:
        RationalVector2 ();
      
        RationalVector2 (const RationalVector<2,IntSize>& rhs);
        RationalVector2 (const Rational& x, const Rational& y);
        
        RationalVector2& operator= (const RationalVector<2,IntSize>& rhs);
        
		CLASS_INVARIANT_DECLARE;
        
        const Rational GetX () const;
        void SetX (const Rational& x);
        const Rational GetY () const;
        void SetY (const Rational& y); 
        
        const RationalVector2 operator- () const;
        
		RationalVector2& operator+= (const RationalVector2& rhs);
		RationalVector2& operator-= (const RationalVector2& rhs);
		RationalVector2& operator*= (const Rational& rational);
		RationalVector2& operator/= (const Rational& rational);
        
        // ∑µªÿ (y,-x).
        const RationalVector2 Perp () const;
        
        const Rational SquaredLength () const;
        
    private:
        RationalVector<2,IntSize> m_Tuple;
    };

    // ∑µªÿ Dot(lhs,rhs).
    template <int IntSize>
    const SignRational<IntSize> Dot (const RationalVector2<IntSize>& lhs,const RationalVector2<IntSize>& rhs);
    
    // ∑µªÿ Cross((lhs.x,lhs.y,0),(rhs.x,rhs.y,0)) = lhs.x*rhs.y - lhs.y*rhs.x
    template <int IntSize>
    const SignRational<IntSize> DotPerp (const RationalVector2<IntSize>& lhs,const RationalVector2<IntSize>& rhs);
    
    template <int IntSize>
    bool operator== (const RationalVector2<IntSize>& lhs,const RationalVector2<IntSize>& rhs);
    
    template <int IntSize>
	bool operator<  (const RationalVector2<IntSize>& lhs,const RationalVector2<IntSize>& rhs);

	template <int IntSize>
	std::ostream& operator<< (std::ostream& os, const RationalVector2<IntSize>& rhs);
}

#endif // MATHEMATICS_RATIONAL_RATIONAL_VECTOR2_H
