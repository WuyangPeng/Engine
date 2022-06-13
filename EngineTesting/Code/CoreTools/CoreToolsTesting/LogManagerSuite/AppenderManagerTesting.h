///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 10:47)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_MANAGER_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class AppenderManagerTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AppenderManagerTesting);

    private:
        void MainTest();
        void LoggerTest();
        void AppenderTest();
        void WriteMessageTest();

        // Logger����
        void LoggerSucceedTest();
        void InsertLoggerFailTest();
        void RemoveLoggerFailTest();

        // Appender����
        void AppenderSucceedTest();
        void InsertAppenderFailTest();
        void RemoveAppenderFailTest();

        // WriteMessage����
        void WriteMessageToFileTest();
        void FileContentTest();
        void DeleteFileTest();

        void DoRunUnitTest() override;

    private:
        System::String appenderManagerTestingName;
        System::String appenderManagerTestingFullName;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_MANAGER_TESTING_H
