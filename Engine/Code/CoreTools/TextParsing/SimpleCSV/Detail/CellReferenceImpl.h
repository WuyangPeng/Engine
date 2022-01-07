///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:33)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_REFERENCE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CELL_REFERENCE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

#include <string>
#include <utility>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE CellReferenceImpl final
        {
        public:
            using ClassType = CellReferenceImpl;

        public:
            /// @brief 以单元格地址为参数的构造函数。
            /// @param cellAddress 单元格的地址，例如 'A1'。
            /// @details 构造函数从字符串创建一个新的CellReference，例如 'A1'。 如果没有输入，默认引用将是单元格 A1。
            explicit CellReferenceImpl(const std::string& cellAddress);

            /// 将单元格坐标作为参数的构造函数。
            CellReferenceImpl(int row, int column);

            /// 构造函数以行号和列字母作为参数。
            CellReferenceImpl(int row, const std::string& column);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetRow() const noexcept;
            void SetRow(int row);
            NODISCARD int GetColumn() const noexcept;
            void SetColumn(int column);
            void SetRowAndColumn(int row, int column);

            /// @brief 获取 CellReference的地址
            /// @return 地址，例如 'A1'
            NODISCARD std::string GetAddress() const;

            /// @brief 设置CellReference的地址
            /// @param address 地址，例如 'A1'
            /// @pre 地址输入字符串必须是有效的Excel单元格引用。否则行为是未定义的。
            void SetAddress(const std::string& address);

        private:
            using Coordinates = std::pair<int, int>;

        private:
            NODISCARD static std::string GetRowAsString(int row);
            NODISCARD static int GetRowAsNumber(const std::string& row);
            NODISCARD static std::string GetColumnAsString(int column);
            NODISCARD static int GetColumnAsNumber(const std::string& column);
            NODISCARD static Coordinates GetCoordinatesFromAddress(const std::string& address);
            NODISCARD static int GetInScope(int value, int minValue, int maxValue) noexcept;

        private:
            int m_Row{ 1 };
            int m_Column{ 1 };
            std::string m_CellAddress{ TextParsing::g_DefaultCellAddress };
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_REFERENCE_IMPL_H
