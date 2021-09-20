// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 16:58)

#ifndef GAME_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define GAME_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "GameServer/GameServerCore/GameServerCoreDll.h"

#include "GameServer/GameServerCore/Macro/ExportMacro.h"  

namespace GameServerCore
{
	class GAME_SERVER_CORE_DEFAULT_DECLARE Placeholder
	{
	public:
		using ClassType = Placeholder;

	public:
		Placeholder();

		CLASS_INVARIANT_DECLARE;
	};
}

#endif // GAME_SERVER_CORE_ENGINE_PLACEHOLDER_H
