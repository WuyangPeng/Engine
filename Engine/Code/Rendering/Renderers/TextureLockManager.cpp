// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 10:36)

#include "Rendering/RenderingExport.h"

#include "TextureLockManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
template <>
Rendering::TextureLockManager<Rendering::PlatformTexture1D>
	::~TextureLockManager()
{EXCEPTION_TRY
{
if (m_Level != -1)
	{		 
		m_Manager.Unlock(m_Level);		 
	}
}
EXCEPTION_ALL_CATCH(Rendering)  
	

	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureLockManager<Rendering::PlatformTexture2D>
	::~TextureLockManager()
{
	EXCEPTION_TRY
{
if (m_Level != -1)
	{		 
		m_Manager.Unlock(m_Level);		 
	}
}
EXCEPTION_ALL_CATCH(Rendering)  

	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureLockManager<Rendering::PlatformTexture3D>
	::~TextureLockManager()
{
	EXCEPTION_TRY
{
if (m_Level != -1)
	{		 
		m_Manager.Unlock(m_Level);		 
	}
}
EXCEPTION_ALL_CATCH(Rendering)  

	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureLockManager<Rendering::PlatformTextureCube>
	::~TextureLockManager()
{EXCEPTION_TRY
{
if (m_Level != -1)
	{		 
		m_Manager.Unlock(m_Face, m_Level);		 
	}
}
EXCEPTION_ALL_CATCH(Rendering)  
	

	RENDERING_SELF_CLASS_IS_VALID_9;
}
	