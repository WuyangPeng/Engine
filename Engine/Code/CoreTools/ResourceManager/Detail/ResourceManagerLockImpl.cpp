// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:08)

#include "CoreTools/CoreToolsExport.h"

#include "ResourceManagerLockImpl.h"
#include "CoreTools/ResourceManager/BaseResourceManager.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::ResourceManagerLockImpl
	::ResourceManagerLockImpl(BaseResourceManager& manager, uint32_t uniqueID)
	:m_ResourceManager{ manager }, m_UniqueID{ uniqueID },
	 m_ResourceSharedPtr{ m_ResourceManager.Lock(m_UniqueID) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ResourceManagerLockImpl
	::~ResourceManagerLockImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;

	m_ResourceManager.Unlock(m_UniqueID);
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ResourceManagerLockImpl)

const CoreTools::ResourceManagerLockImpl::ResourceSharedPtr CoreTools::ResourceManagerLockImpl
	::GetResourceSharedPtr() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_ResourceSharedPtr;
}
