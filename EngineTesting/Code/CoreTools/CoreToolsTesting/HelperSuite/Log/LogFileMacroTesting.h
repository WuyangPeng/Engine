///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/14 20:36)

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