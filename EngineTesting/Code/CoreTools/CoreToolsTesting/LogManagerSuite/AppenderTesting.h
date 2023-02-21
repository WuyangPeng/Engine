///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 10:50)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_APPENDER_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_APPENDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AppenderTesting : public UnitTest
    {
    public:
        using ClassType = AppenderTesting;
        using ParentType = UnitTest;

    public:
        explicit AppenderTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void ConsoleTest();
        void FileTest();
        void FileConfigurationTest();
        void SetLogLevelTest();

        // File测试
        void FileLogTest();
        void FileContentTest();
        void BackupFileTest();
        void BackupFileContentTest();
        void DeleteFileTest();
        NODISCARD System::String GetBackupFileName();

        void DoRunUnitTest() override;

    private:
        System::String appenderTestingName;
        System::String appenderTestingFullName;
        System::String backupFileName;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_APPENDER_TESTING_H
