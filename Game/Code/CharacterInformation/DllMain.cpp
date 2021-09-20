// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/04 21:29)

#include "CharacterInformation/CharacterInformationExport.h"

#include "CharacterInformationFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_CHARACTER_INFORMATION_STATIC

	DLL_MAIN_FUNCTION(CharacterInformation);

#else // !BUILDING_CHARACTER_INFORMATION_STATIC

	CORE_TOOLS_MUTEX_INIT(CharacterInformation);

#endif // BUILDING_CHARACTER_INFORMATION_STATIC
