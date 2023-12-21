/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/15 09:47)

#ifndef RENDERING_RESOURCES_SUITE_INDEX_BUFFER_TESTING_H
#define RENDERING_RESOURCES_SUITE_INDEX_BUFFER_TESTING_H

#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBase.h"

namespace Rendering
{
    class IndexBufferTesting final : public GraphicsObjectTestingBase
    {
    public:
        using ClassType = IndexBufferTesting;
        using ParentType = GraphicsObjectTestingBase;

    public:
        explicit IndexBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        NODISCARD GraphicsObjectSharedPtr Create(const std::string& name, GraphicsObjectType graphicsObjectType) const override;

    private:
        NODISCARD int GetStreamSizeShifting() const noexcept override;

        void DoRunUnitTest() override;

        void MainTest();
        void DefaultTest();
        void CreateStorageTest();
        void ActiveElementTest();
        void StorageTest();
        void PointTest();
        void SegmentTest();
        void TriangleTest();

    private:
        static constexpr auto numPrimitives = 6;
        static constexpr auto indexSize = 5;
        static constexpr auto numBytes = numPrimitives * indexSize;
    };
}

#endif  // RENDERING_RESOURCES_SUITE_INDEX_BUFFER_TESTING_H