///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:29)

#include "Rendering/RenderingExport.h"

#include "LoadTextureDetail.h"
#include "Texture1DArray.h"
#include "Texture2DArray.h"
#include "TextureCubeArray.h"
#include "TextureDepthStencil.h"
#include "TextureRenderTarget.h"
#include "CoreTools/Helper/ExceptionMacro.h"

// static
Rendering::TextureSharedPtr Rendering::LoadTexture::LoadFromFile(const System::String& name)
{
    ReadFileManager inFile{ name };

    // ���ȶ�ȡ����ͷ����Ϣ��
    // һЩͷ�ֶ�û�б�Ҫ��������,�����Ǵ������ļ�,
    // �Է�����������Ҫ����Ϣ,�����贴��һ���������
    auto type = GraphicsObjectType::None;
    inFile.Read(sizeof(GraphicsObjectType), &type);

    switch (type)
    {
        case GraphicsObjectType::Texture1:
        {
            return CreateTexture1D<TextureSharedPtr, 1>(inFile);
        }
        case GraphicsObjectType::Texture2:
        {
            return CreateTexture2D<TextureSharedPtr, 2, Texture2D>(inFile);
        }
        case GraphicsObjectType::TextureRenderTarget:
        {
            return CreateTexture2D<TextureSharedPtr, 2, TextureRenderTarget>(inFile);
        }
        case GraphicsObjectType::TextureDepthStencil:
        {
            return CreateTexture2D<TextureSharedPtr, 2, TextureDepthStencil>(inFile);
        }
        case GraphicsObjectType::Texture3:
        {
            return CreateTexture3D<TextureSharedPtr, 3>(inFile);
        }
        case GraphicsObjectType::Texture1Array:
        {
            return CreateTexture1DArray<TextureSharedPtr, 1>(inFile);
        }
        case GraphicsObjectType::Texture2Array:
        {
            return CreateTexture2DArray<TextureSharedPtr, 2>(inFile);
        }
        case GraphicsObjectType::TextureCube:
        {
            return CreateTextureCube<TextureSharedPtr, 2>(inFile);
        }
        case GraphicsObjectType::TextureCubeArray:
        {
            return CreateTextureCubeArray<TextureSharedPtr, 2>(inFile);
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("��Ч���������͡�\n"s));
        }
    }
}

// static
Rendering::Texture1DSharedPtr Rendering::LoadTexture::Load1DFromFile(const System::String& name)
{
    ReadFileManager inFile{ name };

    // ���ȶ�ȡ����ͷ����Ϣ��
    // һЩͷ�ֶ�û�б�Ҫ��������,�����Ǵ������ļ�,
    // �Է�����������Ҫ����Ϣ,�����贴��һ���������
    auto type = GraphicsObjectType::None;
    inFile.Read(sizeof(GraphicsObjectType), &type);

    switch (type)
    {
        case GraphicsObjectType::Texture1:
        {
            return CreateTexture1D<Texture1DSharedPtr, 1>(inFile);
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("�������Ͳ���TextureType::Texture1D��\n"s));
        }
    }
}

// static
Rendering::Texture2DSharedPtr Rendering::LoadTexture::Load2DFromFile(MAYBE_UNUSED const System::String& name)
{
    ReadFileManager inFile{ name };

    // ���ȶ�ȡ����ͷ����Ϣ��
    // һЩͷ�ֶ�û�б�Ҫ��������,�����Ǵ������ļ�,
    // �Է�����������Ҫ����Ϣ,�����贴��һ���������
    auto type = GraphicsObjectType::None;
    inFile.Read(sizeof(GraphicsObjectType), &type);

    switch (type)
    {
        case GraphicsObjectType::Texture2:
        {
            return CreateTexture2D<Texture2DSharedPtr, 2, Texture2D>(inFile);
        }
        case GraphicsObjectType::TextureRenderTarget:
        {
            return CreateTexture2D<Texture2DSharedPtr, 2, TextureRenderTarget>(inFile);
        }
        case GraphicsObjectType::TextureDepthStencil:
        {
            return CreateTexture2D<Texture2DSharedPtr, 2, TextureDepthStencil>(inFile);
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("�������Ͳ���TextureType::Texture2D��\n"s));
        }
    }
}

// static
Rendering::Texture3DSharedPtr Rendering::LoadTexture::Load3DFromFile(MAYBE_UNUSED const System::String& name)
{
    ReadFileManager inFile{ name };

    // ���ȶ�ȡ����ͷ����Ϣ��
    // һЩͷ�ֶ�û�б�Ҫ��������,�����Ǵ������ļ�,
    // �Է�����������Ҫ����Ϣ,�����贴��һ���������
    auto type = GraphicsObjectType::None;
    inFile.Read(sizeof(GraphicsObjectType), &type);

    switch (type)
    {
        case GraphicsObjectType::Texture3:
        {
            return CreateTexture3D<Texture3DSharedPtr, 3>(inFile);
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("�������Ͳ���TextureType::Texture3D��\n"s));
        }
    }
}

// static
Rendering::TextureCubeSharedPtr Rendering::LoadTexture::LoadCubeFromFile(MAYBE_UNUSED const System::String& name)
{
    ReadFileManager inFile{ name };

    // ���ȶ�ȡ����ͷ����Ϣ��
    // һЩͷ�ֶ�û�б�Ҫ��������,�����Ǵ������ļ�,
    // �Է�����������Ҫ����Ϣ,�����贴��һ���������
    auto type = GraphicsObjectType::None;
    inFile.Read(sizeof(GraphicsObjectType), &type);

    switch (type)
    {
        case GraphicsObjectType::TextureCube:
        {
            return CreateTextureCube<TextureCubeSharedPtr, 2>(inFile);
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("�������Ͳ���TextureType::TextureCube��\n"s));
        }
    }
}
