///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 17:03)

#include "CharacterInformation/CharacterInformationExport.h"

#include "CharacterInformation/CharacterInformation.h"

#ifndef BUILDING_CHARACTER_INFORMATION_STATIC

    #include "DllLib.h"

#else  // !BUILDING_CHARACTER_INFORMATION_STATIC

namespace CharacterInformation
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CHARACTER_INFORMATION_STATIC
