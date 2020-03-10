// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 11:11)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_VECTOR3_H
#define MATHEMATICS_RATIONAL_RATIONAL_VECTOR3_H

#include "Mathematics/MathematicsDll.h"

#include "RationalVector.h"

#include <boost/operators.hpp>
#include <iosfwd>

namespace Mathematics
{
    template <int IntSize>
    class RationalVector3 : private boost::additive<RationalVector3<IntSize>,
                                    boost::totally_ordered<RationalVector3<IntSize>,
                                    boost::multiplicative<RationalVector3<IntSize>,SignRational<IntSize>>>>
    {
    public:
        using ClassType = RationalVector3<IntSize>;
        using Rational = SignRational<IntSize>;
        
    public:
        RationalVector3 ();
        
        RationalVector3 (const RationalVector<3,IntSize>& rhs);
        RationalVector3 (const Rational& x, const Rational& y,const Rational& z);
        
        RationalVector3& operator= (const RationalVector<3,IntSize>& rhs);
        
		CLASS_INVARIANT_DECLARE;
        
        const Rational GetX () const;
        void SetX (const Rational& x);
        const Rational GetY () const;
        void SetY (const Rational& y);
        const Rational GetZ () const;
        void SetZ (const Rational& z);
        
        const RationalVector3 operator- () const;
        
		RationalVector3& operator+= (const RationalVector3& rhs);
		RationalVector3& operator-= (const RationalVector3& rhs);
		RationalVector3& operator*= (const Rational& rational);
		RationalVector3& operator/= (const Rational& rational);
     
        const Rational SquaredLength () const;
        
    private:
        RationalVector<3,IntSize> m_Tuple;
    };
    
    // ∑µªÿ Dot(lhs,rhs).
    template <int IntSize>
    const SignRational<IntSize> Dot (const RationalVector3<IntSize>& lhs,const RationalVector3<IntSize>& rhs);
    
    // ∑µªÿ Cross(lhs,rhs).
    template <int IntSize>
    const RationalVector3<IntSize> Cross (const RationalVector3<IntSize>& lhs,const RationalVector3<IntSize>& rhs);
    
    // ∑µªÿ Dot(lhs,Cross(mhs,rhs)).
    template <int IntSize>
    const SignRational<IntSize> TripleScalar (const RationalVector3<IntSize>& lhs,const RationalVector3<IntSize>& mhs, const RationalVector3<IntSize>& rhs);
    
    template <int IntSize>
    bool operator== (const RationalVector3<IntSize>& lhs,const RationalVector3<IntSize>& rhs);
    
    template <int IntSize>
	bool operator<  (const RationalVector3<IntSize>& lhs,const RationalVector3<IntSize>& rhs);
    
	template <int IntSize>
	std::ostream& operator<< (std::ostream& os, const RationalVector3<IntSize>& rhs);
}

#endif // MATHEMATICS_RATIONAL_RATIONAL_VECTOR3_H



