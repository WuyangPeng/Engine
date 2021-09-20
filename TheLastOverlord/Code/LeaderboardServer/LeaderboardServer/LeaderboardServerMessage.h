// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 15:25)

#ifndef LEADERBOARD_SERVER_LEADERBOARD_SERVER_MESSAGE_H
#define LEADERBOARD_SERVER_LEADERBOARD_SERVER_MESSAGE_H

#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "Framework/WindowProcess/WindowMessage.h"
#include "CoreTools/Console/ConsoleAlloc.h" 
#include "LeaderboardServer/LeaderboardServerMiddleLayer/Input/InputManager.h"
#include "LeaderboardServer/LeaderboardServerMiddleLayer/Network/NetworkManager.h"
#include "LeaderboardServer/LeaderboardServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "LeaderboardServer/LeaderboardServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "LeaderboardServer/LeaderboardServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "LeaderboardServer/LeaderboardServerMiddleLayer/Message/MessageManager.h"
#include "LeaderboardServer/LeaderboardServerMiddleLayer/Event/EventManager.h"
#include "LeaderboardServer/LeaderboardServerMiddleLayer/System/SystemManager.h"
#include "LeaderboardServer/LeaderboardServerMiddleLayer/Resource/ResourceManager.h"	
#include "LeaderboardServer/LeaderboardServerMiddleLayer/Audio/AudioManager.h"												 
#include "LeaderboardServer/LeaderboardServerMiddleLayer/CameraSystems/CameraSystemsManager.h"	
#include "LeaderboardServer/LeaderboardServerMiddleLayer/Rendering/RenderingManager.h"												 
#include "LeaderboardServer/LeaderboardServerMiddleLayer/GUI/GUIManager.h"

namespace LeaderboardServer
{
	using ObjectLogicManager = Framework::ObjectLogicManager<LeaderboardServerMiddleLayer::ObjectLogicManager, LeaderboardServerMiddleLayer::ArtificialIntellegenceManager>;
	using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
																  LeaderboardServerMiddleLayer::InputManager,
		                                                          LeaderboardServerMiddleLayer::NetworkManager,
																  ObjectLogicManager,
																  LeaderboardServerMiddleLayer::PhysicalModellingManager,
																  LeaderboardServerMiddleLayer::MessageManager,		
																  LeaderboardServerMiddleLayer::EventManager, 
																  LeaderboardServerMiddleLayer::SystemManager,
																  LeaderboardServerMiddleLayer::ResourceManager,
																  LeaderboardServerMiddleLayer::AudioManager,
																  LeaderboardServerMiddleLayer::CameraSystemsManager,
																  LeaderboardServerMiddleLayer::RenderingManager,
																  LeaderboardServerMiddleLayer::GUIManager>;
	using MessageType = Framework::WindowMessage<MiddleLayerType>;

	class LeaderboardServerMessage : public MessageType
	{
	public:
		using ClassType = LeaderboardServerMessage;
		using ParentType = MessageType;

	public:
		LeaderboardServerMessage(int64_t delta);
		virtual ~LeaderboardServerMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		CoreTools::ConsoleAlloc m_Alloc;
	};

	using LeaderboardServerMessageWindowProcessHandle = Framework::WindowProcessHandle<LeaderboardServerMessage>;
}

#endif // LEADERBOARD_SERVER_LEADERBOARD_SERVER_MESSAGE_H
