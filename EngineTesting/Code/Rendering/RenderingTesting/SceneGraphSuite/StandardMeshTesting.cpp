// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.5 (2019/09/05 11:26)

#include "StandardMeshTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/StandardMesh.h"

#include <vector>

using std::vector;
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, StandardMeshTesting)

void Rendering::StandardMeshTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    CameraManager::Create();
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RectangleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DiskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BoxTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CylinderOmittedEndDisksTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CylinderIncludedEndDisksTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SphereTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TorusTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TetrahedronTest);
    ASSERT_NOT_THROW_EXCEPTION_0(HexahedronTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OctahedronTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DodecahedronTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IcosahedronTest);

    RendererManager::Destroy();
    CameraManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::StandardMeshTesting::BaseTest()
{
    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{ VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Normal, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 1),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 2),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 3) };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    StandardMesh firstStandardMesh(firstVertexFormat);

    TrianglesMeshSharedPtr firstTrianglesMesh = firstStandardMesh.Tetrahedron();

    ConstVertexBufferSharedPtr firstVertexBuffer = firstTrianglesMesh->GetConstVertexBuffer();

    ASSERT_ENUM_EQUAL(firstVertexBuffer->GetUsage(), BufferUsage::Static);

    StandardMesh secondStandardMesh(firstVertexFormat, false);

    TrianglesMeshSharedPtr secondTrianglesMesh = secondStandardMesh.Tetrahedron();

    ConstVertexBufferSharedPtr secondVertexBuffer = secondTrianglesMesh->GetConstVertexBuffer();

    ASSERT_ENUM_EQUAL(secondVertexBuffer->GetUsage(), BufferUsage::Dynamic);

    // 	Transform firstTransform;
    //
    // 	firstTransform.SetUniformScale(2.0f);
    //
    // 	secondStandardMesh.SetTransform(firstTransform);
    //
    // 	ASSERT_TRUE(Approximate(firstTransform, secondStandardMesh.GetTransform(), 1e-8f));
}

void Rendering::StandardMeshTesting::RectangleTest()
{
    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{ VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Normal, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 1),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 2),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 3) };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    StandardMesh firstStandardMesh(firstVertexFormat);

    int xSamples = 10;
    int ySamples = 10;
    float xExtent = 100.0f;
    float yExtent = 80.0f;

    TrianglesMeshSharedPtr firstTrianglesMesh = firstStandardMesh.Rectangle(xSamples, ySamples, xExtent, yExtent);

    ConstVertexBufferSharedPtr firstVertexBuffer = firstTrianglesMesh->GetConstVertexBuffer();
    ConstIndexBufferSharedPtr firstIndexBuffer = firstTrianglesMesh->GetConstIndexBuffer();

    ASSERT_EQUAL(firstVertexBuffer->GetNumElements(), xSamples * ySamples);
    ASSERT_EQUAL(firstTrianglesMesh->GetNumTriangles(), 2 * (xSamples - 1) * (ySamples - 1));
    ASSERT_EQUAL(firstIndexBuffer->GetNumElements(), 6 * (xSamples - 1) * (ySamples - 1));
}

void Rendering::StandardMeshTesting::DiskTest()
{
    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{ VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Normal, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 1) };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    StandardMesh firstStandardMesh(firstVertexFormat);

    int shellSamples = 10;
    int radialSamples = 10;
    float radius = 50.0f;

    TrianglesMeshSharedPtr firstTrianglesMesh = firstStandardMesh.Disk(shellSamples, radialSamples, radius);

    ConstVertexBufferSharedPtr firstVertexBuffer = firstTrianglesMesh->GetConstVertexBuffer();
    ConstIndexBufferSharedPtr firstIndexBuffer = firstTrianglesMesh->GetConstIndexBuffer();

    ASSERT_EQUAL(firstVertexBuffer->GetNumElements(), 1 + radialSamples * (shellSamples - 1));
    ASSERT_EQUAL(firstTrianglesMesh->GetNumTriangles(), radialSamples * (2 * (shellSamples - 1) - 1));
    ASSERT_EQUAL(firstIndexBuffer->GetNumElements(), 3 * (radialSamples * (2 * (shellSamples - 1) - 1)));
}

void Rendering::StandardMeshTesting::BoxTest()
{
    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{ VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Normal, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 1),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 2) };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    StandardMesh firstStandardMesh(firstVertexFormat);

    float xExtent = 10.0f;
    float yExtent = 20.0f;
    float zExtent = 15.0f;

    TrianglesMeshSharedPtr firstTrianglesMesh = firstStandardMesh.Box(xExtent, yExtent, zExtent);

    ConstVertexBufferSharedPtr firstVertexBuffer = firstTrianglesMesh->GetConstVertexBuffer();
    ConstIndexBufferSharedPtr firstIndexBuffer = firstTrianglesMesh->GetConstIndexBuffer();

    ASSERT_EQUAL(firstVertexBuffer->GetNumElements(), 8);
    ASSERT_EQUAL(firstTrianglesMesh->GetNumTriangles(), 12);
    ASSERT_EQUAL(firstIndexBuffer->GetNumElements(), 3 * 12);
}

void Rendering::StandardMeshTesting::CylinderOmittedEndDisksTest()
{
    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{ VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Normal, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 1),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 2),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 3) };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    StandardMesh firstStandardMesh(firstVertexFormat);

    int axisSamples = 10;
    int radialSamples = 12;
    float radius = 10.0f;
    float height = 14.0f;

    TrianglesMeshSharedPtr firstTrianglesMesh = firstStandardMesh.CylinderOmittedEndDisks(axisSamples, radialSamples, radius, height);

    ConstVertexBufferSharedPtr firstVertexBuffer = firstTrianglesMesh->GetConstVertexBuffer();
    ConstIndexBufferSharedPtr firstIndexBuffer = firstTrianglesMesh->GetConstIndexBuffer();

    ASSERT_EQUAL(firstVertexBuffer->GetNumElements(), axisSamples * (radialSamples + 1));
    ASSERT_EQUAL(firstTrianglesMesh->GetNumTriangles(), 2 * (axisSamples - 1) * radialSamples);
    ASSERT_EQUAL(firstIndexBuffer->GetNumElements(), 6 * (axisSamples - 1) * radialSamples);
}

void Rendering::StandardMeshTesting::CylinderIncludedEndDisksTest()
{
    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Position, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Normal, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 1),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 2),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 3),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 4),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 5),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 6)
    };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    StandardMesh firstStandardMesh(firstVertexFormat);

    int axisSamples = 12;
    int radialSamples = 15;
    float radius = 11.0f;
    float height = 14.2f;

    TrianglesMeshSharedPtr firstTrianglesMesh = firstStandardMesh.CylinderIncludedEndDisks(axisSamples, radialSamples, radius, height);

    ConstVertexBufferSharedPtr firstVertexBuffer = firstTrianglesMesh->GetConstVertexBuffer();
    ConstIndexBufferSharedPtr firstIndexBuffer = firstTrianglesMesh->GetConstIndexBuffer();

    ASSERT_EQUAL(firstVertexBuffer->GetNumElements(), (axisSamples - 2) * (radialSamples + 1) + 2);
    ASSERT_EQUAL(firstTrianglesMesh->GetNumTriangles(), 2 * (axisSamples - 2) * radialSamples);
    ASSERT_EQUAL(firstIndexBuffer->GetNumElements(), 6 * (axisSamples - 2) * radialSamples);
}

void Rendering::StandardMeshTesting::SphereTest()
{
    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Position, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Normal, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 1)
    };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    StandardMesh firstStandardMesh(firstVertexFormat);

    int zSamples = 10;
    int radialSamples = 20;
    float radius = 1.5f;

    TrianglesMeshSharedPtr firstTrianglesMesh = firstStandardMesh.Sphere(zSamples, radialSamples, radius);

    ConstVertexBufferSharedPtr firstVertexBuffer = firstTrianglesMesh->GetConstVertexBuffer();
    ConstIndexBufferSharedPtr firstIndexBuffer = firstTrianglesMesh->GetConstIndexBuffer();

    ASSERT_EQUAL(firstVertexBuffer->GetNumElements(), (zSamples - 2) * (radialSamples + 1) + 2);
    ASSERT_EQUAL(firstTrianglesMesh->GetNumTriangles(), 2 * (zSamples - 2) * radialSamples);
    ASSERT_EQUAL(firstIndexBuffer->GetNumElements(), 6 * (zSamples - 2) * radialSamples);
}

void Rendering::StandardMeshTesting::TorusTest()
{
    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Position, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Normal, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 1),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 2)
    };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    StandardMesh firstStandardMesh(firstVertexFormat);

    int circleSamples = 10;
    int radialSamples = 10;
    float outerRadius = 1.5f;
    float innerRadius = 0.8f;

    TrianglesMeshSharedPtr firstTrianglesMesh = firstStandardMesh.Torus(circleSamples, radialSamples, outerRadius, innerRadius);

    ConstVertexBufferSharedPtr firstVertexBuffer = firstTrianglesMesh->GetConstVertexBuffer();
    ConstIndexBufferSharedPtr firstIndexBuffer = firstTrianglesMesh->GetConstIndexBuffer();

    int numVertices = (circleSamples + 1) * (radialSamples + 1);
    int numTriangles = 2 * circleSamples * radialSamples;
    int numIndices = 3 * numTriangles;

    ASSERT_EQUAL(firstVertexBuffer->GetNumElements(), numVertices);
    ASSERT_EQUAL(firstTrianglesMesh->GetNumTriangles(), numTriangles);
    ASSERT_EQUAL(firstIndexBuffer->GetNumElements(), numIndices);
}

void Rendering::StandardMeshTesting::TetrahedronTest()
{
    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Position, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Normal, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 1),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 2),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 3)
    };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    StandardMesh firstStandardMesh(firstVertexFormat);

    TrianglesMeshSharedPtr firstTrianglesMesh = firstStandardMesh.Tetrahedron();

    ConstVertexBufferSharedPtr firstVertexBuffer = firstTrianglesMesh->GetConstVertexBuffer();
    ConstIndexBufferSharedPtr firstIndexBuffer = firstTrianglesMesh->GetConstIndexBuffer();

    ASSERT_EQUAL(firstVertexBuffer->GetNumElements(), 4);
    ASSERT_EQUAL(firstTrianglesMesh->GetNumTriangles(), 4);
    ASSERT_EQUAL(firstIndexBuffer->GetNumElements(), 12);
}

void Rendering::StandardMeshTesting::HexahedronTest()
{
    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Position, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Normal, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 0)
    };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    StandardMesh firstStandardMesh(firstVertexFormat);

    TrianglesMeshSharedPtr firstTrianglesMesh = firstStandardMesh.Hexahedron();

    ConstVertexBufferSharedPtr firstVertexBuffer = firstTrianglesMesh->GetConstVertexBuffer();
    ConstIndexBufferSharedPtr firstIndexBuffer = firstTrianglesMesh->GetConstIndexBuffer();

    ASSERT_EQUAL(firstVertexBuffer->GetNumElements(), 8);
    ASSERT_EQUAL(firstTrianglesMesh->GetNumTriangles(), 12);
    ASSERT_EQUAL(firstIndexBuffer->GetNumElements(), 3 * 12);
}

void Rendering::StandardMeshTesting::OctahedronTest()
{
    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Position, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Normal, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 1),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 2),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 3),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 4)
    };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    StandardMesh firstStandardMesh(firstVertexFormat);

    TrianglesMeshSharedPtr firstTrianglesMesh = firstStandardMesh.Octahedron();

    ConstVertexBufferSharedPtr firstVertexBuffer = firstTrianglesMesh->GetConstVertexBuffer();
    ConstIndexBufferSharedPtr firstIndexBuffer = firstTrianglesMesh->GetConstIndexBuffer();

    ASSERT_EQUAL(firstVertexBuffer->GetNumElements(), 6);
    ASSERT_EQUAL(firstTrianglesMesh->GetNumTriangles(), 8);
    ASSERT_EQUAL(firstIndexBuffer->GetNumElements(), 24);
}

void Rendering::StandardMeshTesting::DodecahedronTest()
{
    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Position, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Normal, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 0)
    };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    StandardMesh firstStandardMesh(firstVertexFormat);

    TrianglesMeshSharedPtr firstTrianglesMesh = firstStandardMesh.Dodecahedron();

    ConstVertexBufferSharedPtr firstVertexBuffer = firstTrianglesMesh->GetConstVertexBuffer();
    ConstIndexBufferSharedPtr firstIndexBuffer = firstTrianglesMesh->GetConstIndexBuffer();

    ASSERT_EQUAL(firstVertexBuffer->GetNumElements(), 20);
    ASSERT_EQUAL(firstTrianglesMesh->GetNumTriangles(), 36);
    ASSERT_EQUAL(firstIndexBuffer->GetNumElements(), 3 * 36);
}

void Rendering::StandardMeshTesting::IcosahedronTest()
{
    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Position, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float3,
                         VertexFormatFlags::AttributeUsage::Normal, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 0),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 1),
        VertexFormatType(VertexFormatFlags::AttributeType::Float2,
                         VertexFormatFlags::AttributeUsage::TextureCoord, 2)
    };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    StandardMesh firstStandardMesh(firstVertexFormat);

    TrianglesMeshSharedPtr firstTrianglesMesh = firstStandardMesh.Icosahedron();

    ConstVertexBufferSharedPtr firstVertexBuffer = firstTrianglesMesh->GetConstVertexBuffer();
    ConstIndexBufferSharedPtr firstIndexBuffer = firstTrianglesMesh->GetConstIndexBuffer();

    ASSERT_EQUAL(firstVertexBuffer->GetNumElements(), 12);
    ASSERT_EQUAL(firstTrianglesMesh->GetNumTriangles(), 20);
    ASSERT_EQUAL(firstIndexBuffer->GetNumElements(), 60);
}
