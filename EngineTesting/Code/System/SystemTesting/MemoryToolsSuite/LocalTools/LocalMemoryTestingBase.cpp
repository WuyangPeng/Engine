///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/04 20:57)

#include "LocalMemoryTestingBase.h"
#include "System/MemoryTools/Flags/LocalMemoryFlags.h"
#include "System/MemoryTools/LocalTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::LocalMemoryTestingBase::LocalMemoryTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      localMemoryCollection{ LocalMemory::Fixed,
                             LocalMemory::Moveable,
                             LocalMemory::NoCompact,
                             LocalMemory::NoDiscard,
                             LocalMemory::ZeroInit,
                             LocalMemory::Discardable,
                             LocalMemory::ValidFlags,
                             LocalMemory::LHnd,
                             LocalMemory::LPtr,
                             LocalMemory::NonZeroLHnd,
                             LocalMemory::NonZeroLPtr }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LocalMemoryTestingBase)

System::LocalMemoryTestingBase::LocalMemoryContainerConstIter System::LocalMemoryTestingBase::begin() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return localMemoryCollection.cbegin();
}

System::LocalMemoryTestingBase::LocalMemoryContainerConstIter System::LocalMemoryTestingBase::end() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return localMemoryCollection.cend();
}

void System::LocalMemoryTestingBase::LocalMemoryFreeTest(WindowsHLocal localMemory)
{
    SYSTEM_CLASS_IS_VALID_1;

    ASSERT_TRUE(LocalMemoryFree(localMemory));
}
