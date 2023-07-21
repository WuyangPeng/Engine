///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 14:36)

#include "Rendering/RenderingExport.h"

#include "ShaderData.h"
#include "Detail/ShaderDataImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ShaderData)

Rendering::ShaderData::ShaderData(GraphicsObjectType inType, const std::string& inName, int inBindPoint, int inNumBytes, int inExtra, bool inIsGpuWritable)
    : impl{ inType, inName, inBindPoint, inNumBytes, inExtra, inIsGpuWritable }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderData)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderData, GetType, Rendering::GraphicsObjectType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderData, GetName, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderData, GetBindPoint, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderData, GetNumBytes, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderData, GetExtra, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderData, IsGpuWritable, bool)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, ShaderData, SetGraphicsObject, GraphicsObjectSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderData, GetGraphicsObject, Rendering::ConstGraphicsObjectSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderData, GetGraphicsObject, Rendering::GraphicsObjectSharedPtr)

void Rendering::ShaderData::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->Load(source);
}

void Rendering::ShaderData::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    impl->Save(target);
}

int Rendering::ShaderData::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetStreamingSize();
}

void Rendering::ShaderData::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->Link(source);
}

void Rendering::ShaderData::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    impl->Register(target);
}
