// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 09:54)

#ifndef CORE_TOOLS_BASE_UNIQUEID_MANAGER_DETAIL_H
#define CORE_TOOLS_BASE_UNIQUEID_MANAGER_DETAIL_H

#include "UniqueIDManager.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#define MUTEX_ENTER_UNIQUEID_MANAGER_MEMBER CoreTools::ScopedMutex holder{ *sm_UniqueIDManagerMutex }

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

	MUTEX_ENTER_UNIQUEID_MANAGER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return NextUniqueID(System::EnumCastUnderlying<int>(index));
}

#endif // CORE_TOOLS_BASE_UNIQUEID_MANAGER_DETAIL_H

