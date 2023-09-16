///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:15)

#ifndef SYSTEM_FILE_MANAGER_SUITE_FILE_TIME_CONVERT_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_FILE_TIME_CONVERT_TESTING_H

#include "System/FileManager/Using/FileUsing.h"
#include "System/SystemTesting/FileManagerSuite/FileTestingBase.h"

namespace System
{
    class FileTimeConvertTesting final : public FileTestingBase
    {
    public:
        using ClassType = FileTimeConvertTesting;
        using ParentType = FileTestingBase;

    public:
        explicit FileTimeConvertTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FileTimeTest();

        void DoFileTimeTest(WindowsHandle handle);
        void ResultTest(const FileTime& creationTime, const FileTime& fileTime);

    private:
        String existingFileName;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_FILE_TIME_CONVERT_TESTING_H