///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:28)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture2.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

Rendering::OpenGLTexture2::OpenGLTexture2(const Texture2DSharedPtr& texture2D, const std::string& name)
    : ParentType{ texture2D, name, TextureTarget::Texture2D, TextureTargetBinding::Binding2D }
{
    SetGLHandle(System::GetGLGenTextures());
    System::SetGLBindTexture(TextureTarget::Texture2D, GetGLHandle());

    const auto width = texture2D->GetDimension(0);
    const auto height = texture2D->GetDimension(1);
    System::SetGLTexturesStorage2D(TextureTarget::Texture2D, GetNumLevels(), GetInternalFormat(), width, height);

    Initialize();

    System::SetGLBindTexture(TextureTarget::Texture2D, 0);

    CreateStaging();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTexture2::~OpenGLTexture2() noexcept
{
    System::SetGLDeleteTextures(GetGLHandle());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTexture2)

Rendering::ConstTexture2DSharedPtr Rendering::OpenGLTexture2::GetTexture2D() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const Texture2D>(GetGraphicsObject());
}

bool Rendering::OpenGLTexture2::CanAutoGenerateMipmaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto texture = GetTexture2D();

    return texture &&
           texture->HasMipMaps() &&
           texture->WantAutoGenerateMipMaps() &&
           !texture->IsShared();
}

void Rendering::OpenGLTexture2::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLTexture2::LoadTextureLevel(int level, const ConstSpanIterator& data)
{
    auto texture = GetTexture();
    if (texture && level < texture->GetNumLevels())
    {
        const auto width = texture->GetDimension(level, 0);
        const auto height = texture->GetDimension(level, 1);

        System::SetGLTexturesSubImage2D(TextureTarget::Texture2D, level, 0, 0, width, height, GetExternalFormat(), GetExternalType(), &*data.GetCurrent());
    }
}

bool Rendering::OpenGLTexture2::Update(MAYBE_UNUSED int item, MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLTexture2::CopyGpuToCpu(MAYBE_UNUSED int item, MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLTexture2::CopyCpuToGpu(MAYBE_UNUSED int item, MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLTexture2::GetNumActiveElements()
{
    CoreTools::DisableNoexcept();

    return false;
}
