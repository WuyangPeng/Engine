///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/15 11:41)

#ifndef SYSTEM_FILE_MANAGER_SUITE_READ_FILE_USE_OVERLAPPED_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_READ_FILE_USE_OVERLAPPED_TESTING_H

#include "ReadWriteFileTestingBase.h"

namespace System
{
    class ReadFileUseOverlappedTesting final : public ReadWriteFileTestingBase
    {
    public:
        using ClassType = ReadFileUseOverlappedTesting;
        using ParentType = ReadWriteFileTestingBase;

    public:
        explicit ReadFileUseOverlappedTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ReadFileUseOverlappedTest();

        void DoReadFileUseOverlappedTest(WindowsHandle handle);
        void ReadResultTest(WindowsDWord inNumber, const BufferType& buffer) override;

    private:
        WindowsDWord offset;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_READ_FILE_USE_OVERLAPPED_TESTING_H