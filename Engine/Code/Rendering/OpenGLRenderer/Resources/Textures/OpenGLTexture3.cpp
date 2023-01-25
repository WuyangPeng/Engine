///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/24 11:08)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture3.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"
#include "System/OpenGL/OpenGLTextures.h"

Rendering::OpenGLTexture3::OpenGLTexture3(const Texture3DSharedPtr& texture3D, const std::string& name)
    : ParentType{ texture3D, name, TextureTarget::Texture3D, TextureTargetBinding::Binding3D }
{
    SetGLHandle(System::GetGLGenTextures());
    System::SetGLBindTexture(TextureTarget::Texture3D, GetGLHandle());

    const auto width = texture3D->GetDimension(0);
    const auto height = texture3D->GetDimension(1);
    const auto depth = texture3D->GetDimension(2);
    System::SetGLTexturesStorage3D(TextureTarget::Texture3D, GetNumLevels(), GetInternalFormat(), width, height, depth);

    Initialize();

    System::SetGLBindTexture(TextureTarget::Texture3D, 0);

    CreateStaging();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTexture3::~OpenGLTexture3() noexcept
{
    System::SetGLDeleteTextures(GetGLHandle());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTexture3)

Rendering::ConstTexture3DSharedPtr Rendering::OpenGLTexture3::GetTexture3D() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const Texture3D>(GetGraphicsObject());
}

bool Rendering::OpenGLTexture3::CanAutoGenerateMipmaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto texture = GetTexture();

    return texture &&
           texture->HasMipmaps() &&
           texture->WantAutogenerateMipmaps();
}

void Rendering::OpenGLTexture3::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLTexture3::LoadTextureLevel(int level, const ConstSpanIterator& data)
{
    auto texture = GetTexture();
    if (texture && level < texture->GetNumLevels())
    {
        const auto width = texture->GetDimension(level, 0);
        const auto height = texture->GetDimension(level, 1);
        const auto depth = texture->GetDimension(level, 2);

        System::SetGLTexturesSubImage3D(TextureTarget::Texture2D, level, 0, 0, 0, width, height, depth, GetExternalFormat(), GetExternalType(), &*data.GetCurrent());
    }
}
