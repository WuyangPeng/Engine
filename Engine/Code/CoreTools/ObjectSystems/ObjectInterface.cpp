//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/22 16:28)

#include "CoreTools/CoreToolsExport.h"

#include "BufferInStream.h"
#include "InitTerm.h"
#include "InitTermRegisterFactory.h"
#include "ObjectInterface.h"
#include "ObjectManager.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

CoreTools::ObjectInterface::ObjectInterface() noexcept
    : m_UniqueID{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ObjectInterface::ObjectInterface([[maybe_unused]] LoadConstructor value) noexcept
    : m_UniqueID{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectInterface);

CORE_TOOLS_RTTI_BASE_DEFINE(CoreTools, ObjectInterface);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(CoreTools, ObjectInterface);

CORE_TOOLS_MUTEX_EXTERN(CoreTools);

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

uint64_t CoreTools::ObjectInterface::GetUniqueID() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_UniqueID;
}

void CoreTools::ObjectInterface::SetUniqueID(uint64_t uniqueID) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_UniqueID = uniqueID;
}

bool CoreTools::ObjectInterface::IsExactly(const Rtti& type) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetCurrentRttiType().IsExactly(type);
}

bool CoreTools::ObjectInterface::IsDerived(const Rtti& type) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetCurrentRttiType().IsDerived(type);
}

bool CoreTools::ObjectInterface::IsExactlyTypeOf(const ObjectInterface* object) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return object != nullptr && GetRttiType().IsExactly(object->GetRttiType());
}

bool CoreTools::ObjectInterface::IsDerivedTypeOf(const ObjectInterface* object) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return object != nullptr && GetRttiType().IsDerived(object->GetRttiType());
}
