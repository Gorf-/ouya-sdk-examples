#include "Application.h"
#include "CallbacksRequestReceipts.h"
#include "CallbackSingleton.h"
#include "JSON.h"
#include "Receipt.h"

#include <stdio.h>
#include <android/log.h>
#include <nv_and_util/nv_native_app_glue.h>
#include <nv_egl_util/nv_egl_util.h>

#define APP_NAME "inapppurchasesnative_CallbacksRequestReceipts"

#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG,  \
											 APP_NAME, \
											 __VA_ARGS__))
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO,  \
											 APP_NAME, \
											 __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN,  \
											 APP_NAME, \
											 __VA_ARGS__))

void CallbacksRequestReceipts::OnSuccess(const std::vector<OuyaSDK::Receipt>& receipts)
{
	//LOGI("OnSuccess);
	Application::m_ui.SetMessage("CallbacksRequestReceipts::OnSuccess");

	Application::m_ui.ClearReceipts();

	for (int index = 0; index < receipts.size(); ++index)
	{
		Application::m_ui.AddReceipt(receipts[index]);
	}
}

void CallbacksRequestReceipts::OnFailure(int errorCode, const std::string& errorMessage)
{
	//char buffer[256];
	//sprintf(buffer, "OnFailure errorCode=%d errorMessage=%s", errorCode, errorMessage.c_str());
	//LOGI(buffer);
	Application::m_ui.SetMessage("CallbacksRequestReceipts::OnSuccess");
}

void CallbacksRequestReceipts::OnCancel()
{
	//LOGI("OnCancel");
	Application::m_ui.SetMessage("CallbacksRequestReceipts::OnSuccess");
}