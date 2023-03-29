/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef JSON_CONFIGURE_PARTS_H
#define JSON_CONFIGURE_PARTS_H

#include "CoreTools/CoreToolsDll.h"

#include "JsonConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>

namespace JsonConfigure
{
    class PartsContainer final
    {
    public:
        using ClassType = PartsContainer;
        using ConstDataSharedPtr = std::shared_ptr<const Parts::Data>;
        using DataContainer = std::vector<ConstDataSharedPtr>;

    public:
        explicit PartsContainer(const CoreTools::JsonRow& jsonRow);

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

    namespace Parts
    {
        class Data final
        {
        public:
            using ClassType = Data;
            using ConstScenesSharedPtr = std::shared_ptr<const Scenes>;
            using ScenesContainer = std::vector<ConstScenesSharedPtr>;

        public:
            explicit Data(const CoreTools::JsonRow& jsonRow);
            explicit Data(int id) noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetId() const noexcept;

            NODISCARD System::String GetName() const;

            NODISCARD ConstScenesSharedPtr GetFirstScenes() const;
            NODISCARD ConstScenesSharedPtr GetScenes(int key) const;
            NODISCARD ScenesContainer GetScenesContainer() const;

            template <typename Function>
            NODISCARD ConstScenesSharedPtr GetFirstScenes(Function function) const;

            template <typename Function>
            NODISCARD ScenesContainer GetScenes(Function function) const;

            NODISCARD int GetPassFlag() const noexcept;

            NODISCARD int GetPassEvent() const noexcept;

            NODISCARD double GetRunSpeedScale() const noexcept;

            NODISCARD int GetLoop() const noexcept;

        private:
            void Parsing(const CoreTools::JsonRow& jsonRow);

        private:
            int id;
            System::String name;
            ScenesContainer scenes;
            int passFlag;
            int passEvent;
            double runSpeedScale;
            int loop;
        };

        class Scenes final
        {
        public:
            using ClassType = Scenes;
            using ConstNextPositionSharedPtr = std::shared_ptr<const NextPosition>;
            using ConstUpSharedPtr = std::shared_ptr<const Up>;

        public:
            explicit Scenes(const CoreTools::JsonRow& jsonRow);
            explicit Scenes(int id) noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetId() const noexcept;

            NODISCARD ConstNextPositionSharedPtr GetNextPosition() const noexcept;

            NODISCARD ConstUpSharedPtr GetUp() const noexcept;

        private:
            int id;
            ConstNextPositionSharedPtr nextPosition;
            ConstUpSharedPtr up;
        };

        class NextPosition final
        {
        public:
            using ClassType = NextPosition;

        public:
            explicit NextPosition(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class Up final
        {
        public:
            using ClassType = Up;

        public:
            explicit Up(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

    }
}

#endif  // JSON_CONFIGURE_PARTS_H
