///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:30) 

#ifndef CORE_TOOLS_CONTRACT_SUITE_CHECK_INVARIANT_TESTING_H
#define CORE_TOOLS_CONTRACT_SUITE_CHECK_INVARIANT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CheckInvariantTesting final : public UnitTest
    {
    public:
        using ClassType = CheckInvariantTesting;
        using ParentType = UnitTest;
        using TestingType = CheckInvariant<CheckInvariantTesting>;

    public:
        explicit CheckInvariantTesting(const OStreamShared& stream);

#ifdef OPEN_CLASS_INVARIANT

        CLASS_INVARIANT_OVERRIDE_DECLARE;

#else  // !OPEN_CLASS_INVARIANT

        NODISCARD bool IsValid() const noexcept;

#endif  // OPEN_CLASS_INVARIANT

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OnlyPreconditionsTest() noexcept;
        void OnlyPostconditionsTest() noexcept;
        void FullyTest() noexcept;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_CHECK_INVARIANT_TESTING_H