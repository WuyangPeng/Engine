// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/12 22:58)

#ifndef LOG_SERVER_MIDDLE_LAYER_CAMERA_SYSTEMS_MIDDLE_LAYER_CAMERA_SYSTEMS_H
#define LOG_SERVER_MIDDLE_LAYER_CAMERA_SYSTEMS_MIDDLE_LAYER_CAMERA_SYSTEMS_H

#include "LogServer/LogServerMiddleLayer/LogServerMiddleLayerDll.h"

#include "LogServer/LogServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/CameraSystemsManagerInterface.h" 

namespace LogServerMiddleLayer
{
	class LOG_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE CameraSystemsManager : public Framework::CameraSystemsManagerInterface
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

#endif // LOG_SERVER_MIDDLE_LAYER_CAMERA_SYSTEMS_MIDDLE_LAYER_CAMERA_SYSTEMS_H
