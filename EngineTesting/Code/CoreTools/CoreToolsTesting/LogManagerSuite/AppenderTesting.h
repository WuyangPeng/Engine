/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 22:39)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_APPENDER_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_APPENDER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AppenderTesting final : public UnitTest
    {
    public:
        using ClassType = AppenderTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit AppenderTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ConsoleTest();
        void FileTest();
        void FileConfigurationTest();
        void SetLogLevelTest();

        /// File测试
        void FileLogTest();
        void FileContentTest();
        void BackupFileTest();
        void BackupFileContentTest();
        void DeleteFileTest();

        NODISCARD String GetBackupFileName() const;

    private:
        String appenderTestingName;
        String appenderTestingFullName;
        String backupFileName;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_APPENDER_TESTING_H
