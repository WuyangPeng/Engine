// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/09 11:14)

#include "Mathematics/MathematicsExport.h"

#include "EquationOnce.h"
#include "System/Helper/UnusedMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::EquationOnce
	::EquationOnce(double constant,double once, double epsilon)
	:ParentType{ epsilon }, m_Constant{ constant }, m_Once{ once }
{
	Calculate();
    
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::EquationOnce
  ::~EquationOnce()
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics,EquationOnce)

double Mathematics::EquationOnce
	::Substitution(double value) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Constant + value * m_Once;
}

const Mathematics::EquationOnce::Imaginary Mathematics::EquationOnce
	::Substitution(const Imaginary& value) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
	return m_Constant + value * m_Once;
}

double Mathematics::EquationOnce
	::SubstitutionTangent(double solution) const
{   
	SYSTEM_UNUSED_ARG(solution);

	return m_Once;
}

const Mathematics::EquationOnce::Imaginary Mathematics::EquationOnce
	::SubstitutionTangent(const Imaginary& solution) const
{  
	SYSTEM_UNUSED_ARG(solution);

	return m_Once;
}

void Mathematics::EquationOnce
	::Solving()
{    
    MATHEMATICS_ASSERTION_0(GetEpsilon() < Mathd::FAbs(m_Once),"≥˝¡„¥ÌŒÛ£°");
    
    double solution = -m_Constant / m_Once;

    SetRealResult(solution);
}

bool Mathematics::EquationOnce
   ::Predigest()
{    
	return false;
}



