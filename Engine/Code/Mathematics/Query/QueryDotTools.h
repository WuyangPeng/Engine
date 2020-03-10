// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 09:44)

#ifndef MATHEMATICS_QUERY_QUERY_DOT_TOOLS_H
#define MATHEMATICS_QUERY_QUERY_DOT_TOOLS_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	template <typename Real>
    class QueryDotTools
    {
    public:
		using ClassType = QueryDotTools<Real>;

	public:
		CLASS_INVARIANT_DECLARE;
        
        // ∞Ô÷˙∫Ø ˝
       
        static Real Dot (Real x0, Real y0, Real x1, Real y1);    
        static Real Det2 (Real x0, Real y0,  Real x1, Real y1);  
        static Real Det3 (Real x0, Real y0, Real z0,Real x1, Real y1, Real z1,Real x2, Real y2, Real z2);

		static Real Dot(Real x0, Real y0, Real z0, Real x1, Real y1, Real z1);
		static Real Det4(Real x0, Real y0, Real z0, Real w0,Real x1, Real y1, Real z1, Real w1, 
						 Real x2, Real y2, Real z2, Real w2,Real x3, Real y3, Real z3, Real w3);
    };

	using QueryDotToolsf = QueryDotTools<float>;
	using QueryDotToolsd = QueryDotTools<double>;
}

#endif // MATHEMATICS_QUERY_QUERY_DOT_TOOLS_H
