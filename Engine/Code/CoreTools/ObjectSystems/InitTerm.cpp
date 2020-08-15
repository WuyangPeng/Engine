// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:53)

#include "CoreTools/CoreToolsExport.h"

#include "InitTerm.h"
#include "ObjectManager.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

int CoreTools::InitTerm::sm_NumInitializers{ 0 };
CoreTools::InitTerm::Initializer CoreTools::InitTerm
	::sm_Initializers[sm_MaxElements];

int CoreTools::InitTerm::sm_NumTerminators{ 0 };
CoreTools::InitTerm::Terminator CoreTools::InitTerm
	::sm_Terminators[sm_MaxElements];

CORE_TOOLS_MUTEX_EXTERN(CoreTools);

#define MUTEX_ENTER_GLOBAL CoreTools::ScopedMutex holder(GetCoreToolsMutex())

void CoreTools::InitTerm
	::AddInitializer(Initializer function)
{
	if (sm_NumInitializers < sm_MaxElements)
	{
		sm_Initializers[sm_NumInitializers++] = function;
	}
	else
	{
		CORE_TOOLS_ASSERTION_0(false, "增加sm_MaxElements的值和重编译CoreTools库\n");
	}
}

void CoreTools::InitTerm
	::ExecuteInitializers()
{
	MUTEX_ENTER_GLOBAL;

	ObjectManager::Create();

	for (auto i = 0; i < sm_NumInitializers; ++i)
	{
		sm_Initializers[i]();
	}
}

void CoreTools::InitTerm
	::AddTerminator(Terminator function)
{
	if (sm_NumTerminators < sm_MaxElements)
	{
		sm_Terminators[sm_NumTerminators++] = function;
	}
	else
	{
		CORE_TOOLS_ASSERTION_0(false, "增加sm_MaxElements的值和重编译CoreTools库\n");
	}
}

void CoreTools::InitTerm
	::ExecuteTerminators()
{
	MUTEX_ENTER_GLOBAL;

	for (auto i = 0; i < sm_NumTerminators; ++i)
	{
		sm_Terminators[i]();
	}

	ObjectManager::Destroy();
}

#include STSTEM_WARNING_POP