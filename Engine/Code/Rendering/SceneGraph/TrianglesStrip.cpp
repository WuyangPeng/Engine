///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:19)

#include "Rendering/RenderingExport.h"

#include "TrianglesStrip.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TrianglesStrip);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TrianglesStrip);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TrianglesStrip);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, TrianglesStrip);

Rendering::TrianglesStrip::TrianglesStrip(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer)
    : ParentType{ VisualPrimitiveType::TriangleStrip, vertexformat, vertexbuffer, indexbuffer }
{
    RENDERING_ASSERTION_1(indexbuffer->GetNumElements() >= vertexbuffer->GetNumElements(), "索引缓冲区没有足够的元素\n");

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TrianglesStrip::TrianglesStrip(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, int indexSize)
    : ParentType{ VisualPrimitiveType::TriangleStrip, vertexformat, vertexbuffer, IndexBufferSharedPtr() }
{
    const auto numVertices = vertexbuffer->GetNumElements();

    IndexBufferSharedPtr indexBuffer{ IndexBuffer::Create(IndexFormatType::PolyPoint, numVertices, indexSize) };
    InitIndexBuffer(*indexBuffer);
    SetIndexBuffer(indexBuffer);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TrianglesStrip)

int Rendering::TrianglesStrip::GetNumTriangles() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return GetConstIndexBuffer()->GetNumElements() - 2;
}

Rendering::TriangleIndex
    Rendering::TrianglesStrip::GetTriangle(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (0 <= index && index < GetNumTriangles())
    {
        auto indices = (GetConstIndexBuffer()->GetData(index));
        const auto firstIndex = indices.Increase<int>();
        auto secondIndex = -1;
        auto thirdIndex = -1;
        if (index & 1)
        {
            ++indices;
            thirdIndex = indices.Increase<int>();
            ++indices;
            secondIndex = indices.Increase<int>();
        }
        else
        {
            ++indices;
            secondIndex = indices.Increase<int>();
            ++indices;
            thirdIndex = indices.Increase<int>();
        }

        // 退化三角形被假定为互换和添加在三角地带。
        // 他们被认为是无效的。
        if (firstIndex != secondIndex && firstIndex != thirdIndex && secondIndex != thirdIndex)
        {
            return TriangleIndex{ firstIndex, secondIndex, thirdIndex };
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("三角形顶点索引是无效的"s));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到三角形顶点索引"s));
    }
}

Rendering::ControllerInterfaceSharedPtr Rendering::TrianglesStrip::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

void Rendering::TrianglesStrip::InitIndexBuffer(IndexBuffer& indexBuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto indexSize = indexBuffer.GetElementSize();

    RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

    const auto numVertices = indexBuffer.GetNumElements();

    if (indexSize == 2)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        const auto indices = reinterpret_cast<int16_t*>(*indexBuffer.GetData(0));

#include SYSTEM_WARNING_POP

        if (indices != nullptr)
        {
            for (int16_t i{}; i < numVertices; ++i)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[i] = i;

#include SYSTEM_WARNING_POP
            }
        }
    }
    else  // indexSize == 4
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto indices = reinterpret_cast<int32_t*>(*indexBuffer.GetData(0));

#include SYSTEM_WARNING_POP
        if (indices != nullptr)
        {
            for (auto i = 0; i < numVertices; ++i)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[i] = i;

#include SYSTEM_WARNING_POP
            }
        }
    }
}

CoreTools::ObjectInterfaceSharedPtr Rendering::TrianglesStrip::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
