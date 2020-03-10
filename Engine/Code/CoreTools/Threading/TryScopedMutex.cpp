// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:29)

#include "CoreTools/CoreToolsExport.h"

#include "TryScopedMutex.h"
#include "DllMutex.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::TryScopedMutex
	::TryScopedMutex(MasterType& mutex)
	:m_Mutex{ mutex }, m_IsSuccess{ m_Mutex.TryEnter() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::TryScopedMutex
	::~TryScopedMutex()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;

	if (m_IsSuccess)
	{
		m_Mutex.Leave();
	}
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TryScopedMutex)

bool CoreTools::TryScopedMutex
	::IsSuccess() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_IsSuccess;
}

