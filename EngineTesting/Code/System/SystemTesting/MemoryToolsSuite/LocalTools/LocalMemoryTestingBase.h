///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 10:01)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_LOCAL_MEMORY_TESTING_BASE_H
#define SYSTEM_MEMORY_TOOLS_SUITE_LOCAL_MEMORY_TESTING_BASE_H

#include "System/MemoryTools/Fwd/MemoryToolsFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class LocalMemoryTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = LocalMemoryTestingBase;
        using ParentType = UnitTest;

    public:
        explicit LocalMemoryTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using LocalMemoryContainer = std::vector<LocalMemory>;
        using LocalMemoryContainerConstIter = LocalMemoryContainer::const_iterator;

    protected:
        NODISCARD LocalMemoryContainerConstIter begin() const noexcept;
        NODISCARD LocalMemoryContainerConstIter end() const noexcept;
        void LocalMemoryFreeTest(WindowsHLocal localMemory);

    private:
        LocalMemoryContainer localMemoryCollection;
    };
}

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_LOCAL_MEMORY_TESTING_BASE_H