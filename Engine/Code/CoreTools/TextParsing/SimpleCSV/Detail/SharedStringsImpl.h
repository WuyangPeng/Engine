///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:37)

#ifndef CORE_TOOLS_TEXT_PARSING_XML_SHARED_STRINGS_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_XML_SHARED_STRINGS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>
#include <vector>

namespace CoreTools
{
    namespace SimpleCSV
    {
        /// �����װ�˹����ַ�����Excel���
        /// ��Excel�У�������ÿ����Ԫ���а��������ַ��������ǵ�Ԫ������SharedStrings�Ĵ����е���Ŀ��
        /// ��ᵼ���ļ���С����Ϊ�����������ظ����ַ�����
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
}

#endif  // CORE_TOOLS_TEXT_PARSING_XML_SHARED_STRINGS_IMPL_H
