// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 11:31)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureDataManageDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
template <>
Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::Texture1D> >
	::~OpenGLTextureDataManager()
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
Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::Texture2D> >
	::~OpenGLTextureDataManager()
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
Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::Texture3D> >
	::~OpenGLTextureDataManager()
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
Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::TextureCube> >
	::~OpenGLTextureDataManager()
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
 
