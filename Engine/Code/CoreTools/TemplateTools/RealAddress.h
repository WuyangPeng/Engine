///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 16:19)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_REAL_ADDRESS_H
#define CORE_TOOLS_TEMPLATE_TOOLS_REAL_ADDRESS_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    NODISCARD T* GetAddress(T& t) noexcept;
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_REAL_ADDRESS_H