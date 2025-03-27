/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_CALCULATE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_CALCULATE_H

#include "Mathematics/MathematicsDll.h"

#include "BrentsMethodRoot.h"
#include "NumericalAnalysisFwd.h"
#include "Mathematics/Base/MathDetail.h"

#include <boost/noncopyable.hpp>

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class BrentsMethodCalculate final : boost::noncopyable
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BrentsMethodCalculate<Real, UserDataType>;

        using BrentsMethod = BrentsMethod<Real, UserDataType>;
        using BrentsMethodRoot = BrentsMethodRoot<Real>;
        using MathType = Math<Real>;

    public:
        BrentsMethodCalculate(const BrentsMethod& brentsMethod, Real begin, Real end);

        CLASS_INVARIANT_DECLARE;

        NODISCARD BrentsMethodRoot GetRoot() noexcept;

    private:
        void Calculate();
        NODISCARD bool IsBeginSatisfyConditions() const noexcept;
        NODISCARD bool IsEndSatisfyConditions() const noexcept;
        void Search();
        void SwapBeginEnd() noexcept;
        void InitSearchValue() noexcept;
        NODISCARD bool RootSearch();
        NODISCARD bool IsConvXTolerance() const noexcept;
        void UpdateFunctionDifference() noexcept;
        void InverseQuadratic() noexcept;
        void InverseLinear() noexcept;
        void AcceptOrRejectTests() noexcept;
        NODISCARD bool IsSolutionSatisfyConditions() const noexcept;
        void UpdateSubinterval() noexcept;

    private:
        const BrentsMethod& brentsMethod;
        Real begin;
        Real end;
        Real beginFunction;
        Real endFunction;

        BrentsMethodRoot bisect2Root;

        // 根搜索的值。
        Real searchBegin;
        Real searchEnd;
        Real searchFunction;
        bool previousBisected;

        Real beginEndFunctionDifference;
        Real beginSearchFunctionDifference;
        Real endSearchFunctionDifference;

        Real solution;
        Real solutionFunction;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_CALCULATE_H
