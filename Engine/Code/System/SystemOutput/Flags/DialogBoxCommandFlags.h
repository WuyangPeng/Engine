//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 9:25)

#ifndef SYSTEM_SYSTEM_OUTPUT_DIALOG_BOX_COMMAND_FLAGS_H
#define SYSTEM_SYSTEM_OUTPUT_DIALOG_BOX_COMMAND_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class DialogBoxCommand
    {
        IDCreationFailed = 0,
        IDOk = IDOK,
        IDCancel = IDCANCEL,
        IDAbort = IDABORT,
        IDRetry = IDRETRY,
        IDIgnore = IDIGNORE,
        IDYes = IDYES,
        IDNo = IDNO,
        IDClose = IDCLOSE,
        IDHelp = IDHELP,
        IDTryAgain = IDTRYAGAIN,
        IDContinue = IDCONTINUE,
        IDTimeout = IDTIMEOUT,

        PlatformUnknown = -1,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class DialogBoxCommand
    {
        IDCreationFailed = 0,
        IDOk = 1,
        IDCancel = 2,
        IDAbort = 3,
        IDRetry = 4,
        IDIgnore = 5,
        IDYes = 6,
        IDNo = 7,
        IDClose = 8,
        IDHelp = 9,
        IDTryAgain = 10,
        IDContinue = 11,
        IDTimeout = 32000,

        PlatformUnknown = -1,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SYSTEM_OUTPUT_DIALOG_BOX_COMMAND_FLAGS_H