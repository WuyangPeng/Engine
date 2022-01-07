///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 23:09)

#include "CoreTools/CoreToolsExport.h"

#include "BufferInStream.h"
#include "BufferSource.h"
#include "BufferTargetDetail.h"
#include "InitTerm.h"
#include "Object.h"
#include "ObjectManager.h"
#include "ObjectRegister.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::string;

CORE_TOOLS_RTTI_DEFINE(CoreTools, Object);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, Object);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(CoreTools, Object);

CoreTools::Object::Object(const string& name)
    : ParentType{}, m_Name{ name }
{
    SetUniqueID(UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(UniqueIDSelect::Object));

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::Object::Object(LoadConstructor value)
    : ParentType{ value }, m_Name{ string{} }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::Object::~Object()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Object);

// 名字
string CoreTools::Object::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Name.GetName();
}

void CoreTools::Object::SetName(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Name.SetName(name);
}

int CoreTools::Object::GetStreamingSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    // RTTI名
    int size = CORE_TOOLS_STREAM_SIZE(GetRttiType().GetName());

    // UniqueID
    size += CORE_TOOLS_STREAM_SIZE(this);

    // 对象名
    size += CORE_TOOLS_STREAM_SIZE(m_Name.GetName());

    return size;
}

uint64_t CoreTools::Object::Register(ObjectRegister& target) const
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
    target.Write(m_Name.GetName());

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

    if (name == m_Name.GetName())
        return ObjectSharedFromThis();
    else
        return ObjectSharedPtr{};
}

CoreTools::Object::ObjectSharedPtrContainer CoreTools::Object::GetAllObjectsByName(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ObjectSharedPtrContainer objects{};

    if (name == m_Name.GetName())
    {
        objects.emplace_back(ObjectSharedFromThis());
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr CoreTools::Object::GetConstObjectByName(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (name == m_Name.GetName())
        return ObjectSharedFromThis();
    else
        return ConstObjectSharedPtr{};
}

CoreTools::Object::ConstObjectSharedPtrContainer CoreTools::Object::GetAllConstObjectsByName(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    ConstObjectSharedPtrContainer objects{};

    if (name == m_Name.GetName())
    {
        objects.emplace_back(ObjectSharedFromThis());
    }

    return objects;
}

CoreTools::Object::ObjectSharedPtr CoreTools::Object::ObjectSharedFromThis()
{
    return std::const_pointer_cast<Object>(static_cast<const ClassType&>(*this).ObjectSharedFromThis());
}

CoreTools::Object::ConstObjectSharedPtr CoreTools::Object::ObjectSharedFromThis() const
{
    return boost::polymorphic_pointer_cast<const Object>(shared_from_this());
}