///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 21:03)

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
