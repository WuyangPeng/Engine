///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/29 19:26)

#ifndef SYSTEM_FILE_MANAGE_FILE_TIME_FLAGS_H
#define SYSTEM_FILE_MANAGE_FILE_TIME_FLAGS_H

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

#endif  // SYSTEM_FILE_MANAGE_FILE_TIME_FLAGS_H
