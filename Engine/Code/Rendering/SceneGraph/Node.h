/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/28 17:54)

#ifndef RENDERING_SCENE_GRAPH_NODE_H
#define RENDERING_SCENE_GRAPH_NODE_H

#include "Rendering/RenderingDll.h"

#include "Spatial.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/Visibility/VisibilityFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Node, NodeImpl);

// �����ʾ�ڿռ��νṹ�жԽڵ���з��顣
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

        /// ���ǵ�ǰ���������Ԫ����������ЩԪ�ز�����֤���ж��Ƿǿա�
        /// ���,���������������ͷ�����Ԫ��GetChild(...)��
        /// ��Ӧ���ڽ�����֮ǰ���Է���ָ�롣
        NODISCARD int GetNumChildren() const;

        /// ����һ����Ԫ�ص��ڵ㡣
        /// ��������ɹ�,���ص�ֵ����Ԫ�ر��洢�����������,
        /// ����0 <= i < GetNumChildren()��
        /// �洢�ڵ�һ������������Ŀղ۵ġ�
        /// ������в۱�����֮�������Ԫ�ر����ӵ������С�
        /// (���ܵ������·��������)

        /// ����ʧ�ܵ���child����null�򵱡�child���Ѿ���һ��parent,
        /// �����������,��������-1��
        /// �ڵ��γ�һ����,������һ����һ��������޻�ͼ��
        /// �����,һ���ڵ㲻����һ�����ϵ�parent������,

        /// NodeSharedPtr node0 = <some node>;
        /// SpatialSharedPtr child = <some child>;
        /// int index = node0->AttachChild(child);
        /// NodeSharedPtr node1 = <some node>;

        /// ���ﴥ������,��Ϊ��child���Ѿ���һ��parent(node0)��
        /// node1->AttachChild(child);

        /// ��������ȷ��childһ����parent�ķ�����
        /// node0->DetachChild(child);
        /// �� node0->DetachChildAt(index);
        /// node1->AttachChild(child);

        /// ���һ��������DetachChild����֮ǰ,�����child��ֻ��node0����,
        /// Ҫɾ���ķ���ᵼ�¡�child����ɾ��(���ӽڵ��ڲ�ʹ�����ü���)��
        /// ������뱣�桰child���Ա����ã������²�����
        /// SpatialSharedPtr saveChild = node0->GetChild(0);
        /// node0->DetachChild(saveChild);
        /// node1->AttachChild(saveChild);
        int AttachChild(const SpatialSharedPtr& child);

        /// ����һ���ӽڵ������ڵ㡣����ӽڵ��������зǿ�,
        /// ����ֵ�������д洢���ӽڵ������������,�ú�������-1��
        int DetachChild(const SpatialSharedPtr& child);

        /// ����һ���ӽڵ������ڵ㡣
        /// ���0 <= i < GetNumChildren(),����ֵ���ӽڵ������;
        /// ����,��������nullptr��
        SpatialSharedPtr DetachChildAt(int index);

        /// �Ӵ˽ڵ���������ӽڵ㡣
        void DetachAllChildren();

        // ������ͬ��������ͬAttachChildһ�������ڲ����ж��parents��
        // ���0 <= index < GetNumChildren(),�ú����ɹ�,����index��
        // ���index������Χ,�������*��Ȼ*�ɹ�,�����ӽڵ㵽�����ĩβ��
        // ����ֵ��֮ǰ�洢������index���ӽڵ㡣
        NODISCARD SpatialSharedPtr SetChild(int index, const SpatialSharedPtr& child);

        /// ��ȡָ�����������ӽڵ㡣���0 <= i < GetNumChildren(),�ú����ɹ�,�����������ӽڵ㡣
        /// ������ס,child[i]�ܿ�����null�����������Χ,�������ؿն���
        NODISCARD SpatialSharedPtr GetChild(int index);
        NODISCARD ConstSpatialSharedPtr GetConstChild(int index) const;

        NODISCARD ControllerSharedPtr Clone() const override;

        NODISCARD PickRecordContainer ExecuteRecursive(const APoint& origin, const AVector& direction, float tMin, float tMax, int numThreads, float maxDistance) override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        /// �Էּ��ü���֧�֡�
        void GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull) override;

        /// �Լ��θ��µ�֧�֡�
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
