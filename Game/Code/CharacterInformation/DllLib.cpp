///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 15:27)

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
