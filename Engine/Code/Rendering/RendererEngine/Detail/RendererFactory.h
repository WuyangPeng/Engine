///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 15:01)

#ifndef RENDERING_RENDERER_ENGINE_RENDERER_FACTORY_H
#define RENDERING_RENDERER_ENGINE_RENDERER_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/RendererEngine/RendererEngineInternalFwd.h"

#include <string>

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererFactory
    {
    public:
        using RendererSharedPtr = std::shared_ptr<BaseRendererImpl>;

    public:
        NODISCARD static RendererSharedPtr Create(RendererTypes type, const RenderingEnvironment& renderingEnvironment);
        NODISCARD static RendererSharedPtr Create(const EnvironmentParameter& environmentParameter, const std::string& fileName);
    };
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERER_FACTORY_H
