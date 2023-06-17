///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:50)

#include "Rendering/RenderingExport.h"

#include "Dx9TextureCube.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::Dx9TextureCube::Dx9TextureCube(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const TextureCube* texture) noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Dx9TextureCube)

void Rendering::Dx9TextureCube::Enable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED int textureUnit) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::Dx9TextureCube::Disable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED int textureUnit) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void* Rendering::Dx9TextureCube::Lock(MAYBE_UNUSED int face, MAYBE_UNUSED int level, MAYBE_UNUSED BufferLocking mode) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return nullptr;
}

void Rendering::Dx9TextureCube::Unlock(MAYBE_UNUSED int face, MAYBE_UNUSED int level) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}
