/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:16)

#include "LocalMemoryTestingBase.h"
#include "System/MemoryTools/Flags/LocalMemoryFlags.h"
#include "System/MemoryTools/LocalTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::LocalMemoryTestingBase::LocalMemoryTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      localMemoryCollection{ LocalMemory::Fixed,
                             LocalMemory::MoveAble,
                             LocalMemory::NoCompact,
                             LocalMemory::NoDiscard,
                             LocalMemory::ZeroInit,
                             LocalMemory::DiscardAble,
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
