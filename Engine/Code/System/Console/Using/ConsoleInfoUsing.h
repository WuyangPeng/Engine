//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 15:30)

#ifndef SYSTEM_CONSOLE_CONSOLE_INFO_USING_H
#define SYSTEM_CONSOLE_CONSOLE_INFO_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using ConsoleHistoryInfo = CONSOLE_HISTORY_INFO;
    using ConsoleHistoryInfoPtr = PCONSOLE_HISTORY_INFO;
    using ConsoleSelectionInfo = CONSOLE_SELECTION_INFO;
    using ConsoleSelectionInfoPtr = PCONSOLE_SELECTION_INFO;

#else  // !SYSTEM_PLATFORM_WIN32

    struct ConsoleHistoryInfo
    {
        uint32_t cbSize;
        uint32_t HistoryBufferSize;
        uint32_t NumberOfHistoryBuffers;
        uint32_t dwFlags;
    };
    using ConsoleHistoryInfoPtr = ConsoleHistoryInfo*;

    struct ConsoleSelectionInfo
    {
        uint32_t dwFlags;
        uint32_t dwSelectionAnchor;
        ConsoleSmallRect srSelection;
    };

    using ConsoleSelectionInfoPtr = ConsoleSelectionInfo*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CONSOLE_CONSOLE_INFO_USING_H