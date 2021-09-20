// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 15:43)

#ifndef GAME_MASTER_SERVER_GAME_MASTER_SERVER_MESSAGE_H
#define GAME_MASTER_SERVER_GAME_MASTER_SERVER_MESSAGE_H

#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "Framework/WindowProcess/WindowMessage.h"
#include "CoreTools/Console/ConsoleAlloc.h" 
#include "GameMasterServer/GameMasterServerMiddleLayer/Input/InputManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/Network/NetworkManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/Message/MessageManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/Event/EventManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/System/SystemManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/Resource/ResourceManager.h"	
#include "GameMasterServer/GameMasterServerMiddleLayer/Audio/AudioManager.h"												 
#include "GameMasterServer/GameMasterServerMiddleLayer/CameraSystems/CameraSystemsManager.h"	
#include "GameMasterServer/GameMasterServerMiddleLayer/Rendering/RenderingManager.h"												 
#include "GameMasterServer/GameMasterServerMiddleLayer/GUI/GUIManager.h"

namespace GameMasterServer
{
	using ObjectLogicManager = Framework::ObjectLogicManager<GameMasterServerMiddleLayer::ObjectLogicManager, GameMasterServerMiddleLayer::ArtificialIntellegenceManager>;
	using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
																  GameMasterServerMiddleLayer::InputManager,
		                                                          GameMasterServerMiddleLayer::NetworkManager,
																  ObjectLogicManager,
																  GameMasterServerMiddleLayer::PhysicalModellingManager,
																  GameMasterServerMiddleLayer::MessageManager,		
																  GameMasterServerMiddleLayer::EventManager, 
																  GameMasterServerMiddleLayer::SystemManager,
																  GameMasterServerMiddleLayer::ResourceManager,
																  GameMasterServerMiddleLayer::AudioManager,
																  GameMasterServerMiddleLayer::CameraSystemsManager,
																  GameMasterServerMiddleLayer::RenderingManager,
																  GameMasterServerMiddleLayer::GUIManager>;
	using MessageType = Framework::WindowMessage<MiddleLayerType>;

	class GameMasterServerMessage : public MessageType
	{
	public:
		using ClassType = GameMasterServerMessage;
		using ParentType = MessageType;

	public:
		GameMasterServerMessage(int64_t delta);
		virtual ~GameMasterServerMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		CoreTools::ConsoleAlloc m_Alloc;
	};

	using GameMasterServerMessageWindowProcessHandle = Framework::WindowProcessHandle<GameMasterServerMessage>;
}

#endif // GAME_MASTER_SERVER_GAME_MASTER_SERVER_MESSAGE_H
