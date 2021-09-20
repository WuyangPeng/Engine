///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/24 17:52)

#include "Mathematics/MathematicsExport.h"

#include "Equation.h"
#include "Detail/EquationFactory.h"
#include "Detail/EquationImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"

Mathematics::Equation::Equation(double constant, double once, double secondary, double thrice, double quartic, double epsilon)
    : impl{ CoreTools::ImplCreateUseFactory::Default, constant, once, secondary, thrice, quartic, epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, Equation)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Mathematics, Equation, IsRealResult, bool);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, Equation, Substitution, double, double);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Mathematics, Equation, Substitution, Imaginary, const Mathematics::Equation::Imaginary);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Equation, GetRealResultCount, int);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Equation, GetImaginaryResultCount, int);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Mathematics, Equation, GetRealBegin, const Mathematics::Equation::RealConstIterator);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Mathematics, Equation, GetRealEnd, const Mathematics::Equation::RealConstIterator);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Mathematics, Equation, GetImaginaryBegin, const Mathematics::Equation::ImaginaryConstIterator);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Mathematics, Equation, GetImaginaryEnd, const Mathematics::Equation::ImaginaryConstIterator);
