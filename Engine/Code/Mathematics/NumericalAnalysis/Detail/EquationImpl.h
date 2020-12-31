///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 13:58)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_IMPL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "EquationResult.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE EquationImpl
    {
    public:
        using ClassType = EquationImpl;
        using RealConstIterator = EquationResult::RealConstIterator;
        using ImaginaryConstIterator = EquationResult::ImaginaryConstIterator;
        using Imaginary = EquationResult::Imaginary;
        using ImaginaryVector = EquationResult::ImaginaryVector;
        using RealVector = EquationResult::RealVector;

    public:
        explicit EquationImpl(double epsilon = DoubleMath::GetZeroTolerance()) noexcept;
        virtual ~EquationImpl() noexcept = default;
        EquationImpl(const EquationImpl& rhs) = default;
        EquationImpl& operator=(const EquationImpl& rhs) = default;
        EquationImpl(EquationImpl&& rhs) noexcept = default;
        EquationImpl& operator=(EquationImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] double GetEpsilon() const noexcept;

        [[nodiscard]] bool IsRealResult() const noexcept;
        [[nodiscard]] int GetRealResultCount() const;
        [[nodiscard]] int GetImaginaryResultCount() const;

        [[nodiscard]] const RealConstIterator GetRealBegin() const noexcept;
        [[nodiscard]] const RealConstIterator GetRealEnd() const noexcept;
        [[nodiscard]] const ImaginaryConstIterator GetImaginaryBegin() const noexcept;
        [[nodiscard]] const ImaginaryConstIterator GetImaginaryEnd() const noexcept;

        [[nodiscard]] virtual double Substitution(double value) const = 0;
        [[nodiscard]] virtual const Imaginary Substitution(const Imaginary& value) const = 0;

    protected:
        void SetRealResult(double result);
        void SetImaginaryResult(const Imaginary& result);
        void AddResult(const EquationImpl& equation, double offset = 0.0);
        void Calculate();
        void SortResult();

    private:
        [[nodiscard]] double NewtonMethod(double solution) const;
        [[nodiscard]] const Imaginary NewtonMethod(const Imaginary& solution) const;
        [[nodiscard]] const RealVector NewRealResult() const;
        [[nodiscard]] const ImaginaryVector NewImaginaryResult() const;

        void CleanSolution() noexcept;
        void Validate();
        void AddRealResult(const EquationImpl& equation, double offset = 0.0);
        void AddImaginaryResult(const EquationImpl& equation, double offset = 0.0);
        void DisplaceRealResult(const RealVector& result);
        void DisplaceImaginaryResult(const ImaginaryVector& result);

        [[nodiscard]] virtual double SubstitutionTangent(double solution) const = 0;
        [[nodiscard]] virtual const Imaginary SubstitutionTangent(const Imaginary& solution) const = 0;

        virtual void Solving() = 0;
        [[nodiscard]] virtual bool Predigest() = 0;

    private:
        static constexpr auto sm_MaxTime = 10;

    private:
        EquationResult m_Result;
        double m_Epsilon;
    };
}

#endif  // MATH_TOOL_EQUATION_IMPL_H