///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:00)

#include "Rendering/RenderingExport.h"

#include "RectangleSurface.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/CurvesSurfacesVolumes/ParametricSurfaceDetail.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, RectangleSurface);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, RectangleSurface);
CORE_TOOLS_FACTORY_DEFINE(Rendering, RectangleSurface);

Rendering::RectangleSurface::RectangleSurface(const std::shared_ptr<Mathematics::ParametricSurface<float>>& surface,
                                              int numUSamples,
                                              int numVSamples,
                                              const VertexFormatSharedPtr& vformat,
                                              const Mathematics::Float2& tcoordMin,
                                              const Mathematics::Float2& tcoordMax)
    : ParentType{ vformat, nullptr, nullptr },
      surface{ surface },
      numUSamples{ numUSamples },
      numVSamples{ numVSamples }
{
    RENDERING_ASSERTION_0(surface && surface->IsRectangular(), "无效的表面\n");

    SetVertexFormat(vformat);

    const auto uMin = surface->GetUMin();
    const auto uRange = surface->GetUMax() - uMin;

    const auto vMin = surface->GetVMin();
    const auto vRange = surface->GetVMax() - vMin;

    const auto vstride = vformat->GetStride();
    SetVertexBuffer(VertexBuffer::Create(*vformat, vstride));

    MAYBE_UNUSED auto tuDelta = (tcoordMax[0] - tcoordMin[0]) / uRange;
    MAYBE_UNUSED auto tvDelta = (tcoordMax[1] - tcoordMin[1]) / vRange;

    const auto numTriangles = 2 * (numUSamples - 1) * (numVSamples - 1);
    const auto numIndices = 3 * numTriangles;
    SetIndexBuffer(IndexBuffer::Create(IndexFormatType::PolyPoint, numIndices, sizeof(int)));

    auto indices = GetIndexBuffer()->GetData();
    for (auto uIndex = 0, i = 0; uIndex < numUSamples - 1; ++uIndex)
    {
        auto i0 = i;
        auto i1 = i0 + 1;
        i += numVSamples;
        auto i2 = i;
        auto i3 = i2 + 1;
        for (auto vIndex = 0; vIndex < numVSamples - 1; ++vIndex)
        {
            indices.Increase(i0);
            indices.Increase(i1);
            indices.Increase(i2);
            indices.Increase(i1);
            indices.Increase(i3);
            indices.Increase(i2);
            i0++;
            i1++;
            i2++;
            i3++;
        }
    }

    UpdateModelSpace(VisualUpdateType::Normals);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RectangleSurface)

void Rendering::RectangleSurface::UpdateSurface()
{
    RENDERING_CLASS_IS_VALID_1;

    UpdateModelSpace(VisualUpdateType::Normals);
}

Rendering::RectangleSurface::RectangleSurface(LoadConstructor value)
    : ParentType{ value }, surface{}, numUSamples{}, numVSamples{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::RectangleSurface::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(numUSamples);
    source.Read(numVSamples);

    surface = nullptr;

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::RectangleSurface::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::RectangleSurface::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

int64_t Rendering::RectangleSurface::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::RectangleSurface::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(numUSamples);
    target.Write(numVSamples);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::RectangleSurface::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();
    size += sizeof(numUSamples);
    size += sizeof(numVSamples);
    return size;
}

void Rendering::RectangleSurface::SetSurface(const std::shared_ptr<Mathematics::ParametricSurface<float>>& aSurface) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    surface = aSurface;
}

std::shared_ptr<Mathematics::ParametricSurface<float>> Rendering::RectangleSurface::GetSurface() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return surface;
}

int Rendering::RectangleSurface::GetNumUSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numUSamples;
}

int Rendering::RectangleSurface::GetNumVSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numVSamples;
}
