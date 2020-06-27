// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:02)

#ifndef FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_IMPL_H
#define FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Flags/RendererTypes.h"

#include <memory>

namespace Rendering
{
	class RendererInput;
}

namespace Rendering
{
	class RendererInputDataImpl 
	{
	public:
		using ClassType = RendererInputDataImpl;
		using RendererInput = Rendering::RendererInput;
		using RendererInputPtr = std::shared_ptr<RendererInput>;
		using RendererTypes = Rendering::RendererTypes;

	public:
		RendererInputDataImpl();
		~RendererInputDataImpl();
	
		CLASS_INVARIANT_DECLARE;

		void Rebuild(RendererTypes type);

	private:		
		RendererInputPtr m_RendererInput;
	};
}

#endif // FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_IMPL_H



	