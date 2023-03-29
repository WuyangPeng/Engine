///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/22 19:22)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheckHandle.h"
#include "Detail/CyclicRedundancyCheckHandleImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"

SINGLETON_GET_PTR_DEFINE(CoreTools, CyclicRedundancyCheckHandle);

CoreTools::CyclicRedundancyCheckHandle::CyclicRedundancyCheckHandleUniquePtr CoreTools::CyclicRedundancyCheckHandle::cyclicRedundancyCheckHandle{};

void CoreTools::CyclicRedundancyCheckHandle::Create()
{
    cyclicRedundancyCheckHandle = std::make_unique<CoreTools::CyclicRedundancyCheckHandle>(CyclicRedundancyCheckHandleCreate::Init);
}

void CoreTools::CyclicRedundancyCheckHandle::Destroy() noexcept
{
    cyclicRedundancyCheckHandle.reset();
}

CoreTools::CyclicRedundancyCheckHandle::CyclicRedundancyCheckHandle(CyclicRedundancyCheckHandleCreate cyclicRedundancyCheckHandleCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(cyclicRedundancyCheckHandleCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheckHandle)

uint16_t CoreTools::CyclicRedundancyCheckHandle::GetCCITT(int index) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetCCITT(index);
}

uint16_t CoreTools::CyclicRedundancyCheckHandle::Get16Table(int index) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->Get16Table(index);
}

uint32_t CoreTools::CyclicRedundancyCheckHandle::Get32Table(int index) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->Get32Table(index);
}
