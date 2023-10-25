///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 14:38)

#include "CoreTools/CoreToolsExport.h"

#include "DllMutex.h"
#include "TryScopedMutex.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::TryScopedMutex::TryScopedMutex(MasterType& mutex)
    : mutex{ mutex }, isSuccess{ mutex.TryEnter() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::TryScopedMutex::~TryScopedMutex() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    if (isSuccess)
    {
        mutex.Leave();
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TryScopedMutex)

bool CoreTools::TryScopedMutex::IsSuccess() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return isSuccess;
}
