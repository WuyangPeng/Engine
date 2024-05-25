/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/07 21:49)

#ifndef LOG_MANAGER_LOG_APPENDER_IO_MANAGER_SIGN_TESTING_H
#define LOG_MANAGER_LOG_APPENDER_IO_MANAGER_SIGN_TESTING_H

#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LogAppenderIOManagerSignTesting final : public UnitTest
    {
    public:
        using ClassType = LogAppenderIOManagerSignTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit LogAppenderIOManagerSignTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        using AppenderManagerSharedPtr = std::shared_ptr<AppenderManager>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LogAppenderIOManageSignTest();
        void FileContentTest();
        void DeleteFileTest();

        NODISCARD static AppenderManagerSharedPtr GetAppenderManager();
        NODISCARD static LogMessage GetLogMessage();

    private:
        String logAppenderIOManagerTestingName;
        String logAppenderIOManagerTestingFullName;
    };
}

#endif  // LOG_MANAGER_LOG_APPENDER_IO_MANAGER_SIGN_TESTING_H
