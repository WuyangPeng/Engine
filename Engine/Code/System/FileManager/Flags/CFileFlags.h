/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 19:01)

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
        IOFBF = _IOFBF,
        IOLBF = _IOLBF,
        IONBF = _IONBF,
    };
}

#endif  // SYSTEM_FILE_MANAGER_C_FILE_FLAGS_H
