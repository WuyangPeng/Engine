///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/08 16:54)

#include "Rendering/RenderingExport.h"

#include "ShaderFloat.h"
#include "Detail/ShaderFloatImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, ShaderFloat);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ShaderFloat);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ShaderFloat);

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ShaderFloat)

Rendering::ShaderFloat::ShaderFloat(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    SELF_CLASS_IS_VALID_0;
}
CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, ShaderFloat)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, ShaderFloat)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, ShaderFloat)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, ShaderFloat)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, ShaderFloat)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, ShaderFloat)

Rendering::ShaderFloat::ShaderFloat(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "ShaderFloat" }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderFloat::ShaderFloat(int numRegisters)
    : ParentType{ "ShaderFloat" }, impl{ numRegisters }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderFloat::ShaderFloat(const FloatVector& data)
    : ParentType{ "ShaderFloat" }, impl{ data }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ShaderFloat)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderFloat, SetNumRegisters, int, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderFloat, GetNumRegisters, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderFloat, GetData, const float*)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderFloat, GetData, float*)

void Rendering::ShaderFloat::SetRegister(int index, const FloatVector& data)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetRegister(index, data);
}

void Rendering::ShaderFloat::SetRegister(int index, const AVector& vector)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetRegister(index, vector);
}

void Rendering::ShaderFloat::SetRegister(int index, const APoint& point)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetRegister(index, point);
}

void Rendering::ShaderFloat::SetRegister(int index, const Colour& colour)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetRegister(index, colour);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ShaderFloat, SetRegisters, Matrix, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ShaderFloat, SetRegisters, FloatVector, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderFloat, GetRegister, int, Rendering::ShaderFloat::FloatVector)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderFloat, GetRegisters, Rendering::ShaderFloat::FloatVector)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderFloat, operator[], int, const float&)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderFloat, operator[], int, float&)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderFloat, EnableUpdater, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderFloat, DisableUpdater, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderFloat, AllowUpdater, bool)

void Rendering::ShaderFloat::Update(MAYBE_UNUSED const Visual* visual, MAYBE_UNUSED const Camera* camera)
{
    // 派生类存根。
    RENDERING_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();
}

Rendering::ShaderFloat::ShaderFloatSharedPtr Rendering::ShaderFloat::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::ShaderFloat::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
