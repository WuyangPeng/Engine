///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 16:08)

#include "Rendering/RenderingExport.h"

#include "ParticlesImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Rendering/SceneGraph/Culler.h"

#include <gsl/util>

using std::vector;

Rendering::ParticlesImpl::ParticlesImpl(const std::vector<APoint>& positions, const std::vector<float>& sizes, float sizeAdjust)
    : positions{ positions }, sizes{ sizes }, sizeAdjust{ sizeAdjust }, numActive{ boost::numeric_cast<int>(positions.size()) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ParticlesImpl::ParticlesImpl() noexcept
    : positions{}, sizes{}, sizeAdjust{ 1.0f }, numActive{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::ParticlesImpl::IsValid() const noexcept
{
    if (0.0f < sizeAdjust && numActive <= gsl::narrow_cast<int>(positions.size()) && positions.size() == sizes.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::ParticlesImpl::GetNumParticles() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(positions.size());
}

Rendering::ParticlesImpl::APoint Rendering::ParticlesImpl::GetParticlesPosition(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(positions.size()), "索引越界！");

    return positions.at(index);
}

float Rendering::ParticlesImpl::GetSize(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(positions.size()), "索引越界！");

    return sizes.at(index);
}

void Rendering::ParticlesImpl::SetPosition(int index, const APoint& position)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(positions.size()), "索引越界！");

    positions.at(index) = position;
}

void Rendering::ParticlesImpl::SetSize(int index, float size)
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(positions.size()), "索引越界！");

    sizes.at(index) = size;
}

void Rendering::ParticlesImpl::SetSizeAdjust(float aSizeAdjust)
{
    RENDERING_CLASS_IS_VALID_1;

    if (0.0f < aSizeAdjust)
    {
        sizeAdjust = aSizeAdjust;
    }
    else
    {
        RENDERING_ASSERTION_0(false, "无效的大小调整参数。\n");
        sizeAdjust = 1.0f;
    }
}

float Rendering::ParticlesImpl::GetSizeAdjust() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return sizeAdjust;
}

void Rendering::ParticlesImpl::SetNumActive(int aNumActive)
{
    RENDERING_CLASS_IS_VALID_1;

    auto numParticles = boost::numeric_cast<int>(positions.size());
    if (0 <= aNumActive && aNumActive <= numParticles)
    {
        numActive = aNumActive;
    }
    else
    {
        numActive = numParticles;
    }
}

int Rendering::ParticlesImpl::GetNumActive() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numActive;
}

void Rendering::ParticlesImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    int32_t size{ 0 };
    source.Read(size);

    positions.resize(size);
    sizes.resize(size);

    source.ReadAggregateContainer(size, positions);
    sizes = source.ReadVectorWithNumber<float>(size);

    source.Read(sizeAdjust);
    source.Read(numActive);
}

void Rendering::ParticlesImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = boost::numeric_cast<uint32_t>(positions.size());

    target.Write(size);

    target.WriteAggregateContainerWithoutNumber(positions);
    target.WriteContainerWithNumber(sizes);

    target.Write(sizeAdjust);
    target.Write(numActive);
}

int Rendering::ParticlesImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CORE_TOOLS_STREAM_SIZE(int{});
    size += boost::numeric_cast<int>(MATHEMATICS_STREAM_SIZE(positions.at(0)) * positions.size());
    size += boost::numeric_cast<int>(CORE_TOOLS_STREAM_SIZE(sizes.at(0)) * sizes.size());
    size += CORE_TOOLS_STREAM_SIZE(sizeAdjust);
    size += CORE_TOOLS_STREAM_SIZE(numActive);

    return size;
}

float Rendering::ParticlesImpl::GetTrueSize(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return sizeAdjust * GetSize(index);
}
