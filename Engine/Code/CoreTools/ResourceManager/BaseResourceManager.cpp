// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:10)

#include "CoreTools/CoreToolsExport.h"

#include "BaseResourceManager.h"
#include "Detail/BaseResourceManagerImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::BaseResourceManager
	::BaseResourceManager(uint32_t maxSize)
	:m_Impl{ make_shared<ImplType>(maxSize) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, BaseResourceManager)

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, BaseResourceManager)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BaseResourceManager, SetMaximumMemory, uint32_t, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BaseResourceManager, GetMaximumMemory, uint32_t)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(CoreTools, BaseResourceManager, GotoBegin, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, BaseResourceManager, GetCurrentResource, const CoreTools::BaseResourceManager::ResourceWeakPtr)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(CoreTools, BaseResourceManager, GotoNext, void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BaseResourceManager, InsertResource, ResourceSharedPtr, uint32_t)

void CoreTools::BaseResourceManager
	::ModifyResource(uint32_t uniqueID, ResourceSharedPtr resource)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ModifyResource(uniqueID, resource);
}

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BaseResourceManager, RemoveResource, ResourceSharedPtr, void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BaseResourceManager, RemoveResource, uint32_t, void)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BaseResourceManager, GetResource, uint32_t, const CoreTools::BaseResourceManager::ResourceWeakPtr)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BaseResourceManager, Lock, uint32_t, const CoreTools::BaseResourceManager::ResourceSharedPtr)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BaseResourceManager, Unlock, uint32_t, void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BaseResourceManager, Unlock, ResourceSharedPtr, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BaseResourceManager, FindResourceHandle, ResourceSharedPtr, uint32_t)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(CoreTools, BaseResourceManager, IsValidResourceHandle, uint32_t, bool)
