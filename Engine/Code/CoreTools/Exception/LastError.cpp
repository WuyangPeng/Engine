///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/30 14:43)

#include "CoreTools/CoreToolsExport.h"

#include "LastError.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "System/Windows/LastPlatformError.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LastError::LastError() noexcept
    : lastError{ System::GetPlatformLastError() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::LastError::~LastError() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    System::SetPlatformLastError(System::WindowError::Success);
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LastError)

CoreTools::LastError::WindowError CoreTools::LastError::GetLastError() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return lastError;
}
