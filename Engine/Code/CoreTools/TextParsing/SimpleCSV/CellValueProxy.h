///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:48)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_H
#define CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_H

#include "CoreTools/CoreToolsDll.h"

#include "CellValue.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::CellValueProxyImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::CopyUnsharedImpl<CoreTools::SimpleCSV::CellValueProxy, CoreTools::SimpleCSV::CellValueProxyImpl>;

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE CellValueProxy final
        {
        public:
            COPY_UNSHARED_TYPE_DECLARE(CellValueProxy);
            using CellSharedPtr = std::shared_ptr<Cell>;

        public:
            NODISCARD static CellValueProxy CreateEmpty();
            explicit CellValueProxy(const CellSharedPtr& cell);

        private:
            enum class CellValueProxyCreate
            {
                Init,
            };

        private:
            explicit CellValueProxy(MAYBE_UNUSED CellValueProxyCreate cellValueProxyCreate);

        public:
            CLASS_INVARIANT_DECLARE;

            template <typename T,
                      typename std::enable_if_t<TextParsing::cellValueProxyCondition<T> ||
                                                std::is_same_v<std::decay_t<T>, CoreTools::SimpleCSV::CellValue>>* = nullptr>
            CellValueProxy& operator=(T&& rhs);

            template <typename T,
                      typename std::enable_if_t<TextParsing::cellValueProxyCondition<T> ||
                                                std::is_same_v<std::decay_t<T>, CoreTools::SimpleCSV::CellValue>>* = nullptr>
            void Set(T&& rhs);

            template <typename T, typename std::enable_if_t<TextParsing::cellValueCondition<T>>* = nullptr>
            T Get() const;

            void Clear();
            void SetError();
            NODISCARD ValueType GetType() const;
            NODISCARD std::string GetTypeAsString() const;

            void SetInteger(int64_t numberValue);
            void SetBoolean(bool numberValue);
            void SetFloat(double numberValue);
            void SetString(const std::string& stringValue);

            void SetCellValue(const CellValue& cellValue);

            NODISCARD CellValue GetValue() const;

        private:
            PackageType impl;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_VALUE_PROXY_H