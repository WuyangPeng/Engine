///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:40)

#ifndef SYSTEM_WINDOWS_SUITE_LAST_PLATFORM_ERROR_TESTING_H
#define SYSTEM_WINDOWS_SUITE_LAST_PLATFORM_ERROR_TESTING_H

#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class LastPlatformErrorTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LastPlatformErrorTesting;
        using ParentType = UnitTest;

    public:
        explicit LastPlatformErrorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto defaultFlag = ErrorMode::Default;
        using ErrorModeContainer = std::vector<ErrorMode>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LastErrorTest();

        void LastErrorModeTest();

        void DoLastErrorTest(WindowError flag);
        void NoAlignmentFaultExceptTest();
        void DoLastErrorModeTest(ErrorMode mode);

    private:
        ErrorModeContainer errorModes;
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_LAST_PLATFORM_ERROR_TESTING_H