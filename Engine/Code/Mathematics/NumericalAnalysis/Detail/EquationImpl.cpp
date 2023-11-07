///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 13:42)

#include "Mathematics/MathematicsExport.h"

#include "EquationImpl.h"
#include "EquationResult.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/EquationResultConstIteratorDetail.h"

Mathematics::EquationImpl::EquationImpl(double epsilon) noexcept
    : equationResult{}, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, EquationImpl)

double Mathematics::EquationImpl::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return epsilon;
}

bool Mathematics::EquationImpl::IsRealResult() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return equationResult.IsRealResult();
}

int Mathematics::EquationImpl::GetRealResultCount() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return equationResult.GetRealResultCount();
}

int Mathematics::EquationImpl::GetImaginaryResultCount() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return equationResult.GetImaginaryResultCount();
}

Mathematics::EquationImpl::RealConstIterator Mathematics::EquationImpl::GetRealBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return equationResult.GetRealBegin();
}

Mathematics::EquationImpl::RealConstIterator Mathematics::EquationImpl::GetRealEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return equationResult.GetRealEnd();
}

Mathematics::EquationImpl::ImaginaryConstIterator Mathematics::EquationImpl::GetImaginaryBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return equationResult.GetImaginaryBegin();
}

Mathematics::EquationImpl::ImaginaryConstIterator Mathematics::EquationImpl::GetImaginaryEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return equationResult.GetImaginaryEnd();
}

void Mathematics::EquationImpl::SetRealResult(double result)
{
    equationResult.AddRealResult(result, epsilon);
}

void Mathematics::EquationImpl::SetImaginaryResult(const Imaginary& result)
{
    equationResult.AddImaginaryResult(result, epsilon);
}

void Mathematics::EquationImpl::AddResult(const EquationImpl& equation, double offset)
{
    AddRealResult(equation, offset);
    AddImaginaryResult(equation, offset);
}

void Mathematics::EquationImpl::Calculate()
{
    if (!Predigest())
    {
        Solving();
        Validate();
    }
}

double Mathematics::EquationImpl::NewtonMethod(double solution) const
{
    // 没有使用无限循环，避免无法退出！
    for (auto i = 0; i < maxTime; ++i)
    {
        const auto validateValue = Substitution(solution);
        const auto derivative = SubstitutionTangent(solution);

        if (MathD::FAbs(derivative) <= epsilon)
        {
            break;
        }

        const auto adjustedValue = validateValue / derivative;

        solution -= adjustedValue;

        if (MathD::FAbs(validateValue) <= epsilon || MathD::FAbs(derivative) <= epsilon || MathD::FAbs(adjustedValue) <= epsilon)
        {
            break;
        }
    }

    return solution;
}

Mathematics::EquationImpl::Imaginary Mathematics::EquationImpl::NewtonMethod(Imaginary solution) const
{
    // 没有使用无限循环，避免无法退出！
    for (auto i = 0; i < maxTime; ++i)
    {
        const auto validateValue = Substitution(solution);
        const auto derivative = SubstitutionTangent(solution);
        const auto adjustedValue = validateValue / derivative;

        solution -= adjustedValue;

        if ((MathD::FAbs(validateValue.real()) <= epsilon && MathD::FAbs(validateValue.imag()) <= epsilon) ||
            (MathD::FAbs(derivative.real()) <= epsilon && MathD::FAbs(derivative.imag()) <= epsilon) ||
            (MathD::FAbs(adjustedValue.real()) <= epsilon && MathD::FAbs(adjustedValue.imag()) <= epsilon))
        {
            break;
        }
    }

    return solution;
}

Mathematics::EquationImpl::RealContainer Mathematics::EquationImpl::NewRealResult() const
{
    RealContainer newRealSolve{};

    for (auto iter = GetRealBegin(); iter != GetRealEnd(); ++iter)
    {
        auto solve = *iter;
        solve = NewtonMethod(solve);
        newRealSolve.push_back(solve);
    }

    return newRealSolve;
}

Mathematics::EquationImpl::ImaginaryContainer Mathematics::EquationImpl::NewImaginaryResult() const
{
    ImaginaryContainer newImaginarySolve{};

    for (auto iter = GetImaginaryBegin(); iter != GetImaginaryEnd(); ++iter)
    {
        auto solve = *iter;
        solve = NewtonMethod(solve);
        newImaginarySolve.emplace_back(solve);
    }

    return newImaginarySolve;
}

void Mathematics::EquationImpl::CleanSolution() noexcept
{
    equationResult.CleanSolution();
}

void Mathematics::EquationImpl::Validate()
{
    const auto newRealSolve = NewRealResult();
    const auto newImaginarySolve = NewImaginaryResult();

    CleanSolution();

    DisplaceRealResult(newRealSolve);
    DisplaceImaginaryResult(newImaginarySolve);
}

void Mathematics::EquationImpl::AddRealResult(const EquationImpl& equation, double offset)
{
    for (auto iter = equation.GetRealBegin(); iter != equation.GetRealEnd(); ++iter)
    {
        const auto result = *iter + offset;

        SetRealResult(result);
    }
}

void Mathematics::EquationImpl::AddImaginaryResult(const EquationImpl& equation, double offset)
{
    for (auto iter = equation.GetImaginaryBegin(); iter != equation.GetImaginaryEnd(); ++iter)
    {
        const auto result = *iter + offset;

        SetImaginaryResult(result);
    }
}

void Mathematics::EquationImpl::DisplaceRealResult(const RealContainer& result)
{
    for (const auto& value : result)
    {
        SetRealResult(value);
    }
}

void Mathematics::EquationImpl::DisplaceImaginaryResult(const ImaginaryContainer& result)
{
    for (const auto& value : result)
    {
        SetImaginaryResult(value);
    }
}

void Mathematics::EquationImpl::SortResult()
{
    equationResult.SortResult();
}