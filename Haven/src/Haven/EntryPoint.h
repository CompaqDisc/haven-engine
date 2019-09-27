#pragma once

extern Haven::Application* Haven::CreateApplication();

int main(int argc, char** argv)
{
	Haven::Init();

	auto app = Haven::CreateApplication();
	HV_CORE_INFO("Client Initialized.");
	HV_CORE_DEBUG("This is a debug build of the client application.");
	app->Run();
	delete app;

	return 0;
}