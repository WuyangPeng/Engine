// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.3.0 (2020/03/27 10:51)

#ifndef RENDERING_RENDERERS_VIEWPORT_H
#define RENDERING_RENDERERS_VIEWPORT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h" 

namespace Rendering
{
	class Viewport
	{
	public:
		constexpr Viewport(int xPosition, int yPosition, int width, int height)
			:m_XPosition{ xPosition }, m_YPosition{ yPosition }, m_Width{ width }, m_Height{ height }
		{
		}

		constexpr int GetXPosition() const
		{
			return m_XPosition;
		}

		constexpr int GetYPosition() const
		{
			return m_YPosition;
		}

		constexpr int GetWidth() const
		{
			return m_Width;
		}

		constexpr int GetHeight() const
		{
			return m_Height;
		}

		constexpr bool IsInViewport(int x, int y) const
		{
			return (m_XPosition <= x) && (x <= m_XPosition + m_Width) && (m_YPosition <= y) && (y <= m_YPosition + m_Height); 
		}

	private:
		int m_XPosition;
		int m_YPosition;
		int m_Width;
		int m_Height;
	};
}

#endif // RENDERING_RENDERERS_VIEWPORT_H



