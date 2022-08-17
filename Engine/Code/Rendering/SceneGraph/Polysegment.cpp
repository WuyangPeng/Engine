///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 16:43)

#include "Rendering/RenderingExport.h"

#include "Polysegment.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, Polysegment);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Polysegment);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Polysegment);

Rendering::Polysegment::Polysegment(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, bool contiguous)
    : ParentType{ contiguous ? VisualPrimitiveType::PolysegmentsContiguous : VisualPrimitiveType::PolysegmentsDisjoint, vertexformat, vertexbuffer, IndexBufferSharedPtr{} },
      numSegments{ 0 }, contiguous{ contiguous }
{
    const auto numVertices = vertexbuffer->GetNumElements();
    RENDERING_ASSERTION_1(2 <= numVertices, "Polysegments必须至少有两点\n");

    if (contiguous)
    {
        numSegments = numVertices - 1;
    }
    else
    {
        RENDERING_ASSERTION_1((numVertices & 1) == 0, "分离片段需要偶数的顶点\n");

        numSegments = numVertices / 2;
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::Polysegment::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= numSegments)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::Polysegment::GetMaxNumSegments() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto numVertices = GetConstVertexBuffer()->GetNumElements();
    return contiguous ? numVertices - 1 : numVertices / 2;
}

void Rendering::Polysegment::SetNumSegments(int aNumSegments) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    auto numVertices = GetConstVertexBuffer()->GetNumElements();
    if (contiguous)
    {
        const auto numVerticesMinus1 = numVertices - 1;
        if (0 <= aNumSegments && aNumSegments <= numVerticesMinus1)
        {
            numSegments = aNumSegments;
        }
        else
        {
            numSegments = numVerticesMinus1;
        }
    }
    else
    {
        const auto numVerticesDivide2 = numVertices / 2;
        if (0 <= aNumSegments && aNumSegments <= numVerticesDivide2)
        {
            numSegments = aNumSegments;
        }
        else
        {
            numSegments = numVerticesDivide2;
        }
    }
}

int Rendering::Polysegment::GetNumSegments() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numSegments;
}

bool Rendering::Polysegment::GetContiguous() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return contiguous;
}

Rendering::ControllerInterfaceSharedPtr Rendering::Polysegment::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

Rendering::Polysegment::Polysegment(LoadConstructor value)
    : ParentType{ value }, numSegments{ 0 }, contiguous{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Polysegment::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += CORE_TOOLS_STREAM_SIZE(numSegments);
    size += CORE_TOOLS_STREAM_SIZE(contiguous);

    return size;
}

int64_t Rendering::Polysegment::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::Polysegment::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(numSegments);
    target.Write(contiguous);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Polysegment::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::Polysegment::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Polysegment::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(numSegments);
    contiguous = source.ReadBool();

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Polysegment::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
