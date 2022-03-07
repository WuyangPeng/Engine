///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/13 14:28)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_IMPL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "EquationResult.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/NumericalAnalysisInternalFwd.h"

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE EquationImpl
    {
    public:
        using ClassType = EquationImpl;
        using RealConstIterator = EquationResult::RealConstIterator;
        using ImaginaryConstIterator = EquationResult::ImaginaryConstIterator;
        using Imaginary = EquationResult::Imaginary;
        using ImaginaryContainer = EquationResult::ImaginaryContainer;
        using RealContainer = EquationResult::RealContainer;
        using FactoryType = EquationFactory;

    public:
        explicit EquationImpl(double epsilon = MathD::GetZeroTolerance()) noexcept;
        virtual ~EquationImpl() noexcept = default;
        EquationImpl(const EquationImpl& rhs) = default;
        EquationImpl& operator=(const EquationImpl& rhs) = default;
        EquationImpl(EquationImpl&& rhs) noexcept = default;
        EquationImpl& operator=(EquationImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD double GetEpsilon() const noexcept;

        NODISCARD bool IsRealResult() const noexcept;
        NODISCARD int GetRealResultCount() const;
        NODISCARD int GetImaginaryResultCount() const;

        NODISCARD RealConstIterator GetRealBegin() const noexcept;
        NODISCARD RealConstIterator GetRealEnd() const noexcept;
        NODISCARD ImaginaryConstIterator GetImaginaryBegin() const noexcept;
        NODISCARD ImaginaryConstIterator GetImaginaryEnd() const noexcept;

        NODISCARD virtual double Substitution(double value) const = 0;
        NODISCARD virtual Imaginary Substitution(const Imaginary& value) const = 0;

    protected:
        void SetRealResult(double result);
        void SetImaginaryResult(const Imaginary& result);
        void AddResult(const EquationImpl& equation, double offset = 0.0);
        void Calculate();
        void SortResult();

    private:
        NODISCARD double NewtonMethod(double solution) const;
        NODISCARD Imaginary NewtonMethod(Imaginary solution) const;
        NODISCARD RealContainer NewRealResult() const;
        NODISCARD ImaginaryContainer NewImaginaryResult() const;

        void CleanSolution() noexcept;
        void Validate();
        void AddRealResult(const EquationImpl& equation, double offset = 0.0);
        void AddImaginaryResult(const EquationImpl& equation, double offset = 0.0);
        void DisplaceRealResult(const RealContainer& result);
        void DisplaceImaginaryResult(const ImaginaryContainer& result);

        NODISCARD virtual double SubstitutionTangent(double solution) const = 0;
        NODISCARD virtual Imaginary SubstitutionTangent(const Imaginary& solution) const = 0;

        virtual void Solving() = 0;
        NODISCARD virtual bool Predigest() = 0;

    private:
        static constexpr auto maxTime = 10;

    private:
        EquationResult equationResult;
        double epsilon;
    };
}

#endif  // MATH_TOOL_EQUATION_IMPL_H