/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 22:38)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_MANAGER_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_MANAGER_TESTING_H

#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AppenderManagerTesting final : public UnitTest
    {
    public:
        using ClassType = AppenderManagerTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit AppenderManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using AppenderManagerSharedPtr = AppenderManager::AppenderManagerSharedPtr;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LoggerTest();
        void AppenderTest();
        void WriteMessageTest();
        void GetMinLogLevelTypeTest();
        void AppenderNameTest();

        /// Logger测试
        void LoggerSucceedTest();
        void InsertLoggerFailTest();
        void RemoveLoggerFailTest();

        void InsertLoggerSucceedTest(AppenderManager& manager);
        void RemoveLoggerSucceedTest(AppenderManager& manager);

        void WriteTraceMessageTest(const AppenderManager& manager) const;
        void WriteDebugMessageDoNothingTest(const AppenderManager& manager) const;
        void WriteInfoMessageTest(const AppenderManager& manager) const;
        void WriteWarnMessageDoNothingTest(const AppenderManager& manager) const;
        void WriteErrorMessageTest(const AppenderManager& manager) const;
        void WriteFatalMessageTest(const AppenderManager& manager) const;

        NODISCARD AppenderManagerSharedPtr InitTraceLogger(const Appender& appender);
        void InitInfoLogger(AppenderManager& manager);
        void InitFileAppender(Appender& appender, AppenderManager& manager);

        /// Appender测试
        void AppenderSucceedTest();
        void InsertAppenderFailTest();
        void RemoveAppenderFailTest();

        /// WriteMessage测试
        void WriteMessageToFileTest();
        void FileContentTest();
        void DeleteFileTest();

        /// WriteMessageDefaultFile测试
        void WriteMessageToDefaultFileTest();
        void DefaultFileContentTest();

        void DoWriteMessageToDefaultFileTest(AppenderManager& manager, LogLevel logLevel, const String& message);

    private:
        String appenderManagerTestingName;
        String appenderManagerTestingFullName;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_MANAGER_TESTING_H
