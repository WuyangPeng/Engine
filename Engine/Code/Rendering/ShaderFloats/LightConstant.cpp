// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 17:53)

#include "Rendering/RenderingExport.h"

#include "LightConstant.h"
#include "Detail/LightConstantImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;
using std::string;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
CORE_TOOLS_RTTI_DEFINE(Rendering, LightConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightConstant);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, LightConstant); 
CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(Rendering, LightConstant);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, LightConstant);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, LightConstant);

Rendering::LightConstant
	::LightConstant(const LightSmartPointer& light)
	:ParentType{ sm_NumRegisters }, m_Impl{ make_shared<ImplType>(light) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, LightConstant)

void Rendering::LightConstant
	::SetNumRegisters(int numRegisters)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(numRegisters == sm_NumRegisters, "LightConstant�Ĵ�������������Ϊ1");

	ParentType::SetNumRegisters(numRegisters);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, LightConstant,GetLight, const Rendering::ConstLightSmartPointer )




#include STSTEM_WARNING_POP