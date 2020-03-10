// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 19:15)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_NODE_IMPL_H
#define RENDERING_SCENE_GRAPH_CAMERA_NODE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/DataTypes/Transform.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"

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
    class RENDERING_HIDDEN_DECLARE CameraNodeImpl  
    {
    public:
		using ClassType = CameraNodeImpl;
		using APoint = Mathematics::APoint<float>;
		using AVector = Mathematics::AVector<float>;
		using Matrix = Mathematics::Matrix<float>;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using ObjectRegister = CoreTools::ObjectRegister;
		using ObjectLink = CoreTools::ObjectLink;
		using Object = CoreTools::Object;
        
    public:
        // �ڵ����������ʹ�������λ�á�
        // �ڵ��������ת����ʹ������������ᡣ
        // ������ת�������0�������direction����,
        // ������ת�������1�������up����,
        // ������ת�������2�������right������

        // �ڵ�ľֲ��任������Ϊ����ĵ�ǰ����ϵͳ��
        //   local translation       = camera location
        //   local rotation column 0 = camera direction
        //   local rotation column 1 = camera up
        //   local rotation column 2 = camera right
		explicit CameraNodeImpl(const CameraSmartPointer& camera);

		CLASS_INVARIANT_DECLARE;

		bool IsNullPtr() const;

		// ����������������ڵ�ı���ת��������Ϊ��ǰ����ĵ�ǰ����ϵͳ��
		// �ڵ������任��������,
		// �����������ϵʹ�ýڵ������ת����
		void SetCamera(const CameraSmartPointer& camera);
		const ConstCameraSmartPointer GetCamera() const;

		const Transform GetLocalTransform() const;

	    void SetFrame (const APoint& position,const AVector& directionVector,const AVector& upVector,const AVector& rightVector);

		void Load(BufferSource& source);
		void Save(BufferTarget& target) const;
		int GetStreamingSize() const;
		uint64_t Register(CoreTools::ObjectRegister& target) const;
		void Link(CoreTools::ObjectLink& source);

		CORE_TOOLS_NAMES_IMPL_DECLARE;
       
    private:
		CameraSmartPointer m_Camera;
    };
}

#endif // RENDERING_SCENE_GRAPH_CAMERA_NODE_IMPL_H
