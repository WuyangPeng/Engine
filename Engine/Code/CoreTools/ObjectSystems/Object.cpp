///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/07 0:57)

#include "CoreTools/CoreToolsExport.h"

#include "BufferInStream.h"
#include "BufferSource.h"
#include "BufferTargetDetail.h"
#include "InitTerm.h"
#include "NullObject.h"
#include "Object.h"
#include "ObjectManager.h"
#include "ObjectRegister.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManager.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::string;

CORE_TOOLS_RTTI_DEFINE(CoreTools, Object);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, Object);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(CoreTools, Object);

CoreTools::Object::Object(const string& name)
    : ParentType{ UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(UniqueIDSelect::Object) }, objectName{ name }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::Object::Object(LoadConstructor value)
    : ParentType{ value }, objectName{ string{} }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Object);

// 名字
string CoreTools::Object::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return objectName.GetName();
}

void CoreTools::Object::SetName(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    objectName.SetName(name);
}

int CoreTools::Object::GetStreamingSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    // RTTI名
    int size = CORE_TOOLS_STREAM_SIZE(GetRttiType().GetName());

    // UniqueID
    size += CORE_TOOLS_STREAM_SIZE(this);

    // 对象名
    size += CORE_TOOLS_STREAM_SIZE(objectName.GetName());

    return size;
}

int64_t CoreTools::Object::Register(ObjectRegister& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return target.RegisterRoot(shared_from_this());
}

void CoreTools::Object::Save(BufferTarget& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    // 写入RTTI名用于加载期间查找工厂函数。
    target.Write(GetRttiType().GetName());

    // 写入对象的唯一标识符。这是加载和链接时使用。
    target.WriteUniqueID(shared_from_this());

    // 写入对象的名字。
    target.Write(objectName.GetName());

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void CoreTools::Object::Link(MAYBE_UNUSED ObjectLink& source)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    // Object没有Object*成员。

    CoreTools::DisableNoexcept();
}

void CoreTools::Object::PostLink()
{
    // Object 没有后链接语义。

    CORE_TOOLS_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

void CoreTools::Object::Load(BufferSource& source)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    // RTTI名已经在流中读取，以查找正确的对象加载函数。

    // 读取的对象的唯一标识符。这提供信息在链接阶段。
    source.ReadUniqueID(*this);

    // 读取对象名字。
    auto name = source.ReadString();

    SetName(name);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectSharedPtr CoreTools::Object::GetObjectByName(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (name == objectName.GetName())
    {
        return ObjectSharedFromThis();
    }
    else
    {
        return GetNullObject();
    }
}

CoreTools::Object::ObjectSharedPtrContainer CoreTools::Object::GetAllObjectsByName(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (name == objectName.GetName())
    {
        return ObjectSharedPtrContainer{ ObjectSharedFromThis() };
    }
    else
    {
        return ObjectSharedPtrContainer{};
    }
}

CoreTools::ConstObjectSharedPtr CoreTools::Object::GetConstObjectByName(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (name == objectName.GetName())
    {
        return ObjectSharedFromThis();
    }
    else
    {
        return GetNullObject();
    }
}

CoreTools::Object::ConstObjectSharedPtrContainer CoreTools::Object::GetAllConstObjectsByName(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (name == objectName.GetName())
    {
        return ConstObjectSharedPtrContainer{ ObjectSharedFromThis() };
    }
    else
    {
        return ConstObjectSharedPtrContainer{};
    }
}

bool CoreTools::Object::IsNullObject() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return false;
}

// static
const CoreTools::Object::ObjectSharedPtr& CoreTools::Object::GetNullObject()
{
    static ObjectSharedPtr result{ std::make_shared<NullObject>(DisableNotThrow::Disable) };

    return result;
}

// private
CoreTools::Object::ObjectSharedPtr CoreTools::Object::ObjectSharedFromThis()
{
    return std::const_pointer_cast<Object>(static_cast<const ClassType&>(*this).ObjectSharedFromThis());
}

// private
CoreTools::Object::ConstObjectSharedPtr CoreTools::Object::ObjectSharedFromThis() const
{
    return boost::polymorphic_pointer_cast<const Object>(shared_from_this());
}