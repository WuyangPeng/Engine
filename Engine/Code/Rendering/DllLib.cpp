///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/26 22:06)

#include "Rendering/RenderingExport.h"

#include "Rendering/Rendering.h"

#ifndef BUILDING_RENDERING_STATIC

    #include "DllLib.h"

#else  // BUILDING_RENDERING_STATIC

namespace Rendering
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_RENDERING_STATIC
