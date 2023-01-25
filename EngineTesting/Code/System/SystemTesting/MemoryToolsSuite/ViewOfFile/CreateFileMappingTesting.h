///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/05 21:00)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_CREATE_FILE_MAPPING_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_CREATE_FILE_MAPPING_TESTING_H

#include "FileMappingTestingBase.h"

namespace System
{
    class CreateFileMappingTesting final : public FileMappingTestingBase
    {
    public:
        using ClassType = CreateFileMappingTesting;
        using ParentType = FileMappingTestingBase;

    public:
        explicit CreateFileMappingTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool CreateFileMappingRandomShuffle();

        void CreateFileMappingTest();
        void DoCreateFileMappingTest(size_t index);
        void FileMappingTest(size_t index, WindowsHandle fileHandle);
        void FileMappingAgainTest(size_t index, WindowsHandle fileHandle);
        NODISCARD WindowsHandle Create(size_t index, WindowsHandle fileHandle, bool isAgain);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_CREATE_FILE_MAPPING_TESTING_H