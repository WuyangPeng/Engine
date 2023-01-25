///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/06 21:57)

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
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool VirtualProtectTest();

        void ProtectTest();

        void DoProtectTest(size_t index);
        void DoProtectUseProcessTest(size_t index);
        void SetVirtualProtectTest(size_t index, WindowsVoidPtr baseVirtual);
        void SetVirtualProtectUseProcessTest(size_t index, WindowsVoidPtr baseVirtual);
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_VIRTUAL_PROTECT_TESTING_H