// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 14:01)

#ifndef OFFLINE_SERVER_OFFLINE_SERVER_MESSAGE_H
#define OFFLINE_SERVER_OFFLINE_SERVER_MESSAGE_H

#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "Framework/WindowProcess/WindowMessage.h"
#include "CoreTools/Console/ConsoleAlloc.h" 
#include "OfflineServer/OfflineServerMiddleLayer/Input/InputManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/Network/NetworkManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/Message/MessageManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/Event/EventManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/System/SystemManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/Resource/ResourceManager.h"	
#include "OfflineServer/OfflineServerMiddleLayer/Audio/AudioManager.h"												 
#include "OfflineServer/OfflineServerMiddleLayer/CameraSystems/CameraSystemsManager.h"	
#include "OfflineServer/OfflineServerMiddleLayer/Rendering/RenderingManager.h"												 
#include "OfflineServer/OfflineServerMiddleLayer/GUI/GUIManager.h"

namespace OfflineServer
{
	using ObjectLogicManager = Framework::ObjectLogicManager<OfflineServerMiddleLayer::ObjectLogicManager, OfflineServerMiddleLayer::ArtificialIntellegenceManager>;
	using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
																  OfflineServerMiddleLayer::InputManager,
		                                                          OfflineServerMiddleLayer::NetworkManager,
																  ObjectLogicManager,
																  OfflineServerMiddleLayer::PhysicalModellingManager,
																  OfflineServerMiddleLayer::MessageManager,		
																  OfflineServerMiddleLayer::EventManager, 
																  OfflineServerMiddleLayer::SystemManager,
																  OfflineServerMiddleLayer::ResourceManager,
																  OfflineServerMiddleLayer::AudioManager,
																  OfflineServerMiddleLayer::CameraSystemsManager,
																  OfflineServerMiddleLayer::RenderingManager,
																  OfflineServerMiddleLayer::GUIManager>;
	using MessageType = Framework::WindowMessage<MiddleLayerType>;

	class OfflineServerMessage : public MessageType
	{
	public:
		using ClassType = OfflineServerMessage;
		using ParentType = MessageType;

	public:
		OfflineServerMessage(int64_t delta);
		virtual ~OfflineServerMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		CoreTools::ConsoleAlloc m_Alloc;
	};

	using OfflineServerMessageWindowProcessHandle = Framework::WindowProcessHandle<OfflineServerMessage>;
}

#endif // OFFLINE_SERVER_OFFLINE_SERVER_MESSAGE_H
