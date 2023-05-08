/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef JSON_CONFIGURE_MONSTERS_H
#define JSON_CONFIGURE_MONSTERS_H

#include "CoreTools/CoreToolsDll.h"

#include "JsonConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace JsonConfigure
{
    class MonstersContainer final
    {
    public:
        using ClassType = MonstersContainer;
        using Test = std::vector<int>;
        using TestConstIter = Test::const_iterator;
        using ConsoleTest = std::vector<System::String>;
        using ConsoleTestConstIter = ConsoleTest::const_iterator;
        using ConstDataSharedPtr = std::shared_ptr<const Monsters::Data>;
        using DataContainer = std::vector<ConstDataSharedPtr>;

    public:
        explicit MonstersContainer(const CoreTools::JsonRow& jsonRow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetSystem() const noexcept;

        NODISCARD int GetCoreTools() const noexcept;

        NODISCARD System::String GetNetwork() const;

        NODISCARD bool IsBoolTest() const noexcept;

        NODISCARD Test GetTest() const;
        NODISCARD int GetTestSize() const;
        NODISCARD TestConstIter GetTestBegin() const noexcept;
        NODISCARD TestConstIter GetTestEnd() const noexcept;

        NODISCARD ConsoleTest GetConsoleTest() const;
        NODISCARD int GetConsoleTestSize() const;
        NODISCARD ConsoleTestConstIter GetConsoleTestBegin() const noexcept;
        NODISCARD ConsoleTestConstIter GetConsoleTestEnd() const noexcept;

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
        int system;
        int coreTools;
        System::String network;
        bool boolTest;
        Test test;
        ConsoleTest consoleTest;
        DataContainer data;
    };

    namespace Monsters
    {
        class Data final
        {
        public:
            using ClassType = Data;
            using ConstElementsSharedPtr = std::shared_ptr<const Elements>;
            using ElementsContainer = std::vector<ConstElementsSharedPtr>;

        public:
            explicit Data(const CoreTools::JsonRow& jsonRow);
            explicit Data(int id) noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD System::String GetName() const;

            NODISCARD int GetId() const noexcept;

            NODISCARD ConstElementsSharedPtr GetFirstElements() const;
            NODISCARD ConstElementsSharedPtr GetElements(int key) const;
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
            using ConstSpawnPositionSharedPtr = std::shared_ptr<const SpawnPosition>;
            using ConstTargetPositionSharedPtr = std::shared_ptr<const TargetPosition>;
            using ConstUserDataSharedPtr = std::shared_ptr<const UserData>;
            using ConstRodeRandomSharedPtr = std::shared_ptr<const RodeRandom>;

        public:
            explicit Elements(const CoreTools::JsonRow& jsonRow);
            explicit Elements(int id) noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetId() const noexcept;

            NODISCARD int GetMoveType() const noexcept;

            NODISCARD double GetSpeedScale() const noexcept;

            NODISCARD ConstDirectionSharedPtr GetDirection() const noexcept;

            NODISCARD ConstScaleSharedPtr GetScale() const noexcept;

            NODISCARD ConstSpawnPositionSharedPtr GetSpawnPosition() const noexcept;

            NODISCARD ConstTargetPositionSharedPtr GetTargetPosition() const noexcept;

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
            ConstSpawnPositionSharedPtr spawnPosition;
            ConstTargetPositionSharedPtr targetPosition;
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

        class SpawnPosition final
        {
        public:
            using ClassType = SpawnPosition;

        public:
            explicit SpawnPosition(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class TargetPosition final
        {
        public:
            using ClassType = TargetPosition;

        public:
            explicit TargetPosition(const CoreTools::JsonRow& jsonRow);

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

#endif  // JSON_CONFIGURE_MONSTERS_H
