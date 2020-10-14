//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 10:53)

#ifndef CORE_TOOLS_BASE_UNIQUEID_MANAGER_DETAIL_H
#define CORE_TOOLS_BASE_UNIQUEID_MANAGER_DETAIL_H

#include "UniqueIDManager.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template<typename E>
void CoreTools::UniqueIDManager
	::Create(E count)
{
	static_assert(std::is_enum_v<E>, "E must be an enum.");

	// ����������û�е��������ﲻʹ��ȫ������Create�����л�ʹ��ȫ������

	return Create(System::EnumCastUnderlying<int>(count));
}

template<typename E>
uint64_t CoreTools::UniqueIDManager
	::NextUniqueID(E index)
{
	static_assert(std::is_enum_v<E>, "E must be an enum.");

	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return NextUniqueID(System::EnumCastUnderlying<int>(index));
}

#endif // CORE_TOOLS_BASE_UNIQUEID_MANAGER_DETAIL_H

