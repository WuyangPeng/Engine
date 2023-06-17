///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:10)

#ifndef RENDERING_SCENE_GRAPH_POLYPOINT_H
#define RENDERING_SCENE_GRAPH_POLYPOINT_H

#include "Rendering/RenderingDll.h"

#include "Visual.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Polypoint : public Visual
    {
    public:
        using ClassType = Polypoint;
        using ParentType = Visual;
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        using PolypointSharedPtr = std::shared_ptr<ClassType>;
        using ConstPolypointSharedPtr = std::shared_ptr<ClassType>;

    public:
        Polypoint(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Polypoint);

        // ����Ӧ�ó���ָ��������С�����ֵ���ڻ��ơ�
        NODISCARD int GetMaxNumPoints() const noexcept;
        void SetNumPoints(int numPoints) noexcept;
        NODISCARD int GetNumPoints() const noexcept;

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        // ��ǰ����������
        int pointsCount;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Polypoint);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Polypoint);
}

#endif  // RENDERING_SCENE_GRAPH_POLYPOINT_H
