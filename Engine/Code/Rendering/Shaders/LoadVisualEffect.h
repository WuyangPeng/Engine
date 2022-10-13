///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 14:18)

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

        // 从外部的视频流系统的*.trve文件读取视觉效果。
        NODISCARD static VisualEffectSharedPtr Load(const System::String& fileName);
    };
}

#endif  // RENDERING_SHADERS_LOAD_VISUAL_EFFECT_H
