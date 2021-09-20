// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.2.0 (2020/01/08 23:46)

#ifndef GAME_CLIENT_CORE_ENGINE_PLACEHOLDER_H
#define GAME_CLIENT_CORE_ENGINE_PLACEHOLDER_H

#include "GameClient/GameClientCore/GameClientCoreDll.h"

#include "GameClient/GameClientCore/Macro/ExportMacro.h"  

namespace GameClientCore
{
	class GAME_CLIENT_CORE_DEFAULT_DECLARE Placeholder
	{
	public:
		using ClassType = Placeholder;

	public:
		Placeholder();

		CLASS_INVARIANT_DECLARE;
	};
}

#endif // GAME_CLIENT_CORE_ENGINE_PLACEHOLDER_H