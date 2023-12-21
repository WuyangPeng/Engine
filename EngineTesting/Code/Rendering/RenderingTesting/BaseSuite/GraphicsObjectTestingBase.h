/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/11 19:17)

#ifndef RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_BASE_H
#define RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_BASE_H

#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Rendering/Base/BaseFwd.h"
#include "Rendering/Base/GraphicsObject.h"

#include <string>

namespace Rendering
{
    class GraphicsObjectTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = GraphicsObjectTestingBase;
        using ParentType = UnitTest;

        using BufferTarget = CoreTools::BufferTarget;
        using FileBuffer = CoreTools::FileBuffer;
        using OriginalBuffer = FileBuffer::BufferType;
        using FileBufferSharedPtr = CoreTools::FileBufferSharedPtr;

    public:
        GraphicsObjectTestingBase(const OStreamShared& stream,
                                  GraphicsObjectType beginGraphicsObjectType,
                                  GraphicsObjectType endGraphicsObjectType,
                                  const std::string& graphicsObjectName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        template <typename TestingType>
        NODISCARD std::shared_ptr<TestingType> Create(const std::string& name, GraphicsObjectType graphicsObjectType);

        template <typename TestingType>
        void RttiTest();

        template <typename TestingType>
        void CloneObjectTest();

        template <typename TestingType>
        void IsNullObjectTest();

        template <typename TestingType>
        void UniqueIdTest();

        template <typename TestingType>
        void NameTest();

        template <typename TestingType>
        void StreamTest();

        template <typename TestingType>
        void FactoryTest();

        template <typename TestingType>
        void FactoryExceptionTest();

        template <typename TestingType>
        void GetStreamingSizeTest();

        template <typename TestingType>
        void RegisterTest();

        template <typename TestingType>
        void LinkTest();

        template <typename TestingType>
        void StreamCreateTest();

        template <typename TestingType>
        NODISCARD FileBufferSharedPtr SaveTest(const TestingType& testingType);

        NODISCARD FileBufferSharedPtr CorrectFileBuffer(int beginIndex, const OriginalBuffer& buffer);

        NODISCARD GraphicsObjectType GetGraphicsObjectType() const noexcept;
        NODISCARD std::string GetGraphicsObjectName() const;

        NODISCARD virtual GraphicsObjectSharedPtr Create(const std::string& name, GraphicsObjectType graphicsObjectType) const = 0;

        NODISCARD virtual int GetStreamSizeShifting() const noexcept;

    private:
        template <typename LhsTestingTypeSharedPtr, typename RhsTestingTypeSharedPtr>
        void GraphicsObjectRttiTrueTest(const LhsTestingTypeSharedPtr& lhs, const RhsTestingTypeSharedPtr& rhs);

        template <typename LhsTestingTypeSharedPtr, typename RhsTestingTypeSharedPtr>
        void GraphicsObjectRttiFalseTest(const LhsTestingTypeSharedPtr& lhs, const RhsTestingTypeSharedPtr& rhs);

        template <typename TestingType>
        void CloneObjectTrueTest(GraphicsObjectType graphicsObjectType);

        template <typename TestingType>
        void GetObjectByNameTest(const TestingType& testingType, const std::string& name);

        template <typename TestingType>
        void GetConstObjectByNameTest(const TestingType& testingType, const std::string& name);

        template <typename TestingType>
        void GetAllObjectsByNameTest(const TestingType& testingType, const std::string& name);

        template <typename TestingType>
        void GetAllConstObjectsByNameTest(const TestingType& testingType, const std::string& name);

        template <typename TestingType>
        NODISCARD BufferTarget CreateBufferTarget(const TestingType& testingType);

        template <typename TestingType>
        void RttiNameTest(int endIndex, const OriginalBuffer& buffer);

        template <typename TestingType>
        void LoadTest(const FileBufferSharedPtr& saveFileBuffer, const TestingType& testingType);

    private:
        GraphicsObjectType beginGraphicsObjectType;
        GraphicsObjectType endGraphicsObjectType;
        std::string graphicsObjectName;
    };
}

#endif  // RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_BASE_H