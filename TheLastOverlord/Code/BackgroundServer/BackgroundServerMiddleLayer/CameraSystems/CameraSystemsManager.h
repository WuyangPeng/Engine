// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:09)

#ifndef BACKGROUND_SERVER_MIDDLE_LAYER_CAMERA_SYSTEMS_MIDDLE_LAYER_CAMERA_SYSTEMS_H
#define BACKGROUND_SERVER_MIDDLE_LAYER_CAMERA_SYSTEMS_MIDDLE_LAYER_CAMERA_SYSTEMS_H

#include "BackgroundServer/BackgroundServerMiddleLayer/BackgroundServerMiddleLayerDll.h"

#include "BackgroundServer/BackgroundServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/CameraSystemsManagerInterface.h" 

namespace BackgroundServerMiddleLayer
{
	class BACKGROUND_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE CameraSystemsManager : public Framework::CameraSystemsManagerInterface
	{
	public:
		using ClassType = CameraSystemsManager;
		using ParentType = Framework::CameraSystemsManagerInterface;
		
	public:
		CameraSystemsManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~CameraSystemsManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // BACKGROUND_SERVER_MIDDLE_LAYER_CAMERA_SYSTEMS_MIDDLE_LAYER_CAMERA_SYSTEMS_H
