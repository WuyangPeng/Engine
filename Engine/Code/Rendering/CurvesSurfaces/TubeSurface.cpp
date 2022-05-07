///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/18 15:36)

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
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessor.h"

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
    SetVertexBuffer(VertexBuffer::Create(numVertices, vstride));

    ComputeSinCos();
    ComputeVertices();

    if (GetVertexFormat()->GetIndex(VertexFormatFlags::AttributeUsage::Normal) >= 0)
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

    VertexBufferAccessor vba{ *this };

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

        auto save = vba.GetPosition<Mathematics::APointF>(v);
        for (auto i = 0; i < numSliceSamples; ++i, ++v)
        {
            GetVertexBuffer()->SetPosition(vba, v, Mathematics::APointF{ position + radius * (cos.at(i) * normal + sin.at(i) * binormal) });
        }
        GetVertexBuffer()->SetPosition(vba, v, save);
    }

    if (closed)
    {
        for (auto i = 0; i <= numSliceSamples; ++i)
        {
            const auto i1 = Index(i, numMedialSamples);
            const auto i0 = Index(i, 0);

            GetVertexBuffer()->SetPosition(vba, i1, vba.GetPosition<Mathematics::APointF>(i0));
        }
    }
}

void Rendering::TubeSurface::ComputeNormals()
{
    RENDERING_CLASS_IS_VALID_1;

    VertexBufferAccessor vba{ *this };

    for (auto m = 1; m <= numMedialSamples - 2; ++m)
    {
        for (auto s = 0; s < numSliceSamples; ++s)
        {
            const auto sM1 = (s > 0 ? s - 1 : numSliceSamples - 1);
            const auto sP1 = s + 1;
            const auto mM1 = m - 1;
            const auto mP1 = m + 1;

            auto dir0 = vba.GetPosition<Mathematics::AVectorF>(Index(sM1, m)) - vba.GetPosition<Mathematics::AVectorF>(Index(sP1, m));
            auto dir1 = vba.GetPosition<Mathematics::AVectorF>(Index(s, mM1)) - vba.GetPosition<Mathematics::AVectorF>(Index(s, mP1));

            GetVertexBuffer()->SetTriangleNormal(vba, Index(s, m), UnitCross(dir0, dir1));
        }
        GetVertexBuffer()->SetTriangleNormal(vba, Index(numSliceSamples, m), vba.GetNormal<Mathematics::AVectorF>(Index(0, m)));
    }

    if (closed)
    {
        for (auto s = 0; s < numSliceSamples; ++s)
        {
            const auto sM1 = (s > 0 ? s - 1 : numSliceSamples - 1);
            const auto sP1 = s + 1;

            auto dir0 = vba.GetPosition<Mathematics::AVectorF>(Index(sM1, 0)) - vba.GetPosition<Mathematics::AVectorF>(Index(sP1, 0));
            auto dir1 = vba.GetPosition<Mathematics::AVectorF>(Index(s, numMedialSamples - 1)) - vba.GetPosition<Mathematics::AVectorF>(Index(s, 1));
            GetVertexBuffer()->SetTriangleNormal(vba, s, UnitCross(dir0, dir1));

            GetVertexBuffer()->SetTriangleNormal(vba, Index(s, numMedialSamples), vba.GetNormal<Mathematics::AVectorF>(Index(s, 0)));
        }

        GetVertexBuffer()->SetTriangleNormal(vba, Index(numSliceSamples, 0), vba.GetNormal<Mathematics::AVectorF>(Index(0, 0)));
        GetVertexBuffer()->SetTriangleNormal(vba, Index(numSliceSamples, numMedialSamples), vba.GetNormal<Mathematics::AVectorF>(Index(0, numMedialSamples)));
    }
    else
    {
        for (auto s = 0; s < numSliceSamples; ++s)
        {
            const auto sM1 = (s > 0 ? s - 1 : numSliceSamples - 1);
            const auto sP1 = s + 1;

            auto dir0 = vba.GetPosition<Mathematics::AVectorF>(Index(sM1, 0)) - vba.GetPosition<Mathematics::AVectorF>(Index(sP1, 0));
            auto dir1 = vba.GetPosition<Mathematics::AVectorF>(Index(s, 0)) - vba.GetPosition<Mathematics::AVectorF>(Index(s, 1));
            GetVertexBuffer()->SetTriangleNormal(vba, Index(s, 0), UnitCross(dir0, dir1));
        }

        GetVertexBuffer()->SetTriangleNormal(vba, Index(numSliceSamples, 0), vba.GetNormal<Mathematics::AVectorF>(Index(0, 0)));

        for (auto s = 0; s < numSliceSamples; ++s)
        {
            const auto sM1 = (s > 0 ? s - 1 : numSliceSamples - 1);
            const auto sP1 = s + 1;

            auto dir0 = vba.GetPosition<Mathematics::AVectorF>(Index(sM1, numMedialSamples - 1)) - vba.GetPosition<Mathematics::AVectorF>(Index(sP1, numMedialSamples - 1));
            auto dir1 = vba.GetPosition<Mathematics::AVectorF>(Index(s, numMedialSamples - 2)) - vba.GetPosition<Mathematics::AVectorF>(Index(s, numMedialSamples - 1));
            GetVertexBuffer()->SetTriangleNormal(vba, s, UnitCross(dir0, dir1));
        }

        GetVertexBuffer()->SetTriangleNormal(vba, Index(numSliceSamples, numMedialSamples - 1), vba.GetNormal<Mathematics::AVectorF>(Index(0, numMedialSamples - 1)));
    }
}

void Rendering::TubeSurface::ComputeUVs(const Mathematics::Float2& tcoordMin, const Mathematics::Float2& tcoordMax)
{
    RENDERING_CLASS_IS_VALID_1;

    VertexBufferAccessor vba{ *this };

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
                if (vba.HasTextureCoord(unit))
                {
                    RENDERING_ASSERTION_0(vba.GetTextureCoordChannels(unit) == 2, "�������������2D\n");

                    GetVertexBuffer()->SetTextureCoord(vba, v, Mathematics::Vector2F{ tcoord[0], tcoord[1] }, unit);
                }
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

    SetIndexBuffer(IndexBuffer::Create(3 * numTriangles, sizeof(int)));

    auto indices = GetIndexBuffer()->GetWriteSpanIterator();
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

std::vector<Mathematics::Vector3F> Rendering::TubeSurface::GetTMinSlice()
{
    RENDERING_CLASS_IS_VALID_1;

    std::vector<Mathematics::Vector3F> slice{};
    VertexBufferAccessor vba{ *this };
    for (auto i = 0; i <= numSliceSamples; ++i)
    {
        slice.emplace_back(vba.GetPosition<Mathematics::Vector3F>(i));
    }
    return slice;
}

std::vector<Mathematics::Vector3F> Rendering::TubeSurface::GetTMaxSlice()
{
    RENDERING_CLASS_IS_VALID_1;

    std::vector<Mathematics::Vector3F> slice{};
    VertexBufferAccessor vba{ *this };
    auto j = GetVertexBuffer()->GetNumElements() - numSliceSamples - 1;
    for (auto i = 0; i <= numSliceSamples; ++i, ++j)
    {
        slice.emplace_back(vba.GetPosition<Mathematics::Vector3F>(j));
    }
    return slice;
}

void Rendering::TubeSurface::UpdateSurface()
{
    RENDERING_CLASS_IS_VALID_1;

    ComputeVertices();
    UpdateModelSpace(VisualUpdateType::ModelBoundOnly);

    if (GetVertexFormat()->GetIndex(VertexFormatFlags::AttributeUsage::Normal) >= 0)
    {
        ComputeNormals();
    }
    RENDERER_MANAGE_SINGLETON.UpdateAll(GetVertexBuffer());
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
    sin = source.ReadContainerWithNumber<std::vector<float>>(numSliceSamples + 1);
    cos = source.ReadContainerWithNumber<std::vector<float>>(numSliceSamples + 1);

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

uint64_t Rendering::TubeSurface::Register(CoreTools::ObjectRegister& target) const
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
    size += CORE_TOOLS_STREAM_SIZE(numMedialSamples);
    size += CORE_TOOLS_STREAM_SIZE(numSliceSamples);
    size += CORE_TOOLS_STREAM_SIZE(upVector);
    size += CORE_TOOLS_STREAM_SIZE(sin);
    size += CORE_TOOLS_STREAM_SIZE(cos);
    size += CORE_TOOLS_STREAM_SIZE(closed);
    size += CORE_TOOLS_STREAM_SIZE(sampleByArcLength);
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
