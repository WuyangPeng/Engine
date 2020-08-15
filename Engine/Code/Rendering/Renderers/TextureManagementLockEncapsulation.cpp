// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 10:36)

#include "Rendering/RenderingExport.h"

#include "TextureManagementLockEncapsulationDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include "CoreTools/Helper/ExceptionMacro.h" 
template <>
Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTexture1D> >
	::~TextureManagementLockEncapsulation()
{
	

EXCEPTION_TRY
{
if (m_Texture != nullptr)
	{		 
		m_Manager.Unlock(m_Texture,m_Level);		 
	}
}
EXCEPTION_ALL_CATCH(Rendering)  
	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTexture2D> >
	::~TextureManagementLockEncapsulation()
{
 
EXCEPTION_TRY
{
if (m_Texture != nullptr)
	{		 
		m_Manager.Unlock(m_Texture,m_Level);		 
	}
}
EXCEPTION_ALL_CATCH(Rendering)  
	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTexture3D> >
	::~TextureManagementLockEncapsulation()
{
EXCEPTION_TRY
{
if (m_Texture != nullptr)
	{		 
		m_Manager.Unlock(m_Texture,m_Level);		 
	}
}
EXCEPTION_ALL_CATCH(Rendering)  

	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTextureCube> >
	::~TextureManagementLockEncapsulation()
{
	
	EXCEPTION_TRY
{
if (m_Texture != nullptr)
	{		 
		m_Manager.UnlockCube(m_Texture,m_Face, m_Level);		 
	}
}
EXCEPTION_ALL_CATCH(Rendering)  
	

	RENDERING_SELF_CLASS_IS_VALID_9;
}
	