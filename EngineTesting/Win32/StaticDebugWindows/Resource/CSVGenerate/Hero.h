/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef C_S_V_CONFIGURE_HERO_H
#define C_S_V_CONFIGURE_HERO_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Data/Vector4.h"

#include <vector>


namespace CSVConfigure
{
    class Hero final
    {
    public:
        using ClassType = Hero;

        using CSVRow = CoreTools::CSVRow;
        using String = System::String;
        using Char = System::TChar;
        using CharContainer = std::vector<Char>;
        using CharContainerConstIter = CharContainer::const_iterator;

    public:
        explicit Hero(const CSVRow& csvRow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetKey() const noexcept;

        NODISCARD int GetId() const noexcept;

        NODISCARD int GetNextId() const noexcept;

        NODISCARD int GetReward() const noexcept;

        NODISCARD String GetHeroName() const;

        NODISCARD int64_t GetUniqueIdentifier() const noexcept;

        NODISCARD CoreTools::Vector4 GetPosition() const noexcept;

        NODISCARD CharContainer GetDescribe() const;
        NODISCARD int GetDescribeCount() const;
        NODISCARD System::TChar GetDescribe(int index) const;
        NODISCARD CharContainerConstIter GetDescribeBegin() const noexcept;
        NODISCARD CharContainerConstIter GetDescribeEnd() const noexcept;

    private:
        int id;  // Id
        int nextId;  // ��һ��Id
        int reward;  // ���ؽ���
        String heroName;  // Ӣ������
        int64_t uniqueIdentifier;  // Ψһ��ʶ��
        CoreTools::Vector4 position;  // λ��
        CharContainer describe;  // ����
    };
}

#endif  // C_S_V_CONFIGURE_HERO_H
