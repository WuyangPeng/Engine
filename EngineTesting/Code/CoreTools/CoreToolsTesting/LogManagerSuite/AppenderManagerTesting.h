///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 10:47)

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

        // Logger测试
        void LoggerSucceedTest();
        void InsertLoggerFailTest();
        void RemoveLoggerFailTest();

        // Appender测试
        void AppenderSucceedTest();
        void InsertAppenderFailTest();
        void RemoveAppenderFailTest();

        // WriteMessage测试
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
