///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/04 21:52)

#ifndef RENDERING_RENDERERS_RENDERING_ENVIRONMENT_H
#define RENDERING_RENDERERS_RENDERING_ENVIRONMENT_H

#include "Rendering/RenderingDll.h"

#include "RenderersFwd.h"
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

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_RENDERING_ENVIRONMENT_H
