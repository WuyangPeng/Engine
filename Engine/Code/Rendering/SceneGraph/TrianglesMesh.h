///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:11)

#ifndef RENDERING_SCENE_GRAPH_TRIANGLES_MESH_H
#define RENDERING_SCENE_GRAPH_TRIANGLES_MESH_H

#include "Rendering/RenderingDll.h"

#include "Triangles.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TrianglesMesh : public Triangles
    {
    public:
        using ClassType = TrianglesMesh;
        using ParentType = Triangles;
        using ClassShareType = CoreTools::CopyUnsharedClasses;

    public:
        TrianglesMesh(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(TrianglesMesh);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    public:
        // �������������ݵĽ��͡�
        NODISCARD int GetNumTriangles() const noexcept override;
        NODISCARD TriangleIndex GetTriangle(int index) const override;

        NODISCARD ControllerSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(TrianglesMesh);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TrianglesMesh);
}

#endif  // RENDERING_SCENE_GRAPH_TRIANGLES_MESH_H
