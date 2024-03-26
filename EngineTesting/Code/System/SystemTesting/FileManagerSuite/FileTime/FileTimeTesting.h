/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 11:22)

#ifndef SYSTEM_FILE_MANAGER_SUITE_FILE_TIME_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_FILE_TIME_TESTING_H

#include "System/FileManager/Using/FileUsing.h"
#include "System/SystemTesting/FileManagerSuite/FileTestingBase.h"

namespace System
{
    class FileTimeTesting final : public FileTestingBase
    {
    public:
        using ClassType = FileTimeTesting;
        using ParentType = FileTestingBase;

    public:
        explicit FileTimeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FileTimeTest();
        void DoFileTimeTest(WindowsHandle handle);
        void SetSystemFileTimeTest(WindowsHandle handle);
        void ResultTest(const FileTime& newCreationTime, const FileTime& newLastAccessTime, const FileTime& newLastWriteTime);

    private:
        String existingFileName;
        FileTime creationTime;
        FileTime lastAccessTime;
        FileTime lastWriteTime;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_FILE_TIME_TESTING_H