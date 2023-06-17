///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 12:49)

#include "Rendering/RenderingExport.h"

#include "PlatformTexture3D.h"
#include "Renderer.h"
#include "Detail/PlatformTexture3DImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::PlatformTexture3D::PlatformTexture3D(Renderer* renderer, const Texture3D* texture3D)
    : impl{ CoreTools::ImplCreateUseFactory::Default, renderer, texture3D }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformTexture3D)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformTexture3D, Unlock, int, void)

void Rendering::PlatformTexture3D::Enable(Renderer* renderer, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->Enable(renderer, textureUnit);
}

void Rendering::PlatformTexture3D::Disable(Renderer* renderer, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->Disable(renderer, textureUnit);
}

void* Rendering::PlatformTexture3D::Lock(int level, BufferLocking mode)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->Lock(level, mode);
}
