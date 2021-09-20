///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/23 14:36)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_VIEW_OF_FILE_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_VIEW_OF_FILE_TESTING_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class ViewOfFileTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ViewOfFileTesting;
        using ParentType = UnitTest;

    public:
        explicit ViewOfFileTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ViewOfFileTest();

        void DoViewOfFileTest(FileMapDesiredAccess fileMapDesiredAccess);

        void DoViewOfFileUseBaseAddressTest(FileMapDesiredAccess fileMapDesiredAccess);

    private:
        using FileMapDesiredAccessFlagsCollection = std::vector<FileMapDesiredAccess>;

    private:
        FileMapDesiredAccessFlagsCollection fileMapDesiredAccessFlags;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_VIEW_OF_FILE_TESTING_H