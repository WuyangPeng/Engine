/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

#include "SkillBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CSVConfigure::SkillBase::SkillBase(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, SkillBase)

int CSVConfigure::SkillBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int CSVConfigure::SkillBase::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int CSVConfigure::SkillBase::GetNextID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int CSVConfigure::SkillBase::GetReward() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

System::String CSVConfigure::SkillBase::GetSkillName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("skill����಻�����ȡ�ַ�����"s));
}

CSVConfigure::VectorType CSVConfigure::SkillBase::GetVectorType() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return CSVConfigure::VectorType{};
}

CoreTools::IntVector3 CSVConfigure::SkillBase::GetPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return CoreTools::IntVector3{};
}

