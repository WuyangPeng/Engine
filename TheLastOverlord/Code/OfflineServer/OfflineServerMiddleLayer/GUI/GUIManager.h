// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 14:05)

#ifndef OFFLINE_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
#define OFFLINE_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H

#include "OfflineServer/OfflineServerMiddleLayer/OfflineServerMiddleLayerDll.h"

#include "OfflineServer/OfflineServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/GUIManagerInterface.h" 

namespace OfflineServerMiddleLayer
{
	class OFFLINE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE GUIManager : public Framework::GUIManagerInterface
	{
	public:
		using ClassType = GUIManager;
		using ParentType = Framework::GUIManagerInterface;
		
	public:
		GUIManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~GUIManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // OFFLINE_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H