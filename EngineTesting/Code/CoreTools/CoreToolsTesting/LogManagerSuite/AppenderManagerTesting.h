/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
/// ¡™œµ◊˜’ﬂ£∫94458936@qq.com
///
/// ±Í◊º£∫std:c++20
/// ∞Ê±æ£∫1.0.0.8 (2024/04/17 22:38)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_MANAGER_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_MANAGER_TESTING_H

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
        void DoRunUnitTest() override;
        void MainTest();

        void LoggerTest();
        void AppenderTest();
        void WriteMessageTest();
        void GetMinLogLevelTypeTest();
        void AppenderNameTest();

        /// Logger≤‚ ‘
        void LoggerSucceedTest();
        void InsertLoggerFailTest();
        void RemoveLoggerFailTest();

        /// Appender≤‚ ‘
        void AppenderSucceedTest();
        void InsertAppenderFailTest();
        void RemoveAppenderFailTest();

        /// WriteMessage≤‚ ‘
        void WriteMessageToFileTest();
        void FileContentTest();
        void DeleteFileTest();

        /// WriteMessageDefaultFile≤‚ ‘
        void WriteMessageToDefaultFileTest();
        void DefaultFileContentTest();

    private:
        String appenderManagerTestingName;
        String appenderManagerTestingFullName;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_MANAGER_TESTING_H
