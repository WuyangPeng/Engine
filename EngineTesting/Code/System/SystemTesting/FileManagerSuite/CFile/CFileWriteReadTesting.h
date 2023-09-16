///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:12)

#ifndef SYSTEM_FILE_MANAGER_SUITE_C_FILE_WRITE_READ_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_C_FILE_WRITE_READ_TESTING_H

#include "CFileTestingBase.h"

namespace System
{
    class CFileWriteReadTesting final : public CFileTestingBase
    {
    public:
        using ClassType = CFileWriteReadTesting;
        using ParentType = CFileTestingBase;

    public:
        explicit CFileWriteReadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WriteTest();
        void ReadTest();

        void DoWriteTest(FILE* file);
        void DoReadTest(FILE* file);
        NODISCARD OffType GetFileLengthTest();
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_C_FILE_WRITE_READ_TESTING_H