/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:16)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadGroupImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::ThreadGroupImpl::ThreadGroupImpl() noexcept
    : threads{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ThreadGroupImpl::~ThreadGroupImpl() noexcept
{
    Join();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ThreadGroupImpl)

void CoreTools::ThreadGroupImpl::Join() noexcept
{
    EXCEPTION_TRY
    {
        std::ranges::for_each(threads, std::mem_fn(&std::thread::join));
    }
    EXCEPTION_STD_EXCEPTION_CATCH(CoreTools)
    EXCEPTION_UNKNOWN_CATCH(CoreTools)
}

void CoreTools::ThreadGroupImpl::AddThread(std::thread thread)
{
    threads.emplace_back(std::move(thread));
}