// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:53)

#include "Framework/FrameworkExport.h"

#include "PixelViewMiddleLayerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/PixelScreen.h"
#include "Framework/WindowCreate/WindowSize.h"

Framework::PixelViewMiddleLayerImpl
	::PixelViewMiddleLayerImpl(int width, int height)  
	:m_PixelScreen{ WindowSize{ width, height } }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, PixelViewMiddleLayerImpl)

void Framework::PixelViewMiddleLayerImpl
	::Resize(const WindowSize& windowSize, const Colour& colour)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_PixelScreen.Resize(windowSize, colour);
}

void Framework::PixelViewMiddleLayerImpl
	::ClearScreen(const Colour& colour)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_PixelScreen.ClearScreen(colour);
}

void Framework::PixelViewMiddleLayerImpl
	::DoFlip(bool doFlip)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_PixelScreen.DoFlip(doFlip);
}

bool Framework::PixelViewMiddleLayerImpl
	::IsDoFlip() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_PixelScreen.IsDoFlip();
}

void Framework::PixelViewMiddleLayerImpl
	::SetPixel(int x, int y, const Colour& colour)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_PixelScreen.SetPixel(x, y, colour);
}

void Framework::PixelViewMiddleLayerImpl
	::SetThickPixel(int x, int y, int thick, const Colour& colour)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_PixelScreen.SetThickPixel(x, y, thick, colour);
}

const Framework::PixelViewMiddleLayerImpl::Colour Framework::PixelViewMiddleLayerImpl
	::GetPixel(int x, int y) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_PixelScreen.GetPixel(x, y);
}

void  Framework::PixelViewMiddleLayerImpl
	::DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& colour)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_PixelScreen.DrawLine(xMin, yMin, xMax, yMax, colour);
}

void  Framework::PixelViewMiddleLayerImpl
	::DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& colour, bool solid)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_PixelScreen.DrawRectangle(xMin, yMin, xMax, yMax, colour, solid);
}

void  Framework::PixelViewMiddleLayerImpl
	::DrawCircle(int xCenter, int yCenter, int radius, const Colour& colour, bool solid)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_PixelScreen.DrawCircle(xCenter, yCenter, radius, colour, solid);
}

void  Framework::PixelViewMiddleLayerImpl
	::Fill(int x, int y, const Colour& foreColour, const Colour& backColour)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_PixelScreen.Fill(x, y, foreColour, backColour);
}

void Framework::PixelViewMiddleLayerImpl
	::Draw(const RendererSharedPtr& renderer)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_PixelScreen.Draw(renderer);
}

int Framework::PixelViewMiddleLayerImpl
	::GetScreenWidth() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_PixelScreen.GetScreenWidth();
}

int Framework::PixelViewMiddleLayerImpl
	::GetScreenHeight() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_PixelScreen.GetScreenHeight();
}
