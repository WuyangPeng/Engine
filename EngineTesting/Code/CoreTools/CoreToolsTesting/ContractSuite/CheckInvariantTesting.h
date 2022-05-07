///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/26 11:37)

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