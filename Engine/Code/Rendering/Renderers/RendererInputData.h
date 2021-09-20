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
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>
RENDERING_EXPORT_UNIQUE_PTR(RendererInputData);
RENDERING_NON_COPY_EXPORT_IMPL(RendererInputDataImpl);


namespace CoreTools
{
	class Mutex;
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE RendererInputData : public CoreTools::Singleton<RendererInputData>
	{
	public:
	public:
		NON_COPY_TYPE_DECLARE(RendererInputData);
		using ParentType = Singleton<RendererInputData>;
		using RendererTypes = Rendering::RendererTypes;

	private:
		enum class RendererInputDataCreate
		{
			Init,
		};

	public:
		explicit RendererInputData(RendererInputDataCreate rendererInputDataCreate);

		static void Create();
		static void Destroy() noexcept;

		SINGLETON_GET_PTR_DECLARE(RendererInputData);

		CLASS_INVARIANT_DECLARE;

		void Rebuild(RendererTypes type);

	private:
		using RendererInputDataUniquePtr = std::unique_ptr<RendererInputData>;

	private:
		static RendererInputDataUniquePtr sm_RendererInputData;
            PackageType impl;
	};
}

#define RENDERER_INPUT_DATA_SINGLETON Rendering::RendererInputData::GetSingleton()

#endif // FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_H



	