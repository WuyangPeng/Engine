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

using std::make_unique;

SINGLETON_MUTEX_DEFINE(Network, BaseMainManager);

#define MUTEX_ENTER_GLOBAL CoreTools::ScopedMutex holder{ GetNetworkMutex() }

#define MUTEX_ENTER_MEMBER CoreTools::ScopedMutex holder{ *sm_BaseMainManagerMutex }

SINGLETON_GET_PTR_DEFINE(Network, BaseMainManager)

void Network::BaseMainManager
	::Create(const ConfigurationStrategy& configurationStrategy)
{
	MUTEX_ENTER_GLOBAL;

	try
	{
		DoCreate(configurationStrategy);
	}
	catch (...)
	{
		Destroy();
		throw;
	}
}

void Network::BaseMainManager::Create()
{
	MUTEX_ENTER_GLOBAL;
}

void Network::BaseMainManager
	::DoCreate(const ConfigurationStrategy& configurationStrategy)
{
	MUTEX_ENTER_GLOBAL;

	if (sm_BaseMainManagerMutex == nullptr)
	{
		sm_BaseMainManagerMutex = make_unique<CoreTools::Mutex>().release();
	}

	if (sm_BaseMainManager == nullptr)
	{
		sm_BaseMainManager = new BaseMainManager(configurationStrategy);
	}
}

void Network::BaseMainManager
	::Destroy()
{
	MUTEX_ENTER_GLOBAL;

	delete sm_BaseMainManager;
	sm_BaseMainManager = nullptr;

	delete sm_BaseMainManagerMutex;
	sm_BaseMainManagerMutex = nullptr;
}

Network::BaseMainManager
	::BaseMainManager(const ConfigurationStrategy& configurationStrategy)
	:m_Impl{ BaseMainManagerFactory::Create(configurationStrategy) }
{
	MUTEX_ENTER_MEMBER;

	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::BaseMainManager
	::~BaseMainManager()
{
	MUTEX_ENTER_MEMBER;

	NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Network::BaseMainManager
	::IsValid() const noexcept
{
	MUTEX_ENTER_MEMBER;

	if (m_Impl != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Network::BaseMainManager
	::Run()
{
	// Run调用会阻塞线程，不能加锁。

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->Run();
}

Network::IOContextType& Network::BaseMainManager
	::GetIOContext()
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->GetIOContext();
}

void Network::BaseMainManager
	::StopContext()
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->StopContext();
}

bool Network::BaseMainManager
	::IsContextStop() const
{
	MUTEX_ENTER_MEMBER;

	NETWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->IsContextStop();
}

void Network::BaseMainManager
	::RestartContext()
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->RestartContext();
}

