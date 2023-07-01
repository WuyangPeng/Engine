///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 10:00)

#ifndef RENDERING_BASE_RENDERER_DRAW_TARGET_H
#define RENDERING_BASE_RENDERER_DRAW_TARGET_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SharedPtrMacro.h"
#include "Rendering/LocalEffects/LocalEffectsFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(RendererDrawTarget, RendererDrawTargetImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererDrawTarget
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(RendererDrawTarget);

        using ConstDrawTargetSharedPtr = std::shared_ptr<const DrawTarget>;

    public:
        explicit RendererDrawTarget(const ConstDrawTargetSharedPtr& drawTarget);
        virtual ~RendererDrawTarget() noexcept = default;
        RendererDrawTarget(const RendererDrawTarget& rhs) = default;
        RendererDrawTarget& operator=(const RendererDrawTarget& rhs) = default;
        RendererDrawTarget(RendererDrawTarget&& rhs) noexcept = default;
        RendererDrawTarget& operator=(RendererDrawTarget&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD ConstDrawTargetSharedPtr GetDrawTarget() const;

        virtual void Enable() = 0;
        virtual void Disable() = 0;

    private:
        PackageType impl;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(RendererDrawTarget);
}

#endif  // RENDERING_BASE_RENDERER_DRAW_TARGET_H
