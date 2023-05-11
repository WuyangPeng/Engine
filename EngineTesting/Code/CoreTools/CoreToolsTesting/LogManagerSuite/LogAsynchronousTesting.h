﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/12 14:56)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_LOG_ASYNCHRONOUS_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_LOG_ASYNCHRONOUS_TESTING_H

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
        void MainTest();

        void WriteMessageToFileTest();
        void FileContentTest();
        void DeleteFileTest();
        void WriteMessageToDefaultFileTest();

        void DoRunUnitTest() override;

    private:
        String logAsynchronousTestingName;
        String logAsynchronousTestingFullName;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_LOG_ASYNCHRONOUS_TESTING_H