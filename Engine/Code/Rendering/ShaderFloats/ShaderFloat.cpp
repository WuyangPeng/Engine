// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 18:22)

#include "Rendering/RenderingExport.h"

#include "ShaderFloat.h"
#include "Detail/ShaderFloatImpl.h"

#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, ShaderFloat);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ShaderFloat);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ShaderFloat); 
Rendering::ShaderFloat::ShaderFloat(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ make_shared<ImplType>() }
{
    SELF_CLASS_IS_VALID_0;
}
CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, ShaderFloat)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, ShaderFloat)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, ShaderFloat)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, ShaderFloat)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, ShaderFloat)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, ShaderFloat)

#define COPY_CONSTRUCTION_DEFINE_WITH_PARENT(namespaceName, className)                      \
    namespaceName::className::className(const className& rhs)                               \
        : ParentType{ rhs }, impl{ std::make_shared<ImplType>(*rhs.impl) }                  \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        SELF_CLASS_IS_VALID_0;                                                              \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(const className& rhs)     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        className temp{ rhs };                                                              \
        Swap(temp);                                                                         \
        return *this;                                                                       \
    }                                                                                       \
    void namespaceName::className::Swap(className& rhs) noexcept                            \
    {                                                                                       \
        ;                                       \
        std::swap(impl, rhs.impl);                                                          \
    }                                                                                       \
    namespaceName::className::className(className&& rhs) noexcept                           \
        : ParentType{ std::move(rhs) }, impl{ std::move(rhs.impl) }                         \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(className&& rhs) noexcept \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        ParentType::operator=(std::move(rhs));                                              \
        impl = std::move(rhs.impl);                                                         \
        return *this;                                                                       \
    }                                                                                        
    COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, ShaderFloat);

Rendering::ShaderFloat
	::ShaderFloat()
	:ParentType{ "ShaderFloat" }, impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderFloat
	::ShaderFloat(int numRegisters)
	:ParentType{ "ShaderFloat" }, impl{ make_shared<ImplType>(numRegisters) } 
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

Rendering::ShaderFloat
	::ShaderFloat(const FloatVector& data)
	:ParentType{ "ShaderFloat" }, impl{ make_shared<ImplType>(data) } 
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderFloat
	::~ShaderFloat()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,ShaderFloat)
 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderFloat,SetNumRegisters, int, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderFloat,GetNumRegisters, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderFloat,GetData, const float*)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderFloat,GetData, float*)		 
 

void Rendering::ShaderFloat
	::SetRegister(int index, const FloatVector& data)
{
	;

	return impl->SetRegister(index, data);
}

void Rendering::ShaderFloat
	::SetRegister(int index, const AVector& vector)
{
	;

	return impl->SetRegister(index, vector);
}

void Rendering::ShaderFloat
	::SetRegister(int index, const APoint& point)
{
	;

	return impl->SetRegister(index, point);
}

void Rendering::ShaderFloat
	::SetRegister( int index, const Colour& colour )
{
	;

	return impl->SetRegister(index, colour);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ShaderFloat,SetRegisters, Matrix,void)	

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ShaderFloat,SetRegisters, FloatVector,void)	

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderFloat,GetRegister, int,const Rendering::ShaderFloat::FloatVector)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderFloat,GetRegisters,const Rendering::ShaderFloat::FloatVector)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderFloat,operator[], int,const float&)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderFloat,operator[], int, float&)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderFloat,EnableUpdater,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderFloat,DisableUpdater,void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderFloat,AllowUpdater, bool)
 
void Rendering::ShaderFloat::Update([[maybe_unused]] const Visual* visual, [[maybe_unused]] const Camera* camera)
{
    // ≈……˙¿‡¥Ê∏˘°£
	;

	CoreTools::DisableNoexcept();

 
}

Rendering::ShaderFloat::ShaderFloatSharedPtr Rendering::ShaderFloat
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ShaderFloatSharedPtr{ std::make_shared<ClassType>(*this) };
}

CoreTools::ObjectInterfaceSharedPtr Rendering::ShaderFloat::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP