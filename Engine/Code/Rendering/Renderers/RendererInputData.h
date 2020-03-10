// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:37)

#ifndef FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_H
#define FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"

#include <boost/noncopyable.hpp>

RENDERING_EXPORT_SHARED_PTR(RendererInputDataImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace CoreTools
{
	class Mutex;
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE RendererInputData : public CoreTools::Singleton<RendererInputData>
	{
	public:
		SINGLETON_INITIALIZE_DECLARE(RendererInputData); 
		using RendererTypes = Rendering::RendererTypes;

	public:	
		CLASS_INVARIANT_DECLARE;

		void Rebuild(RendererTypes type);

	private:		
		SINGLETON_INSTANCE_DECLARE(RendererInputData);
		SINGLETON_IMPL_DECLARE(RendererInputData);
	};
}

#define RENDERER_INPUT_DATA_SINGLETON Rendering::RendererInputData::GetSingleton()

#endif // FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_H



	