/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/12 14:55)

#ifndef RENDERING_RESOURCES_SUITE_RESOURCE_TESTING_H
#define RENDERING_RESOURCES_SUITE_RESOURCE_TESTING_H

#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBase.h"

namespace Rendering
{
    class ResourceTesting final : public GraphicsObjectTestingBase
    {
    public:
        using ClassType = ResourceTesting;
        using ParentType = GraphicsObjectTestingBase;

    public:
        explicit ResourceTesting(const OStreamShared& stream);

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
    };
}

#endif  // RENDERING_RESOURCES_SUITE_RESOURCE_TESTING_H