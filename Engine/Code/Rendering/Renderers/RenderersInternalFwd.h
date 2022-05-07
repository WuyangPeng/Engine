///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/19 19:24)

#ifndef RENDERING_RENDERERS_INTERNAL_FWD_H
#define RENDERING_RENDERERS_INTERNAL_FWD_H

#include "RenderersFwd.h"

namespace Rendering
{
    using PlatformTexture2DSharedPtr = std::shared_ptr<PlatformTexture2D>;

    class RendererParameterImpl;

    class RendererFactory;

    class RendererImpl;
    class RendererInputImpl;
}

#endif  // RENDERING_RENDERERS_INTERNAL_FWD_H