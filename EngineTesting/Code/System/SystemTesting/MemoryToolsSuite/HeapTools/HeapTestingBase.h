///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/16 19:35)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_HEAP_TESTING_BASE_H
#define SYSTEM_MEMORY_TOOLS_SUITE_HEAP_TESTING_BASE_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class HeapTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = HeapTestingBase;
        using ParentType = UnitTest;

    public:
        explicit HeapTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using HeapCreateContainer = std::vector<HeapCreate>;
        using HeapCreateContainerConstIter = HeapCreateContainer::const_iterator;

    protected:
        NODISCARD HeapCreateContainerConstIter begin() const noexcept;
        NODISCARD HeapCreateContainerConstIter end() const noexcept;
        NODISCARD HeapCreate GetRandomHeapCreate();
        void DestroyHeapTest(WindowsHandle handle);
        void FreeHeapTest(WindowsHandle handle, WindowsVoidPtr memory);

    private:
        HeapCreateContainer heapCreates;
        std::default_random_engine randomEngine;
        std::uniform_int_distribution<size_t> indexDistribution;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_HEAP_TESTING_BASE_H