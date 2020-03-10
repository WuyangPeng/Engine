// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/08/01 11:30)

#ifndef FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_DETAIL_H

#include "EngineMiddleLayerContainer.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "CoreTools/MemoryTools/SmartPointerManager.h"

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                      MessageManager, EventManager, SystemManager, ResourceManager, 
									  AudioManager, CameraSystemsManager, RenderingManager, GUIManager>
	::EngineMiddleLayerContainer()
	:m_NetworkManager(NEW0 NetworkManagerType), 
	 m_InputManager(NEW0 InputManagerType),	 
	 m_ObjectLogicManager(NEW0 ObjectLogicManagerType),
	 m_PhysicalModellingManager(NEW0 PhysicalModellingManagerType),
	 m_MessageManager(NEW0 MessageManagerType),
	 m_EventManager(NEW0 EventManagerType),
	 m_SystemManager(NEW0 SystemManagerType),
	 m_ResourceManager(NEW0 ResourceManagerType),
	 m_AudioManager(NEW0 AudioManagerType),
	 m_CameraSystemsManager(NEW0 CameraSystemsManagerType),
	 m_RenderingManager(NEW0 RenderingManagerType),
	 m_GUIManager(NEW0 GUIManagerType)
{
	Init();

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// private
template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                           MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::Init()
{
	InitNetworkManager();
	InitInputManager();
	InitObjectLogicManager();
	InitPhysicalModellingManager();
	InitMessageManager();
	InitEventManager();
	InitSystemManager();
	InitResourceManager();
	InitAudioManager();
	InitCameraSystemsManager();
	InitRenderingManager();
	InitGUIManager();
}

// private
template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                           MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitNetworkManager()
{
	m_NetworkManager->SetInputManager(m_InputManager);
	m_NetworkManager->SetObjectLogicManager(m_ObjectLogicManager);
}

// private
template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                           MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitInputManager()
{
	m_InputManager->SetNetworkManager(m_NetworkManager);
	m_InputManager->SetObjectLogicManager(m_ObjectLogicManager);
	m_InputManager->SetSystemManager(m_SystemManager);
	m_InputManager->SetCameraSystemsManager(m_CameraSystemsManager);
}

// private
template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                           MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitObjectLogicManager()
{
	m_ObjectLogicManager->SetNetworkManager(m_NetworkManager);
	m_ObjectLogicManager->SetInputManager(m_InputManager);
	m_ObjectLogicManager->SetPhysicalModellingManager(m_PhysicalModellingManager);
	m_ObjectLogicManager->SetMessageManager(m_MessageManager);
	m_ObjectLogicManager->SetSystemManager(m_SystemManager);
}

// private
template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                           MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitPhysicalModellingManager()
{
	m_PhysicalModellingManager->SetObjectLogicManager(m_ObjectLogicManager);
}

// private
template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                           MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitMessageManager()
{
	m_MessageManager->SetObjectLogicManager(m_ObjectLogicManager);
	m_MessageManager->SetSystemManager(m_SystemManager);
}

// private
template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                           MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitEventManager()
{
	m_EventManager->SetMessageManager(m_MessageManager);
	m_EventManager->SetSystemManager(m_SystemManager);
}

// private
template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                           MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitSystemManager()
{
	m_SystemManager->SetInputManager(m_InputManager);
	m_SystemManager->SetObjectLogicManager(m_ObjectLogicManager);
	m_SystemManager->SetMessageManager(m_MessageManager);
	m_SystemManager->SetEventManager(m_EventManager);
	m_SystemManager->SetResourceManager(m_ResourceManager);
	m_SystemManager->SetAudioManager(m_AudioManager);
	m_SystemManager->SetCameraSystemsManager(m_CameraSystemsManager);
	m_SystemManager->SetRenderingManager(m_RenderingManager);	
}

// private
template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                           MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitResourceManager()
{
	m_ResourceManager->SetSystemManager(m_SystemManager);
	m_ResourceManager->SetAudioManager(m_AudioManager);
	m_ResourceManager->SetRenderingManager(m_RenderingManager);
	m_ResourceManager->SetGUIManager(m_GUIManager);
}

// private
template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                           MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitAudioManager()
{
	m_AudioManager->SetSystemManager(m_SystemManager);
	m_AudioManager->SetResourceManager(m_ResourceManager);
}


// private
template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                           MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitCameraSystemsManager()
{
	m_CameraSystemsManager->SetSystemManager(m_SystemManager);
	m_CameraSystemsManager->SetRenderingManager(m_RenderingManager);
	m_CameraSystemsManager->SetGUIManager(m_GUIManager);
}

// private
template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                           MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitRenderingManager()
{
	m_RenderingManager->SetSystemManager(m_SystemManager);
}

// private
template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                           MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitGUIManager()
{
	m_GUIManager->SetRenderingManager(m_RenderingManager);
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                      MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, 
									  CameraSystemsManager, RenderingManager, GUIManager>
	::~EngineMiddleLayerContainer()
{
	MiddleLayerInterfaceSmartPointer nullPointer;

	m_SystemManager->SetEngineManager(nullPointer);

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

 #ifdef OPEN_CLASS_INVARIANT
template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, 
                                           MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::IsValid() const noexcept
{
	if(ParentType::IsValid() &&
	   m_NetworkManager.IsValidPtr() &&
	   m_InputManager.IsValidPtr() &&
	   m_ObjectLogicManager.IsValidPtr() &&
	   m_PhysicalModellingManager.IsValidPtr() &&
	   m_MessageManager.IsValidPtr() &&
	   m_EventManager.IsValidPtr() &&
	   m_SystemManager.IsValidPtr() &&
	   m_ResourceManager.IsValidPtr() &&
	   m_AudioManager.IsValidPtr() &&
	   m_CameraSystemsManager.IsValidPtr() &&
	   m_RenderingManager.IsValidPtr() &&
	   m_GUIManager.IsValidPtr())
	{
		return true;
	}
	else
	{
		return false;
	}		
}
#endif // OPEN_CLASS_INVARIANT

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager,
										   SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetInputManager(MiddleLayerInterfaceSmartPointer& inputManager) 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_InputManager = inputManager.PolymorphicDowncastSmartPointer<InputManagerInterfaceSmartPointer>();

	InitInputManager();
	ResetInputManager();
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager,
										   SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetNetworkManager(MiddleLayerInterfaceSmartPointer& networkManager) 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_NetworkManager = networkManager.PolymorphicDowncastSmartPointer<NetworkManagerInterfaceSmartPointer>();

	InitNetworkManager();
	ResetNetworkManager();
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager,
										   SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetObjectLogicManager(MiddleLayerInterfaceSmartPointer& objectLogicManager) 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_ObjectLogicManager = objectLogicManager.PolymorphicDowncastSmartPointer<ObjectLogicManagerInterfaceSmartPointer>();

	InitObjectLogicManager();
	ResetObjectLogicManager();
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager,
										   SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetPhysicalModellingManager(MiddleLayerInterfaceSmartPointer& physicalModellingManager) 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_PhysicalModellingManager = physicalModellingManager.PolymorphicDowncastSmartPointer<PhysicalModellingManagerInterfaceSmartPointer>();

	InitPhysicalModellingManager();
	ResetPhysicalModellingManager();
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager,
										   SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetMessageManager(MiddleLayerInterfaceSmartPointer& messageManager) 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MessageManager = messageManager.PolymorphicDowncastSmartPointer<MessageManagerInterfaceSmartPointer>();

	InitMessageManager();
	ResetMessageManager();
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager,
										   SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetEventManager(MiddleLayerInterfaceSmartPointer& eventManager) 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_EventManager = eventManager.PolymorphicDowncastSmartPointer<EventManagerInterfaceSmartPointer>();

	InitEventManager();
	ResetEventManager();
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager,
										   SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetSystemManager(MiddleLayerInterfaceSmartPointer& systemManager) 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SystemManager = systemManager.PolymorphicDowncastSmartPointer<SystemManagerInterfaceSmartPointer>();

	InitSystemManager();
	InitSystemEngineInterface();
	ResetSystemManager();
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager,
										   SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetResourceManager(MiddleLayerInterfaceSmartPointer& resourceManager) 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_ResourceManager = resourceManager.PolymorphicDowncastSmartPointer<ResourceManagerInterfaceSmartPointer>();

	InitResourceManager();
	ResetResourceManager();
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager,
										   SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetAudioManager(MiddleLayerInterfaceSmartPointer& audioManager) 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_AudioManager = audioManager.PolymorphicDowncastSmartPointer<AudioManagerInterfaceSmartPointer>();

	InitAudioManager();
	ResetAudioManager();
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager,
										   SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetCameraSystemsManager(MiddleLayerInterfaceSmartPointer& cameraSystemsManager) 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_CameraSystemsManager = cameraSystemsManager.PolymorphicDowncastSmartPointer<CameraSystemsManagerInterfaceSmartPointer>();

	InitCameraSystemsManager();
	ResetCameraSystemsManager();
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager,
										   SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetRenderingManager(MiddleLayerInterfaceSmartPointer& renderingManager) 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_RenderingManager = renderingManager.PolymorphicDowncastSmartPointer<RenderingManagerInterfaceSmartPointer>();

	InitRenderingManager();
	ResetRenderingManager();
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait,InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager,
										   SystemManager, ResourceManager, AudioManager, 
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetGUIManager(MiddleLayerInterfaceSmartPointer& guiManager) 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_GUIManager = guiManager.PolymorphicDowncastSmartPointer<GUIManagerInterfaceSmartPointer>();

	InitGUIManager();
	ResetGUIManager();
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::ResetNetworkManager() 
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	m_InputManager->SetNetworkManager(m_NetworkManager);
	m_ObjectLogicManager->SetNetworkManager(m_NetworkManager);
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::ResetInputManager() 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_NetworkManager->SetInputManager(m_InputManager);
	m_ObjectLogicManager->SetInputManager(m_InputManager);
	m_SystemManager->SetInputManager(m_InputManager);
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::ResetObjectLogicManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_NetworkManager->SetObjectLogicManager(m_ObjectLogicManager);
	m_InputManager->SetObjectLogicManager(m_ObjectLogicManager);
	m_PhysicalModellingManager->SetObjectLogicManager(m_ObjectLogicManager);
	m_MessageManager->SetObjectLogicManager(m_ObjectLogicManager);
	m_SystemManager->SetObjectLogicManager(m_ObjectLogicManager);
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::ResetPhysicalModellingManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

 	m_ObjectLogicManager->SetPhysicalModellingManager(m_PhysicalModellingManager);
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::ResetMessageManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_ObjectLogicManager->SetMessageManager(m_MessageManager);
	m_EventManager->SetMessageManager(m_MessageManager);
	m_SystemManager->SetMessageManager(m_MessageManager);
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::ResetEventManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

 	m_SystemManager->SetEventManager(m_EventManager);
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::ResetSystemManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_InputManager->SetSystemManager(m_SystemManager);
	m_ObjectLogicManager->SetSystemManager(m_SystemManager);
	m_MessageManager->SetSystemManager(m_SystemManager);
	m_EventManager->SetSystemManager(m_SystemManager);
	m_ResourceManager->SetSystemManager(m_SystemManager);
	m_AudioManager->SetSystemManager(m_SystemManager);
	m_CameraSystemsManager->SetSystemManager(m_SystemManager);
	m_RenderingManager->SetSystemManager(m_SystemManager);
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::ResetResourceManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SystemManager->SetResourceManager(m_ResourceManager);
	m_AudioManager->SetResourceManager(m_ResourceManager);
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::ResetAudioManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SystemManager->SetAudioManager(m_AudioManager);
	m_ResourceManager->SetAudioManager(m_AudioManager);
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::ResetCameraSystemsManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

 	m_InputManager->SetCameraSystemsManager(m_CameraSystemsManager);
	m_SystemManager->SetCameraSystemsManager(m_CameraSystemsManager);
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::ResetRenderingManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SystemManager->SetRenderingManager(m_RenderingManager);
	m_ResourceManager->SetRenderingManager(m_RenderingManager);
	m_CameraSystemsManager->SetRenderingManager(m_RenderingManager);
	m_GUIManager->SetRenderingManager(m_RenderingManager);
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::ResetGUIManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_ResourceManager->SetGUIManager(m_GUIManager);
	m_CameraSystemsManager->SetGUIManager(m_GUIManager);
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::PreCreate() 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	 if (ParentType::PreCreate() &&
		 InitSystemEngineInterface() &&
		 m_SystemManager->PreCreate() &&
		 m_NetworkManager->PreCreate() &&
		 m_InputManager->PreCreate() &&
		 m_ObjectLogicManager->PreCreate() &&
		 m_PhysicalModellingManager->PreCreate() &&
		 m_MessageManager->PreCreate() &&
		 m_EventManager->PreCreate() &&
		 m_AudioManager->PreCreate() &&
		 m_ResourceManager->PreCreate() &&
		 m_CameraSystemsManager->PreCreate() &&
		 m_GUIManager->PreCreate() &&
		 m_RenderingManager->PreCreate())
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::Initialize() 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	 if (ParentType::Initialize() &&
		 m_SystemManager->Initialize() &&
		 m_NetworkManager->Initialize() &&
		 m_InputManager->Initialize() &&
		 m_ObjectLogicManager->Initialize() &&
		 m_PhysicalModellingManager->Initialize() &&
		 m_MessageManager->Initialize() &&
		 m_EventManager->Initialize() &&
		 m_AudioManager->Initialize() &&
		 m_ResourceManager->Initialize() &&
		 m_CameraSystemsManager->Initialize() &&
		 m_GUIManager->Initialize() &&
		 m_RenderingManager->Initialize())
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::PreIdle() 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	 ParentType::PreIdle();
	 m_SystemManager->PreIdle();
	 m_NetworkManager->PreIdle();
	 m_InputManager->PreIdle();
	 m_ObjectLogicManager->PreIdle();
	 m_PhysicalModellingManager->PreIdle();
	 m_MessageManager->PreIdle();	
	 m_EventManager->PreIdle();	
	 m_AudioManager->PreIdle();
	 m_ResourceManager->PreIdle();
	 m_CameraSystemsManager->PreIdle();
	 m_GUIManager->PreIdle();
	 m_RenderingManager->PreIdle();
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::Terminate() 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	 ParentType::Terminate();
	 m_NetworkManager->Terminate();
	 m_InputManager->Terminate();
	 m_ObjectLogicManager->Terminate();
	 m_PhysicalModellingManager->Terminate();
	 m_MessageManager->Terminate();
	 m_EventManager->Terminate();
	 m_AudioManager->Terminate();
	 m_ResourceManager->Terminate();
	 m_CameraSystemsManager->Terminate();
	 m_GUIManager->Terminate();
	 m_SystemManager->Terminate();
	 m_RenderingManager->Terminate();
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::Paint() 
{
	FRAMEWORK_CLASS_IS_VALID_1;

	 if (ParentType::Paint() &&
		 m_RenderingManager->Paint())
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }
}


template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::Move(const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	if (ParentType::Move(point) &&
		m_InputManager->Move(point))
	{
		return true;
	}
	else
	{
		return false;							
	}
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::Resize(WindowDisplayFlags type, const WindowSize& size)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	if (ParentType::Resize(type, size) &&
		m_InputManager->Resize(type, size))
	{
		return true;
	}
	else
	{
		return false;							
	}
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::KeyDown(uint8_t key,const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	if (ParentType::KeyDown(key, point) &&
		m_InputManager->KeyDown(key, point))
	{
		return true;
	}
	else
	{
		return false;							
	}
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::KeyUp(uint8_t key,const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	if (ParentType::KeyUp(key, point) &&
		m_InputManager->KeyUp(key, point))
	{
		return true;
	}
	else
	{
		return false;							
	}
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::SpecialKeyDown(int key,const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	if (ParentType::SpecialKeyDown(key, point) &&
		m_InputManager->SpecialKeyDown(key, point))
	{
		return true;
	}
	else
	{
		return false;							
	}
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::SpecialKeyUp(int key,const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	if (ParentType::SpecialKeyUp(key, point) &&
		m_InputManager->SpecialKeyUp(key, point))
	{
		return true;
	}
	else
	{
		return false;							
	}
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::MouseClick(MouseButtonsTypes button,MouseStateTypes state,
			     const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	if (ParentType::MouseClick(button, state, point, virtualKeysTypes) &&
		m_InputManager->MouseClick(button, state, point, virtualKeysTypes))
	{
		return true;
	}
	else
	{
		return false;							
	}
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	if (ParentType::Motion(point, virtualKeysTypes) &&
		m_InputManager->Motion(point, virtualKeysTypes))
	{
		return true;
	}
	else
	{
		return false;							
	}
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	:: PassiveMotion(const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	if (ParentType::PassiveMotion(point) &&
		m_InputManager->PassiveMotion(point))
	{
		return true;
	}
	else
	{
		return false;							
	}
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::MouseWheel(int delta,const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	if (ParentType::MouseWheel(delta, point, virtualKeysTypes) &&
		m_InputManager->MouseWheel(delta, point, virtualKeysTypes))
	{
		return true;
	}
	else
	{
		return false;							
	}
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	:: Create()
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	if (ParentType::Create() &&
		m_SystemManager->Create() &&
		m_NetworkManager->Create() &&
		m_InputManager->Create() &&
		m_ObjectLogicManager->Create() &&
		m_PhysicalModellingManager->Create() &&
		m_MessageManager->Create() &&
		m_EventManager->Create() &&
		m_AudioManager->Create() &&
		m_ResourceManager->Create() &&
		m_CameraSystemsManager->Create() &&
		m_GUIManager->Create() &&
		m_RenderingManager->Create())
	{
		return true;
	}
	else
	{
		return false;							
	}
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	:: Destroy()
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	if (ParentType::Destroy() &&
		m_NetworkManager->Destroy() &&
		m_InputManager->Destroy() &&
		m_ObjectLogicManager->Destroy() &&
		m_PhysicalModellingManager->Destroy() &&
		m_MessageManager->Destroy() &&
		m_EventManager->Destroy() &&
		m_AudioManager->Destroy() &&
		m_ResourceManager->Destroy() &&	
		m_CameraSystemsManager->Destroy() &&
		m_GUIManager->Destroy() &&
		m_RenderingManager->Destroy() &&
		m_SystemManager->Destroy())
	{
		return true;
	}
	else
	{
		return false;							
	}
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, 
                                           PhysicalModellingManager, MessageManager, EventManager, SystemManager,
										   ResourceManager, AudioManager, CameraSystemsManager, 
										   RenderingManager, GUIManager>
	::Idle(int64_t timeDelta)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	if (ParentType::Idle(timeDelta) &&
		m_SystemManager->Idle(timeDelta) &&
		m_NetworkManager->Idle(timeDelta) &&
		m_InputManager->Idle(timeDelta) &&
		m_ObjectLogicManager->Idle(timeDelta) &&
		m_PhysicalModellingManager->Idle(timeDelta) &&
		m_MessageManager->Idle(timeDelta) &&
		m_EventManager->Idle(timeDelta) &&
		m_AudioManager->Idle(timeDelta) &&
		m_ResourceManager->Idle(timeDelta) &&
		m_CameraSystemsManager->Idle(timeDelta) &&
		m_GUIManager->Idle(timeDelta) &&
		m_RenderingManager->Idle(timeDelta))
	{
		return true;
	}
	else
	{
		return false;							
	}
}

template < typename ApplicationTrait,template<typename > class InputManager,typename NetworkManager,typename ObjectLogicManager,typename PhysicalModellingManager,
		   typename MessageManager,typename EventManager,typename SystemManager,typename ResourceManager,
		   typename AudioManager,typename CameraSystemsManager,typename RenderingManager,typename GUIManager >
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, CameraSystemsManager, RenderingManager, GUIManager>
	::InitSystemEngineInterface()
{
	if (SMART_POINTER_SINGLETON.IsSmartPointer(this))
	{
		MiddleLayerInterfaceSmartPointer self(this);

		m_SystemManager->SetEngineManager(self);

		return true;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("´íÎóµÄ¿ò¼Ü"));
	}
}

#endif // FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_DETAIL_H

