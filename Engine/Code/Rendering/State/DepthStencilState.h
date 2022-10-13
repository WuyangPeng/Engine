///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/18 19:11)

#ifndef RENDERING_STATE_DEPTH_STENCIL_STATE_H
#define RENDERING_STATE_DEPTH_STENCIL_STATE_H

#include "Rendering/RenderingDll.h"

#include "DepthStencilStateFace.h"
#include "StateFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Base/GraphicsObject.h"

#include <string>

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE DepthStencilState : public GraphicsObject
    {
    public:
        using ClassType = DepthStencilState;
        using ParentType = GraphicsObject;

    public:
        explicit DepthStencilState(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DepthStencilState);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        bool depthEnable;
        DepthStencilStateWriteMask writeMask;
        DepthStencilStateComparison comparison;
        bool stencilEnable;
        int stencilReadMask;
        int stencilWriteMask;
        DepthStencilStateFace frontFace;
        DepthStencilStateFace backFace;
        int reference;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(DepthStencilState);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(DepthStencilState);
}

#endif  // RENDERING_STATE_DEPTH_STENCIL_STATE_H
