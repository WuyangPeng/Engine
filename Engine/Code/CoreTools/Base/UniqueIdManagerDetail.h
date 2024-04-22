/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/28 16:47)

#ifndef CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_DETAIL_H
#define CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_DETAIL_H

#include "UniqueIdManager.h"
#include "System/Helper/EnumCast.h"

template <typename E>
void CoreTools::UniqueIdManager::Create(E count) requires(std::is_enum_v<E>)
{
    /// ����������û�е��������ﲻʹ��ȫ������Create�����л�ʹ��ȫ������

    return Create(System::EnumCastUnderlying<int>(count));
}

template <typename E>
int64_t CoreTools::UniqueIdManager::NextUniqueId(E index) requires(std::is_enum_v<E>)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    return NextUniqueId(System::EnumCastUnderlying<int>(index));
}

template <typename E>
void CoreTools::UniqueIdManager::SetUniqueId(E index, int64_t latestIndex) requires(std::is_enum_v<E>)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    return SetUniqueId(System::EnumCastUnderlying(index), latestIndex);
}

#endif  // CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_DETAIL_H
