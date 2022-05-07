/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

#ifndef C_S_V_CONFIGURE_HERO_CONTAINER_H
#define C_S_V_CONFIGURE_HERO_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <map>
#include <memory>
#include <vector>

namespace CSVConfigure
{
    class HeroContainer final
    {
    public:
        using ClassType = HeroContainer;
        using ConstHeroSharedPtr = std::shared_ptr<const Hero>;
        using MappingContainer = std::map<int, ConstHeroSharedPtr>;
        using Container = std::vector<ConstHeroSharedPtr>;

    public:
        explicit HeroContainer(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstHeroSharedPtr GetFirstHero() const;
        NODISCARD ConstHeroSharedPtr GetHero(int key) const;
        NODISCARD MappingContainer GetContainer() const;

        template <typename Function>
        NODISCARD ConstHeroSharedPtr GetFirstHero(Function function) const;

        template <typename Function>
        NODISCARD Container GetHero(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        MappingContainer hero;
    };
}

#endif  // C_S_V_CONFIGURE_HERO_CONTAINER_H