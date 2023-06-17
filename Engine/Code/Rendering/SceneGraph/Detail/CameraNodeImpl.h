///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:06)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_NODE_IMPL_H
#define RENDERING_SCENE_GRAPH_CAMERA_NODE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/SceneGraph/Camera.h"

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
        using ObjectAssociated = CoreTools::ObjectAssociated<Camera>;

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
        explicit CameraNodeImpl(const CameraSharedPtr& camera) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsNullPtr() const noexcept;

        // ����������������ڵ�ı���ת��������Ϊ��ǰ����ĵ�ǰ����ϵͳ��
        // �ڵ������任��������,
        // �����������ϵʹ�ýڵ������ת����
        void SetCamera(const CameraSharedPtr& aCamera) noexcept;
        NODISCARD ConstCameraSharedPtr GetCamera() const noexcept;

        NODISCARD TransformF GetLocalTransform() const;

        void SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector);

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;
        uint64_t Register(CoreTools::ObjectRegister& target) const;
        void Link(CoreTools::ObjectLink& source);

        CORE_TOOLS_NAMES_IMPL_DECLARE;

    private:
        ObjectAssociated camera;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_NODE_IMPL_H
