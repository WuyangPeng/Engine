/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/12 19:17)

#ifndef RENDERING_RESOURCES_SUITE_VERTEX_BUFFER_TESTING_H
#define RENDERING_RESOURCES_SUITE_VERTEX_BUFFER_TESTING_H

#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBase.h"

namespace Rendering
{
    class VertexBufferTesting final : public GraphicsObjectTestingBase
    {
    public:
        using ClassType = VertexBufferTesting;
        using ParentType = GraphicsObjectTestingBase;

    public:
        explicit VertexBufferTesting(const OStreamShared& stream);

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
        void GetChannelTest();

    private:
        static constexpr auto numVertices = 6;
        static constexpr auto stride = 5;
        static constexpr auto numBytes = numVertices * stride;
    };
}

#endif  // RENDERING_RESOURCES_SUITE_VERTEX_BUFFER_TESTING_H