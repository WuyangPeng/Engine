/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_SOURCE_H
#define ANCIENT_BOOKS_SOURCE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "SourceBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Source final : public SourceBase
    {
    public:
        using ClassType = Source;
        using ParentType = SourceBase;

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit Source(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD String GetName() const override;

        NODISCARD int GetSort() const noexcept override;


    private:
        int id;  // Id
        String name;  // ����
        int sort;  // ����
    };
}

#endif  // ANCIENT_BOOKS_SOURCE_H
