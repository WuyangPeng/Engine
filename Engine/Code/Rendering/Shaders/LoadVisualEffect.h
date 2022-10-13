///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/13 14:18)

#ifndef RENDERING_SHADERS_LOAD_VISUAL_EFFECT_H
#define RENDERING_SHADERS_LOAD_VISUAL_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/LocalEffects/VisualEffect.h"
#include "System/Helper/UnicodeUsing.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE LoadVisualEffect
    {
    public:
        using ClassType = LoadVisualEffect;

    public:
        LoadVisualEffect() noexcept;

        CLASS_INVARIANT_DECLARE;

        // ���ⲿ����Ƶ��ϵͳ��*.trve�ļ���ȡ�Ӿ�Ч����
        NODISCARD static VisualEffectSharedPtr Load(const System::String& fileName);
    };
}

#endif  // RENDERING_SHADERS_LOAD_VISUAL_EFFECT_H
