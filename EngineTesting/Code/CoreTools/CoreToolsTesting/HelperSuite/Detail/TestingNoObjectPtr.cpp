///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/19 15:09)

#include "TestingNoObjectPtr.h"
#include "TestingNoObjectPtrImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;
using std::string;

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, TestingNoObjectPtr);

CORE_TOOLS_RTTI_DEFINE(CoreTools, TestingNoObjectPtr);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, TestingNoObjectPtr);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, TestingNoObjectPtr);

CoreTools::TestingNoObjectPtr::TestingNoObjectPtr(const string& name)
    : ParentType{ name }, impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::TestingNoObjectPtr::ObjectSharedPtr CoreTools::TestingNoObjectPtr::Create(const string& name)
{
    return make_shared<ClassType>(name);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TestingNoObjectPtr);

CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_CONSTRUCTOR_DEFINE(CoreTools, TestingNoObjectPtr);
CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(CoreTools, TestingNoObjectPtr);
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(CoreTools, TestingNoObjectPtr);
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(CoreTools, TestingNoObjectPtr);
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(CoreTools, TestingNoObjectPtr);
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(CoreTools, TestingNoObjectPtr);
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(CoreTools, TestingNoObjectPtr);

CoreTools::ObjectInterfaceSharedPtr CoreTools::TestingNoObjectPtr::CloneObject() const
{
    return make_shared<ClassType>(*this);
}
