/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "ChapterBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CSVConfigure::ChapterBase::ChapterBase(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, ChapterBase)

int CSVConfigure::ChapterBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int CSVConfigure::ChapterBase::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int CSVConfigure::ChapterBase::GetNextId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int CSVConfigure::ChapterBase::GetReward() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

System::String CSVConfigure::ChapterBase::GetChapterName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("chapter����಻�����ȡ�ַ�����"s))
}

bool CSVConfigure::ChapterBase::IsMain() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return false;
}

CoreTools::Vector2 CSVConfigure::ChapterBase::GetPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return CoreTools::Vector2{};
}

CoreTools::IntVector4 CSVConfigure::ChapterBase::GetPoint() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return CoreTools::IntVector4{};
}

