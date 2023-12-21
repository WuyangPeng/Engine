/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/13 09:58)

#ifndef RENDERING_RESOURCES_SUITE_STRUCTURED_BUFFER_TESTING_H
#define RENDERING_RESOURCES_SUITE_STRUCTURED_BUFFER_TESTING_H

#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBase.h"

namespace Rendering
{
    class StructuredBufferTesting final : public GraphicsObjectTestingBase
    {
    public:
        using ClassType = StructuredBufferTesting;
        using ParentType = GraphicsObjectTestingBase;

    public:
        explicit StructuredBufferTesting(const OStreamShared& stream);

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

    private:
        static constexpr auto numElements = 5;
        static constexpr auto elementSize = 6;
        static constexpr auto numBytes = numElements * elementSize;
    };
}

#endif  // RENDERING_RESOURCES_SUITE_STRUCTURED_BUFFER_TESTING_H