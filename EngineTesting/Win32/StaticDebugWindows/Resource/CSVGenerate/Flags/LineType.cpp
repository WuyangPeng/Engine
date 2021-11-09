/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

#include "LineType.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <map>

using std::map;
using namespace std::literals;

CSVConfigure::LineType CSVConfigure::StringCastLineType(const System::String& describe)
{
    static map<System::String, LineType> typeDescribe{ { SYSTEM_TEXT("Two"s), LineType::Two },
                                                       { SYSTEM_TEXT("Three"s), LineType::Three },
                                                       { SYSTEM_TEXT("Four"s), LineType::Four } };

    const auto iter = typeDescribe.find(describe);

    if (iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ���Ӧ�����͡�"s));
    }
}

System::String CSVConfigure::EnumCastString(LineType type)
{
    static map<LineType, System::String> typeDescribe{ { LineType::Two, SYSTEM_TEXT("Two"s) },
                                                       { LineType::Three, SYSTEM_TEXT("Three"s) },
                                                       { LineType::Four, SYSTEM_TEXT("Four"s) } };

    const auto iter = typeDescribe.find(type);

    if (iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ���Ӧ�����͡�"s));
    }
}

System::String CSVConfigure::GetEnumDescribe(LineType type)
{
    static map<LineType, System::String> typeDescribe{ { LineType::Two, SYSTEM_TEXT("��ά"s) },
                                                       { LineType::Three, SYSTEM_TEXT("��ά"s) },
                                                       { LineType::Four, SYSTEM_TEXT("��ά"s) } };

    const auto iter = typeDescribe.find(type);

    if (iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ���Ӧ�����͡�"s));
    }
}

