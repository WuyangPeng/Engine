/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/08 15:55)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureSingle.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/OpenGLRenderer/Detail/Resources/Textures/OpenGLTextureSingleImpl.h"
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

Rendering::TextureSingleSharedPtr Rendering::OpenGLTextureSingle::GetTextureSingle()
{
    RENDERING_CLASS_IS_VALID_9;

    return boost::polymorphic_pointer_cast<TextureSingle>(GetGraphicsObject());
}

void Rendering::OpenGLTextureSingle::Initialize()
{
    const auto prevBinding = GetGLInteger(GetTargetBinding());
    SetGLBindTexture(GetTarget(), GetGLHandle());

    SetGLPixelStore(System::PixelStore::UnpackAlignment, 1);
    SetGLPixelStore(System::PixelStore::PackAlignment, 1);

    SetGLTexturesParameter(GetTarget(), System::TextureParameter::TextureBaseLevel, 0);
    SetGLTexturesParameter(GetTarget(), System::TextureParameter::TextureMaxLevel, GetNumLevels() - 1);

    const auto texture = GetTexture();

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

    SetGLBindTexture(GetTarget(), prevBinding);
}

bool Rendering::OpenGLTextureSingle::Update()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto texture = GetTexture();

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
        for (auto level = 0; level < texture->GetNumLevels(); ++level)
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

    const auto texture = GetTexture();

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
        for (auto level = 0; level < texture->GetNumLevels(); ++level)
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

    const auto texture = GetTexture();

    for (auto level = 0; level < texture->GetNumLevels(); ++level)
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

    if (const auto texture = GetTexture();
        texture->GetUsage() != UsageType::DynamicUpdate)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����ʹ�ñ���ΪDynamicUpdate��"));
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

    const auto texture = GetTextureSingle();

    if (texture->GetNumLevels() <= level)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����𳬳���Χ��"));
    }

    const auto pixBuffer = impl->GetLevelPixelPackBuffer(level);
    if (pixBuffer == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("δΪ����") + System::ToString(level) + SYSTEM_TEXT("�����ݴ滺������"));
    }

    const auto data = texture->GetDataFor(0, level);
    const auto numBytes = texture->GetNumLevelBytes(level);
    if (numBytes == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("û��������") + System::ToString(level) + SYSTEM_TEXT("��Ŀ�����ݡ�"));
    }

    auto const textureTarget = GetTarget();
    SetGLBindTexture(textureTarget, GetGLHandle());

    SetGLBindBuffer(System::BindBuffer::PixelUnpackBuffer, pixBuffer);
    GetGLTexturesImage(textureTarget, level, GetExternalFormat(), GetExternalType(), nullptr);
    GetGLBufferSubData(System::BindBuffer::PixelPackBuffer, 0, numBytes, &*data.GetCurrent());
    SetGLBindBuffer(System::BindBuffer::PixelPackBuffer, 0);

    SetGLBindTexture(textureTarget, 0);

    return true;
}

bool Rendering::OpenGLTextureSingle::GenerateMipmaps()
{
    RENDERING_CLASS_IS_VALID_9;

    if (CanAutoGenerateMipmaps())
    {
        const auto prevBinding = GetGLInteger(GetTargetBinding());
        SetGLBindTexture(GetTarget(), GetGLHandle());

        SetGLGenerateMipmap(GetTarget());

        SetGLBindTexture(GetTarget(), prevBinding);

        return true;
    }

    return false;
}

bool Rendering::OpenGLTextureSingle::DoCopyCpuToGpu(int level)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto texture = GetTexture();

    if (CanAutoGenerateMipmaps() && (0 < level))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�޷�����GPU���Զ����ɵ�mipmap��"));
    }

    if (texture->GetNumLevels() <= level)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����𳬳���Χ��"));
    }

    const auto data = texture->GetDataFor(0, level);
    const auto numBytes = texture->GetNumLevelBytes(level);
    if (numBytes == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("û��������") + System::ToString(level) + SYSTEM_TEXT("��Դ����"));
    }

    const auto textureTarget = GetTarget();
    SetGLBindTexture(textureTarget, GetGLHandle());

    if (const auto pixBuffer = impl->GetLevelPixelUnpackBuffer(level);
        pixBuffer != 0)
    {
        SetGLBindBuffer(System::BindBuffer::PixelUnpackBuffer, pixBuffer);
        SetGLBufferSubData(System::BindBuffer::PixelUnpackBuffer, 0, numBytes, data.GetData());
        LoadTextureLevel(level, ConstSpanIterator{ data.GetBegin(), data.GetBegin() });
        SetGLBindBuffer(System::BindBuffer::PixelUnpackBuffer, 0);
    }
    else
    {
        LoadTextureLevel(level, ConstSpanIterator{ data.GetBegin(), data.GetEnd(), data.GetCurrent() });
    }

    SetGLBindTexture(textureTarget, 0);

    return true;
}

void Rendering::OpenGLTextureSingle::CreateStaging()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto texture = GetTexture();
    const auto copyType = texture->GetCopy();

    const auto createPixelUnpackBuffers = (copyType == CopyType::CpuToStaging) || (copyType == CopyType::Bidirectional);

    const auto createPixelPackBuffers = (copyType == CopyType::StagingToCpu) || (copyType == CopyType::Bidirectional);

    constexpr auto usage = System::BufferUsage::Dynamic;

    if (createPixelUnpackBuffers)
    {
        for (auto level = 0; level < GetNumLevels(); ++level)
        {
            if (auto pixBuffer = impl->GetLevelPixelUnpackBuffer(level);
                pixBuffer == 0)
            {
                const auto numBytes = texture->GetNumLevelBytes(level);

                pixBuffer = System::GetGLGenBuffers();
                impl->SetLevelPixelUnpackBuffer(level, pixBuffer);
                SetGLBindBuffer(System::BindBuffer::PixelUnpackBuffer, pixBuffer);
                SetGLBufferData(System::BindBuffer::PixelUnpackBuffer, numBytes, nullptr, usage);
                SetGLBindBuffer(System::BindBuffer::PixelUnpackBuffer, 0);
            }
        }
    }

    if (createPixelPackBuffers)
    {
        for (auto level = 0; level < GetNumLevels(); ++level)
        {
            if (auto pixBuffer = impl->GetLevelPixelPackBuffer(level);
                pixBuffer == 0)
            {
                const auto numBytes = texture->GetNumLevelBytes(level);

                pixBuffer = System::GetGLGenBuffers();
                impl->SetLevelPixelPackBuffer(level, pixBuffer);

                SetGLBindBuffer(BindBuffer::PixelPackBuffer, pixBuffer);
                SetGLBufferData(BindBuffer::PixelPackBuffer, numBytes, nullptr, usage);
                SetGLBindBuffer(BindBuffer::PixelPackBuffer, 0);
            }
        }
    }
}
