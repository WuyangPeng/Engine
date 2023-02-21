///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/06 16:32)

#include "Rendering/RenderingExport.h"

#include "SkinControllerImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Rendering/DataTypes/SpecializedIO.h"

using std::vector;

Rendering::SkinControllerImpl::SkinControllerImpl(int numVertices, int numBones)
    : numVertices{ numVertices },
      numBones{ numBones },
      size{ numVertices * numBones },
      bones(numBones),
      weights(size),
      offsets(size)
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SkinControllerImpl::SkinControllerImpl() noexcept
    : numVertices{ 0 },
      numBones{ 0 },
      size{ 0 },
      bones{},
      weights{},
      offsets{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::SkinControllerImpl::IsValid() const noexcept
{
    if (0 <= size && numBones * numVertices == size)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::SkinControllerImpl::GetNumVertices() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numVertices;
}

int Rendering::SkinControllerImpl::GetNumBones() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numBones;
}

Rendering::ConstNodeSharedPtr Rendering::SkinControllerImpl::GetBones(int bonesIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < numBones, "索引错误！");

    return bones.at(bonesIndex).object;
}

float Rendering::SkinControllerImpl::GetWeights(int bonesIndex, int verticesIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < numBones, "索引错误！");
    RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < numVertices, "索引错误！");

    const auto index = verticesIndex + bonesIndex * numVertices;

    RENDERING_ASSERTION_0(0 <= index && index < size, "索引错误！");

    return weights.at(index);
}

Rendering::SkinControllerImpl::APoint Rendering::SkinControllerImpl::GetOffsets(int bonesIndex, int verticesIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < numBones, "索引错误！");
    RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < numVertices, "索引错误！");

    const auto index = verticesIndex + bonesIndex * numVertices;

    RENDERING_ASSERTION_0(0 <= index && index < size, "索引错误！");

    return offsets.at(index);
}

void Rendering::SkinControllerImpl::SetBones(int bonesIndex, const ConstNodeSharedPtr& node)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < numBones, "索引错误！");

    bones.at(bonesIndex).object = node;
}

void Rendering::SkinControllerImpl::SetBones(const std::vector<CoreTools::ConstObjectAssociated<Node>>& aBones)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_2(boost::numeric_cast<int>(aBones.size()) == numBones, "传入的骨骼大小错误");

    bones = aBones;
}

void Rendering::SkinControllerImpl::SetWeights(int bonesIndex, int verticesIndex, float weight)
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < numBones, "索引错误！");
    RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < numVertices, "索引错误！");

    const auto index = verticesIndex + bonesIndex * numVertices;

    RENDERING_ASSERTION_0(0 <= index && index < size, "索引错误！");

    weights.at(index) = weight;
}

void Rendering::SkinControllerImpl::SetWeights(int bonesIndex, const vector<float>& weight)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_2(boost::numeric_cast<int>(weight.size()) == numVertices, "传入的骨骼大小错误");

    const auto beginIndex = bonesIndex * numVertices;
    RENDERING_ASSERTION_0(0 <= beginIndex && beginIndex < size, "索引错误！");

    RENDERING_ASSERTION_0(0 <= beginIndex + numVertices - 1 && beginIndex + numVertices - 1 < size, "索引错误！");

    for (auto i = 0; i < numVertices; ++i)
    {
        const auto index = i + beginIndex;
        weights.at(index) = weight.at(i);
    }
}

void Rendering::SkinControllerImpl::SetOffsets(int bonesIndex, int verticesIndex, const APoint& offset)
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < numBones, "索引错误！");
    RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < numVertices, "索引错误！");

    const auto index = verticesIndex + bonesIndex * numVertices;

    RENDERING_ASSERTION_0(0 <= index && index < size, "索引错误！");

    offsets.at(index) = offset;
}

void Rendering::SkinControllerImpl::SetOffsets(int bonesIndex, const vector<APoint>& offset)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_2(boost::numeric_cast<int>(offset.size()) == numVertices, "传入的骨骼大小错误");

    const auto beginIndex = bonesIndex * numVertices;
    RENDERING_ASSERTION_0(0 <= beginIndex && beginIndex < size, "索引错误！");
    RENDERING_ASSERTION_0(0 <= beginIndex + numVertices - 1 && beginIndex + numVertices - 1 < size, "索引错误！");

    for (auto i = 0; i < numVertices; ++i)
    {
        const auto index = i + beginIndex;
        offsets.at(index) = offset.at(i);
    }
}

int Rendering::SkinControllerImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto result = CoreTools::GetStreamSize(numVertices);
    result += CoreTools::GetStreamSize(numBones);

    result += numBones * RENDERING_STREAM_SIZE(bones.at(0));
    result += size * MATHEMATICS_STREAM_SIZE(weights.at(0));
    result += size * CoreTools::GetStreamSize(offsets.at(0));

    return result;
}

void Rendering::SkinControllerImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(numVertices);
    target.Write(numBones);

    target.WriteObjectAssociatedContainerWithNumber(bones);
    target.WriteContainerWithNumber(weights);
    target.WriteAggregateContainerWithNumber(offsets);
}

void Rendering::SkinControllerImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.Read(numVertices);
    source.Read(numBones);
    size = numVertices * numBones;
    bones.resize(numBones);
    weights.resize(size);
    offsets.resize(size);

    source.ReadObjectAssociatedContainer(numBones, bones);
    weights = source.ReadVectorWithNumber<float>(size);
    source.ReadAggregateContainer(size, offsets);
}

void Rendering::SkinControllerImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ResolveLinkContainer(bones);
}

void Rendering::SkinControllerImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.RegisterContainer(bones);
}
