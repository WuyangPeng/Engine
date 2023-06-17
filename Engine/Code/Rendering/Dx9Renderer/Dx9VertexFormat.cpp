///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:50)

#include "Rendering/RenderingExport.h"

#include "Dx9VertexFormat.h"

#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::Dx9VertexFormat::Dx9VertexFormat(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const VertexFormat* vertexFormat) noexcept
    : ParentType{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::Dx9VertexFormat::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::Dx9VertexFormat::Enable(MAYBE_UNUSED Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1; 
}

void Rendering::Dx9VertexFormat::Disable(MAYBE_UNUSED Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1; 
}
