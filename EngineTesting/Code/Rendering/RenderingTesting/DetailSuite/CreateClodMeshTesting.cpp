// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 16:43)

#include "CreateClodMeshTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Detail/CreateClodMesh.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"

#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

#include "CoreTools/FileManager/WriteFileManager.h"

#include <random>
#include <vector>
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
using CoreTools::WriteFileManager;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, CreateClodMeshTesting)

void Rendering::CreateClodMeshTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    CameraManager::Create();
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateTrianglesMeshFile);
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);

    RendererManager::Destroy();
    CameraManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::CreateClodMeshTesting::CreateTrianglesMeshFile()
{
    WriteFileManager manage(SYSTEM_TEXT("Resource/DetailSuite/CreateClodMesh.trv"));

    std::default_random_engine generator;
    std::uniform_real<float> firstFloatRandomDistribution(-1.0f, 1.0f);

    constexpr int type = System::EnumCastUnderlying(VisualPrimitiveType::TriangleMesh);
    manage.Write(sizeof(int), &type);

    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Position, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Normal, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Tangent, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Binormal, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 0)
    };

    VertexFormatSharedPtr firstVertexFormat =
        VertexFormat::Create(firstVertexFormatType);

    firstVertexFormat->SaveToFile(manage);

    // VertexBuffer
    int numElements = 20;
    int elementSize = firstVertexFormat->GetStride();
    constexpr int usage = System::EnumCastUnderlying(BufferUsage::Static);

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
            VertexFormat::AttributeType type2 =
                firstVertexFormat->GetAttributeType(attributesIndex);

            int componentSize = VertexFormat::GetComponentSize(type2);
            int numComponents = VertexFormat::GetNumComponents(type2);

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
    int indexBufferNumElements = 48;
    elementSize = 4;
    int numBytes = indexBufferNumElements * elementSize;

    manage.Write(sizeof(int), &indexBufferNumElements);
    manage.Write(sizeof(int), &elementSize);
    manage.Write(sizeof(int), &usage);
    manage.Write(sizeof(int), &numBytes);

    vector<char> buffer(numBytes);

    int* intBufferPtr = reinterpret_cast<int*>(&buffer[0]);

    intBufferPtr[0] = 0;
    intBufferPtr[1] = 1;
    intBufferPtr[2] = 2;
    intBufferPtr[3] = 2;
    intBufferPtr[4] = 1;
    intBufferPtr[5] = 3;

    intBufferPtr[6] = 4;
    intBufferPtr[7] = 0;
    intBufferPtr[8] = 2;
    intBufferPtr[9] = 4;
    intBufferPtr[10] = 2;
    intBufferPtr[11] = 3;

    intBufferPtr[12] = 5;
    intBufferPtr[13] = 6;
    intBufferPtr[14] = 7;
    intBufferPtr[15] = 7;
    intBufferPtr[16] = 6;
    intBufferPtr[17] = 8;

    intBufferPtr[18] = 9;
    intBufferPtr[19] = 5;
    intBufferPtr[20] = 7;
    intBufferPtr[21] = 9;
    intBufferPtr[22] = 7;
    intBufferPtr[23] = 8;

    intBufferPtr[24] = 10;
    intBufferPtr[25] = 11;
    intBufferPtr[26] = 12;
    intBufferPtr[27] = 12;
    intBufferPtr[28] = 11;
    intBufferPtr[29] = 13;

    intBufferPtr[30] = 14;
    intBufferPtr[31] = 10;
    intBufferPtr[32] = 12;
    intBufferPtr[33] = 14;
    intBufferPtr[34] = 12;
    intBufferPtr[35] = 13;

    intBufferPtr[36] = 15;
    intBufferPtr[37] = 16;
    intBufferPtr[38] = 17;
    intBufferPtr[39] = 17;
    intBufferPtr[40] = 16;
    intBufferPtr[41] = 18;

    intBufferPtr[42] = 19;
    intBufferPtr[43] = 15;
    intBufferPtr[44] = 17;
    intBufferPtr[45] = 19;
    intBufferPtr[46] = 17;
    intBufferPtr[47] = 18;

    manage.Write(elementSize, numBytes / elementSize, &buffer[0]);

    int offset = 0;

    manage.Write(sizeof(int), &offset);
}

void Rendering::CreateClodMeshTesting::InitTest()
{
    VisualSharedPtr firstTrianglesMesh = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/DetailSuite/CreateClodMesh.trv"));

    TrianglesMeshSharedPtr mesh(new TrianglesMesh(firstTrianglesMesh->GetVertexFormat(),
                                                  firstTrianglesMesh->GetVertexBuffer(),
                                                  firstTrianglesMesh->GetIndexBuffer()));

    CreateClodMesh createClodMesh(mesh);

    CollapseRecordArraySharedPtr collapse = createClodMesh.GetCollapseRecordArray();

    ASSERT_TRUE(0 < collapse->GetNumRecords());

    std::vector<CollapseRecord> records = collapse->GetRecords();

    for (int i = 0; i < collapse->GetNumRecords(); ++i)
    {
        ASSERT_EQUAL(records[i], collapse->GetRecord(i));
    }
}
