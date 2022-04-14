///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 19:05)

#include "Rendering/RenderingExport.h"

#include "VertexBufferAccessorDetail.h"
#include "Detail/VertexBufferAccessorImpl.h"

#include "System/Helper/PragmaWarning.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/SceneGraph/Detail/PickRecordContainerImpl.h"
#include "Rendering/SceneGraph/Detail/PickRecordImpl.h"
#include "Rendering/SceneGraph/Visual.h"

using std::make_shared;

Rendering::VertexBufferAccessor::VertexBufferAccessor(const ConstVertexFormatSharedPtr& vertexformat, const ConstVertexBufferSharedPtr& vertexbuffer)
    : impl{ vertexformat, vertexbuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VertexBufferAccessor::VertexBufferAccessor(const Visual& visual)
    : impl{ visual }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VertexBufferAccessor)

void Rendering::VertexBufferAccessor::ApplyTo(const ConstVertexFormatSharedPtr& vertexformat, const ConstVertexBufferSharedPtr& vertexbuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->ApplyTo(vertexformat, vertexbuffer);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, VertexBufferAccessor)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor, ApplyTo, const Visual&, void)

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

const char* Rendering::VertexBufferAccessor::GetTextureCoord(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetTextureCoord(unit, index);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor, HasTextureCoord, int, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor, GetTextureCoordChannels, int, int)

const float* Rendering::VertexBufferAccessor::GetTextureCoordTuple(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetTextureCoordTuple(unit, index);
}

const char* Rendering::VertexBufferAccessor::GetColor(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetColor(unit, index);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor, HasColor, int, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexBufferAccessor, GetColorChannels, int, int)

const float* Rendering::VertexBufferAccessor::GetColorTuple(int unit, int index) const
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
Mathematics::APointF Rendering::VertexBufferAccessor::GetPosition(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    const auto firstPosition = *(reinterpret_cast<const float*>(GetPosition(index)));
    const auto secondPosition = *(reinterpret_cast<const float*>(GetPosition(index) + sizeof(float)));
    const auto thirdPosition = *(reinterpret_cast<const float*>(GetPosition(index) + sizeof(float) * 2));

#include STSTEM_WARNING_POP

    Mathematics::APointF position{ firstPosition, secondPosition, thirdPosition };

    return position;
}

template <>
Mathematics::AVectorF Rendering::VertexBufferAccessor::GetNormal(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    const auto firstNormal = *(reinterpret_cast<const float*>(GetNormal(index)));
    const auto secondNormal = *(reinterpret_cast<const float*>(GetNormal(index) + sizeof(float)));
    const auto thirdNormal = *(reinterpret_cast<const float*>(GetNormal(index) + sizeof(float) * 2));

#include STSTEM_WARNING_POP

    Mathematics::AVectorF normal{ firstNormal, secondNormal, thirdNormal };

    return normal;
}

template <>
Mathematics::AVectorF Rendering::VertexBufferAccessor::GetTangent(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    const auto firstTangent = *(reinterpret_cast<const float*>(GetTangent(index)));
    const auto secondTangent = *(reinterpret_cast<const float*>(GetTangent(index) + sizeof(float)));
    const auto thirdTangent = *(reinterpret_cast<const float*>(GetTangent(index) + sizeof(float) * 2));

#include STSTEM_WARNING_POP

    Mathematics::AVectorF tangent{ firstTangent, secondTangent, thirdTangent };

    return tangent;
}

template <>
Mathematics::AVectorF Rendering::VertexBufferAccessor::GetBinormal(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    const auto firstBinormal = *(reinterpret_cast<const float*>(GetBinormal(index)));
    const auto secondBinormal = *(reinterpret_cast<const float*>(GetBinormal(index) + sizeof(float)));
    const auto thirdBinormal = *(reinterpret_cast<const float*>(GetBinormal(index) + sizeof(float) * 2));

#include STSTEM_WARNING_POP

    Mathematics::AVectorF binormal{ firstBinormal, secondBinormal, thirdBinormal };

    return binormal;
}

template <>
Mathematics::Vector2F Rendering::VertexBufferAccessor::GetTextureCoord(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    const auto firstTextureCoord = *(reinterpret_cast<const float*>(GetTextureCoord(unit, index)));
    const auto secondTextureCoord = *(reinterpret_cast<const float*>(GetTextureCoord(unit, index) + sizeof(float)));

#include STSTEM_WARNING_POP

    Mathematics::Vector2F textureCoord{ firstTextureCoord, secondTextureCoord };

    return textureCoord;
}

int Rendering::VertexBufferAccessor::GetTextureCoordExcursion(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetTextureCoordExcursion(unit, index);
}
