///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/24 11:08)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture2.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"
#include "System/OpenGL/OpenGLTextures.h"

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
           texture->HasMipmaps() &&
           texture->WantAutogenerateMipmaps() &&
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
