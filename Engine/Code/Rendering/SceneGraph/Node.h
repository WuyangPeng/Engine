///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:10)

#ifndef RENDERING_SCENE_GRAPH_NODE_H
#define RENDERING_SCENE_GRAPH_NODE_H

#include "Rendering/RenderingDll.h"

#include "Culler.h"
#include "Spatial.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Node, NodeImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Node : public Spatial
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Node);
        using ParentType = Spatial;
        using NodeSharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static NodeSharedPtr Create();

    protected:
        enum class NodeCreate
        {
            Init,
        };

    public:
        explicit Node(MAYBE_UNUSED NodeCreate nodeCreate);
        ~Node() noexcept = default;
        Node(const Node& rhs);
        Node& operator=(const Node& rhs);
        Node(Node&& rhs) noexcept;
        Node& operator=(Node&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Node);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        NODISCARD int GetNumChildren() const;

        int AttachChild(SpatialSharedPtr child);
        int DetachChild(SpatialSharedPtr child);
        SpatialSharedPtr DetachChildAt(int index);
        NODISCARD SpatialSharedPtr GetChild(int index);
        NODISCARD ConstSpatialSharedPtr GetConstChild(int index) const;

        void GetVisibleSet(Culler& culler, bool noCull) override;

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;

        NODISCARD PickRecordContainer ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax) const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        NODISCARD bool UpdateWorldData(double applicationTime) override;

        NODISCARD bool UpdateImplWorldData(double applicationTime);

    private:
        void UpdateWorldBound() override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Node);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Node);
}

#endif  // RENDERING_SCENE_GRAPH_NODE_H
