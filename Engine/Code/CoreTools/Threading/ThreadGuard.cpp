///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/01 18:03)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadGuard.h"
#include "Detail/ThreadGuardImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::ThreadGuard::ThreadGuard(std::thread thread)
    : impl{ std::move(thread) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ThreadGuard)