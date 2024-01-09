/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/28 17:55)

#ifndef RENDERING_SCENE_GRAPH_VIEW_VOLUME_NODE_H
#define RENDERING_SCENE_GRAPH_VIEW_VOLUME_NODE_H

#include "Rendering/RenderingDll.h"

#include "Camera.h"
#include "Node.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ViewVolumeNode, ViewVolumeNodeImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ViewVolumeNode : public Node
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ViewVolumeNode);
        using ParentType = Node;

    public:
        explicit ViewVolumeNode(const ViewVolumeSharedPtr& viewVolume);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ControllerSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ViewVolumeNode);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        void SetViewVolume(const ViewVolumeSharedPtr& viewVolume);
        NODISCARD ViewVolumeSharedPtr GetViewVolume() const noexcept;

    protected:
        NODISCARD bool UpdateWorldData(double applicationTime) override;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ViewVolumeNode);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ViewVolumeNode);
}

#endif  // RENDERING_SCENE_GRAPH_VIEW_VOLUME_NODE_H
