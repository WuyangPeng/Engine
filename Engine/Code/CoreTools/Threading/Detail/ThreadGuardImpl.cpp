///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 16:40)

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
