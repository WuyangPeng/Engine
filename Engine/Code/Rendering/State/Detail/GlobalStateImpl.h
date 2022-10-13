///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/21 10:08)

#ifndef RENDERING_STATE_GLOBAL_STATE_H
#define RENDERING_STATE_GLOBAL_STATE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/State/StateFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GlobalStateImpl
    {
    public:
        using ClassType = GlobalStateImpl;
        using BlendStateSharedPtr = std::shared_ptr<BlendState>;
        using DepthStencilStateSharedPtr = std::shared_ptr<DepthStencilState>;
        using RasterizerStateSharedPtr = std::shared_ptr<RasterizerState>;

    private:
        BlendStateSharedPtr defaultBlendState;
        BlendStateSharedPtr activeBlendState;
        DepthStencilStateSharedPtr defaultDepthStencilState;
        DepthStencilStateSharedPtr activeDepthStencilState;
        RasterizerStateSharedPtr defaultRasterizerState;
        RasterizerStateSharedPtr activeRasterizerState;
    };
}

#endif  // RENDERING_STATE_GLOBAL_STATE_H
