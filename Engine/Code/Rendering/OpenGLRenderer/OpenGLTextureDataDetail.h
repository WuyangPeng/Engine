// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 11:15)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_DETAIL_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_DETAIL_H

#include "Rendering/RenderingExport.h" 

#include "OpenGLTextureData.h"
#include "OpenGLMapping.h"
#include "OpenGLBindTexture.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"
#include "Rendering/Resources/Texture1D.h"
#include "Rendering/Resources/Texture2D.h"
#include "Rendering/Resources/Texture3D.h"
#include "Rendering/Resources/TextureCube.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26493)
template <typename Texture>
Rendering::OpenGLTextureData<Texture>
	::OpenGLTextureData( const Texture* texture )
	:m_Texture{ 0 },m_InternalFormat{ TextureInternalFormat(g_OpenGLTextureInternalFormat[System::EnumCastUnderlying(texture->GetFormat())]) },
	 m_Format{ TextureFormat(g_OpenGLTextureFormat[System::EnumCastUnderlying(texture->GetFormat())]) },
	 m_Type{ DataType( g_OpenGLTextureType[System::EnumCastUnderlying(texture->GetFormat())]) },
	 m_PreviousTexture{ 0 }, m_NumLevels{ boost::numeric_cast<UInt>(texture->GetNumLevels()) }, m_IsCompressed{ texture->IsCompressed() }
{
	CreatePixelBufferObjects(texture);
	InitRemainData();
	const auto previousBind = CreateTextureStructure();
	CreateMipmapLevelStructures(texture,previousBind);	

	RENDERING_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Texture>
void Rendering::OpenGLTextureData<Texture>
	::CreatePixelBufferObjects(const Texture* texture)
{
	const auto usage = g_OpenGLBufferUsage[System::EnumCastUnderlying(texture->GetUsage())];

	// �������ػ������Ķ������洢�������ݡ�
	for (auto level = 0u; level < m_NumLevels; ++level)
	{
		m_NumLevelBytes[level] = texture->GetNumLevelBytes(level);

		for (auto i = 0;i < sm_Dimension;++i)
		{
			m_Dimension[i][level] = texture->GetDimension(i, level);
		}

		for (auto face = 0; face < sm_Face; ++face)
		{
		    m_Buffer[face][level] =  System::GlPixelUnpackBufferData(m_NumLevelBytes[level], usage);
		    m_LockedMemory[face][level] = nullptr;
		    m_WriteLock[face][level] = false;
		}
	}	
}

// private
template <typename Texture>
void Rendering::OpenGLTextureData<Texture>
	::InitRemainData() noexcept
{
	for (auto level = m_NumLevels; level < TextureMaximumMipmapLevels; ++level)
	{
		m_NumLevelBytes[level] = 0;

		for (auto i = 0;i < sm_Dimension;++i)
		{
			m_Dimension[i][level] = 0;
		}

		for (auto face = 0; face < sm_Face; ++face)
		{
		     m_Buffer[face][level] = 0;
			 m_LockedMemory[face][level] = nullptr;
		     m_WriteLock[face][level] = false;
		}
	}
}

// private
template <typename Texture>
System::OpenGLUInt Rendering::OpenGLTextureData<Texture>
	::CreateTextureStructure() noexcept
{
	// ��������ṹ��
	m_Texture = System::GlGenTextures();
	const auto previousBind = BindTexture(sm_SamplerType, m_Texture);

	return previousBind;
}

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLTextureData<Rendering::Texture1D>
	::CreateMipmapLevelStructures(const Texture1D* texture,UInt previousBind);

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLTextureData<Rendering::Texture2D>
	::CreateMipmapLevelStructures(const Texture2D* texture,UInt previousBind);

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLTextureData<Rendering::Texture3D>
	::CreateMipmapLevelStructures(const Texture3D* texture,UInt previousBind);

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLTextureData<Rendering::TextureCube>
	::CreateMipmapLevelStructures(const TextureCube* texture,UInt previousBind);

template <typename Texture>
Rendering::OpenGLTextureData<Texture>
	::~OpenGLTextureData()
{
	for (auto i = 0;i < sm_Face;++i)
	{
		for (auto level = 0u; level < m_NumLevels; ++level)
		{
			m_Buffer[i][level] = System::GlDeleteBuffers(m_Buffer[i][level]);
		}
	}
   
    m_Texture = System::GlDeleteTextures(m_Texture);

	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Texture>
bool Rendering::OpenGLTextureData<Texture>
	::IsValid() const noexcept
{
    if(0 < m_Texture  && 0 < m_NumLevels)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIAN


template <typename Texture>
void Rendering::OpenGLTextureData<Texture>
	::Enable( int textureUnit ) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	System::SetGlActiveTexture(static_cast<GLenum>(System::TextureNumber::Type0) + textureUnit);
    m_PreviousTexture = BindTexture(sm_SamplerType,m_Texture);
}


template <typename Texture>
void Rendering::OpenGLTextureData<Texture>
	::Disable( int textureUnit ) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	System::SetGlActiveTexture(static_cast<GLenum>(System::TextureNumber::Type0) + textureUnit);
	System::SetGlBindTexture(sm_TextureTargetType, m_PreviousTexture);
}


template <typename Texture>
void* Rendering::OpenGLTextureData<Texture>
	::Lock( int level, BufferLocking mode ) noexcept
{
	static_assert(TextureDataTraits<Texture>::sm_TextureType != TextureFlags::TextureCube);

	RENDERING_CLASS_IS_VALID_1;
	
	if (m_LockedMemory[0][level] == nullptr)
    {
		m_LockedMemory[0][level] = System::GlMapPixelUnpackBuffer(m_Buffer[0][level], g_OpenGLBufferLocking[System::EnumCastUnderlying(mode)]);

        m_WriteLock[0][level] = (mode != BufferLocking::ReadOnly);
    }

    return m_LockedMemory[0][level];
}


template <typename Texture>
void Rendering::OpenGLTextureData<Texture>
	::Unlock( int level ) noexcept
{
	static_assert(TextureDataTraits<Texture>::sm_TextureType != TextureFlags::TextureCube);

	RENDERING_CLASS_IS_VALID_1;
	
	if (m_LockedMemory[0][level] != nullptr)
    {
        System::GlBindPixelUnpackBuffer(m_Buffer[0][level]);
        System::GlUnmapPixelUnpackBuffer();

        if (m_WriteLock[0][level])
        {
            const GLuint previousBind = BindTexture(sm_SamplerType, m_Texture);

			TextureImage(level);			
			
			System::SetGlBindTexture(sm_TextureTargetType, previousBind);
            m_WriteLock[0][level] = false;
        }

        System::GlBindPixelUnpackBuffer(0);
        m_LockedMemory[0][level] = nullptr;
    }
}

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLTextureData<Rendering::Texture1D>
	::TextureImage(int level) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLTextureData<Rendering::Texture2D>
	::TextureImage(int level) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLTextureData<Rendering::Texture3D>
	::TextureImage(int level) noexcept;

template <typename Texture>
void* Rendering::OpenGLTextureData<Texture>
	::Lock( int face, int level, BufferLocking mode ) noexcept
{
	static_assert(TextureDataTraits<Texture>::sm_TextureType == TextureFlags::TextureCube);

	RENDERING_CLASS_IS_VALID_1;

	if (m_LockedMemory[face][level] == nullptr)
    {
		m_LockedMemory[face][level] = System::GlMapPixelUnpackBuffer(m_Buffer[face][level],g_OpenGLBufferLocking[System::EnumCastUnderlying(mode)]);

		m_WriteLock[face][level] = (mode != BufferLocking::ReadOnly);     
    }

    return m_LockedMemory[face][level];
}

template <typename Texture>
void Rendering::OpenGLTextureData<Texture>
	::Unlock( int face, int level ) noexcept
{
	static_assert(TextureDataTraits<Texture>::sm_TextureType == TextureFlags::TextureCube);

	RENDERING_CLASS_IS_VALID_1;

	if (m_LockedMemory[face][level] != nullptr)
    {
		System::GlBindPixelUnpackBuffer(m_Buffer[face][level]);
		System::GlUnmapPixelUnpackBuffer();

        if (m_WriteLock[face][level])
        {
            const UInt previousBind = BindTexture(TextureDataTraits<Texture>::sm_SamplerType, m_Texture);

            if (m_IsCompressed)
            {
				System::GlCompressedTexSubImage2D(static_cast<GLenum>(System::TextureCubeMap::PositiveX) + face,level, m_Dimension[0][level], 
                                                  m_Dimension[1][level],m_InternalFormat, m_NumLevelBytes[level]);
            }
            else
            {		
				System::GlTexImage2D(static_cast<GLenum>(System::TextureCubeMap::PositiveX) + face, level,m_InternalFormat,
			                         m_Dimension[0][level], m_Dimension[1][level], m_Format,m_Type); 

				// TODO:  ������ֻ��0����������һ��������mipmaps��ͼ����
				// ������Ĵ���������AMD Radeon HD 7970
				// ���߻���13.4��13.6�Ĵ߻������԰棩�����һ��GL_INVALID_OPERATION��
				// �ҵķ������������ǲ���Ҫ�ġ��������ڣ�ֻ��ʹ��GlTexImage2D��
				// ���ҵ�NVIDIA�Կ��򲻻���ִ����⡣

                // System::GlTexSubImage2D(System::TextureCubeMapTypePositiveX + face, 
				//                         level, m_Dimension[0][level], 
				//                         m_Dimension[1][level], m_Format,
				// 						   m_Type);
            }

			System::SetGlBindTexture(System::TextureTarget::TextureCubeMap, previousBind);
           
            m_WriteLock[face][level] = false;
        }

        System::GlBindPixelUnpackBuffer(0);
        m_LockedMemory[face][level] = 0;
    }
}

template <typename Texture>
System::OpenGLUInt Rendering::OpenGLTextureData<Texture>
	::GetTexture() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Texture;
}
#include STSTEM_WARNING_POP
#endif // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_DETAIL_H