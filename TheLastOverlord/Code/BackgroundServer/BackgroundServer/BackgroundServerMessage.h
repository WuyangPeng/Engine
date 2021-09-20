// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:05)

#ifndef BACKGROUND_SERVER_BACKGROUND_SERVER_MESSAGE_H
#define BACKGROUND_SERVER_BACKGROUND_SERVER_MESSAGE_H

#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "Framework/WindowProcess/WindowMessage.h"
#include "CoreTools/Console/ConsoleAlloc.h" 
#include "BackgroundServer/BackgroundServerMiddleLayer/Input/InputManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/Network/NetworkManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/Message/MessageManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/Event/EventManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/System/SystemManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/Resource/ResourceManager.h"	
#include "BackgroundServer/BackgroundServerMiddleLayer/Audio/AudioManager.h"												 
#include "BackgroundServer/BackgroundServerMiddleLayer/CameraSystems/CameraSystemsManager.h"	
#include "BackgroundServer/BackgroundServerMiddleLayer/Rendering/RenderingManager.h"												 
#include "BackgroundServer/BackgroundServerMiddleLayer/GUI/GUIManager.h"

namespace BackgroundServer
{
	using ObjectLogicManager = Framework::ObjectLogicManager<BackgroundServerMiddleLayer::ObjectLogicManager, BackgroundServerMiddleLayer::ArtificialIntellegenceManager>;
	using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
																  BackgroundServerMiddleLayer::InputManager,
		                                                          BackgroundServerMiddleLayer::NetworkManager,
																  ObjectLogicManager,
																  BackgroundServerMiddleLayer::PhysicalModellingManager,
																  BackgroundServerMiddleLayer::MessageManager,		
																  BackgroundServerMiddleLayer::EventManager, 
																  BackgroundServerMiddleLayer::SystemManager,
																  BackgroundServerMiddleLayer::ResourceManager,
																  BackgroundServerMiddleLayer::AudioManager,
																  BackgroundServerMiddleLayer::CameraSystemsManager,
																  BackgroundServerMiddleLayer::RenderingManager,
																  BackgroundServerMiddleLayer::GUIManager>;
	using MessageType = Framework::WindowMessage<MiddleLayerType>;

	class BackgroundServerMessage : public MessageType
	{
	public:
		using ClassType = BackgroundServerMessage;
		using ParentType = MessageType;

	public:
		BackgroundServerMessage(int64_t delta);
		virtual ~BackgroundServerMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		CoreTools::ConsoleAlloc m_Alloc;
	};

	using BackgroundServerMessageWindowProcessHandle = Framework::WindowProcessHandle<BackgroundServerMessage>;
}

#endif // BACKGROUND_SERVER_BACKGROUND_SERVER_MESSAGE_H
