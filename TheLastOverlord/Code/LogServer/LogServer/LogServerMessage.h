// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/12 22:53)

#ifndef LOG_SERVER_LOG_SERVER_MESSAGE_H
#define LOG_SERVER_LOG_SERVER_MESSAGE_H

#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "Framework/WindowProcess/WindowMessage.h"
#include "CoreTools/Console/ConsoleAlloc.h" 
#include "LogServer/LogServerMiddleLayer/Input/InputManager.h"
#include "LogServer/LogServerMiddleLayer/Network/NetworkManager.h"
#include "LogServer/LogServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "LogServer/LogServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "LogServer/LogServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "LogServer/LogServerMiddleLayer/Message/MessageManager.h"
#include "LogServer/LogServerMiddleLayer/Event/EventManager.h"
#include "LogServer/LogServerMiddleLayer/System/SystemManager.h"
#include "LogServer/LogServerMiddleLayer/Resource/ResourceManager.h"	
#include "LogServer/LogServerMiddleLayer/Audio/AudioManager.h"												 
#include "LogServer/LogServerMiddleLayer/CameraSystems/CameraSystemsManager.h"	
#include "LogServer/LogServerMiddleLayer/Rendering/RenderingManager.h"												 
#include "LogServer/LogServerMiddleLayer/GUI/GUIManager.h"

namespace LogServer
{
	using ObjectLogicManager = Framework::ObjectLogicManager<LogServerMiddleLayer::ObjectLogicManager, LogServerMiddleLayer::ArtificialIntellegenceManager>;
	using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
																  LogServerMiddleLayer::InputManager,
		                                                          LogServerMiddleLayer::NetworkManager,
																  ObjectLogicManager,
																  LogServerMiddleLayer::PhysicalModellingManager,
																  LogServerMiddleLayer::MessageManager,		
																  LogServerMiddleLayer::EventManager, 
																  LogServerMiddleLayer::SystemManager,
																  LogServerMiddleLayer::ResourceManager,
																  LogServerMiddleLayer::AudioManager,
																  LogServerMiddleLayer::CameraSystemsManager,
																  LogServerMiddleLayer::RenderingManager,
																  LogServerMiddleLayer::GUIManager>;
	using MessageType = Framework::WindowMessage<MiddleLayerType>;

	class LogServerMessage : public MessageType
	{
	public:
		using ClassType = LogServerMessage;
		using ParentType = MessageType;

	public:
		LogServerMessage(int64_t delta);
		virtual ~LogServerMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		CoreTools::ConsoleAlloc m_Alloc;
	};

	using LogServerMessageWindowProcessHandle = Framework::WindowProcessHandle<LogServerMessage>;
}

#endif // LOG_SERVER_LOG_SERVER_MESSAGE_H
