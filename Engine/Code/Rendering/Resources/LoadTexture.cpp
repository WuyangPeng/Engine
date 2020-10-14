// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 15:33)

#include "Rendering/RenderingExport.h"

#include "LoadTextureDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
 

// static
Rendering::TextureSharedPtr  Rendering::LoadTexture
      ::LoadFromFile (const System::String& name)
{
	ReadFileManager inFile{ name };
    
	// ���ȶ�ȡ����ͷ����Ϣ��
	// һЩͷ�ֶ�û�б�Ҫ��������,�����Ǵ������ļ�,
	// �Է�����������Ҫ����Ϣ,�����贴��һ���������
	TextureData data;
	data.ReadFromFile(inFile);    
  
    switch (data.GetTextureType())
    {
        case TextureFlags::Texture1D:
        {
			return CreateTexture1DPtr<TextureSharedPtr,1>(data,inFile);			
        }
        case TextureFlags::Texture2D:
        {
			return CreateTexture2DPtr<TextureSharedPtr,2>(data,inFile);			
        }
        case TextureFlags::Texture3D:
        {
			return CreateTexture3DPtr<TextureSharedPtr,3>(data,inFile);	
        }
        case TextureFlags::TextureCube:
        {
			return CreateTextureCubePtr<TextureSharedPtr,2>(data,inFile);	
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("��Ч���������͡�\n"s));
        }
    }	
}

// static
Rendering::Texture1DSharedPtr Rendering::LoadTexture
        ::Load1DFromFile (const System::String& name)
{
	ReadFileManager inFile{ name };
    
	// ���ȶ�ȡ����ͷ����Ϣ��
	// һЩͷ�ֶ�û�б�Ҫ��������,�����Ǵ������ļ�,
	// �Է�����������Ҫ����Ϣ,�����贴��һ���������
	TextureData data;
	data.ReadFromFile(inFile);   
   
    if (data.GetTextureType() == TextureFlags::Texture1D)
    {	
		return CreateTexture1DPtr<Texture1DSharedPtr, 1>(data, inFile);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�������Ͳ���TextureType::Texture1D��\n"s));
	}	
}

// static
Rendering::Texture2DSharedPtr Rendering::LoadTexture
        ::Load2DFromFile (const System::String& name)
{
	ReadFileManager inFile{ name };
    
	// ���ȶ�ȡ����ͷ����Ϣ��
	// һЩͷ�ֶ�û�б�Ҫ��������,�����Ǵ������ļ�,
	// �Է�����������Ҫ����Ϣ,�����贴��һ���������
	TextureData data;
	data.ReadFromFile(inFile);   
   
    if (data.GetTextureType() == TextureFlags::Texture2D)
    {	
		return CreateTexture2DPtr<Texture2DSharedPtr, 2>(data, inFile);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�������Ͳ���TextureType::Texture2D��\n"s));
	}
}

// static
Rendering::Texture3DSharedPtr Rendering::LoadTexture
        ::Load3DFromFile (const System::String& name)
{
	ReadFileManager inFile{ name };
    
	// ���ȶ�ȡ����ͷ����Ϣ��
	// һЩͷ�ֶ�û�б�Ҫ��������,�����Ǵ������ļ�,
	// �Է�����������Ҫ����Ϣ,�����贴��һ���������
	TextureData data;

	data.ReadFromFile(inFile);   
   
    if (data.GetTextureType() == TextureFlags::Texture3D)
    {	
		return CreateTexture3DPtr<Texture3DSharedPtr, 3>(data, inFile);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�������Ͳ���TextureType::Texture3D��\n"s));
	}
}

// static
Rendering::TextureCubeSharedPtr Rendering::LoadTexture
        ::LoadCubeFromFile (const System::String& name)
{
	ReadFileManager inFile{ name };
    
	// ���ȶ�ȡ����ͷ����Ϣ��
	// һЩͷ�ֶ�û�б�Ҫ��������,�����Ǵ������ļ�,
	// �Է�����������Ҫ����Ϣ,�����贴��һ���������
	TextureData data;

	data.ReadFromFile(inFile);   
   
    if (data.GetTextureType() == TextureFlags::TextureCube)
    {	
		return CreateTextureCubePtr<TextureCubeSharedPtr, 2>(data, inFile);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�������Ͳ���TextureType::TextureCube��\n"s));
	}
}


