// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 10:36)

#include "Rendering/RenderingExport.h"

#include "TextureLockManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <>
Rendering::TextureLockManager<Rendering::PlatformTexture1D>
	::~TextureLockManager()
{
	if (m_Level != -1)
	{		 
		m_Manager.Unlock(m_Level);		 
	}

	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureLockManager<Rendering::PlatformTexture2D>
	::~TextureLockManager()
{
	if (m_Level != -1)
	{		 
		m_Manager.Unlock(m_Level);		 
	}

	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureLockManager<Rendering::PlatformTexture3D>
	::~TextureLockManager()
{
	if (m_Level != -1)
	{		 
		m_Manager.Unlock(m_Level);		 
	}

	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureLockManager<Rendering::PlatformTextureCube>
	::~TextureLockManager()
{
	if (m_Level != -1)
	{		 
		m_Manager.Unlock(m_Face, m_Level);		 
	}

	RENDERING_SELF_CLASS_IS_VALID_9;
}
	