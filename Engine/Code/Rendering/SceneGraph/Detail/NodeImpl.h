///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:07)

#ifndef RENDERING_SCENE_GRAPH_NODE_IMPL_H
#define RENDERING_SCENE_GRAPH_NODE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/BoundingSphere.h"
#include "Rendering/SceneGraph/Culler.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/SceneGraph/Spatial.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE NodeImpl
    {
    public:
        using ClassType = NodeImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ObjectLink = CoreTools::ObjectLink;
        using Object = CoreTools::Object;

    public:
        explicit NodeImpl(Node* realThis) noexcept;
        ~NodeImpl() noexcept;

        NodeImpl(NodeImpl&& rhs) = default;
        NodeImpl& operator=(NodeImpl&& rhs) = default;
        NodeImpl(const NodeImpl& rhs) noexcept = default;
        NodeImpl& operator=(const NodeImpl& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        // 这是当前的子数组的元素数量。这些元素并不保证所有都是非空。
        // 因此,当您遍历这个数组和访问子元素GetChild(...)，
        // 你应该在解引用之前测试返回指针。
        NODISCARD int GetNumChildren() const;

        // 附加一个子元素到节点。
        // 如果函数成功,返回的值是子元素被存储在数组的索引,
        // 其中0 <= i < GetNumChildren()。
        // 存储于第一个可用子数组的空槽的。
        // 如果所有槽被填满之后，这个子元素被附加到数组中。
        // (可能导致重新分配的数组)
        //

        // 函数失败当‘child’是null或当“child”已经有一个parent,
        // 在这种情况下,函数返回-1。
        // 节点形成一个树,而不是一个更一般的有向无环图。
        // 结果是,一个节点不能有一个以上的parent。例如,

        // Node* node0 = <some node>;
        // Spatial* child = <some child>;
        // int index = node0->AttachChild(child);
        // Node* node1 = <some node>;

        // 这里触发断言,因为“child”已经有一个parent(node0)。
        // node1->AttachChild(child);

        // 以下是正确给child一个新parent的方法。
        // node0->DetachChild(child);
        // 或 node0->DetachChildAt(index);
        // node1->AttachChild(child);

        // 最后一个例子在DetachChild调用之前,如果‘child’只有node0引用,
        // 要删除的分离会导致“child”被删除(其子节点内部使用引用计数)。
        // 如果你想保存“child”以备后用,做以下。
        // SpatialPtr saveChild = node0->GetChild(0);
        // node0->DetachChild(saveChild);
        // node1->AttachChild(saveChild);
        int AttachChild(const SpatialSharedPtr& child);

        // 分离一个子节点从这个节点。如果子节点在数组中非空,
        // 返回值是数组中存储的子节点的索引。否则,该函数返回-1。
        int DetachChild(const SpatialSharedPtr& child);

        // 分离一个子节点从这个节点。
        // 如果0 <= i < GetNumChildren(),返回值是子节点的索引;
        // 否则,函数返回nullptr。
        NODISCARD SpatialSharedPtr DetachChildAt(int index);

        // 在这里同样的限制同AttachChild一样，关于不能有多个parents。
        // 如果0 <= index < GetNumChildren(),该函数成功,返回index。
        // 如果index超出范围,这个函数*还*成功,附加子节点到数组的末尾。
        // 返回值是之前存储在索引index的子节点。
        NODISCARD SpatialSharedPtr SetChild(int index, const SpatialSharedPtr& child);

        // 获取指定的索引的子节点。如果0 <= i < GetNumChildren(),该函数成功,返回索引的子节点
        // ——记住,child[i]很可能是null。如果超出范围,函数返回nullptr。
        NODISCARD SpatialSharedPtr GetChild(int index);
        NODISCARD ConstSpatialSharedPtr GetConstChild(int index) const;

        // 对几何更新的支持。
        NODISCARD bool UpdateWorldData(double applicationTime);
        NODISCARD Mathematics::BoundingSphereF GetWorldBound();

        // 对分级裁剪的支持。
        void GetVisibleSet(Culler& culler, bool noCull);

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;
        void Register(CoreTools::ObjectRegister& target) const;
        void Link(CoreTools::ObjectLink& source);

        void Clear() noexcept;
        void ChangeRealThis(Node* aRealThis) noexcept;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

    private:
        using ObjectAssociated = CoreTools::ObjectAssociated<Spatial>;
        using SpatialVector = std::vector<ObjectAssociated>;

    private:
        NODISCARD int GetFirstNullIndex() const;

    private:
        // 子节点指针。
        SpatialVector spatialChild;

        Node* realThis;
    };
}

#endif  // RENDERING_SCENE_GRAPH_NODE_IMPL_H
