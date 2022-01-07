/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#ifndef JSON_CONFIGURE_DUNGON_PARTS_H
#define JSON_CONFIGURE_DUNGON_PARTS_H

#include "CoreTools/CoreToolsDll.h"

#include "JsonConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>

namespace JsonConfigure
{
    class DungonPartsContainer final
    {
    public:
        using ClassType = DungonPartsContainer;
        using ConstDatasSharedPtr = std::shared_ptr<const DungonParts::Datas>;
        using DatasContainer = std::vector<ConstDatasSharedPtr>;

    public:
        explicit DungonPartsContainer(const CoreTools::JsonRow& jsonRow);

        CLASS_INVARIANT_DECLARE;

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
        DatasContainer datas;
    };

    namespace DungonParts
    {
        class Datas final
        {
        public:
            using ClassType = Datas;
            using ConstScenesSharedPtr = std::shared_ptr<const Scenes>;
            using ScenesContainer = std::vector<ConstScenesSharedPtr>;
            using ConstGroupsSharedPtr = std::shared_ptr<const Groups>;
            using GroupsContainer = std::vector<ConstGroupsSharedPtr>;
            using ConstPassParamsSharedPtr = std::shared_ptr<const PassParams>;
            using PassParamsContainer = std::vector<ConstPassParamsSharedPtr>;

        public:
            explicit Datas(const CoreTools::JsonRow& jsonRow);
            explicit Datas(int id);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetID() const noexcept;

            NODISCARD System::String GetName() const;

            NODISCARD ConstScenesSharedPtr GetFirstScenes() const;
            NODISCARD ConstScenesSharedPtr GetScenes(int id) const;
            NODISCARD ScenesContainer GetScenesContainer() const;

            template <typename Function>
            NODISCARD ConstScenesSharedPtr GetFirstScenes(Function function) const;

            template <typename Function>
            NODISCARD ScenesContainer GetScenes(Function function) const;

            NODISCARD ConstGroupsSharedPtr GetFirstGroups() const;
            NODISCARD ConstGroupsSharedPtr GetGroups(int id) const;
            NODISCARD GroupsContainer GetGroupsContainer() const;

            template <typename Function>
            NODISCARD ConstGroupsSharedPtr GetFirstGroups(Function function) const;

            template <typename Function>
            NODISCARD GroupsContainer GetGroups(Function function) const;

            NODISCARD int GetPassFlag() const noexcept;

            NODISCARD ConstPassParamsSharedPtr GetFirstPassParams() const;
            NODISCARD ConstPassParamsSharedPtr GetPassParams(int id) const;
            NODISCARD PassParamsContainer GetPassParamsContainer() const;

            template <typename Function>
            NODISCARD ConstPassParamsSharedPtr GetFirstPassParams(Function function) const;

            template <typename Function>
            NODISCARD PassParamsContainer GetPassParams(Function function) const;

            NODISCARD int GetPassEvent() const noexcept;

            NODISCARD double GetRunSpeedSacle() const noexcept;

            NODISCARD int GetLoop() const noexcept;

        private:
            void Parsing(const CoreTools::JsonRow& jsonRow);

        private:
            int id;
            System::String name;
            ScenesContainer scenes;
            GroupsContainer groups;
            int passFlag;
            PassParamsContainer passParams;
            int passEvent;
            double runSpeedSacle;
            int loop;
        };

        class Scenes final
        {
        public:
            using ClassType = Scenes;
            using ConstNextPosSharedPtr = std::shared_ptr<const NextPos>;
            using ConstUpSharedPtr = std::shared_ptr<const Up>;

        public:
            explicit Scenes(const CoreTools::JsonRow& jsonRow);
            explicit Scenes(int id);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetID() const noexcept;

            NODISCARD ConstNextPosSharedPtr GetNextPos() const noexcept;

            NODISCARD ConstUpSharedPtr GetUp() const noexcept;

        private:
            int id;
            ConstNextPosSharedPtr nextPos;
            ConstUpSharedPtr up;
        };

        class NextPos final
        {
        public:
            using ClassType = NextPos;

        public:
            explicit NextPos(const CoreTools::JsonRow& jsonRow);

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

        class Groups final
        {
        public:
            using ClassType = Groups;
            using ConstElementsSharedPtr = std::shared_ptr<const Elements>;
            using ElementsContainer = std::vector<ConstElementsSharedPtr>;
            using ConstElementsSharedPtr = std::shared_ptr<const Elements>;
            using ElementsContainer = std::vector<ConstElementsSharedPtr>;
            using ConstElementsSharedPtr = std::shared_ptr<const Elements>;
            using ElementsContainer = std::vector<ConstElementsSharedPtr>;
            using ConstElementsSharedPtr = std::shared_ptr<const Elements>;
            using ElementsContainer = std::vector<ConstElementsSharedPtr>;

        public:
            explicit Groups(const CoreTools::JsonRow& jsonRow);
            explicit Groups(int id);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetWeight() const noexcept;

            NODISCARD int GetCount() const noexcept;

            NODISCARD bool IsMust() const noexcept;

            NODISCARD ConstElementsSharedPtr GetFirstElements() const;
            NODISCARD ConstElementsSharedPtr GetElements(int id) const;
            NODISCARD ElementsContainer GetElementsContainer() const;

            template <typename Function>
            NODISCARD ConstElementsSharedPtr GetFirstElements(Function function) const;

            template <typename Function>
            NODISCARD ElementsContainer GetElements(Function function) const;

            NODISCARD ConstElementsSharedPtr GetFirstElements() const;
            NODISCARD ConstElementsSharedPtr GetElements(int id) const;
            NODISCARD ElementsContainer GetElementsContainer() const;

            template <typename Function>
            NODISCARD ConstElementsSharedPtr GetFirstElements(Function function) const;

            template <typename Function>
            NODISCARD ElementsContainer GetElements(Function function) const;

            NODISCARD ConstElementsSharedPtr GetFirstElements() const;
            NODISCARD ConstElementsSharedPtr GetElements(int id) const;
            NODISCARD ElementsContainer GetElementsContainer() const;

            template <typename Function>
            NODISCARD ConstElementsSharedPtr GetFirstElements(Function function) const;

            template <typename Function>
            NODISCARD ElementsContainer GetElements(Function function) const;

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
            int weight;
            int count;
            bool must;
            ElementsContainer elements;
            ElementsContainer elements;
            ElementsContainer elements;
            ElementsContainer elements;
        };

        class Elements final
        {
        public:
            using ClassType = Elements;
            using ConstOffsetSharedPtr = std::shared_ptr<const Offset>;
            using ConstElementSharedPtr = std::shared_ptr<const Element>;

        public:
            explicit Elements(const CoreTools::JsonRow& jsonRow);
            explicit Elements(int id);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetID() const noexcept;

            NODISCARD ConstOffsetSharedPtr GetOffset() const noexcept;

            NODISCARD int GetCount() const noexcept;

            NODISCARD bool IsMust() const noexcept;

            NODISCARD int GetWeight() const noexcept;

            NODISCARD ConstElementSharedPtr GetElement() const noexcept;

        private:
            int id;
            ConstOffsetSharedPtr offset;
            int count;
            bool must;
            int weight;
            ConstElementSharedPtr element;
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

        class Element final
        {
        public:
            using ClassType = Element;
            using ConstSharedPtr = std::shared_ptr<const >;

        public:
            explicit Element(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD System::String GetName() const;

            NODISCARD int GetID() const noexcept;

            NODISCARD ConstSharedPtr Get() const noexcept;

        private:
            System::String name;
            int id;
            ConstSharedPtr ;
        };

        class Elements final
        {
        public:
            using ClassType = Elements;
            using ConstPositionSharedPtr = std::shared_ptr<const Position>;
            using ConstEulerAngleSharedPtr = std::shared_ptr<const EulerAngle>;
            using ConstTransferSharedPtr = std::shared_ptr<const Transfer>;

        public:
            explicit Elements(const CoreTools::JsonRow& jsonRow);
            explicit Elements(int id);

            CLASS_INVARIANT_DECLARE;

            NODISCARD ConstPositionSharedPtr GetPosition() const noexcept;

            NODISCARD ConstEulerAngleSharedPtr GetEulerAngle() const noexcept;

            NODISCARD ConstTransferSharedPtr GetTransfer() const noexcept;

            NODISCARD int GetID() const noexcept;

            NODISCARD double GetTargetRadius() const noexcept;

            NODISCARD bool IsTerrainY() const noexcept;

        private:
            ConstPositionSharedPtr position;
            ConstEulerAngleSharedPtr eulerAngle;
            ConstTransferSharedPtr transfer;
            int id;
            double targetRadius;
            bool terrainY;
        };

        class Position final
        {
        public:
            using ClassType = Position;

        public:
            explicit Position(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class EulerAngle final
        {
        public:
            using ClassType = EulerAngle;

        public:
            explicit EulerAngle(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class Transfer final
        {
        public:
            using ClassType = Transfer;

        public:
            explicit Transfer(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

            NODISCARD int GetSerializedVersion() const noexcept;

            NODISCARD int GetPreInfinity() const noexcept;

            NODISCARD int GetPostInfinity() const noexcept;

            NODISCARD int GetRotationOrder() const noexcept;

        private:
            double x;
            double y;
            double x;
            double y;
            double z;
            double x;
            double y;
            double z;
            double x;
            double y;
            double z;
            int serializedVersion;
            int preInfinity;
            int postInfinity;
            int rotationOrder;
        };

        class SpeedDelta final
        {
        public:
            using ClassType = SpeedDelta;

        public:
            explicit SpeedDelta(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

        private:
            double x;
            double y;
        };

        class TransferEnd final
        {
        public:
            using ClassType = TransferEnd;

        public:
            explicit TransferEnd(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class TransferTanOut final
        {
        public:
            using ClassType = TransferTanOut;

        public:
            explicit TransferTanOut(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class TransferTanIn final
        {
        public:
            using ClassType = TransferTanIn;

        public:
            explicit TransferTanIn(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class Speed final
        {
        public:
            using ClassType = Speed;

        public:
            explicit Speed(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetSerializedVersion() const noexcept;

            NODISCARD int GetPreInfinity() const noexcept;

            NODISCARD int GetPostInfinity() const noexcept;

            NODISCARD int GetRotationOrder() const noexcept;

        private:
            int serializedVersion;
            int preInfinity;
            int postInfinity;
            int rotationOrder;
        };

        class Elements final
        {
        public:
            using ClassType = Elements;
            using ConstOffsetSharedPtr = std::shared_ptr<const Offset>;
            using ConstElementSharedPtr = std::shared_ptr<const Element>;

        public:
            explicit Elements(const CoreTools::JsonRow& jsonRow);
            explicit Elements(int id);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetID() const noexcept;

            NODISCARD ConstOffsetSharedPtr GetOffset() const noexcept;

            NODISCARD int GetCount() const noexcept;

            NODISCARD bool IsMust() const noexcept;

            NODISCARD int GetWeight() const noexcept;

            NODISCARD ConstElementSharedPtr GetElement() const noexcept;

        private:
            int id;
            ConstOffsetSharedPtr offset;
            int count;
            bool must;
            int weight;
            ConstElementSharedPtr element;
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

        class Element final
        {
        public:
            using ClassType = Element;

        public:
            explicit Element(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetID() const noexcept;

        private:
            int id;
        };

        class Elements final
        {
        public:
            using ClassType = Elements;
            using ConstOffsetSharedPtr = std::shared_ptr<const Offset>;
            using ConstElementSharedPtr = std::shared_ptr<const Element>;

        public:
            explicit Elements(const CoreTools::JsonRow& jsonRow);
            explicit Elements(int id);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetID() const noexcept;

            NODISCARD ConstOffsetSharedPtr GetOffset() const noexcept;

            NODISCARD int GetCount() const noexcept;

            NODISCARD bool IsMust() const noexcept;

            NODISCARD int GetWeight() const noexcept;

            NODISCARD ConstElementSharedPtr GetElement() const noexcept;

        private:
            int id;
            ConstOffsetSharedPtr offset;
            int count;
            bool must;
            int weight;
            ConstElementSharedPtr element;
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

        class Element final
        {
        public:
            using ClassType = Element;
            using ConstSharedPtr = std::shared_ptr<const >;

        public:
            explicit Element(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD System::String GetName() const;

            NODISCARD int GetID() const noexcept;

            NODISCARD ConstSharedPtr Get() const noexcept;

        private:
            System::String name;
            int id;
            ConstSharedPtr ;
        };

        class Elements final
        {
        public:
            using ClassType = Elements;
            using ConstPositionSharedPtr = std::shared_ptr<const Position>;
            using ConstEulerAngleSharedPtr = std::shared_ptr<const EulerAngle>;
            using ConstTransferSharedPtr = std::shared_ptr<const Transfer>;

        public:
            explicit Elements(const CoreTools::JsonRow& jsonRow);
            explicit Elements(int id);

            CLASS_INVARIANT_DECLARE;

            NODISCARD ConstPositionSharedPtr GetPosition() const noexcept;

            NODISCARD ConstEulerAngleSharedPtr GetEulerAngle() const noexcept;

            NODISCARD ConstTransferSharedPtr GetTransfer() const noexcept;

            NODISCARD int GetID() const noexcept;

            NODISCARD double GetTargetRadius() const noexcept;

            NODISCARD bool IsTerrainY() const noexcept;

        private:
            ConstPositionSharedPtr position;
            ConstEulerAngleSharedPtr eulerAngle;
            ConstTransferSharedPtr transfer;
            int id;
            double targetRadius;
            bool terrainY;
        };

        class Position final
        {
        public:
            using ClassType = Position;

        public:
            explicit Position(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class EulerAngle final
        {
        public:
            using ClassType = EulerAngle;

        public:
            explicit EulerAngle(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class Transfer final
        {
        public:
            using ClassType = Transfer;

        public:
            explicit Transfer(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

            NODISCARD int GetSerializedVersion() const noexcept;

            NODISCARD int GetPreInfinity() const noexcept;

            NODISCARD int GetPostInfinity() const noexcept;

            NODISCARD int GetRotationOrder() const noexcept;

        private:
            double x;
            double y;
            double x;
            double y;
            double z;
            double x;
            double y;
            double z;
            double x;
            double y;
            double z;
            int serializedVersion;
            int preInfinity;
            int postInfinity;
            int rotationOrder;
        };

        class SpeedDelta final
        {
        public:
            using ClassType = SpeedDelta;

        public:
            explicit SpeedDelta(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

        private:
            double x;
            double y;
        };

        class TransferEnd final
        {
        public:
            using ClassType = TransferEnd;

        public:
            explicit TransferEnd(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class TransferTanOut final
        {
        public:
            using ClassType = TransferTanOut;

        public:
            explicit TransferTanOut(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class TransferTanIn final
        {
        public:
            using ClassType = TransferTanIn;

        public:
            explicit TransferTanIn(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class Speed final
        {
        public:
            using ClassType = Speed;

        public:
            explicit Speed(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetSerializedVersion() const noexcept;

            NODISCARD int GetPreInfinity() const noexcept;

            NODISCARD int GetPostInfinity() const noexcept;

            NODISCARD int GetRotationOrder() const noexcept;

        private:
            int serializedVersion;
            int preInfinity;
            int postInfinity;
            int rotationOrder;
        };

        class Elements final
        {
        public:
            using ClassType = Elements;
            using ConstOffsetSharedPtr = std::shared_ptr<const Offset>;
            using ConstElementSharedPtr = std::shared_ptr<const Element>;

        public:
            explicit Elements(const CoreTools::JsonRow& jsonRow);
            explicit Elements(int id);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetID() const noexcept;

            NODISCARD ConstOffsetSharedPtr GetOffset() const noexcept;

            NODISCARD int GetCount() const noexcept;

            NODISCARD bool IsMust() const noexcept;

            NODISCARD int GetWeight() const noexcept;

            NODISCARD ConstElementSharedPtr GetElement() const noexcept;

        private:
            int id;
            ConstOffsetSharedPtr offset;
            int count;
            bool must;
            int weight;
            ConstElementSharedPtr element;
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

        class Element final
        {
        public:
            using ClassType = Element;
            using ConstSharedPtr = std::shared_ptr<const >;

        public:
            explicit Element(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD System::String GetName() const;

            NODISCARD int GetID() const noexcept;

            NODISCARD ConstSharedPtr Get() const noexcept;

        private:
            System::String name;
            int id;
            ConstSharedPtr ;
        };

        class Elements final
        {
        public:
            using ClassType = Elements;
            using ConstPositionSharedPtr = std::shared_ptr<const Position>;
            using ConstEulerAngleSharedPtr = std::shared_ptr<const EulerAngle>;
            using ConstTransferSharedPtr = std::shared_ptr<const Transfer>;

        public:
            explicit Elements(const CoreTools::JsonRow& jsonRow);
            explicit Elements(int id);

            CLASS_INVARIANT_DECLARE;

            NODISCARD ConstPositionSharedPtr GetPosition() const noexcept;

            NODISCARD ConstEulerAngleSharedPtr GetEulerAngle() const noexcept;

            NODISCARD ConstTransferSharedPtr GetTransfer() const noexcept;

            NODISCARD int GetID() const noexcept;

            NODISCARD double GetTargetRadius() const noexcept;

            NODISCARD bool IsTerrainY() const noexcept;

        private:
            ConstPositionSharedPtr position;
            ConstEulerAngleSharedPtr eulerAngle;
            ConstTransferSharedPtr transfer;
            int id;
            double targetRadius;
            bool terrainY;
        };

        class Position final
        {
        public:
            using ClassType = Position;

        public:
            explicit Position(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class EulerAngle final
        {
        public:
            using ClassType = EulerAngle;

        public:
            explicit EulerAngle(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class Transfer final
        {
        public:
            using ClassType = Transfer;

        public:
            explicit Transfer(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

            NODISCARD int GetSerializedVersion() const noexcept;

            NODISCARD int GetPreInfinity() const noexcept;

            NODISCARD int GetPostInfinity() const noexcept;

            NODISCARD int GetRotationOrder() const noexcept;

        private:
            double x;
            double y;
            double x;
            double y;
            double z;
            double x;
            double y;
            double z;
            double x;
            double y;
            double z;
            int serializedVersion;
            int preInfinity;
            int postInfinity;
            int rotationOrder;
        };

        class SpeedDelta final
        {
        public:
            using ClassType = SpeedDelta;

        public:
            explicit SpeedDelta(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

        private:
            double x;
            double y;
        };

        class TransferEnd final
        {
        public:
            using ClassType = TransferEnd;

        public:
            explicit TransferEnd(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class TransferTanOut final
        {
        public:
            using ClassType = TransferTanOut;

        public:
            explicit TransferTanOut(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class TransferTanIn final
        {
        public:
            using ClassType = TransferTanIn;

        public:
            explicit TransferTanIn(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD double GetX() const noexcept;

            NODISCARD double GetY() const noexcept;

            NODISCARD double GetZ() const noexcept;

        private:
            double x;
            double y;
            double z;
        };

        class Speed final
        {
        public:
            using ClassType = Speed;

        public:
            explicit Speed(const CoreTools::JsonRow& jsonRow);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetSerializedVersion() const noexcept;

            NODISCARD int GetPreInfinity() const noexcept;

            NODISCARD int GetPostInfinity() const noexcept;

            NODISCARD int GetRotationOrder() const noexcept;

        private:
            int serializedVersion;
            int preInfinity;
            int postInfinity;
            int rotationOrder;
        };

        class PassParams final
        {
        public:
            using ClassType = PassParams;

        public:
            explicit PassParams(const CoreTools::JsonRow& jsonRow);
            explicit PassParams(int id);

            CLASS_INVARIANT_DECLARE;

        private:
        };

    }
}

#endif  // JSON_CONFIGURE_DUNGON_PARTS_H
