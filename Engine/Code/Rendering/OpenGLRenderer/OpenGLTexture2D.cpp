// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:29)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture2D.h"
#include "OpenGLTextureDataDetail.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
 
Rendering::OpenGLTexture2D
	::OpenGLTexture2D( Renderer* renderer, const Texture2D* texture )
	:m_OpenGLTextureData{ texture }
{	
	SYSTEM_UNUSED_ARG(renderer);

	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTexture2D
	::~OpenGLTexture2D()
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,OpenGLTexture2D)

void Rendering::OpenGLTexture2D
	::Enable( Renderer* renderer, int textureUnit )
{
	RENDERING_CLASS_IS_VALID_9;

	m_OpenGLTextureData.Enable(textureUnit);

	SYSTEM_UNUSED_ARG(renderer);
}

void Rendering::OpenGLTexture2D
	::Disable( Renderer* renderer, int textureUnit )
{
	RENDERING_CLASS_IS_VALID_9;

	m_OpenGLTextureData.Disable(textureUnit);

	SYSTEM_UNUSED_ARG(renderer);
}

void* Rendering::OpenGLTexture2D
	::Lock( int level, BufferLocking mode )
{
	RENDERING_CLASS_IS_VALID_9;

	return m_OpenGLTextureData.Lock(level,mode);
}

void Rendering::OpenGLTexture2D
	::Unlock( int level )
{
	RENDERING_CLASS_IS_VALID_9;

	m_OpenGLTextureData.Unlock(level);
}

System::OpenGLUInt Rendering::OpenGLTexture2D
	::GetTexture() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_OpenGLTextureData.GetTexture();
}

