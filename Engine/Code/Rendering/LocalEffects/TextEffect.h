///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/05 10:58)

#ifndef RENDERING_RENDERERS_TEXT_EFFECT_H
#define RENDERING_RENDERERS_TEXT_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TextEffect
    {
    public:
        using ClassType = TextEffect;

    public:
        NODISCARD std::shared_ptr<const VertexShader> GetVertexShader() const;
        NODISCARD std::shared_ptr<const PixelShader> GetPixelShader() const;

        NODISCARD std::shared_ptr<const ConstantBuffer> GetTranslate() const;
        NODISCARD std::shared_ptr<const ConstantBuffer> GetColor() const;
    };
}

#endif  // RENDERING_RENDERERS_TEXT_EFFECT_H
