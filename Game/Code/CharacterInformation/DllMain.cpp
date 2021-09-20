// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/04 21:29)

#include "CharacterInformation/CharacterInformationExport.h"

#include "CharacterInformationFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_CHARACTER_INFORMATION_STATIC

	DLL_MAIN_FUNCTION(CharacterInformation);

#else // !BUILDING_CHARACTER_INFORMATION_STATIC

	CORE_TOOLS_MUTEX_INIT(CharacterInformation);

#endif // BUILDING_CHARACTER_INFORMATION_STATIC
