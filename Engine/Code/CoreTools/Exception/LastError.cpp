//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 14:29)

#include "CoreTools/CoreToolsExport.h"

#include "LastError.h"
#include "System/Window/Flags/PlatformErrorFlags.h"
#include "System/Window/LastPlatformError.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LastError::LastError() noexcept
    : m_LastError{ System::GetPlatformLastError() }
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

    return m_LastError;
}
