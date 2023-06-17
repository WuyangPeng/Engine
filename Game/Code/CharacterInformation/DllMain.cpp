///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 17:02)

#include "CharacterInformation/CharacterInformationExport.h"

#include "CharacterInformationFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CHARACTER_INFORMATION_STATIC

DLL_MAIN_FUNCTION(CharacterInformation);

#else  // !BUILDING_CHARACTER_INFORMATION_STATIC

CORE_TOOLS_MUTEX_INIT(CharacterInformation);

#endif  // BUILDING_CHARACTER_INFORMATION_STATIC
