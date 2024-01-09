/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:52)

#ifndef RENDERING_SCENE_GRAPH_VIEW_VOLUME_NODE_IMPL_H
#define RENDERING_SCENE_GRAPH_VIEW_VOLUME_NODE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/SceneGraph/Camera.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ViewVolumeNodeImpl
    {
    public:
        using ClassType = ViewVolumeNodeImpl;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ObjectLink = CoreTools::ObjectLink;
        using ObjectAssociated = CoreTools::ObjectAssociated<ViewVolume>;

    public:
        explicit ViewVolumeNodeImpl(const ViewVolumeSharedPtr& viewVolume) noexcept;

        CLASS_INVARIANT_DECLARE;
        CORE_TOOLS_NAMES_IMPL_DECLARE;

        void SetViewVolume(const ViewVolumeSharedPtr& aViewVolume) noexcept;
        NODISCARD ViewVolumeSharedPtr GetViewVolume() const noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;
        void Register(ObjectRegister& target) const;
        void Link(ObjectLink& source);

    private:
        ObjectAssociated viewVolume;
    };
}

#endif  // RENDERING_SCENE_GRAPH_VIEW_VOLUME_NODE_IMPL_H
