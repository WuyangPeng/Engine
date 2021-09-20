// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 13:06)

#ifndef WORLD_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define WORLD_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "WorldServer/WorldServerCore/WorldServerCoreDll.h"

#include "WorldServer/WorldServerCore/Macro/ExportMacro.h"  

namespace WorldServerCore
{
	class WORLD_SERVER_CORE_DEFAULT_DECLARE Placeholder
	{
	public:
		using ClassType = Placeholder;

	public:
		Placeholder();

		CLASS_INVARIANT_DECLARE;
	};
}

#endif // WORLD_SERVER_CORE_ENGINE_PLACEHOLDER_H
