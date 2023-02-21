///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/12 15:58)

#ifndef CORE_TOOLS_HELPER_SUITE_LOG_FILE_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_LOG_FILE_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LogFileMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LogFileMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit LogFileMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FileLogTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_LOG_FILE_MACRO_TESTING_H