/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/27 20:18)

#ifndef SYSTEM_SYSTEM_OUTPUT_DIALOG_BOX_COMMAND_FLAGS_H
#define SYSTEM_SYSTEM_OUTPUT_DIALOG_BOX_COMMAND_FLAGS_H

#include "System/Helper/Platform.h"

/// 对话框命令Id
namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class DialogBoxCommand
    {
        IdCreationFailed = 0,
        IdOk = IDOK,
        IdCancel = IDCANCEL,
        IdAbort = IDABORT,
        IdRetry = IDRETRY,
        IdIgnore = IDIGNORE,
        IdYes = IDYES,
        IdNo = IDNO,
        IdClose = IDCLOSE,
        IdHelp = IDHELP,
        IdTryAgain = IDTRYAGAIN,
        IdContinue = IDCONTINUE,
        IdTimeout = IDTIMEOUT,

        PlatformUnknown = -1,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class DialogBoxCommand
    {
        IdCreationFailed = 0,
        IdOk = 1,
        IdCancel = 2,
        IdAbort = 3,
        IdRetry = 4,
        IdIgnore = 5,
        IdYes = 6,
        IdNo = 7,
        IdClose = 8,
        IdHelp = 9,
        IdTryAgain = 10,
        IdContinue = 11,
        IdTimeout = 32000,

        PlatformUnknown = -1,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SYSTEM_OUTPUT_DIALOG_BOX_COMMAND_FLAGS_H