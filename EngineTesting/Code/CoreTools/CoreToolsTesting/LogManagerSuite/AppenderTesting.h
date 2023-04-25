///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/12 14:14)

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
        void MainTest();

        void ConsoleTest();
        void FileTest();
        void FileConfigurationTest();
        void SetLogLevelTest();

        // File����
        void FileLogTest();
        void FileContentTest();
        void BackupFileTest();
        void BackupFileContentTest();
        void DeleteFileTest();
        NODISCARD String GetBackupFileName();

        void DoRunUnitTest() override;

    private:
        String appenderTestingName;
        String appenderTestingFullName;
        String backupFileName;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_APPENDER_TESTING_H
