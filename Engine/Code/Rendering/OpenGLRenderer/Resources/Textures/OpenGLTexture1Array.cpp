///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:28)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture1Array.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

Rendering::OpenGLTexture1Array::OpenGLTexture1Array(const Texture1DArraySharedPtr& texture1Array, const std::string& name)
    : ParentType{ texture1Array, name, TextureTarget::Texture1DArray, TextureTargetBinding::Binding1DArray }
{
    SetGLHandle(System::GetGLGenTextures());
    System::SetGLBindTexture(TextureTarget::Texture1DArray, GetGLHandle());

    const auto length = texture1Array->GetDimension(0);
    const auto numItems = texture1Array->GetNumItems();
    System::SetGLTexturesStorage2D(TextureTarget::Texture1DArray, GetNumLevels(), GetInternalFormat(), length, numItems);

    Initialize();

    System::SetGLBindTexture(TextureTarget::Texture1DArray, 0);

    CreateStaging();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTexture1Array::~OpenGLTexture1Array() noexcept
{
    System::SetGLDeleteTextures(GetGLHandle());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTexture1Array)

Rendering::ConstTexture1DArraySharedPtr Rendering::OpenGLTexture1Array::GetTexture1DArray() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const Texture1DArray>(GetGraphicsObject());
}

bool Rendering::OpenGLTexture1Array::CanAutoGenerateMipmaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto texture = GetTexture();

    return texture && texture->HasMipMaps() && texture->WantAutoGenerateMipMaps();
}

void Rendering::OpenGLTexture1Array::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLTexture1Array::LoadTextureLevel(int item, int level, const ConstSpanIterator& data)
{
    RENDERING_CLASS_IS_VALID_9;

    auto texture = GetTexture();
    if (texture && level < texture->GetNumLevels())
    {
        auto const length = texture->GetDimension(level, 0);

        System::SetGLTexturesSubImage2D(TextureTarget::Texture1DArray, level, 0, item, length, 1, GetExternalFormat(), GetExternalType(), &*data.GetCurrent());
    }
}

bool Rendering::OpenGLTexture1Array::Update(MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLTexture1Array::CopyGpuToCpu(MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLTexture1Array::CopyCpuToGpu(MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLTexture1Array::GetNumActiveElements()
{
    CoreTools::DisableNoexcept();

    return false;
}
