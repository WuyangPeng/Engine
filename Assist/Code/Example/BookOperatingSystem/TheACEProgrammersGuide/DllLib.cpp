///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/06 21:46)

#include "Example/BookOperatingSystem/TheACEProgrammersGuide/TheACEProgrammersGuideExport.h"

#include "TheACEProgrammersGuide.h"

#ifndef BUILDING_THE_ACE_PROGRAMMERS_GUIDE_STATIC

    #include "DllLib.h"

#else  // !BUILDING_THE_ACE_PROGRAMMERS_GUIDE_STATIC

namespace TheACEProgrammersGuide
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_THE_ACE_PROGRAMMERS_GUIDE_STATIC