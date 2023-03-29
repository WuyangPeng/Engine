/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef JSON_CONFIGURE_JSON_CONFIGURE_CONTAINER_H
#define JSON_CONFIGURE_JSON_CONFIGURE_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "JsonConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>

namespace JsonConfigure
{
    class JsonConfigureContainer final
    {
    public:
        using ClassType = JsonConfigureContainer;

    public:
        explicit JsonConfigureContainer(const System::String& directory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::shared_ptr<const MonstersContainer> GetMonstersContainer() const noexcept;
        NODISCARD std::shared_ptr<const PartsContainer> GetPartsContainer() const noexcept;
        NODISCARD std::shared_ptr<const RoadContainer> GetRoadContainer() const noexcept;
        NODISCARD std::shared_ptr<const RunScenesContainer> GetRunScenesContainer() const noexcept;

    private:
        void Parsing(const System::String& directory);
        void Verify() const;

    private:
        std::shared_ptr<const MonstersContainer> monstersContainer;
        std::shared_ptr<const PartsContainer> partsContainer;
        std::shared_ptr<const RoadContainer> roadContainer;
        std::shared_ptr<const RunScenesContainer> runScenesContainer;
    };
}

#endif  // JSON_CONFIGURE_CONTAINER_H
