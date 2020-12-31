///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 14:11)

#include "Mathematics/MathematicsExport.h"

#include "EquationResult.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/NumericalAnalysis/EquationResultConstIteratorDetail.h"

#include <algorithm>

Mathematics::EquationResult::EquationResult() noexcept
    : m_RealResult{}, m_ImaginaryResult{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, EquationResult)
 
bool Mathematics::EquationResult::IsRealResult() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return !m_RealResult.empty();
}

int Mathematics::EquationResult::GetRealResultCount() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_RealResult.size());
}

int Mathematics::EquationResult::GetImaginaryResultCount() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_ImaginaryResult.size());
}

void Mathematics::EquationResult::AddRealResult(double solution, double epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (!FindSolution(solution, epsilon))
    {
        m_RealResult.push_back(solution);
    }
}

void Mathematics::EquationResult::AddImaginaryResult(const Imaginary& solution, double epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (!FindSolution(solution, epsilon))
    {
        m_ImaginaryResult.push_back(solution);
    }
}

void Mathematics::EquationResult::CleanSolution() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_RealResult.clear();
    m_ImaginaryResult.clear();
}

// private
bool Mathematics::EquationResult::FindSolution(double solution, double epsilon) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (const auto& value : m_RealResult)
    {
        if (DoubleMath::FAbs(solution - value) <= epsilon)
        {
            return true;
        }
    }

    return false;
}

// private
bool Mathematics::EquationResult::FindSolution(const Imaginary& solution, double epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (const auto& value : m_ImaginaryResult)
    {
        if (!((0 < value.imag()) ^ (0 < solution.imag())))
        {
            if (DoubleMath::FAbs(solution.real() - value.real()) <= epsilon &&
                DoubleMath::FAbs(solution.imag() - value.imag()) <= epsilon)
            {
                return true;
            }
        }
    }

    return false;
}

const Mathematics::EquationResult::RealConstIterator Mathematics::EquationResult::GetRealBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return RealConstIterator{ m_RealResult.begin() };
}

const Mathematics::EquationResult::RealConstIterator Mathematics::EquationResult::GetRealEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return RealConstIterator{ m_RealResult.end() };
}

const Mathematics::EquationResult::ImaginaryConstIterator Mathematics::EquationResult::GetImaginaryBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ImaginaryConstIterator{ m_ImaginaryResult.begin() };
}

const Mathematics::EquationResult::ImaginaryConstIterator Mathematics::EquationResult::GetImaginaryEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ImaginaryConstIterator{ m_ImaginaryResult.end() };
}

void Mathematics::EquationResult::SortResult()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    sort(m_RealResult.begin(), m_RealResult.end());
    sort(m_ImaginaryResult.begin(), m_ImaginaryResult.end(), ImaginaryLess{});
}

bool Mathematics::EquationResult::ImaginaryLess::operator()(const Imaginary& lhs, const Imaginary& rhs) const
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
