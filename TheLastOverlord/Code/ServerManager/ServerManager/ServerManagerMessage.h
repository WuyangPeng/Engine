// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 16:35)

#ifndef SERVER_MANAGER_SERVER_MANAGER_MESSAGE_H
#define SERVER_MANAGER_SERVER_MANAGER_MESSAGE_H

#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "Framework/WindowProcess/WindowMessage.h"
#include "CoreTools/Console/ConsoleAlloc.h" 
#include "ServerManager/ServerManagerMiddleLayer/Input/InputManager.h"
#include "ServerManager/ServerManagerMiddleLayer/Network/NetworkManager.h"
#include "ServerManager/ServerManagerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "ServerManager/ServerManagerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "ServerManager/ServerManagerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "ServerManager/ServerManagerMiddleLayer/Message/MessageManager.h"
#include "ServerManager/ServerManagerMiddleLayer/Event/EventManager.h"
#include "ServerManager/ServerManagerMiddleLayer/System/SystemManager.h"
#include "ServerManager/ServerManagerMiddleLayer/Resource/ResourceManager.h"	
#include "ServerManager/ServerManagerMiddleLayer/Audio/AudioManager.h"												 
#include "ServerManager/ServerManagerMiddleLayer/CameraSystems/CameraSystemsManager.h"	
#include "ServerManager/ServerManagerMiddleLayer/Rendering/RenderingManager.h"												 
#include "ServerManager/ServerManagerMiddleLayer/GUI/GUIManager.h"

namespace ServerManager
{
	using ObjectLogicManager = Framework::ObjectLogicManager<ServerManagerMiddleLayer::ObjectLogicManager, ServerManagerMiddleLayer::ArtificialIntellegenceManager>;
	using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
																  ServerManagerMiddleLayer::InputManager,
		                                                          ServerManagerMiddleLayer::NetworkManager,
																  ObjectLogicManager,
																  ServerManagerMiddleLayer::PhysicalModellingManager,
																  ServerManagerMiddleLayer::MessageManager,		
																  ServerManagerMiddleLayer::EventManager, 
																  ServerManagerMiddleLayer::SystemManager,
																  ServerManagerMiddleLayer::ResourceManager,
																  ServerManagerMiddleLayer::AudioManager,
																  ServerManagerMiddleLayer::CameraSystemsManager,
																  ServerManagerMiddleLayer::RenderingManager,
																  ServerManagerMiddleLayer::GUIManager>;
	using MessageType = Framework::WindowMessage<MiddleLayerType>;

	class ServerManagerMessage : public MessageType
	{
	public:
		using ClassType = ServerManagerMessage;
		using ParentType = MessageType;

	public:
		ServerManagerMessage(int64_t delta);
		virtual ~ServerManagerMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		CoreTools::ConsoleAlloc m_Alloc;
	};

	using ServerManagerMessageWindowProcessHandle = Framework::WindowProcessHandle<ServerManagerMessage>;
}

#endif // SERVER_MANAGER_SERVER_MANAGER_MESSAGE_H
