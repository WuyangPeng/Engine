///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 11:17)

#ifndef LOG_MANAGER_LOG_APPENDER_IO_MANAGER_TESTING_H
#define LOG_MANAGER_LOG_APPENDER_IO_MANAGER_TESTING_H

#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LogAppenderIOManagerTesting final : public UnitTest
    {
    public:
        using ClassType = LogAppenderIOManagerTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit LogAppenderIOManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void IntegerTest();
        void StringTest();
        void ExceptionTest();
        void LogAppenderIOManageSignTest();
        void FileContentTest();
        void DeleteFileTest();

        void SetAppenderManagerTest();

        void DoRunUnitTest() override;

    private:
        using AppenderManagerSharedPtr = std::shared_ptr<AppenderManager>;

    private:
        NODISCARD static AppenderManagerSharedPtr GetAppenderManager();

    private:
        String logAppenderIOManagerTestingName;
        String logAppenderIOManagerTestingFullName;
    };
}

#endif  // LOG_MANAGER_LOG_APPENDER_IO_MANAGER_TESTING_H
