// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 10:36)

#include "Rendering/RenderingExport.h"

#include "TextureManagementLockEncapsulationDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <>
Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTexture1D> >
	::~TextureManagementLockEncapsulation()
{
	if (m_Texture != nullptr)
	{		 
		m_Manager.Unlock(m_Texture,m_Level);		 
	}

	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTexture2D> >
	::~TextureManagementLockEncapsulation()
{
	if (m_Texture != nullptr)
	{		 
		m_Manager.Unlock(m_Texture,m_Level);		 
	}

	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTexture3D> >
	::~TextureManagementLockEncapsulation()
{
	if (m_Texture != nullptr)
	{		 
		m_Manager.Unlock(m_Texture,m_Level);		 
	}

	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTextureCube> >
	::~TextureManagementLockEncapsulation()
{
	if (m_Texture != nullptr)
	{		 
		m_Manager.UnlockCube(m_Texture,m_Face, m_Level);		 
	}

	RENDERING_SELF_CLASS_IS_VALID_9;
}
	