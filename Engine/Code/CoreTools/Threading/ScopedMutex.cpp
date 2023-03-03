///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/01 17:34)

#include "CoreTools/CoreToolsExport.h"

#include "DllMutex.h"
#include "ScopedMutex.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::ScopedMutex::ScopedMutex(MasterType& mutex)
    : mutex{ mutex }
{
    mutex.Enter();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ScopedMutex::~ScopedMutex() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    mutex.Leave();
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ScopedMutex)
