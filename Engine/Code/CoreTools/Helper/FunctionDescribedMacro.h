///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.1 (2021/07/29 16:09)

#ifndef CORE_TOOLS_HELPER_FUNCTION_DESCRIBED_MACRO_H
#define CORE_TOOLS_HELPER_FUNCTION_DESCRIBED_MACRO_H

#include "CoreTools/Contract/FunctionDescribed.h"

#define CORE_TOOLS_FUNCTION_DESCRIBED \
    CoreTools::FunctionDescribed      \
    {                                 \
        __func__, __FILE__, __LINE__  \
    }

#endif  // CORE_TOOLS_HELPER_FUNCTION_DESCRIBED_MACRO_H