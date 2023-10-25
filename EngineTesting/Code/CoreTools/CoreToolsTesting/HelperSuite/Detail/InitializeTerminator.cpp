///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:37)

#include "InitializeTerminator.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(CoreTools, InitializeTerminator)
CORE_TOOLS_INITIALIZE_TERMINATE_DEFINE(CoreTools, InitializeTerminator)

void CoreTools::InitializeTerminator::InitializeFactory() noexcept(true)
{
    isRegister = true;
}

void CoreTools::InitializeTerminator::TerminateFactory() noexcept(true)
{
    isRegister = false;
}

bool CoreTools::InitializeTerminator::IsRegister() noexcept
{
    return isRegister;
}

bool CoreTools::InitializeTerminator::isRegister = false;
