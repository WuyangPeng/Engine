/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_IDENTITY_H
#define ANCIENT_BOOKS_IDENTITY_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "IdentityBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Identity final : public IdentityBase
    {
    public:
        using ClassType = Identity;
        using ParentType = IdentityBase;

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit Identity(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD String GetIdentity() const override;


    private:
        int id;  // Id
        String identity;  // ����
    };
}

#endif  // ANCIENT_BOOKS_IDENTITY_H
