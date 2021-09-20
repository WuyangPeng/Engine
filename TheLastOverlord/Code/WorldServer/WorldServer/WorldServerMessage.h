// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 13:05)

#ifndef WORLD_SERVER_WORLD_SERVER_MESSAGE_H
#define WORLD_SERVER_WORLD_SERVER_MESSAGE_H

#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "Framework/WindowProcess/WindowMessage.h"
#include "CoreTools/Console/ConsoleAlloc.h" 
#include "WorldServer/WorldServerMiddleLayer/Input/InputManager.h"
#include "WorldServer/WorldServerMiddleLayer/Network/NetworkManager.h"
#include "WorldServer/WorldServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "WorldServer/WorldServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "WorldServer/WorldServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "WorldServer/WorldServerMiddleLayer/Message/MessageManager.h"
#include "WorldServer/WorldServerMiddleLayer/Event/EventManager.h"
#include "WorldServer/WorldServerMiddleLayer/System/SystemManager.h"
#include "WorldServer/WorldServerMiddleLayer/Resource/ResourceManager.h"	
#include "WorldServer/WorldServerMiddleLayer/Audio/AudioManager.h"												 
#include "WorldServer/WorldServerMiddleLayer/CameraSystems/CameraSystemsManager.h"	
#include "WorldServer/WorldServerMiddleLayer/Rendering/RenderingManager.h"												 
#include "WorldServer/WorldServerMiddleLayer/GUI/GUIManager.h"

namespace WorldServer
{
	using ObjectLogicManager = Framework::ObjectLogicManager<WorldServerMiddleLayer::ObjectLogicManager, WorldServerMiddleLayer::ArtificialIntellegenceManager>;
	using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
																  WorldServerMiddleLayer::InputManager,
		                                                          WorldServerMiddleLayer::NetworkManager,
																  ObjectLogicManager,
																  WorldServerMiddleLayer::PhysicalModellingManager,
																  WorldServerMiddleLayer::MessageManager,		
																  WorldServerMiddleLayer::EventManager, 
																  WorldServerMiddleLayer::SystemManager,
																  WorldServerMiddleLayer::ResourceManager,
																  WorldServerMiddleLayer::AudioManager,
																  WorldServerMiddleLayer::CameraSystemsManager,
																  WorldServerMiddleLayer::RenderingManager,
																  WorldServerMiddleLayer::GUIManager>;
	using MessageType = Framework::WindowMessage<MiddleLayerType>;

	class WorldServerMessage : public MessageType
	{
	public:
		using ClassType = WorldServerMessage;
		using ParentType = MessageType;

	public:
		WorldServerMessage(int64_t delta);
		virtual ~WorldServerMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		CoreTools::ConsoleAlloc m_Alloc;
	};

	using WorldServerMessageWindowProcessHandle = Framework::WindowProcessHandle<WorldServerMessage>;
}

#endif // WORLD_SERVER_WORLD_SERVER_MESSAGE_H
