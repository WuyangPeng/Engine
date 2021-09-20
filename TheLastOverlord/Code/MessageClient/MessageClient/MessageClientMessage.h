// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 16:26)

#ifndef MESSAGE_CLIENT_MESSAGE_CLIENT_MESSAGE_H
#define MESSAGE_CLIENT_MESSAGE_CLIENT_MESSAGE_H

#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "Framework/WindowProcess/WindowMessage.h"
#include "CoreTools/Console/ConsoleAlloc.h" 
#include "MessageClient/MessageClientMiddleLayer/Input/InputManager.h"
#include "MessageClient/MessageClientMiddleLayer/Network/NetworkManager.h"
#include "MessageClient/MessageClientMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "MessageClient/MessageClientMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "MessageClient/MessageClientMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "MessageClient/MessageClientMiddleLayer/Message/MessageManager.h"
#include "MessageClient/MessageClientMiddleLayer/Event/EventManager.h"
#include "MessageClient/MessageClientMiddleLayer/System/SystemManager.h"
#include "MessageClient/MessageClientMiddleLayer/Resource/ResourceManager.h"	
#include "MessageClient/MessageClientMiddleLayer/Audio/AudioManager.h"												 
#include "MessageClient/MessageClientMiddleLayer/CameraSystems/CameraSystemsManager.h"	
#include "MessageClient/MessageClientMiddleLayer/Rendering/RenderingManager.h"												 
#include "MessageClient/MessageClientMiddleLayer/GUI/GUIManager.h"

namespace MessageClient
{
	using ObjectLogicManager = Framework::ObjectLogicManager<MessageClientMiddleLayer::ObjectLogicManager, MessageClientMiddleLayer::ArtificialIntellegenceManager>;
	using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
																  MessageClientMiddleLayer::InputManager,
		                                                          MessageClientMiddleLayer::NetworkManager,
																  ObjectLogicManager,
																  MessageClientMiddleLayer::PhysicalModellingManager,
																  MessageClientMiddleLayer::MessageManager,		
																  MessageClientMiddleLayer::EventManager, 
																  MessageClientMiddleLayer::SystemManager,
																  MessageClientMiddleLayer::ResourceManager,
																  MessageClientMiddleLayer::AudioManager,
																  MessageClientMiddleLayer::CameraSystemsManager,
																  MessageClientMiddleLayer::RenderingManager,
																  MessageClientMiddleLayer::GUIManager>;
	using MessageType = Framework::WindowMessage<MiddleLayerType>;

	class MessageClientMessage : public MessageType
	{
	public:
		using ClassType = MessageClientMessage;
		using ParentType = MessageType;

	public:
		MessageClientMessage(int64_t delta);
		virtual ~MessageClientMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		CoreTools::ConsoleAlloc m_Alloc;
	};

	using MessageClientMessageWindowProcessHandle = Framework::WindowProcessHandle<MessageClientMessage>;
}

#endif // MESSAGE_CLIENT_MESSAGE_CLIENT_MESSAGE_H
