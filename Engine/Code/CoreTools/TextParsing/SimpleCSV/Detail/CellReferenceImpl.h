///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:33)

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
            /// @brief �Ե�Ԫ���ַΪ�����Ĺ��캯����
            /// @param cellAddress ��Ԫ��ĵ�ַ������ 'A1'��
            /// @details ���캯�����ַ�������һ���µ�CellReference������ 'A1'�� ���û�����룬Ĭ�����ý��ǵ�Ԫ�� A1��
            explicit CellReferenceImpl(const std::string& cellAddress);

            /// ����Ԫ��������Ϊ�����Ĺ��캯����
            CellReferenceImpl(int row, int column);

            /// ���캯�����кź�����ĸ��Ϊ������
            CellReferenceImpl(int row, const std::string& column);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetRow() const noexcept;
            void SetRow(int row);
            NODISCARD int GetColumn() const noexcept;
            void SetColumn(int column);
            void SetRowAndColumn(int row, int column);

            /// @brief ��ȡ CellReference�ĵ�ַ
            /// @return ��ַ������ 'A1'
            NODISCARD std::string GetAddress() const;

            /// @brief ����CellReference�ĵ�ַ
            /// @param address ��ַ������ 'A1'
            /// @pre ��ַ�����ַ�����������Ч��Excel��Ԫ�����á�������Ϊ��δ����ġ�
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
