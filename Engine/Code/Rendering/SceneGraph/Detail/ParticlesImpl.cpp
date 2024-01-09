/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:48)

#include "Rendering/RenderingExport.h"

#include "ParticlesImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"

#include <gsl/util>

Rendering::ParticlesImpl::ParticlesImpl(const Container& positionSize, float sizeAdjust)
    : positionSize{ positionSize }, sizeAdjust{ sizeAdjust }, numActive{ boost::numeric_cast<int>(positionSize.size()) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ParticlesImpl::ParticlesImpl() noexcept
    : positionSize{}, sizeAdjust{ 1.0f }, numActive{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::ParticlesImpl::IsValid() const noexcept
{
    if (0.0f < sizeAdjust && numActive <= gsl::narrow_cast<int>(positionSize.size()))
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

    return boost::numeric_cast<int>(positionSize.size());
}

Mathematics::Vector4F Rendering::ParticlesImpl::GetParticlesPosition(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return positionSize.at(index);
}

void Rendering::ParticlesImpl::SetPosition(int index, const Vector4& position)
{
    RENDERING_CLASS_IS_VALID_1;

    positionSize.at(index) = position;
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
        THROW_EXCEPTION(SYSTEM_TEXT("无效的大小调整参数。\n"))
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

    if (const auto numParticles = boost::numeric_cast<int>(positionSize.size());
        0 <= aNumActive && aNumActive <= numParticles)
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

void Rendering::ParticlesImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    positionSize = source.ReadAggregateContainerNotUseNumber<Container>();

    source.Read(sizeAdjust);
    source.Read(numActive);
}

void Rendering::ParticlesImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteAggregateContainerWithNumber(positionSize);

    target.Write(sizeAdjust);
    target.Write(numActive);
}

int Rendering::ParticlesImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = Mathematics::GetStreamSize(positionSize);

    size += CoreTools::GetStreamSize(sizeAdjust);
    size += CoreTools::GetStreamSize(numActive);

    return size;
}
