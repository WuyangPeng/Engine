///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/20 20:19)

#include "BoundTreeChildTesting.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Rendering/DataTypes/Bound.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"
#include "Physics/CollisionDetection/BoundTreeDetail.h"

#include <random>

using CoreTools::WriteFileManager;
using std::vector;

namespace Physics
{
    template class BoundTreeChild<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF>;
    template class BoundTreeChild<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Physics, BoundTreeChildTesting)

void Physics::BoundTreeChildTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    Rendering::RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateTrianglesMeshFile);
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);

    Rendering::RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Physics::BoundTreeChildTesting::CreateTrianglesMeshFile()
{
    WriteFileManager manage(SYSTEM_TEXT("Resource/CollisionDetectionSuite/TrianglesMesh.trv"));

    std::default_random_engine generator;
    const std::uniform_real<float> firstFloatRandomDistribution(-1.0f, 1.0f);

    constexpr int type = System::EnumCastUnderlying(Rendering::VisualPrimitiveType::TriangleMesh);
    manage.Write(sizeof(int), &type);

    // VertexFormat
    vector<Rendering::VertexFormatType> firstVertexFormatType{
        Rendering::VertexFormatType(Rendering::VertexFormatFlags::AttributeType::Float3,
                                    Rendering::VertexFormatFlags::AttributeUsage::Position, 0),
        Rendering::VertexFormatType(Rendering::VertexFormatFlags::AttributeType::Float3,
                                    Rendering::VertexFormatFlags::AttributeUsage::Normal, 0),
        Rendering::VertexFormatType(Rendering::VertexFormatFlags::AttributeType::Float3,
                                    Rendering::VertexFormatFlags::AttributeUsage::Tangent, 0),
        Rendering::VertexFormatType(Rendering::VertexFormatFlags::AttributeType::Float3,
                                    Rendering::VertexFormatFlags::AttributeUsage::Binormal, 0),
        Rendering::VertexFormatType(Rendering::VertexFormatFlags::AttributeType::Float2,
                                    Rendering::VertexFormatFlags::AttributeUsage::TextureCoord, 0)
    };

    Rendering::VertexFormatSharedPtr firstVertexFormat = Rendering::VertexFormat::Create(firstVertexFormatType);

    firstVertexFormat->SaveToFile(manage);

    // VertexBuffer
    int numElements = 20;
    int elementSize = firstVertexFormat->GetStride();
    constexpr int usage = System::EnumCastUnderlying(Rendering::BufferUsage::Static);

    manage.Write(sizeof(int), &numElements);
    manage.Write(sizeof(int), &elementSize);
    manage.Write(sizeof(int), &usage);

    int vertexIndex = 0;
    for (int i = 0; i < numElements; ++i)
    {
        for (int attributesIndex = 0;
             attributesIndex < firstVertexFormat->GetNumAttributes();
             ++attributesIndex)
        {
            const Rendering::VertexFormat::AttributeType type2 = firstVertexFormat->GetAttributeType(attributesIndex);

            const int componentSize = Rendering::VertexFormat::GetComponentSize(type2);
            const int numComponents = Rendering::VertexFormat::GetNumComponents(type2);

            const auto size = componentSize * numComponents;
            vector<char> buffer(size);

            for (unsigned bufferIndex = 0; bufferIndex < buffer.size() / sizeof(float); ++bufferIndex)
            {
                const auto index = bufferIndex * sizeof(float);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

                auto* floatBufferPtr = reinterpret_cast<float*>(&buffer.at(index));

#include STSTEM_WARNING_POP

                *floatBufferPtr = firstFloatRandomDistribution(generator);
            }

            manage.Write(componentSize, numComponents, buffer.data());
        }

        vertexIndex += elementSize;
    }

    // IndexBuffer
    constexpr int indexBufferNumElements = 105;
    elementSize = 4;
    const int numBytes = indexBufferNumElements * elementSize;

    manage.Write(sizeof(int), &indexBufferNumElements);
    manage.Write(sizeof(int), &elementSize);
    manage.Write(sizeof(int), &usage);
    manage.Write(sizeof(int), &numBytes);

    vector<char> buffer(numBytes);

    for (unsigned bufferIndex = 0; bufferIndex < buffer.size() / sizeof(float); ++bufferIndex)
    {
        const auto index = bufferIndex * sizeof(int);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto* intBufferPtr = reinterpret_cast<int*>(&buffer.at(index));

#include STSTEM_WARNING_POP

        *intBufferPtr = bufferIndex % numElements;
    }

    manage.Write(elementSize, numBytes / elementSize, buffer.data());

    constexpr int offset = 0;

    manage.Write(sizeof(int), &offset);
}

void Physics::BoundTreeChildTesting::InitTest()
{
    Rendering::VisualSharedPtr firstTrianglesMesh = Rendering::LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/CollisionDetectionSuite/TrianglesMesh.trv"));

    Rendering::TrianglesMeshSharedPtr secondTrianglesMesh = boost::polymorphic_pointer_cast<Rendering::TrianglesMesh>(firstTrianglesMesh);

    using BoundTree = BoundTree<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF>;
    BoundTree firstBoundTree(secondTrianglesMesh, 1, true);

    using BoundTreeChild = BoundTreeChild<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF>;

    BoundTree::BoundTreeChildSharedPtr firstChild = firstBoundTree.GetBeginChild();

    const int numTriangles = secondTrianglesMesh->GetNumTriangles();

    vector<BoundTree::BoundTreeChildSharedPtr> leftChild;
    vector<BoundTree::BoundTreeChildSharedPtr> rightChild;

    leftChild.push_back(firstChild);

    vector<int> resultTriangles;
    for (int i = 0; i < numTriangles; ++i)
    {
        resultTriangles.push_back(i);
    }

    for (int i = numTriangles; 0 < i; i /= 2)
    {
        int sumTriangles = 0;
        vector<int> triangles;
        vector<BoundTree::BoundTreeChildSharedPtr> newLeftChild;
        vector<BoundTree::BoundTreeChildSharedPtr> newRightChild;

        for (const auto& child : leftChild)
        {
            sumTriangles += child->GetNumTriangles();
            ASSERT_TRUE(child->GetNumTriangles() == i || child->GetNumTriangles() == i + 1);

            vector<int> childTriangles = child->GetTriangles();
            triangles.insert(triangles.end(), childTriangles.begin(), childTriangles.end());

            if (child->GetLeftChild() != nullptr)
            {
                newLeftChild.push_back(child->GetLeftChild());
                ASSERT_TRUE(child->IsInteriorNode());
                ASSERT_FALSE(child->IsLeafNode());
            }
            else
            {
                ASSERT_EQUAL(i, 1);
                ASSERT_FALSE(child->IsInteriorNode());
                ASSERT_TRUE(child->IsLeafNode());
            }

            if (child->GetRightChild() != nullptr)
            {
                newRightChild.push_back(child->GetRightChild());
                ASSERT_TRUE(child->IsInteriorNode());
                ASSERT_FALSE(child->IsLeafNode());
            }
            else
            {
                ASSERT_EQUAL(i, 1);
                ASSERT_FALSE(child->IsInteriorNode());
                ASSERT_TRUE(child->IsLeafNode());
            }
        }

        for (const auto& child : rightChild)
        {
            vector<int> childTriangles = child->GetTriangles();
            triangles.insert(triangles.end(), childTriangles.begin(), childTriangles.end());

            sumTriangles += child->GetNumTriangles();
            ASSERT_TRUE(child->GetNumTriangles() == i || child->GetNumTriangles() == i + 1);

            if (child->GetLeftChild() != nullptr)
            {
                newLeftChild.push_back(child->GetLeftChild());
                ASSERT_TRUE(child->IsInteriorNode());
                ASSERT_FALSE(child->IsLeafNode());
            }
            else
            {
                ASSERT_EQUAL(i, 1);
                ASSERT_FALSE(child->IsInteriorNode());
                ASSERT_TRUE(child->IsLeafNode());
            }

            if (child->GetRightChild() != nullptr)
            {
                newRightChild.push_back(child->GetRightChild());
                ASSERT_TRUE(child->IsInteriorNode());
                ASSERT_FALSE(child->IsLeafNode());
            }
            else
            {
                ASSERT_EQUAL(i, 1);
                ASSERT_FALSE(child->IsInteriorNode());
                ASSERT_TRUE(child->IsLeafNode());
            }
        }

        leftChild = newLeftChild;
        rightChild = newRightChild;
        ASSERT_EQUAL(sumTriangles, numTriangles);

        sort(triangles.begin(), triangles.end());

        ASSERT_EQUAL(resultTriangles, triangles);
    }
}
