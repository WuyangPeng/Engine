/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_IMPERIAL_COURT_H
#define ANCIENT_BOOKS_IMPERIAL_COURT_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "ImperialCourtBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class ImperialCourt final : public ImperialCourtBase
    {
    public:
        using ClassType = ImperialCourt;
        using ParentType = ImperialCourtBase;

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit ImperialCourt(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD String GetCategory() const override;

        NODISCARD String GetBook() const override;

        NODISCARD int GetBegin() const noexcept override;
        NODISCARD ConstYearSharedPtr GetBegin(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetEnd() const noexcept override;
        NODISCARD ConstYearSharedPtr GetEnd(const AncientBooksContainer& csvContainer) const override;


    private:
        int id;  // Id
        String category;  // ����
        String book;  // ����
        int begin;  // ��ʼ
        int end;  // ����
    };
}

#endif  // ANCIENT_BOOKS_IMPERIAL_COURT_H
