///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/10 16:27)

#include "Rendering/RenderingExport.h"

#include "DlodNodeImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/DataTypes/Transform.h"

#include <gsl/util>

Rendering::DlodNodeImpl::DlodNodeImpl() noexcept
    : modelLodCenter{}, worldLodCenter{}, numLevelsOfDetail{ 0 }, modelMinDistance{}, modelMaxDistance{}, worldMinDistance{}, worldMaxDistance{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::DlodNodeImpl::DlodNodeImpl(int numLevelsOfDetail)
    : modelLodCenter{},
      worldLodCenter{},
      numLevelsOfDetail{ numLevelsOfDetail },
      modelMinDistance(numLevelsOfDetail),
      modelMaxDistance(numLevelsOfDetail),
      worldMinDistance(numLevelsOfDetail),
      worldMaxDistance(numLevelsOfDetail)
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::DlodNodeImpl::IsValid() const noexcept
{
    if (gsl::narrow_cast<size_t>(numLevelsOfDetail) == modelMinDistance.size() &&
        modelMinDistance.size() == modelMaxDistance.size() &&
        worldMinDistance.size() == worldMaxDistance.size() &&
        modelMinDistance.size() == worldMaxDistance.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::DlodNodeImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadAggregate(modelLodCenter);
    source.ReadAggregate(worldLodCenter);
    source.Read(numLevelsOfDetail);
    source.ReadContainer(modelMinDistance);
    source.ReadContainer(modelMaxDistance);
    source.ReadContainer(worldMinDistance);
    source.ReadContainer(worldMaxDistance);
}

void Rendering::DlodNodeImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteAggregate(modelLodCenter);
    target.WriteAggregate(worldLodCenter);
    target.Write(numLevelsOfDetail);
    target.WriteContainerWithNumber(modelMinDistance);
    target.WriteContainerWithNumber(modelMaxDistance);
    target.WriteContainerWithNumber(worldMinDistance);
    target.WriteContainerWithNumber(worldMaxDistance);
}

int Rendering::DlodNodeImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CoreTools::GetStreamSize(modelLodCenter);

    size += CoreTools::GetStreamSize(worldLodCenter);
    size += CoreTools::GetStreamSize(numLevelsOfDetail);
    size += CoreTools::GetStreamSize(modelMinDistance);
    size += CoreTools::GetStreamSize(modelMaxDistance);
    size += CoreTools::GetStreamSize(worldMinDistance);
    size += CoreTools::GetStreamSize(worldMaxDistance);

    return size;
}

Rendering::DlodNodeImpl::APoint Rendering::DlodNodeImpl::GetModelCenter() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return modelLodCenter;
}

Rendering::DlodNodeImpl::APoint Rendering::DlodNodeImpl::GetWorldCenter() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return worldLodCenter;
}

void Rendering::DlodNodeImpl::SetModelCenter(const APoint& modelCenter) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    modelLodCenter = modelCenter;
}

int Rendering::DlodNodeImpl::GetNumLevelsOfDetail() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numLevelsOfDetail;
}

float Rendering::DlodNodeImpl::GetModelMinDistance(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numLevelsOfDetail, "索引越界");

    return modelMinDistance.at(index);
}

float Rendering::DlodNodeImpl::GetModelMaxDistance(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numLevelsOfDetail, "索引越界");

    return modelMaxDistance.at(index);
}

float Rendering::DlodNodeImpl::GetWorldMinDistance(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numLevelsOfDetail, "索引越界");

    return worldMinDistance.at(index);
}

float Rendering::DlodNodeImpl::GetWorldMaxDistance(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numLevelsOfDetail, "索引越界");

    return worldMaxDistance.at(index);
}

void Rendering::DlodNodeImpl::SetModelDistance(int index, float minDistance, float maxDistance)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < numLevelsOfDetail, "索引越界");

    modelMinDistance.at(index) = minDistance;
    modelMaxDistance.at(index) = maxDistance;
    worldMinDistance.at(index) = minDistance;
    worldMaxDistance.at(index) = minDistance;
}

void Rendering::DlodNodeImpl::SetWorldCenter(const TransformF& transform) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    worldLodCenter = transform * modelLodCenter;
}

void Rendering::DlodNodeImpl::SetWorldDistance(float uniformScale) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    for (auto i = 0; i < numLevelsOfDetail; ++i)
    {
        worldMinDistance.at(i) = uniformScale * modelMinDistance.at(i);
        worldMaxDistance.at(i) = uniformScale * modelMaxDistance.at(i);
    }
}
