// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 19:19)

#ifndef RENDERING_SCENE_GRAPH_NODE_IMPL_H
#define RENDERING_SCENE_GRAPH_NODE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Bound.h"
#include "Rendering/SceneGraph/Culler.h"
#include "Rendering/SceneGraph/Spatial.h"

#include <string>
#include <vector>

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
	class ObjectRegister;
	class ObjectLink;
    class Object;
}

namespace Rendering
{
    class Culler;
	class Node;
    
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
        explicit NodeImpl (Node* realThis);
        ~NodeImpl ();
        
		CLASS_INVARIANT_DECLARE;    
        
        // ���ǵ�ǰ���������Ԫ����������ЩԪ�ز�����֤���ж��Ƿǿա�
        // ���,���������������ͷ�����Ԫ��GetChild(...)��
        // ��Ӧ���ڽ�����֮ǰ���Է���ָ�롣
        int GetNumChildren () const;

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
		int AttachChild(SpatialSmartPointer& child);

        // ����һ���ӽڵ������ڵ㡣����ӽڵ��������зǿ�,
        // ����ֵ�������д洢���ӽڵ������������,�ú�������-1��
		int DetachChild(SpatialSmartPointer& child);
 
        // ����һ���ӽڵ������ڵ㡣
        // ���0 <= i < GetNumChildren(),����ֵ���ӽڵ������;
        // ����,��������nullptr��
		SpatialSmartPointer DetachChildAt(int index);
 
        // ������ͬ��������ͬAttachChildһ�������ڲ����ж��parents��
        // ���0 <= index < GetNumChildren(),�ú����ɹ�,����index��
        // ���index������Χ,�������*��*�ɹ�,�����ӽڵ㵽�����ĩβ��
        // ����ֵ��֮ǰ�洢������index���ӽڵ㡣
		SpatialSmartPointer SetChild(int index,SpatialSmartPointer& child);
 
        // ��ȡָ�����������ӽڵ㡣���0 <= i < GetNumChildren(),�ú����ɹ�,�����������ӽڵ�
        // ������ס,child[i]�ܿ�����null�����������Χ,��������nullptr��
		SpatialSmartPointer GetChild(int index);
		ConstSpatialSmartPointer GetConstChild(int index) const;

        // �Լ��θ��µ�֧�֡�
        bool UpdateWorldData (double applicationTime);
        const Bound GetWorldBound ();

        // �Էּ��ü���֧�֡�
        void GetVisibleSet (Culler& culler, bool noCull);
        
        void Load (BufferSource& source);
		void Save (BufferTarget& target) const;
		int GetStreamingSize () const;
        void Register (ObjectRegister& target) const;
        void Link (ObjectLink& source);
        
       CORE_TOOLS_NAMES_IMPL_DECLARE;
        
    private:
		using SpatialPtrVector = std::vector<SpatialSmartPointer>; 
        
    private:
        int GetFirstNullIndex() const;

    private:
        // �ӽڵ�ָ�롣
		SpatialPtrVector m_Child;
        
        Node* m_RealThis;
    };
}

#endif // RENDERING_SCENE_GRAPH_NODE_IMPL_H
