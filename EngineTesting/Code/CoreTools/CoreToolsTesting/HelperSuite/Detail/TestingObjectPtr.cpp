///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/16 20:58)

#include "TestingNoObjectPtrImpl.h"
#include "TestingObjectPtr.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, TestingObjectPtr);

CORE_TOOLS_RTTI_DEFINE(CoreTools, TestingObjectPtr);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, TestingObjectPtr);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, TestingObjectPtr);

CoreTools::TestingObjectPtr::TestingObjectPtr(const std::string& name)
    : ParentType{ name }, impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::TestingObjectPtr::ObjectSharedPtr CoreTools::TestingObjectPtr::Create(const std::string& name)
{
    return std::make_shared<ClassType>(name);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TestingObjectPtr);

CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_CONSTRUCTOR_DEFINE(CoreTools, TestingObjectPtr);
CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(CoreTools, TestingObjectPtr);
CORE_TOOLS_WITH_IMPL_OBJECT_REGISTER_DEFINE(CoreTools, TestingObjectPtr);
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(CoreTools, TestingObjectPtr);
CORE_TOOLS_WITH_IMPL_OBJECT_LINK_DEFINE(CoreTools, TestingObjectPtr);
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(CoreTools, TestingObjectPtr);
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(CoreTools, TestingObjectPtr);

CoreTools::ObjectInterfaceSharedPtr CoreTools::TestingObjectPtr::CloneObject() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
