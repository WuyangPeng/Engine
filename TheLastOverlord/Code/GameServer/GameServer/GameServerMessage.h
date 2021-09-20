// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 16:57)

#ifndef GAME_SERVER_GAME_SERVER_MESSAGE_H
#define GAME_SERVER_GAME_SERVER_MESSAGE_H

#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "Framework/WindowProcess/WindowMessage.h"
#include "CoreTools/Console/ConsoleAlloc.h" 
#include "GameServer/GameServerMiddleLayer/Input/InputManager.h"
#include "GameServer/GameServerMiddleLayer/Network/NetworkManager.h"
#include "GameServer/GameServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "GameServer/GameServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "GameServer/GameServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "GameServer/GameServerMiddleLayer/Message/MessageManager.h"
#include "GameServer/GameServerMiddleLayer/Event/EventManager.h"
#include "GameServer/GameServerMiddleLayer/System/SystemManager.h"
#include "GameServer/GameServerMiddleLayer/Resource/ResourceManager.h"	
#include "GameServer/GameServerMiddleLayer/Audio/AudioManager.h"												 
#include "GameServer/GameServerMiddleLayer/CameraSystems/CameraSystemsManager.h"	
#include "GameServer/GameServerMiddleLayer/Rendering/RenderingManager.h"												 
#include "GameServer/GameServerMiddleLayer/GUI/GUIManager.h"

namespace GameServer
{
	using ObjectLogicManager = Framework::ObjectLogicManager<GameServerMiddleLayer::ObjectLogicManager, GameServerMiddleLayer::ArtificialIntellegenceManager>;
	using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
																  GameServerMiddleLayer::InputManager,
		                                                          GameServerMiddleLayer::NetworkManager,
																  ObjectLogicManager,
																  GameServerMiddleLayer::PhysicalModellingManager,
																  GameServerMiddleLayer::MessageManager,		
																  GameServerMiddleLayer::EventManager, 
																  GameServerMiddleLayer::SystemManager,
																  GameServerMiddleLayer::ResourceManager,
																  GameServerMiddleLayer::AudioManager,
																  GameServerMiddleLayer::CameraSystemsManager,
																  GameServerMiddleLayer::RenderingManager,
																  GameServerMiddleLayer::GUIManager>;
	using MessageType = Framework::WindowMessage<MiddleLayerType>;

	class GameServerMessage : public MessageType
	{
	public:
		using ClassType = GameServerMessage;
		using ParentType = MessageType;

	public:
		GameServerMessage(int64_t delta);
		virtual ~GameServerMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		CoreTools::ConsoleAlloc m_Alloc;
	};

	using GameServerMessageWindowProcessHandle = Framework::WindowProcessHandle<GameServerMessage>;
}

#endif // GAME_SERVER_GAME_SERVER_MESSAGE_H
