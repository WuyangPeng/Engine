///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:27)

#include "CharacterInformation/CharacterInformationExport.h"

#include "CharacterInformationFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CHARACTER_INFORMATION_STATIC

DLL_MAIN_FUNCTION(CharacterInformation);

#else  // !BUILDING_CHARACTER_INFORMATION_STATIC

CORE_TOOLS_MUTEX_INIT(CharacterInformation);

#endif  // BUILDING_CHARACTER_INFORMATION_STATIC
