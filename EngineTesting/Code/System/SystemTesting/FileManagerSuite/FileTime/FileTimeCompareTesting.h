/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 11:22)

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
        void DoRunUnitTest() override;
        void MainTest();

        void FileTimeTest();
        void DoFileTimeTest(WindowsHandle handle);

    private:
        String existingFileName;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_FILE_TIME_COMPARE_TESTING_H