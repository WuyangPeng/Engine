/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#include "Chapter.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

CSVConfigure::Chapter::Chapter(const CoreTools::CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      nextID{ csvRow.GetInt(SYSTEM_TEXT("nextID"s)) },
      reward{ csvRow.GetInt(SYSTEM_TEXT("reward"s)) },
      chapterName{ csvRow.GetString(SYSTEM_TEXT("chapterName"s)) },
      isMain{ csvRow.GetBool(SYSTEM_TEXT("isMain"s)) },
      position{ csvRow.GetVector2(SYSTEM_TEXT("position"s)) },
      point{ csvRow.GetIntVector4(SYSTEM_TEXT("point"s)) }
{
    Checking();

    USER_SELF_CLASS_IS_VALID_1;
}

void CSVConfigure::Chapter::Checking()
{
    if (!((1 <= reward) && (reward < 5)))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("reward 数据校验失败。"s));
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CSVConfigure::Chapter::IsValid() const noexcept
{
    if (ParentType::IsValid() &&
        ((1 <= reward) && (reward < 5)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

int CSVConfigure::Chapter::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return id;
}

int CSVConfigure::Chapter::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return id;
}

int CSVConfigure::Chapter::GetNextID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return nextID;
}

int CSVConfigure::Chapter::GetReward() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return reward;
}

System::String CSVConfigure::Chapter::GetChapterName() const
{
    USER_CLASS_IS_VALID_CONST_1;

    return chapterName;
}

bool CSVConfigure::Chapter::IsMain() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return isMain;
}

CoreTools::Vector2 CSVConfigure::Chapter::GetPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return position;
}

CoreTools::IntVector4 CSVConfigure::Chapter::GetPoint() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return point;
}

