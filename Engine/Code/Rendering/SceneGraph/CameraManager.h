// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 11:17)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_MANAGE_H
#define RENDERING_SCENE_GRAPH_CAMERA_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "Flags/CameraFlags.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Base/SingletonDetail.h"

#include <boost/noncopyable.hpp>
RENDERING_EXPORT_UNIQUE_PTR(CameraManager);
RENDERING_NON_COPY_EXPORT_IMPL(CameraManagerImpl); 

namespace CoreTools
{
	class Mutex;
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE CameraManager : public CoreTools::Singleton<CameraManager>
	{
 
	public:
		NON_COPY_TYPE_DECLARE(CameraManager);
		using ParentType = Singleton<CameraManager>;

	private:
		enum class CameraManagerCreate
		{
			Init,
		};

	public:
		explicit CameraManager(CameraManagerCreate cameraManagerCreate);

		static void Create();
		static void Destroy() noexcept;

		SINGLETON_GET_PTR_DECLARE(CameraManager);

		CLASS_INVARIANT_DECLARE;

		void SetDefaultDepthType(RendererTypes type);
		DepthType GetDepthType() const;

	private:		
	private:
		using CameraManagerUniquePtr = std::unique_ptr<CameraManager>;

	private:
		static CameraManagerUniquePtr sm_CameraManager;
            PackageType impl;
	};
}

#define CAMERA_MANAGE_SINGLETON Rendering::CameraManager::GetSingleton()

#endif // FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_H



	