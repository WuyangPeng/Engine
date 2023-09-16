///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 10:01)

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