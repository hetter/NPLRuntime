//----------------------------------------------------------------------
// Class: main app file
// Authors:	yuanquanwei
// Company: ParaEngine
// Date: 2018.3
//-----------------------------------------------------------------------
#include "ParaAppAndroid.h"
using namespace  ParaEngine;

IParaEngineApp* CreateParaEngineApp()
{
	return new CParaEngineAppAndroid(nullptr);
}

void ParaEngine::CParaEngineAppAndroid::GetScreenResolution(Vector2* pOut)
{
	// should return full render window 
	pOut->x = CGlobals::GetApp()->GetRenderWindow()->GetWidth();
	pOut->y = CGlobals::GetApp()->GetRenderWindow()->GetHeight();
}

ParaEngine::CParaEngineAppAndroid::CParaEngineAppAndroid(struct android_app* state):m_appState(state)
{
	SetTouchInputting(true);
}

void ParaEngine::CParaEngineAppAndroid::GameToClient(int& inout_x, int & inout_y, bool bInBackbuffer /*= true*/)
{
	//throw std::logic_error("The method or operation is not implemented.");
}

void ParaEngine::CParaEngineAppAndroid::ClientToGame(int& inout_x, int & inout_y, bool bInBackbuffer /*= true*/)
{
	//throw std::logic_error("The method or operation is not implemented.");
}

bool ParaEngine::CParaEngineAppAndroid::AppHasFocus()
{
	//throw std::logic_error("The method or operation is not implemented.");
	return true;
}

void ParaEngine::CParaEngineAppAndroid::GetStats(string& output, DWORD dwFields)
{
	//throw std::logic_error("The method or operation is not implemented.");
}

bool ParaEngine::CParaEngineAppAndroid::WriteRegStr(const string& root_key, const string& sSubKey, const string& name, const string& value)
{
	//throw std::logic_error("The method or operation is not implemented.");
	return true;
}

void ParaEngine::CParaEngineAppAndroid::SetAutoLowerFrameRateWhenNotFocused(bool bEnabled)
{
	//throw std::logic_error("The method or operation is not implemented.");
}

const char* ParaEngine::CParaEngineAppAndroid::ReadRegStr(const string& root_key, const string& sSubKey, const string& name)
{
	//throw std::logic_error("The method or operation is not implemented.");
	return "";
}

bool ParaEngine::CParaEngineAppAndroid::WriteRegDWORD(const string& root_key, const string& sSubKey, const string& name, DWORD value)
{
	//throw std::logic_error("The method or operation is not implemented.");
	return true;
}

DWORD ParaEngine::CParaEngineAppAndroid::ReadRegDWORD(const string& root_key, const string& sSubKey, const string& name)
{
	//throw std::logic_error("The method or operation is not implemented.");
	return  0;
}

bool ParaEngine::CParaEngineAppAndroid::GetAutoLowerFrameRateWhenNotFocused()
{
	//throw std::logic_error("The method or operation is not implemented.");
	return true;
}

void ParaEngine::CParaEngineAppAndroid::SetToggleSoundWhenNotFocused(bool bEnabled)
{
	//	throw std::logic_error("The method or operation is not implemented.");

}

bool ParaEngine::CParaEngineAppAndroid::GetToggleSoundWhenNotFocused()
{
	//throw std::logic_error("The method or operation is not implemented.");
	return true;
}


HRESULT ParaEngine::CParaEngineAppAndroid::DoWork()
{
	if (!IsAppActive())
		return S_FALSE;
	if (m_pRenderWindow == nullptr)
		return S_FALSE;
	double fCurTime = m_Timer->GetAppTime();
	auto elapsedTime = m_doWorkFRC.FrameMove(fCurTime);
	if (elapsedTime > 0)
	{
		FrameMove(fCurTime);
		Render();
		m_pRenderDevice->Present();
		return S_OK;
	}
	else
	{
		return E_FAIL;
	}
}