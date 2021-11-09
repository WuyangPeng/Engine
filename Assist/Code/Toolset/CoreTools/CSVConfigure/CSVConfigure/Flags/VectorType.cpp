/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

#include "VectorType.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <map>

using std::map;
using namespace std::literals;

CSVConfigure::VectorType CSVConfigure::StringCastVectorType(const System::String& describe)
{
    static map<System::String, VectorType> typeDescribe{ { SYSTEM_TEXT("Two"s), VectorType::Two },
                                                         { SYSTEM_TEXT("Three"s), VectorType::Three },
                                                         { SYSTEM_TEXT("Four"s), VectorType::Four } };

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

System::String CSVConfigure::EnumCastString(VectorType type)
{
    static map<VectorType, System::String> typeDescribe{ { VectorType::Two, SYSTEM_TEXT("Two"s) },
                                                         { VectorType::Three, SYSTEM_TEXT("Three"s) },
                                                         { VectorType::Four, SYSTEM_TEXT("Four"s) } };

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

System::String CSVConfigure::GetEnumDescribe(VectorType type)
{
    static map<VectorType, System::String> typeDescribe{ { VectorType::Two, SYSTEM_TEXT("��ά"s) },
                                                         { VectorType::Three, SYSTEM_TEXT("��ά"s) },
                                                         { VectorType::Four, SYSTEM_TEXT("��ά"s) } };

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

