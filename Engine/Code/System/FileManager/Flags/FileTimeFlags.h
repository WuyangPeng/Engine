///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/28 16:47)

#ifndef SYSTEM_FILE_MANAGER_FILE_TIME_FLAGS_H
#define SYSTEM_FILE_MANAGER_FILE_TIME_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    enum class ComparesFileTimeReturn
    {
        Earlier = -1,
        Equal = 0,
        Later = 1,
    };
}

#endif  // SYSTEM_FILE_MANAGER_FILE_TIME_FLAGS_H
