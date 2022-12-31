///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/14 17:27)

#ifndef SYSTEM_FILE_MANAGER_SUITE_DIRECTORY_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_DIRECTORY_TESTING_H

#include "System/SystemTesting/FileManagerSuite/FileTestingBase.h"

namespace System
{
    class DirectoryTesting final : public FileTestingBase
    {
    public:
        using ClassType = DirectoryTesting;
        using ParentType = FileTestingBase;

    public:
        explicit DirectoryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DirectoryTest();
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_DIRECTORY_TESTING_H