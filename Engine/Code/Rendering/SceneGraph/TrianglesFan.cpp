///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/03 17:24)

#include "Rendering/RenderingExport.h"

#include "TrianglesFan.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TrianglesFan);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TrianglesFan);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TrianglesFan);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, TrianglesFan);

Rendering::TrianglesFan::TrianglesFan(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer)
    : ParentType{ VisualPrimitiveType::TriangleFan, vertexformat, vertexbuffer, indexbuffer }
{
    RENDERING_ASSERTION_1(indexbuffer->GetNumElements() >= vertexbuffer->GetNumElements(), "索引缓冲区没有足够的元素\n");

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TrianglesFan::TrianglesFan(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, int indexSize)
    : ParentType{ VisualPrimitiveType::TriangleFan, vertexformat, vertexbuffer, IndexBufferSharedPtr() }
{
    const auto numVertices = vertexbuffer->GetNumElements();

    auto indexBuffer = IndexBuffer::Create(IndexFormatType::Polypoint, numVertices, indexSize);
    InitIndexBuffer(*indexBuffer);
    SetIndexBuffer(indexBuffer);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TrianglesFan)

int Rendering::TrianglesFan::GetNumTriangles() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return GetConstIndexBuffer()->GetNumElements() - 2;
}

Rendering::TriangleIndex Rendering::TrianglesFan::GetTriangle(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (0 <= index && index < GetNumTriangles())
    {
        auto indices = (GetConstIndexBuffer()->GetData());
        const auto firstIndex = *indices;
        indices += (index + 1);
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

Rendering::ControllerInterfaceSharedPtr Rendering::TrianglesFan::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

void Rendering::TrianglesFan::InitIndexBuffer(IndexBuffer& indexBuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto indexSize = indexBuffer.GetElementSize();

    RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

    const auto numVertices = indexBuffer.GetNumElements();

    if (indexSize == 2)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        const auto indices = reinterpret_cast<int16_t*>(&*indexBuffer.GetData(0).GetCurrent());

#include STSTEM_WARNING_POP

        if (indices != nullptr)
        {
            for (int16_t i{}; i < numVertices; ++i)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[i] = i;

#include STSTEM_WARNING_POP
            }
        }
    }
    else  // indexSize == 4
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto indices = reinterpret_cast<int32_t*>(&*indexBuffer.GetData(0).GetCurrent());

#include STSTEM_WARNING_POP
        if (indices != nullptr)
        {
            for (auto i = 0; i < numVertices; ++i)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[i] = i;

#include STSTEM_WARNING_POP
            }
        }
    }
}

CoreTools::ObjectInterfaceSharedPtr Rendering::TrianglesFan::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
