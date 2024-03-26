/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 09:23)

#ifndef SYSTEM_FILE_MANAGER_C_FILE_FLAGS_H
#define SYSTEM_FILE_MANAGER_C_FILE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

#include <cstdio>

namespace System
{
    enum class FileSeek
    {
        Set = SEEK_SET,
        Cur = SEEK_CUR,
        End = SEEK_END
    };

    enum class FileSetVBuffer
    {
        IoFullyBuffered = _IOFBF,
        IoLineBuffering = _IOLBF,
        IoNoBuffering = _IONBF,
    };
}

#endif  // SYSTEM_FILE_MANAGER_C_FILE_FLAGS_H
