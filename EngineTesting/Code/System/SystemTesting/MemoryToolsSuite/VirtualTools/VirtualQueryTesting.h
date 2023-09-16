///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 10:02)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_QUERY_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_QUERY_TESTING_H

#include "VirtualToolsTestingBase.h"
#include "System/MemoryTools/Using/VirtualToolsUsing.h"

namespace System
{
    class VirtualQueryTesting final : public VirtualToolsTestingBase
    {
    public:
        using ClassType = VirtualQueryTesting;
        using ParentType = VirtualToolsTestingBase;

    public:
        explicit VirtualQueryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool VirtualQueryTest();
        void QueryTest();

        void DoQueryTest(size_t index);
        void DoQueryUseProcessTest(size_t index);

        void QueryMemoryBasicInformationTest(size_t index, WindowsVoidPtr baseVirtual);
        void QueryMemoryBasicInformationUseProcessTest(size_t index, WindowsVoidPtr baseVirtual);
        void MemoryBasicInformationTest(const MemoryBasicInformation& memoryBasicInformation, size_t index, WindowsVoidPtr baseVirtual);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_QUERY_TESTING_H