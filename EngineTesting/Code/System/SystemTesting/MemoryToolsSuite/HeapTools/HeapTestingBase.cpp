///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/19 21:17)

#include "HeapTestingBase.h"
#include "System/MemoryTools/Flags/HeapToolsFlags.h"
#include "System/MemoryTools/HeapTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::HeapTestingBase::HeapTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      heapCreates{ HeapCreate::Default,
                   HeapCreate::NoSerialize,
                   HeapCreate::GenerateExceptions,
                   HeapCreate::ZeroMemory,
                   HeapCreate::ReallocInPlaceOnly,
                   HeapCreate::Growable,
                   HeapCreate::TailCheckingEnabled,
                   HeapCreate::FreeCheckingEnabled,
                   HeapCreate::DisableCoalesceOnFree,
                   HeapCreate::CreateAlign16,
                   HeapCreate::CreateEnableTracing,
                   HeapCreate::MaximumTag,
                   HeapCreate::PseudoTagFlag,
                   HeapCreate::TagShift,
                   HeapCreate::CreateSegmentHeap,
                   HeapCreate::CreateHardened },
      randomEngine{ GetEngineRandomSeed() },
      indexDistribution{ 0u, heapCreates.size() - 1 }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, HeapTestingBase)

System::HeapTestingBase::HeapCreateContainerConstIter System::HeapTestingBase::begin() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return heapCreates.cbegin();
}

System::HeapTestingBase::HeapCreateContainerConstIter System::HeapTestingBase::end() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return heapCreates.cend();
}

System::HeapCreate System::HeapTestingBase::GetRandomHeapCreate()
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return heapCreates.at(indexDistribution(randomEngine));
}

void System::HeapTestingBase::DestroyHeapTest(WindowsHandle handle)
{
    SYSTEM_CLASS_IS_VALID_1;

    ASSERT_TRUE(DestroyProcessHeap(handle));
}

void System::HeapTestingBase::FreeHeapTest(WindowsHandle handle, WindowsVoidPtr memory)
{
    SYSTEM_CLASS_IS_VALID_1;

    ASSERT_TRUE(FreeProcessHeap(handle, GetRandomHeapCreate(), memory));
}
