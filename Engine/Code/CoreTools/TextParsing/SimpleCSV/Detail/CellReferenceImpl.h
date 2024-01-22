/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:46)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_REFERENCE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CELL_REFERENCE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

#include <string>
#include <utility>

namespace CoreTools::SimpleCSV
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
        void SetRow(int aRow);
        NODISCARD int GetColumn() const noexcept;
        void SetColumn(int aColumn);
        void SetRowAndColumn(int aRow, int aColumn);

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
        NODISCARD static std::string GetRowAsString(int aRow);
        NODISCARD static int GetRowAsNumber(const std::string& aRow);
        NODISCARD static std::string GetColumnAsString(int aColumn);
        NODISCARD static int GetColumnAsNumber(const std::string& aColumn);
        NODISCARD static Coordinates GetCoordinatesFromAddress(const std::string& address);
        NODISCARD static int GetInScope(int value, int minValue, int maxValue) noexcept;

    private:
        int row;
        int column;
        std::string cellAddress;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_REFERENCE_IMPL_H
