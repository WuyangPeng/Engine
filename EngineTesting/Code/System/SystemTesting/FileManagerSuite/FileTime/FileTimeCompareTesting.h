///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/15 21:49)

#ifndef SYSTEM_FILE_MANAGER_SUITE_FILE_TIME_COMPARE_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_FILE_TIME_COMPARE_TESTING_H

#include "System/SystemTesting/FileManagerSuite/FileTestingBase.h"

namespace System
{
    class FileTimeCompareTesting final : public FileTestingBase
    {
    public:
        using ClassType = FileTimeCompareTesting;
        using ParentType = FileTestingBase;

    public:
        explicit FileTimeCompareTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FileTimeTest();

        void DoFileTimeTest(WindowsHandle handle);

    private:
        String existingFileName;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_FILE_TIME_COMPARE_TESTING_H