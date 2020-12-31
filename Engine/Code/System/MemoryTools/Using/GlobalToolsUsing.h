//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 0:59)

#ifndef SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_USING_H
#define SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using WindowMemoryStatus = MEMORYSTATUS;
    using WindowMemoryStatusPtr = LPMEMORYSTATUS;

#else  // !SYSTEM_PLATFORM_WIN32

    struct WindowMemoryStatus
    {
        WindowDWord dwLength;
        WindowDWord dwMemoryLoad;
        WindowSize dwTotalPhys;
        WindowSize dwAvailPhys;
        WindowSize dwTotalPageFile;
        WindowSize dwAvailPageFile;
        WindowSize dwTotalVirtual;
        WindowSize dwAvailVirtual;
    };

    using WindowMemoryStatusPtr = WindowMemoryStatus*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_USING_H