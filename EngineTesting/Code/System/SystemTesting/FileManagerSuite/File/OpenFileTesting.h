///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/15 0:54)

#ifndef SYSTEM_FILE_MANAGER_SUITE_OPEN_FILE_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_OPEN_FILE_TESTING_H

#include "System/SystemTesting/FileManagerSuite/FileTestingBase.h"

namespace System
{
    class OpenFileTesting final : public FileTestingBase
    {
    public:
        using ClassType = OpenFileTesting;
        using ParentType = FileTestingBase;

    public:
        explicit OpenFileTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OpenValidFileTest();
        void OpenInvalidFileTest();
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_OPEN_FILE_TESTING_H