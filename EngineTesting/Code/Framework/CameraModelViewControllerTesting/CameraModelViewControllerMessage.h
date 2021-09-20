// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 17:34)

#ifndef CAMERA_MODEL_VIEW_CONTROLLER_TESTING_PIXEL_MODEL_VIEW_CONTROLLER_MESSAGE_H
#define CAMERA_MODEL_VIEW_CONTROLLER_TESTING_PIXEL_MODEL_VIEW_CONTROLLER_MESSAGE_H

#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/MiddleLayer/ModelViewControllerMiddleLayerContainer.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/CameraModelMiddleLayer.h"
#include "Framework/MiddleLayer/CameraControllerMiddleLayer.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "FrameViewMiddleLayer.h"

namespace CameraModelViewController
{
	using MiddleLayerType = Framework::ModelViewControllerMiddleLayerContainer<Framework::WindowApplicationTrait, Framework::CameraModelMiddleLayer,
																			   FrameViewMiddleLayer, Framework::CameraControllerMiddleLayer>;
	using MessageType = Framework::WindowMessage<MiddleLayerType>;

	class CameraModelViewControllerMessage : public MessageType
	{
	public:
		using ClassType = CameraModelViewControllerMessage;
		using ParentType = MessageType;

	public:
		explicit CameraModelViewControllerMessage(int64_t delta);
		virtual ~CameraModelViewControllerMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		CoreTools::ConsoleAlloc m_Alloc;
	};

	using CameraModelViewControllerTesting = Framework::WindowProcessHandle<CameraModelViewControllerMessage>;
}

#endif // CAMERA_MODEL_VIEW_CONTROLLER_TESTING_PIXEL_MODEL_VIEW_CONTROLLER_MESSAGE_H
