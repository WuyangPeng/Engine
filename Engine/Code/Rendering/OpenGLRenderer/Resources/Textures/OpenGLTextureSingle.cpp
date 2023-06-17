///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:27)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureSingle.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/OpenGLRenderer/Detail/Resources/Textures/OpenGLTextureSingleImpl.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, OpenGLTextureSingle)

Rendering::OpenGLTextureSingle::OpenGLTextureSingle(const TextureSingleSharedPtr& textureSingle, const std::string& name, TextureTarget target, TextureTargetBinding targetBinding)
    : ParentType{ textureSingle, name, target, targetBinding }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTextureSingle::~OpenGLTextureSingle() noexcept
{
    CoreTools::NoexceptNoReturn(*this, &ClassType::DeleteBuffers);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::OpenGLTextureSingle::DeleteBuffers() const
{
    for (auto level = 0; level < GetNumLevels(); ++level)
    {
        System::SetGLDeleteBuffers(impl->GetLevelPixelUnpackBuffer(level));
        System::SetGLDeleteBuffers(impl->GetLevelPixelPackBuffer(level));
    }
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTextureSingle)

Rendering::ConstTextureSingleSharedPtr Rendering::OpenGLTextureSingle::GetTextureSingle() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const TextureSingle>(GetGraphicsObject());
}

void Rendering::OpenGLTextureSingle::Initialize()
{
    const auto prevBinding = GetGLInteger(GetTargetBinding());
    System::SetGLBindTexture(GetTarget(), GetGLHandle());

    System::SetGLPixelStore(System::PixelStore::UnpackAlignment, 1);
    System::SetGLPixelStore(System::PixelStore::PackAlignment, 1);

    System::SetGLTexturesParameter(GetTarget(), System::TextureParameter::TextureBaseLevel, 0);
    System::SetGLTexturesParameter(GetTarget(), System::TextureParameter::TextureMaxLevel, GetNumLevels() - 1);

    auto texture = GetTexture();

    if (CanAutoGenerateMipmaps())
    {
        const auto data = texture->GetDataFor(0, 0);

        LoadTextureLevel(0, data);
        GenerateMipmaps();
    }
    else
    {
        for (auto level = 0; level < GetNumLevels(); ++level)
        {
            const auto data = texture->GetDataFor(0, level);

            LoadTextureLevel(level, data);
        }
    }

    System::SetGLBindTexture(GetTarget(), prevBinding);
}

bool Rendering::OpenGLTextureSingle::Update()
{
    RENDERING_CLASS_IS_VALID_9;

    auto texture = GetTexture();

    if (CanAutoGenerateMipmaps())
    {
        if (!Update(0))
        {
            return false;
        }
        GenerateMipmaps();
    }
    else
    {
        const auto count = texture->GetNumLevels();
        for (auto level = 0; level < count; ++level)
        {
            if (!Update(level))
            {
                return false;
            }
        }
    }

    return true;
}

bool Rendering::OpenGLTextureSingle::CopyCpuToGpu()
{
    RENDERING_CLASS_IS_VALID_9;

    auto texture = GetTexture();

    if (CanAutoGenerateMipmaps())
    {
        if (!CopyCpuToGpu(0))
        {
            return false;
        }
        GenerateMipmaps();
    }
    else
    {
        const auto count = texture->GetNumLevels();
        for (auto level = 0; level < count; ++level)
        {
            if (!CopyCpuToGpu(level))
            {
                return false;
            }
        }
    }

    return true;
}

bool Rendering::OpenGLTextureSingle::CopyGpuToCpu()
{
    RENDERING_CLASS_IS_VALID_9;

    auto texture = GetTexture();
    const auto count = texture->GetNumLevels();
    for (auto level = 0; level < count; ++level)
    {
        if (!CopyGpuToCpu(level))
        {
            return false;
        }
    }

    return true;
}

bool Rendering::OpenGLTextureSingle::Update(int level)
{
    RENDERING_CLASS_IS_VALID_9;

    auto texture = GetTexture();
    if (texture->GetUsage() != UsageType::DynamicUpdate)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("纹理使用必须为DynamicUpdate。"));
    }

    return DoCopyCpuToGpu(level);
}

bool Rendering::OpenGLTextureSingle::CopyCpuToGpu(int level)
{
    RENDERING_CLASS_IS_VALID_9;

    if (!PreparedForCopy(BufferLocking::WriteOnly))
    {
        return false;
    }

    return DoCopyCpuToGpu(level);
}

bool Rendering::OpenGLTextureSingle::CopyGpuToCpu(int level)
{
    RENDERING_CLASS_IS_VALID_9;

    if (!PreparedForCopy(BufferLocking::ReadOnly))
    {
        return false;
    }

    auto texture = boost::polymorphic_pointer_cast<Texture>(GetGraphicsObject());

    const auto count = texture->GetNumLevels();
    if (level >= count)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("纹理级别超出范围。"));
    }

    auto pixBuffer = impl->GetLevelPixelPackBuffer(level);
    if (0 == pixBuffer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未为级别") + System::ToString(level) + SYSTEM_TEXT("定义暂存缓冲区。"));
    }

    const auto data = texture->GetDataFor(0, level);
    const auto numBytes = texture->GetNumLevelBytes(level);
    if (0 == numBytes)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("没有纹理级别") + System::ToString(level) + SYSTEM_TEXT("的目标数据。"));
    }

    auto const textureTarget = GetTarget();
    System::SetGLBindTexture(textureTarget, GetGLHandle());

    System::SetGLBindBuffer(System::BindBuffer::PixePackBuffer, pixBuffer);
    System::GetGLTexturesImage(textureTarget, level, GetExternalFormat(), GetExternalType(), nullptr);
    System::GetGLBufferSubData(System::BindBuffer::PixePackBuffer, 0, numBytes, &*data.GetCurrent());
    System::SetGLBindBuffer(System::BindBuffer::PixePackBuffer, 0);

    System::SetGLBindTexture(textureTarget, 0);

    return true;
}

bool Rendering::OpenGLTextureSingle::GenerateMipmaps()
{
    RENDERING_CLASS_IS_VALID_9;

    if (CanAutoGenerateMipmaps())
    {
        const auto prevBinding = GetGLInteger(GetTargetBinding());
        System::SetGLBindTexture(GetTarget(), GetGLHandle());

        System::SetGLGenerateMipmap(GetTarget());

        System::SetGLBindTexture(GetTarget(), prevBinding);

        return true;
    }

    return false;
}

bool Rendering::OpenGLTextureSingle::DoCopyCpuToGpu(MAYBE_UNUSED int level)
{
    RENDERING_CLASS_IS_VALID_9;

    auto texture = boost::polymorphic_pointer_cast<Texture>(GetGraphicsObject());

    if (CanAutoGenerateMipmaps() && (level > 0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无法更新GPU中自动生成的mipmap。"));
    }

    const auto count = texture->GetNumLevels();
    if (level >= count)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("纹理级别超出范围。"));
    }

    const auto data = texture->GetDataFor(0, level);
    const auto numBytes = texture->GetNumLevelBytes(level);
    if (0 == numBytes)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("没有纹理级别") + System::ToString(level) + SYSTEM_TEXT("的源数据"));
    }

    const auto textureTarget = GetTarget();
    System::SetGLBindTexture(textureTarget, GetGLHandle());

    auto pixBuffer = impl->GetLevelPixelUnpackBuffer(level);
    if (0 != pixBuffer)
    {
        System::SetGLBindBuffer(System::BindBuffer::PixelUnpackBuffer, pixBuffer);
        System::SetGLBufferSubData(System::BindBuffer::PixelUnpackBuffer, 0, numBytes, &*data.GetCurrent());
        LoadTextureLevel(level, ConstSpanIterator{ data.GetBegin(), data.GetBegin() });
        System::SetGLBindBuffer(System::BindBuffer::PixelUnpackBuffer, 0);
    }
    else
    {
        LoadTextureLevel(level, ConstSpanIterator{ data.GetBegin(), data.GetEnd(), data.GetCurrent() });
    }

    System::SetGLBindTexture(textureTarget, 0);

    return true;
}

void Rendering::OpenGLTextureSingle::CreateStaging()
{
    RENDERING_CLASS_IS_VALID_9;

    auto texture = GetTexture();
    const auto copyType = texture->GetCopy();

    const auto createPixelUnpackBuffers = (copyType == CopyType::CpuToStaging) || (copyType == CopyType::Bidirectional);

    const auto createPixelPackBuffers = (copyType == CopyType::StagingToCpu) || (copyType == CopyType::Bidirectional);

    constexpr auto usage = System::BufferUsage::Dynamic;

    if (createPixelUnpackBuffers)
    {
        for (auto level = 0; level < GetNumLevels(); ++level)
        {
            auto pixBuffer = impl->GetLevelPixelUnpackBuffer(level);
            if (0 == pixBuffer)
            {
                const auto numBytes = texture->GetNumLevelBytes(level);

                pixBuffer = System::GetGLGenBuffers();
                impl->SetLevelPixelUnpackBuffer(level, pixBuffer);
                System::SetGLBindBuffer(System::BindBuffer::PixelUnpackBuffer, pixBuffer);
                System::SetGLBufferData(System::BindBuffer::PixelUnpackBuffer, numBytes, nullptr, usage);
                System::SetGLBindBuffer(System::BindBuffer::PixelUnpackBuffer, 0);
            }
        }
    }

    if (createPixelPackBuffers)
    {
        for (auto level = 0; level < GetNumLevels(); ++level)
        {
            auto pixBuffer = impl->GetLevelPixelPackBuffer(level);

            if (0 == pixBuffer)
            {
                const auto numBytes = texture->GetNumLevelBytes(level);

                pixBuffer = System::GetGLGenBuffers();
                impl->SetLevelPixelPackBuffer(level, pixBuffer);

                System::SetGLBindBuffer(System::BindBuffer::PixePackBuffer, pixBuffer);
                System::SetGLBufferData(System::BindBuffer::PixePackBuffer, numBytes, nullptr, usage);
                System::SetGLBindBuffer(System::BindBuffer::PixePackBuffer, 0);
            }
        }
    }
}
