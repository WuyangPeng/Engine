///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/02 11:15)

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
        std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
    }
    EXCEPTION_STD_EXCEPTION_CATCH(CoreTools)
    EXCEPTION_UNKOWN_CATCH(CoreTools)
}

void CoreTools::ThreadGroupImpl::AddThread(std::thread thread)
{
    threads.emplace_back(std::move(thread));
}