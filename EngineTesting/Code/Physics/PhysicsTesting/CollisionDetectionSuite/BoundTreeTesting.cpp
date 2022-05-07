// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 16:44)

#include "BoundTreeTesting.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/DataTypes/Bound.h"
#include "Rendering/DataTypes/BoundDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"
#include "Physics/CollisionDetection/BoundTreeDetail.h"

#include <random>
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26435)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26498)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26490)
using CoreTools::WriteFileManager;
using std::vector;

namespace Physics
{
    template class BoundTree<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF>;
    template class BoundTree<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Physics, BoundTreeTesting)

void Physics::BoundTreeTesting ::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    Rendering::RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateTrianglesMeshFile);
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);

    Rendering::RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Physics::BoundTreeTesting ::CreateTrianglesMeshFile()
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
            Rendering::VertexFormat::AttributeType type2 =
                firstVertexFormat->GetAttributeType(attributesIndex);

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

void Physics::BoundTreeTesting ::InitTest()
{
    Rendering::VisualSharedPtr firstTrianglesMesh = Rendering::LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/CollisionDetectionSuite/TrianglesMesh.trv"));

    Rendering::TrianglesMeshSharedPtr secondTrianglesMesh = boost::polymorphic_pointer_cast<Rendering::TrianglesMesh>(firstTrianglesMesh);

    typedef BoundTree<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF> BoundTree;
    BoundTree firstBoundTree(secondTrianglesMesh);

    Rendering::TrianglesMeshSharedPtr thirdTrianglesMesh = firstBoundTree.GetMesh();

    ASSERT_EQUAL(secondTrianglesMesh, thirdTrianglesMesh);

    Rendering::ConstTrianglesMeshSharedPtr fifthTrianglesMesh = firstBoundTree.GetConstMesh();

    ASSERT_EQUAL(secondTrianglesMesh, fifthTrianglesMesh);

    BoundTree::BoundTreeChildSharedPtr firstChild = firstBoundTree.GetBeginChild();

    int numTriangles = secondTrianglesMesh->GetNumTriangles();
    std::vector<Mathematics::APointF> centroids;
    constexpr float oneThird = 1.0f / 3.0f;
    for (int index = 0; index < numTriangles; ++index)
    {
        Mathematics::APointF vertex[3];
        Rendering::TrianglePosition trianglePosition = secondTrianglesMesh->GetModelTriangle(index);

        centroids.push_back(oneThird * (trianglePosition.GetFirstPosition() + trianglePosition.GetSecondPosition() + trianglePosition.GetThirdPosition()));
    }

    vector<int> inSplit;
    for (int index = 0; index < numTriangles; ++index)
    {
        inSplit.push_back(index);
    }

    typedef BoundTreeChild<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF> BoundTreeChild;

    BoundTree::BoundTreeChildSharedPtr secondChild(std::make_shared<BoundTreeChild>(secondTrianglesMesh, 1,
                                                                                    centroids, 0, numTriangles - 1,
                                                                                    inSplit, false));

    ASSERT_TRUE(Approximate(firstChild->GetWorldBound(), secondChild->GetWorldBound(), 1e-8f));
    ASSERT_EQUAL(firstChild->IsInteriorNode(), secondChild->IsInteriorNode());
    ASSERT_EQUAL(firstChild->IsLeafNode(), secondChild->IsLeafNode());
    ASSERT_EQUAL(firstChild->GetNumTriangles(), secondChild->GetNumTriangles());
    ASSERT_EQUAL(firstChild->GetTriangles(), secondChild->GetTriangles());

    firstBoundTree.UpdateWorldBound();
    secondChild->UpdateWorldBound();

    ASSERT_TRUE(Approximate(firstChild->GetWorldBound(), secondChild->GetWorldBound(), 1e-8f));
}
