///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 11:18)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_LOG_HELPER_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_LOG_HELPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LogHelperTesting final : public UnitTest
    {
    public:
        using ClassType = LogHelperTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit LogHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void WriteMessageTest() noexcept;
        void FileContentTest();
        void DeleteFileTest();
        void WriteMessageToFileTest() noexcept;

        void DoRunUnitTest() override;

    private:
        String logHelperTestingName;
        String logHelperTestingFullName;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_LOG_HELPER_TESTING_H