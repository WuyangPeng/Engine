///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 16:30)

#include "Mathematics/MathematicsExport.h"

#include "EquationImpl.h"
#include "EquationResult.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
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

// protected
void Mathematics::EquationImpl::SetRealResult(double result)
{
    equationResult.AddRealResult(result, epsilon);
}

// protected
void Mathematics::EquationImpl::SetImaginaryResult(const Imaginary& result)
{
    equationResult.AddImaginaryResult(result, epsilon);
}

// protected
void Mathematics::EquationImpl::AddResult(const EquationImpl& equation, double offset)
{
    AddRealResult(equation, offset);
    AddImaginaryResult(equation, offset);
}

// protected
void Mathematics::EquationImpl::Calculate()
{
    if (!Predigest())
    {
        Solving();
        Validate();
    }
}

// private
double Mathematics::EquationImpl::NewtonMethod(double solution) const
{
    // û��ʹ������ѭ���������޷��˳���
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

// private
Mathematics::EquationImpl::Imaginary Mathematics::EquationImpl::NewtonMethod(Imaginary solution) const
{
    // û��ʹ������ѭ���������޷��˳���
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

// private
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

// private
Mathematics::EquationImpl::ImaginaryContainer Mathematics::EquationImpl::NewImaginaryResult() const
{
    ImaginaryContainer newImaginarySolve{};

    for (auto iter = GetImaginaryBegin(); iter != GetImaginaryEnd(); ++iter)
    {
        auto solve = *iter;
        solve = NewtonMethod(solve);
        newImaginarySolve.push_back(solve);
    }

    return newImaginarySolve;
}

// private
void Mathematics::EquationImpl::CleanSolution() noexcept
{
    equationResult.CleanSolution();
}

// private
void Mathematics::EquationImpl::Validate()
{
    const auto newRealSolve = NewRealResult();
    const auto newImaginarySolve = NewImaginaryResult();

    CleanSolution();

    DisplaceRealResult(newRealSolve);
    DisplaceImaginaryResult(newImaginarySolve);
}

// private
void Mathematics::EquationImpl::AddRealResult(const EquationImpl& equation, double offset)
{
    for (auto iter = equation.GetRealBegin(); iter != equation.GetRealEnd(); ++iter)
    {
        const auto result = *iter + offset;

        SetRealResult(result);
    }
}

// private
void Mathematics::EquationImpl::AddImaginaryResult(const EquationImpl& equation, double offset)
{
    for (auto iter = equation.GetImaginaryBegin(); iter != equation.GetImaginaryEnd(); ++iter)
    {
        const auto result = *iter + offset;

        SetImaginaryResult(result);
    }
}

// private
void Mathematics::EquationImpl::DisplaceRealResult(const RealContainer& result)
{
    for (const auto& value : result)
    {
        SetRealResult(value);
    }
}

// private
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