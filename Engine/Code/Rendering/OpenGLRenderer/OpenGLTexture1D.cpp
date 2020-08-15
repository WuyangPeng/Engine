// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:28)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture1D.h"
#include "OpenGLTextureDataDetail.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::OpenGLTexture1D
	::OpenGLTexture1D( Renderer* renderer, const Texture1D* texture )
	:m_OpenGLTextureData{ texture }
{	
	SYSTEM_UNUSED_ARG(renderer);

	RENDERING_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,OpenGLTexture1D)

void Rendering::OpenGLTexture1D
	::Enable( Renderer* renderer, int textureUnit ) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_OpenGLTextureData.Enable(textureUnit);

	SYSTEM_UNUSED_ARG(renderer);
}

void Rendering::OpenGLTexture1D
	::Disable( Renderer* renderer, int textureUnit ) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_OpenGLTextureData.Disable(textureUnit);

	SYSTEM_UNUSED_ARG(renderer);
}

void* Rendering::OpenGLTexture1D
	::Lock( int level, BufferLocking mode ) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	return m_OpenGLTextureData.Lock(level,mode);
}

void Rendering::OpenGLTexture1D
	::Unlock( int level ) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_OpenGLTextureData.Unlock(level);
}

