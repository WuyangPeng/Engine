///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 16:32)

#include "Rendering/RenderingExport.h"

#include "VertexBuffer.h"
#include "VertexBufferAccessor.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/Renderers/RendererManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, VertexBuffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VertexBuffer);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VertexBuffer);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, VertexBuffer);

Rendering::VertexBuffer::VertexBuffer(MAYBE_UNUSED VertexBufferCreate indexBufferCreate)
    : ParentType{ CoreTools::DisableNotThrow::Disable }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VertexBuffer::VertexBuffer(MAYBE_UNUSED VertexBufferCreate indexBufferCreate, int numVertices, int vertexSize, BufferUsage usage)
    : ParentType{ numVertices, vertexSize, usage }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VertexBuffer)

Rendering::VertexBuffer::VertexBufferSharedPtr Rendering::VertexBuffer::Create()
{
    return std::make_shared<ClassType>(VertexBufferCreate::Init);
}

Rendering::VertexBuffer::VertexBufferSharedPtr Rendering::VertexBuffer::Create(int numVertices, int vertexSize, BufferUsage usage)
{
    return std::make_shared<ClassType>(VertexBufferCreate::Init, numVertices, vertexSize, usage);
}

void Rendering::VertexBuffer::SaveToFile(WriteFileManager& outFile, const VertexFormat& vertexformat) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ParentType::SaveHeadToFile(outFile);
    ParentType::SaveBufferDataToFile(outFile, vertexformat);
}

void Rendering::VertexBuffer::ReadFromFile(ReadFileManager& inFile, const VertexFormat& vertexformat)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::ReadHeadFromFile(inFile);
    ParentType::ReadBufferDataFromFile(inFile, vertexformat);
}

void Rendering::VertexBuffer::ClearModelNormals(const VertexBufferAccessor& vertexBufferAccessor)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

    const auto numVertices = vertexBufferAccessor.GetNumVertices();

    for (auto index = 0; index < numVertices; ++index)
    {
        const auto excursion = vertexBufferAccessor.GetNormalExcursion(index);
        auto data = GetAccessWriteData(excursion);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

        auto firstNormal = reinterpret_cast<float*>(data);
        auto secondNormal = firstNormal + 1;
        auto thirdNormal = secondNormal + 1;

#include STSTEM_WARNING_POP

        *firstNormal = 0.0f;
        *secondNormal = 0.0f;
        *thirdNormal = 0.0f;
    }
}

void Rendering::VertexBuffer::NormalizeModelNormals(const VertexBufferAccessor& vertexBufferAccessor)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

    const auto numVertices = vertexBufferAccessor.GetNumVertices();

    for (auto index = 0; index < numVertices; ++index)
    {
        const auto excursion = vertexBufferAccessor.GetNormalExcursion(index);
        auto data = GetAccessWriteData(excursion);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

        auto firstNormal = reinterpret_cast<float*>(data);
        auto secondNormal = firstNormal + 1;
        auto thirdNormal = secondNormal + 1;

#include STSTEM_WARNING_POP

        AVector vector{ *firstNormal, *secondNormal, *thirdNormal };
        vector.Normalize();

        *firstNormal = vector[0];
        *secondNormal = vector[1];
        *thirdNormal = vector[2];
    }
}

void Rendering::VertexBuffer::AddTriangleNormal(const VertexBufferAccessor& vertexBufferAccessor, int index, const AVector& normal)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

    const auto numVertices = vertexBufferAccessor.GetNumVertices();

    if (0 <= index && index < numVertices)
    {
        const auto excursion = vertexBufferAccessor.GetNormalExcursion(index);
        auto data = GetAccessWriteData(excursion);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

        auto firstNormal = reinterpret_cast<float*>(data);
        auto secondNormal = firstNormal + 1;
        auto thirdNormal = secondNormal + 1;

#include STSTEM_WARNING_POP

        AVector sum{ *firstNormal, *secondNormal, *thirdNormal };
        sum += normal;

        *firstNormal = sum[0];
        *secondNormal = sum[1];
        *thirdNormal = sum[2];
    }
}

void Rendering::VertexBuffer::SetTriangleTangent(const VertexBufferAccessor& vertexBufferAccessor, int index, const AVector& tangent)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

    const auto numVertices = vertexBufferAccessor.GetNumVertices();

    if (0 <= index && index < numVertices)
    {
        const auto excursion = vertexBufferAccessor.GetTangentExcursion(index);
        auto data = GetAccessWriteData(excursion);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

        auto firstTangent = reinterpret_cast<float*>(data);
        auto secondTangent = firstTangent + 1;
        auto thirdTangent = secondTangent + 1;

#include STSTEM_WARNING_POP

        *firstTangent = tangent[0];
        *secondTangent = tangent[1];
        *thirdTangent = tangent[2];
    }
}

void Rendering::VertexBuffer::SetTriangleBinormal(const VertexBufferAccessor& vertexBufferAccessor, int index, const AVector& binormal)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

    const auto numVertices = vertexBufferAccessor.GetNumVertices();

    if (0 <= index && index < numVertices)
    {
        const auto excursion = vertexBufferAccessor.GetBinormalExcursion(index);
        auto data = GetAccessWriteData(excursion);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

        auto firstBinormal = reinterpret_cast<float*>(data);
        auto secondBinormal = firstBinormal + 1;
        auto thirdBinormal = secondBinormal + 1;

#include STSTEM_WARNING_POP

        *firstBinormal = binormal[0];
        *secondBinormal = binormal[1];
        *thirdBinormal = binormal[2];
    }
}

void Rendering::VertexBuffer::ClearTangent(const VertexBufferAccessor& vertexBufferAccessor)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

    const auto numVertices = vertexBufferAccessor.GetNumVertices();

    for (auto index = 0; index < numVertices; ++index)
    {
        const auto excursion = vertexBufferAccessor.GetTangentExcursion(index);
        auto data = GetAccessWriteData(excursion);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

        auto firstTangent = reinterpret_cast<float*>(data);
        auto secondTangent = firstTangent + 1;
        auto thirdTangent = secondTangent + 1;

#include STSTEM_WARNING_POP

        *firstTangent = 0.0f;
        *secondTangent = 0.0f;
        *thirdTangent = 0.0f;
    }
}

void Rendering::VertexBuffer::ClearBinormal(const VertexBufferAccessor& vertexBufferAccessor)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

    const auto numVertices = vertexBufferAccessor.GetNumVertices();

    for (auto index = 0; index < numVertices; ++index)
    {
        const auto excursion = vertexBufferAccessor.GetBinormalExcursion(index);
        auto data = GetAccessWriteData(excursion);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

        auto firstBinormal = reinterpret_cast<float*>(data);
        auto secondBinormal = firstBinormal + 1;
        auto thirdBinormal = secondBinormal + 1;

#include STSTEM_WARNING_POP

        *firstBinormal = 0.0f;
        *secondBinormal = 0.0f;
        *thirdBinormal = 0.0f;
    }
}

void Rendering::VertexBuffer::SetTextureCoordStandard(const VertexBufferAccessor& vertexBufferAccessor)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

    const auto numVertices = vertexBufferAccessor.GetNumVertices();

    for (auto index = 0; index < numVertices; ++index)
    {
        const auto excursion = vertexBufferAccessor.GetTextureCoordExcursion(0, index);
        auto data = GetAccessWriteData(excursion);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

        auto firstTextureCoord = reinterpret_cast<float*>(data);
        auto secondTextureCoord = firstTextureCoord + 1;

#include STSTEM_WARNING_POP

        if (index % 4 == 0 || index % 4 == 3)
        {
            *firstTextureCoord = 0.0f;
        }
        else
        {
            *firstTextureCoord = 1.0f;
        }

        if (index % 4 == 0 || index % 4 == 1)
        {
            *secondTextureCoord = 0.0f;
        }
        else
        {
            *secondTextureCoord = 1.0f;
        }
    }
}

void Rendering::VertexBuffer::SetPosition(const VertexBufferAccessor& vertexBufferAccessor, int index, const APoint& position)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

    const auto numVertices = vertexBufferAccessor.GetNumVertices();

    if (0 <= index && index < numVertices)
    {
        const auto excursion = vertexBufferAccessor.GetPositionExcursion(index);
        auto data = GetAccessWriteData(excursion);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

        auto firstPosition = reinterpret_cast<float*>(data);
        auto secondPosition = firstPosition + 1;
        auto thirdPosition = secondPosition + 1;

#include STSTEM_WARNING_POP

        *firstPosition = position[0];
        *secondPosition = position[1];
        *thirdPosition = position[2];
    }
}

void Rendering::VertexBuffer::SetTextureCoord(const VertexBufferAccessor& vertexBufferAccessor, int index, const Vector2F& textureCoord, int unit)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

    const auto numVertices = vertexBufferAccessor.GetNumVertices();

    if (0 <= index && index < numVertices)
    {
        const auto excursion = vertexBufferAccessor.GetTextureCoordExcursion(unit, index);
        auto data = GetAccessWriteData(excursion);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

        auto firstTextureCoord = reinterpret_cast<float*>(data);
        auto secondTextureCoord = firstTextureCoord + 1;

#include STSTEM_WARNING_POP

        *firstTextureCoord = textureCoord[0];
        *secondTextureCoord = textureCoord[1];
    }
}

void Rendering::VertexBuffer::SetTriangleNormal(const VertexBufferAccessor& vertexBufferAccessor, int index, const AVector& normal)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

    const auto numVertices = vertexBufferAccessor.GetNumVertices();

    if (0 <= index && index < numVertices)
    {
        const auto excursion = vertexBufferAccessor.GetNormalExcursion(index);
        auto data = GetAccessWriteData(excursion);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

        auto firstNormal = reinterpret_cast<float*>(data);
        auto secondNormal = firstNormal + 1;
        auto thirdNormal = secondNormal + 1;

#include STSTEM_WARNING_POP

        *firstNormal = normal[0];
        *secondNormal = normal[1];
        *thirdNormal = normal[2];
    }
}

Rendering::VertexBufferSharedPtr Rendering::VertexBuffer::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::VertexBuffer::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
