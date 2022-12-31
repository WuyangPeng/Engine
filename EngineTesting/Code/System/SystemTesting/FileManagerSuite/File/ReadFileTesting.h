///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/15 11:17)

#ifndef SYSTEM_FILE_MANAGER_SUITE_READ_FILE_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_READ_FILE_TESTING_H

#include "ReadWriteFileTestingBase.h"

namespace System
{
    class ReadFileTesting final : public ReadWriteFileTestingBase
    {
    public:
        using ClassType = ReadFileTesting;
        using ParentType = ReadWriteFileTestingBase;

    public:
        explicit ReadFileTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ReadTest();

        void DoReadTest(WindowsHandle handle);
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_READ_FILE_TESTING_H