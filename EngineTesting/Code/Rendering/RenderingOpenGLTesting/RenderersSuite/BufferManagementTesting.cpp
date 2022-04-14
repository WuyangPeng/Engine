// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/09 15:23)

#include "BufferManagementTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "Rendering/Renderers/PlatformIndexBuffer.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/Visual.h"

#include "Rendering/Renderers/BufferManagementDetail.h"

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, BufferManagementTesting)

void Rendering::BufferManagementTesting::MainTest()
{
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(VertexBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IndexBufferTest);

    RendererManager::Destroy();
}

void Rendering::BufferManagementTesting::VertexBufferTest() noexcept
{
    // 	RendererSharedPtr renderer(new Renderer("Configuration/Renderer.json"));
    // 	renderer->Init();
    // 	BufferManagement<PlatformVertexBuffer> management(renderer);
    //
    // 	vector<VertexBufferSmartPointer> vertexBufferCollection;
    //
    // 	for (int i = 0;i < 10;++i)
    // 	{
    // 		VisualSmartPointer firstTrianglesStrip = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/RenderersSuite/TrianglesStrip.trv"));
    //
    // 		VertexBufferSmartPointer vertexbuffer = firstTrianglesStrip->GetVertexBuffer();
    //
    // 		vertexBufferCollection.push_back(vertexbuffer);
    // 	}
    //
    // 	for (unsigned i = 0;i < vertexBufferCollection.size();++i)
    // 	{
    // 		if (i % 2 == 0)
    // 		{
    // 			management.Bind(vertexBufferCollection[i]);
    // 		}
    //
    // 		management.EnableVertexBuffer(vertexBufferCollection[i],0,0);
    //
    // 		management.Lock(vertexBufferCollection[i],BufferLocking::WriteOnly);
    // 		management.Unlock(vertexBufferCollection[i]);
    //
    // 		management.Update(vertexBufferCollection[i]);
    //
    // 		ASSERT_UNEQUAL_NULL_PTR(management.GetResource(vertexBufferCollection[i]));
    //
    // 		management.DisableVertexBuffer(vertexBufferCollection[i],0);
    // 		management.Unbind(vertexBufferCollection[i]);
    //}
}

void Rendering::BufferManagementTesting::IndexBufferTest() noexcept
{
    // 	RendererSharedPtr renderer(new Renderer("Configuration/Renderer.json"));
    // 	renderer->Init();
    // 	BufferManagement<PlatformIndexBuffer> management(renderer);
    //
    // 	vector<IndexBufferSmartPointer> indexBufferCollection;
    //
    // 	for (int i = 0;i < 10;++i)
    // 	{
    // 		VisualSmartPointer firstTrianglesStrip = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/RenderersSuite/TrianglesStrip.trv"));
    //
    // 		IndexBufferSmartPointer indexbuffer = firstTrianglesStrip->GetIndexBuffer();
    //
    // 		indexBufferCollection.push_back(indexbuffer);
    // 	}
    //
    // 	for (unsigned i = 0;i < indexBufferCollection.size();++i)
    // 	{
    // 		if (i % 2 == 0)
    // 		{
    // 			management.Bind(indexBufferCollection[i]);
    // 		}
    //
    // 		management.EnableIndexBuffer(indexBufferCollection[i]);
    //
    // 		management.Lock(indexBufferCollection[i],BufferLocking::WriteOnly);
    // 		management.Unlock(indexBufferCollection[i]);
    //
    // 		management.Update(indexBufferCollection[i]);
    //
    // 		ASSERT_UNEQUAL_NULL_PTR(management.GetResource(indexBufferCollection[i]));
    //
    // 		management.DisableIndexBuffer(indexBufferCollection[i]);
    // 		management.Unbind(indexBufferCollection[i]);
    // 	}
}
