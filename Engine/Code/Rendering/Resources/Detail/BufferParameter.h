// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 09:42)

#ifndef RENDERING_RESOURCES_BUFFER_PARAMETER_H
#define RENDERING_RESOURCES_BUFFER_PARAMETER_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE BufferParameter
	{
	public:
		using ClassType = BufferParameter;

	public:	
		BufferParameter() noexcept;
            BufferParameter(int offset, int componentSize, int numComponents) noexcept;

		CLASS_INVARIANT_DECLARE;
		
		void Set(int offset, int componentSize, int numComponents) noexcept;

		int GetOffset() const noexcept;
                int GetComponentSize() const noexcept;
                int GetNumComponents() const noexcept;
		
	private:
		int m_Offset;
		int m_ComponentSize;
		int m_NumComponents;
	};
}

#endif // RENDERING_RESOURCES_BUFFER_PARAMETER_H
