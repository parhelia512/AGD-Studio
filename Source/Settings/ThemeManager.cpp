//---------------------------------------------------------------------------
#include "AgdStudio.pch.h"
//---------------------------------------------------------------------------
#include "ThemeManager.h"
#include "Project/Documents/Settings.h"
#include "Services/File.h"
#include "Services/Folders.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void __fastcall ThemeManager::SetStyle(const String& styleName)
{
    auto styleFile = Services::File::Combine(Services::Folders::GetFolder(Services::Folders::lpApplication, "Styles"), styleName + ".vsf");
    auto styleNameNoSpaces = StringReplace(styleName, " ", "", TReplaceFlags(rfReplaceAll || rfIgnoreCase)).LowerCase();
    for (auto name : TStyleManager::StyleNames)
    {
        auto nameWithoutSpaces = StringReplace(name, " ", "", TReplaceFlags(rfReplaceAll || rfIgnoreCase)).LowerCase();
        if (styleNameNoSpaces == nameWithoutSpaces)
        {
            auto style = TStyleManager::Style[name];
            TStyleManager::SetStyle(style);
            theAppSettings.ActiveStyle = styleName;
            Bus::Publish<ThemeChangedEvent>(ThemeChangedEvent());
            return;
        }
    }
    if (!TStyleManager::TrySetStyle(styleName, false) && Services::File::Exists(styleFile))
    {
        TStyleManager::SetStyle(TStyleManager::LoadFromFile(styleFile));
        theAppSettings.ActiveStyle = styleName;
        Bus::Publish<ThemeChangedEvent>(ThemeChangedEvent());
    }
}
//---------------------------------------------------------------------------
void __fastcall ThemeManager::LoadStyles(TComboBox* combo)
{
    combo->Items->Clear();
    auto sl = std::make_unique<TStringList>();
    // default application style
    sl->Add("Windows 10 Black Pearl");
    // load the styles from the styles folder
    auto styles = GetStyles();
    TStyleInfo si;
    for (auto styleFile : styles)
    {
        sl->Add(Services::File::NameWithoutExtension(styleFile));
    }
    sl->Sort();
    // add to the combo box
    const String style = theAppSettings.ActiveStyle;
    for (auto i = 0; i < sl->Count; i++)
    {
        auto styleName = sl->Strings[i];
        if (styleName.Pos(" ") > 0 && combo->Items->IndexOf(styleName) == -1) {
            combo->Items->Add(styleName);
            if (styleName == style)
            {
                combo->ItemIndex = combo->Items->Count - 1;
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall ThemeManager::ReapplyStyle()
{
    // force a change back to the current style to reapply it for a hidden form on activation
    auto style = TStyleManager::ActiveStyle->Name;
    TStyleManager::SetStyle(style == TStyleManager::StyleNames[0] ? TStyleManager::StyleNames[1] : TStyleManager::StyleNames[0]);
    TStyleManager::SetStyle(style);
}
//---------------------------------------------------------------------------
TStringDynArray __fastcall ThemeManager::GetStyles()
{
    return Services::Folders::GetFiles(Services::Folders::lpApplication, "*.vsf", "Styles");
}
//---------------------------------------------------------------------------
TColor __fastcall ThemeManager::GetColor(int index)
{
    switch (index)
    {
        // button highlight
        case 0: break;
        // button background
        case 1: return StyleServices()->GetSystemColor(clBtnFace); break;
        // button shadow
        case 3: return StyleServices()->GetSystemColor(clBtnShadow); break;
        // button text
        case 2:
        default:
                return StyleServices()->GetSystemColor(clBtnText); break;
    }
    return StyleServices()->GetSystemColor(clHighlight);
}
//---------------------------------------------------------------------------

