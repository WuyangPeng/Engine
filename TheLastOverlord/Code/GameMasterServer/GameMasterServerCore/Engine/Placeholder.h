// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 15:43)

#ifndef GAME_MASTER_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define GAME_MASTER_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "GameMasterServer/GameMasterServerCore/GameMasterServerCoreDll.h"

#include "GameMasterServer/GameMasterServerCore/Macro/ExportMacro.h"  

namespace GameMasterServerCore
{
	class GAME_MASTER_SERVER_CORE_DEFAULT_DECLARE Placeholder
	{
	public:
		using ClassType = Placeholder;

	public:
		Placeholder();

		CLASS_INVARIANT_DECLARE;
	};
}

#endif // GAME_MASTER_SERVER_CORE_ENGINE_PLACEHOLDER_H
