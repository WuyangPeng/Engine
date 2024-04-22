/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Equip.h"
#include "CSVConfigureContainer.h"
#include "HeroContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals; 

CSVConfigure::Equip::Equip(const CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      nextId{ csvRow.GetInt(SYSTEM_TEXT("nextId"s)) },
      reward{ csvRow.GetInt(SYSTEM_TEXT("reward"s)) },
      equipName{ csvRow.GetString(SYSTEM_TEXT("equipName"s)) },
      logo{ csvRow.GetChar(SYSTEM_TEXT("logo"s)) },
      position{ csvRow.GetVector3(SYSTEM_TEXT("position"s)) },
      mask{ csvRow.GetBoolArray(SYSTEM_TEXT("mask"s)) },
      heroId{ csvRow.GetInt(SYSTEM_TEXT("heroId"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, Equip)

int CSVConfigure::Equip::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int CSVConfigure::Equip::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int CSVConfigure::Equip::GetNextId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return nextId;
}

int CSVConfigure::Equip::GetReward() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return reward;
}

System::String CSVConfigure::Equip::GetEquipName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return equipName;
}

System::TChar CSVConfigure::Equip::GetLogo() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return logo;
}

CoreTools::Vector3 CSVConfigure::Equip::GetPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return position;
}

CSVConfigure::Equip::BoolContainer CSVConfigure::Equip::GetMask() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return mask;
}

int CSVConfigure::Equip::GetMaskCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(mask.size());
}

bool CSVConfigure::Equip::GetMask(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return mask.at(index);
}

CSVConfigure::Equip::BoolContainerConstIter CSVConfigure::Equip::GetMaskBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return mask.cbegin();
}

CSVConfigure::Equip::BoolContainerConstIter CSVConfigure::Equip::GetMaskEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return mask.cend();
}

int CSVConfigure::Equip::GetHeroId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return heroId;
}

CSVConfigure::Equip::ConstHeroSharedPtr CSVConfigure::Equip::GetHeroId(const CSVConfigureContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetHeroContainer()->GetHero(heroId);
}

