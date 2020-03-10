// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/08/01 13:07)

#include "Framework/FrameworkExport.h"
 
#include "CameraViewMiddleLayer.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Rendering/Renderers/Renderer.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"

Framework::CameraViewMiddleLayer
	::CameraViewMiddleLayer()
	:ParentType{},m_Multiplier(0.0f)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::CameraViewMiddleLayer
	::~CameraViewMiddleLayer()	
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework,CameraViewMiddleLayer)

bool Framework::CameraViewMiddleLayer
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::Initialize())
		return true;
	else
		return false;
}

void Framework::CameraViewMiddleLayer
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::Terminate();
}

void Framework::CameraViewMiddleLayer
	::SetCamera( const ConstCameraSmartPointer& camera )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	RendererSmartPointer renderer = GetRenderer();

	if(renderer.IsValidPtr())
	{
		renderer->SetCamera(camera);
	}
}

const Framework::WindowSize Framework::CameraViewMiddleLayer
	::GetWindowSize() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	ConstRendererSmartPointer renderer = GetConstRenderer();

	if (renderer.IsValidPtr())
	{
		int width = renderer->GetWidth();
		int height = renderer->GetHeight();

		return WindowSize(width,height);
	}
	else
	{
		return WindowSize();
	}
}

bool Framework::CameraViewMiddleLayer
	::Resize( WindowDisplayFlags type, const WindowSize& size )
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	if(ParentType::Resize(type,size))
	{
		int width = size.GetWindowWidth();
		int height = size.GetWindowHeight();

		int minValue = std::min(height, width);

		if (0 < minValue)
		{
			m_Multiplier = 1.0f / minValue;
		}		

		return true;
	}
	else
	{
		return false;
	}
}

float Framework::CameraViewMiddleLayer
	::GetXTrack(int x) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	ConstRendererSmartPointer renderer = GetConstRenderer();

	if(renderer != nullptr)
	{		
		int width = renderer->GetWidth();
		
		return (2 * x - width) * m_Multiplier;	
	}
	else
	{
		return 0.0f;
	}
}

float Framework::CameraViewMiddleLayer
	::GetYTrack(int y) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	ConstRendererSmartPointer renderer = GetConstRenderer();

	if(renderer != nullptr)
	{		
		int height = renderer->GetHeight();
		
		return (2 * (height - 1 - y) - height) * m_Multiplier;	
	}
	else
	{
		return 0.0f;
	}
}
