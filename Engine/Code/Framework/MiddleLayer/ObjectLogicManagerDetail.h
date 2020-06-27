// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:44)

#ifndef FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_DETAIL_H

#include "ObjectLogicManager.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template<typename ObjectLogic, typename  ArtificialIntellegence>
Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::ObjectLogicManager(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, m_ObjectLogic{ middleLayerPlatform }, m_ArtificialIntellegence{ middleLayerPlatform }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
} 

#ifdef OPEN_CLASS_INVARIANT
template<typename ObjectLogic, typename  ArtificialIntellegence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template<typename ObjectLogic, typename  ArtificialIntellegence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::PreCreate(environmentDirectory) && 
		m_ObjectLogic.PreCreate(environmentDirectory) &&
		m_ArtificialIntellegence.PreCreate(environmentDirectory))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::Initialize()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Initialize() &&
		m_ObjectLogic.Initialize() &&
		m_ArtificialIntellegence.Initialize())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::PreIdle()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::PreIdle();
	m_ObjectLogic.PreIdle();
	m_ArtificialIntellegence.PreIdle();
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::Terminate()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Terminate();
	m_ObjectLogic.Terminate();
	m_ArtificialIntellegence.Terminate();
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::Create()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Create() && m_ObjectLogic.Create() && m_ArtificialIntellegence.Create())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::Destroy()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Destroy() && m_ObjectLogic.Destroy() && m_ArtificialIntellegence.Destroy())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::Idle(int64_t timeDelta)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Idle(timeDelta) && m_ObjectLogic.Idle(timeDelta) && m_ArtificialIntellegence.Idle(timeDelta))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::SetSystemManager(const MiddleLayerInterfaceSharedPtr& systemManager)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto manager = systemManager;
	
	ParentType::SetSystemManager(manager);
	m_ObjectLogic.SetSystemManager(manager);
	m_ArtificialIntellegence.SetSystemManager(manager);
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::SetPhysicalModellingManager(const MiddleLayerInterfaceSharedPtr& physicalModellingManager)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto manager = physicalModellingManager;

	ParentType::SetPhysicalModellingManager(manager);
	m_ObjectLogic.SetPhysicalModellingManager(manager);
	m_ArtificialIntellegence.SetPhysicalModellingManager(manager);
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::SetMessageManager(const MiddleLayerInterfaceSharedPtr& messageManager)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto manager = messageManager;

	ParentType::SetMessageManager(manager);
	m_ObjectLogic.SetMessageManager(manager);
	m_ArtificialIntellegence.SetMessageManager(manager);
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::SetInputManager(const MiddleLayerInterfaceSharedPtr& inputManager)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto manager = inputManager;

	ParentType::SetInputManager(manager);
	m_ObjectLogic.SetInputManager(manager);
	m_ArtificialIntellegence.SetInputManager(manager);
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::SetNetworkManager(const MiddleLayerInterfaceSharedPtr& networkManager)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto manager = networkManager;

	ParentType::SetNetworkManager(manager);
	m_ObjectLogic.SetNetworkManager(manager);
	m_ArtificialIntellegence.SetNetworkManager(manager);
}

#endif // FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_DETAIL_H

