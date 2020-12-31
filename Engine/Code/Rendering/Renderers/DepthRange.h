// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.3.0 (2020/03/26 18:12)

#ifndef RENDERING_RENDERERS_DEPTH_RANGE_H
#define RENDERING_RENDERERS_DEPTH_RANGE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h" 

namespace Rendering
{
	class DepthRange
	{
	public:
		constexpr DepthRange(float zMin, float zMax)
			:m_ZMin{ zMin }, m_ZMax{ zMax }
		{
		}

		constexpr float GetZMin() const
		{
			return m_ZMin;
		}

		constexpr float GetMax() const
		{
			return m_ZMax;
		}

	private:
		float m_ZMin;
		float m_ZMax;
	};
}

#endif // RENDERING_RENDERERS_GLOBAL_STATE_H



