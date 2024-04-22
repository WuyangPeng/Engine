/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 18:11)

#include "CoreTools/CoreToolsExport.h"

#include "DllMutex.h"
#include "Detail/MutexFactory.h"
#include "Detail/MutexImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::DllMutex::DllMutex(MutexCreate mutexCreate)
    : impl{ ImplCreateUseFactory::Default, mutexCreate }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::DllMutex::DllMutex(DllMutex&& rhs) noexcept
    : impl{ std::move(rhs.impl) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::DllMutex& CoreTools::DllMutex::operator=(DllMutex&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (this != &rhs)
    {
        impl = std::move(rhs.impl);
    }

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DllMutex)

bool CoreTools::DllMutex::TryEnter()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->TryEnter();
}

void CoreTools::DllMutex::Enter()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->Enter();
}

void CoreTools::DllMutex::Leave() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->Leave();
}

void CoreTools::DllMutex::Initialize()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->Initialize();
}

void CoreTools::DllMutex::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->Delete();
}
