// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:30)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureCube.h"
#include "OpenGLTextureDataDetail.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
 
Rendering::OpenGLTextureCube
	::OpenGLTextureCube( Renderer* renderer, const TextureCube* texture )
	:m_OpenGLTextureData{ texture }
{	
	SYSTEM_UNUSED_ARG(renderer);

	RENDERING_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,OpenGLTextureCube)

void Rendering::OpenGLTextureCube
	::Enable( Renderer* renderer, int textureUnit ) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_OpenGLTextureData.Enable(textureUnit);

	SYSTEM_UNUSED_ARG(renderer);
}

void Rendering::OpenGLTextureCube
	::Disable( Renderer* renderer, int textureUnit ) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_OpenGLTextureData.Disable(textureUnit);

	SYSTEM_UNUSED_ARG(renderer);
}

void* Rendering::OpenGLTextureCube
	::Lock( int face,int level, BufferLocking mode ) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	return m_OpenGLTextureData.Lock(face ,level,mode);
}

void Rendering::OpenGLTextureCube
	::Unlock( int face,int level ) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_OpenGLTextureData.Unlock(face ,level);
}
 
 