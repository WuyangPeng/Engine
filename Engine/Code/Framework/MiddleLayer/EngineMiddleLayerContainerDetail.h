// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:42)

#ifndef FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_DETAIL_H

#include "EngineMiddleLayerContainer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
									  MessageManager, EventManager, SystemManager, ResourceManager,
									  AudioManager, CameraSystemsManager, RenderingManager, GUIManager>
	::EngineMiddleLayerContainer(MiddleLayerPlatform modelViewController)
	:ParentType{ modelViewController },
	 m_NetworkManager{ std::make_shared<NetworkManagerType>(modelViewController) },
	 m_InputManager{ std::make_shared<InputManagerType>(modelViewController) },
	 m_ObjectLogicManager{ std::make_shared<ObjectLogicManagerType>(modelViewController) },
	 m_PhysicalModellingManager{ std::make_shared<PhysicalModellingManagerType>(modelViewController) },
	 m_MessageManager{ std::make_shared<MessageManagerType>(modelViewController) },
	 m_EventManager{ std::make_shared<EventManagerType>(modelViewController) },
	 m_SystemManager{ std::make_shared<SystemManagerType>(modelViewController) },
	 m_ResourceManager{ std::make_shared<ResourceManagerType>(modelViewController) },
	 m_AudioManager{ std::make_shared<AudioManagerType>(modelViewController) },
	 m_CameraSystemsManager{ std::make_shared<CameraSystemsManagerType>(modelViewController) },
	 m_RenderingManager{ std::make_shared<RenderingManagerType>(modelViewController) },
	 m_GUIManager{ std::make_shared<GUIManagerType>(modelViewController) }
{
	Init();

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// private
template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
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
template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitNetworkManager()
{
	m_NetworkManager->SetInputManager(m_InputManager);
	m_NetworkManager->SetObjectLogicManager(m_ObjectLogicManager);
}

// private
template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
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
template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
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
template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitPhysicalModellingManager()
{
	m_PhysicalModellingManager->SetObjectLogicManager(m_ObjectLogicManager);
}

// private
template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitMessageManager()
{
	m_MessageManager->SetObjectLogicManager(m_ObjectLogicManager);
	m_MessageManager->SetSystemManager(m_SystemManager);
}

// private
template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitEventManager()
{
	m_EventManager->SetMessageManager(m_MessageManager);
	m_EventManager->SetSystemManager(m_SystemManager);
}

// private
template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
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
template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
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
template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitAudioManager()
{
	m_AudioManager->SetSystemManager(m_SystemManager);
	m_AudioManager->SetResourceManager(m_ResourceManager);
}


// private
template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitCameraSystemsManager()
{
	m_CameraSystemsManager->SetSystemManager(m_SystemManager);
	m_CameraSystemsManager->SetRenderingManager(m_RenderingManager);
	m_CameraSystemsManager->SetGUIManager(m_GUIManager);
}

// private
template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitRenderingManager()
{
	m_RenderingManager->SetSystemManager(m_SystemManager);
}

// private
template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitGUIManager()
{
	m_GUIManager->SetRenderingManager(m_RenderingManager);
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
									  MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
									  CameraSystemsManager, RenderingManager, GUIManager>
	::~EngineMiddleLayerContainer()
{
	CoreTools::NoexceptNoReturn(*this, &ClassType::SetEngineManagerNullptr);

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// private
template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										  CameraSystemsManager, RenderingManager, GUIManager>
	::SetEngineManagerNullptr()
{
	MiddleLayerInterfaceSharedPtr nullPointer;

	m_SystemManager->SetEngineManager(nullPointer);
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
									  MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
									  CameraSystemsManager, RenderingManager, GUIManager>
	::EngineMiddleLayerContainer(EngineMiddleLayerContainer&& rhs) noexcept
	:ParentType{ std::move(rhs) },
	 m_NetworkManager{ std::move(rhs.m_NetworkManager) },
	 m_InputManager{ std::move(rhs.m_InputManager) },
	 m_ObjectLogicManager{ std::move(rhs.m_ObjectLogicManager) },
	 m_PhysicalModellingManager{ std::move(rhs.m_PhysicalModellingManager) },
	 m_MessageManager{ std::move(rhs.m_MessageManager) },
	 m_EventManager{ std::move(rhs.m_EventManager) },
	 m_SystemManager{ std::move(rhs.m_SystemManager) },
	 m_ResourceManager{ std::move(rhs.m_ResourceManager) },
	 m_AudioManager{ std::move(rhs.m_AudioManager) },
	 m_CameraSystemsManager{ std::move(rhs.m_CameraSystemsManager) },
	 m_RenderingManager{ std::move(rhs.m_RenderingManager) },
	 m_GUIManager{ std::move(rhs.m_GUIManager) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager> 
Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, CameraSystemsManager, RenderingManager, GUIManager>&
	Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager, MessageManager, EventManager, SystemManager, ResourceManager, AudioManager, CameraSystemsManager, RenderingManager, GUIManager>
	::operator=(EngineMiddleLayerContainer&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::operator=(std::move(rhs));
	m_NetworkManager = std::move(rhs.m_NetworkManager);
	m_InputManager = std::move(rhs.m_InputManager);
	m_ObjectLogicManager = std::move(rhs.m_ObjectLogicManager);
	m_PhysicalModellingManager = std::move(rhs.m_PhysicalModellingManager);
	m_MessageManager = std::move(rhs.m_MessageManager);
	m_EventManager = std::move(rhs.m_EventManager);
	m_SystemManager = std::move(rhs.m_SystemManager);
	m_ResourceManager = std::move(rhs.m_ResourceManager);
	m_AudioManager = std::move(rhs.m_AudioManager);
	m_CameraSystemsManager = std::move(rhs.m_CameraSystemsManager);
	m_RenderingManager = std::move(rhs.m_RenderingManager);
	m_GUIManager = std::move(rhs.m_GUIManager);

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() &&
		m_NetworkManager != nullptr&&
		m_InputManager != nullptr &&
		m_ObjectLogicManager != nullptr &&
		m_PhysicalModellingManager != nullptr &&
		m_MessageManager != nullptr &&
		m_EventManager != nullptr &&
		m_SystemManager != nullptr &&
		m_ResourceManager != nullptr &&
		m_AudioManager != nullptr &&
		m_CameraSystemsManager != nullptr &&
		m_RenderingManager != nullptr &&
		m_GUIManager != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetInputManager(const MiddleLayerInterfaceSharedPtr& inputManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto manager = inputManager;

	m_InputManager = boost::polymorphic_pointer_downcast<InputManagerInterface>(manager);

	InitInputManager();
	ResetInputManager();
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetNetworkManager(const MiddleLayerInterfaceSharedPtr& networkManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto manager = networkManager;

	m_NetworkManager = boost::polymorphic_pointer_downcast<NetworkManagerInterface>(manager);

	InitNetworkManager();
	ResetNetworkManager();
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetObjectLogicManager(const MiddleLayerInterfaceSharedPtr& objectLogicManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto manager = objectLogicManager;

	m_ObjectLogicManager = boost::polymorphic_pointer_downcast<ObjectLogicManagerInterface>(manager);

	InitObjectLogicManager();
	ResetObjectLogicManager();
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetPhysicalModellingManager(const MiddleLayerInterfaceSharedPtr& physicalModellingManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto manager = physicalModellingManager;

	m_PhysicalModellingManager = boost::polymorphic_pointer_downcast<PhysicalModellingManagerInterface>(manager);

	InitPhysicalModellingManager();
	ResetPhysicalModellingManager();
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetMessageManager(const MiddleLayerInterfaceSharedPtr& messageManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto manager = messageManager;

	m_MessageManager = boost::polymorphic_pointer_downcast<MessageManagerInterface>(manager);

	InitMessageManager();
	ResetMessageManager();
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetEventManager(const MiddleLayerInterfaceSharedPtr& eventManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto manager = eventManager;

	m_EventManager = boost::polymorphic_pointer_downcast<EventManagerInterface>(manager);

	InitEventManager();
	ResetEventManager();
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetSystemManager(const MiddleLayerInterfaceSharedPtr& systemManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto manager = systemManager;

	m_SystemManager = boost::polymorphic_pointer_downcast<SystemManagerInterface>(manager);

	InitSystemManager();
	InitSystemEngineInterface();
	ResetSystemManager();
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetResourceManager(const MiddleLayerInterfaceSharedPtr& resourceManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto manager = resourceManager;

	m_ResourceManager = boost::polymorphic_pointer_downcast<ResourceManagerInterface>(manager);

	InitResourceManager();
	ResetResourceManager();
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetAudioManager(const MiddleLayerInterfaceSharedPtr& audioManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto manager = audioManager;

	m_AudioManager = boost::polymorphic_pointer_downcast<AudioManagerInterface>(manager);

	InitAudioManager();
	ResetAudioManager();
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetCameraSystemsManager(const MiddleLayerInterfaceSharedPtr& cameraSystemsManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto manager = cameraSystemsManager;

	m_CameraSystemsManager = boost::polymorphic_pointer_downcast<CameraSystemsManagerInterface>(manager);

	InitCameraSystemsManager();
	ResetCameraSystemsManager();
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetRenderingManager(const MiddleLayerInterfaceSharedPtr& renderingManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto manager = renderingManager;

	m_RenderingManager = boost::polymorphic_pointer_downcast<RenderingManagerInterface>(manager);

	InitRenderingManager();
	ResetRenderingManager();
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SetGUIManager(const MiddleLayerInterfaceSharedPtr& guiManager)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto manager = guiManager;

	m_GUIManager = boost::polymorphic_pointer_downcast<GUIManagerInterface>(manager);

	InitGUIManager();
	ResetGUIManager();
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::ResetNetworkManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_InputManager->SetNetworkManager(m_NetworkManager);
	m_ObjectLogicManager->SetNetworkManager(m_NetworkManager);
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::ResetInputManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_NetworkManager->SetInputManager(m_InputManager);
	m_ObjectLogicManager->SetInputManager(m_InputManager);
	m_SystemManager->SetInputManager(m_InputManager);
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::ResetObjectLogicManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_NetworkManager->SetObjectLogicManager(m_ObjectLogicManager);
	m_InputManager->SetObjectLogicManager(m_ObjectLogicManager);
	m_PhysicalModellingManager->SetObjectLogicManager(m_ObjectLogicManager);
	m_MessageManager->SetObjectLogicManager(m_ObjectLogicManager);
	m_SystemManager->SetObjectLogicManager(m_ObjectLogicManager);
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::ResetPhysicalModellingManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_ObjectLogicManager->SetPhysicalModellingManager(m_PhysicalModellingManager);
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::ResetMessageManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_ObjectLogicManager->SetMessageManager(m_MessageManager);
	m_EventManager->SetMessageManager(m_MessageManager);
	m_SystemManager->SetMessageManager(m_MessageManager);
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::ResetEventManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SystemManager->SetEventManager(m_EventManager);
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
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

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::ResetResourceManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SystemManager->SetResourceManager(m_ResourceManager);
	m_AudioManager->SetResourceManager(m_ResourceManager);
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::ResetAudioManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SystemManager->SetAudioManager(m_AudioManager);
	m_ResourceManager->SetAudioManager(m_AudioManager);
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::ResetCameraSystemsManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_InputManager->SetCameraSystemsManager(m_CameraSystemsManager);
	m_SystemManager->SetCameraSystemsManager(m_CameraSystemsManager);
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::ResetRenderingManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SystemManager->SetRenderingManager(m_RenderingManager);
	m_ResourceManager->SetRenderingManager(m_RenderingManager);
	m_CameraSystemsManager->SetRenderingManager(m_RenderingManager);
	m_GUIManager->SetRenderingManager(m_RenderingManager);
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::ResetGUIManager()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_ResourceManager->SetGUIManager(m_GUIManager);
	m_CameraSystemsManager->SetGUIManager(m_GUIManager);
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::PreCreate(environmentDirectory) &&
		InitSystemEngineInterface() &&
		m_SystemManager->PreCreate(environmentDirectory) &&
		m_NetworkManager->PreCreate(environmentDirectory) &&
		m_InputManager->PreCreate(environmentDirectory) &&
		m_ObjectLogicManager->PreCreate(environmentDirectory) &&
		m_PhysicalModellingManager->PreCreate(environmentDirectory) &&
		m_MessageManager->PreCreate(environmentDirectory) &&
		m_EventManager->PreCreate(environmentDirectory) &&
		m_AudioManager->PreCreate(environmentDirectory) &&
		m_ResourceManager->PreCreate(environmentDirectory) &&
		m_CameraSystemsManager->PreCreate(environmentDirectory) &&
		m_GUIManager->PreCreate(environmentDirectory) &&
		m_RenderingManager->PreCreate(environmentDirectory))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
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

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
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

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
void Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
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

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
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

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::Move(const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::Move(point) &&
		m_RenderingManager->Move(point))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::Resize(windowDisplay, size) &&
		m_RenderingManager->Resize(windowDisplay, size))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::KeyDown(int key, const WindowPoint& point)
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

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::KeyUp(int key, const WindowPoint& point)
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

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SpecialKeyDown(int key, const WindowPoint& point)
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

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::SpecialKeyUp(int key, const WindowPoint& point)
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

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::MouseClick(MouseButtonsTypes button, MouseStateTypes state,
				 const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::MouseClick(button, state, point, virtualKeys) &&
		m_InputManager->MouseClick(button, state, point, virtualKeys))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::Motion(point, virtualKeys) &&
		m_InputManager->Motion(point, virtualKeys))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::PassiveMotion(const WindowPoint& point)
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

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::MouseWheel(delta, point, virtualKeys) &&
		m_InputManager->MouseWheel(delta, point, virtualKeys))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::Create()
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

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::Destroy()
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

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
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

template <typename ApplicationTrait, template<typename> class InputManager, typename NetworkManager, typename ObjectLogicManager, typename PhysicalModellingManager,
		  typename MessageManager, typename EventManager, typename SystemManager, typename ResourceManager,
		  typename AudioManager, typename CameraSystemsManager, typename RenderingManager, typename GUIManager>
bool Framework::EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager, PhysicalModellingManager,
										   MessageManager, EventManager, SystemManager, ResourceManager, AudioManager,
										   CameraSystemsManager, RenderingManager, GUIManager>
	::InitSystemEngineInterface()
{
	m_SystemManager->SetEngineManager(shared_from_this());

	return true;
}

#endif // FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_DETAIL_H

