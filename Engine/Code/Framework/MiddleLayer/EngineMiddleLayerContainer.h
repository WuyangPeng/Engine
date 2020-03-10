// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:40)

#ifndef FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_H
#define FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_H

#include "EngineMiddleLayerInterface.h"
#include "InputManager.h"
#include "NetworkManagerInterface.h"
#include "ObjectLogicManagerInterface.h"
#include "PhysicalModellingManagerInterface.h"
#include "MessageManagerInterface.h"
#include "EventManagerInterface.h"
#include "SystemManagerInterface.h"
#include "ResourceManagerInterface.h"
#include "AudioManagerInterface.h"
#include "CameraSystemsManagerInterface.h"
#include "RenderingManagerInterface.h"
#include "GUIManagerInterface.h"

#include <type_traits> 

namespace Framework
{
	// 这个游戏系统管理器分为输入管理器、网络管理器、对象逻辑、物理模拟、
	// 消息管理器、事件管理器、系统管理器、资源管理器、
	// 音频管理器、相机系统、渲染管理器、GUI管理器构成。
	template <typename ApplicationTrait,
			  template<typename > class InputManager = InputManager,
			  typename NetworkManager = NetworkManagerInterface,
			  typename ObjectLogicManager = ObjectLogicManagerInterface,
			  typename PhysicalModellingManager = PhysicalModellingManagerInterface,
			  typename MessageManager = MessageManagerInterface,
			  typename EventManager = EventManagerInterface,
			  typename SystemManager = SystemManagerInterface,
			  typename ResourceManager = ResourceManagerInterface,
			  typename AudioManager = AudioManagerInterface,
			  typename CameraSystemsManager = CameraSystemsManagerInterface,
			  typename RenderingManager = RenderingManagerInterface,
			  typename GUIManager = GUIManagerInterface>
	class EngineMiddleLayerContainer : public EngineMiddleLayerInterface
	{	
	public:
		using ClassType = EngineMiddleLayerContainer<ApplicationTrait, InputManager, NetworkManager, ObjectLogicManager,
													 PhysicalModellingManager, MessageManager, EventManager,
													 SystemManager, ResourceManager, AudioManager,
													 CameraSystemsManager, RenderingManager, GUIManager>;
		using ParentType = EngineMiddleLayerInterface;
		using InputManagerType = InputManager<ApplicationTrait>;
		using NetworkManagerType = NetworkManager;
		using ObjectLogicManagerType = ObjectLogicManager;
		using PhysicalModellingManagerType = PhysicalModellingManager;
		using MessageManagerType = MessageManager;
		using EventManagerType = EventManager;
		using SystemManagerType = SystemManager;
		using ResourceManagerType = ResourceManager;
		using AudioManagerType = AudioManager;
		using CameraSystemsManagerType = CameraSystemsManager;
		using RenderingManagerType = RenderingManager;
		using GUIManagerType = GUIManager;

	public:
		static_assert(std::is_base_of_v<InputManagerInterface,InputManagerType>);
		static_assert(std::is_base_of_v<NetworkManagerInterface,NetworkManagerType>);
		static_assert(std::is_base_of_v<ObjectLogicManagerInterface,ObjectLogicManagerType>);
		static_assert(std::is_base_of_v<PhysicalModellingManagerInterface,PhysicalModellingManagerType>);
		static_assert(std::is_base_of_v<MessageManagerInterface,MessageManagerType>);
		static_assert(std::is_base_of_v<EventManagerInterface,EventManagerType>);
		static_assert(std::is_base_of_v<SystemManagerInterface,SystemManagerType>);
		static_assert(std::is_base_of_v<ResourceManagerInterface,ResourceManagerType>);
		static_assert(std::is_base_of_v<AudioManagerInterface,AudioManagerType>);
		static_assert(std::is_base_of_v<CameraSystemsManagerInterface,CameraSystemsManagerType>);
		static_assert(std::is_base_of_v<RenderingManagerInterface,RenderingManagerType>);
		static_assert(std::is_base_of_v<GUIManagerInterface,GUIManagerType>);

	public:
		EngineMiddleLayerContainer();
		virtual ~EngineMiddleLayerContainer();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void SetNetworkManager(MiddleLayerInterfaceSmartPointer& networkManager);
		void SetInputManager(MiddleLayerInterfaceSmartPointer& inputManager);
		void SetObjectLogicManager(MiddleLayerInterfaceSmartPointer& objectLogicManager);
		void SetPhysicalModellingManager(MiddleLayerInterfaceSmartPointer& physicalModellingManager);
		void SetMessageManager(MiddleLayerInterfaceSmartPointer& messageManager);
		void SetEventManager(MiddleLayerInterfaceSmartPointer& eventManager);
		void SetSystemManager(MiddleLayerInterfaceSmartPointer& systemManager);
		void SetResourceManager(MiddleLayerInterfaceSmartPointer& resourceManager);
		void SetAudioManager(MiddleLayerInterfaceSmartPointer& audioManager);
		void SetCameraSystemsManager(MiddleLayerInterfaceSmartPointer& cameraSystemsManager);
		void SetRenderingManager(MiddleLayerInterfaceSmartPointer& renderingManager);
		void SetGUIManager(MiddleLayerInterfaceSmartPointer& guiManager);

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();
		virtual bool Paint();
		virtual bool Move(const WindowPoint& point);
		virtual bool Resize(WindowDisplayFlags type,const WindowSize& size);
		virtual bool KeyDown(uint8_t key,const WindowPoint& point);
	    virtual bool KeyUp(uint8_t key, const WindowPoint& point);
		virtual bool SpecialKeyDown (int key, const WindowPoint& point);
		virtual bool SpecialKeyUp (int key, const WindowPoint& point);
		virtual bool MouseClick(MouseButtonsTypes button,MouseStateTypes state, const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes);
		virtual bool Motion(const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes);
		virtual bool PassiveMotion(const WindowPoint& point);
		virtual bool MouseWheel(int delta,const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes);
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);

	private:
		void Init();
		void InitNetworkManager();
		void InitInputManager();
		void InitObjectLogicManager();
		void InitPhysicalModellingManager();
		void InitMessageManager();
		void InitEventManager();
		void InitSystemManager();
		void InitResourceManager();
		void InitAudioManager();
		void InitCameraSystemsManager();
		void InitRenderingManager();
		void InitGUIManager();

		void ResetNetworkManager();
		void ResetInputManager();
		void ResetObjectLogicManager();
		void ResetPhysicalModellingManager();
		void ResetMessageManager();
		void ResetEventManager();
		void ResetSystemManager();
		void ResetResourceManager();
		void ResetAudioManager();
		void ResetCameraSystemsManager();
		void ResetRenderingManager();
		void ResetGUIManager();

		bool InitSystemEngineInterface();

	private:
		NetworkManagerInterfaceSmartPointer m_NetworkManager;
		InputManagerInterfaceSmartPointer m_InputManager;
		ObjectLogicManagerInterfaceSmartPointer m_ObjectLogicManager;
		PhysicalModellingManagerInterfaceSmartPointer m_PhysicalModellingManager;
		MessageManagerInterfaceSmartPointer m_MessageManager;
		EventManagerInterfaceSmartPointer m_EventManager;
		SystemManagerInterfaceSmartPointer m_SystemManager;
		ResourceManagerInterfaceSmartPointer m_ResourceManager;
		AudioManagerInterfaceSmartPointer m_AudioManager;
		CameraSystemsManagerInterfaceSmartPointer m_CameraSystemsManager;
		RenderingManagerInterfaceSmartPointer m_RenderingManager;
		GUIManagerInterfaceSmartPointer m_GUIManager;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_H

