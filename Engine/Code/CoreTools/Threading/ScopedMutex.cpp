//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 19:20)

#include "CoreTools/CoreToolsExport.h"

#include "DllMutex.h"
#include "ScopedMutex.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::ScopedMutex::ScopedMutex(MasterType& mutex)
    : m_Mutex{ mutex }
{
    m_Mutex.Enter();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ScopedMutex::~ScopedMutex() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    m_Mutex.Leave();
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ScopedMutex)
