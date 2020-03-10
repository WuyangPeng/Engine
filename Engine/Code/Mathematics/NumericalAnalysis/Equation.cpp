// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/09 11:30)

#include "Mathematics/MathematicsExport.h"

#include "Equation.h"
#include "Detail/EquationImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Detail/EquationFactory.h" 

Mathematics::Equation
	::Equation(double constant,double once,double secondary,
               double thrice,double quartic, double epsilon)
	:m_Impl{ EquationFactory::Create(constant,once, secondary,thrice, quartic, epsilon) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Mathematics, Equation)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Equation, IsRealResult,bool);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, Equation,Substitution,double,double);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Mathematics, Equation,Substitution, Imaginary,const Mathematics::Equation::Imaginary);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics,  Equation,GetRealResultCount,int);


IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Equation,GetImaginaryResultCount,int);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Equation,GetRealBegin,const Mathematics::Equation::RealConstIterator);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Equation,GetRealEnd,const Mathematics::Equation::RealConstIterator);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Equation,GetImaginaryBegin,const Mathematics::Equation::ImaginaryConstIterator);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Equation,GetImaginaryEnd,const Mathematics::Equation::ImaginaryConstIterator);
 
