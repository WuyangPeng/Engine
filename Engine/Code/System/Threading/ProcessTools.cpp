///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/21 0:15)

#include "System/SystemExport.h"

#include "ProcessTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::OpenSysemProcessToken(WindowsHandle process, TokenStandardAccess standardAccess, TokenSpecificAccess specificAccess, WindowsHandlePtr tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::OpenProcessToken(process, EnumCastUnderlying(standardAccess) | EnumCastUnderlying(specificAccess), tokenHandle) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(process, standardAccess, specificAccess, tokenHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
