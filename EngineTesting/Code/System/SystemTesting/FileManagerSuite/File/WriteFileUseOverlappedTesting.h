/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 11:22)

#ifndef SYSTEM_FILE_MANAGER_SUITE_WRITE_FILE_USE_OVERLAPPED_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_WRITE_FILE_USE_OVERLAPPED_TESTING_H

#include "ReadWriteFileTestingBase.h"

namespace System
{
    class WriteFileUseOverlappedTesting final : public ReadWriteFileTestingBase
    {
    public:
        using ClassType = WriteFileUseOverlappedTesting;
        using ParentType = ReadWriteFileTestingBase;

    public:
        explicit WriteFileUseOverlappedTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WriteFileUseOverlappedTest();
        void DoWriteFileUseOverlappedTest(WindowsHandle handle);
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_WRITE_FILE_USE_OVERLAPPED_TESTING_H