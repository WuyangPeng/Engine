///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:10)

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
