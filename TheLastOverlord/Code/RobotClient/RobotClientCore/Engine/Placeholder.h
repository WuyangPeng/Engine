// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.0 (2019/10/09 23:38)

#ifndef ROBOT_CLIENT_CORE_ENGINE_PLACEHOLDER_H
#define ROBOT_CLIENT_CORE_ENGINE_PLACEHOLDER_H

#include "RobotClient/RobotClientCore/RobotClientCoreDll.h"

#include "RobotClient/RobotClientCore/Macro/ExportMacro.h"  

namespace RobotClientCore
{
	class ROBOT_CLIENT_CORE_DEFAULT_DECLARE Placeholder
	{
	public:
		using ClassType = Placeholder;

	public:
		Placeholder();

		CLASS_INVARIANT_DECLARE;
	};
}

#endif // ROBOT_CLIENT_CORE_ENGINE_PLACEHOLDER_H
