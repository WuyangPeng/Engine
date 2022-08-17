///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/04 11:54)

#ifndef RENDERING_RENDERERS_FONT_H
#define RENDERING_RENDERERS_FONT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/LocalEffects/LocalEffectsFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Font
    {
    public:
        using ClassType = Font;

    public:
        NODISCARD std::shared_ptr<const VertexBuffer> GetVertexBuffer() const;
        NODISCARD std::shared_ptr<const IndexBuffer> GetIndexBuffer() const;
        NODISCARD std::shared_ptr<const TextEffect> GetTextEffect() const;
    };
}

#endif  // RENDERING_RENDERERS_FONT_H
