/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 18:09)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadGuardImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::ThreadGuardImpl::ThreadGuardImpl(std::thread thread) noexcept
    : thread{ std::move(thread) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ThreadGuardImpl::~ThreadGuardImpl() noexcept
{
    Join();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ThreadGuardImpl)

void CoreTools::ThreadGuardImpl::Join() noexcept
{
    EXCEPTION_TRY
    {
        thread.join();
    }
    EXCEPTION_STD_EXCEPTION_CATCH(CoreTools)
    EXCEPTION_UNKNOWN_CATCH(CoreTools)
}
