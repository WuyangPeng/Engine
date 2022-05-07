///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/21 19:12)

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
        NODISCARD static RendererSharedPtr Create(RendererTypes type, const RendererBasis& basis);
        NODISCARD static RendererSharedPtr Create(const std::string& fileName);
        NODISCARD static RendererInputSharedPtr CreateInput(RendererTypes type);

    private:
        NODISCARD static RendererSharedPtr CreateDefault(const RendererBasis& basis);
        NODISCARD static RendererInputSharedPtr CreateDefaultInput();
    };
}

#endif  // RENDERING_RENDERERS_RENDERER_FACTORY_H
