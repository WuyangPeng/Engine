///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/24 21:59)

#include "Example/BookCpp/CppPrimerFourthEdition/CppPrimerFourthEditionExport.h"

#include "CppPrimerFourthEdition.h"

#ifndef BUILDING_CPP_PRIMER_FOURTH_EDITION_STATIC

    #include "DllLib.h"

#else  // BUILDING_CPP_PRIMER_FOURTH_EDITION_STATIC

namespace CppPrimerFourthEdition
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CPP_PRIMER_FOURTH_EDITION_STATIC
