// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 11:30)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureDataDetail.h"
#include "OpenGLTextureDataManageDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
// private
template <>
void Rendering::OpenGLTextureData<Rendering::Texture1D>
	::CreateMipmapLevelStructures(const Texture1D* texture,UInt previousBind)
{
	// ����mipmap��νṹ����ͼ��ĳ�ʼ��������
	for (UInt level = 0; level < m_NumLevels; ++level)
	{
		System::GlTexImage1D(level, m_InternalFormat, m_Dimension[0][level],m_Format, m_Type);
	}

	System::SetGlBindTexture(System::TextureTarget::Texture1D, previousBind);

	for (UInt level = 0; level < m_NumLevels; ++level)
	{
		OpenGLTextureDataManager<ClassType> manager(*this);

		void* data = manager.Lock(level, BufferLocking::WriteOnly);
		memcpy(data, texture->GetTextureData(level), texture->GetNumLevelBytes(level));		 
	}
}

// private
template <>
void Rendering::OpenGLTextureData<Rendering::Texture2D>
	::CreateMipmapLevelStructures(const Texture2D* texture,UInt previousBind)
{
	// ����mipmap��νṹ����ͼ��ĳ�ʼ��������
    if (m_IsCompressed)
    {
        for (UInt level = 0; level < m_NumLevels; ++level)
        {
            System::GlCompressedTexImage2D(static_cast<GLenum>(System::TextureTarget::Texture2D), level, 
                                           m_InternalFormat, m_Dimension[0][level],m_Dimension[1][level], m_NumLevelBytes[level]);
        }
    }
    else
    {
        for (UInt level = 0; level < m_NumLevels; ++level)
        {
			System::GlTexImage2D(static_cast<GLenum>(System::TextureTarget::Texture2D), level,m_InternalFormat, 
								 m_Dimension[0][level],m_Dimension[1][level], m_Format,m_Type);
        }
    }

	System::SetGlBindTexture(System::TextureTarget::Texture2D, previousBind);

    for (UInt level = 0; level < m_NumLevels; ++level)
    {
		OpenGLTextureDataManager<ClassType> manage(*this);

		void* data = manage.Lock(level, BufferLocking::WriteOnly);
        memcpy(data, texture->GetTextureData(level), texture->GetNumLevelBytes(level));        
    }
}

// private
template <>
void Rendering::OpenGLTextureData<Rendering::Texture3D>
	::CreateMipmapLevelStructures(const Texture3D* texture,UInt previousBind)
{
	// ����mipmap��νṹ����ͼ��ĳ�ʼ��������
    for (UInt level = 0; level < m_NumLevels; ++level)
    {
		System::GetGlTexImage3D(level, m_InternalFormat,m_Dimension[0][level], m_Dimension[1][level],m_Dimension[2][level], m_Format, m_Type);
    }

	System::SetGlBindTexture(System::TextureTarget::Texture3D, previousBind);

    for (UInt level = 0; level < m_NumLevels; ++level)
    {
		OpenGLTextureDataManager<ClassType> manager(*this);

		void* data = manager.Lock(level, BufferLocking::WriteOnly);
        memcpy(data, texture->GetTextureData(level), texture->GetNumLevelBytes(level));
    }
}

// private
template <>
void Rendering::OpenGLTextureData<Rendering::TextureCube>
	::CreateMipmapLevelStructures(const TextureCube* texture,UInt previousBind)
{
	// ����mipmap��νṹ����ͼ��ĳ�ʼ��������
    if (m_IsCompressed)
    {
        for (int face = 0; face < sm_Face; ++face)
        {
            for (UInt level = 0; level < m_NumLevels; ++level)
            {
				System::GlCompressedTexImage2D(static_cast<GLenum>(System::TextureCubeMap::PositiveX) + face,
                                                level, m_InternalFormat,m_Dimension[0][level],m_Dimension[1][level], m_NumLevelBytes[level]);
            }
        }
    }
    else
    {
        for (int face = 0; face < sm_Face; ++face)
        {
            for (UInt level = 0; level < m_NumLevels; ++level)
            {
				System::GlTexImage2D(static_cast<GLenum>(System::TextureCubeMap::PositiveX) + face, level,m_InternalFormat, 
								     m_Dimension[0][level],m_Dimension[1][level], m_Format, m_Type);
            }
        }
    }

	System::SetGlBindTexture(System::TextureTarget::TextureCubeMap, previousBind);

    for (int face = 0; face < sm_Face; ++face)
    {
        for (UInt level = 0; level < m_NumLevels; ++level)
        {
			OpenGLTextureDataManager<ClassType> manager(*this);

			void* data = manager.Lock(face, level, BufferLocking::WriteOnly);
            memcpy(data, texture->GetTextureData(face, level), texture->GetNumLevelBytes(level));            
        }
    }
}

// private
template <>
void Rendering::OpenGLTextureData<Rendering::Texture1D>
	::TextureImage(int level) noexcept
{
	// TODO:  ������ֻ��0����������һ��������mipmaps��ͼ����
	// ������Ĵ���������AMD Radeon HD 7970
	// ���߻���13.4��13.6�Ĵ߻������԰棩�����һ��GL_INVALID_OPERATION��
	// �ҵķ������������ǲ���Ҫ�ġ��������ڣ�ֻ��ʹ��GlTexImage1D��
	// ���ҵ�NVIDIA�Կ��򲻻���ִ����⡣
	//
	// System::GlTexSubImage1D(level, m_Dimension[0][level],
	//                         m_Format, m_Type);	

	System::GlTexImage1D(level, m_InternalFormat, m_Dimension[0][level], m_Format, m_Type);
}

// private
template <>
void Rendering::OpenGLTextureData<Rendering::Texture2D>
	::TextureImage(int level) noexcept
{ 	 
	if (m_IsCompressed)
	{
		System::GlCompressedTexSubImage2D(static_cast<GLenum>(System::TextureTarget::Texture2D), level,  m_Dimension[0][level],
										  m_Dimension[1][level], m_InternalFormat, m_NumLevelBytes[level]);
	}
	else
	{
		// TODO:  ������ֻ��0����������һ��������mipmaps��ͼ����
		// ������Ĵ���������AMD Radeon HD 7970
		// ���߻���13.4��13.6�Ĵ߻������԰棩�����һ��GL_INVALID_OPERATION��
		// �ҵķ������������ǲ���Ҫ�ġ��������ڣ�ֻ��ʹ��GlTexImage2D��
		// ���ҵ�NVIDIA�Կ��򲻻���ִ����⡣

        // 	System::GlTexSubImage2D(System::TextureTargetType2D, level,
		// 		                    m_Dimension[0][level], m_Dimension[1][level], 
		// 						    m_Format, m_Type);

		System::GlTexImage2D(static_cast<GLenum>(System::TextureTarget::Texture2D), level, m_InternalFormat,
			                 m_Dimension[0][level], m_Dimension[1][level],  m_Format,m_Type);
	}
	
}

// private
template <>
void Rendering::OpenGLTextureData<Rendering::Texture3D>
	::TextureImage(int level) noexcept
{ 
	// TODO:  ������ֻ��0����������һ��������mipmaps��ͼ����
	// ������Ĵ���������AMD Radeon HD 7970
	// ���߻���13.4��13.6�Ĵ߻������԰棩�����һ��GL_INVALID_OPERATION��
	// �ҵķ������������ǲ���Ҫ�ġ��������ڣ�ֻ��ʹ��GlTexImage3D��
	// ���ҵ�NVIDIA�Կ��򲻻���ִ����⡣
	
	//  System::GlTexSubImage3D(level,  m_Dimension[0][level], m_Dimension[1][level],
	//                          m_Dimension[2][level], m_Format, m_Type);

	System::GetGlTexImage3D(level, m_InternalFormat,  m_Dimension[0][level], m_Dimension[1][level], m_Dimension[2][level], m_Format, m_Type);
		 
}
#include STSTEM_WARNING_POP