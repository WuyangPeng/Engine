///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/03 17:24)

#ifndef RENDERING_SCENE_GRAPH_TRIANGLES_FAN_H
#define RENDERING_SCENE_GRAPH_TRIANGLES_FAN_H

#include "Rendering/RenderingDll.h"

#include "Triangles.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TrianglesFan : public Triangles
    {
    public:
        using ClassType = TrianglesFan;
        using ParentType = Triangles;
        using ClassShareType = CoreTools::CopyUnsharedClasses;

    public:
        TrianglesFan(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, int indexSize);
        TrianglesFan(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(TrianglesFan);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    public:
        // �������������ݵĽ��͡�
        NODISCARD int GetNumTriangles() const noexcept override;
        NODISCARD TriangleIndex GetTriangle(int index) const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD ControllerInterfaceSharedPtr Clone() const override;

    private:
        void InitIndexBuffer(IndexBuffer& indexBuffer);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(TrianglesFan);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TrianglesFan);
}

#endif  // RENDERING_SCENE_GRAPH_TRIANGLES_FAN_H
