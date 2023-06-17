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

    public:
        explicit Genus(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetCategory() const noexcept override;
        NODISCARD std::shared_ptr<const CategoryMappingType> GetCategory(const AncientBooksContainer& csvContainer) const override;

        NODISCARD System::String GetName() const override;

        NODISCARD int GetFather() const noexcept override;
        NODISCARD std::shared_ptr<const GenusMappingType> GetFather(const AncientBooksContainer& csvContainer) const override;

        NODISCARD System::String GetBegin() const override;

        NODISCARD System::String GetEnd() const override;

    private:
        int id;  // Id
        int category;  // �
        System::String name;  // ����
        int father;  // ���
        System::String begin;  // ��ʼ
        System::String end;  // ����
    };
}

#endif  // ANCIENT_BOOKS_GENUS_H
