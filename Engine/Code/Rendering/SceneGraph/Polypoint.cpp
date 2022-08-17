///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 16:40)

#include "Rendering/RenderingExport.h"

#include "Polypoint.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, Polypoint);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Polypoint);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Polypoint);

Rendering::Polypoint::Polypoint(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer)
    : ParentType{ VisualPrimitiveType::Polypoint, vertexformat, vertexbuffer, IndexBufferSharedPtr() }, pointsCount{ vertexbuffer->GetNumElements() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::Polypoint::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= pointsCount)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::Polypoint::GetMaxNumPoints() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return GetConstVertexBuffer()->GetNumElements();
}

void Rendering::Polypoint::SetNumPoints(int numPoints) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    const auto numVertices = GetMaxNumPoints();
    if (0 <= numPoints && numPoints <= numVertices)
    {
        pointsCount = numPoints;
    }
    else
    {
        pointsCount = numVertices;
    }
}

int Rendering::Polypoint::GetNumPoints() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return pointsCount;
}

Rendering::Polypoint::Polypoint(LoadConstructor value)
    : ParentType{ value }, pointsCount{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Polypoint::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += CORE_TOOLS_STREAM_SIZE(pointsCount);

    return size;
}

int64_t Rendering::Polypoint::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::Polypoint::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(pointsCount);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Polypoint::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::Polypoint::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Polypoint::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(pointsCount);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::ControllerInterfaceSharedPtr Rendering::Polypoint::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Polypoint::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
