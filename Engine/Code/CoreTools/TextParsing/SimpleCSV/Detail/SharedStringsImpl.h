///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 14:55)

#ifndef CORE_TOOLS_TEXT_PARSING_XML_SHARED_STRINGS_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_XML_SHARED_STRINGS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>
#include <vector>

/// �����װ�˹����ַ�����Excel���
/// ��Excel�У�������ÿ����Ԫ���а��������ַ��������ǵ�Ԫ������SharedStrings�Ĵ����е���Ŀ��
/// ��ᵼ���ļ���С����Ϊ�����������ظ����ַ�����
namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE SharedStringsImpl final
    {
    public:
        using ClassType = SharedStringsImpl;

    public:
        SharedStringsImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetStringIndex(const std::string& str) const;
        NODISCARD bool IsStringExists(const std::string& str) const;
        NODISCARD bool IsStringExists(int index) const;
        NODISCARD const std::string& GetString(int index) const;
        int AppendString(const std::string& str);

        void ClearString(int index);

    private:
        using CacheType = std::vector<std::string>;

    private:
        NODISCARD auto Find(const std::string& str) const;

    private:
        CacheType stringCache;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_XML_SHARED_STRINGS_IMPL_H
