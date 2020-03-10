// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:35)

#ifndef FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_DETAIL_H

#include "ObjectLogicManager.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template<typename ObjectLogic, typename  ArtificialIntellegence>
Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::ObjectLogicManager() 
	:ParentType{}, m_ObjectLogic(), 
	 m_ArtificialIntellegence()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::~ObjectLogicManager()
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
	::PreCreate() 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::PreCreate() && m_ObjectLogic.PreCreate() &&
		m_ArtificialIntellegence.PreCreate())
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
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::Initialize() &&	m_ObjectLogic.Initialize() &&
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
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::PreIdle();
	m_ObjectLogic.PreIdle();
	m_ArtificialIntellegence.PreIdle();
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::Terminate() 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::Terminate();	
	m_ObjectLogic.Terminate();
	m_ArtificialIntellegence.Terminate();
}
		
template<typename ObjectLogic, typename  ArtificialIntellegence>
bool Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::Create() 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::Create() &&	m_ObjectLogic.Create() && m_ArtificialIntellegence.Create())
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
	FRAMEWORK_CLASS_IS_VALID_1;

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
	FRAMEWORK_CLASS_IS_VALID_1;

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
	::SetSystemManager(MiddleLayerInterfaceSmartPointer& systemManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::SetSystemManager(systemManager);
	m_ObjectLogic.SetSystemManager(systemManager);
	m_ArtificialIntellegence.SetSystemManager(systemManager);
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::SetPhysicalModellingManager(MiddleLayerInterfaceSmartPointer& physicalModellingManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::SetPhysicalModellingManager(physicalModellingManager);
	m_ObjectLogic.SetPhysicalModellingManager(physicalModellingManager);
	m_ArtificialIntellegence.SetPhysicalModellingManager(physicalModellingManager);
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::SetMessageManager(MiddleLayerInterfaceSmartPointer& messageManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::SetMessageManager(messageManager);
	m_ObjectLogic.SetMessageManager(messageManager);
	m_ArtificialIntellegence.SetMessageManager(messageManager);
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::SetInputManager(MiddleLayerInterfaceSmartPointer& inputManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::SetInputManager(inputManager);
	m_ObjectLogic.SetInputManager(inputManager);
	m_ArtificialIntellegence.SetInputManager(inputManager);
}

template<typename ObjectLogic, typename  ArtificialIntellegence>
void Framework::ObjectLogicManager<ObjectLogic, ArtificialIntellegence>
	::SetNetworkManager(MiddleLayerInterfaceSmartPointer& networkManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::SetNetworkManager(networkManager);
	m_ObjectLogic.SetNetworkManager(networkManager);
	m_ArtificialIntellegence.SetNetworkManager(networkManager);
}

#endif // FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_DETAIL_H

