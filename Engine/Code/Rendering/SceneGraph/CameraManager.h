///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:09)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_MANAGE_H
#define RENDERING_SCENE_GRAPH_CAMERA_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "Flags/CameraFlags.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"

RENDERING_EXPORT_UNIQUE_PTR(CameraManager);
RENDERING_NON_COPY_EXPORT_IMPL(CameraManagerImpl);

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
        NODISCARD DepthType GetDepthType() const;

    private:
        using CameraManagerUniquePtr = std::unique_ptr<CameraManager>;

    private:
        static CameraManagerUniquePtr cameraManager;
        PackageType impl;
    };
}

#define CAMERA_MANAGE_SINGLETON Rendering::CameraManager::GetSingleton()

#endif  // FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_H
