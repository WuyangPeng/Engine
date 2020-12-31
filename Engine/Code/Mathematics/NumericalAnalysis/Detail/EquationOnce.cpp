///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 14:08)

#include "Mathematics/MathematicsExport.h"

#include "EquationOnce.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

Mathematics::EquationOnce::EquationOnce(double constant, double once, double epsilon)
    : ParentType{ epsilon }, m_Constant{ constant }, m_Once{ once }
{
    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EquationOnce)

double Mathematics::EquationOnce::Substitution(double value) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Constant + value * m_Once;
}

const Mathematics::EquationOnce::Imaginary Mathematics::EquationOnce::Substitution(const Imaginary& value) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Constant + value * m_Once;
}

double Mathematics::EquationOnce::SubstitutionTangent([[maybe_unused]] double solution) const noexcept
{
    return m_Once;
}

const Mathematics::EquationOnce::Imaginary Mathematics::EquationOnce::SubstitutionTangent([[maybe_unused]] const Imaginary& solution) const
{
    return m_Once;
}

void Mathematics::EquationOnce::Solving()
{
    MATHEMATICS_ASSERTION_0(GetEpsilon() < DoubleMath::FAbs(m_Once), "除零错误！");

    const auto solution = -m_Constant / m_Once;

    SetRealResult(solution);
}

bool Mathematics::EquationOnce::Predigest() noexcept
{
    return false;
}
