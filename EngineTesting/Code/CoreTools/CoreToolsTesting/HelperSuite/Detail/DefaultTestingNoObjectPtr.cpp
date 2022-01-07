///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/19 14:49)

#include "DefaultTestingNoObjectPtr.h"
#include "TestingNoObjectPtrImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;
using std::string;

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, DefaultTestingNoObjectPtr);

CORE_TOOLS_RTTI_DEFINE(CoreTools, DefaultTestingNoObjectPtr);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, DefaultTestingNoObjectPtr);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, DefaultTestingNoObjectPtr);

CoreTools::DefaultTestingNoObjectPtr::DefaultTestingNoObjectPtr(const string& name)
    : ParentType{ name }, impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::DefaultTestingNoObjectPtr::ObjectSharedPtr CoreTools::DefaultTestingNoObjectPtr::Create(const string& name)
{
    return make_shared<ClassType>(name); 
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DefaultTestingNoObjectPtr);

CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(CoreTools, DefaultTestingNoObjectPtr);

CoreTools::ObjectInterfaceSharedPtr CoreTools::DefaultTestingNoObjectPtr::CloneObject() const
{
    return make_shared<ClassType>(*this);
}
