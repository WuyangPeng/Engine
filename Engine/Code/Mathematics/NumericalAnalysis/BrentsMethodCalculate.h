///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/23 18:13)

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
        using Math = Math<Real>;

    public:
        BrentsMethodCalculate(const BrentsMethod& brentsMethod, Real begin, Real end);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const BrentsMethodRoot GetRoot() noexcept;

    private:
        void Calculate();
        [[nodiscard]] bool IsBeginSatisfyConditions() const noexcept;
        [[nodiscard]] bool IsEndSatisfyConditions() const noexcept;
        void Search();
        void SwapBeginEnd() noexcept;
        void InitSearchValue() noexcept;
        [[nodiscard]] bool RootSearch();
        [[nodiscard]] bool IsConvXTolerance() const noexcept;
        void UpdateFunctionDifference() noexcept;
        void InverseQuadratic() noexcept;
        void InverseLinear() noexcept;
        void AcceptOrRejectTests() noexcept;
        [[nodiscard]] bool IsSolutionSatisfyConditions() const noexcept;
        void UpdateSubinterval() noexcept;

    private:
        const BrentsMethod& m_BrentsMethod;
        Real m_Begin;
        Real m_End;
        Real m_BeginFunction;
        Real m_EndFunction;

        BrentsMethodRoot m_Bisect2Root;

        // 根搜索的值。
        Real m_SearchBegin;
        Real m_SearchEnd;
        Real m_SearchFunction;
        bool m_PreviousBisected;

        Real m_BeginEndFunctionDifference;
        Real m_BeginSearchFunctionDifference;
        Real m_EndSearchFunctionDifference;

        Real m_Solution;
        Real m_SolutionFunction;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_CALCULATE_H
