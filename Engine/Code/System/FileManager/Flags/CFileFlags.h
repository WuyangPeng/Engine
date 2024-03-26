/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 09:23)

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
