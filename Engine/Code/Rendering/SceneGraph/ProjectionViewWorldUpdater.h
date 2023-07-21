///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/17 19:32)

#ifndef RENDERING_SCENE_GRAPH_PROJECTION_VIEW_WORLD_UPDATER_H
#define RENDERING_SCENE_GRAPH_PROJECTION_VIEW_WORLD_UPDATER_H

#include "Rendering/RenderingDll.h"

#include "Camera.h"
#include "Visual.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ProjectionViewWorldUpdater
    {
    public:
        using ClassType = ProjectionViewWorldUpdater;

    public:
        explicit ProjectionViewWorldUpdater(CoreTools::DisableNotThrow disableNotThrow) noexcept;

        CLASS_INVARIANT_DECLARE;

        std::shared_ptr<Camera> GetCamera() noexcept;
        void Update() noexcept;
        void Unsubscribe(const std::shared_ptr<Visual>& visual) noexcept;
        void Subscribe(const std::shared_ptr<Visual>& visual) noexcept;
    };
}

#endif  // RENDERING_SCENE_GRAPH_PROJECTION_VIEW_WORLD_UPDATER_H
