//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/19 12:53)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MD5_CONTEXT_STATUS_H
#define CORE_TOOLS_MEMORY_TOOLS_MD5_CONTEXT_STATUS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
    enum class MD5ContextStatus
    {
        Init,
        Update,
        Final,
        Disabled,
    };
}
#endif  // CORE_TOOLS_MEMORY_TOOLS_MD5_CONTEXT_STATUS_H
