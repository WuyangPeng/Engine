/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:16)

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

uint16_t CoreTools::CyclicRedundancyCheckHandle::GetCcitt(int index) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetCcitt(index);
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
