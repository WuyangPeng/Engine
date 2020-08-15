// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/11 10:53)

#include "Network/NetworkExport.h"

#include "BaseMainManager.h"
#include "Detail/BaseMainManagerImpl.h"
#include "Detail/BaseMainManagerFactory.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MainFunctionMacro.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(CoreTools, EntityManager);

Network::BaseMainManager::BaseMainManagerUniquePtr Network::BaseMainManager
::sm_BaseMainManager{ };

void Network::BaseMainManager
::Create(const ConfigurationStrategy& configurationStrategy)
{
	sm_BaseMainManager = make_unique<Network::BaseMainManager>(configurationStrategy,BaseMainManagerCreate::Init);
}

void Network::BaseMainManager
::Destroy() noexcept
{
	sm_BaseMainManager.reset();
}

Network::BaseMainManager
::BaseMainManager(const ConfigurationStrategy& configurationStrategy, BaseMainManagerCreate baseMainManagerCreate)
	:m_Impl{ BaseMainManagerFactory::Create(configurationStrategy) }
{
	SYSTEM_UNUSED_ARG(baseMainManagerCreate);

	NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, BaseMainManager)
 

void Network::BaseMainManager
	::Run()
{
	// Run调用会阻塞线程，不能加锁。

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->Run();
}
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26489)
Network::IOContextType& Network::BaseMainManager
	::GetIOContext()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->GetIOContext();
}
#include STSTEM_WARNING_POP
void Network::BaseMainManager
	::StopContext()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->StopContext();
}

bool Network::BaseMainManager
	::IsContextStop() const
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->IsContextStop();
}

void Network::BaseMainManager
	::RestartContext()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->RestartContext();
}

