/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/18 21:51)

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
        void DoRunUnitTest() override;
        void MainTest();

        void LogAppenderIOManageSignTest();
        void FileContentTest();
        void DeleteFileTest();

    private:
        using AppenderManagerSharedPtr = std::shared_ptr<AppenderManager>;

    private:
        NODISCARD static AppenderManagerSharedPtr GetAppenderManager();

    private:
        String logAppenderIOManagerTestingName;
        String logAppenderIOManagerTestingFullName;
    };
}

#endif  // LOG_MANAGER_LOG_APPENDER_IO_MANAGER_SIGN_TESTING_H
