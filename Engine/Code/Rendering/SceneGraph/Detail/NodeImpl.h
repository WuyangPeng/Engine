///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/01 15:40)

#ifndef RENDERING_SCENE_GRAPH_NODE_IMPL_H
#define RENDERING_SCENE_GRAPH_NODE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Bound.h"
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

        // ���ǵ�ǰ���������Ԫ����������ЩԪ�ز�����֤���ж��Ƿǿա�
        // ���,���������������ͷ�����Ԫ��GetChild(...)��
        // ��Ӧ���ڽ�����֮ǰ���Է���ָ�롣
        NODISCARD int GetNumChildren() const;

        // ����һ����Ԫ�ص��ڵ㡣
        // ��������ɹ�,���ص�ֵ����Ԫ�ر��洢�����������,
        // ����0 <= i < GetNumChildren()��
        // �洢�ڵ�һ������������Ŀղ۵ġ�
        // ������в۱�����֮�������Ԫ�ر����ӵ������С�
        // (���ܵ������·��������)
        //

        // ����ʧ�ܵ���child����null�򵱡�child���Ѿ���һ��parent,
        // �����������,��������-1��
        // �ڵ��γ�һ����,������һ����һ��������޻�ͼ��
        // �����,һ���ڵ㲻����һ�����ϵ�parent������,

        // Node* node0 = <some node>;
        // Spatial* child = <some child>;
        // int index = node0->AttachChild(child);
        // Node* node1 = <some node>;

        // ���ﴥ������,��Ϊ��child���Ѿ���һ��parent(node0)��
        // node1->AttachChild(child);

        // ��������ȷ��childһ����parent�ķ�����
        // node0->DetachChild(child);
        // �� node0->DetachChildAt(index);
        // node1->AttachChild(child);

        // ���һ��������DetachChild����֮ǰ,�����child��ֻ��node0����,
        // Ҫɾ���ķ���ᵼ�¡�child����ɾ��(���ӽڵ��ڲ�ʹ�����ü���)��
        // ������뱣�桰child���Ա�����,�����¡�
        // SpatialPtr saveChild = node0->GetChild(0);
        // node0->DetachChild(saveChild);
        // node1->AttachChild(saveChild);
        int AttachChild(const SpatialSharedPtr& child);

        // ����һ���ӽڵ������ڵ㡣����ӽڵ��������зǿ�,
        // ����ֵ�������д洢���ӽڵ������������,�ú�������-1��
        int DetachChild(const SpatialSharedPtr& child);

        // ����һ���ӽڵ������ڵ㡣
        // ���0 <= i < GetNumChildren(),����ֵ���ӽڵ������;
        // ����,��������nullptr��
        NODISCARD SpatialSharedPtr DetachChildAt(int index);

        // ������ͬ��������ͬAttachChildһ�������ڲ����ж��parents��
        // ���0 <= index < GetNumChildren(),�ú����ɹ�,����index��
        // ���index������Χ,�������*��*�ɹ�,�����ӽڵ㵽�����ĩβ��
        // ����ֵ��֮ǰ�洢������index���ӽڵ㡣
        NODISCARD SpatialSharedPtr SetChild(int index, const SpatialSharedPtr& child);

        // ��ȡָ�����������ӽڵ㡣���0 <= i < GetNumChildren(),�ú����ɹ�,�����������ӽڵ�
        // ������ס,child[i]�ܿ�����null�����������Χ,��������nullptr��
        NODISCARD SpatialSharedPtr GetChild(int index);
        NODISCARD ConstSpatialSharedPtr GetConstChild(int index) const;

        // �Լ��θ��µ�֧�֡�
        NODISCARD bool UpdateWorldData(double applicationTime);
        NODISCARD BoundF GetWorldBound();

        // �Էּ��ü���֧�֡�
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
        // �ӽڵ�ָ�롣
        SpatialVector spatialChild;

        Node* realThis;
    };
}

#endif  // RENDERING_SCENE_GRAPH_NODE_IMPL_H
