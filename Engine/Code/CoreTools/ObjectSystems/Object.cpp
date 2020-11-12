//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/22 15:15)

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
using std::swap;
using std::vector;

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

// ����
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

// private
void CoreTools::Object::Swap(Object& rhs) noexcept
{
    m_Name.SwapObjectName(rhs.m_Name);
}

int CoreTools::Object::GetStreamingSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    // RTTI��
    int size = CORE_TOOLS_STREAM_SIZE(GetRttiType().GetName());

    // UniqueID
    size += CORE_TOOLS_STREAM_SIZE(this);

    // ������
    size += CORE_TOOLS_STREAM_SIZE(m_Name.GetName());

    return size;
}

uint64_t CoreTools::Object::Register(const ObjectRegisterSharedPtr& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto modify = target;

    return modify->RegisterRoot(shared_from_this());
}

void CoreTools::Object::Save(const BufferTargetSharedPtr& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto modify = target;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(modify);

    // д��RTTI�����ڼ����ڼ���ҹ���������
    modify->Write(GetRttiType().GetName());

    // д������Ψһ��ʶ�������Ǽ��غ�����ʱʹ�á�
    modify->WriteUniqueID(shared_from_this());

    // д���������֡�
    modify->Write(m_Name.GetName());

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(modify);
}

void CoreTools::Object::Link(const ObjectLinkSharedPtr& source)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    // Objectû��Object*��Ա��

    [[maybe_unused]] auto modify = source;

    CoreTools::DisableNoexcept();
}

void CoreTools::Object::PostLink()
{
    // Object û�к��������塣

    CORE_TOOLS_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

void CoreTools::Object::Load(const BufferSourceSharedPtr& source)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto modify = source;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(modify);

    // RTTI���Ѿ������ж�ȡ���Բ�����ȷ�Ķ�����غ�����

    // ��ȡ�Ķ����Ψһ��ʶ�������ṩ��Ϣ�����ӽ׶Ρ�
    modify->ReadUniqueID(shared_from_this());

    // ��ȡ�������֡�
    auto name = modify->ReadString();

    SetName(name);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(modify);
}

const CoreTools::ObjectSharedPtr CoreTools::Object::GetObjectByName(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (name == m_Name.GetName())
        return ObjectSharedFromThis();
    else
        return ObjectSharedPtr{};
}

const vector<CoreTools::ObjectSharedPtr> CoreTools::Object::GetAllObjectsByName(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    vector<ObjectSharedPtr> objects{};

    if (name == m_Name.GetName())
    {
        objects.emplace_back(ObjectSharedFromThis());
    }

    return objects;
}

const CoreTools::ConstObjectSharedPtr CoreTools::Object::GetConstObjectByName(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (name == m_Name.GetName())
        return ObjectSharedFromThis();
    else
        return ConstObjectSharedPtr{};
}

const vector<CoreTools::ConstObjectSharedPtr> CoreTools::Object::GetAllConstObjectsByName(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    vector<ConstObjectSharedPtr> objects{};

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