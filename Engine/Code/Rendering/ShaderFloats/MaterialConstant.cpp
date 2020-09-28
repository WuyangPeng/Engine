// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 18:05)

#include "Rendering/RenderingExport.h"

#include "MaterialConstant.h"
#include "Detail/MaterialConstantImpl.h"

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
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, MaterialConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, MaterialConstant);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, MaterialConstant); 
CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(Rendering, MaterialConstant);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, MaterialConstant);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, MaterialConstant);

Rendering::MaterialConstant
	::MaterialConstant(const MaterialSmartPointer& material)
	:ParentType{ sm_NumRegisters }, m_Impl{ make_shared<ImplType>(material) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 
CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, MaterialConstant)

void Rendering::MaterialConstant
	::SetNumRegisters(int numRegisters)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(numRegisters == sm_NumRegisters, "MaterialConstant寄存器的数量必须为1");

	ParentType::SetNumRegisters(numRegisters);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, MaterialConstant,GetMaterial, const Rendering::ConstMaterialSmartPointer )

#include STSTEM_WARNING_POP