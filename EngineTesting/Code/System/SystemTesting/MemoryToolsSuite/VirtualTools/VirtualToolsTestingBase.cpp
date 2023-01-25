///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/06 20:40)

#include "VirtualToolsTestingBase.h"
#include "System/MemoryTools/Flags/VirtualToolsFlags.h"
#include "System/MemoryTools/VirtualTools.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::VirtualToolsTestingBase::VirtualToolsTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      memoryAllocations{ MemoryAllocation::Commit,
                         MemoryAllocation::ReserveAndCommit,
                         MemoryAllocation::TopDown | MemoryAllocation::Commit,
                         MemoryAllocation::TopDown | MemoryAllocation::ReserveAndCommit,
                         MemoryAllocation::WriteWatch | MemoryAllocation::Commit },
      memoryProtects{ MemoryProtect::NoAccess,
                      MemoryProtect::ReadOnly,
                      MemoryProtect::ReadWrite,
                      MemoryProtect::Execute,
                      MemoryProtect::ExecuteRead,
                      MemoryProtect::ExecuteReadWrite },
      maxSize{ std::max(memoryAllocations.size(), memoryProtects.size()) },
      randomEngine{ GetEngineRandomSeed() },
      windowsSystemInfo{}
{
    GetWindowSystemInfo(windowsSystemInfo);

    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, VirtualToolsTestingBase)

void System::VirtualToolsTestingBase::RandomShuffle()
{
    SYSTEM_CLASS_IS_VALID_1;

    shuffle(memoryAllocations.begin(), memoryAllocations.end(), randomEngine);
    shuffle(memoryProtects.begin(), memoryProtects.end(), randomEngine);
}

size_t System::VirtualToolsTestingBase::GetMaxSize() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return maxSize;
}

System::MemoryAllocation System::VirtualToolsTestingBase::GetMemoryAllocation(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return memoryAllocations.at(index % memoryAllocations.size());
}

System::MemoryProtect System::VirtualToolsTestingBase::GetMemoryProtect(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return memoryProtects.at(index % memoryProtects.size());
}

System::WindowsDWord System::VirtualToolsTestingBase::GetPageSize() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return GetOnePageSize() * pageLimit;
}

System::WindowsDWord System::VirtualToolsTestingBase::GetOnePageSize() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return windowsSystemInfo.dwPageSize;
}

void System::VirtualToolsTestingBase::FreeVirtualTest(WindowsVoidPtr baseVirtual)
{
    SYSTEM_CLASS_IS_VALID_1;

    ASSERT_TRUE(FreeVirtual(baseVirtual));
}

void System::VirtualToolsTestingBase::FreeVirtualUseProcessTest(WindowsHandle process, WindowsVoidPtr baseVirtual)
{
    SYSTEM_CLASS_IS_VALID_1;

    ASSERT_TRUE(FreeVirtual(process, baseVirtual));
}

void System::VirtualToolsTestingBase::DoReadWriteTest(MemoryProtect memoryProtect, char& basePage) noexcept
{
    if ((memoryProtect & MemoryProtect::ReadWrite) != MemoryProtect::Zero ||
        (memoryProtect & MemoryProtect::ExecuteReadWrite) != MemoryProtect::Zero)
    {
        basePage = '\0';
    }

    if ((memoryProtect & MemoryProtect::ReadOnly) != MemoryProtect::Zero ||
        (memoryProtect & MemoryProtect::ExecuteRead) != MemoryProtect::Zero)
    {
        MAYBE_UNUSED const auto read = basePage;
    }
}
