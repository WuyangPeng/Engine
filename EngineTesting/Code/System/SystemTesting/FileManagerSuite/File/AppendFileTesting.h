///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/15 14:07)

#ifndef SYSTEM_FILE_MANAGER_SUITE_APPEND_FILE_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_APPEND_FILE_TESTING_H

#include "ReadWriteFileTestingBase.h"

namespace System
{
    class AppendFileTesting final : public ReadWriteFileTestingBase
    {
    public:
        using ClassType = AppendFileTesting;
        using ParentType = ReadWriteFileTestingBase;

    public:
        explicit AppendFileTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void WriteTest();

        void DoWriteTest(WindowsHandle handle);
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_APPEND_FILE_TESTING_H