///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/17 21:56)

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
