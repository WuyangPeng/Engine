/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 10:14)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_PROTECT_TESTING_H
#define SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_PROTECT_TESTING_H

#include "VirtualToolsTestingBase.h"

namespace System
{
    class VirtualProtectTesting final : public VirtualToolsTestingBase
    {
    public:
        using ClassType = VirtualProtectTesting;
        using ParentType = VirtualToolsTestingBase;

    public:
        explicit VirtualProtectTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool VirtualProtectTest();

        void ProtectTest();

        void DoProtectTest(size_t index);
        void MemoryProtectTest(size_t index);
        void DoProtectUseProcessTest(size_t index);
        void SetVirtualProtectTest(size_t index, WindowsVoidPtr baseVirtual);
        void SetVirtualProtectUseProcessTest(size_t index, WindowsVoidPtr baseVirtual);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_PROTECT_TESTING_H