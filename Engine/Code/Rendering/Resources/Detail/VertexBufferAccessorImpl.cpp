///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 18:54)

#include "Rendering/RenderingExport.h"

#include "VertexBufferAccessorImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/VertexBufferAccessorArrayDataDetail.h"
#include "Rendering/Resources/VertexBufferAccessorDataDetail.h"
#include "Rendering/SceneGraph/Visual.h"

Rendering::VertexBufferAccessorImpl::VertexBufferAccessorImpl(const ConstVertexFormatSharedPtr& vertexformat, const ConstVertexBufferSharedPtr& vertexbuffer)
    : vertexFormat{ vertexformat },
      vertexBuffer{ vertexbuffer },
      stride{ vertexFormat->GetStride() },
      data{ vertexBuffer->GetReadOnlyData() },
      position{ *vertexFormat, *vertexBuffer },
      normal{ *vertexFormat, *vertexBuffer },
      tangent{ *vertexFormat, *vertexBuffer },
      binormal{ *vertexFormat, *vertexBuffer },
      textureCoord{ *vertexFormat, *vertexBuffer },
      color{ *vertexFormat, *vertexBuffer },
      blendIndices{ *vertexFormat, *vertexBuffer },
      blendWeight{ *vertexFormat, *vertexBuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VertexBufferAccessorImpl::VertexBufferAccessorImpl(const Visual& visual)
    : vertexFormat{ visual.GetConstVertexFormat() },
      vertexBuffer{ visual.GetConstVertexBuffer() },
      stride{ vertexFormat->GetStride() },
      data{ vertexBuffer->GetReadOnlyData() },
      position{ *vertexFormat, *vertexBuffer },
      normal{ *vertexFormat, *vertexBuffer },
      tangent{ *vertexFormat, *vertexBuffer },
      binormal{ *vertexFormat, *vertexBuffer },
      textureCoord{ *vertexFormat, *vertexBuffer },
      color{ *vertexFormat, *vertexBuffer },
      blendIndices{ *vertexFormat, *vertexBuffer },
      blendWeight{ *vertexFormat, *vertexBuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::VertexBufferAccessorImpl::IsValid() const noexcept
{
    if (!(!vertexFormat || !vertexBuffer))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::VertexBufferAccessorImpl::ApplyTo(const ConstVertexFormatSharedPtr& vertexformat, const ConstVertexBufferSharedPtr& vertexbuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    vertexFormat = vertexformat;
    vertexBuffer = vertexbuffer;

    Initialize();
}

void Rendering::VertexBufferAccessorImpl::ApplyTo(const Visual& visual)
{
    RENDERING_CLASS_IS_VALID_1;

    vertexFormat = visual.GetConstVertexFormat();
    vertexBuffer = visual.GetConstVertexBuffer();

    Initialize();
}

// private
void Rendering::VertexBufferAccessorImpl::Initialize()
{
    stride = vertexFormat->GetStride();
    data = vertexBuffer->GetReadOnlyData();

    position.Init(*vertexFormat, *vertexBuffer);
    normal.Init(*vertexFormat, *vertexBuffer);
    tangent.Init(*vertexFormat, *vertexBuffer);
    binormal.Init(*vertexFormat, *vertexBuffer);
    textureCoord.Init(*vertexFormat, *vertexBuffer);
    color.Init(*vertexFormat, *vertexBuffer);
    blendIndices.Init(*vertexFormat, *vertexBuffer);
    blendWeight.Init(*vertexFormat, *vertexBuffer);
}

const char* Rendering::VertexBufferAccessorImpl::GetData() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return data;
}

int Rendering::VertexBufferAccessorImpl::GetNumVertices() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return vertexBuffer->GetNumElements();
}

int Rendering::VertexBufferAccessorImpl::GetStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return stride;
}

const char* Rendering::VertexBufferAccessorImpl::GetPosition(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return position.GetData(stride, index);
}

bool Rendering::VertexBufferAccessorImpl::HasPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return position.HasData();
}

int Rendering::VertexBufferAccessorImpl::GetPositionChannels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return position.GetDataChannels();
}

const float* Rendering::VertexBufferAccessorImpl::GetPositionTuple(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return position.GetDataTuple(stride, index);
}

const char* Rendering::VertexBufferAccessorImpl::GetNormal(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return normal.GetData(stride, index);
}

bool Rendering::VertexBufferAccessorImpl::HasNormal() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return normal.HasData();
}

int Rendering::VertexBufferAccessorImpl::GetNormalChannels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return normal.GetDataChannels();
}

const float* Rendering::VertexBufferAccessorImpl::GetNormalTuple(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return normal.GetDataTuple(stride, index);
}

const char* Rendering::VertexBufferAccessorImpl::GetTangent(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return tangent.GetData(stride, index);
}

bool Rendering::VertexBufferAccessorImpl::HasTangent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return tangent.HasData();
}

int Rendering::VertexBufferAccessorImpl::GetTangentChannels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return tangent.GetDataChannels();
}

const float* Rendering::VertexBufferAccessorImpl::GetTangentTuple(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return tangent.GetDataTuple(stride, index);
}

const char* Rendering::VertexBufferAccessorImpl::GetBinormal(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return binormal.GetData(stride, index);
}

bool Rendering::VertexBufferAccessorImpl::HasBinormal() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return binormal.HasData();
}

int Rendering::VertexBufferAccessorImpl::GetBinormalChannels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return binormal.GetDataChannels();
}

const float* Rendering::VertexBufferAccessorImpl::GetBinormalTuple(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return binormal.GetDataTuple(stride, index);
}

const char* Rendering::VertexBufferAccessorImpl::GetTextureCoord(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return textureCoord.GetData(stride, unit, index);
}

bool Rendering::VertexBufferAccessorImpl::HasTextureCoord(int unit) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return textureCoord.HasData(unit);
}

int Rendering::VertexBufferAccessorImpl::GetTextureCoordChannels(int unit) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return textureCoord.GetDataChannels(unit);
}

const float* Rendering::VertexBufferAccessorImpl::GetTextureCoordTuple(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return textureCoord.GetDataTuple(stride, unit, index);
}

const char* Rendering::VertexBufferAccessorImpl::GetColor(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return color.GetData(stride, unit, index);
}

bool Rendering::VertexBufferAccessorImpl::HasColor(int unit) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return color.HasData(unit);
}

int Rendering::VertexBufferAccessorImpl::GetColorChannels(int unit) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return color.GetDataChannels(unit);
}

const float* Rendering::VertexBufferAccessorImpl::GetColorTuple(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return color.GetDataTuple(stride, unit, index);
}

const char* Rendering::VertexBufferAccessorImpl::GetBlendIndices(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return blendIndices.GetData(stride, index);
}

bool Rendering::VertexBufferAccessorImpl::HasBlendIndices() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return blendIndices.HasData();
}

const char* Rendering::VertexBufferAccessorImpl::GetBlendWeight(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return blendWeight.GetData(stride, index);
}

bool Rendering::VertexBufferAccessorImpl::HasBlendWeight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return blendWeight.HasData();
}

int Rendering::VertexBufferAccessorImpl::GetNormalExcursion(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto excursion = boost::numeric_cast<int>(normal.GetData(stride, index) - data);

    return excursion;
}

int Rendering::VertexBufferAccessorImpl::GetTangentExcursion(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto excursion = boost::numeric_cast<int>(tangent.GetData(stride, index) - data);

    return excursion;
}

int Rendering::VertexBufferAccessorImpl::GetBinormalExcursion(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto excursion = boost::numeric_cast<int>(binormal.GetData(stride, index) - data);

    return excursion;
}

int Rendering::VertexBufferAccessorImpl::GetTextureCoordExcursion(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto excursion = boost::numeric_cast<int>(textureCoord.GetData(stride, unit, index) - data);

    return excursion;
}

int Rendering::VertexBufferAccessorImpl::GetPositionExcursion(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto excursion = boost::numeric_cast<int>(position.GetData(stride, index) - data);

    return excursion;
}
