///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/04 21:52)

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
