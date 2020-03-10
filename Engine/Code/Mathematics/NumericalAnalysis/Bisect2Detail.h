// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/09 13:47)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_DETAIL_H

#include "CoreTools/Exception/Error.h"
#include "Bisect2.h"
#include "Math.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect2<Real>
	::Bisect2 (Function firstFunction,Function secondFunction,int maxLevel,Real tolerance)
	: m_FirstFunction{ firstFunction }, m_SecondFunction{ secondFunction }, m_MaxLevel{ maxLevel }, m_Tolerance{ tolerance }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect2<Real>
	::IsValid() const noexcept
{
	if (m_FirstFunction != nullptr && m_SecondFunction != nullptr && 0 < m_MaxLevel && Real{} <= m_Tolerance)
	{
        return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Bisect2<Real>::Bisect2Root Mathematics::Bisect2<Real>
	::Bisect(Real beginPointX, Real beginPointY,Real endPointX, Real endPointY) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
	Bisect2Calculate calculate{ *this,beginPointX,beginPointY,endPointX,endPointY };
    
    return calculate.GetRoot();
   
}
template <typename Real>
Real Mathematics::Bisect2<Real>
	::GetFirstFunctionValue(Real x,Real y) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
    return m_FirstFunction(x,y);
}

template <typename Real>
Real Mathematics::Bisect2<Real>
	::GetSecondFunctionValue(Real x,Real y) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
    return m_SecondFunction(x,y);
}

template <typename Real>
int Mathematics::Bisect2<Real>
	::GetMaxLevel() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
    return m_MaxLevel;
}

template <typename Real>
Real Mathematics::Bisect2<Real>
	::GetTolerance() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
    return m_Tolerance;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_DETAIL_H

