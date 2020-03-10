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

RENDERING_EXPORT_SHARED_PTR(CameraManagerImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace CoreTools
{
	class Mutex;
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE CameraManager : public CoreTools::Singleton<CameraManager>
	{
	public:
		SINGLETON_INITIALIZE_DECLARE(CameraManager); 

	public:	
		CLASS_INVARIANT_DECLARE;

		void SetDefaultDepthType(RendererTypes type);
		DepthType GetDepthType() const;

	private:		
		SINGLETON_INSTANCE_DECLARE(CameraManager);
		SINGLETON_IMPL_DECLARE(CameraManager);
	};
}

#define CAMERA_MANAGE_SINGLETON Rendering::CameraManager::GetSingleton()

#endif // FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_H



	