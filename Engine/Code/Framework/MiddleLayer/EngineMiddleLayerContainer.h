// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 14:48)

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
	// �����Ϸϵͳ��������Ϊ���������������������������߼�������ģ�⡢
	// ��Ϣ���������¼���������ϵͳ����������Դ��������
	// ��Ƶ�����������ϵͳ����Ⱦ��������GUI���������ɡ�
	template <typename ApplicationTrait,
			  template<typename> class InputManager = InputManager,
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
		static_assert(std::is_base_of_v<InputManagerInterface, InputManagerType>);
		static_assert(std::is_base_of_v<NetworkManagerInterface, NetworkManagerType>);
		static_assert(std::is_base_of_v<ObjectLogicManagerInterface, ObjectLogicManagerType>);
		static_assert(std::is_base_of_v<PhysicalModellingManagerInterface, PhysicalModellingManagerType>);
		static_assert(std::is_base_of_v<MessageManagerInterface, MessageManagerType>);
		static_assert(std::is_base_of_v<EventManagerInterface, EventManagerType>);
		static_assert(std::is_base_of_v<SystemManagerInterface, SystemManagerType>);
		static_assert(std::is_base_of_v<ResourceManagerInterface, ResourceManagerType>);
		static_assert(std::is_base_of_v<AudioManagerInterface, AudioManagerType>);
		static_assert(std::is_base_of_v<CameraSystemsManagerInterface, CameraSystemsManagerType>);
		static_assert(std::is_base_of_v<RenderingManagerInterface, RenderingManagerType>);
		static_assert(std::is_base_of_v<GUIManagerInterface, GUIManagerType>);

	public:
		explicit EngineMiddleLayerContainer(MiddleLayerPlatform modelViewController);
		~EngineMiddleLayerContainer();
		EngineMiddleLayerContainer(const EngineMiddleLayerContainer& rhs) noexcept = delete;
		EngineMiddleLayerContainer& operator=(const EngineMiddleLayerContainer& rhs) noexcept = delete;
		EngineMiddleLayerContainer(EngineMiddleLayerContainer&& rhs) noexcept;
		EngineMiddleLayerContainer& operator=(EngineMiddleLayerContainer&& rhs) noexcept;

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void SetNetworkManager(const MiddleLayerInterfaceSharedPtr& networkManager) override;
		void SetInputManager(const MiddleLayerInterfaceSharedPtr& inputManager) override;
		void SetObjectLogicManager(const MiddleLayerInterfaceSharedPtr& objectLogicManager) override;
		void SetPhysicalModellingManager(const MiddleLayerInterfaceSharedPtr& physicalModellingManager) override;
		void SetMessageManager(const MiddleLayerInterfaceSharedPtr& messageManager) override;
		void SetEventManager(const MiddleLayerInterfaceSharedPtr& eventManager) override;
		void SetSystemManager(const MiddleLayerInterfaceSharedPtr& systemManager) override;
		void SetResourceManager(const MiddleLayerInterfaceSharedPtr& resourceManager) override;
		void SetAudioManager(const MiddleLayerInterfaceSharedPtr& audioManager) override;
		void SetCameraSystemsManager(const MiddleLayerInterfaceSharedPtr& cameraSystemsManager) override;
		void SetRenderingManager(const MiddleLayerInterfaceSharedPtr& renderingManager) override;
		void SetGUIManager(const MiddleLayerInterfaceSharedPtr& guiManager) override;

		bool PreCreate(const EnvironmentDirectory& environmentDirectory) override;
		bool Initialize() override;
		void PreIdle() override;
		void Terminate() override;
		bool Paint() override;
		bool Move(const WindowPoint& point) override;
		bool Resize(WindowDisplay windowDisplay, const WindowSize& size) override;
		bool KeyDown(int key, const WindowPoint& point) override;
		bool KeyUp(int key, const WindowPoint& point) override;
		bool SpecialKeyDown(int key, const WindowPoint& point) override;
		bool SpecialKeyUp(int key, const WindowPoint& point) override;
		bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) override;
		bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) override;
		bool PassiveMotion(const WindowPoint& point) override;
		bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) override;
		bool Create() override;
		bool Destroy() override;
		bool Idle(int64_t timeDelta) override;

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

		void SetEngineManagerNullptr();

	private:
		NetworkManagerInterfaceSharedPtr m_NetworkManager;
		InputManagerInterfaceSharedPtr m_InputManager;
		ObjectLogicManagerInterfaceSharedPtr m_ObjectLogicManager;
		PhysicalModellingManagerInterfaceSharedPtr m_PhysicalModellingManager;
		MessageManagerInterfaceSharedPtr m_MessageManager;
		EventManagerInterfaceSharedPtr m_EventManager;
		SystemManagerInterfaceSharedPtr m_SystemManager;
		ResourceManagerInterfaceSharedPtr m_ResourceManager;
		AudioManagerInterfaceSharedPtr m_AudioManager;
		CameraSystemsManagerInterfaceSharedPtr m_CameraSystemsManager;
		RenderingManagerInterfaceSharedPtr m_RenderingManager;
		GUIManagerInterfaceSharedPtr m_GUIManager;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_CONTAINER_H

