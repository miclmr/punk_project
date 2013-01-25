#include "../../punk_engine.h"

System::Proxy<Scene::SceneGraph> scene;
System::Proxy<Virtual::TerrainObserver> observer;
bool m_left_down = false;
System::Proxy<Scene::DebugTextureViewNode> node;
System::Proxy<Scene::TerrainNode> terrain_node;

Scene::BoundingVolumeUpdater updater;
OpenGL::SimpleRender render;
System::Proxy<GUI::Widget> widget;

float x = 0, y = 0;
void OnMouseLeftButtonDown(System::Event* ee)
{
	m_left_down = true;
}

void OnMouseLeftButtonUp(System::Event* ee)
{
	m_left_down = false;
}

void OnMouseMove(System::Event* ee)
{
	System::MouseMoveEvent* e = static_cast<System::MouseMoveEvent*>(ee);
	
	//if (m_left_down)
	//{
	//	x += (float)(e->x - e->x_prev);
	//	y += (float)(e->y - e->y_prev);		
	//	observer->SetPosition(Math::vec3(x, 0, y));
	//}
	
	//if (m_left_down)
	{
		x += 0.001 * (float)(e->x - e->x_prev);
		y += 0.001 * (float)(e->y - e->y_prev);		

		System::Proxy<Virtual::FirstPersonCamera> c = scene->GetCameraNode()->GetCamera();
		c->SetYawRollPitch(x, y, 0);
	}
}

void OnKeyDown(System::Event* ee)
{
	System::KeyDownEvent* e = static_cast<System::KeyDownEvent*>(ee);
	switch (e->key)
	{
	case System::PUNK_KEY_F5:
		{
			std::ofstream stream("scene.save", std::ios_base::binary);
			scene->Save(stream);
		}
		break;
	case System::PUNK_KEY_F9:
		{			
			scene.Reset(new Scene::SceneGraph);
			std::ifstream stream("scene.save", std::ios_base::binary);
			scene->Load(stream);
			render.SetScene(scene);
		}
	case System::PUNK_KEY_A:
		{
		}
	default:
		break;
	}
}

void Idle(System::Event*)
{	
	System::AsyncLoader::Instance()->MainThreadProc(1);
	//node->SetWatchTexture(OpenGL::Texture2DManager::Instance()->Load(L"checker2.png"));
	node->SetWatchTexture(observer->GetTerrainView()->GetHeightMap());
	
	updater.Update();
	render.Render();
	System::Proxy<Virtual::FirstPersonCamera> c = scene->GetCameraNode()->GetCamera();
	bool update = false;
	if (System::Keyboard::Instance()->GetKeyState(System::PUNK_KEY_A))
	{
		c->SetPosition(c->GetPosition() + c->GetRightVector() * -0.5f);
		update = true;
	}
	if (System::Keyboard::Instance()->GetKeyState(System::PUNK_KEY_D))
	{
		c->SetPosition(c->GetPosition() + c->GetRightVector() * 0.5f);
		update = true;
	}
	if (System::Keyboard::Instance()->GetKeyState(System::PUNK_KEY_W))
	{
		c->SetPosition(c->GetPosition() + c->GetDirection() * 0.5f);
		update = true;
	}
	if (System::Keyboard::Instance()->GetKeyState(System::PUNK_KEY_S))
	{
		c->SetPosition(c->GetPosition() + c->GetDirection() * -0.5f);
		update = true;
	}

	if (update)
	{
		System::string text = System::string::Format(L"X: %f; Z: %f, Height: %f", c->GetPosition().X(), c->GetPosition().Z(), c->GetPosition().Z());
		widget->SetText(text);
		observer->SetPosition(c->GetPosition());
	}

	//OpenGL::Driver* d = OpenGL::Driver::Instance();
	//OpenGL::RenderPass* pass = new OpenGL::RenderPass;
	//Math::mat4 m = Math::mat4::CreateRotation(1, 0, 0, y)*Math::mat4::CreateRotation(0, 1, 0, x);;
	//Render::SolidObjectRender::Parameters p(*m_object, &camera,pass, &m);
	//
	//pass->SetRenderTarget(rt);
	//render->Render(&p);
	//frame.Begin();
	//frame.AddRenderPass(pass);
	//frame.End();	
}

int main()
{
	System::GetFactory()->Init();

	System::Window::Instance()->SetTitle(L"OpenGL object test");
	System::Mouse::Instance()->LockInWindow(true);
	OpenGL::Driver::Instance()->Start();

	System::EventManager::Instance()->SubscribeHandler(System::EVENT_IDLE, System::EventHandler(Idle));
	System::EventManager::Instance()->SubscribeHandler(System::EVENT_MOUSE_LBUTTON_DOWN, System::EventHandler(OnMouseLeftButtonDown));
	System::EventManager::Instance()->SubscribeHandler(System::EVENT_MOUSE_LBUTTON_UP, System::EventHandler(OnMouseLeftButtonUp));
	System::EventManager::Instance()->SubscribeHandler(System::EVENT_MOUSE_MOVE, System::EventHandler(OnMouseMove));
	System::EventManager::Instance()->SubscribeHandler(System::EVENT_KEY_DOWN, System::EventHandler(OnKeyDown));

	scene = System::GetFactory()->CreateFromTextFile(System::Environment::Instance()->GetModelFolder() + L"plane.pmd");

	Virtual::TerrainManager::Instance()->Manage(L"test_map");
	
	System::Proxy<Virtual::FirstPersonCamera> c = scene->GetCameraNode()->GetCamera();	
	c->SetPosition(Math::vec3(x, 0, y));

	observer = Virtual::TerrainManager::Instance()->CreateTerrainObserver(Math::vec3(c->GetPosition()));
	node.Reset(new Scene::DebugTextureViewNode);	
	System::Proxy<Scene::Node> root = scene->GetRootNode();

	widget.Reset(new GUI::Widget(0, 0, 0.5, 0.2, L"DF"));

	GUI::Manager::Instance()->AddRootWidget(widget);
	
	render.SetGUIHud(widget);

	terrain_node.Reset(new Scene::TerrainNode());
	terrain_node->SetTerrainObserver(observer);
	root->Add(terrain_node);
	root->Add(node);
	render.SetScene(scene);
	updater.SetScene(scene);	

	System::Window::Instance()->Loop();

	System::AsyncLoader::Destroy();

	return 0;
}
