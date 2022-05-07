///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 15:59)

#ifndef RENDERING_RENDERERS_RENDERER_INPUT_IMPL_H
#define RENDERING_RENDERERS_RENDERER_INPUT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/Windows/Using/WindowsUsing.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RendererInputImpl
    {
    public:
        using ClassType = RendererInputImpl;
        using HWnd = System::WindowsHWnd;
        using FactoryType = RendererInputImpl;
        using RendererInputSharedPtr = std::shared_ptr<RendererInputImpl>;

    public:
        RendererInputImpl() noexcept;
        virtual ~RendererInputImpl() noexcept = default;
        RendererInputImpl(const RendererInputImpl& rhs) noexcept = default;
        RendererInputImpl& operator=(const RendererInputImpl& rhs) noexcept = default;
        RendererInputImpl(RendererInputImpl&& rhs) noexcept = default;
        RendererInputImpl& operator=(RendererInputImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual RendererTypes GetRendererType() const = 0;
        virtual void SetWindowID(int windowID) = 0;
        virtual void SetWindowHandle(HWnd windowID) = 0;

        NODISCARD static RendererInputSharedPtr Create(RendererTypes type);
    };
}

#endif  // RENDERING_RENDERERS_RENDERER_INPUT_IMPL_H
