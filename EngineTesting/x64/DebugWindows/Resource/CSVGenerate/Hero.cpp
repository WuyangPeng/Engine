/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#include "Hero.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

CSVConfigure::Hero::Hero(const CoreTools::CSVRow& csvRow)
    : id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      nextID{ csvRow.GetInt(SYSTEM_TEXT("nextID"s)) },
      reward{ csvRow.GetInt(SYSTEM_TEXT("reward"s)) },
      heroName{ csvRow.GetString(SYSTEM_TEXT("heroName"s)) },
      uniqueIdentifier{ csvRow.GetInt64(SYSTEM_TEXT("uniqueIdentifier"s)) },
      position{ csvRow.GetVector4(SYSTEM_TEXT("position"s)) },
      describe{ csvRow.GetCharArray(SYSTEM_TEXT("describe"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, Hero)

int CSVConfigure::Hero::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int CSVConfigure::Hero::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int CSVConfigure::Hero::GetNextID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return nextID;
}

int CSVConfigure::Hero::GetReward() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return reward;
}

System::String CSVConfigure::Hero::GetHeroName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return heroName;
}

int64_t CSVConfigure::Hero::GetUniqueIdentifier() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return uniqueIdentifier;
}

CoreTools::Vector4 CSVConfigure::Hero::GetPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return position;
}

std::vector<System::TChar> CSVConfigure::Hero::GetDescribe() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return describe;
}

int CSVConfigure::Hero::GetDescribeCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(describe.size());
}

System::TChar CSVConfigure::Hero::GetDescribe(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return describe.at(index);
}

std::vector<System::TChar>::const_iterator CSVConfigure::Hero::GetDescribeBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return describe.cbegin();
}

std::vector<System::TChar>::const_iterator CSVConfigure::Hero::GetDescribeEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return describe.cend();
}

