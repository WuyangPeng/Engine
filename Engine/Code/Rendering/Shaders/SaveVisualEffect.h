///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/13 14:46)

#ifndef RENDERING_SHADERS_SAVE_VISUAL_EFFECT_H
#define RENDERING_SHADERS_SAVE_VISUAL_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/LocalEffects/VisualEffect.h"
#include "System/Helper/UnicodeUsing.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SaveVisualEffect
    {
    public:
        using ClassType = SaveVisualEffect;

    public:
        // �����Ӿ�Ч�����ⲿ����Ƶ��ϵͳ��*.trve�ļ���
        SaveVisualEffect(const VisualEffect& visualEffect, const System::String& fileName);

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // RENDERING_SHADERS_SAVE_VISUAL_EFFECT_H
