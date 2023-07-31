///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/22 13:09)

#include "Rendering/RenderingExport.h"

#include "VertexColorEffect.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Shaders/Shader.h"

Rendering::VertexColorEffect::VertexColorEffect(ProgramFactory& factory, const BaseRendererSharedPtr& baseRenderer)
    : ParentType{ factory,
                  baseRenderer,
                  "Resource/Shader/VertexColorEffect.vs",
                  "Resource/Shader/VertexColorEffect.ps" }
{
    GetVertexShader()->Set("projectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VertexColorEffect)

void Rendering::VertexColorEffect::SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::SetProjectionViewWorldMatrixConstant(buffer);

    GetVertexShader()->Set("projectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
}
