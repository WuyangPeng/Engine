///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:28)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture1.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

Rendering::OpenGLTexture1::OpenGLTexture1(const Texture1DSharedPtr& texture1D, const std::string& name)
    : ParentType{ texture1D, name, TextureTarget::Texture1D, TextureTargetBinding::Binding1D }
{
    SetGLHandle(System::GetGLGenTextures());
    System::SetGLBindTexture(TextureTarget::Texture1D, GetGLHandle());

    const auto length = texture1D->GetDimension(0);
    System::SetGLTexturesStorage1D(TextureTarget::Texture1D, GetNumLevels(), GetInternalFormat(), length);

    Initialize();

    System::SetGLBindTexture(TextureTarget::Texture1D, 0);

    CreateStaging();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTexture1::~OpenGLTexture1() noexcept
{
    System::SetGLDeleteTextures(GetGLHandle());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTexture1)

Rendering::ConstTexture1DSharedPtr Rendering::OpenGLTexture1::GetTexture1D() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const Texture1D>(GetGraphicsObject());
}

bool Rendering::OpenGLTexture1::CanAutoGenerateMipmaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto texture = GetTexture();

    return texture && texture->HasMipmaps() && texture->WantAutogenerateMipmaps();
}

void Rendering::OpenGLTexture1::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLTexture1::LoadTextureLevel(int level, const ConstSpanIterator& data)
{
    auto texture = GetTexture();
    if (texture && level < texture->GetNumLevels())
    {
        const auto length = texture->GetDimension(level, 0);

        System::SetGLTexturesSubImage1D(TextureTarget::Texture1D, level, 0, length, GetExternalFormat(), GetExternalType(), &*data.GetCurrent());
    }
}
