/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 11:16)

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
        void DoRunUnitTest() override;
        void MainTest();

        void WriteTest();
        void DoWriteTest(WindowsHandle handle);
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_APPEND_FILE_TESTING_H