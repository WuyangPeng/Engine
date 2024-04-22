/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 14:18)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_REAL_ADDRESS_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_REAL_ADDRESS_DETAIL_H

#include "RealAddress.h"
#include "System/Helper/PragmaWarning.h"

template <typename T>
T* CoreTools::GetAddress(T& t) noexcept
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<T*>(reinterpret_cast<T const volatile*>(&reinterpret_cast<uint8_t const volatile&>(t)));

#include SYSTEM_WARNING_POP
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_REAL_ADDRESS_DETAIL_H