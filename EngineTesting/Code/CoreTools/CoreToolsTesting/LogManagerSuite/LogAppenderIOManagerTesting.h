///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 10:52)

#ifndef LOG_MANAGER_LOG_APPENDER_IO_MANAGER_TESTING_H
#define LOG_MANAGER_LOG_APPENDER_IO_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class LogAppenderIOManagerTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(LogAppenderIOManagerTesting);

    private:
        void MainTest();
        void IntegerTest();
        void StringTest();
        void Error1Test();
        void FormatTest();
        void LogAppenderIOManageSignTest();
        void FileContentTest();
        void DeleteFileTest();

        void DoRunUnitTest() override;

    private:
        using AppenderManagerSharedPtr = std::shared_ptr<AppenderManager>;

    private:
        NODISCARD AppenderManagerSharedPtr GetAppenderManager();

    private:
        System::String logAppenderIOManagerTestingName;
        System::String logAppenderIOManagerTestingFullName;
    };
}

#endif  // LOG_MANAGER_LOG_APPENDER_IO_MANAGER_TESTING_H
