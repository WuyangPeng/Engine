///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/05 22:36)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_VIEW_OF_FILE_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_VIEW_OF_FILE_TESTING_H

#include "FileMappingTestingBase.h"

namespace System
{
    class ViewOfFileTesting final : public FileMappingTestingBase
    {
    public:
        using ClassType = ViewOfFileTesting;
        using ParentType = FileMappingTestingBase;

    public:
        explicit ViewOfFileTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ViewOfFileTest();

        void DoViewOfFileTest(FileMapDesiredAccess fileMapDesiredAccess);
        void DoViewOfFileUseBaseAddressTest(FileMapDesiredAccess fileMapDesiredAccess);
        void BufferTest(WindowsVoidPtr buffer);

        NODISCARD WindowsHandle Create();
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_VIEW_OF_FILE_TESTING_H