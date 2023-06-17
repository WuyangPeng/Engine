///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:53)

#include "Rendering/RenderingExport.h"

#include "CollapseRecordArray.h"
#include "Detail/CollapseRecordArrayImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, CollapseRecordArray)

CORE_TOOLS_RTTI_DEFINE(Rendering, CollapseRecordArray);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, CollapseRecordArray);
CORE_TOOLS_FACTORY_DEFINE(Rendering, CollapseRecordArray);

Rendering::CollapseRecordArray::CollapseRecordArray(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, CollapseRecordArray)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, CollapseRecordArray)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, CollapseRecordArray)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, CollapseRecordArray)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, CollapseRecordArray)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, CollapseRecordArray)

Rendering::CollapseRecordArray::CollapseRecordArray(const std::vector<CollapseRecord>& collapseRecord)
    : ParentType{ "CollapseRecordArray" }, impl{ collapseRecord }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, CollapseRecordArray)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, CollapseRecordArray, GetNumRecords, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, CollapseRecordArray, GetRecord, int, Rendering::CollapseRecord)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, CollapseRecordArray, GetRecords, std::vector<Rendering::CollapseRecord>)

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::CollapseRecordArray::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
