///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:37)

#ifndef CORE_TOOLS_TEXT_PARSING_XML_SHARED_STRINGS_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_XML_SHARED_STRINGS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>
#include <vector>

namespace CoreTools
{
    namespace SimpleCSV
    {
        /// 此类封装了共享字符串的Excel概念。
        /// 在Excel中，不是在每个单元格中包含单个字符串，而是单元格引用SharedStrings寄存器中的条目。
        /// 这会导致文件变小，因为很容易引用重复的字符串。
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
