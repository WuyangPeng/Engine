// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:07)

#include "CoreTools/CoreToolsExport.h"

#include "BaseResourceLockManager.h"
#include "CoreTools/ResourceManager/BaseResource.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::BaseResourceLockManager
	::BaseResourceLockManager(BaseResource& manager) noexcept
	:m_Manager{ manager }
{
	m_Manager.Lock();

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::BaseResourceLockManager
	::~BaseResourceLockManager()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;

	m_Manager.Unlock();
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BaseResourceLockManager)

