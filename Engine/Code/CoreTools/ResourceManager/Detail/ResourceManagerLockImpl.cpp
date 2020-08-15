// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 13:08)

#include "CoreTools/CoreToolsExport.h"

#include "ResourceManagerLockImpl.h"
#include "CoreTools/ResourceManager/BaseResourceManager.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::ResourceManagerLockImpl
	::ResourceManagerLockImpl(BaseResourceManager& manager, uint32_t uniqueID)
	:m_ResourceManager{ manager }, m_UniqueID{ uniqueID },
	 m_ResourceSharedPtr{ m_ResourceManager.Lock(m_UniqueID) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ResourceManagerLockImpl
	::~ResourceManagerLockImpl() noexcept
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
	
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)

	EXCEPTION_TRY
	{
		m_ResourceManager.Unlock(m_UniqueID);
	}
	EXCEPTION_ALL_CATCH(CoreTools)

#include STSTEM_WARNING_POP 

	
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ResourceManagerLockImpl)

const CoreTools::ResourceManagerLockImpl::ResourceSharedPtr CoreTools::ResourceManagerLockImpl
	::GetResourceSharedPtr() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_ResourceSharedPtr;
}
