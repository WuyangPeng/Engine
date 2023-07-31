///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/22 13:07)

#ifndef RENDERING_LOCAL_EFFECTS_VERTEX_COLOR_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_VERTEX_COLOR_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualEffect.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VertexColorEffect : public VisualEffect
    {
    public:
        using ClassType = VertexColorEffect;
        using ParentType = VisualEffect;

    public:
        VertexColorEffect(ProgramFactory& factory, const BaseRendererSharedPtr& baseRenderer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer) override;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_VERTEX_COLOR_EFFECT_H