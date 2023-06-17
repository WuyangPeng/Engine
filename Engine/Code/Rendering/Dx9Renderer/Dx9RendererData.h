///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:48)

#ifndef RENDERING_DX9_RENDERER_DX9_RENDERER_DATA_H
#define RENDERING_DX9_RENDERER_DX9_RENDERER_DATA_H

#include "Rendering/RenderingDll.h"

#include "Dx9RendererInput.h"
#include "Rendering/Renderers/RendererData.h"
#include "Rendering/Shaders/AlphaState.h"
#include "Rendering/Shaders/CullState.h"
#include "Rendering/Shaders/DepthState.h"
#include "Rendering/Shaders/OffsetState.h"
#include "Rendering/Shaders/StencilState.h"
#include "Rendering/Shaders/WireState.h"

namespace Rendering
{
    class Dx9RendererData
    {
    public:
        class RenderState
        {
        };

        class SamplerState
        {
        };
    };

}

#endif  // RENDERING_DX9_RENDERER_DX9_RENDERER_DATA_H
