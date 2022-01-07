/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#ifndef JSON_CONFIGURE_DUNGON_MONSTERS_H
#define JSON_CONFIGURE_DUNGON_MONSTERS_H

#include "CoreTools/CoreToolsDll.h"

#include "JsonConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace JsonConfigure
{
    class DungonMonstersContainer final
    {
    public:
        using ClassType = DungonMonstersContainer;
        using Test = std::vector<int>;
        using TestConstIter = Test::const_iterator;
        using ConsoleTest = std::vector<System::String>;
        using ConsoleTestConstIter = ConsoleTest::const_iterator;
        using ConstDatasSharedPtr = std::shared_ptr<const DungonMonsters::Datas>;
        using DatasContainer = std::vector<ConstDatasSharedPtr>;

    public:
        explicit DungonMonstersContainer(const CoreTools::JsonRow& jsonRow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetSystem() const noexcept;

        NODISCARD int GetCoreTools() const noexcept;

        NODISCARD System::String GetNetwork() const;

        NODISCARD Test GetTest() const;
        NODISCARD int GetTestSize() const;
        NODISCARD TestConstIter GetTestBegin() const;
        NODISCARD TestConstIter GetTestEnd() const;

        NODISCARD ConsoleTest GetConsoleTest() const;
        NODISCARD int GetConsoleTestSize() const;
        NODISCARD ConsoleTestConstIter GetConsoleTestBegin() const;
        NODISCARD ConsoleTestConstIter GetConsoleTestEnd() const;

        NODISCARD ConstDatasSharedPtr GetFirstDatas() const;
        NODISCARD ConstDatasSharedPtr GetDatas(int id) const;
        NODISCARD DatasContainer GetDatasContainer() const;

        template <typename Function>
        NODISCARD ConstDatasSharedPtr GetFirstDatas(Function function) const;

        template <typename Function>
        NODISCARD DatasContainer GetDatas(Function function) const;

    private:
        void Parsing(const CoreTools::JsonRow& jsonRow);

    private:
        int system;
        int coreTools;
        System::String network;
        Test test;
        ConsoleTest consoleTest;
        DatasContainer datas;
    };

    namespace DungonMonsters
    {
        class Datas final
        {
        public:
            using ClassType = Datas;
            using ConstElementsSharedPtr = std::shared_ptr<const Elements>;
            using ElementsContainer = std::vector<ConstElementsSharedPtr>;

        public:
            explicit Datas(const CoreTools::JsonRow& jsonRow);
            explicit Datas(int id);

            CLASS_INVARIANT_DECLARE;

            NODISCARD System::String GetName() const;

            NODISCARD int GetID() const noexcept;

            NODISCARD ConstElementsSharedPtr GetFirstElements() const;
            NODISCARD ConstElementsSharedPtr GetElements(int id) const;
            NODISCARD ElementsContainer GetElementsContainer() const;

            template <typename Function>
            NODISCARD ConstElementsSharedPtr GetFirstElements(Function function) const;

            template <typename Function>
            NODISCARD ElementsContainer GetElements(Function function) const;

        private:
            void Parsing(const CoreTools::JsonRow& jsonRow);

        private:
            System::String name;
            int id;
            ElementsContainer elements;
        };

        class Elements final
        {
        public:
            using ClassType = Elements;
            using ConstDirectionSharedPtr = std::shared_ptr<const Direction>;
            using ConstScaleSharedPtr = std::shared_ptr<const Scale>;
            using ConstSpawnPosSharedPtr = std::shared_ptr<const SpawnPos>;
            using ConstTargetOffestPosSharedPtr = std::shared_ptr<const TargetOffestPos>;
            using ConstUserDataSharedPtr = std::shared_ptr<const UserData>;
            using ConstRodeRandomSharedPtr = std::shared_ptr<const RodeRandom>;

        public:
            explicit Elements(const CoreTools::JsonRow& jsonRow);
            explicit Elements(int id);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetID() const noexcept;

            NODISCARD int GetMoveType() const noexcept;

            NODISCARD double GetSpeedScale() const noexcept;

            NODISCARD ConstDirectionSharedPtr GetDirection() const noexcept;

            NODISCARD ConstScaleSharedPtr GetScale() const noexcept;

            NODISCARD ConstSpawnPosSharedPtr GetSpawnPos() const noexcept;

            NODISCARD ConstTargetOffestPosSharedPtr GetTargetOffestPos() const noexcept;

            NODISCARD ConstUserDataSharedPtr GetUserData() const noexcept;

            NODISCARD ConstRodeRandomSharedPtr GetRodeRandom() const noexcept;

            NODISCARD int GetExternLevel() const noexcept;

            NODISCARD bool IsUseGravity() const noexcept;

        private:
            int id;
            int moveType;
            double speedScale;
            ConstDirectionSharedPtr direction;
            ConstScaleSharedPtr scale;
            ConstSpawnPosSharedPtr spawnPos;
            ConstTargetOffestPosSharedPtr targetOffestPos;
            ConstUserDataSharedPtr userData;
            ConstRodeRandomSharedPtr rodeRandom;
            int externLevel;
            bool useGravity;
        };

        class Direction final
        {
        public:
            using ClassType = Direction;

        public:
            explicit Direction(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class Scale final
        {
        public:
            using ClassType = Scale;

        public:
            explicit Scale(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class SpawnPos final
        {
        public:
            using ClassType = SpawnPos;

        public:
            explicit SpawnPos(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class TargetOffestPos final
        {
        public:
            using ClassType = TargetOffestPos;

        public:
            explicit TargetOffestPos(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class UserData final
        {
        public:
            using ClassType = UserData;

        public:
            explicit UserData(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

            NODISCARD double GetW() const noexcept;

        private:
            double x;
            double y;
            double z;
            double w;
        };

        class RodeRandom final
        {
        public:
            using ClassType = RodeRandom;

        public:
            explicit RodeRandom(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetX() const noexcept;

            NODISCARD int GetY() const noexcept;

            NODISCARD int GetZ() const noexcept;

        private:
            int x;
            int y;
            int z;
        };

    }
}

#endif  // JSON_CONFIGURE_DUNGON_MONSTERS_H
