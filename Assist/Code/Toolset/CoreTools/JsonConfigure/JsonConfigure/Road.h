/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef JSON_CONFIGURE_ROAD_H
#define JSON_CONFIGURE_ROAD_H

#include "CoreTools/CoreToolsDll.h"

#include "JsonConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>

namespace JsonConfigure
{
    class RoadContainer final
    {
    public:
        using ClassType = RoadContainer;
        using ConstDataSharedPtr = std::shared_ptr<const Road::Data>;
        using DataContainer = std::vector<ConstDataSharedPtr>;

    public:
        explicit RoadContainer(const CoreTools::JsonRow& jsonRow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstDataSharedPtr GetFirstData() const;
        NODISCARD ConstDataSharedPtr GetData(int key) const;
        NODISCARD DataContainer GetDataContainer() const;

        template <typename Function>
        NODISCARD ConstDataSharedPtr GetFirstData(Function function) const;

        template <typename Function>
        NODISCARD DataContainer GetData(Function function) const;

    private:
        void Parsing(const CoreTools::JsonRow& jsonRow);

    private:
        DataContainer data;
    };

    namespace Road
    {
        class Data final
        {
        public:
            using ClassType = Data;

        public:
            explicit Data(const CoreTools::JsonRow& jsonRow);
            explicit Data(int id) noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetId() const noexcept;

            NODISCARD int GetFile() const noexcept;

            NODISCARD System::String GetName() const;

            NODISCARD int GetPassFlag() const noexcept;

            NODISCARD int GetPassRelation() const noexcept;

        private:
            int id;
            int file;
            System::String name;
            int passFlag;
            int passRelation;
        };

    }
}

#endif  // JSON_CONFIGURE_ROAD_H
