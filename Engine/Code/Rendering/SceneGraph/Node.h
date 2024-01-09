/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:54)

#ifndef RENDERING_SCENE_GRAPH_NODE_H
#define RENDERING_SCENE_GRAPH_NODE_H

#include "Rendering/RenderingDll.h"

#include "Spatial.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/Visibility/VisibilityFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Node, NodeImpl);

// 此类表示在空间层次结构中对节点进行分组。
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Node : public Spatial
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Node);
        using ParentType = Spatial;

        using NodeSharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static NodeSharedPtr Create(const std::string& name);

    protected:
        enum class NodeCreate
        {
            Init,
        };

    public:
        Node(const std::string& name, NodeCreate nodeCreate);
        ~Node() noexcept = default;
        Node(const Node& rhs);
        Node& operator=(const Node& rhs);
        Node(Node&& rhs) noexcept;
        Node& operator=(Node&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Node);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        /// 这是当前的子数组的元素数量。这些元素并不保证所有都是非空。
        /// 因此,当您遍历这个数组和访问子元素GetChild(...)，
        /// 你应该在解引用之前测试返回指针。
        NODISCARD int GetNumChildren() const;

        /// 附加一个子元素到节点。
        /// 如果函数成功,返回的值是子元素被存储在数组的索引,
        /// 其中0 <= i < GetNumChildren()。
        /// 存储于第一个可用子数组的空槽的。
        /// 如果所有槽被填满之后，这个子元素被附加到数组中。
        /// (可能导致重新分配的数组)

        /// 函数失败当‘child’是null或当“child”已经有一个parent,
        /// 在这种情况下,函数返回-1。
        /// 节点形成一个树,而不是一个更一般的有向无环图。
        /// 结果是,一个节点不能有一个以上的parent。例如,

        /// NodeSharedPtr node0 = <some node>;
        /// SpatialSharedPtr child = <some child>;
        /// int index = node0->AttachChild(child);
        /// NodeSharedPtr node1 = <some node>;

        /// 这里触发断言,因为“child”已经有一个parent(node0)。
        /// node1->AttachChild(child);

        /// 以下是正确给child一个新parent的方法。
        /// node0->DetachChild(child);
        /// 或 node0->DetachChildAt(index);
        /// node1->AttachChild(child);

        /// 最后一个例子在DetachChild调用之前,如果‘child’只有node0引用,
        /// 要删除的分离会导致“child”被删除(其子节点内部使用引用计数)。
        /// 如果你想保存“child”以备后用，做以下操作。
        /// SpatialSharedPtr saveChild = node0->GetChild(0);
        /// node0->DetachChild(saveChild);
        /// node1->AttachChild(saveChild);
        int AttachChild(const SpatialSharedPtr& child);

        /// 分离一个子节点从这个节点。如果子节点在数组中非空,
        /// 返回值是数组中存储的子节点的索引。否则,该函数返回-1。
        int DetachChild(const SpatialSharedPtr& child);

        /// 分离一个子节点从这个节点。
        /// 如果0 <= i < GetNumChildren(),返回值是子节点的索引;
        /// 否则,函数返回nullptr。
        SpatialSharedPtr DetachChildAt(int index);

        /// 从此节点分离所有子节点。
        void DetachAllChildren();

        // 在这里同样的限制同AttachChild一样，关于不能有多个parents。
        // 如果0 <= index < GetNumChildren(),该函数成功,返回index。
        // 如果index超出范围,这个函数*依然*成功,附加子节点到数组的末尾。
        // 返回值是之前存储在索引index的子节点。
        NODISCARD SpatialSharedPtr SetChild(int index, const SpatialSharedPtr& child);

        /// 获取指定的索引的子节点。如果0 <= i < GetNumChildren(),该函数成功,返回索引的子节点。
        /// ——记住,child[i]很可能是null。如果超出范围,函数返回空对象。
        NODISCARD SpatialSharedPtr GetChild(int index);
        NODISCARD ConstSpatialSharedPtr GetConstChild(int index) const;

        NODISCARD ControllerSharedPtr Clone() const override;

        NODISCARD PickRecordContainer ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax, int numThreads, float maxDistance) override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        /// 对分级裁剪的支持。
        void GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull) override;

        /// 对几何更新的支持。
        NODISCARD bool UpdateWorldData(double applicationTime) override;
        void UpdateWorldBound() override;
        NODISCARD bool UpdateChildWorldData(double applicationTime);

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Node);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Node);
}

#endif  // RENDERING_SCENE_GRAPH_NODE_H
