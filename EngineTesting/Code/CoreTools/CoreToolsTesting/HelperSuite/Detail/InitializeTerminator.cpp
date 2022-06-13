///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:22)

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
