// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 19:38)

#ifndef ENGINE_MIDDLE_LAYER_TESTING_ENGINE_MIDDLE_LAYER_MESSAGE_H
#define ENGINE_MIDDLE_LAYER_TESTING_ENGINE_MIDDLE_LAYER_MESSAGE_H

#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"
#include "Framework/MiddleLayer/ArtificialIntellegenceInterface.h"
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "CoreTools/Console/ConsoleAlloc.h" 

namespace EngineMiddleLayer
{
	using ObjectLogicManager = Framework::ObjectLogicManager<Framework::ObjectLogicInterface, Framework::ArtificialIntellegenceInterface>;
	using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait, Framework::InputManager,
																  Framework::NetworkManagerInterface,ObjectLogicManager,
																  Framework::PhysicalModellingManagerInterface,Framework::MessageManagerInterface,		
																  Framework::EventManagerInterface, Framework::SystemManagerInterface,
																  Framework::ResourceManagerInterface,Framework::AudioManagerInterface,
																  Framework::CameraSystemsManagerInterface,Framework::RenderingManagerInterface,
																  Framework::GUIManagerInterface>;
	using MessageType = Framework::WindowMessage<MiddleLayerType>;

	class EngineMiddleLayerMessage : public MessageType
	{
	public:
		using ClassType = EngineMiddleLayerMessage;
		using ParentType = MessageType;

	public:
		explicit EngineMiddleLayerMessage(int64_t delta);
		virtual ~EngineMiddleLayerMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		CoreTools::ConsoleAlloc m_Alloc;
	};

	using EngineMiddleLayerTesting = Framework::WindowProcessHandle<EngineMiddleLayerMessage>;
}

#endif // ENGINE_MIDDLE_LAYER_TESTING_ENGINE_MIDDLE_LAYER_MESSAGE_H
