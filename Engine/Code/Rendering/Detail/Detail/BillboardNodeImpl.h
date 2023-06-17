///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:50)

#ifndef RENDERING_DETAIL_BILLBOARD_NODE_IMPL_H
#define RENDERING_DETAIL_BILLBOARD_NODE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/SceneGraph/Camera.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE BillboardNodeImpl
    {
    public:
        using ClassType = BillboardNodeImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ObjectLink = CoreTools::ObjectLink;
        using Object = CoreTools::Object;

    public:
        BillboardNodeImpl() noexcept;
        explicit BillboardNodeImpl(const CameraSharedPtr& camera) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        void AlignTo(const CameraSharedPtr& aCamera) noexcept;

        NODISCARD ConstCameraSharedPtr GetCamera() const noexcept;

    private:
        CoreTools::ObjectAssociated<Camera> camera;
    };
}

#endif  // RENDERING_DETAIL_BILLBOARD_NODE_IMPL_H
