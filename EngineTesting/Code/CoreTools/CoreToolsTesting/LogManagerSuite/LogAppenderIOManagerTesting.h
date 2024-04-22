/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 22:39)

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
        void DoRunUnitTest() override;
        void MainTest();
        
        void IntegerTest();
        void StringTest();
        void ExceptionTest(); 
        void FileContentTest();
        void DeleteFileTest();

        void SetAppenderManagerTest();

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
