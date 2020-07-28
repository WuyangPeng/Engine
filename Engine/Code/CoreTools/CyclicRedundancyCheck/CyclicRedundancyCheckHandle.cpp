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
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(CoreTools, CyclicRedundancyCheckHandle);

CoreTools::CyclicRedundancyCheckHandle::CyclicRedundancyCheckHandleUniquePtr CoreTools::CyclicRedundancyCheckHandle
::sm_CyclicRedundancyCheckHandle{ };

void CoreTools::CyclicRedundancyCheckHandle
::Create()
{
	sm_CyclicRedundancyCheckHandle = make_unique<CoreTools::CyclicRedundancyCheckHandle>(CyclicRedundancyCheckHandleCreate::Init);
}

void CoreTools::CyclicRedundancyCheckHandle
::Destroy() noexcept
{
	sm_CyclicRedundancyCheckHandle.reset();
}

CoreTools::CyclicRedundancyCheckHandle
::CyclicRedundancyCheckHandle(CyclicRedundancyCheckHandleCreate cyclicRedundancyCheckHandleCreate)
	:m_Impl{ make_shared<ImplType>() }
{
	SYSTEM_UNUSED_ARG(cyclicRedundancyCheckHandleCreate);

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, CyclicRedundancyCheckHandle)
uint16_t CoreTools::CyclicRedundancyCheckHandle
	::GetCCITT(int index) const
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetCCITT(index);
}

uint16_t CoreTools::CyclicRedundancyCheckHandle
	::Get16Table(int index) const
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->Get16Table(index);
}

uint32_t CoreTools::CyclicRedundancyCheckHandle
	::Get32Table(int index) const
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->Get32Table(index);
}

