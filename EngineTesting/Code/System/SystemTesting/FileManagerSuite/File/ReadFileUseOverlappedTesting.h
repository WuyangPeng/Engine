///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 17:14)

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
        void DoRunUnitTest() override;
        void MainTest();

        void ReadFileUseOverlappedTest();

        void DoReadFileUseOverlappedTest(WindowsHandle handle);
        void ReadResultTest(WindowsDWord inNumber, const BufferType& buffer) override;

    private:
        WindowsDWord offset;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_READ_FILE_USE_OVERLAPPED_TESTING_H