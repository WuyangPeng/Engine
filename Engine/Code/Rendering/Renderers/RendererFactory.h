///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:37)

#ifndef RENDERING_RENDERERS_RENDERER_FACTORY_H
#define RENDERING_RENDERERS_RENDERER_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "Flags/RendererTypes.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Renderers/RenderersInternalFwd.h"

#include <string>

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererFactory
    {
    public:
        using RendererSharedPtr = std::shared_ptr<RendererImpl>;
        using RendererInputSharedPtr = std::shared_ptr<RendererInputImpl>;

    public:
        NODISCARD static RendererSharedPtr Create(const EnvironmentParameter& environmentParameter, RendererTypes type, const RendererParameter& basis, const RenderingEnvironment& renderingEnvironment);
        NODISCARD static RendererSharedPtr Create(const EnvironmentParameter& environmentParameter, const std::string& fileName);
        NODISCARD static RendererInputSharedPtr CreateInput(RendererTypes type);

    private:
        NODISCARD static RendererSharedPtr CreateDefault(const RendererParameter& basis, const RenderingEnvironment& renderingEnvironment);
        NODISCARD static RendererInputSharedPtr CreateDefaultInput();
    };
}

#endif  // RENDERING_RENDERERS_RENDERER_FACTORY_H
