///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
///	¡™œµ◊˜’ﬂ£∫94458936@qq.com
///
///	±Í◊º£∫std:c++20
///	“˝«Ê≤‚ ‘∞Ê±æ£∫0.9.0.6 (2023/04/12 11:31)

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
        void MainTest();
        void LoggerTest();
        void AppenderTest();
        void WriteMessageTest();
        void GetMinLogLevelTypeTest();

        // Logger≤‚ ‘
        void LoggerSucceedTest();
        void InsertLoggerFailTest();
        void RemoveLoggerFailTest();

        // Appender≤‚ ‘
        void AppenderSucceedTest();
        void InsertAppenderFailTest();
        void RemoveAppenderFailTest();

        // WriteMessage≤‚ ‘
        void WriteMessageToFileTest();
        void FileContentTest();
        void DeleteFileTest();

        // WriteMessageDefaultFile≤‚ ‘
        void WriteMessageToDefaultFileTest();
        void DefaultFileContentTest();

        void DoRunUnitTest() override;

    private:
        String appenderManagerTestingName;
        String appenderManagerTestingFullName;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_MANAGER_TESTING_H
