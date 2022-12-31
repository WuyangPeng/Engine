///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/15 0:41)

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
        void DoRunUnitTest() final;
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