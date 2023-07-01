/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

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

    THROW_EXCEPTION(SYSTEM_TEXT("equip表基类不允许获取字符串。"s))
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

CSVConfigure::EquipBase::BoolContainer CSVConfigure::EquipBase::GetMask() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("equip表基类不允许获取数组。"s))
}

int CSVConfigure::EquipBase::GetMaskCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("equip表基类不允许获取数组。"s))
}

bool CSVConfigure::EquipBase::GetMask(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("equip表基类不允许获取数组。"s))
}

CSVConfigure::EquipBase::BoolContainerConstIter CSVConfigure::EquipBase::GetMaskBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("equip表基类不允许获取数组。"s))
}

CSVConfigure::EquipBase::BoolContainerConstIter CSVConfigure::EquipBase::GetMaskEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("equip表基类不允许获取数组。"s))
}

int CSVConfigure::EquipBase::GetHeroId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

CSVConfigure::EquipBase::ConstHeroSharedPtr CSVConfigure::EquipBase::GetHeroId(const CSVConfigureContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("equip表基类不允许获取映射值。"s))
}

