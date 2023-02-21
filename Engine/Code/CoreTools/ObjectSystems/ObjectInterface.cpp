///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/07 0:02)

#include "CoreTools/CoreToolsExport.h"

#include "BufferInStream.h"
#include "InitTerm.h"
#include "InitTermRegisterFactory.h"
#include "ObjectInterface.h"
#include "ObjectManager.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

CoreTools::ObjectInterface::ObjectInterface() noexcept
    : uniqueID{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ObjectInterface::ObjectInterface(LoadConstructor loadConstructor) noexcept
    : uniqueID{ 0 }
{
    System::UnusedFunction(loadConstructor);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ObjectInterface::ObjectInterface(int64_t uniqueID) noexcept
    : uniqueID{ uniqueID }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectInterface);

CORE_TOOLS_RTTI_BASE_DEFINE(CoreTools, ObjectInterface);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(CoreTools, ObjectInterface);

// static
bool CoreTools::ObjectInterface::RegisterFactory()
{
    static InitTermRegisterFactory registerFactory{ ClassType::InitializeFactory, ClassType::TerminateFactory };

    return true;
}

// static
void CoreTools::ObjectInterface::InitializeFactory()
{
    OBJECT_MANAGER_SINGLETON.Insert(GetCurrentRttiType().GetName(), Factory);
}

// static
void CoreTools::ObjectInterface::TerminateFactory()
{
    OBJECT_MANAGER_SINGLETON.Remove(GetCurrentRttiType().GetName());
}

int64_t CoreTools::ObjectInterface::GetUniqueID() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return uniqueID;
}

void CoreTools::ObjectInterface::SetUniqueID(int64_t aUniqueID) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    uniqueID = aUniqueID;
}

bool CoreTools::ObjectInterface::IsExactly(const Rtti& type) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetRttiType().IsExactly(type);
}

bool CoreTools::ObjectInterface::IsDerived(const Rtti& type) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetRttiType().IsDerived(type);
}

bool CoreTools::ObjectInterface::IsExactlyTypeOf(const ObjectInterface* object) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return object != nullptr && IsExactly(object->GetRttiType());
}

bool CoreTools::ObjectInterface::IsDerivedTypeOf(const ObjectInterface* object) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return object != nullptr && IsDerived(object->GetRttiType());
}
