// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 18:22)

#include "Rendering/RenderingExport.h"

#include "ShaderFloat.h"
#include "Detail/ShaderFloatImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/ClassInvariant/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455)
CORE_TOOLS_RTTI_DEFINE(Rendering, ShaderFloat);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ShaderFloat);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ShaderFloat); 
CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(Rendering, ShaderFloat);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, ShaderFloat);

Rendering::ShaderFloat
	::ShaderFloat()
	:ParentType{ "ShaderFloat" }, m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderFloat
	::ShaderFloat(int numRegisters)
	:ParentType{ "ShaderFloat" }, m_Impl{ make_shared<ImplType>(numRegisters) } 
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderFloat
	::ShaderFloat(const FloatVector& data)
	:ParentType{ "ShaderFloat" }, m_Impl{ make_shared<ImplType>(data) } 
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderFloat
	::~ShaderFloat()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering,ShaderFloat)
 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderFloat,SetNumRegisters, int, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderFloat,GetNumRegisters, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderFloat,GetData, const float*)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderFloat,GetData, float*)		 
 

void Rendering::ShaderFloat
	::SetRegister(int index, const FloatVector& data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetRegister(index, data);
}

void Rendering::ShaderFloat
	::SetRegister(int index, const AVector& vector)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetRegister(index, vector);
}

void Rendering::ShaderFloat
	::SetRegister(int index, const APoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetRegister(index, point);
}

void Rendering::ShaderFloat
	::SetRegister( int index, const Colour& colour )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetRegister(index, colour);
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
 
void Rendering::ShaderFloat
	::Update (const Visual* visual, const Camera* camera)
{
    // ≈……˙¿‡¥Ê∏˘°£
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	CoreTools::DoNothing();

	SYSTEM_UNUSED_ARG(visual);
	SYSTEM_UNUSED_ARG(camera);
}

Rendering::ShaderFloat::ShaderFloatSmartPointer Rendering::ShaderFloat
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ShaderFloatSmartPointer{ std::make_shared<ClassType>(*this) };
}
#include STSTEM_WARNING_POP