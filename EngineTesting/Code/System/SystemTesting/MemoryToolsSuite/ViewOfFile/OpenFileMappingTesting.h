/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:13)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_OPEN_FILE_MAPPING_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_OPEN_FILE_MAPPING_TESTING_H

#include "FileMappingTestingBase.h"

namespace System
{
    class OpenFileMappingTesting final : public FileMappingTestingBase
    {
    public:
        using ClassType = OpenFileMappingTesting;
        using ParentType = FileMappingTestingBase;

    public:
        explicit OpenFileMappingTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();

        void OpenFileMappingTest();
        void DoOpenFileMappingTest(size_t index);

        void FileMappingTest(size_t index, WindowsHandle fileHandle);
        void FileMappingOpenTest(size_t index);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_OPEN_FILE_MAPPING_TESTING_H