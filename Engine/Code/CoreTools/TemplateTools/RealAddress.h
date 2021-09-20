//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/23 15:28)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_REAL_ADDRESS_H
#define CORE_TOOLS_TEMPLATE_TOOLS_REAL_ADDRESS_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    [[nodiscard]] T* GetAddress(T& t) noexcept;
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_REAL_ADDRESS_H