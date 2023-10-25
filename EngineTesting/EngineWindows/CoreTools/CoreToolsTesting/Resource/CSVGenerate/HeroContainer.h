/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

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

        using ConstHeroSharedPtr = std::shared_ptr<const HeroMappingType>;
        using MappingContainer = std::map<int, ConstHeroSharedPtr>;
        using Container = std::vector<ConstHeroSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit HeroContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstHeroSharedPtr GetFirstHero() const;
        NODISCARD ConstHeroSharedPtr GetHero(int key) const;
        NODISCARD MappingContainer GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstHeroSharedPtr GetFirstHero(Function function) const;

        template <typename Function>
        NODISCARD Container GetHero(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);

    private:
        MappingContainer hero;
    };
}

#endif  // C_S_V_CONFIGURE_HERO_CONTAINER_H
