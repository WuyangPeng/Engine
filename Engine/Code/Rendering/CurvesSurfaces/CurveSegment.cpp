// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/25 16:42)

#include "Rendering/RenderingExport.h"

#include "CurveSegment.h"
#include "System/Helper/PragmaWarning.h"

#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Base/MathDetail.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26496)
CORE_TOOLS_RTTI_DEFINE(Rendering, CurveSegment);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, CurveSegment);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, CurveSegment);

Rendering::CurveSegment::CurveSegment(float umin, float umax)
    : mUMin(umin), mUMax(umax), ParentType("CurveSegment")
{
}

float Rendering::CurveSegment::GetUMin() const noexcept
{
    return mUMin;
}

float Rendering::CurveSegment::GetUMax() const noexcept
{
    return mUMax;
}

Mathematics::AVectorF Rendering::CurveSegment::Tangent(float u) const
{
    AVector velocity = PU(u);
    velocity.Normalize();
    return velocity;
}

Mathematics::AVectorF Rendering::CurveSegment::Normal(float u) const
{
    AVector velocity = PU(u);
    AVector acceleration = PUU(u);
    const float VDotV = Dot(velocity, velocity);
    const float VDotA = Dot(velocity, acceleration);
    AVector normal = VDotV * acceleration - VDotA * velocity;
    normal.Normalize();
    return normal;
}

Mathematics::AVectorF Rendering::CurveSegment::Binormal(float u) const
{
    AVector velocity = PU(u);
    AVector acceleration = PUU(u);
    const float VDotV = Dot(velocity, velocity);
    const float VDotA = Dot(velocity, acceleration);
    AVector normal = VDotV * acceleration - VDotA * velocity;
    normal.Normalize();
    velocity.Normalize();
    AVector binormal = Cross(velocity, normal);
    return binormal;
}

void Rendering::CurveSegment::GetFrame(float u, APoint& position, AVector& tangent, AVector& normal, AVector& binormal) const
{
    position = P(u);
    AVector velocity = PU(u);
    AVector acceleration = PUU(u);
    const float VDotV = Dot(velocity, velocity);
    const  float VDotA = Dot(velocity, acceleration);
    normal = VDotV * acceleration - VDotA * velocity;
    normal.Normalize();
    tangent = velocity;
    tangent.Normalize();
    binormal = Cross(tangent, normal);
}

float Rendering::CurveSegment::Curvature(float u) const
{
    AVector velocity = PU(u);
    const float speedSqr = velocity.SquaredLength();

    if (speedSqr >= Mathematics::MathF::GetZeroTolerance())
    {
        AVector acceleration = PUU(u);
        AVector cross = Cross(velocity, acceleration);
        const float numer = cross.Length();
        const float denom = Mathematics::MathF::Pow(speedSqr, 1.5f);
        return numer / denom;
    }
    else
    {
        // Curvature is indeterminate, just return 0.
        return 0.0f;
    }
}

float Rendering::CurveSegment::Torsion(float u) const
{
    AVector velocity = PU(u);
    AVector acceleration = PUU(u);
    AVector cross = Cross(velocity, acceleration);
    const float denom = cross.SquaredLength();

    if (denom >= Mathematics::MathF::GetZeroTolerance())
    {
        AVector jerk = PUUU(u);
        const float numer = Dot(cross, jerk);
        return numer / denom;
    }
    else
    {
        // Torsion is indeterminate, just return 0.
        return 0.0f;
    }
}

// Name support.

// Streaming support.

Rendering::CurveSegment::CurveSegment(LoadConstructor value)
    : Object(value), mUMin(0.0f), mUMax(0.0f)
{
}

void Rendering::CurveSegment::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    Object::Load(source);

    source.Read(mUMin);
    source.Read(mUMax);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::CurveSegment::Link(CoreTools::ObjectLink& source)
{
    Object::Link(source);
}

void Rendering::CurveSegment::PostLink()
{
    Object::PostLink();
}

uint64_t Rendering::CurveSegment::Register(CoreTools::ObjectRegister& target) const
{
    return Object::Register(target);
}

void Rendering::CurveSegment::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    Object::Save(target);

    target.Write(mUMin);
    target.Write(mUMax);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::CurveSegment::GetStreamingSize() const
{
    int size = Object::GetStreamingSize();
    size += sizeof(mUMin);
    size += sizeof(mUMax);
    return size;
}

#include STSTEM_WARNING_POP