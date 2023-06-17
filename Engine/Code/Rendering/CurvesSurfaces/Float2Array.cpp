///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:59)

#include "Rendering/RenderingExport.h"

#include "Float2Array.h"
#include "Detail/Float2ArrayImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Float2Array)

CORE_TOOLS_RTTI_DEFINE(Rendering, Float2Array);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Float2Array);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Float2Array);

Rendering::Float2Array::Float2Array(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, Float2Array)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, Float2Array)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, Float2Array)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, Float2Array)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, Float2Array)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, Float2Array)

Rendering::Float2Array::Float2Array(const Float2Vector& data)
    : ParentType("Float2Array"), impl{ data }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Float2Array)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Float2Array, operator[], int, const Rendering::Float2Array::Float2&)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Float2Array, operator[], int, Rendering::Float2Array::Float2&)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Float2Array, GetNumElements, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Float2Array, GetData, const Rendering::Float2Array::Float2*)

CoreTools::ObjectInterfaceSharedPtr Rendering::Float2Array::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
