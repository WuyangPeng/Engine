///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/02 16:46)

#ifndef RENDERING_SCENE_GRAPH_PROJECTOR_H
#define RENDERING_SCENE_GRAPH_PROJECTOR_H

#include "Camera.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Projector : public Camera
    {
    public:
        using ClassType = Projector;
        using ParentType = Camera;
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        using ProjectorSharedPtr = std::shared_ptr<ClassType>;
        using ConstProjectorSharedPtr = std::shared_ptr<ClassType>;
        using Matrix = Mathematics::MatrixF;

    public:
        // �����Camera���Ψһ������,�������ʽ��ָ����ȵ����͡�
        // Camera�౻��ʹ��Ĭ�ϵ��������(�����ϵ�ǰ����ͼ��API)��
        Projector(DepthType depthType, bool isPerspective = true, float epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Projector);

        // ����0����ӳ�� x' = (1 + x) / 2 �� y' = (1 - y) / 2��
        // ����1����ӳ�� x' = (1 + x) / 2 �� y' = (1 + y) / 2��
        NODISCARD static Matrix GetBiasScaleMatrix(int index);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(Projector);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Projector);
}

#endif  // RENDERING_SCENE_GRAPH_PROJECTOR_H
