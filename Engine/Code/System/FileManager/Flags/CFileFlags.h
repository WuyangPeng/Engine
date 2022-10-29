///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/29 19:26)

#ifndef SYSTEM_FILE_MANAGE_C_FILE_FLAGS_H
#define SYSTEM_FILE_MANAGE_C_FILE_FLAGS_H

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

    enum class FileSetvBuf
    {
        IOFBF = _IOFBF,
        IOLBF = _IOLBF,
        IONBF = _IONBF,
    };
}

#endif  // SYSTEM_FILE_MANAGE_C_FILE_FLAGS_H
