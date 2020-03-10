// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 15:42)

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
        // OpenGL使用投影矩阵在深度[-1,1]。
	    m_DepthType = DepthType::MinusOneToOne;
	    break;

	case RendererTypes::Dx9:
        // DirectX使用投影矩阵在深度[0,1]。 
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
