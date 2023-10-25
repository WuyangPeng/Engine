/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_GENUS_H
#define ANCIENT_BOOKS_GENUS_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "GenusBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Genus final : public GenusBase
    {
    public:
        using ClassType = Genus;
        using ParentType = GenusBase;

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit Genus(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetCategory() const noexcept override;
        NODISCARD ConstCategorySharedPtr GetCategory(const AncientBooksContainer& csvContainer) const override;

        NODISCARD String GetName() const override;

        NODISCARD int GetFather() const noexcept override;
        NODISCARD ConstGenusSharedPtr GetFather(const AncientBooksContainer& csvContainer) const override;

        NODISCARD String GetBegin() const override;

        NODISCARD String GetEnd() const override;


    private:
        int id;  // Id
        int category;  // �
        String name;  // ����
        int father;  // ���
        String begin;  // ��ʼ
        String end;  // ����
    };
}

#endif  // ANCIENT_BOOKS_GENUS_H
