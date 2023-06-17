///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:22)

#include "Rendering/RenderingExport.h"

#include "OpenGLMapping.h"
#include "OpenGLVertexFormat.h"
#include "OpenGLVertexFormatArrayDataDetail.h"
#include "OpenGLVertexFormatDataDetail.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::OpenGLVertexFormat::OpenGLVertexFormat(MAYBE_UNUSED Renderer* renderer, const VertexFormat* vertexFormat)
    : ParentType{},
      stride{ vertexFormat != nullptr ? vertexFormat->GetStride() : 0 },
      position{},
      normal{},
      tangent{},
      binormal{},
      texCoord{},
      color{},
      blendIndices{},
      blendWeight{},
      fogCoord{},
      pSize{}
{
    Init(vertexFormat);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

// private
void Rendering::OpenGLVertexFormat::Init(const VertexFormat* vertexFormat)
{
    position.Init(vertexFormat);
    normal.Init(vertexFormat);
    tangent.Init(vertexFormat);
    binormal.Init(vertexFormat);

    texCoord.Init(vertexFormat);
    color.Init(vertexFormat);

    blendIndices.Init(vertexFormat);
    blendWeight.Init(vertexFormat);
    fogCoord.Init(vertexFormat);
    pSize.Init(vertexFormat);
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::OpenGLVertexFormat::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 < stride)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::OpenGLVertexFormat::Enable([[maybe_unused]] Renderer* renderer) noexcept
{
    // 数据指针允许使用顶点缓冲
    RENDERING_CLASS_IS_VALID_1;

    position.Enable(stride);
    normal.Enable(stride);
    tangent.Enable(stride);
    binormal.Enable(stride);

    texCoord.Enable(stride);
    color.Enable(stride);

    blendIndices.Enable(stride);
    blendWeight.Enable(stride);
    fogCoord.Enable(stride);
    pSize.Enable(stride);
}

void Rendering::OpenGLVertexFormat::Disable([[maybe_unused]] Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    position.Disable();
    normal.Disable();
    tangent.Disable();
    binormal.Disable();

    texCoord.Disable();
    color.Disable();

    blendIndices.Disable();
    blendWeight.Disable();
    fogCoord.Disable();
    pSize.Disable();
}
