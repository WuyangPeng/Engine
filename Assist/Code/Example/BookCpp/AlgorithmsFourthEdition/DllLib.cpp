///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/07 0:26)

#include "Example/BookCpp/AlgorithmsFourthEdition/AlgorithmsFourthEditionExport.h"

#include "AlgorithmsFourthEdition.h"

#ifndef BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC

    #include "DllLib.h"

#else  // BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC

namespace AlgorithmsFourthEdition
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC
