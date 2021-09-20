///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/08 21:28)

#include "Example/BookCpp/TheCppProgrammingLanguageSpecialEdition/TheCppProgrammingLanguageSpecialEditionExport.h"

#include "TheCppProgrammingLanguageSpecialEdition.h"

#ifndef BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_STATIC

    #include "DllLib.h"

#else  // BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_STATIC

namespace TheCppProgrammingLanguageSpecialEdition
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_STATIC
