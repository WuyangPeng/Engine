/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:13)

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
        void DoRunUnitTest() override;
        void MainTest();

        void ViewOfFileTest();

        void DoViewOfFileTest(unsigned index);
        void MapViewOfFileTest(FileMapDesiredAccess fileMapDesiredAccess);
        void DoViewOfFileUseBaseAddressTest(FileMapDesiredAccess fileMapDesiredAccess);
        void BufferTest(WindowsVoidPtr buffer);

        NODISCARD WindowsHandle Create();
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_VIEW_OF_FILE_TESTING_H