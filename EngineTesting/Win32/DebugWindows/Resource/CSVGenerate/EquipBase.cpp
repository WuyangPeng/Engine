/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "EquipBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CSVConfigure::EquipBase::EquipBase(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, EquipBase)

int CSVConfigure::EquipBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int CSVConfigure::EquipBase::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int CSVConfigure::EquipBase::GetNextId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int CSVConfigure::EquipBase::GetReward() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

System::String CSVConfigure::EquipBase::GetEquipName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("equip����಻�����ȡ�ַ�����"s))
}

System::TChar CSVConfigure::EquipBase::GetLogo() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return SYSTEM_TEXT('\0');
}

CoreTools::Vector3 CSVConfigure::EquipBase::GetPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return CoreTools::Vector3{};
}

std::deque<bool> CSVConfigure::EquipBase::GetMask() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("equip����಻�����ȡ���顣"s))
}

int CSVConfigure::EquipBase::GetMaskCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("equip����಻�����ȡ���顣"s))
}

bool CSVConfigure::EquipBase::GetMask(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("equip����಻�����ȡ���顣"s))
}

std::deque<bool>::const_iterator CSVConfigure::EquipBase::GetMaskBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("equip����಻�����ȡ���顣"s))
}

std::deque<bool>::const_iterator CSVConfigure::EquipBase::GetMaskEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("equip����಻�����ȡ���顣"s))
}

int CSVConfigure::EquipBase::GetHeroId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::shared_ptr<const CSVConfigure::Hero> CSVConfigure::EquipBase::GetHeroId(MAYBE_UNUSED const CSVConfigureContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("equip����಻�����ȡӳ��ֵ��"s))
}

