///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/03 17:25)

#include "Rendering/RenderingExport.h"

#include "TrianglesMesh.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TrianglesMesh);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TrianglesMesh);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TrianglesMesh);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, TrianglesMesh);

Rendering::TrianglesMesh::TrianglesMesh(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer)
    : ParentType{ VisualPrimitiveType::TriangleMesh, vertexformat, vertexbuffer, indexbuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TrianglesMesh)

int Rendering::TrianglesMesh::GetNumTriangles() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return GetConstIndexBuffer()->GetNumElements() / 3;
}

Rendering::TriangleIndex
    Rendering::TrianglesMesh::GetTriangle(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (0 <= index && index < GetNumTriangles())
    {
        const auto value = 3 * index;
        auto indices = (GetConstIndexBuffer()->GetData(value));
        const auto firstIndex = *indices;
        ++indices;
        const auto secondIndex = *indices;
        ++indices;
        const auto thirdIndex = *indices;

        return TriangleIndex{ firstIndex, secondIndex, thirdIndex };
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到三角形顶点索引"s));
    }
}

Rendering::ControllerInterfaceSharedPtr Rendering::TrianglesMesh::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::TrianglesMesh::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return std::make_shared<ClassType>(*this);
}
