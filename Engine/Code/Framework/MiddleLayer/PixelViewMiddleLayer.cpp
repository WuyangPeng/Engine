// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/08/01 13:08)

#include "Framework/FrameworkExport.h"

#include "PixelViewMiddleLayer.h"
#include "Detail/PixelViewMiddleLayerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"  
#include "Framework/WindowCreate/WindowSize.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"

Framework::PixelViewMiddleLayer
	::PixelViewMiddleLayer()
	:ParentType{},m_Impl(new ImplType)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::PixelViewMiddleLayer
	::~PixelViewMiddleLayer()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Framework, PixelViewMiddleLayer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, PixelViewMiddleLayer, IsDoFlip, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, PixelViewMiddleLayer, DoFlip, bool, void);

bool Framework::PixelViewMiddleLayer
	::Initialize()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if(ParentType::Initialize())
	{	
		ConstRendererSmartPointer renderer = GetConstRenderer();

		if (renderer.IsValidPtr())
		{
			WindowSize windowSize(renderer->GetWidth(), renderer->GetHeight());

			m_Impl->Resize(windowSize, GetClearColor());
		}	

		return true;
	}
	else
	{
		return false;
	}
} 

void Framework::PixelViewMiddleLayer
	::Terminate()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Terminate();
} 

bool Framework::PixelViewMiddleLayer
	::Display( int64_t timeDelta )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	RendererSmartPointer renderer = GetRenderer();

	if(ParentType::Idle(timeDelta) && renderer.IsValidPtr() && renderer->PreDraw())
	{
        renderer->ClearBuffers();
        m_Impl->Draw(renderer);
        ScreenOverlay();
        renderer->PostDraw();
        renderer->DisplayColorBuffer();

		return true;
	}
	else
	{
		return false;
	}
}

bool Framework:: PixelViewMiddleLayer
	::Resize( WindowDisplayFlags type, const WindowSize& size )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	int width = size.GetWindowWidth();
	int height = size.GetWindowHeight();

	if(ParentType::Resize(type,size) && 0 < width * height)
	{
		RendererSmartPointer renderer = GetRenderer();

		if (renderer.IsValidPtr())
		{
			renderer->Resize(width, height);
		}		

		Colour colour = GetClearColor();

		m_Impl->Resize(size,colour);

		return true;
	}
	else
	{
		return false;
	}
}

void Framework::PixelViewMiddleLayer
	::ScreenOverlay ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
     // ´æ¸ùÔÚÅÉÉúÀà.
}

void Framework::PixelViewMiddleLayer
	::ClearScreen ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;	

	Colour colour = GetClearColor();

	return m_Impl->ClearScreen(colour);
}
 
void Framework::PixelViewMiddleLayer
	::SetPixel (int x, int y, const Colour& colour)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetPixel(x, y, colour);
}

void Framework::PixelViewMiddleLayer
	::SetThickPixel (int x, int y, int thick, const Colour& colour)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetThickPixel(x, y, thick, colour);
}

const Framework::PixelViewMiddleLayer::Colour Framework::PixelViewMiddleLayer
	::GetPixel (int x, int y) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Impl->GetPixel(x, y);
}

void  Framework::PixelViewMiddleLayer
	::DrawLine (int beginX, int beginY, int endX, int endY, const Colour& colour)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->DrawLine(beginX, beginY, endX, endY, colour);
}

void  Framework::PixelViewMiddleLayer
	::DrawRectangle (int xMin, int yMin, int xMax, int yMax, const Colour& colour, bool solid)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->DrawRectangle(xMin, yMin, xMax, yMax, colour, solid);
}

void  Framework::PixelViewMiddleLayer
	::DrawCircle (int xCenter, int yCenter, int radius, const Colour& colour, bool solid)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->DrawCircle(xCenter, yCenter, radius, colour, solid);
}

void  Framework::PixelViewMiddleLayer
	::Fill (int x, int y, const Colour& foreColour, const Colour& backColour)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Fill(x, y, foreColour, backColour);
}
