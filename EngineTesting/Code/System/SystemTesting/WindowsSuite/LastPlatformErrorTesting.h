/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:19)

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