// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 15:42)

#include "Rendering/RenderingExport.h"

#include "CameraManagerImpl.h"
#include "Rendering/Renderers/RendererInput.h" 
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::CameraManagerImpl
	::CameraManagerImpl()
	:m_DepthType{ DepthType::Quantity }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,CameraManagerImpl)

void Rendering::CameraManagerImpl
    ::SetDefaultDepthType(RendererTypes type)
{
	RENDERING_CLASS_IS_VALID_9;

	switch(type)
	{
	case RendererTypes::Default:
	    m_DepthType = DepthType::MinusOneToOne;
	    break;

	case RendererTypes::Window:
	case RendererTypes::Glut:
	case RendererTypes::OpenGL:
	case RendererTypes::OpenGLES:
        // OpenGLʹ��ͶӰ���������[-1,1]��
	    m_DepthType = DepthType::MinusOneToOne;
	    break;

	case RendererTypes::Dx9:
        // DirectXʹ��ͶӰ���������[0,1]�� 
	    m_DepthType = DepthType::ZeroToOne;
	    break;

	default:
	    m_DepthType = DepthType::MinusOneToOne;
	    break;
	}
}

Rendering::DepthType Rendering::CameraManagerImpl
    ::GetDepthType() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_DepthType;
}
