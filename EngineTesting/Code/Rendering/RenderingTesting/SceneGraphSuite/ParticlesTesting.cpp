///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/14 20:25)

#include "ParticlesTesting.h"
#include "VisualTest.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorOrthonormalBasisDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessorDetail.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/Particles.h"
#include "Rendering/SceneGraph/SaveVisual.h"

#include <random>
#include <vector>

using CoreTools::WriteFileManager;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ParticlesTesting)

void Rendering::ParticlesTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    CameraManager::Create();
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateTrianglesMeshFile);
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TransformTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileTest);

    RendererManager::Destroy();
    CameraManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::ParticlesTesting::CreateTrianglesMeshFile()
{
    WriteFileManager manage(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesParticles.trv"));

    std::default_random_engine generator;
    const std::uniform_real<float> firstFloatRandomDistribution(-1.0f, 1.0f);

    constexpr int type = System::EnumCastUnderlying(VisualPrimitiveType::TriangleMesh);
    manage.Write(sizeof(int), &type);

    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{ VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 0) };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    firstVertexFormat->SaveToFile(manage);

    // VertexBuffer
    constexpr int numElements = 80;
    const int elementSize = firstVertexFormat->GetStride();
    constexpr int usage = System::EnumCastUnderlying(BufferUsage::Static);

    manage.Write(sizeof(int), &numElements);
    manage.Write(sizeof(int), &elementSize);
    manage.Write(sizeof(int), &usage);

    for (int i = 0; i < numElements; ++i)
    {
        for (int attributesIndex = 0; attributesIndex < firstVertexFormat->GetNumAttributes(); ++attributesIndex)
        {
            const VertexFormat::AttributeType type2 = firstVertexFormat->GetAttributeType(attributesIndex);

            const int componentSize = VertexFormat::GetComponentSize(type2);
            const int numComponents = VertexFormat::GetNumComponents(type2);

            const auto size = componentSize * numComponents;

            vector<char> buffer(size);

            for (unsigned bufferIndex = 0; bufferIndex < buffer.size() / sizeof(float); ++bufferIndex)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

                auto* floatBufferPtr = reinterpret_cast<float*>(&buffer.at(bufferIndex * sizeof(float)));

#include STSTEM_WARNING_POP

                *floatBufferPtr = firstFloatRandomDistribution(generator);
            }

            manage.Write(componentSize, numComponents, &buffer.at(0));
        }
    }

    // IndexBuffer
    constexpr int indexBufferNumElements = 0;

    manage.Write(sizeof(int), &indexBufferNumElements);
}

void Rendering::ParticlesTesting::InitTest() noexcept
{
}

void Rendering::ParticlesTesting::CopyTest() noexcept
{
}

void Rendering::ParticlesTesting::TransformTest() noexcept
{
}

void Rendering::ParticlesTesting::StreamTest() noexcept
{
}

void Rendering::ParticlesTesting::FileTest() noexcept
{
}
