/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 17:18)

#include "System/SystemExport.h"

#include "ProcessTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

bool System::OpenSystemProcessToken(WindowsHandle process, TokenStandardAccess standardAccess, TokenSpecificAccess specificAccess, WindowsHandlePtr tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::OpenProcessToken(process, EnumCastUnderlying(standardAccess) | EnumCastUnderlying(specificAccess), tokenHandle) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(process, standardAccess, specificAccess, tokenHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}