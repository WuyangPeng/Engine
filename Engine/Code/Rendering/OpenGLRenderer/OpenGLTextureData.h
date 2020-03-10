// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:08)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_H

#include "Rendering/RenderingDll.h"

#include "TextureDataTraits.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "Rendering/Resources/Flags/TextureFlags.h"

#include <boost/noncopyable.hpp>

namespace Rendering
{
	template <typename Texture>
	class OpenGLTextureData : boost::noncopyable
	{
	public:
		using ClassType = OpenGLTextureData<Texture>;
		using TextureType = Texture;
		using UInt = System::OpenGLUInt;
		using TextureTargetType = System::TextureTarget;
		using TextureInternalFormat = System::TextureInternalFormat;
		using TextureFormat = System::TextureFormat;
		using DataType = System::OpenGLData;

	public:
		explicit OpenGLTextureData (const Texture* texture);
		~OpenGLTextureData();

		CLASS_INVARIANT_DECLARE;

		void Enable (int textureUnit);
		void Disable (int textureUnit);
		void* Lock (int level, BufferLocking mode);
		void Unlock (int level);
		void* Lock (int face, int level, BufferLocking mode);
		void Unlock (int face, int level);

		UInt GetTexture () const;

	private:
		void CreatePixelBufferObjects(const Texture* texture);
		void InitRemainData();
		UInt CreateTextureStructure();
		void CreateMipmapLevelStructures(const Texture* texture,UInt previousBind);
		void TextureImage(int level);

	private:
		static constexpr int sm_Dimension = TextureDataTraits<Texture>::sm_Dimension;
		static constexpr int sm_Face = TextureDataTraits<Texture>::sm_Face;
		static constexpr ShaderFlags::SamplerType sm_SamplerType = TextureDataTraits<Texture>::sm_SamplerType;
		static constexpr TextureTargetType sm_TextureTargetType = TextureDataTraits<Texture>::sm_TextureTargetType;

	private:
		UInt m_Texture;
		TextureInternalFormat m_InternalFormat;
		TextureFormat m_Format;
		DataType m_Type;
		UInt m_PreviousTexture;
		UInt m_NumLevels;
		UInt m_NumLevelBytes[TextureMaximumMipmapLevels];
		UInt m_Dimension[sm_Dimension][TextureMaximumMipmapLevels];
		UInt m_Buffer[sm_Face][TextureMaximumMipmapLevels];
		void* m_LockedMemory[sm_Face][TextureMaximumMipmapLevels];
		bool m_WriteLock[sm_Face][TextureMaximumMipmapLevels];
		bool m_IsCompressed;
	};
}

#endif // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_H
