/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef JSON_CONFIGURE_RUN_SCENES_H
#define JSON_CONFIGURE_RUN_SCENES_H

#include "CoreTools/CoreToolsDll.h"

#include "JsonConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>

namespace JsonConfigure
{
    class RunScenesContainer final
    {
    public:
        using ClassType = RunScenesContainer;
        using ConstDataSharedPtr = std::shared_ptr<const RunScenes::Data>;
        using DataContainer = std::vector<ConstDataSharedPtr>;

    public:
        explicit RunScenesContainer(const CoreTools::JsonRow& jsonRow);

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

    namespace RunScenes
    {
        class Data final
        {
        public:
            using ClassType = Data;
            using ConstNextLinkPositionSharedPtr = std::shared_ptr<const NextLinkPosition>;
            using ConstCenterPositionSharedPtr = std::shared_ptr<const CenterPosition>;
            using ConstBoundsSharedPtr = std::shared_ptr<const Bounds>;
            using BoundsContainer = std::vector<ConstBoundsSharedPtr>;
            using ConstAnchorPositionSharedPtr = std::shared_ptr<const AnchorPosition>;
            using ConstCameraLockSharedPtr = std::shared_ptr<const CameraLock>;
            using ConstTerrainsSharedPtr = std::shared_ptr<const Terrains>;
            using TerrainsContainer = std::vector<ConstTerrainsSharedPtr>;
            using ConstRopeStartSharedPtr = std::shared_ptr<const RopeStart>;

        public:
            explicit Data(const CoreTools::JsonRow& jsonRow);
            explicit Data(int id) noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetId() const noexcept;

            NODISCARD System::String GetName() const;

            NODISCARD ConstNextLinkPositionSharedPtr GetNextLinkPosition() const noexcept;

            NODISCARD ConstCenterPositionSharedPtr GetCenterPosition() const noexcept;

            NODISCARD double GetCheckSize() const noexcept;

            NODISCARD ConstBoundsSharedPtr GetFirstBounds() const;
            NODISCARD ConstBoundsSharedPtr GetBounds(int key) const;
            NODISCARD BoundsContainer GetBoundsContainer() const;

            template <typename Function>
            NODISCARD ConstBoundsSharedPtr GetFirstBounds(Function function) const;

            template <typename Function>
            NODISCARD BoundsContainer GetBounds(Function function) const;

            NODISCARD ConstAnchorPositionSharedPtr GetAnchorPosition() const noexcept;

            NODISCARD ConstCameraLockSharedPtr GetCameraLock() const noexcept;

            NODISCARD int GetMoveGap() const noexcept;

            NODISCARD ConstTerrainsSharedPtr GetFirstTerrains() const;
            NODISCARD ConstTerrainsSharedPtr GetTerrains(int key) const;
            NODISCARD TerrainsContainer GetTerrainsContainer() const;

            template <typename Function>
            NODISCARD ConstTerrainsSharedPtr GetFirstTerrains(Function function) const;

            template <typename Function>
            NODISCARD TerrainsContainer GetTerrains(Function function) const;

            NODISCARD ConstRopeStartSharedPtr GetRopeStart() const noexcept;

        private:
            void Parsing(const CoreTools::JsonRow& jsonRow);

        private:
            int id;
            System::String name;
            ConstNextLinkPositionSharedPtr nextLinkPosition;
            ConstCenterPositionSharedPtr centerPosition;
            double checkSize;
            BoundsContainer bounds;
            ConstAnchorPositionSharedPtr anchorPosition;
            ConstCameraLockSharedPtr cameraLock;
            int moveGap;
            TerrainsContainer terrains;
            ConstRopeStartSharedPtr ropeStart;
        };

        class NextLinkPosition final
        {
        public:
            using ClassType = NextLinkPosition;

        public:
            explicit NextLinkPosition(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class CenterPosition final
        {
        public:
            using ClassType = CenterPosition;

        public:
            explicit CenterPosition(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class Bounds final
        {
        public:
            using ClassType = Bounds;
            using ConstOffsetSharedPtr = std::shared_ptr<const Offset>;
            using ConstSizeSharedPtr = std::shared_ptr<const Size>;

        public:
            explicit Bounds(const CoreTools::JsonRow& jsonRow);
            explicit Bounds(int id) noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetId() const noexcept;

            NODISCARD ConstOffsetSharedPtr GetOffset() const noexcept;

            NODISCARD ConstSizeSharedPtr GetSize() const noexcept;

        private:
            int id;
            ConstOffsetSharedPtr offset;
            ConstSizeSharedPtr size;
        };

        class Offset final
        {
        public:
            using ClassType = Offset;

        public:
            explicit Offset(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class Size final
        {
        public:
            using ClassType = Size;

        public:
            explicit Size(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class AnchorPosition final
        {
        public:
            using ClassType = AnchorPosition;

        public:
            explicit AnchorPosition(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class CameraLock final
        {
        public:
            using ClassType = CameraLock;

        public:
            explicit CameraLock(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class Terrains final
        {
        public:
            using ClassType = Terrains;
            using ConstStartPositionSharedPtr = std::shared_ptr<const StartPosition>;

        public:
            explicit Terrains(const CoreTools::JsonRow& jsonRow);
            explicit Terrains(int id) noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetId() const noexcept;

            NODISCARD int GetType() const noexcept;

            NODISCARD ConstStartPositionSharedPtr GetStartPosition() const noexcept;

            NODISCARD double GetSpeedAdd() const noexcept;

            NODISCARD double GetMoveGap() const noexcept;

            NODISCARD double GetMaxMoveGap() const noexcept;

        private:
            int id;
            int type;
            ConstStartPositionSharedPtr startPosition;
            double speedAdd;
            double moveGap;
            double maxMoveGap;
        };

        class StartPosition final
        {
        public:
            using ClassType = StartPosition;

        public:
            explicit StartPosition(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class RopeStart final
        {
        public:
            using ClassType = RopeStart;

        public:
            explicit RopeStart(const CoreTools::JsonRow& jsonRow);

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

#endif  // JSON_CONFIGURE_RUN_SCENES_H
