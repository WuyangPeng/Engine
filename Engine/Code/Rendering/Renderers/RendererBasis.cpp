// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 10:23)

#include "Rendering/RenderingExport.h"

#include "RendererBasis.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RendererBasis
	::RendererBasis(int width,int height,TextureFormat colorFormat, TextureFormat depthStencilFormat, int numMultisamples) noexcept
	: m_WindowWidth{ width }, m_WindowHeight{ height }, m_ColorFormat{ colorFormat },
	  m_DepthStencilFormat{ depthStencilFormat }, m_MultisamplesNumber{ numMultisamples }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::RendererBasis
	::RendererBasis() noexcept
	: m_WindowWidth{ 0 }, m_WindowHeight{},m_ColorFormat{ TextureFormat::DefaultColour },
	  m_DepthStencilFormat{ TextureFormat::DefaultDepth }, m_MultisamplesNumber{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::RendererBasis
	::IsValid() const noexcept
{
    if(0 <= m_MultisamplesNumber && 0 <= m_WindowWidth && 0 <= m_WindowHeight)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

Rendering::TextureFormat Rendering::RendererBasis
	::GetColorFormat() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_ColorFormat;
}

Rendering::TextureFormat Rendering::RendererBasis
	::GetDepthStencilFormat() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_DepthStencilFormat;
}

int Rendering::RendererBasis
	::GetNumMultisamples() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_MultisamplesNumber;
}

int Rendering::RendererBasis
	::GetWidth () const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_WindowWidth;
}

int Rendering::RendererBasis
	::GetHeight () const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_WindowHeight;
}

void Rendering::RendererBasis
	::SetSize(int width,int height) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_WindowWidth = width;
	m_WindowHeight = height;
}

void Rendering::RendererBasis
	::SetTextureFormat(TextureFormat colorFormat, TextureFormat depthStencilFormat) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_ColorFormat = colorFormat;
	m_DepthStencilFormat = depthStencilFormat;
}

void Rendering::RendererBasis
	::SetMultisamplesNumber(int numMultisamples)  noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_MultisamplesNumber = numMultisamples;
}
