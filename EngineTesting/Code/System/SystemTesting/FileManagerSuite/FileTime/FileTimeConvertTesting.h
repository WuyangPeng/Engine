///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/24 15:33)

#ifndef SYSTEM_FILE_MANAGE_SUITE_FILE_TIME_CONVERT_TESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_FILE_TIME_CONVERT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class FileTimeConvertTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FileTimeConvertTesting;
        using ParentType = UnitTest;

    public:
        explicit FileTimeConvertTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FileTimeTest();
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_FILE_TIME_CONVERT_TESTING_H