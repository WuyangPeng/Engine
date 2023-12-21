///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:51)

#ifndef RENDERING_DETAIL_SWITCH_NODE_H
#define RENDERING_DETAIL_SWITCH_NODE_H

#include "Flags/SwitchNodeType.h"
#include "Rendering/SceneGraph/Node.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SwitchNode : public Node
    {
    public:
        using ClassType = SwitchNode;
        using ParentType = Node;
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        using SwitchNodeSharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static SwitchNodeSharedPtr Create();

    public:
        explicit SwitchNode(NodeCreate nodeCreate);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(SwitchNode);

        void SetActiveChild(int aActiveChild);
        NODISCARD int GetActiveChild() const noexcept;
        void DisableAllChildren() noexcept;

        NODISCARD ControllerSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD PickRecordContainer ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax) const override;

    protected:
        void GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull) override;

    private:
        int activeChild;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(SwitchNode);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(SwitchNode);
}

#endif  // RENDERING_DETAIL_SWITCH_NODE_H
