// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 17:47)

#ifndef BACKGROUND_CLIENT_BACKGROUND_CLIENT_MESSAGE_H
#define BACKGROUND_CLIENT_BACKGROUND_CLIENT_MESSAGE_H

#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "Framework/WindowProcess/WindowMessage.h"
#include "CoreTools/Console/ConsoleAlloc.h" 
#include "BackgroundClient/BackgroundClientMiddleLayer/Input/InputManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/Network/NetworkManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/Message/MessageManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/Event/EventManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/System/SystemManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/Resource/ResourceManager.h"	
#include "BackgroundClient/BackgroundClientMiddleLayer/Audio/AudioManager.h"												 
#include "BackgroundClient/BackgroundClientMiddleLayer/CameraSystems/CameraSystemsManager.h"	
#include "BackgroundClient/BackgroundClientMiddleLayer/Rendering/RenderingManager.h"												 
#include "BackgroundClient/BackgroundClientMiddleLayer/GUI/GUIManager.h"

namespace BackgroundClient
{
	using ObjectLogicManager = Framework::ObjectLogicManager<BackgroundClientMiddleLayer::ObjectLogicManager, BackgroundClientMiddleLayer::ArtificialIntellegenceManager>;
	using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
																  BackgroundClientMiddleLayer::InputManager,
		                                                          BackgroundClientMiddleLayer::NetworkManager,
																  ObjectLogicManager,
																  BackgroundClientMiddleLayer::PhysicalModellingManager,
																  BackgroundClientMiddleLayer::MessageManager,		
																  BackgroundClientMiddleLayer::EventManager, 
																  BackgroundClientMiddleLayer::SystemManager,
																  BackgroundClientMiddleLayer::ResourceManager,
																  BackgroundClientMiddleLayer::AudioManager,
																  BackgroundClientMiddleLayer::CameraSystemsManager,
																  BackgroundClientMiddleLayer::RenderingManager,
																  BackgroundClientMiddleLayer::GUIManager>;
	using MessageType = Framework::WindowMessage<MiddleLayerType>;

	class BackgroundClientMessage : public MessageType
	{
	public:
		using ClassType = BackgroundClientMessage;
		using ParentType = MessageType;

	public:
		explicit BackgroundClientMessage(int64_t delta);
		virtual ~BackgroundClientMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		CoreTools::ConsoleAlloc m_Alloc;
	};

	using BackgroundClientMessageWindowProcessHandle = Framework::WindowProcessHandle<BackgroundClientMessage>;
}

#endif // BACKGROUND_CLIENT_BACKGROUND_CLIENT_MESSAGE_H
