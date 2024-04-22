/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 22:40)

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
        void DoRunUnitTest() override;
        void MainTest();

        void WriteMessageTest() noexcept;
        void FileContentTest();
        void DeleteFileTest();
        void WriteMessageToFileTest() noexcept;

    private:
        String logHelperTestingName;
        String logHelperTestingFullName;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_LOG_HELPER_TESTING_H