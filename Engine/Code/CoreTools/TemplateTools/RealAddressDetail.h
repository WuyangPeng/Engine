//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/23 15:34)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_REAL_ADDRESS_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_REAL_ADDRESS_DETAIL_H

#include "RealAddress.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26492)
template <typename T>
T* CoreTools::GetAddress(T& t) noexcept
{
    return const_cast<T*>(reinterpret_cast<T const volatile*>(&reinterpret_cast<uint8_t const volatile&>(t)));
}
#include STSTEM_WARNING_POP

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_REAL_ADDRESS_DETAIL_H