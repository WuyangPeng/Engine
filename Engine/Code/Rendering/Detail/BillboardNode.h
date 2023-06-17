///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:51)

#ifndef RENDERING_DETAIL_BILLBOARD_NODE_H
#define RENDERING_DETAIL_BILLBOARD_NODE_H

#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Node.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(BillboardNode, BillboardNodeImpl);

namespace Rendering
{
    // 广告牌的模型空间具有的(0,1,0)向上矢量
    // 被选择为旋转的广告牌的轴。
    class RENDERING_DEFAULT_DECLARE BillboardNode : public Node
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(BillboardNode);
        using ParentType = Node;

    public:
        explicit BillboardNode(const CameraSharedPtr& camera);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BillboardNode);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        // 广告牌对齐的摄像头。
        void AlignTo(const CameraSharedPtr& camera) noexcept;

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;

        NODISCARD ConstCameraSharedPtr GetCamera() const noexcept;

    private:
        // 对几何更新的支持。
        bool UpdateWorldData(double applicationTime) override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(BillboardNode);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(BillboardNode);
}

#endif  // RENDERING_DETAIL_BILLBOARD_NODE_H
