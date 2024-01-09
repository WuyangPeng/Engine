/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:35)

#ifndef RENDERING_SCENE_GRAPH_LIGHT_IMPL_H
#define RENDERING_SCENE_GRAPH_LIGHT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "Rendering/LocalEffects/Lighting.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE LightImpl
    {
    public:
        using ClassType = LightImpl;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectAssociated = CoreTools::ObjectAssociated<Lighting>;

    public:
        LightImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD LightingSharedPtr GetLighting();
        void SetLighting(const LightingSharedPtr& aLighting) noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

    private:
        ObjectAssociated lighting;
    };
}

#endif  // RENDERING_SCENE_GRAPH_LIGHT_IMPL_H
