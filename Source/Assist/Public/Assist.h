#pragma once

#include "Modules/ModuleManager.h"
#include "Containers/Ticker.h"
#include "AssistConfig.h"

class SWindow;
class SWidget;

class FAssistModule : public IModuleInterface {
   public:
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

   private:
    void init();
    void RegisterMenus();
    FAssistConfig AssistConfig;

    void ReloadProject();
    void ReloadAsset(const FString AssetType);
    void SetLayout(const bool IsHorizontal);
    void SetCurrentLanguage(const FString Language);

    void FindWidget(TSharedRef<SWidget> Parent, FString TypeString, TSharedPtr<SWidget>& Result);

    void OnPostEngineInit();
    bool ApplyContentBrowserToolWindowStyle();
    bool TickApplyContentBrowserToolWindowStyle(float DeltaTime);
    TSharedPtr<SWindow> FindContentBrowserWindow() const;

    FDelegateHandle PostEngineInitHandle;
    FTSTicker::FDelegateHandle ApplyStyleTickerHandle;
    int32 ApplyStyleRetryCount = 0;
};
