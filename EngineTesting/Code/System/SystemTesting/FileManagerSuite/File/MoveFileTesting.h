///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 17:14)

#ifndef SYSTEM_FILE_MANAGER_SUITE_MOVE_FILE_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_MOVE_FILE_TESTING_H

#include "System/SystemTesting/FileManagerSuite/FileTestingBase.h"

namespace System
{
    class MoveFileTesting final : public FileTestingBase
    {
    public:
        using ClassType = MoveFileTesting;
        using ParentType = FileTestingBase;

    public:
        explicit MoveFileTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void MoveFileTest();

        void CreateAlwaysTest();
        void MoveSuccessTest();
        void RemoveFileTest();

    private:
        String oldName;
        String newName;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_MOVE_FILE_TESTING_H