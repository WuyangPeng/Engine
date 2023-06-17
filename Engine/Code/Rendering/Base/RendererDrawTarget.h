///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:07)

#ifndef RENDERING_RENDERERS_RENDERER_DRAW_TARGET_H
#define RENDERING_RENDERERS_RENDERER_DRAW_TARGET_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SharedPtrMacro.h"
#include "Rendering/LocalEffects/LocalEffectsFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererDrawTarget
    {
    public:
        using ClassType = RendererDrawTarget;

    public:
        RendererDrawTarget() noexcept = default;
        virtual ~RendererDrawTarget() noexcept = default;
        RendererDrawTarget(const RendererDrawTarget& rhs) noexcept = default;
        RendererDrawTarget& operator=(const RendererDrawTarget& rhs) noexcept = default;
        RendererDrawTarget(RendererDrawTarget&& rhs) noexcept = default;
        RendererDrawTarget& operator=(RendererDrawTarget&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(RendererDrawTarget);
}

#endif  // RENDERING_RENDERERS_RENDERER_DRAW_TARGET_H
