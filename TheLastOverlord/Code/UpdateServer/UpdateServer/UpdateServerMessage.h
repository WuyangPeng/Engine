// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:54)

#ifndef UPDATE_SERVER_UPDATE_SERVER_MESSAGE_H
#define UPDATE_SERVER_UPDATE_SERVER_MESSAGE_H

#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "Framework/WindowProcess/WindowMessage.h"
#include "CoreTools/Console/ConsoleAlloc.h" 
#include "UpdateServer/UpdateServerMiddleLayer/Input/InputManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/Network/NetworkManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/Message/MessageManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/Event/EventManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/System/SystemManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/Resource/ResourceManager.h"	
#include "UpdateServer/UpdateServerMiddleLayer/Audio/AudioManager.h"												 
#include "UpdateServer/UpdateServerMiddleLayer/CameraSystems/CameraSystemsManager.h"	
#include "UpdateServer/UpdateServerMiddleLayer/Rendering/RenderingManager.h"												 
#include "UpdateServer/UpdateServerMiddleLayer/GUI/GUIManager.h"

namespace UpdateServer
{
	using ObjectLogicManager = Framework::ObjectLogicManager<UpdateServerMiddleLayer::ObjectLogicManager, UpdateServerMiddleLayer::ArtificialIntellegenceManager>;
	using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
																  UpdateServerMiddleLayer::InputManager,
		                                                          UpdateServerMiddleLayer::NetworkManager,
																  ObjectLogicManager,
																  UpdateServerMiddleLayer::PhysicalModellingManager,
																  UpdateServerMiddleLayer::MessageManager,		
																  UpdateServerMiddleLayer::EventManager, 
																  UpdateServerMiddleLayer::SystemManager,
																  UpdateServerMiddleLayer::ResourceManager,
																  UpdateServerMiddleLayer::AudioManager,
																  UpdateServerMiddleLayer::CameraSystemsManager,
																  UpdateServerMiddleLayer::RenderingManager,
																  UpdateServerMiddleLayer::GUIManager>;
	using MessageType = Framework::WindowMessage<MiddleLayerType>;

	class UpdateServerMessage : public MessageType
	{
	public:
		using ClassType = UpdateServerMessage;
		using ParentType = MessageType;

	public:
		UpdateServerMessage(int64_t delta);
		virtual ~UpdateServerMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		CoreTools::ConsoleAlloc m_Alloc;
	};

	using UpdateServerMessageWindowProcessHandle = Framework::WindowProcessHandle<UpdateServerMessage>;
}

#endif // UPDATE_SERVER_UPDATE_SERVER_MESSAGE_H
