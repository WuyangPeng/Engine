// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:51)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheckHandle.h"
#include "Detail/CyclicRedundancyCheckHandleImpl.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

SINGLETON_MUTEX_DEFINE(CoreTools, CyclicRedundancyCheckHandle);

#define MUTEX_ENTER_GLOBAL CoreTools::ScopedMutex holder{ g_CoreToolsMutex }
#define MUTEX_ENTER_MEMBER CoreTools::ScopedMutex holder{ *sm_CyclicRedundancyCheckHandleMutex }

SINGLETON_INITIALIZE_DEFINE(CoreTools, CyclicRedundancyCheckHandle);

CoreTools::CyclicRedundancyCheckHandle
	::CyclicRedundancyCheckHandle()
	:m_Impl{ make_shared<ImplType>() }
{
	MUTEX_ENTER_MEMBER;

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CyclicRedundancyCheckHandle
	::~CyclicRedundancyCheckHandle()
{
	MUTEX_ENTER_MEMBER;

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::CyclicRedundancyCheckHandle
	::IsValid() const noexcept
{
	MUTEX_ENTER_MEMBER;

	if (m_Impl != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

uint16_t CoreTools::CyclicRedundancyCheckHandle
	::GetCCITT(int index) const
{
	MUTEX_ENTER_MEMBER;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetCCITT(index);
}

uint16_t CoreTools::CyclicRedundancyCheckHandle
	::Get16Table(int index) const
{
	MUTEX_ENTER_MEMBER;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->Get16Table(index);
}

uint32_t CoreTools::CyclicRedundancyCheckHandle
	::Get32Table(int index) const
{
	MUTEX_ENTER_MEMBER;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->Get32Table(index);
}

