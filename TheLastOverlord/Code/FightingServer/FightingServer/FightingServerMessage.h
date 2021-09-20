// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 09:36)

#ifndef FIGHTING_SERVER_FIGHTING_SERVER_MESSAGE_H
#define FIGHTING_SERVER_FIGHTING_SERVER_MESSAGE_H

#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "Framework/WindowProcess/WindowMessage.h"
#include "CoreTools/Console/ConsoleAlloc.h" 
#include "FightingServer/FightingServerMiddleLayer/Input/InputManager.h"
#include "FightingServer/FightingServerMiddleLayer/Network/NetworkManager.h"
#include "FightingServer/FightingServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "FightingServer/FightingServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "FightingServer/FightingServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "FightingServer/FightingServerMiddleLayer/Message/MessageManager.h"
#include "FightingServer/FightingServerMiddleLayer/Event/EventManager.h"
#include "FightingServer/FightingServerMiddleLayer/System/SystemManager.h"
#include "FightingServer/FightingServerMiddleLayer/Resource/ResourceManager.h"	
#include "FightingServer/FightingServerMiddleLayer/Audio/AudioManager.h"												 
#include "FightingServer/FightingServerMiddleLayer/CameraSystems/CameraSystemsManager.h"	
#include "FightingServer/FightingServerMiddleLayer/Rendering/RenderingManager.h"												 
#include "FightingServer/FightingServerMiddleLayer/GUI/GUIManager.h"

namespace FightingServer
{
	using ObjectLogicManager = Framework::ObjectLogicManager<FightingServerMiddleLayer::ObjectLogicManager, FightingServerMiddleLayer::ArtificialIntellegenceManager>;
	using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
																  FightingServerMiddleLayer::InputManager,
		                                                          FightingServerMiddleLayer::NetworkManager,
																  ObjectLogicManager,
																  FightingServerMiddleLayer::PhysicalModellingManager,
																  FightingServerMiddleLayer::MessageManager,		
																  FightingServerMiddleLayer::EventManager, 
																  FightingServerMiddleLayer::SystemManager,
																  FightingServerMiddleLayer::ResourceManager,
																  FightingServerMiddleLayer::AudioManager,
																  FightingServerMiddleLayer::CameraSystemsManager,
																  FightingServerMiddleLayer::RenderingManager,
																  FightingServerMiddleLayer::GUIManager>;
	using MessageType = Framework::WindowMessage<MiddleLayerType>;

	class FightingServerMessage : public MessageType
	{
	public:
		using ClassType = FightingServerMessage;
		using ParentType = MessageType;

	public:
		FightingServerMessage(int64_t delta);
		virtual ~FightingServerMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		CoreTools::ConsoleAlloc m_Alloc;
	};

	using FightingServerMessageWindowProcessHandle = Framework::WindowProcessHandle<FightingServerMessage>;
}

#endif // FIGHTING_SERVER_FIGHTING_SERVER_MESSAGE_H
