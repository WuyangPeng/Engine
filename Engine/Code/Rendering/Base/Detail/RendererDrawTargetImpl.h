/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 17:40)

#ifndef RENDERING_BASE_RENDERER_DRAW_TARGET_IMPL_H
#define RENDERING_BASE_RENDERER_DRAW_TARGET_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Base/BaseFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RendererDrawTargetImpl
    {
    public:
        using ClassType = RendererDrawTargetImpl;

        using ConstDrawTargetWeakPtr = std::weak_ptr<const DrawTarget>;
        using ConstDrawTargetSharedPtr = std::shared_ptr<const DrawTarget>;

    public:
        explicit RendererDrawTargetImpl(const ConstDrawTargetSharedPtr& drawTarget) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstDrawTargetSharedPtr GetDrawTarget() const;

    private:
        ConstDrawTargetWeakPtr drawTarget;
    };
}

#endif  // RENDERING_BASE_RENDERER_DRAW_TARGET_IMPL_H
