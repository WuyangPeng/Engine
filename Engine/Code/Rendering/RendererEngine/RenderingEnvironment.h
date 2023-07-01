///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 16:54)
///
///	单元测试：Pass

#ifndef RENDERING_RENDERER_ENGINE_RENDERING_ENVIRONMENT_H
#define RENDERING_RENDERER_ENGINE_RENDERING_ENVIRONMENT_H

#include "Rendering/RenderingDll.h"

#include "RendererEngineFwd.h"
#include "RenderingDevice.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(RenderingEnvironment, RenderingEnvironmentImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RenderingEnvironment
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(RenderingEnvironment);

    public:
        RenderingEnvironment(const EnvironmentParameter& environmentParameter, const RendererParameter& rendererParameter);

        CLASS_INVARIANT_DECLARE;

        void Release();

        NODISCARD RenderingDevice GetRenderingDevice() const;

        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD DataFormatType GetColorFormat() const noexcept;
        NODISCARD DataFormatType GetDepthStencilFormat() const noexcept;
        NODISCARD int GetNumMultiSamples() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERING_ENVIRONMENT_H
