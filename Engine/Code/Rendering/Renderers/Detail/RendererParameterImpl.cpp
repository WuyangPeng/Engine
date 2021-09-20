// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 10:07)

#include "Rendering/RenderingExport.h"

#include "RendererParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;

Rendering::RendererParameterImpl
	::RendererParameterImpl(RendererTypes type) noexcept
	:m_Type{ type }, m_RendererBasis{}, m_Colour{ 0.0f, 0.0f, 0.0f, 1.0f },
	m_WindowTitle{}, m_WindowX{ 0 }, m_WindowY{ 0 }, m_IsAllowResize{ true }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE( Rendering,RendererParameterImpl)

Rendering::TextureFormat Rendering::RendererParameterImpl
	::GetColorFormat() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_RendererBasis.GetColorFormat();
}

Rendering::TextureFormat Rendering::RendererParameterImpl ::GetDepthStencilFormat() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_RendererBasis.GetDepthStencilFormat();
}

int Rendering::RendererParameterImpl ::GetNumMultisamples() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_RendererBasis.GetNumMultisamples();
}

Rendering::Colour<float> Rendering::RendererParameterImpl
	::GetClearColor() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Colour;
}

const std::string Rendering::RendererParameterImpl
	::GetWindowTitle() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_WindowTitle;
}

int Rendering::RendererParameterImpl
	::GetXPosition () const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_WindowX;
}

int Rendering::RendererParameterImpl
	::GetYPosition () const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_WindowY;
}

int Rendering::RendererParameterImpl ::GetWidth() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_RendererBasis.GetWidth();
}

int Rendering::RendererParameterImpl ::GetHeight() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_RendererBasis.GetHeight();
}

bool Rendering::RendererParameterImpl
	::IsAllowResize() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_IsAllowResize;
}

Rendering::RendererTypes Rendering::RendererParameterImpl
	::GetRendererType() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Type;
}
	
void Rendering::RendererParameterImpl ::SetTextureFormat(TextureFormat colorFormat, TextureFormat depthStencilFormat, int numMultisamples) noexcept
{ 
	RENDERING_CLASS_IS_VALID_9;

	m_RendererBasis.SetTextureFormat(colorFormat, depthStencilFormat); 
	m_RendererBasis.SetMultisamplesNumber(0 < numMultisamples ? numMultisamples : 0);
}

void Rendering::RendererParameterImpl
	::SetClearColor(float red,float green,float blue,float alpha) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_Colour.SetColour(red,green,blue,alpha);
}

void Rendering::RendererParameterImpl
	::SetWindowParameter( const string& windowTitle,int width,int height,int x,int y,bool allowResize )
{
	RENDERING_CLASS_IS_VALID_9;

	m_WindowTitle = windowTitle;
	m_RendererBasis.SetSize(width, height);
	m_WindowX = x;
	m_WindowY = y;
	m_IsAllowResize = allowResize;
}

void Rendering::RendererParameterImpl ::Resize(int width, int height) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_RendererBasis.SetSize(width, height);
}

const Rendering::RendererBasis Rendering::RendererParameterImpl
	::GetRendererBasis() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_RendererBasis;
}

System::String Rendering::RendererParameterImpl
	::GetWindowClassName() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_ClassName;
}

void Rendering::RendererParameterImpl
	::SetWindowClassName(const System::String& className)
{
	RENDERING_CLASS_IS_VALID_9;

	m_ClassName = className;
}

System::String Rendering::RendererParameterImpl
	::GetWindowMenuName() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_MenuName;
}

void Rendering::RendererParameterImpl
	::SetWindowMenuName(const System::String& menuName)
{
	RENDERING_CLASS_IS_VALID_9;

	m_MenuName = menuName;
}

int Rendering::RendererParameterImpl
	::GetIcon() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Icon;
}

bool Rendering::RendererParameterImpl
	::IsIconDefault() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_IsIconDefault;
}

int Rendering::RendererParameterImpl
	::GetCursor() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Cursor;
}

bool Rendering::RendererParameterImpl::IsCursorDefault() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_IsCursorDefault;
}

System::WindowsBrushTypes Rendering::RendererParameterImpl
	::GetBackground() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Background;
}

void Rendering::RendererParameterImpl
	::SetWindowPictorialParameter(int icon, bool isIconDefault, int cursor, bool isCursorDefault, System::WindowsBrushTypes background) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_Icon = icon;
	m_IsIconDefault = isIconDefault;
	m_Cursor = cursor;
	m_IsCursorDefault = isCursorDefault;
	m_Background = background;
}
