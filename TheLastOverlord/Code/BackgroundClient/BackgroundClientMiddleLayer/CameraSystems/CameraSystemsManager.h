// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 17:56)

#ifndef BACKGROUND_CLIENT_MIDDLE_LAYER_CAMERA_SYSTEMS_MIDDLE_LAYER_CAMERA_SYSTEMS_H
#define BACKGROUND_CLIENT_MIDDLE_LAYER_CAMERA_SYSTEMS_MIDDLE_LAYER_CAMERA_SYSTEMS_H

#include "BackgroundClient/BackgroundClientMiddleLayer/BackgroundClientMiddleLayerDll.h"

#include "BackgroundClient/BackgroundClientMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/CameraSystemsManagerInterface.h" 

namespace BackgroundClientMiddleLayer
{
	class BACKGROUND_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE CameraSystemsManager : public Framework::CameraSystemsManagerInterface
	{
	public:
		using ClassType = CameraSystemsManager;
		using ParentType = Framework::CameraSystemsManagerInterface;
		
	public:
		explicit CameraSystemsManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~CameraSystemsManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // BACKGROUND_CLIENT_MIDDLE_LAYER_CAMERA_SYSTEMS_MIDDLE_LAYER_CAMERA_SYSTEMS_H
