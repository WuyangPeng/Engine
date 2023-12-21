///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	°æ±¾£º0.9.1.2 (2023/07/24 19:34)

#include "Rendering/RenderingExport.h"

#include "MorphControllerImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::MorphControllerImpl::MorphControllerImpl(int numVertices, int numTargets, int numKeys, const BaseRendererSharedPtr& baseRenderer)
    : numVertices{ numVertices },
      numTargets{ numTargets },
      vertices(numVertices * boost::numeric_cast<size_t>(numTargets)),
      numKeys{ numKeys },
      times(numKeys),
      weights((boost::numeric_cast<size_t>(numTargets) - 1) * numKeys),
      lastIndex{ 0 },
      baseRenderer{ baseRenderer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::MorphControllerImpl::MorphControllerImpl() noexcept
    : numVertices{ 0 },
      numTargets{ 0 },
      vertices{},
      numKeys{ 0 },
      times{},
      weights{},
      lastIndex{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::MorphControllerImpl::IsValid() const noexcept
{
    if (0 <= numVertices && 0 <= numTargets && 0 <= numKeys)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::MorphControllerImpl::GetNumVertices() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numVertices;
}

int Rendering::MorphControllerImpl::GetNumTargets() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numTargets;
}

int Rendering::MorphControllerImpl::GetNumKeys() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numKeys;
}

Rendering::MorphControllerImpl::APoint Rendering::MorphControllerImpl::GetVertices(int target, int aVertices) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= target && target < numTargets, "Ë÷Òý´íÎó£¡");
    RENDERING_ASSERTION_0(0 <= aVertices && aVertices < numVertices, "Ë÷Òý´íÎó£¡");

    const int index = aVertices + target * numVertices;

    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(vertices.size()), "Ë÷Òý´íÎó£¡");

    return vertices.at(index);
}

float Rendering::MorphControllerImpl::GetTimes(int key) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= key && key < numKeys, "Ë÷Òý´íÎó£¡");

    return times.at(key);
}

float Rendering::MorphControllerImpl::GetWeights(int key, int target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= target && target < numTargets - 1, "Ë÷Òý´íÎó£¡");
    RENDERING_ASSERTION_0(0 <= key && key < numKeys, "Ë÷Òý´íÎó£¡");

    const auto index = target + key * (numTargets - 1);

    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(weights.size()), "Ë÷Òý´íÎó£¡");

    return weights.at(index);
}

void Rendering::MorphControllerImpl::SetVertices(int target, int aVertices, const APoint& point)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= target && target < numTargets, "Ë÷Òý´íÎó£¡");
    RENDERING_ASSERTION_0(0 <= aVertices && aVertices < numVertices, "Ë÷Òý´íÎó£¡");

    const auto index = aVertices + target * numVertices;

    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(vertices.size()), "Ë÷Òý´íÎó£¡");

    vertices.at(index) = point;
}

void Rendering::MorphControllerImpl::SetTimes(int key, float time)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= key && key < numKeys, "Ë÷Òý´íÎó£¡");

    times.at(key) = time;
}

void Rendering::MorphControllerImpl::SetWeights(int key, int target, float weight)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= target && target < numTargets - 1, "Ë÷Òý´íÎó£¡");
    RENDERING_ASSERTION_0(0 <= key && key < numKeys, "Ë÷Òý´íÎó£¡");

    const auto index = target + key * (numTargets - 1);

    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(weights.size()), "Ë÷Òý´íÎó£¡");

    weights.at(index) = weight;
}

Rendering::ControllerKeyInfo Rendering::MorphControllerImpl::GetKeyInfo(float ctrlTime) noexcept
{
    if (ctrlTime <= times.at(0))
    {
        lastIndex = 0;

        return ControllerKeyInfo{};
    }

    if (const auto index = numKeys - 1;
        times.at(index) <= ctrlTime)
    {
        lastIndex = numKeys - 1;

        return ControllerKeyInfo{ 0.0f, lastIndex, lastIndex };
    }

    if (times.at(lastIndex) < ctrlTime)
    {
        auto nextIndex = lastIndex + 1;
        while (times.at(nextIndex) <= ctrlTime)
        {
            lastIndex = nextIndex;
            ++nextIndex;
        }

        const auto normTime = (ctrlTime - times.at(lastIndex)) / (times.at(nextIndex) - times.at(lastIndex));

        return ControllerKeyInfo{ normTime, lastIndex, nextIndex };
    }
    else if (ctrlTime < times.at(lastIndex))
    {
        auto nextIndex = lastIndex - 1;
        while (ctrlTime <= times.at(nextIndex))
        {
            lastIndex = nextIndex;
            --nextIndex;
        }

        const auto normTime = (ctrlTime - times.at(nextIndex)) / (times.at(lastIndex) - times.at(nextIndex));

        return ControllerKeyInfo{ normTime, nextIndex, lastIndex };
    }
    else
    {
        return ControllerKeyInfo{ 0.0f, lastIndex, lastIndex };
    }
}

int Rendering::MorphControllerImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CoreTools::GetStreamSize(numVertices);

    size += CoreTools::GetStreamSize(numTargets);
    size += CoreTools::GetStreamSize(numKeys);
    size += boost::numeric_cast<int>(vertices.size() * Mathematics::GetStreamSize(vertices.at(0)));
    size += numKeys * CoreTools::GetStreamSize(times.at(0));
    size += boost::numeric_cast<int>(weights.size() * CoreTools::GetStreamSize(weights.at(0)));

    return size;
}

void Rendering::MorphControllerImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(numVertices);
    target.Write(numTargets);
    target.Write(numKeys);

    target.WriteAggregateContainerWithoutNumber(vertices);
    target.WriteContainerWithoutNumber(times);
    target.WriteContainerWithoutNumber(weights);
}

void Rendering::MorphControllerImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.Read(numVertices);
    source.Read(numTargets);
    source.Read(numKeys);

    const auto numTotalVertices = numVertices * numTargets;
    vertices.resize(numTotalVertices);
    source.ReadAggregateContainer(numTotalVertices, vertices);

    times.resize(numKeys);
    source.ReadContainer(numKeys, times);

    const auto numTotalWeights = numKeys * (numTargets - 1);
    weights.resize(numTotalWeights);
    source.ReadContainer(numTotalWeights, weights);
}

void Rendering::MorphControllerImpl::SetControllerObject(Visual& visual)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto vertexBuffer = visual.GetVertexBuffer();
    if (vertexBuffer->GetNumElements() != numVertices)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Mismatch in number of vertices."))
    }

    const auto vertexFormat = vertexBuffer->GetFormat();
    const auto index = vertexFormat.GetIndex(VertexFormatFlags::Semantic::Position, 0);
    if (index < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Vertex format does not have VertexFormatFlags::Semantic::Position."))
    }

    if (const auto type = vertexFormat.GetAttributeType(index);
        type != DataFormatType::R32G32B32A32Float && type != DataFormatType::R32G32B32Float)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Invalid position type."))
    }

    if (const auto offset = vertexFormat.GetOffset(index);
        offset != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Position offset must be 0."))
    }
}

bool Rendering::MorphControllerImpl::Update(double controlTime, Visual& visual)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto vertexBuffer = visual.GetVertexBuffer();
    const auto vertexFormat = vertexBuffer->GetFormat();

    const auto count = vertexBuffer->GetNumElements();
    auto combination = vertexBuffer->GetStorage();
    const auto vertexSize = vertexFormat.GetVertexSize();
    for (auto i = 0; i < count; ++i)
    {
        combination.Increase(0.0f);
        combination.Increase(0.0f);
        combination.Increase(0.0f);

        if (vertexSize > CoreTools::GetStreamSize<float>() * 3)
        {
            combination += (vertexSize - CoreTools::GetStreamSize<float>() * 3);
        }
    }

    const auto controllerKeyInfo = GetKeyInfo(boost::numeric_cast<float>(controlTime));
    const auto oneMinusNormTime = 1.0f - controllerKeyInfo.GetNormTime();

    for (auto n = 0; n < numTargets; ++n)
    {
        const auto index0 = controllerKeyInfo.GetFirstIndex() * numTargets + n;
        const auto index1 = controllerKeyInfo.GetSecondIndex() * numTargets + n;
        const auto w = oneMinusNormTime * weights.at(index0) + controllerKeyInfo.GetNormTime() * weights.at(index1);
        combination = vertexBuffer->GetStorage();
        for (auto m = 0; m < numVertices; ++m)
        {
            const auto x = combination.Increase<float>();
            const auto y = combination.Increase<float>();
            const auto z = combination.Increase<float>();

            auto position = w * Mathematics::Vector3{ x, y, z };

            combination -= CoreTools::GetStreamSize<float>() * 3;
            combination.Increase(position.GetX());
            combination.Increase(position.GetY());
            combination.Increase(position.GetZ());

            if (vertexSize > CoreTools::GetStreamSize<float>() * 3)
            {
                combination += (vertexSize - CoreTools::GetStreamSize<float>() * 3);
            }
        }
    }

    visual.UpdateModelBound();
    visual.UpdateModelNormals();

    return baseRenderer.lock()->Update(vertexBuffer);
}
