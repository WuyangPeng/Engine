///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 12:16)

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