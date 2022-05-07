///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/16 18:04)

#include "Rendering/RenderingExport.h"

#include "FloatArray.h"
#include "Detail/FloatArrayImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, FloatArray)

CORE_TOOLS_RTTI_DEFINE(Rendering, FloatArray);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, FloatArray);
CORE_TOOLS_FACTORY_DEFINE(Rendering, FloatArray);

Rendering::FloatArray::FloatArray(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, FloatArray)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, FloatArray)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, FloatArray)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, FloatArray)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, FloatArray)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, FloatArray)

Rendering::FloatArray::FloatArray(const FloatVector& data)
    : ParentType{ "FloatArray" }, impl{ data }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, FloatArray)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, FloatArray, operator[], int, const float&)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, FloatArray, operator[], int, float&)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, FloatArray, GetNumElements, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, FloatArray, GetData, const float*)

CoreTools::ObjectInterfaceSharedPtr Rendering::FloatArray::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
