// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:56)

#include "Framework/FrameworkExport.h"

#include "PixelViewMiddleLayer.h"
#include "Detail/PixelViewMiddleLayerImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"  
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "Rendering/Renderers/Renderer.h"
#include "Framework/WindowCreate/WindowSize.h"

using std::move;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Framework
{
	static constexpr auto g_DefaultWidth = 1024;
	static constexpr auto g_DefaultHeight = 768;
}

Framework::PixelViewMiddleLayer
	::PixelViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, m_Impl{ make_shared<ImplType>(g_DefaultWidth,g_DefaultHeight) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::PixelViewMiddleLayer
	::PixelViewMiddleLayer(PixelViewMiddleLayer&& rhs) noexcept
	:ParentType{ move(rhs) }, m_Impl{ move(rhs.m_Impl) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
 
Framework::PixelViewMiddleLayer& Framework::PixelViewMiddleLayer
	::operator=(PixelViewMiddleLayer&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::operator=(move(rhs));

	m_Impl = move(rhs.m_Impl);

	return *this;
}
 
CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Framework, PixelViewMiddleLayer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, PixelViewMiddleLayer, IsDoFlip, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, PixelViewMiddleLayer, DoFlip, bool, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, PixelViewMiddleLayer, GetScreenWidth, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, PixelViewMiddleLayer, GetScreenHeight, int); 

bool Framework::PixelViewMiddleLayer
	::Initialize()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto renderer = GetRenderer();

	if (ParentType::Initialize() && renderer)
	{
		const WindowSize windowSize{ renderer->GetWidth(), renderer->GetHeight() };

		m_Impl->Resize(windowSize, GetClearColor());

		return true;
	}
	else
	{
		return false;
	}
}

bool Framework::PixelViewMiddleLayer
	::Idle(int64_t timeDelta)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto renderer = GetRenderer();

	if (ParentType::Idle(timeDelta) && renderer)
	{
		if (renderer->PreDraw())
		{
			renderer->ClearBuffers();
			m_Impl->Draw(renderer);
			ScreenOverlay();
			renderer->PostDraw();
			renderer->DisplayColorBuffer();
		}

		return true;
	}
	else
	{
		return false;
	}
}

bool Framework::PixelViewMiddleLayer
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	const auto width = size.GetWindowWidth();
	const auto height = size.GetWindowHeight();
	auto renderer = GetRenderer();

	if (ParentType::Resize(windowDisplay, size))
	{
		if (0 < width * height && renderer)
		{
			renderer->Resize(width, height);

			const auto colour = GetClearColor();

			m_Impl->Resize(size, colour);
		}		

		return true;
	}
	else
	{
		return false;
	}
}
 
void Framework::PixelViewMiddleLayer
	::ScreenOverlay()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	// 存根在派生类。
	CoreTools::DisableNoexcept();
}
 
void Framework::PixelViewMiddleLayer
	::ClearScreen()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	const auto colour = GetClearColor();

	return m_Impl->ClearScreen(colour);
}

void Framework::PixelViewMiddleLayer
	::SetPixel(int x, int y, const Colour& colour)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetPixel(x, y, colour);
}

void Framework::PixelViewMiddleLayer
	::SetThickPixel(int x, int y, int thick, const Colour& colour)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetThickPixel(x, y, thick, colour);
}

const Framework::PixelViewMiddleLayer::Colour Framework::PixelViewMiddleLayer
	::GetPixel(int x, int y) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Impl->GetPixel(x, y);
}

void  Framework::PixelViewMiddleLayer
	::DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& colour)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->DrawLine(xMin, yMin, xMax, yMax, colour);
}

void  Framework::PixelViewMiddleLayer
	::DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& colour, bool solid)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->DrawRectangle(xMin, yMin, xMax, yMax, colour, solid);
}

void  Framework::PixelViewMiddleLayer
	::DrawCircle(int xCenter, int yCenter, int radius, const Colour& colour, bool solid)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->DrawCircle(xCenter, yCenter, radius, colour, solid);
}

void  Framework::PixelViewMiddleLayer
	::Fill(int x, int y, const Colour& foreColour, const Colour& backColour)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Fill(x, y, foreColour, backColour);
}
#include STSTEM_WARNING_POP