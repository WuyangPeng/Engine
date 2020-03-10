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

SINGLETON_MUTEX_DEFINE(CoreTools, UniqueIDManager);

SINGLETON_GET_PTR_DEFINE(CoreTools, UniqueIDManager);

CORE_TOOLS_MUTEX_EXTERN(CoreTools);

#define MUTEX_ENTER_GLOBAL CoreTools::ScopedMutex holder{ g_CoreToolsMutex }

void CoreTools::UniqueIDManager
	::Create(int count)
{
	MUTEX_ENTER_GLOBAL;

	try
	{
		DoCreate(count);
	}
	catch (...)
	{
		Destroy();

		throw;
	}
}

void CoreTools::UniqueIDManager
	::DoCreate(int count)
{
	MUTEX_ENTER_GLOBAL;

	if (sm_UniqueIDManagerMutex == nullptr)
	{
		sm_UniqueIDManagerMutex = make_unique<CoreTools::Mutex>().release();
	}

	if (sm_UniqueIDManager == nullptr)
	{
		sm_UniqueIDManager = new UniqueIDManager{ count };
	}
}

void CoreTools::UniqueIDManager
	::Destroy()
{
	MUTEX_ENTER_GLOBAL;

	delete sm_UniqueIDManager;
	sm_UniqueIDManager = nullptr;

	delete sm_UniqueIDManagerMutex;
	sm_UniqueIDManagerMutex = nullptr;
}

CoreTools::UniqueIDManager
	::UniqueIDManager(int count)
	:m_Impl{ make_shared<ImplType>(count) }
{
	MUTEX_ENTER_UNIQUEID_MANAGER_MEMBER;

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::UniqueIDManager
	::~UniqueIDManager()
{
	MUTEX_ENTER_UNIQUEID_MANAGER_MEMBER;

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::UniqueIDManager
	::IsValid() const noexcept
{
	MUTEX_ENTER_UNIQUEID_MANAGER_MEMBER;

	if (m_Impl != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT 

uint64_t CoreTools::UniqueIDManager
	::NextDefaultUniqueID()
{
	MUTEX_ENTER_UNIQUEID_MANAGER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return NextUniqueID(UniqueIDSelect::Default);
}

uint64_t CoreTools::UniqueIDManager
	::NextUniqueID(int index)
{
	MUTEX_ENTER_UNIQUEID_MANAGER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->NextUniqueID(index);
}


