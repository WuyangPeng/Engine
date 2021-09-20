// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 14:06)

#ifndef LOGIN_SERVER_MIDDLE_LAYER_OBJECT_LOGIC_MIDDLE_LAYER_OBJECT_LOGIC_H
#define LOGIN_SERVER_MIDDLE_LAYER_OBJECT_LOGIC_MIDDLE_LAYER_OBJECT_LOGIC_H

#include "LoginServer/LoginServerMiddleLayer/LoginServerMiddleLayerDll.h"

#include "LoginServer/LoginServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/ObjectLogicInterface.h" 

namespace LoginServerMiddleLayer
{
	class LOGIN_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ObjectLogicManager : public Framework::ObjectLogicInterface
	{
	public:
		using ClassType = ObjectLogicManager;
		using ParentType = Framework::ObjectLogicInterface;
		
	public:
		ObjectLogicManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~ObjectLogicManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // LOGIN_SERVER_MIDDLE_LAYER_OBJECT_LOGIC_MIDDLE_LAYER_OBJECT_LOGIC_H
