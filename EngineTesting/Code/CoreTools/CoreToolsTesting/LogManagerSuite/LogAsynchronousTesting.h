/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 22:39)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_LOG_ASYNCHRONOUS_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_LOG_ASYNCHRONOUS_TESTING_H

#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LogAsynchronousTesting final : public UnitTest
    {
    public:
        using ClassType = LogAsynchronousTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit LogAsynchronousTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using AppenderManagerSharedPtr = AppenderManager::AppenderManagerSharedPtr;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WriteMessageToFileTest();
        void FileContentTest();
        void DeleteFileTest();
        void WriteMessageToDefaultFileTest();

        void InitAppenderManager(const Appender& appender, const Logger& logger, AppenderManager& manager);
        void RegisteredTest(const AppenderManagerSharedPtr& manager, LogLevel logLevel, const String& message);
        void WriteMessageToFileRegisteredTest(const AppenderManagerSharedPtr& manager);
        void WriteMessageToDefaultFileRegisteredTest(const AppenderManagerSharedPtr& manager);
        void DefaultFileRegisteredTest(const AppenderManagerSharedPtr& manager, LogLevel logLevel, const String& message);

    private:
        String logAsynchronousTestingName;
        String logAsynchronousTestingFullName;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_LOG_ASYNCHRONOUS_TESTING_H