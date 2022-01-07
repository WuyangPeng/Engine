///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/18 12:29)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadGuard.h"
#include "Detail/ThreadGuardImpl.h" 

CoreTools::ThreadGuard::ThreadGuard(std::thread thread)
    : impl{ std::move(thread) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ThreadGuard)