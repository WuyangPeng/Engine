// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/19 16:09)

#include "Rendering/RenderingExport.h"

#include "VertexBufferAccessorDetail.h"
#include "Detail/VertexBufferAccessorImpl.h"

#include "System/Helper/PragmaWarning.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/SceneGraph/Detail/PickRecordContainerImpl.h"
#include "Rendering/SceneGraph/Detail/PickRecordImpl.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
using std::make_shared;

Rendering::VertexBufferAccessor ::VertexBufferAccessor(const ConstVertexFormatSharedPtr& vertexformat, const ConstVertexBufferSharedPtr& vertexbuffer)
    : impl{ vertexformat, vertexbuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VertexBufferAccessor ::VertexBufferAccessor(Visual* visual)
    : impl{ visual }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VertexBufferAccessor)

void Rendering::VertexBufferAccessor ::ApplyTo(const ConstVertexFormatSharedPtr& vertexformat, const ConstVertexBufferSharedPtr& vertexbuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->ApplyTo(vertexformat, vertexbuffer);
}
COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, VertexBufferAccessor)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor, ApplyTo, const Visual*, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexBufferAccessor, GetData, const char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexBufferAccessor, GetNumVertices, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexBufferAccessor, GetStride, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, VertexBufferAccessor, GetPosition, int, const char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexBufferAccessor, HasPosition, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexBufferAccessor, GetPositionChannels, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, VertexBufferAccessor, GetPositionTuple, int, const float*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, VertexBufferAccessor, GetNormal, int, const char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexBufferAccessor, HasNormal, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexBufferAccessor, GetNormalChannels, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, VertexBufferAccessor, GetNormalTuple, int, const float*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor, GetNormalExcursion, int, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, VertexBufferAccessor, GetTangent, int, const char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexBufferAccessor, HasTangent, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexBufferAccessor, GetTangentChannels, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, VertexBufferAccessor, GetTangentTuple, int, const float*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, VertexBufferAccessor, GetBinormal, int, const char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexBufferAccessor, HasBinormal, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexBufferAccessor, GetBinormalChannels, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, VertexBufferAccessor, GetBinormalTuple, int, const float*)

const char* Rendering::VertexBufferAccessor ::GetTextureCoord(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetTextureCoord(unit, index);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor, HasTextureCoord, int, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor, GetTextureCoordChannels, int, int)

const float* Rendering::VertexBufferAccessor ::GetTextureCoordTuple(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetTextureCoordTuple(unit, index);
}

const char* Rendering::VertexBufferAccessor ::GetColor(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetColor(unit, index);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor, HasColor, int, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor, GetColorChannels, int, int)

const float* Rendering::VertexBufferAccessor ::GetColorTuple(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetColorTuple(unit, index);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, VertexBufferAccessor, GetBlendIndices, int, const char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexBufferAccessor, HasBlendIndices, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, VertexBufferAccessor, GetBlendWeight, int, const char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VertexBufferAccessor, HasBlendWeight, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor, GetBinormalExcursion, int, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor, GetTangentExcursion, int, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor, GetPositionExcursion, int, int)

template <>
Mathematics::FloatAPoint Rendering::VertexBufferAccessor ::GetPosition(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto firstPosition = *(reinterpret_cast<const float*>(GetPosition(index)));
    auto secondPosition = *(reinterpret_cast<const float*>(GetPosition(index) + sizeof(float)));
    auto thirdPosition = *(reinterpret_cast<const float*>(GetPosition(index) + sizeof(float) * 2));

    Mathematics::FloatAPoint position{ firstPosition, secondPosition, thirdPosition };

    return position;
}

template <>
Mathematics::FloatAVector Rendering::VertexBufferAccessor ::GetNormal(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto firstNormal = *(reinterpret_cast<const float*>(GetNormal(index)));
    auto secondNormal = *(reinterpret_cast<const float*>(GetNormal(index) + sizeof(float)));
    auto thirdNormal = *(reinterpret_cast<const float*>(GetNormal(index) + sizeof(float) * 2));

    Mathematics::FloatAVector normal{ firstNormal, secondNormal, thirdNormal };

    return normal;
}

template <>
Mathematics::FloatAVector Rendering::VertexBufferAccessor ::GetTangent(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto firstTangent = *(reinterpret_cast<const float*>(GetTangent(index)));
    auto secondTangent = *(reinterpret_cast<const float*>(GetTangent(index) + sizeof(float)));
    auto thirdTangent = *(reinterpret_cast<const float*>(GetTangent(index) + sizeof(float) * 2));

    Mathematics::FloatAVector tangent{ firstTangent, secondTangent, thirdTangent };

    return tangent;
}

template <>
Mathematics::FloatAVector Rendering::VertexBufferAccessor ::GetBinormal(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto firstBinormal = *(reinterpret_cast<const float*>(GetBinormal(index)));
    auto secondBinormal = *(reinterpret_cast<const float*>(GetBinormal(index) + sizeof(float)));
    auto thirdBinormal = *(reinterpret_cast<const float*>(GetBinormal(index) + sizeof(float) * 2));

    Mathematics::FloatAVector binormal{ firstBinormal, secondBinormal, thirdBinormal };

    return binormal;
}

template <>
Mathematics::FloatVector2D Rendering::VertexBufferAccessor ::GetTextureCoord(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto firstTextureCoord = *(reinterpret_cast<const float*>(GetTextureCoord(unit, index)));
    auto secondTextureCoord = *(reinterpret_cast<const float*>(GetTextureCoord(unit, index) + sizeof(float)));

    Mathematics::FloatVector2D textureCoord{ firstTextureCoord, secondTextureCoord };

    return textureCoord;
}

int Rendering::VertexBufferAccessor ::GetTextureCoordExcursion(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetTextureCoordExcursion(unit, index);
}
#include STSTEM_WARNING_POP