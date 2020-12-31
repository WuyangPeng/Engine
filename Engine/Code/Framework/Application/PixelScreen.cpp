// Copyright (c) 2010-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.3.0.1 (2020/05/21 13:57)

#include "Framework/FrameworkExport.h"

#include "PixelScreen.h"
#include "Detail/PixelScreenImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowCreate/WindowSize.h"

using std::make_shared;

Framework::PixelScreen
	::PixelScreen(const WindowSize& size)
	:m_Impl{ make_shared<ImplType>(size) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework, PixelScreen)

DELAY_COPY_CONSTRUCTION_DEFINE(Framework, PixelScreen)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, PixelScreen,GetScreenWidth,int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, PixelScreen, GetScreenHeight, int);

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Framework, PixelScreen, Draw, RendererSharedPtr, void);
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Framework, PixelScreen, ClearScreen, Colour, void);
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Framework, PixelScreen, DoFlip, bool, void);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, PixelScreen, IsDoFlip, bool);

void Framework::PixelScreen
	::SetPixel(int x, int y, const Colour& color)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetPixel(x, y, color);
}

void Framework::PixelScreen
	::SetThickPixel(int x, int y, int thick, const Colour& color)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetThickPixel(x, y, thick, color);
}

const Framework::PixelScreen::Colour Framework::PixelScreen
	::GetPixel(int x, int y) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetPixel(x, y);
}

void  Framework::PixelScreen
	::DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& color)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->DrawLine(xMin, yMin, xMax, yMax, color);
}

void  Framework::PixelScreen
	::DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& color, bool solid)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->DrawRectangle(xMin, yMin, xMax, yMax, color, solid);
}

void  Framework::PixelScreen
	::DrawCircle(int xCenter, int yCenter, int radius, const Colour& color, bool solid)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->DrawCircle(xCenter, yCenter, radius, color, solid);
}

void  Framework::PixelScreen
	::Fill(int x, int y, const Colour& foreColor, const Colour& backColor)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Fill(x, y, foreColor, backColor);
}

void Framework::PixelScreen
	::Resize(const WindowSize& size, const Colour& color)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Resize(size, color);
}
