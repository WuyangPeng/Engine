///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	°æ±¾£º0.9.1.2 (2023/07/24 13:48)

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
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

Rendering::SkinControllerImpl::SkinControllerImpl(int numVertices, int numBones, const BaseRendererSharedPtr& baseRenderer)
    : numVertices{ numVertices },
      numBones{ numBones },
      size{ numVertices * numBones },
      bones(numBones),
      weights(size),
      offsets(size),
      baseRenderer{ baseRenderer },
      position{ -1 },
      stride{},
      firstUpdate{},
      canUpdate{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SkinControllerImpl::SkinControllerImpl() noexcept
    : numVertices{ 0 },
      numBones{ 0 },
      size{ 0 },
      bones{},
      weights{},
      offsets{},
      baseRenderer{},
      position{ -1 },
      stride{},
      firstUpdate{},
      canUpdate{}
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
    RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < numBones, "Ë÷Òý´íÎó£¡");

    return bones.at(bonesIndex).object.lock();
}

float Rendering::SkinControllerImpl::GetWeights(int bonesIndex, int verticesIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < numBones, "Ë÷Òý´íÎó£¡");
    RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < numVertices, "Ë÷Òý´íÎó£¡");

    const auto index = verticesIndex + bonesIndex * numVertices;

    RENDERING_ASSERTION_0(0 <= index && index < size, "Ë÷Òý´íÎó£¡");

    return weights.at(index);
}

Rendering::SkinControllerImpl::APoint Rendering::SkinControllerImpl::GetOffsets(int bonesIndex, int verticesIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < numBones, "Ë÷Òý´íÎó£¡");
    RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < numVertices, "Ë÷Òý´íÎó£¡");

    const auto index = verticesIndex + bonesIndex * numVertices;

    RENDERING_ASSERTION_0(0 <= index && index < size, "Ë÷Òý´íÎó£¡");

    return offsets.at(index);
}

void Rendering::SkinControllerImpl::SetBones(int bonesIndex, const ConstNodeSharedPtr& node)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < numBones, "Ë÷Òý´íÎó£¡");

    bones.at(bonesIndex).object = node;
}

void Rendering::SkinControllerImpl::SetBones(const ConstObjectAssociatedContainer& aBones)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_2(boost::numeric_cast<int>(aBones.size()) == numBones, "´«ÈëµÄ¹Ç÷À´óÐ¡´íÎó");

    bones.clear();
    for (const auto& element : aBones)
    {
        bones.emplace_back(element.object, element.associated);
    }
}

void Rendering::SkinControllerImpl::SetWeights(int bonesIndex, int verticesIndex, float weight)
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < numBones, "Ë÷Òý´íÎó£¡");
    RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < numVertices, "Ë÷Òý´íÎó£¡");

    const auto index = verticesIndex + bonesIndex * numVertices;

    RENDERING_ASSERTION_0(0 <= index && index < size, "Ë÷Òý´íÎó£¡");

    weights.at(index) = weight;
}

void Rendering::SkinControllerImpl::SetWeights(int bonesIndex, const std::vector<float>& weight)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_2(boost::numeric_cast<int>(weight.size()) == numVertices, "´«ÈëµÄ¹Ç÷À´óÐ¡´íÎó");

    const auto beginIndex = bonesIndex * numVertices;
    RENDERING_ASSERTION_0(0 <= beginIndex && beginIndex < size, "Ë÷Òý´íÎó£¡");

    RENDERING_ASSERTION_0(0 <= beginIndex + numVertices - 1 && beginIndex + numVertices - 1 < size, "Ë÷Òý´íÎó£¡");

    for (auto i = 0; i < numVertices; ++i)
    {
        const auto index = i + beginIndex;
        weights.at(index) = weight.at(i);
    }
}

void Rendering::SkinControllerImpl::SetOffsets(int bonesIndex, int verticesIndex, const APoint& offset)
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= bonesIndex && bonesIndex < numBones, "Ë÷Òý´íÎó£¡");
    RENDERING_ASSERTION_0(0 <= verticesIndex && verticesIndex < numVertices, "Ë÷Òý´íÎó£¡");

    const auto index = verticesIndex + bonesIndex * numVertices;

    RENDERING_ASSERTION_0(0 <= index && index < size, "Ë÷Òý´íÎó£¡");

    offsets.at(index) = offset;
}

void Rendering::SkinControllerImpl::SetOffsets(int bonesIndex, const std::vector<APoint>& offset)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_2(boost::numeric_cast<int>(offset.size()) == numVertices, "´«ÈëµÄ¹Ç÷À´óÐ¡´íÎó");

    const auto beginIndex = bonesIndex * numVertices;
    RENDERING_ASSERTION_0(0 <= beginIndex && beginIndex < size, "Ë÷Òý´íÎó£¡");
    RENDERING_ASSERTION_0(0 <= beginIndex + numVertices - 1 && beginIndex + numVertices - 1 < size, "Ë÷Òý´íÎó£¡");

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
    result += size * Mathematics::GetStreamSize(weights.at(0));
    result += size * CoreTools::GetStreamSize(offsets.at(0));

    return result;
}

void Rendering::SkinControllerImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(numVertices);
    target.Write(numBones);

    for (const auto& element : bones)
    {
        target.WriteWeakObjectAssociated(element);
    }

    target.WriteContainerWithNumber(weights);
    target.WriteAggregateContainerWithNumber(offsets);
}

void Rendering::SkinControllerImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.Read(numVertices);
    source.Read(numBones);
    size = numVertices * numBones;

    weights.resize(size);
    offsets.resize(size);

    std::vector<ConstObjectAssociated> objectAssociated{};
    source.ReadObjectAssociatedContainer(numBones, objectAssociated);
    for (const auto& element : objectAssociated)
    {
        bones.emplace_back(element.object, element.associated);
    }

    weights = source.ReadVectorUseNumber<float>(size);
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

    for (const auto& element : bones)
    {
        target.RegisterWeakPtr(element);
    }
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

bool Rendering::SkinControllerImpl::Update(const VisualSharedPtr& visual)
{
    RENDERING_CLASS_IS_VALID_1;

    if (firstUpdate)
    {
        firstUpdate = false;
        OnFirstUpdate(*visual);
    }

    if (canUpdate)
    {
        Mathematics::TransformF identity{};
        identity.MakeIdentity();
        visual->SetWorldTransform(identity);

        std::vector<Mathematics::Matrix<float>> worldTransforms(numBones);
        for (auto bone = 0; bone < numBones; ++bone)
        {
            worldTransforms.at(bone) = bones.at(bone).object.lock()->GetWorldTransform().GetMatrix();
        }

        auto current = position;

        const auto vertexBuffer = visual->GetVertexBuffer();

        for (auto vertex = 0; vertex < numVertices; ++vertex)
        {
            std::array<float, 3> currentPosition{};
            for (auto bone = 0; bone < numBones; ++bone)
            {
                if (const auto weight = weights.at(bone);
                    !Mathematics::MathF::Approximate(weight, 0.0f))
                {
                    const auto& worldTransform = worldTransforms.at(bone);
                    const auto& offset = offsets.at(bone);

                    currentPosition.at(0) += weight * (worldTransform.GetValue<0>() * offset[0] + worldTransform.GetValue<1>() * offset[1] + worldTransform.GetValue<2>() * offset[2] + worldTransform.GetValue<3>());
                    currentPosition.at(1) += weight * (worldTransform.GetValue<4>() * offset[0] + worldTransform.GetValue<5>() * offset[1] + worldTransform.GetValue<6>() * offset[2] + worldTransform.GetValue<7>());
                    currentPosition.at(2) += weight * (worldTransform.GetValue<8>() * offset[0] + worldTransform.GetValue<9>() * offset[1] + worldTransform.GetValue<10>() * offset[2] + worldTransform.GetValue<11>());
                }
            }

            auto target = vertexBuffer->GetStorage(current);
            target.Increase(currentPosition.at(0));
            target.Increase(currentPosition.at(1));
            target.Increase(currentPosition.at(2));

            current += stride;
        }

        visual->UpdateModelBound();
        visual->UpdateModelNormals();

        return baseRenderer.lock()->Update(visual->GetVertexBuffer());
    }

    return false;
}

#include SYSTEM_WARNING_POP

void Rendering::SkinControllerImpl::OnFirstUpdate(Visual& visual)
{
    if (const auto vertexBuffer = visual.GetVertexBuffer();
        numVertices == vertexBuffer->GetNumElements())
    {
        const auto vertexFormat = vertexBuffer->GetFormat();
        const auto numAttributes = vertexFormat.GetNumAttributes();
        for (auto i = 0; i < numAttributes; ++i)
        {
            const auto semantic = vertexFormat.GetSemantic(i);
            const auto type = vertexFormat.GetAttributeType(i);

            const auto offset = vertexFormat.GetOffset(i);

            if (semantic == VertexFormatFlags::Semantic::Position &&
                (type == DataFormatType::R32G32B32Float || type == DataFormatType::R32G32B32A32Float))
            {
                position = offset;
                stride = vertexFormat.GetVertexSize();
                canUpdate = true;
                break;
            }
        }
    }

    canUpdate = (position != -1);
}
