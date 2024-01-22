/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:27)

#include "Mathematics/MathematicsExport.h"

#include "Equation.h"
#include "Detail/EquationFactory.h"
#include "Detail/EquationImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Mathematics::Equation::Equation(double constant, double once, double secondary, double thrice, double quartic, double epsilon)
    : impl{ CoreTools::ImplCreateUseFactory::Default, constant, once, secondary, thrice, quartic, epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, Equation)

bool Mathematics::Equation::IsRealResult() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->IsRealResult();
}

double Mathematics::Equation::Substitution(double value) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->Substitution(value);
}

Mathematics::Equation::Imaginary Mathematics::Equation::Substitution(const Imaginary& value) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->Substitution(value);
}

int Mathematics::Equation::GetRealResultCount() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetRealResultCount();
}

int Mathematics::Equation::GetImaginaryResultCount() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetImaginaryResultCount();
}

Mathematics::Equation::RealConstIterator Mathematics::Equation::GetRealBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetRealBegin();
}

Mathematics::Equation::RealConstIterator Mathematics::Equation::GetRealEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetRealEnd();
}

Mathematics::Equation::ImaginaryConstIterator Mathematics::Equation::GetImaginaryBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetImaginaryBegin();
}

Mathematics::Equation::ImaginaryConstIterator Mathematics::Equation::GetImaginaryEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetImaginaryEnd();
}
