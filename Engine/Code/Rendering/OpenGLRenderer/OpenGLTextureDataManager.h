// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:09)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_MANAGE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"

#include <boost/noncopyable.hpp>

namespace Rendering
{
	template <typename ManageType>
	class OpenGLTextureDataManager : boost::noncopyable
	{
	public:
		using ClassType = OpenGLTextureDataManager<ManageType>;

	public:
		explicit OpenGLTextureDataManager(ManageType& manager);
		~OpenGLTextureDataManager();

		CLASS_INVARIANT_DECLARE;
	 
		void* Lock (int level, BufferLocking mode);	 
		void* Lock (int face, int level, BufferLocking mode);	

	private:
		ManageType& m_Manager;	
		int m_Level;
		int m_Face;
	};
}

#endif // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_MANAGE_H
