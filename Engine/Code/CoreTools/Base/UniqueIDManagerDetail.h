///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/12 14:23)

#ifndef CORE_TOOLS_BASE_UNIQUEID_MANAGER_DETAIL_H
#define CORE_TOOLS_BASE_UNIQUEID_MANAGER_DETAIL_H

#include "UniqueIDManager.h"
#include "System/Helper/EnumCast.h"

template <typename E>
void CoreTools::UniqueIDManager::Create(E count)
{
    static_assert(std::is_enum_v<E>, "E must be an enum.");

    // ����������û�е��������ﲻʹ��ȫ������Create�����л�ʹ��ȫ������

    return Create(System::EnumCastUnderlying<int>(count));
}

template <typename E>
uint64_t CoreTools::UniqueIDManager::NextUniqueID(E index)
{
    static_assert(std::is_enum_v<E>, "E must be an enum.");

    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    return NextUniqueID(System::EnumCastUnderlying<int>(index));
}

template <typename E>
void CoreTools::UniqueIDManager::SetUniqueID(E index, uint64_t latestIndex)
{
    static_assert(std::is_enum_v<E>, "E must be an enum.");

    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    return SetUniqueID(System::EnumCastUnderlying<int>(index), latestIndex);
}

#endif  // CORE_TOOLS_BASE_UNIQUEID_MANAGER_DETAIL_H
