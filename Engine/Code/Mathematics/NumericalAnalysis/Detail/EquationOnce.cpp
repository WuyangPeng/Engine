///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 13:45)

#include "Mathematics/MathematicsExport.h"

#include "EquationOnce.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

Mathematics::EquationOnce::EquationOnce(double constant, double once, double epsilon)
    : ParentType{ epsilon }, constant{ constant }, once{ once }
{
    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EquationOnce)

double Mathematics::EquationOnce::Substitution(double value) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return constant + value * once;
}

Mathematics::EquationOnce::Imaginary Mathematics::EquationOnce::Substitution(const Imaginary& value) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return constant + value * once;
}

double Mathematics::EquationOnce::SubstitutionTangent([[maybe_unused]] double solution) const noexcept
{
    return once;
}

Mathematics::EquationOnce::Imaginary Mathematics::EquationOnce::SubstitutionTangent([[maybe_unused]] const Imaginary& solution) const
{
    return once;
}

void Mathematics::EquationOnce::Solving()
{
    MATHEMATICS_ASSERTION_0(GetEpsilon() < MathD::FAbs(once), "�������");

    const auto solution = -constant / once;

    SetRealResult(solution);
}

bool Mathematics::EquationOnce::Predigest() noexcept
{
    return false;
}
