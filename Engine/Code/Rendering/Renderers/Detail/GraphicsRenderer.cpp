///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/06 0:55)

#include "Rendering/RenderingExport.h"

#include "GraphicsRenderer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/LocalEffects/Font.h"
#include "Rendering/LocalEffects/TextEffect.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"

Rendering::GraphicsRenderer::GraphicsRenderer(RendererTypes rendererTypes, const RenderingEnvironment& renderingEnvironment, const RendererBasis& basis)
    : ParentType{ rendererTypes, renderingEnvironment, basis },
      rendererObject{},
      rendererObjectMutex{},
      rendererDrawTarget{},
      rendererDrawTargetMutex{},
      inputLayoutManager{ nullptr },
      allowOcclusionQuery{ false },
      warnOnNonemptyBridges{ true }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::GraphicsRenderer::IsValid() const noexcept
{
    if (ParentType::IsValid())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26440)

void Rendering::GraphicsRenderer::SetFont(MAYBE_UNUSED const FontSharedPtr& font)
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::GraphicsRenderer::Bind(MAYBE_UNUSED const ConstGraphicsObjectSharedPtr& object)
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::GraphicsRenderer::Unbind(MAYBE_UNUSED const ConstDrawTargetSharedPtr& object)
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::GraphicsRenderer::Unbind(MAYBE_UNUSED const ConstGraphicsObjectSharedPtr& object)
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::GraphicsRenderer::Bind(MAYBE_UNUSED const ConstDrawTargetSharedPtr& object)
{
    RENDERING_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP