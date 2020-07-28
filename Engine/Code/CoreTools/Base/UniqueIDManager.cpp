// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 09:58)

#include "CoreTools/CoreToolsExport.h"

#include "UniqueIDManagerDetail.h"
#include "Flags/UniqueIDSelectFlags.h"
#include "Detail/UniqueIDManagerImpl.h"
#include "CoreTools/Helper/MainFunctionMacro.h" 

#include <memory>

using std::string;
using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(CoreTools, UniqueIDManager);

CoreTools::UniqueIDManager::UniqueIDManagerUniquePtr CoreTools::UniqueIDManager
	::sm_UniqueIDManager{ };

void CoreTools::UniqueIDManager
	::Create(int count)
{
	sm_UniqueIDManager = make_unique<CoreTools::UniqueIDManager>(count, UniqueIDManagerCreate::Init);
}

void CoreTools::UniqueIDManager
	::Destroy() noexcept
{
	sm_UniqueIDManager.reset();
}

CoreTools::UniqueIDManager
	::UniqueIDManager(int count, UniqueIDManagerCreate uniqueIDManagerCreate)
	:m_Impl{ make_shared<ImplType>(count) }
{
	SYSTEM_UNUSED_ARG(uniqueIDManagerCreate);

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, UniqueIDManager)

uint64_t CoreTools::UniqueIDManager
	::NextDefaultUniqueID()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return NextUniqueID(UniqueIDSelect::Default);
}

uint64_t CoreTools::UniqueIDManager
	::NextUniqueID(int index)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->NextUniqueID(index);
}


