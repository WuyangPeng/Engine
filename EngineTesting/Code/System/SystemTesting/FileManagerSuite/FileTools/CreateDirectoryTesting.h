///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/15 21:15)

#ifndef SYSTEM_FILE_MANAGER_SUITE_CREATE_DIRECTORY_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_CREATE_DIRECTORY_TESTING_H

#include "System/SystemTesting/FileManagerSuite/FileTestingBase.h"

namespace System
{
    class CreateDirectoryTesting final : public FileTestingBase
    {
    public:
        using ClassType = CreateDirectoryTesting;
        using ParentType = FileTestingBase;

    public:
        explicit CreateDirectoryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateDirectoryTest();

        void CreateFileFailTest();
        void CreateFileSuccessTest();
        void RemoveDirectoryTest();

    private:
        String directoryName;
        String fileName;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_CREATE_DIRECTORY_TESTING_H