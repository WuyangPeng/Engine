///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/12 19:16)

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
