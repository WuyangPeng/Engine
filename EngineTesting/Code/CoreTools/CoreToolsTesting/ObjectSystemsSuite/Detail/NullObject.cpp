///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 14:58)

#include "NullObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(CoreTools, NullObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, NullObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, NullObject);

CoreTools::NullObject::NullObject(MAYBE_UNUSED DisableNotThrow disableNotThrow) noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::NullObject::NullObject(LoadConstructor value)
    : ParentType{ value }
{
    DisableNoexcept();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NullObject);

int CoreTools::NullObject::GetStreamingSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    // RTTI��
    auto size = CORE_TOOLS_STREAM_SIZE(GetRttiType().GetName());

    // UniqueID
    size += CORE_TOOLS_STREAM_SIZE(this);

    return size;
}

uint64_t CoreTools::NullObject::Register(ObjectRegister& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return target.RegisterRoot(shared_from_this());
}

void CoreTools::NullObject::Save(BufferTarget& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    target.Write(GetRttiType().GetName());

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void CoreTools::NullObject::Link(MAYBE_UNUSED ObjectLink& source)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    DisableNoexcept();
}

void CoreTools::NullObject::PostLink()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    DisableNoexcept();
}

void CoreTools::NullObject::Load(MAYBE_UNUSED BufferSource& source)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    // RTTI���Ѿ������ж�ȡ���Բ�����ȷ�Ķ�����غ�����

    // ��ȡ�Ķ����Ψһ��ʶ�������ṩ��Ϣ�����ӽ׶Ρ�

    source.ReadUniqueID(*this);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr CoreTools::NullObject::CloneObject() const
{
    return std::make_shared<ClassType>(*this);
}
