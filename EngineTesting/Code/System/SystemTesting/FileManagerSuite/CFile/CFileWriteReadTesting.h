///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/12 16:10)

#ifndef SYSTEM_FILE_MANAGER_SUITE_CFILE_WRITE_READ_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_CFILE_WRITE_READ_TESTING_H

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
        void DoRunUnitTest() final;
        void MainTest();

        void WriteTest();
        void ReadTest();

        void DoWriteTest(FILE* file);
        void DoReadTest(FILE* file);
        NODISCARD OffType GetFileLengthTest();
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_CFILE_WRITE_READ_TESTING_H