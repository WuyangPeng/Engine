///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/02 16:49)

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

        // ֧�ֱ���Visual��
    public:
        // ����һ��visual��*.trv�ļ�����ý��ϵͳ��
        static void SaveToFile(const Visual& visual, const System::String& name);
    };
}

#endif  // RENDERING_SCENE_GRAPH_SAVE_VISUAL_H
