///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 17:14)

#ifndef SYSTEM_FILE_MANAGER_SUITE_FILE_HANDLE_POINTER_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_FILE_HANDLE_POINTER_TESTING_H

#include "System/SystemTesting/FileManagerSuite/FileTestingBase.h"

namespace System
{
    class FileHandlePointerTesting final : public FileTestingBase
    {
    public:
        using ClassType = FileHandlePointerTesting;
        using ParentType = FileTestingBase;

    public:
        explicit FileHandlePointerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FilePointerTest();

        void DoFilePointerTest(WindowsHandle handle);
        void SetFilePointerTest(WindowsHandle handle);
        void FlushSystemFileBuffersTest(WindowsHandle handle);
        void SetEndOfFileTest(WindowsHandle handle);

    private:
        BufferType buffer;
        WindowsLong distanceToMove;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_FILE_HANDLE_POINTER_TESTING_H