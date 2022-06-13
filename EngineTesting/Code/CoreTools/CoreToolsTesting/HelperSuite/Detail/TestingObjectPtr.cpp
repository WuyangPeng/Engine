///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:24)

#include "TestingNoObjectPtrImpl.h"
#include "TestingObjectPtr.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;
using std::string;

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, TestingObjectPtr);

CORE_TOOLS_RTTI_DEFINE(CoreTools, TestingObjectPtr);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, TestingObjectPtr);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, TestingObjectPtr);

CoreTools::TestingObjectPtr::TestingObjectPtr(const string& name)
    : ParentType{ name }, impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::TestingObjectPtr::ObjectSharedPtr CoreTools::TestingObjectPtr::Create(const string& name)
{
    return make_shared<ClassType>(name);
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
    return make_shared<ClassType>(*this);
}
