// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 16:40)

#include "BoundTreeChildTesting.h"
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
    template class BoundTreeChild<Rendering::TrianglesMeshSharedPtr, Rendering::FloatBound>;
    template class BoundTreeChild<Rendering::TrianglesMeshSharedPtr, Rendering::FloatBound>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Physics, BoundTreeChildTesting)

void Physics::BoundTreeChildTesting ::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    Rendering::RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateTrianglesMeshFile);
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);

    Rendering::RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Physics::BoundTreeChildTesting ::CreateTrianglesMeshFile()
{
    WriteFileManager manage(SYSTEM_TEXT("Resource/CollisionDetectionSuite/TrianglesMesh.trv"));

    std::default_random_engine generator;
    std::uniform_real<float> firstFloatRandomDistribution(-1.0f, 1.0f);

    int type = System::EnumCastUnderlying(Rendering::VisualPrimitiveType::TriangleMesh);
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
    int usage = System::EnumCastUnderlying(Rendering::BufferUsage::Static);

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
            Rendering::VertexFormat::AttributeType type2 = firstVertexFormat->GetAttributeType(attributesIndex);

            int componentSize = Rendering::VertexFormat::GetComponentSize(type2);
            int numComponents = Rendering::VertexFormat::GetNumComponents(type2);

            vector<char> buffer(componentSize * numComponents);

            for (unsigned bufferIndex = 0; bufferIndex < buffer.size() / sizeof(float);
                 ++bufferIndex)
            {
                float* floatBufferPtr = reinterpret_cast<float*>(&buffer[bufferIndex * sizeof(float)]);

                *floatBufferPtr = firstFloatRandomDistribution(generator);
            }

            manage.Write(componentSize, numComponents, &buffer[0]);
        }

        vertexIndex += elementSize;
    }

    // IndexBuffer
    int indexBufferNumElements = 105;
    elementSize = 4;
    int numBytes = indexBufferNumElements * elementSize;

    manage.Write(sizeof(int), &indexBufferNumElements);
    manage.Write(sizeof(int), &elementSize);
    manage.Write(sizeof(int), &usage);
    manage.Write(sizeof(int), &numBytes);

    vector<char> buffer(numBytes);

    for (unsigned bufferIndex = 0; bufferIndex < buffer.size() / sizeof(float);
         ++bufferIndex)
    {
        int* intBufferPtr = reinterpret_cast<int*>(&buffer[bufferIndex * sizeof(int)]);

        *intBufferPtr = bufferIndex % numElements;
    }

    manage.Write(elementSize, numBytes / elementSize, &buffer[0]);

    int offset = 0;

    manage.Write(sizeof(int), &offset);
}

void Physics::BoundTreeChildTesting ::InitTest()
{
    Rendering::VisualSharedPtr firstTrianglesMesh = Rendering::LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/CollisionDetectionSuite/TrianglesMesh.trv"));

    Rendering::TrianglesMeshSharedPtr secondTrianglesMesh;  //        = firstTrianglesMesh.PolymorphicDowncastObjectSmartPointer<Rendering::TrianglesMeshSmartPointer>();

    typedef BoundTree<Rendering::TrianglesMeshSharedPtr, Rendering::FloatBound> BoundTree;
    BoundTree firstBoundTree(secondTrianglesMesh, 1, true);

    typedef BoundTreeChild<Rendering::TrianglesMeshSharedPtr, Rendering::FloatBound> BoundTreeChild;

    BoundTree::BoundTreeChildPtr firstChild = firstBoundTree.GetBeginChild();

    int numTriangles = secondTrianglesMesh->GetNumTriangles();

    vector<BoundTree::BoundTreeChildPtr> leftChild;
    vector<BoundTree::BoundTreeChildPtr> rightChild;

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
        vector<BoundTree::BoundTreeChildPtr> newLeftChild;
        vector<BoundTree::BoundTreeChildPtr> newRightChild;

        for (BoundTree::BoundTreeChildPtr child : leftChild)
        {
            sumTriangles += child->GetNumTriangles();
            ASSERT_TRUE(child->GetNumTriangles() == i ||
                        child->GetNumTriangles() == i + 1);

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

        for (BoundTree::BoundTreeChildPtr child : rightChild)
        {
            vector<int> childTriangles = child->GetTriangles();
            triangles.insert(triangles.end(), childTriangles.begin(),
                             childTriangles.end());

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

        ASSERT_EQUAL_DO_NOT_USE_MESSAGE(resultTriangles, triangles);
    }
}
