
#include "AStar.h"

void DemoScreen::LoadContent(ResourceManager *pResourceManager)
{
	Font::SetLoadSize(36, true);
	Font *pFont36 = pResourceManager->Load<Font>("Fonts\\LucidaSans.ttf", false);
	DrawableVertex::SetFont(pFont36);

	Font::SetLoadSize(24, true);
	Font *pFont24 = pResourceManager->Load<Font>("Fonts\\LucidaSans.ttf", false);
	DrawableEdge::SetFont(pFont24);

	m_pGraph = new DrawableGraph();
	m_pGraph->SetIsDraggable();
}

void DemoScreen::HandleInput(const InputState *pInput)
{
	if (pInput->IsNewKeyPress(Key::PAD_1))
	{
		delete m_pGraph;
		m_pGraph = DrawableGraph::GenerateGraph1();
	}

	if (pInput->IsNewKeyPress(Key::PAD_2))
	{
		delete m_pGraph;
		m_pGraph = DrawableGraph::GenerateGraph2();
	}

	m_pGraph->HandleInput(pInput);
}

void DemoScreen::Draw(SpriteBatch *pSpriteBatch)
{
	pSpriteBatch->Begin();
	m_pGraph->Draw(pSpriteBatch);
	pSpriteBatch->End();
}