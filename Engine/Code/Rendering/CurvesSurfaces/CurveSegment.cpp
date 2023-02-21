///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/16 17:47)

#include "Rendering/RenderingExport.h"

#include "CurveSegment.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Base/MathDetail.h"

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, CurveSegment)
CORE_TOOLS_RTTI_DEFINE(Rendering, CurveSegment);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, CurveSegment);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, CurveSegment);

Rendering::CurveSegment::CurveSegment(float umin, float umax)
    : ParentType{ "CurveSegment" }, uMin{ umin }, uMax{ umax }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

float Rendering::CurveSegment::GetUMin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return uMin;
}

float Rendering::CurveSegment::GetUMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return uMax;
}

Mathematics::AVectorF Rendering::CurveSegment::Tangent(float u) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto velocity = PU(u);
    velocity.Normalize();
    return velocity;
}

Mathematics::AVectorF Rendering::CurveSegment::Normal(float u) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto velocity = PU(u);
    const auto acceleration = PUU(u);
    const auto vDotV = Dot(velocity, velocity);
    const auto vDotA = Dot(velocity, acceleration);
    auto normal = vDotV * acceleration - vDotA * velocity;
    normal.Normalize();
    return normal;
}

Mathematics::AVectorF Rendering::CurveSegment::Binormal(float u) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto velocity = PU(u);
    const auto acceleration = PUU(u);
    const auto vDotV = Dot(velocity, velocity);
    const auto vDotA = Dot(velocity, acceleration);
    auto normal = vDotV * acceleration - vDotA * velocity;
    normal.Normalize();
    velocity.Normalize();
    auto binormal = Cross(velocity, normal);
    return binormal;
}

void Rendering::CurveSegment::GetFrame(float u, APoint& position, AVector& tangent, AVector& normal, AVector& binormal) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    position = P(u);
    auto velocity = PU(u);
    const auto acceleration = PUU(u);
    const auto vDotV = Dot(velocity, velocity);
    const auto vDotA = Dot(velocity, acceleration);
    normal = vDotV * acceleration - vDotA * velocity;
    normal.Normalize();
    tangent = velocity;
    tangent.Normalize();
    binormal = Cross(tangent, normal);
}

float Rendering::CurveSegment::Curvature(float u) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto velocity = PU(u);
    const auto speedSqr = velocity.SquaredLength();

    if (speedSqr >= Mathematics::MathF::GetZeroTolerance())
    {
        const auto acceleration = PUU(u);
        const auto cross = Cross(velocity, acceleration);
        const auto numer = cross.Length();
        const auto denom = Mathematics::MathF::Pow(speedSqr, 1.5f);
        return numer / denom;
    }
    else
    {
        return 0.0f;
    }
}

float Rendering::CurveSegment::Torsion(float u) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto velocity = PU(u);
    const auto acceleration = PUU(u);
    const auto cross = Cross(velocity, acceleration);
    const auto denom = cross.SquaredLength();

    if (denom >= Mathematics::MathF::GetZeroTolerance())
    {
        const auto jerk = PUUU(u);
        const auto numer = Dot(cross, jerk);
        return numer / denom;
    }
    else
    {
        return 0.0f;
    }
}

Rendering::CurveSegment::CurveSegment(LoadConstructor value)
    : ParentType{ value }, uMin{ 0.0f }, uMax{ 0.0f }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::CurveSegment::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(uMin);
    source.Read(uMax);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::CurveSegment::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::CurveSegment::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

int64_t Rendering::CurveSegment::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::CurveSegment::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(uMin);
    target.Write(uMax);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::CurveSegment::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();
    size += CoreTools::GetStreamSize(uMin);
    size += CoreTools::GetStreamSize(uMax);
    return size;
}
