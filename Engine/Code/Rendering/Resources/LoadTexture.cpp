// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 15:33)

#include "Rendering/RenderingExport.h"

#include "LoadTextureDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
 

// static
Rendering::TextureSharedPtr  Rendering::LoadTexture
      ::LoadFromFile (const System::String& name)
{
	ReadFileManager inFile{ name };
    
	// 首先读取纹理头部信息。
	// 一些头字段没有必要创建纹理,但他们存在于文件,
	// 以防其他工具需要此信息,而无需创建一个纹理对象。
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
            THROW_EXCEPTION(SYSTEM_TEXT("无效的纹理类型。\n"s));
        }
    }	
}

// static
Rendering::Texture1DSharedPtr Rendering::LoadTexture
        ::Load1DFromFile (const System::String& name)
{
	ReadFileManager inFile{ name };
    
	// 首先读取纹理头部信息。
	// 一些头字段没有必要创建纹理,但他们存在于文件,
	// 以防其他工具需要此信息,而无需创建一个纹理对象。
	TextureData data;
	data.ReadFromFile(inFile);   
   
    if (data.GetTextureType() == TextureFlags::Texture1D)
    {	
		return CreateTexture1DPtr<Texture1DSharedPtr, 1>(data, inFile);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("纹理类型不是TextureType::Texture1D。\n"s));
	}	
}

// static
Rendering::Texture2DSharedPtr Rendering::LoadTexture
        ::Load2DFromFile (const System::String& name)
{
	ReadFileManager inFile{ name };
    
	// 首先读取纹理头部信息。
	// 一些头字段没有必要创建纹理,但他们存在于文件,
	// 以防其他工具需要此信息,而无需创建一个纹理对象。
	TextureData data;
	data.ReadFromFile(inFile);   
   
    if (data.GetTextureType() == TextureFlags::Texture2D)
    {	
		return CreateTexture2DPtr<Texture2DSharedPtr, 2>(data, inFile);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("纹理类型不是TextureType::Texture2D。\n"s));
	}
}

// static
Rendering::Texture3DSharedPtr Rendering::LoadTexture
        ::Load3DFromFile (const System::String& name)
{
	ReadFileManager inFile{ name };
    
	// 首先读取纹理头部信息。
	// 一些头字段没有必要创建纹理,但他们存在于文件,
	// 以防其他工具需要此信息,而无需创建一个纹理对象。
	TextureData data;

	data.ReadFromFile(inFile);   
   
    if (data.GetTextureType() == TextureFlags::Texture3D)
    {	
		return CreateTexture3DPtr<Texture3DSharedPtr, 3>(data, inFile);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("纹理类型不是TextureType::Texture3D。\n"s));
	}
}

// static
Rendering::TextureCubeSharedPtr Rendering::LoadTexture
        ::LoadCubeFromFile (const System::String& name)
{
	ReadFileManager inFile{ name };
    
	// 首先读取纹理头部信息。
	// 一些头字段没有必要创建纹理,但他们存在于文件,
	// 以防其他工具需要此信息,而无需创建一个纹理对象。
	TextureData data;

	data.ReadFromFile(inFile);   
   
    if (data.GetTextureType() == TextureFlags::TextureCube)
    {	
		return CreateTextureCubePtr<TextureCubeSharedPtr, 2>(data, inFile);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("纹理类型不是TextureType::TextureCube。\n"s));
	}
}


