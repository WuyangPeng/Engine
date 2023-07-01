///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:00)

#include "Rendering/RenderingExport.h"

#include "TubeSurface.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/CurvesSurfacesVolumes/Curve3Detail.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TubeSurface);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TubeSurface);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TubeSurface);

CLASS_INVARIANT_STUB_DEFINE(Rendering, TubeSurface)

Rendering::TubeSurface::TubeSurface(const std::shared_ptr<Mathematics::Curve3<float>>& medial,
                                    RadialFunction radial,
                                    bool closed,
                                    const Mathematics::Vector3F& upVector,
                                    int numMedialSamples,
                                    int numSliceSamples,
                                    bool sampleByArcLength,
                                    bool insideView,
                                    const Mathematics::Float2& tcoordMin,
                                    const Mathematics::Float2& tcoordMax,
                                    VertexFormatSharedPtr vformat)
    : ParentType{ vformat, nullptr, nullptr },
      medial{ medial },
      radial{ radial },
      numMedialSamples{ numMedialSamples },
      numSliceSamples{ numSliceSamples },
      upVector{ upVector },
      sin{},
      cos{},
      closed{ closed },
      sampleByArcLength{ sampleByArcLength }
{
    auto numVertices = 0;
    if (closed)
    {
        numVertices = (numSliceSamples + 1) * (numMedialSamples + 1);
    }
    else
    {
        numVertices = (numSliceSamples + 1) * numMedialSamples;
    }

    SetVertexFormat(vformat);
    const auto vstride = vformat->GetStride();
    SetVertexBuffer(VertexBuffer::Create(*vformat, vstride));

    ComputeSinCos();
    ComputeVertices();

    if (GetVertexFormat()->GetIndex(VertexFormatFlags::Semantic::Normal) >= 0)
    {
        ComputeNormals();
    }

    ComputeUVs(tcoordMin, tcoordMax);

    ComputeIndices(insideView);

    UpdateModelSpace(VisualUpdateType::Normals);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::TubeSurface::ComputeSinCos()
{
    RENDERING_CLASS_IS_VALID_1;

    const auto size = numSliceSamples + 1;
    sin.resize(size);
    cos.resize(size);

    const auto invSliceSamples = 1.0f / boost::numeric_cast<float>(numSliceSamples);
    for (auto i = 0; i < numSliceSamples; ++i)
    {
        const auto angle = Mathematics::MathF::GetTwoPI() * invSliceSamples * i;
        cos.at(i) = Mathematics::MathF::Cos(angle);
        sin.at(i) = Mathematics::MathF::Sin(angle);
    }
    sin.at(numSliceSamples) = sin.at(0);
    cos.at(numSliceSamples) = cos.at(0);
}

void Rendering::TubeSurface::ComputeVertices()
{
    RENDERING_CLASS_IS_VALID_1;

    const auto tMin = medial->GetMinTime();
    const auto tRange = medial->GetMaxTime() - tMin;

    auto totalLength = 0.0f;
    if (sampleByArcLength)
    {
        totalLength = medial->GetTotalLength();
    }
    else
    {
        totalLength = 0.0f;
    }

    auto denom = 0.0f;
    if (closed)
    {
        denom = 1.0f / boost::numeric_cast<float>(numMedialSamples);
    }
    else
    {
        denom = 1.0f / boost::numeric_cast<float>(numMedialSamples - 1);
    }

    for (auto m = 0, v = 0; m < numMedialSamples; ++m, ++v)
    {
        auto t = 0.0f;
        if (sampleByArcLength)
        {
            t = medial->GetTime(m * totalLength * denom);
        }
        else
        {
            t = tMin + m * tRange * denom;
        }

        const auto radius = radial(t);

        Mathematics::Vector3F position{};
        Mathematics::Vector3F tangent{};
        Mathematics::Vector3F normal{};
        Mathematics::Vector3F binormal{};
        if (upVector != Mathematics::Vector3F::GetZero())
        {
            position = medial->GetPosition(t);
            tangent = medial->GetTangent(t);
            binormal = Mathematics::Vector3ToolsF::UnitCrossProduct(tangent, upVector);
            normal = Mathematics::Vector3ToolsF::UnitCrossProduct(binormal, tangent);
        }
        else
        {
            medial->GetFrame(t, position, tangent, normal, binormal);
        }
    }

    if (closed)
    {
        for (auto i = 0; i <= numSliceSamples; ++i)
        {
            MAYBE_UNUSED const auto i1 = Index(i, numMedialSamples);
            MAYBE_UNUSED const auto i0 = Index(i, 0);
        }
    }
}

void Rendering::TubeSurface::ComputeNormals() noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::TubeSurface::ComputeUVs(const Mathematics::Float2& tcoordMin, const Mathematics::Float2& tcoordMax)
{
    RENDERING_CLASS_IS_VALID_1;

    Mathematics::Float2 tcoordRange{ tcoordMax[0] - tcoordMin[0], tcoordMax[1] - tcoordMin[1] };
    const auto mMax = (closed ? numMedialSamples : numMedialSamples - 1);
    for (auto m = 0, v = 0; m <= mMax; m++)
    {
        const auto mRatio = Mathematics::MathF::GetValue(m) / Mathematics::MathF::GetValue(mMax);
        const auto mValue = tcoordMin[1] + mRatio * tcoordRange[1];
        for (auto s = 0; s <= numSliceSamples; ++s, ++v)
        {
            const auto sRatio = Mathematics::MathF::GetValue(s) / Mathematics::MathF::GetValue(numSliceSamples);
            const auto sValue = tcoordMin[0] + sRatio * tcoordRange[0];
            const Mathematics::Float2 tcoord{ sValue, mValue };
            constexpr auto numTCoords = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::TextureCoordinateUnits);
            for (auto unit = 0; unit < numTCoords; ++unit)
            {
            }
        }
    }
}

void Rendering::TubeSurface::ComputeIndices(bool insideView)
{
    RENDERING_CLASS_IS_VALID_1;

    auto numTriangles = 0;
    if (closed)
    {
        numTriangles = 2 * numSliceSamples * numMedialSamples;
    }
    else
    {
        numTriangles = 2 * numSliceSamples * (numMedialSamples - 1);
    }

    SetIndexBuffer(IndexBuffer::Create(IndexFormatType::PolyPoint, 3 * numTriangles, sizeof(int)));

    auto indices = GetIndexBuffer()->GetData();
    auto start = 0;
    for (auto m = 0; m < numMedialSamples - 1; ++m)
    {
        auto i0 = start;
        auto i1 = i0 + 1;
        start += numSliceSamples + 1;
        auto i2 = start;
        auto i3 = i2 + 1;
        for (auto i = 0; i < numSliceSamples; ++i, indices += 6)
        {
            if (insideView)
            {
                indices.Increase<int32_t>(i0++);
                indices.Increase<int32_t>(i2);
                indices.Increase<int32_t>(i1);
                indices.Increase<int32_t>(i1++);
                indices.Increase<int32_t>(i2++);
                indices.Increase<int32_t>(i3++);
            }
            else
            {
                indices.Increase<int32_t>(i0++);
                indices.Increase<int32_t>(i1);
                indices.Increase<int32_t>(i2);
                indices.Increase<int32_t>(i1++);
                indices.Increase<int32_t>(i3++);
                indices.Increase<int32_t>(i2++);
            }
        }
    }

    if (closed)
    {
        auto i0 = start;
        auto i1 = i0 + 1;
        auto i2 = 0;
        auto i3 = i2 + 1;
        for (auto i = 0; i < numSliceSamples; ++i, indices += 6)
        {
            if (insideView)
            {
                indices.Increase<int32_t>(i0++);
                indices.Increase<int32_t>(i2);
                indices.Increase<int32_t>(i1);
                indices.Increase<int32_t>(i1++);
                indices.Increase<int32_t>(i2++);
                indices.Increase<int32_t>(i3++);
            }
            else
            {
                indices.Increase<int32_t>(i0++);
                indices.Increase<int32_t>(i1);
                indices.Increase<int32_t>(i2);
                indices.Increase<int32_t>(i1++);
                indices.Increase<int32_t>(i3++);
                indices.Increase<int32_t>(i2++);
            }
        }
    }
}

std::vector<Mathematics::Vector3F> Rendering::TubeSurface::GetTMinSlice() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    std::vector<Mathematics::Vector3F> slice{};

    for (auto i = 0; i <= numSliceSamples; ++i)
    {
    }
    return slice;
}

std::vector<Mathematics::Vector3F> Rendering::TubeSurface::GetTMaxSlice() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    std::vector<Mathematics::Vector3F> slice{};

    auto j = GetVertexBuffer()->GetNumElements() - numSliceSamples - 1;
    for (auto i = 0; i <= numSliceSamples; ++i, ++j)
    {
    }
    return slice;
}

void Rendering::TubeSurface::UpdateSurface()
{
    RENDERING_CLASS_IS_VALID_1;

    ComputeVertices();
    UpdateModelSpace(VisualUpdateType::ModelBoundOnly);

    if (GetVertexFormat()->GetIndex(VertexFormatFlags::Semantic::Normal) >= 0)
    {
        ComputeNormals();
    }

}

Rendering::TubeSurface::TubeSurface(LoadConstructor value)
    : ParentType{ value },
      medial{},
      radial{},
      numMedialSamples{},
      numSliceSamples{},
      upVector{},
      sin{},
      cos{},
      closed{ false },
      sampleByArcLength{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::TubeSurface::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(numMedialSamples);
    source.Read(numSliceSamples);
    source.ReadAggregate(upVector);
    sin = source.ReadContainerUseNumber<std::vector<float>>(numSliceSamples + 1);
    cos = source.ReadContainerUseNumber<std::vector<float>>(numSliceSamples + 1);

    closed = source.ReadBool();
    sampleByArcLength = source.ReadBool();

    medial = nullptr;
    radial = nullptr;

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::TubeSurface::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::TubeSurface::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

int64_t Rendering::TubeSurface::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::TubeSurface::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(numMedialSamples);
    target.Write(numSliceSamples);
    target.WriteAggregate(upVector);
    target.WriteContainerWithoutNumber(sin);
    target.WriteContainerWithoutNumber(cos);
    target.Write(closed);
    target.Write(sampleByArcLength);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::TubeSurface::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();
    size += CoreTools::GetStreamSize(numMedialSamples);
    size += CoreTools::GetStreamSize(numSliceSamples);
    size += CoreTools::GetStreamSize(upVector);
    size += CoreTools::GetStreamSize(sin);
    size += CoreTools::GetStreamSize(cos);
    size += CoreTools::GetStreamSize(closed);
    size += CoreTools::GetStreamSize(sampleByArcLength);
    return size;
}

void Rendering::TubeSurface::SetMedial(const std::shared_ptr<Mathematics::Curve3<float>>& aMedial) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    medial = aMedial;
}

std::shared_ptr<Mathematics::Curve3<float>> Rendering::TubeSurface::GetMedial() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return medial;
}

void Rendering::TubeSurface::SetRadial(RadialFunction aRadial) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    radial = aRadial;
}

Rendering::TubeSurface::RadialFunction Rendering::TubeSurface::GetRadial() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return radial;
}

void Rendering::TubeSurface::SetUpVector(const Mathematics::Vector3F& aUpVector) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    upVector = aUpVector;
}

const Mathematics::Vector3F& Rendering::TubeSurface::GetUpVector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return upVector;
}

int Rendering::TubeSurface::GetNumMedialSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numMedialSamples;
}

int Rendering::TubeSurface::GetNumSliceSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numSliceSamples;
}

int Rendering::TubeSurface::Index(int s, int m) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return s + (numSliceSamples + 1) * m;
}
