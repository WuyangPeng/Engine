///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 13:45)

#include "Mathematics/MathematicsExport.h"

#include "EquationResult.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/NumericalAnalysis/EquationResultConstIteratorDetail.h"

#include <algorithm>

Mathematics::EquationResult::EquationResult() noexcept
    : realResult{}, imaginaryResult{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, EquationResult)

bool Mathematics::EquationResult::IsRealResult() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return !realResult.empty();
}

int Mathematics::EquationResult::GetRealResultCount() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(realResult.size());
}

int Mathematics::EquationResult::GetImaginaryResultCount() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(imaginaryResult.size());
}

void Mathematics::EquationResult::AddRealResult(double solution, double epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (!FindSolution(solution, epsilon))
    {
        realResult.push_back(solution);
    }
}

void Mathematics::EquationResult::AddImaginaryResult(const Imaginary& solution, double epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (!FindSolution(solution, epsilon))
    {
        imaginaryResult.push_back(solution);
    }
}

void Mathematics::EquationResult::CleanSolution() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    realResult.clear();
    imaginaryResult.clear();
}

bool Mathematics::EquationResult::FindSolution(double solution, double epsilon) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (const auto& value : realResult)
    {
        if (MathD::FAbs(solution - value) <= epsilon)
        {
            return true;
        }
    }

    return false;
}

bool Mathematics::EquationResult::FindSolution(const Imaginary& solution, double epsilon) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (const auto& value : imaginaryResult)
    {
        if (!((0 < value.imag()) ^ (0 < solution.imag())))
        {
            if (MathD::FAbs(solution.real() - value.real()) <= epsilon &&
                MathD::FAbs(solution.imag() - value.imag()) <= epsilon)
            {
                return true;
            }
        }
    }

    return false;
}

Mathematics::EquationResult::RealConstIterator Mathematics::EquationResult::GetRealBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return RealConstIterator{ realResult.begin() };
}

Mathematics::EquationResult::RealConstIterator Mathematics::EquationResult::GetRealEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return RealConstIterator{ realResult.end() };
}

Mathematics::EquationResult::ImaginaryConstIterator Mathematics::EquationResult::GetImaginaryBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ImaginaryConstIterator{ imaginaryResult.begin() };
}

Mathematics::EquationResult::ImaginaryConstIterator Mathematics::EquationResult::GetImaginaryEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ImaginaryConstIterator{ imaginaryResult.end() };
}

void Mathematics::EquationResult::SortResult()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::ranges::sort(realResult);
    std::ranges::sort(imaginaryResult, ImaginaryLess{});
}

bool Mathematics::EquationResult::ImaginaryLess::operator()(const Imaginary& lhs, const Imaginary& rhs) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (lhs.real() < rhs.real())
        return true;
    else if (rhs.real() < lhs.real())
        return false;
    else
        return lhs.imag() < rhs.imag();
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, EquationResult::ImaginaryLess)
