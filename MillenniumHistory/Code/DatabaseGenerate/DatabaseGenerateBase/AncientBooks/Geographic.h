/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_GEOGRAPHIC_H
#define ANCIENT_BOOKS_GEOGRAPHIC_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "GeographicBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Geographic final : public GeographicBase
    {
    public:
        using ClassType = Geographic;
        using ParentType = GeographicBase;

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit Geographic(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD String GetName() const override;

    private:
        int id;  // Id
        String name;  // ����
    };
}

#endif  // ANCIENT_BOOKS_GEOGRAPHIC_H
