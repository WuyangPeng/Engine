//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/24 12:54)

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
