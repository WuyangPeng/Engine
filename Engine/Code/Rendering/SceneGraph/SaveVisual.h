///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 16:49)

#ifndef RENDERING_SCENE_GRAPH_SAVE_VISUAL_H
#define RENDERING_SCENE_GRAPH_SAVE_VISUAL_H

#include "Rendering/RenderingDll.h"

#include "Visual.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SaveVisual
    {
    public:
        using ClassType = SaveVisual;

        // 支持保存Visual。
    public:
        // 保存一个visual从*.trv文件在流媒体系统。
        static void SaveToFile(const Visual& visual, const System::String& name);
    };
}

#endif  // RENDERING_SCENE_GRAPH_SAVE_VISUAL_H
